#include"all.h"
extern  Day days[];


//コンストラクタ
playerController::playerController() {
	hitarea_pos = { SCREEN_W * 0.5f,SCREEN_H * 0.4f };
	hitarea_scale = { 50,50 };
	flickarea_pos = { SCREEN_W * 0.5f,SCREEN_H * 0.7f };
	flickarea_scale = { 50,50 };
	main_conveyor = true;
	right_hit_area = true;
	main_conveyor_color = 1.0f;
	sub_conveyor_color = 1.0f;
}

//デストラクタ
playerController::~playerController() {

}

//叩くエリアと弾くエリアの描画関数
void playerController::HITAREA_FLICKAREA_RENDER() {
	//叩くエリア
	primitive::rect(hitarea_pos.x, hitarea_pos.y, hitarea_scale.x, hitarea_scale.y,
		0, 0, ToRadian(0), 1, 1, main_conveyor_color);

	if (right_hit_area == true) {
		sprite_render(hand, hitarea_pos.x, hitarea_pos.y, 1, 1, 0, 0, 150, 200, ToRadian(0));//正常
	}
	else {
		sprite_render(hand, hitarea_pos.x, hitarea_pos.y, 1, 1, 0, 0, 150, 200, ToRadian(0));//反転
	}

	//弾くエリア
	primitive::rect(flickarea_pos.x, flickarea_pos.y, flickarea_scale.x, flickarea_scale.y,
		0, 0, ToRadian(0), sub_conveyor_color, 1, 1);
}

//playerの叩く動作関数
void playerController::PLAYER_HIT_CAN(Can* cans, int day) {
	if (main_conveyor == true) {
		for (int i = 0; i < days[day - 1].CAN_NUM; i++) {
			if (HITCHECK_CAN(&cans[i], 1) == true) {
				if (TRG(0) & PAD_START) {
					//音を鳴らす
					music::play(1);
				}
			}
		}
	}
}

//缶と叩くエリアの当たり判定関数
bool playerController::HITCHECK_CAN(Can* can, int day) {
	float areaL = hitarea_pos.x;
	float areaR = hitarea_pos.x + hitarea_scale.x;
	float areaU = hitarea_pos.y;
	float areaD = hitarea_pos.y + hitarea_scale.y;

	float canL = can->getCAN_POS().x;
	float canR = can->getCAN_POS().x + can->getCAN_SCALE().x;
	float canU = can->getCAN_POS().y;
	float canD = can->getCAN_POS().y + can->getCAN_SCALE().y;

	if (areaR > canL && areaL < canR &&
		areaU<canD && areaD > canU) {

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
	float canR = can->getCAN_POS().x + can->getCAN_SCALE().x;
	float canU = can->getCAN_POS().y;
	float canD = can->getCAN_POS().y + can->getCAN_SCALE().y;

	if (areaR > canL && areaL < canR &&
		areaU<canD && areaD > canU) {

		return true;
	}
	return false;
}

//ベルトコンベアの上下と叩くエリアの左右切り替え関数
void playerController::BELTCONVEYOR_HITAREA_CHANGE() {
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
	if (TRG(0) & PAD_RIGHT) {
		right_hit_area = true;
	}
	if (TRG(0) & PAD_LEFT) {
		right_hit_area = false;
	}

}