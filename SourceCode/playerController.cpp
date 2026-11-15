#include"all.h"
extern  Day days[];
extern Can ojis[];

//コンストラクタ
playerController::playerController() {
	hitarea_pos = { SCREEN_W * 0.507f,SCREEN_H * 0.5f };
	hitarea_scale = { 166,120 };
	flickarea_pos = { SCREEN_W * 0.507f,SCREEN_H * 0.77f };
	flickarea_scale = { 166,120 };
	main_conveyor = true;
	right_hit_area = true;
	main_conveyor_color = 1.0f;
	sub_conveyor_color = 1.0f;
	control_stop_timer = 0;
}

//デストラクタ
playerController::~playerController() {

}

//叩くエリアと弾くエリアの描画関数
void playerController::HITAREA_FLICKAREA_RENDER() {
	//叩くエリア
	primitive::rect(hitarea_pos.x, hitarea_pos.y, hitarea_scale.x, hitarea_scale.y,
		0, 0, ToRadian(0), 1, 1, main_conveyor_color, 0.0f);

	if (right_hit_area == true) {
		sprite_render(hand, hitarea_pos.x + 130, hitarea_pos.y - 40, 1, 1, 0, 0, 150, 200, ToRadian(0));//正常
	}
	if (right_hit_area == false) {
		sprite_render(hand, hitarea_pos.x - 20, hitarea_pos.y - 40, 1, 1, 0, 0, 150, 200, ToRadian(0));//反転
	}

	//弾くエリア
	primitive::rect(flickarea_pos.x, flickarea_pos.y, flickarea_scale.x, flickarea_scale.y,
		0, 0, ToRadian(0), sub_conveyor_color, 1, 1, 0.0f);
}

//playerの叩く動作関数
void playerController::PLAYER_HIT_CAN(Can* cans, Can* obas, Can* ojis, int day) {
	for (int i = 0; i < days[day - 1].CAN_NUM; i++) {
		if (control_stop_timer <= 0) {
			if (main_conveyor == true) {
				if (TRG(0) & PAD_START) {
					if (cans[i].getCAN_COLOR() >= 61 && cans[i].getCAN_COLOR() <= 100) {//缶
						if (HITCHECK_CAN(&cans[i]) == true) {
							//音を鳴らす
							music::play(1);
						}
					}
					if (cans[i].getCAN_COLOR() >= 21 && cans[i].getCAN_COLOR() <= 60) {//缶
						if (HITCHECK_CAN(&cans[i]) == true) {
							//音を鳴らす
							music::play(2);
						}
					}

					else if (cans[i].getCAN_COLOR() >= 11 && cans[i].getCAN_COLOR() <= 20) {//おじさん吹っ飛び
						if (HITCHECK_OJI(&ojis[i]) == true) {
							if (ojis[i].getOJI_HIT() == false) {
								ojis[i].setOJI_HIT(true);
								ojis[i].setOJI_JUMP(true);
							}
						}
					}

					else if (cans[i].getCAN_COLOR() >= 1 && cans[i].getCAN_COLOR() <= 10) {//おばさん
						if (HITCHECK_OBA(&obas[i]) == true) {
							//横向きに変更
							if (obas[i].getOBA_HIT() == false) {
								obas[i].setOBA_HIT(true);
								control_stop_timer = 180;
							}
						}
					}
				}

			}
		}
		//おじさんが飛んでいく処理
		if (ojis[i].getOJI_JUMP() == true) {
			ojis->OJI_JUMP(&ojis[i]);
		}
	}
	//プレイヤーが操作できないタイムの減少
	if (control_stop_timer > 0) {
		control_stop_timer--;
	}
}


//缶と叩くエリアの当たり判定関数
bool playerController::HITCHECK_CAN(Can* can) {
	float areaL = hitarea_pos.x;
	float areaR = hitarea_pos.x + hitarea_scale.x;
	float areaU = hitarea_pos.y;
	float areaD = hitarea_pos.y + hitarea_scale.y;

	float canL = can->getCAN_POS().x;
	float canR = can->getCAN_POS().x + can->getCAN_SCALE().x * can->getCAN_TEXTSIZE().x;
	float canU = can->getCAN_POS().y;
	float canD = can->getCAN_POS().y + can->getCAN_SCALE().y * can->getCAN_TEXTSIZE().y;

	if (areaR > canL && areaL < canR &&
		areaU<canD && areaD > canU) {

		return true;
	}

	return false;
}

//おばさんと叩くエリアの当たり判定関数
bool playerController::HITCHECK_OBA(Can* oba) {
	float areaL = hitarea_pos.x;
	float areaR = hitarea_pos.x + hitarea_scale.x;
	float areaU = hitarea_pos.y;
	float areaD = hitarea_pos.y + hitarea_scale.y;

	float obaL = oba->getCAN_POS().x;
	float obaR = oba->getCAN_POS().x + 130;//oba->getCAN_SCALE().x * oba->getOBA_TEXTSIZE().x;
	float obaU = oba->getCAN_POS().y;
	float obaD = oba->getCAN_POS().y + oba->getCAN_SCALE().y * oba->getOBA_TEXTSIZE().y;

	if (areaR > obaL && areaL < obaR &&
		areaU<obaD && areaD > obaU) {

		return true;
	}

	return false;
}
//おじさんと叩くエリアの当たり判定関数
bool playerController::HITCHECK_OJI(Can* oji) {
	float areaL = hitarea_pos.x;
	float areaR = hitarea_pos.x + hitarea_scale.x;
	float areaU = hitarea_pos.y;
	float areaD = hitarea_pos.y + hitarea_scale.y;

	float ojiL = oji->getCAN_POS().x;
	float ojiR = oji->getCAN_POS().x + 180;//oba->getCAN_SCALE().x * oba->getOBA_TEXTSIZE().x;
	float ojiU = oji->getCAN_POS().y;
	float ojiD = oji->getCAN_POS().y + oji->getCAN_SCALE().y * oji->getOJI_TEXTSIZE().y;

	if (areaR > ojiL && areaL < ojiR &&
		areaU<ojiD && areaD > ojiU) {

		return true;
	}

	return false;
}

//playerの弾く動作関数
void playerController::PLAYER_FLICK_CAN(Can* can, int day) {
	if (main_conveyor == false) {
		for (int i = 0; i < days[day - 1].CAN_NUM; i++) {
			if (FLICKCHECK_CAN(&can[i], day) == true) {
				if (TRG(0) & PAD_START) {
					//缶を弾く、消す
					can[i].setCAN_ALIVE(false);
				}
			}
		}
	}
}

//缶と弾くエリアの当たり判定関数
bool playerController::FLICKCHECK_CAN(Can* can, int day) {
	float areaL = flickarea_pos.x;
	float areaR = flickarea_pos.x + flickarea_scale.x;
	float areaU = flickarea_pos.y;
	float areaD = flickarea_pos.y + flickarea_scale.y;

	float canL = can->getCAN_POS().x;
	float canR = can->getCAN_POS().x + can->getCAN_SCALE().x * can->getCAN_TEXTSIZE().x;
	float canU = can->getCAN_POS().y;
	float canD = can->getCAN_POS().y + can->getCAN_SCALE().y * can->getCAN_TEXTSIZE().y;

	if (areaR > canL && areaL < canR &&
		areaU<canD && areaD > canU) {

		return true;
	}
	return false;
}

//ベルトコンベアの上下と叩くエリアの左右切り替え関数
void playerController::BELTCONVEYOR_HITAREA_CHANGE() {
	debug::setString("palyer_stop:%i", control_stop_timer);
	if (control_stop_timer <= 0) {
		//上下
		if (TRG(0) & PAD_UP) {
			main_conveyor = true;
		}
		if (TRG(0) & PAD_DOWN) {
			main_conveyor = false;
		}
		if (main_conveyor == true) {
			main_conveyor_color = 1.0f;
			sub_conveyor_color = 0.0f;
		}
		if (main_conveyor == false) {
			sub_conveyor_color = 1.0f;
			main_conveyor_color = 0.0f;
		}

		//左右
		if (main_conveyor == true) {

			if (TRG(0) & PAD_RIGHT) {
				right_hit_area = true;
			}
			if (TRG(0) & PAD_LEFT) {
				right_hit_area = false;
			}
		}
	}
}