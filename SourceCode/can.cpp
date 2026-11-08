#include"all.h"

//コンストラクタ
Can::Can() {
	srand(unsigned int(NULL));
	generate_num = 0;
	generate_timer = 60;
	can_num = 0;
	can_color = 0;
	can_alive = true;

	pos = { SCREEN_W,SCREEN_H * 0.4f };
	speed = { 3,0 };
	scale = { 30,30 };
}

//缶の生成関数
void Can::CAN_GENERATE(Can* can) {
	debug::setString("generate:%i", generate_timer);

	generate_timer--;
	if (generate_timer < 0) {
		can_num = rand() % 100 + 1;
		can[generate_num].can_color = can_num;
		generate_num++;
		generate_timer = 60;
	}

	if (generate_num > CAN_NUM) {
		generate_num = CAN_NUM;
	}
}

//缶の描画関数
void Can::CAN_RENDER(Can* can) {
	debug::setString("cun_num:%i", can_num);
	for (int i = 0; i < generate_num; i++) {
		if (can[i].can_alive == true) {
			if (can[i].can_color <= 100) {
				primitive::rect(can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					can[i].scale.x * 0.5f, can[i].scale.y * 0.5f, ToRadian(0), 0, 0, 1);//青缶
			}
			if (can[i].can_color <= 66) {
				primitive::rect(can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					can[i].scale.x * 0.5f, can[i].scale.y * 0.5f, ToRadian(0), 1, 0, 0);//赤缶
			}
			if (can[i].can_color <= 33) {
				primitive::rect(can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					can[i].scale.x * 0.5f, can[i].scale.y * 0.5f, ToRadian(0), 0, 1, 0);//緑缶
			}
		}
	}
}

//缶の移動関数
void Can::CAN_MOVE(Can* can) {
	debug::setString("posX:%fposX:%f", can[0].pos.x, can[0].pos.y);
	for (int i = 0; i < generate_num; i++) {
		if (can[i].can_alive == true) {
			if (can[i].pos.y == SCREEN_H * 0.4f) {
				can[i].pos.x -= can[i].speed.x;
			}

			if (can[i].pos.x <= 0 - (can[i].scale.x * 2)) {
				can[i].pos.y = SCREEN_H * 0.7f;
			}

			if (can[i].pos.y >= SCREEN_H * 0.7f) {
				can[i].pos.x += can[i].speed.x;
				if (can[i].pos.x >= SCREEN_W) {
					can[i].can_alive = false;
				}
			}
		}
	}
	//if (pos.y == SCREEN_H * 0.4f) {
	//	pos.x -= speed.x;
	//}
	//if (pos.x <= 0 - (scale.x * 2)) {
	//	pos.y = SCREEN_H * 0.7f;
	//}
	//if (pos.y >= SCREEN_H * 0.7f) {
	//	pos.x += speed.x;
	//	if (pos.x >= SCREEN_W) {
	//		can_alive = false;
	//	}
	//}
}

//posのゲッター関数
VECTOR2 Can::getCAN_POS() {
	return pos;
}

//scaleのゲッター関数
VECTOR2 Can::getCAN_SCALE() {
	return scale;
}

//can_aliveのセッター関数
void Can::setCAN_ALIVE(bool alive) {
	can_alive = alive;
}