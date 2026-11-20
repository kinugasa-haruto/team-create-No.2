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
	//生成間隔			生成個数	缶の速度		爆弾の確率		おばさんの確率		おじさんの確率		不正解の缶の確率		缶の確率
	//{ 100.0f,		20,		5.0f,		0,			60,				85,				90,					100},	// デバック用
	{ 200.0f,		20,		2.0f,		0,			0,				0,				10,					100},	// 1日目
	{ 150.0f,		20,		5.0f,		10,			20,				80,				90,					100},	// 2日目
	{ 150.0f,		20,		3.0f,		10,			20,				80,				90,					100},	// 3日目
	{ 100.0f,		20,		3.0f,		10,			20,				80,				90,					100},	// 4日目
	{ 100.0f,		20,		4.0f,		10,			20,				80,				90,					100},	// 5日目
	{ 80.0f,		20,		4.0f,		10,			20,				80,				90,					100},	// 6日目
	{ 70.0f,		20,		5.0f,		10,			20,				80,				90,					100},	// 7日目
	{ 100.0f,		100,	2.0f,		0,			0,				0,				0,					100},	// 8タイトルの缶
	{ 0.0f,			2,		4.0f,		0,			0,				0,				50,					100},	// チュートリアル
	//{ 0.0f,			1,		2.0f,		0,			0,				0,				100,					0},		// 10チュートリアル2

};

//ゲームでの関数をまとめた関数
void GAME_DAY(int num) {
	back_update(days[num - 1].speed);
	can.CAN_GENERATE(cans, obas, ojis, boms, num);//缶の生成関数
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

	can.GAUGE_UPDATE();
	can.BOM_EFFECT_UPDATE(boms);

}
void GAME_DAY_RENDER(int num) {
	GameLib::clear(0.2f, 0.2f, 0.4f);
	back_render();
	can.OJI_BACK_RENDER(cans, ojis, num);//おじさんがコンベアの後ろに消える処理
	conveyor_render();
	can.CAN_RENDER(cans, obas, ojis, boms, num);//缶の描画関数
	judgearea_render();
	can.GAUGE_RENDER();
	player.HITAREA_FLICKAREA_RENDER();			//叩く,弾くエリアの描画
	//can.DAY_CLEAR(cans, obas, ojis, boms, num);//CLEAR時の関数	ゲージの描画
	can.BOM_EFFECT_RENDER(boms);
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
	can.CAN_GENERATE(cans, obas, ojis, boms, 9);										//缶の生成関数
	player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);	//缶と叩くエリアの当たり判定関数
	player.PLAYER_HIT_CAN(cans, obas, ojis, boms, 9);									//playerの缶を叩く動作関数
	player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);//缶と弾くエリアの当たり判定関数
	player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, 9);									//playerの缶を弾く動作関数
}
//void TUTORIAL_CAN_RENDER() {
//	can.CAN_RENDER(cans, obas, ojis, boms, 8);	//缶の描画関数
//}
void TUTORIAL_MISSCAN_UPDATE() {
	can.CAN_GENERATE(cans, obas, ojis, boms, 10);										//不正解の缶の生成関数
	player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);	//不正解の缶と叩くエリアの当たり判定関数
	player.PLAYER_HIT_CAN(cans, obas, ojis, boms, 10);									//playerの不正解の缶を叩く動作関数
	player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);//不正解の缶と弾くエリアの当たり判定関数
	player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, 10);									//playerの不正解の缶を弾く動作関数
}
//void TUTORIAL_MISSCAN_RENDER() {
//	can.CAN_RENDER(cans, obas, ojis, boms, 9);	//不正解の缶の描画関数
//}



//コンストラクタ
Can::Can() {
	srand((unsigned int)time(NULL));
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

	effect_scale = 0.9f;

	oji_jump = false;
	oji_jump_power = -50;
	oji_speed = 0;
	oji_gra = 3;
	oji_hit = false;
	oji_back = false;
	oba_hit = false;

	kigen = 60;
	errorcan_count = 0;
	othercan_count = 0;

	gravity = 20;//重力
	gravity_flag = false;//重力をかけ始める判断

	gauge_pos = { SCREEN_W * 0.6f,SCREEN_W * 0.0f };
	gauge_scale = { 0.7f,0.7f };
	gaugeW = 0;

	Bomeffect_flag = false;

	Beffect_textsize = { 2000,1500 };
	efc_timer = 0;

	flick_flag = false;
	bom_dropped = false;
}

//デストラクタ
Can::~Can() {

}

//缶の生成関数
void Can::CAN_GENERATE(Can* cans, Can* obas, Can* ojis, Can* boms, int day) {
	debug::setString("generate:%i", generate_timer);
	debug::setString("error_can:%i", errorcan_count);
	debug::setString("other_can:%i", othercan_count);

	generate_timer--;
	if (generate_timer < 0 && generate_num < days[day - 1].CAN_NUM) {
		int i = generate_num;
		can_num = rand() % 100 + 1;

		cans[i].can_color = can_num;

		if (can_num <= days[day - 1].bom_pro) {// 爆弾
			boms[i].setCAN_ALIVE(true);
			othercan_count++;
		}

		if (can_num > days[day - 1].bom_pro && can_num <= days[day - 1].oba_pro) {// おばさん
			obas[i].setCAN_ALIVE(true);
			othercan_count++;
		}

		if (can_num > days[day - 1].oba_pro && can_num <= days[day - 1].oji_pro) {// おじさん
			ojis[i].setCAN_ALIVE(true);
			othercan_count++;
		}

		if (can_num > days[day - 1].oji_pro && can_num <= days[day - 1].errorcan_pro) {
			cans[i].setCAN_ALIVE(true);//缶
			errorcan_count++;
		}

 		if (can_num > days[day - 1].errorcan_pro && can_num <= days[day - 1].can_pro) {
			cans[i].setCAN_ALIVE(true);//缶
		}

		cans[i].setOJI_HIT(false);

		generate_timer = days[day - 1].timer;
		generate_num++;
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
				sprite_render(Bom, bom[i].pos.x, bom[i].pos.y + 20, bom[i].scale.x * 0.8f, bom[i].scale.y,
					0, 0, bom_textsize.x, bom_textsize.y, 0, 0, ToRadian(0));//爆弾
				primitive::rect(bom[i].pos.x, bom[i].pos.y + 20, bom_textsize.x * 0.8f, bom_textsize.y,
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
					if (cans[i].getCAN_COLOR() > days[day - 1].errorcan_pro &&
						cans[i].getCAN_COLOR() <= days[day - 1].can_pro) {
						kigen += 2;
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

				if (bom[i].pos.x >= SCREEN_W + 50) {
					//bom[i].can_alive = false;
					if (boms[i].getBOM_EFFECT() == false) {
						boms[i].setEFC_TIMER(0);
						boms[i].setBOM_EFFECT(true);
					}
					bom[i].bom_dropped = true;
					kigen -= 100;
				}
			}

			bom[i].Bbom_pos.x = bom[i].pos.x + 20;
			bom[i].Bbom_pos.y = bom[i].pos.y + 50;

			bom[i].Rbom_pos.x = bom[i].pos.x + 120;
			bom[i].Rbom_pos.y = bom[i].pos.y + 50;

		}

		//重力を足して画面外にいったら消える
		if (boms[i].gravity_flag == true) {
			boms[i].pos.y += gravity;
		}
		if (boms[i].pos.y >= SCREEN_H + 250) {
			boms[i].setCAN_ALIVE(false);
		}

		if (obas[i].gravity_flag == true) {
			obas[i].pos.y += gravity;
		}
		if (obas[i].pos.y >= SCREEN_H + 250) {
			obas[i].setCAN_ALIVE(false);

		}

		if (ojis[i].gravity_flag == true) {
			ojis[i].pos.y += gravity;
		}
		if (ojis[i].pos.y >= SCREEN_H + 250) {
			ojis[i].setCAN_ALIVE(false);

		}

		if (cans[i].gravity_flag == true) {
			cans[i].pos.y += gravity;
		}
		if (cans[i].pos.y >= SCREEN_H + 250) {
			cans[i].setCAN_ALIVE(false);

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

		if (oji->pos.y <= SCREEN_H * 0.45f) {
			oji->oji_back = true;
		}

		if (oji->pos.y >= SCREEN_H * 0.6f) {
			oji->pos.y = SCREEN_H * 0.6f;

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

void Can::BOM_EFFECT_UPDATE(Can* bom) {
	for (int i = 0; i < generate_num; i++) {
		//debug::setString("effect:%d", bom[i].efc_timer);
		if (bom[i].Bomeffect_flag == true) {
			bom[i].efc_timer++;

			if (bom[i].Bomeffect_flag == true || bom[i].bom_dropped == true) {
				if (bom[i].efc_timer > 200) {
					bom[i].Bomeffect_flag = false;
					bom[i].can_alive = false;
					//爆発時の処理（リザルトシーンにいって。日にちを１日スキップする処理）

				}
			}
		}
	}
}

void Can::BOM_EFFECT_RENDER(Can* bom) {
	float d = 0.0f;
	for (int i = 0; i < generate_num; i++) {
		if (bom[i].Bomeffect_flag == true) {
			if (bom[i].efc_timer <= 200 && bom[i].efc_timer > 40) {
				effect_scale = 1.5f + 3.0f * ((bom[i].efc_timer - 41) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.5, SCREEN_H * 0.5, effect_scale, effect_scale,
					8000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 40 && bom[i].efc_timer > 30) {
				effect_scale = 1.5f + 3.0f * ((bom[i].efc_timer - 31) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.5, SCREEN_H * 0.5, effect_scale, effect_scale,
					6000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 30 && bom[i].efc_timer > 20) {
				effect_scale = 1.5f + 3.0f * ((bom[i].efc_timer - 21) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.5, SCREEN_H * 0.5, effect_scale, effect_scale,
					4000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 20 && bom[i].efc_timer > 10) {
				effect_scale = 1.5f + 3.0f * ((bom[i].efc_timer - 11) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.5, SCREEN_H * 0.5, effect_scale, effect_scale,
					2000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 10 && bom[i].efc_timer > 0) {
				effect_scale = 1.5f + 3.0f * ((bom[i].efc_timer - 1) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.5, SCREEN_H * 0.5, effect_scale, effect_scale,
					0, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 200 && bom[i].efc_timer >= 80) {
				d = (bom[i].efc_timer - 80) / 120.0f;
				primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 0, 0, 0, d);
			}
		}

		if (bom[i].bom_dropped == true) {
			if (bom[i].efc_timer <= 200 && bom[i].efc_timer > 40) {
				effect_scale = 3.5f + 3.0f * ((bom[i].efc_timer - 41) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.9, SCREEN_H * 0.7, effect_scale, effect_scale,
					8000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 40 && bom[i].efc_timer > 30) {
				effect_scale = 3.5f + 3.0f * ((bom[i].efc_timer - 31) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.9, SCREEN_H * 0.7, effect_scale, effect_scale,
					6000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 30 && bom[i].efc_timer > 20) {
				effect_scale = 3.5f + 3.0f * ((bom[i].efc_timer - 21) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.9, SCREEN_H * 0.7, effect_scale, effect_scale,
					4000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 20 && bom[i].efc_timer > 10) {
				effect_scale = 3.5f + 3.0f * ((bom[i].efc_timer - 11) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.9, SCREEN_H * 0.7, effect_scale, effect_scale,
					2000, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 10 && bom[i].efc_timer > 0) {
				effect_scale = 3.5f + 3.0f * ((bom[i].efc_timer - 1) * 0.15) * 0.09f;
				sprite_render(Bom_effect, SCREEN_W * 0.9, SCREEN_H * 0.7, effect_scale, effect_scale,
					0, 0, bom[i].Beffect_textsize.x, bom[i].Beffect_textsize.y, 1000, 750, ToRadian(0));
			}
			if (bom[i].efc_timer <= 200 && bom[i].efc_timer >= 80) {
				d = (bom[i].efc_timer - 80) / 120.0f;
				primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 0, 0, 0, d);
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

////CLEAR時の関数
//void Can::DAY_CLEAR(Can* can, Can* oba, Can* oji, Can* bom, int day) {
//
//	//if (generate_num >= days[day - 1].CAN_NUM &&
//	//	CAN_ALL_VANISH(can, oba, oji, bom) == true) {
//	//	text_out(1, "game clear", SCREEN_W * 0.4f, SCREEN_H * 0.4f, 2, 2, 0, 0, 0);
//	//}
//}

//ゲージの処理関数
void Can::GAUGE_UPDATE() {
	debug::setString("KIGEN:%f", kigen);
	if (kigen < 0) {
		kigen = 0;
	}
	if (kigen >= 100) {
		kigen = 100;
	}

	if (kigen <= 0) {
		//機嫌ゲージが０になった時にゲームオーバーの処理

	}

	float g = kigen * 0.01f;
	gaugeW = 760 * g;
}

//ゲージの描画関数
void Can::GAUGE_RENDER() {
	sprite_render(sub_gauge, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
		0, 0, 1000, 300, 0, 0, ToRadian(0));
	sprite_render(main_gauge, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
		0, 0, gaugeW, 300, 0, 0, ToRadian(0));

	if (kigen >= 90) {
		sprite_render(jousi3, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
			0, 0, 1000, 300, 0, 0, ToRadian(0));
	}
	if (kigen < 90 && kigen >= 70) {
		sprite_render(jousi2, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
			0, 0, 1000, 300, 0, 0, ToRadian(0));
	}
	if (kigen < 70 && kigen >= 50) {
		sprite_render(jousi1, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
			0, 0, 1000, 300, 0, 0, ToRadian(0));
	}
	if (kigen < 50 && kigen >= 40) {
		sprite_render(jousi4, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
			0, 0, 1000, 300, 0, 0, ToRadian(0));
	}
	if (kigen < 40 && kigen >= 20) {
		sprite_render(jousi5, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
			0, 0, 1000, 300, 0, 0, ToRadian(0));
	}
	if (kigen < 20 && kigen >= 0) {
		sprite_render(jousi6, gauge_pos.x, gauge_pos.y, gauge_scale.x, gauge_scale.y,
			0, 0, 1000, 300, 0, 0, ToRadian(0));
	}

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

//kigenの-セッター関数
void Can::MINUSsetKIGEN(int k) {
	kigen -= k;
}

//kigenの+セッター関数
void Can::PLUSsetKIGEN(int k) {
	kigen += k;
}

//不正解の缶の生成数のゲッター関数
int Can::getERRORCAN_COUNT() {
	return errorcan_count;
}

//缶以外の生成合計数のゲッター関数
int Can::getOTHERCAN_COUNT() {
	return othercan_count;
}

void Can::setGRA_FLAG(bool gra) {
	gravity_flag = gra;
}

void Can::setBOM_EFFECT(bool effect) {
	Bomeffect_flag = effect;
}

bool Can::getBOM_EFFECT() {
	return Bomeffect_flag;
}

void Can::setEFC_TIMER(int timer) {
	efc_timer = timer;
}

//flick_flagのセッター関数
void Can::setFLICK_FLAG(bool flick) {
	flick_flag = flick;
}

//flick_flagのセッター関数
bool Can::getFLICK_FLAG() {
	return flick_flag;
}

void Can::CAN_RESET(Can* can, Can* oba, Can* oji, Can* bom)
{
	for (int i = 0; i < generate_num; i++)
	{
		if (can[i].can_alive == true)
		{
			can[i].pos = { SCREEN_W,SCREEN_H * 0.48f };;
			can[i].setCAN_ALIVE(false);
		}
		if (oba[i].can_alive == true)
		{
			oba[i].oba_pos = { SCREEN_W - 35,SCREEN_H * 0.48f - 50 };;
			oba[i].setCAN_ALIVE(false);
		}
		if (oji[i].can_alive == true)
		{
			oji[i].oji_pos = { SCREEN_W,SCREEN_H * 0.48f - 50 };;
			oji[i].setCAN_ALIVE(false);
			oji[i].oji_back = false;
		}
		if (bom[i].can_alive == true)
		{
			bom[i].bom_pos = { SCREEN_W,SCREEN_H * 0.48f + 20 };;
			bom[i].setCAN_ALIVE(false);
		}
	}

	generate_num = 0;
	generate_timer = 0;
	can_num = 0;
	can_color = 0;

}

void Can::TUTORIAL_RESET()
{
	generate_num = 0;
}

void Can::TUTORIAL_GENERATE(bool impure, int day, Can* cans)
{
	generate_timer--;
	if (generate_timer < 0 && generate_num < days[day - 1].CAN_NUM) {


		int i = generate_num;
		if (impure)
		{
			cans[i].can_color = 20;
			cans[i].setCAN_ALIVE(true);//缶
			errorcan_count++;
		}
		else
		{
			cans[i].can_color = 80;
			cans[i].setCAN_ALIVE(true);//缶

		}

		cans[i].setOJI_HIT(false);


		generate_timer = days[day - 1].timer;

		generate_num++;
	}
	if (generate_num > days[day - 1].CAN_NUM) {
		generate_num = days[day - 1].CAN_NUM;
	}
}



