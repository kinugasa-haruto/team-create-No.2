#include"all.h"

Day days[] = {
	//生成間隔	生成個数		缶の速度	１日に流す物の種類
	{ 60.0f,		20,			3.0f,			3},	// 0
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

	generate_num = 0;
	generate_timer = 0;
	can_num = 0;
	can_color = 0;
	can_alive = true;


	pos = { SCREEN_W,SCREEN_H * 0.48f };
	oba_pos = { SCREEN_W - 35,SCREEN_H * 0.48f - 50 };
	oji_pos = { SCREEN_W,SCREEN_H * 0.48f - 50 };
	//speed = { 3,0 };
	scale = { 1,1 };
	can_textsize = { 125,125 };
	oba_textsize = { 200,200 };
	oji_textsize = { 200,200 };

	oji_jump = false;
	oji_jump_power = -50;
	oji_speed = 0;
	oji_gra = 3;
	oji_hit = false;
	oji_back = false;
	oba_hit = false;
}

//デストラクタ
Can::~Can() {

}

//缶の生成関数
void Can::CAN_GENERATE(Can* can, int day) {
	debug::setString("generate:%i", generate_timer);

	generate_timer--;
	if (generate_timer < 0) {
		can_num = rand() % 100 + 1;
		can[generate_num].can_color = can_num;
		generate_timer = days[day - 1].timer;
		generate_num++;
		can[generate_num].setOJI_HIT(false);
	}

	if (generate_num > days[day - 1].CAN_NUM) {
		generate_num = days[day - 1].CAN_NUM;
	}
}

//缶の描画関数	日にちによって種類を増やせるようにする
void Can::CAN_RENDER(Can* can, Can* oba, Can* oji, int day) {
	debug::setString("cun_num:%i", can_num);
	for (int i = 0; i < generate_num; i++) {
		if (can[i].can_alive == true) {
			if (can[i].can_color >= 61 && can[i].can_color <= 100) {
				sprite_render(sabaCan, can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, can_textsize.x, can_textsize.y, 0, 0, ToRadian(0));//サバ缶

				primitive::rect(can[i].pos.x, can[i].pos.y, can_textsize.x, can_textsize.y,
					0, 0, ToRadian(0), 0, 0, 1, 0.3f);//デバック用の当たり判定
			}
			if (can[i].can_color >= 21 && can[i].can_color <= 60) {
				sprite_render(sabaCan, can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, can_textsize.x, can_textsize.y, 0, 0, ToRadian(0));//サバ缶

				primitive::rect(can[i].pos.x, can[i].pos.y, can_textsize.x, can_textsize.y,
					0, 0, ToRadian(0), 0, 1, 1, 0.3f);//デバック用の当たり判定
			}
		}
		if (oji[i].can_alive == true) {
			if (can[i].oji_back == false) {
				if (can[i].can_color >= 11 && can[i].can_color <= 20) {
					if (oji[i].oji_hit == true) {
						sprite_render(ojisan_push, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
							0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん
						sprite_render(tie, oji[i].pos.x - 50, oji[i].pos.y - 150, oji[i].scale.x, oji[i].scale.y,
							0, 0, 60, 65, 0, 0, ToRadian(0));//ネクタイ
					}
					if (oji[i].oji_hit == false) {
						sprite_render(ojisan, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
							0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん

						primitive::rect(can[i].pos.x + 10, oji[i].pos.y - 50, 180, oji_textsize.y,
							0, 0, ToRadian(0), 1, 0, 0, 0.3f);//デバック用の当たり判定
					}
				}
			}
		}
		if (oba[i].can_alive == true) {
			if (can[i].can_color >= 1 && can[i].can_color <= 10) {
				primitive::rect(oba[i].pos.x, oba[i].pos.y - 50, 130, oba_textsize.y,
					0, 0, ToRadian(0), 0, 1, 0, 0.3f);//デバック用の当たり判定
				if (oba[i].oba_hit == true) {
					sprite_render(obasan, oba[i].pos.x - 35, oba[i].pos.y - 50, oba[i].scale.x, oba[i].scale.y,
						oba_textsize.x, 0, oba_textsize.x, oba_textsize.y, 0, 0, ToRadian(0));//横おばさん
				}

				if (oba[i].oba_hit == false) {
					sprite_render(obasan, oba[i].pos.x - 35, oba[i].pos.y - 50, oba[i].scale.x, oba[i].scale.y,
						0, 0, oba_textsize.x, oba_textsize.y, 0, 0, ToRadian(0));//おばさん

				}
			}
		}
	}
}

//缶の移動関数
void Can::CAN_MOVE(Can* can, Can* oba, Can* oji, int day) {
	debug::setString("posX:%fposX:%f", can[0].pos.x, can[0].pos.y);
	for (int i = 0; i < generate_num; i++) {
		if (can[i].can_alive == true) {
			if (can[i].pos.y == pos.y) {
				can[i].pos.x -= days[day - 1].speed;
			}
			if (oba[i].pos.y == pos.y) {
				oba[i].pos.x -= days[day - 1].speed;
			}
			if (oji[i].pos.y <= pos.y) {
				oji[i].pos.x -= days[day - 1].speed;
			}


			if (can[i].pos.x <= 0 - (can[i].scale.x * 250)) {
				can[i].pos.y = SCREEN_H * 0.75f;
			}
			if (oba[i].pos.x <= 0 - (can[i].scale.x * 250)) {
				oba[i].pos.y = SCREEN_H * 0.75f;
			}
			if (oji[i].pos.x <= 0 - (can[i].scale.x * 250)) {
				oji[i].pos.y = SCREEN_H * 0.75f;
			}


			if (can[i].pos.y >= SCREEN_H * 0.75f) {
				can[i].pos.x += days[day - 1].speed;
				if (can[i].pos.x >= SCREEN_W) {
					can[i].can_alive = false;
				}
			}
			if (oba[i].pos.y >= SCREEN_H * 0.75f) {
				oba[i].pos.x += days[day - 1].speed;
				if (oba[i].pos.x >= SCREEN_W) {
					oba[i].can_alive = false;
				}
			}
			if (oji[i].pos.y >= SCREEN_H * 0.75f) {
				oji[i].pos.x += days[day - 1].speed;
				if (oji[i].pos.x >= SCREEN_W) {
					oji[i].can_alive = false;
				}
			}
		}
	}
}

//おじさんが飛んでいく処理
void Can::OJI_JUMP(Can* oji) {
	if (oji->oji_jump == true) {
		oji->oji_speed += oji_gra;
		oji->pos.y += oji->oji_speed;
		oji->scale.x -= 0.01f;
		oji->scale.y -= 0.01f;

		if (oji->pos.y <= SCREEN_H * 0.45) {
			oji->oji_back = true;
		}


		if (oji->pos.y >= SCREEN_H * 0.6) {
			oji->pos.y = SCREEN_H * 0.6;

			oji->setCAN_ALIVE(false);
			oji->oji_jump = false;
		}
	}
}

void Can::OJI_BACK_RENDER(Can* can, Can* oji) {
	for (int i = 0; i < generate_num; i++) {
		if (oji[i].can_alive == true) {
			if (oji[i].oji_back == true) {
				if (can[i].can_color >= 34 && can[i].can_color <= 66) {
					sprite_render(ojisan_push, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
						0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん
					sprite_render(tie, oji[i].pos.x - 50, oji[i].pos.y - 150, oji[i].scale.x, oji[i].scale.y,
						0, 0, 60, 65, 0, 0, ToRadian(0));//ネクタイ
				}
			}
		}
	}
}

//void Can::OJI_FRONT_RENDER(Can* can, Can* oji) {
//	for (int i = 0; i < generate_num; i++) {
//		if (oji[i].can_alive == true) {
//			if (oji[i].oji_back == false) {
//				if (can[i].can_color >= 34 && can[i].can_color <= 66) {
//					if (oji[i].oji_hit == true) {
//						sprite_render(ojisan_push, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
//							0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん
//						sprite_render(tie, oji[i].pos.x - 50, oji[i].pos.y - 150, oji[i].scale.x, oji[i].scale.y,
//							0, 0, 60, 65, 0, 0, ToRadian(0));//ネクタイ
//					}
//					if (oji[i].oji_hit == false) {
//						sprite_render(ojisan, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
//							0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん
//
//						primitive::rect(oji[i].pos.x + 10, oji[i].pos.y - 50, 180, oji_textsize.y,
//							0, 0, ToRadian(0), 1, 0, 0, 0.3f);//デバック用の当たり判定
//					}
//				}
//			}
//		}
//	}
//}

//間違った物がレーンを流れ切った時の処理
bool Can::CHECK_IMPURITY_FLOW() {
	return true;
}

//缶のcolorのゲッター関数
int Can::getCAN_COLOR() {
	return can_color;
}

//缶のposのゲッター関数
VECTOR2 Can::getCAN_POS() {
	return pos;
}

//おばさんのposのゲッター関数
VECTOR2 Can::getOBA_POS() {
	return oba_pos;
}

//おじさんのposのゲッター関数
VECTOR2 Can::getOJI_POS() {
	return oji_pos;
}

//scaleのゲッター関数
VECTOR2 Can::getCAN_SCALE() {
	return scale;
}

//speedのゲッター関数
VECTOR2 Can::getCAN_SPEED() {
	return speed;
}

//缶の画像の大きさのゲッター関数
VECTOR2 Can::getCAN_TEXTSIZE() {
	return can_textsize;
}

//おばさんの画像の大きさのゲッター関数
VECTOR2 Can::getOBA_TEXTSIZE() {
	return oba_textsize;
}

//おじさんの画像の大きさのゲッター関数
VECTOR2 Can::getOJI_TEXTSIZE() {
	return oji_textsize;
}

//can_aliveのセッター関数
void Can::setCAN_ALIVE(bool alive) {
	can_alive = alive;
}

//oji_jumpのセッター関数
void Can::setOJI_JUMP(bool jump) {
	oji_jump = jump;
	if (jump == true) {
		oji_speed = oji_jump_power;
	}
}

//oji_hitのセッター関数
void Can::setOJI_HIT(bool hit) {
	oji_hit = hit;
}

//oji_jumpのゲッター関数
bool Can::getOJI_JUMP() {
	return oji_jump;
}

//oji_hitのゲッター関数
bool Can::getOJI_HIT() {
	return oji_hit;
}

//oba_hitのゲッター関数
bool Can::getOBA_HIT() {
	return oba_hit;
}

//oba_hitのセッター関数
void Can::setOBA_HIT(bool hit) {
	oba_hit = hit;
}
