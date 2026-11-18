#include"all.h"
extern Can cans[500];
extern Can obas[500];
extern Can ojis[500];
extern Can boms[500];
extern Can can;
extern playerController player; 
extern GameTimer gameTimer;

//日にち事の設定
Day days[] = {
	//生成間隔	生成個数	缶の速度	爆弾の確率	おばさんの確率	おじさんの確率	不正解の缶の確率	缶の確率
	//{ 70.0f,		20,		5.0f,		0,			0,				0,				90,					100},	// 1日目
	{ 1.0f,		1,		40.0f,		0,			0,				0,				100,					100},	// 1日目
	{ 150.0f,		20,		2.0f,		10,			20,				80,				90,					100},	// 2日目
	{ 150.0f,		20,		3.0f,		10,			20,				80,				90,					100},	// 3日目
	{ 100.0f,		20,		3.0f,		10,			20,				80,				90,					100},	// 4日目
	{ 100.0f,		20,		4.0f,		10,			20,				80,				90,					100},	// 5日目
	{ 80.0f,		20,		4.0f,		10,			20,				80,				90,					100},	// 6日目
	{ 70.0f,		20,		5.0f,		10,			20,				80,				90,					100},	// 7日目
	{ 200.0f,		1,		2.0f,		0,			0,				0,				0,					100},	// 8チュートリアル1//タイトルの缶
	{ 0.0f,		1,		2.0f,		0,			0,				0,				100,				0},		// 9チュートリアル2

};

//ゲームでの関数をまとめた関数
void GAME_DAY(int num) {
	back_update();
	can.CAN_GENERATE(cans, obas, ojis, boms, num);			//缶の生成関数
	can.CAN_MOVE(cans, obas, ojis, boms, num);//缶の移動関数

	//流れている物と叩くエリアの当たり判定関数
	player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);
	player.HITCHECK_THING(ojis, ojis->getCAN_TEXTSIZE().x, ojis->getCAN_TEXTSIZE().y);
	player.HITCHECK_THING(obas, obas->getCAN_TEXTSIZE().x, obas->getCAN_TEXTSIZE().y);
	player.HITCHECK_HUND_BUTTON(player.getRHUND_POS(), player.getRHUND_SCALE(), boms->getBBOM_POS(), boms->getBBOM_SCALE());//右手と青ボタンの当たり判定
	player.PLAYER_HIT_CAN(cans, obas, ojis, boms, num);//playerの叩く動作関数

	//流れている物と弾くエリアの当たり判定関数
	player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);
	player.FLICKCHECK_THING(ojis, ojis->getCAN_TEXTSIZE().x, ojis->getCAN_TEXTSIZE().y);
	player.FLICKCHECK_THING(obas, obas->getCAN_TEXTSIZE().x, obas->getCAN_TEXTSIZE().y);
	player.FLICKCHECK_THING(boms, boms->getCAN_TEXTSIZE().x, boms->getCAN_TEXTSIZE().y);
	player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, num);//playerの弾く動作関数

	player.BELTCONVEYOR_HITAREA_CHANGE();//ベルトコンベアの上下と叩くエリアの左右切り替え関数
	can.CAN_ALL_VANISH(cans, obas, ojis, boms);//１日に流れるものが全部消えたかの処理

}
void GAME_DAY_RENDER(int num) {
	GameLib::clear(0.2f, 0.2f, 0.4f);
	back_render();
	can.OJI_BACK_RENDER(cans, ojis, num);//おじさんがコンベアの後ろに消える処理
	conveyor_render();
	can.CAN_RENDER(cans, obas, ojis, boms, num);//缶の描画関数
	player.HITAREA_FLICKAREA_RENDER();			//叩く,弾くエリアの描画
	can.DAY_CLEAR(cans, obas, ojis, boms, num);//CLEAR時の関数	ゲージの描画

}
//void TUTORIAL_UPDATE() {
//	player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);
//	player.PLAYER_HIT_CAN(cans, obas, ojis, boms, 8);//playerの叩く動作関数
//
//	player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);
//	player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, 8);//playerの弾く動作関数
//
//	player.BELTCONVEYOR_HITAREA_CHANGE();//ベルトコンベアの上下と叩くエリアの左右切り替え関数
//
//
//}
//void TUTORIAL_RENDER() {
//	player.HITAREA_FLICKAREA_RENDER();			//叩く,弾くエリアの描画
//
//}
void TUTORIAL_CAN_UPDATE() {
	can.CAN_GENERATE(cans, obas, ojis, boms, 8);										//缶の生成関数
	player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);	//缶と叩くエリアの当たり判定関数
	player.PLAYER_HIT_CAN(cans, obas, ojis, boms, 8);									//playerの缶を叩く動作関数
	player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);//缶と弾くエリアの当たり判定関数
	player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, 8);									//playerの缶を弾く動作関数
}
//void TUTORIAL_CAN_RENDER() {
//	can.CAN_RENDER(cans, obas, ojis, boms, 8);	//缶の描画関数
//}
void TUTORIAL_MISSCAN_UPDATE() {
	can.CAN_GENERATE(cans, obas, ojis, boms, 9);										//不正解の缶の生成関数
	player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);	//不正解の缶と叩くエリアの当たり判定関数
	player.PLAYER_HIT_CAN(cans, obas, ojis, boms, 9);									//playerの不正解の缶を叩く動作関数
	player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);//不正解の缶と弾くエリアの当たり判定関数
	player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, 9);									//playerの不正解の缶を弾く動作関数
}
//void TUTORIAL_MISSCAN_RENDER() {
//	can.CAN_RENDER(cans, obas, ojis, boms, 9);	//不正解の缶の描画関数
//}



//コンストラクタ
Can::Can() {
	srand(unsigned int(NULL));

	generate_num = 0;
	generate_timer = 0;
	can_num = 0;
	can_color = 0;
	can_alive = false;

	pos = { SCREEN_W,SCREEN_H * 0.48f };
	oba_pos = { SCREEN_W - 35,SCREEN_H * 0.48f - 50 };
	oji_pos = { SCREEN_W,SCREEN_H * 0.48f - 50 };
	bom_pos = { SCREEN_W,SCREEN_H * 0.48f + 20 };

	scale = { 1,1 };
	can_textsize = { 125,125 };
	oba_textsize = { 200,200 };
	oji_textsize = { 200,200 };
	bom_textsize = { 241,100 };

	Bbom_pos = { bom_pos.x + 20 , bom_pos.y + 30 };
	Rbom_pos = { bom_pos.x + 120 , bom_pos.y + 30 };
	Bbom_scale = { 60, 50 };
	Rbom_scale = { 60, 50 };

	oji_jump = false;
	oji_jump_power = -50;
	oji_speed = 0;
	oji_gra = 3;
	oji_hit = false;
	oji_back = false;
	oba_hit = false;

	kigen = 100;
}

//デストラクタ
Can::~Can() {

}

//缶の生成関数
void Can::CAN_GENERATE(Can* cans, Can* obas, Can* ojis, Can* boms, int day) {
	debug::setString("generate:%i", generate_timer);

	generate_timer--;
	if (generate_timer < 0 &&generate_num < days[day - 1].CAN_NUM) {
		int i = generate_num;
		can_num = rand() % 100 + 1;

		cans[i].can_color = can_num;

		if (can_num <= days[day - 1].bom_pro) {// 爆弾
			boms[i].setCAN_ALIVE(true);
		}
		
		else if (can_num <= days[day - 1].oba_pro) {// おばさん
			obas[i].setCAN_ALIVE(true);
		}
		
		else if (can_num <= days[day - 1].oji_pro) {// おじさん
			ojis[i].setCAN_ALIVE(true);
		}
		
		else {
			cans[i].setCAN_ALIVE(true);//缶
		}

		cans[i].setOJI_HIT(false);

		generate_timer = days[day - 1].timer;
		generate_num++;
		//can[generate_num].can_color = can_num;
		//generate_timer = days[day - 1].timer;
		//generate_num++;
		//can[generate_num].setOJI_HIT(false);
	}

	if (generate_num > days[day - 1].CAN_NUM) {
		generate_num = days[day - 1].CAN_NUM;
	}
}

//缶の描画関数	日にちによって種類を増やせるようにする
void Can::CAN_RENDER(Can* can, Can* oba, Can* oji, Can* bom, int day) {
	debug::setString("cun_num:%i", can_num);
	for (int i = 0; i < generate_num; i++) {
		if (bom[i].can_alive == true) {
			if (can[i].can_color <= days[day - 1].bom_pro) {
				sprite_render(Bom, bom[i].pos.x, bom[i].pos.y + 20, bom[i].scale.x * 0.8, bom[i].scale.y,
					0, 0, bom_textsize.x, bom_textsize.y, 0, 0, ToRadian(0));//爆弾
				primitive::rect(bom[i].pos.x, bom[i].pos.y + 20, bom_textsize.x * 0.8, bom_textsize.y,
					0, 0, ToRadian(0), 1, 0, 1, 0.3f);//デバック用の当たり判定
				primitive::rect(bom[i].Bbom_pos.x, bom[i].Bbom_pos.y, bom[i].Bbom_scale.x, bom[i].Bbom_scale.y,
					0, 0, ToRadian(0), 1, 1, 1, 0.7f);//青ボタンののデバック用の当たり判定
				primitive::rect(bom[i].Rbom_pos.x, bom[i].Rbom_pos.y, bom[i].Rbom_scale.x, bom[i].Rbom_scale.y,
					0, 0, ToRadian(0), 0, 0, 0, 0.7f);//赤ボタンののデバック用の当たり判定
			}
		}

		if (oba[i].can_alive == true) {
			if (can[i].can_color > days[day - 1].bom_pro && can[i].can_color <= days[day - 1].oba_pro) {
				if (oba[i].oba_hit == true) {
					sprite_render(obasan, oba[i].pos.x - 35, oba[i].pos.y - 50, oba[i].scale.x, oba[i].scale.y,
						oba_textsize.x, 0, oba_textsize.x, oba_textsize.y, 0, 0, ToRadian(0));//横おばさん
				}
				if (oba[i].oba_hit == false) {
					sprite_render(obasan, oba[i].pos.x - 35, oba[i].pos.y - 50, oba[i].scale.x, oba[i].scale.y,
						0, 0, oba_textsize.x, oba_textsize.y, 0, 0, ToRadian(0));//おばさん
				}
				primitive::rect(oba[i].pos.x, oba[i].pos.y - 50, 130, oba_textsize.y,
					0, 0, ToRadian(0), 0, 1, 0, 0.3f);//おばさんのデバック用の当たり判定
			}
		}

		if (oji[i].can_alive == true) {
			if (can[i].oji_back == false) {
				if (can[i].can_color > days[day - 1].oba_pro && can[i].can_color <= days[day - 1].oji_pro) {
					if (oji[i].oji_hit == false) {
						sprite_render(ojisan, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
							0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん

						primitive::rect(oji[i].pos.x + 10, oji[i].pos.y - 50, 180, oji_textsize.y,
							0, 0, ToRadian(0), 1, 0, 0, 0.3f);//おじさんのデバック用の当たり判定
					}
				}
			}
		}
		if (can[i].can_alive == true) {
			if (can[i].can_color > days[day - 1].oji_pro && can[i].can_color <= days[day - 1].errorcan_pro) {
				sprite_render(sabaCan, can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, can_textsize.x, can_textsize.y, 0, 0, ToRadian(0));//音の違うサバ缶

				primitive::rect(can[i].pos.x, can[i].pos.y, can_textsize.x, can_textsize.y,
					0, 0, ToRadian(0), 0, 1, 1, 0.3f);//音の違うサバ缶のデバック用の当たり判定
			}
			if (can[i].can_color > days[day - 1].errorcan_pro && can[i].can_color <= days[day - 1].can_pro) {
				sprite_render(sabaCan, can[i].pos.x, can[i].pos.y, can[i].scale.x, can[i].scale.y,
					0, 0, can_textsize.x, can_textsize.y, 0, 0, ToRadian(0));//サバ缶

				primitive::rect(can[i].pos.x, can[i].pos.y, can_textsize.x, can_textsize.y,
					0, 0, ToRadian(0), 0, 0, 1, 0.3f);//サバ缶のデバック用の当たり判定
			}
		}
	}
}

//缶の移動関数
void Can::CAN_MOVE(Can* can, Can* oba, Can* oji, Can* bom, int day) {
	for (int i = 0; i < generate_num; i++) {
		if (can[i].can_alive == true) {
			if (can[i].pos.y == pos.y) {
				can[i].pos.x -= days[day - 1].speed;
			}

			if (can[i].pos.x <= 0 - (can[i].scale.x * 250)) {
				can[i].pos.y = SCREEN_H * 0.75f;
			}

			if (can[i].pos.y >= SCREEN_H * 0.75f) {
				can[i].pos.x += days[day - 1].speed;

				if (can[i].pos.x >= SCREEN_W) {
					can[i].can_alive = false;
					if (can[i].getCAN_COLOR() <= days[day - 1].errorcan_pro &&
						can[i].getCAN_COLOR() > days[day - 1].oji_pro) {
						kigen -= 10;
					}
				}
			}
		}

		if (oji[i].can_alive == true) {
			if (oji[i].pos.y == pos.y) {
				oji[i].pos.x -= days[day - 1].speed;
			}

			if (oji[i].pos.x <= 0 - (oji[i].scale.x * 250)) {
				oji[i].pos.y = SCREEN_H * 0.75f;
			}

			if (oji[i].pos.y >= SCREEN_H * 0.75f) {
				oji[i].pos.x += days[day - 1].speed;

				if (oji[i].pos.x >= SCREEN_W) {
					oji[i].can_alive = false;
					kigen -= 10;
				}
			}
		}

		if (oba[i].can_alive == true) {
			if (oba[i].pos.y == pos.y) {
				oba[i].pos.x -= days[day - 1].speed;
			}

			if (oba[i].pos.x <= 0 - (oba[i].scale.x * 250)) {
				oba[i].pos.y = SCREEN_H * 0.75f;
			}

			if (oba[i].pos.y >= SCREEN_H * 0.75f) {
				oba[i].pos.x += days[day - 1].speed;

				if (oba[i].pos.x >= SCREEN_W) {
					oba[i].can_alive = false;
					kigen -= 10; 
				}
			}
		}

		if (bom[i].can_alive == true) {
			if (bom[i].pos.y == pos.y) {
				bom[i].pos.x -= days[day - 1].speed;
			}

			if (bom[i].pos.x <= 0 - (bom[i].scale.x * 250)) {
				bom[i].pos.y = SCREEN_H * 0.75f;
			}

			if (bom[i].pos.y >= SCREEN_H * 0.75f) {
				bom[i].pos.x += days[day - 1].speed;

				if (bom[i].pos.x >= SCREEN_W) {
					bom[i].can_alive = false;
					kigen -= 10;
				}
			}

			bom[i].Bbom_pos.x = bom[i].pos.x + 20;
			bom[i].Bbom_pos.y = bom[i].pos.y + 50;

			bom[i].Rbom_pos.x = bom[i].pos.x + 120;
			bom[i].Rbom_pos.y = bom[i].pos.y + 50;
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

//おじさんがコンベアの後ろに消える処理
void Can::OJI_BACK_RENDER(Can* can, Can* oji, int day) {
	for (int i = 0; i < generate_num; i++) {
		if (oji[i].can_alive == true) {
			if (oji[i].oji_back == true) {
				if (can[i].can_color < days[day - 1].oji_pro) {
					sprite_render(ojisan_push, oji[i].pos.x, oji[i].pos.y - 50, oji[i].scale.x, oji[i].scale.y,
						0, 0, oji_textsize.x, oji_textsize.y, 0, 0, ToRadian(0));//おじさん
					sprite_render(tie, oji[i].pos.x - 50, oji[i].pos.y - 150, oji[i].scale.x, oji[i].scale.y,
						0, 0, 60, 65, 0, 0, ToRadian(0));//ネクタイ
				}
			}
		}
	}
}

//おじさんがコンベアよりも前の時の処理
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

//１日に流れるものが全部消えたかの処理
bool Can::CAN_ALL_VANISH(Can* can, Can* oba, Can* oji, Can* bom) {
	for (int i = 0; i < generate_num; i++) {

		if (can[i].can_alive == true || oba[i].can_alive == true ||
			oji[i].can_alive == true || bom[i].can_alive == true) {

			return false;
		}
	}

	return true;
}

//CLEAR時の関数	ゲージの描画
void Can::DAY_CLEAR(Can* can, Can* oba, Can* oji, Can* bom, int day) {
	debug::setString("DAY_CLEAR KIGEN:%d", kigen);
	if (kigen < 0) {
		kigen = 0;
	}
	primitive::rect(SCREEN_W * 0.5, 0, kigen * 2.5f, 50, 0, 0, ToRadian(0), 1, 0, 0);
	primitive::rect(0, 0, 800, 400, 0, 0, ToRadian(0), 0, 0, 0);
	if (kigen <= 0) {
		text_out(1, "game over", SCREEN_W * 0.4f, SCREEN_H * 0.4f, 2, 2, 0, 0, 1);
	}

	//if (generate_num >= days[day - 1].CAN_NUM &&
	//	CAN_ALL_VANISH(can, oba, oji, bom) == true) {
	//	text_out(1, "game clear", SCREEN_W * 0.4f, SCREEN_H * 0.4f, 2, 2, 0, 0, 0);
	//}
}


//缶のcolorのゲッター関数
int Can::getCAN_COLOR() {
	return can_color;
}

//can_aliveのゲッター関数
bool Can::getCAN_ALIVE() {
	return can_alive;
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

//青ボタンのposのゲッター関数
VECTOR2 Can::getBBOM_POS() {
	return Bbom_pos;
}

//赤ボタンのposのゲッター関数
VECTOR2 Can::getRBOM_POS() {
	return Rbom_pos;
}

//青ボタンのscaleのゲッター関数
VECTOR2 Can::getBBOM_SCALE() {
	return Bbom_scale;
}

//赤ボタンのscaleのゲッター関数
VECTOR2 Can::getRBOM_SCALE() {
	return Rbom_scale;
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

//oba_hitのセッター関数
void Can::setOBA_HIT(bool hit) {
	oba_hit = hit;
}

void Can::setKIGEN(int k) {

	kigen -= k;
}
