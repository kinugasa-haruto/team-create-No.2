#include"all.h"

//コンストラクタ
playerController::playerController() {
	hitarea_pos = { SCREEN_W * 0.5f,SCREEN_H * 0.4f };
	hitarea_scale = { 50,50 };
	flickarea_pos = { SCREEN_W * 0.5f,SCREEN_H * 0.7f };
	flickarea_scale = { 50,50 };
}

//叩くエリアの描画関数
void playerController::HITAREA_RENDER() {
	primitive::rect(hitarea_pos.x, hitarea_pos.y, hitarea_scale.x, hitarea_scale.y, hitarea_scale.x * 0.5f, hitarea_scale.y * 0.5f, ToRadian(0), 1, 1, 1);
}

//playerの叩く動作関数
void playerController::PLAYER_HIT_CAN(Can* cans) {
	for (int i = 0; i < CAN_NUM; i++) {
		if (HITCHECK_CAN(&cans[i]) == true) {
			if (TRG(0) & PAD_START) {
				//音を鳴らす
				music::play(1);
			}
		}
	}
}

//缶と叩くエリアの当たり判定関数
bool playerController::HITCHECK_CAN(Can* can) {
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

//弾くエリアの描画関数
void playerController::FLICKAREA_RENDER() {
	primitive::rect(flickarea_pos.x, flickarea_pos.y, flickarea_scale.x, flickarea_scale.y, flickarea_scale.x * 0.5f, flickarea_scale.y * 0.5f, ToRadian(0), 1, 1, 1);
}

//playerの弾く動作関数
void playerController::PLAYER_FLICK_CAN(Can* can) {
	for (int i = 0; i < CAN_NUM; i++) {
		if (FLICKCHECK_CAN(&can[i]) == true) {
			if (TRG(0) & PAD_START) {
				//缶を弾く、消す
				can[i].setCAN_ALIVE(false);
			}
		}
	}
}

//缶と弾くエリアの当たり判定関数
bool playerController::FLICKCHECK_CAN(Can* can) {
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
