#include"all.h"
Can num[CIRCLE_NUM];

//コンストラクタ
Can::Can() {
	srand(unsigned int(NULL));

	generate_num = 0;
	generate_timer = 60;
	can_num = 0;

	for (int i = 0; i < CIRCLE_NUM; i++) {
		num[i].pos = { SCREEN_W,SCREEN_H * 0.4f };
		num[i].speed = { 3,0 };
		num[i].scale = { 10,10 };
	}
}

//缶の生成関数
void Can::CAN_GENERATE() {
	debug::setString("generate:%i", generate_timer);

	generate_timer--;
	if (generate_timer < 0) {
		can_num = rand() % CAN_TYPES;
		num[generate_num].can_color = can_num;
		generate_num++;
		generate_timer = 60;
	}

	if (generate_num > CIRCLE_NUM) {
		generate_num = CIRCLE_NUM;
	}
}

//缶の描画関数
void Can::CAN_RENDER() {
	debug::setString("cun_num:%i", can_num);
	for (int i = 0; i < generate_num; i++) {
		switch (num[i].can_color) {
		case 0:
			primitive::circle(num[i].pos.x, num[i].pos.y, 1, num[i].scale.x, num[i].scale.y, ToRadian(0), 0, 1, 0);
			break;
		case 1:
			primitive::circle(num[i].pos.x, num[i].pos.y, 1, num[i].scale.x, num[i].scale.y, ToRadian(0), 1, 0, 0);
			break;
		case 2:
			primitive::circle(num[i].pos.x, num[i].pos.y, 1, num[i].scale.x, num[i].scale.y, ToRadian(0), 0, 0, 1);
			break;
		}
	}
}

//缶の移動関数
void Can::CAN_MOVE() {
	debug::setString("posX:%fposX:%f", num[0].pos.x, num[0].pos.y);
	for (int i = 0; i < generate_num; i++) {
		if (num[i].pos.y == SCREEN_H * 0.4f) {
			num[i].pos.x -= num[i].speed.x;
		}

		if (num[i].pos.x <= 0 - (num[i].scale.x * 2)) {
			num[i].pos.y = SCREEN_H * 0.7f;
		}

		if (num[i].pos.y >= SCREEN_H * 0.7f) {
			num[i].pos.x += num[i].speed.x;
		}
	}
}