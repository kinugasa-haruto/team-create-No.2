#include"all.h"

Day days[] = {
	//生成間隔	生成個数
		{ 60,		20 },	// 0
		//{ 70, 2 },	// 1
		//{ 60, 1 },	// 2
		//{ 50, 6 },	// 3
		//{ 40, 4 },	// 4
		//{ 30, 3 },	// 5
		//{ 20, 7 },	// 6
};

//コンストラクタ
Can::Can() {
	srand(unsigned int(NULL));

	//sabaCan = sprite_load(L"./Data/Images/saba_can.png");
	//ojisan = sprite_load(L"./Data/Images/ojisan.png");
	//ojisan_push = sprite_load(L"./Data/Images/ojisan_push.png");

	generate_num = 0;
	generate_timer = 0;
	can_num = 0;
	can_color = 0;
	can_alive = true;

	pos = { SCREEN_W,SCREEN_H * 0.4f };
	speed = { 3,0 };
	scale = { 30,30 };
}

//デストラクタ
Can::~Can() {
	//safe_delete(sabaCan);
	//safe_delete(ojisan);
	//safe_delete(ojisan_push);
}

//缶の生成関数
void Can::CAN_GENERATE(Can* can, int day) {
	debug::setString("generate:%i", generate_timer);

	generate_timer--;
	if (generate_timer < 0) {
		can_num = rand() % 100 + 1;
		can[generate_num].can_color = can_num;
		generate_timer = days[day - 1].timer;//
		generate_num++;
		//generate_timer = 60;

		//// 日によって異なる数値の設定
		////switch (day)
		////{
		////case 1:
		////	generate_timer = 60;
		////	break;
		////}
	}

	if (generate_num > days[day - 1].CAN_NUM) {
		generate_num = days[day - 1].CAN_NUM;
	}
}

//缶の描画関数	日にちによって種類を増やせるようにする
void Can::CAN_RENDER(Can* can) {
	debug::setString("cun_num:%i", can_num);
	for (int i = 0; i < generate_num; i++) {
		if (can[i].can_alive == true) {
			if (can[i].can_color <= 100) {
				//sprite_render(sabaCan, can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
				//	0, 0, 125, 125, 0, 0, ToRadian(0));//サバ缶

				primitive::rect(can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, ToRadian(0), 0, 0, 1);//青缶
			}
			if (can[i].can_color <= 66) {
				primitive::rect(can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, ToRadian(0), 1, 0, 0);//赤缶
			}
			if (can[i].can_color <= 33) {
				primitive::rect(can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, ToRadian(0), 0, 1, 0);//緑缶
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

//speedのゲッター関数
VECTOR2 Can::getCAN_SPEED() {
	return speed;
}

//can_aliveのセッター関数
void Can::setCAN_ALIVE(bool alive) {
	can_alive = alive;
}

//画像の変数にデータを入れる関数
//void Can::CAN_SET_VARIABLE() {
//	sabaCan = sprite_load(L"./Data/Images/saba_can.png");
//}

//画像をsafe_deleteする関数
//void Can::CAN_SAFE_DELETE() {
//	safe_delete(sabaCan);
//}