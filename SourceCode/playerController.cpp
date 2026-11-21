#include"all.h"
extern  Day days[];
extern Can ojis[];
extern Can can;

//コンストラクタ
playerController::playerController() {
	hitarea_pos = { SCREEN_W * 0.516f,SCREEN_H * 0.5f };
	hitarea_scale = { 130,120 };
	flickarea_pos = { SCREEN_W * 0.516f,SCREEN_H * 0.77f };
	flickarea_scale = { 130,120 };

	Rhund_pos = { hitarea_pos.x + 120 ,hitarea_pos.y + 50 };
	Lhund_pos = { hitarea_pos.x + 30 ,hitarea_pos.y + 50 };
	Rhund_scale = { 20, 20 };
	Lhund_scale = { 20, 20 };

	main_conveyor = true;
	right_hit_area = true;
	main_conveyor_color = 1.0f;
	sub_conveyor_color = 1.0f;

	control_stop_timer = 0;
	control_stop_timer2 = 0;
	flick_errorcan_count = 0;
	flick_other_count = 0;

	hit_timer = 0;
	flick_timer = 0;
	obaeffect_timer = 0;
}

//デストラクタ
playerController::~playerController() {

}

//叩くエリアと弾くエリアの描画関数
void playerController::HITAREA_FLICKAREA_RENDER() {
	//叩くエリア
	//primitive::rect(hitarea_pos.x, hitarea_pos.y, hitarea_scale.x, hitarea_scale.y,
	//	0, 0, ToRadian(0), 1, 1, main_conveyor_color, 0.5f);

	if (main_conveyor == true) {
		if (right_hit_area == true) {
			//primitive::rect(hitarea_pos.x + 120, hitarea_pos.y + 40,
			//	20, 20, 0, 0, ToRadian(0), 0, 0, 1, 0.7f);//右の時のデバック用の当たり判定
			if (hit_timer == 0) {
				sprite_render(hand, hitarea_pos.x + 130, hitarea_pos.y - 20,
					1, 1, 0, 0, 150, 200, 0, 0, ToRadian(0));//右手の通常時
			}
			if (hit_timer > 0) {
				sprite_render(hand, hitarea_pos.x + 100, hitarea_pos.y - 40,
					1, 0.85f, 0, 0, 150, 200, ToRadian(0));//右手の叩いた時
			}
		}
		if (right_hit_area == false) {
			//primitive::rect(hitarea_pos.x + 30, hitarea_pos.y + 50,
			//	20, 20, 0, 0, ToRadian(0), 0, 0, 1, 0.7f);//左の時のデバック用の当たり判定
			if (hit_timer == 0) {
				sprite_render(hand, hitarea_pos.x - 20, hitarea_pos.y - 20,
					1, 1, 0, 0, 150, 200, 0, 0, ToRadian(0));//左手の通常時
			}
			if (hit_timer > 0) {
				sprite_render(hand, hitarea_pos.x - 50, hitarea_pos.y - 40,
					1, 0.85f, 0, 0, 150, 200, 0, 0, ToRadian(0));//左手の叩いた時
			}
		}
	}

	//弾くエリア
	//primitive::rect(flickarea_pos.x, flickarea_pos.y, flickarea_scale.x, flickarea_scale.y,
	//	0, 0, ToRadian(0), sub_conveyor_color, 1, 1, 0.5f);//手

	if (main_conveyor == false) {
		if (flick_timer == 0) {
			sprite_render(hand_hold, flickarea_pos.x + 50, flickarea_pos.y - 40,
				1, 1, 0, 0, 200, 200, 0, 0, ToRadian(0));//弾くエリアの通常時の手
		}
		if (flick_timer > 0) {
			sprite_render(hand_hold, flickarea_pos.x - 50, flickarea_pos.y + 140,
				1, 1, 0, 0, 200, 200, 0, 0, ToRadian(-45));//弾くエリアの弾いた時の手
		}
	}
	if (control_stop_timer > 0 && obaeffect_timer <= 0)
	{
		ObachanRender();
	}

}

//playerの叩く動作関数
void playerController::PLAYER_HIT_CAN(Can* cans, Can* obas, Can* ojis, Can* boms, int day) {
	for (int i = 0; i < days[day - 1].CAN_NUM; i++) {
		if (control_stop_timer <= 0 && control_stop_timer2 <= 0) {
			if (main_conveyor == true) {
				if (TRG(0) & PAD_TRG1) {
					if (boms[i].getCAN_ALIVE() == true) {
						if (cans[i].getCAN_COLOR() <= days[day - 1].bom_pro) {//爆弾
							if (right_hit_area == true) {
								if (HITCHECK_HUND_BUTTON(Rhund_pos, Rhund_scale, boms[i].getBBOM_POS(), boms[i].getBBOM_SCALE())) {//右手と青ボタンの処理
									music::play(BOM_BOTTON);
									boms[i].setBOMB_HIT(true);
								}
								if (HITCHECK_HUND_BUTTON(Rhund_pos, Rhund_scale, boms[i].getRBOM_POS(), boms[i].getRBOM_SCALE())) {//右手と赤ボタンの処理
									if (boms[i].getBOMB_HIT() == false) {
										//爆発
										if (boms[i].getBOM_EFFECT() == false) {
											boms[i].setEFC_TIMER(0);
											boms[i].setBOM_EFFECT(true);
										}
										//can.MINUSsetKIGEN(100);
										control_stop_timer2 = 250;
										music::play(BOM);
									}
								}
							}
							if (right_hit_area == false) {
								if (HITCHECK_HUND_BUTTON(Lhund_pos, Lhund_scale, boms[i].getBBOM_POS(), boms[i].getBBOM_SCALE())) {//左手と青ボタンの処理
									music::play(BOM_BOTTON);
								}
								if (HITCHECK_HUND_BUTTON(Lhund_pos, Lhund_scale, boms[i].getRBOM_POS(), boms[i].getRBOM_SCALE())) {//左手と赤ボタンの処理
									if (boms[i].getBOMB_HIT() == false) {
										//爆発
										if (boms[i].getBOM_EFFECT() == false) {
											boms[i].setEFC_TIMER(0);
											boms[i].setBOM_EFFECT(true);
										}
										control_stop_timer2 = 250;
										//can.MINUSsetKIGEN(100);
										music::play(BOM);
									}
								}
							}
						}
					}

					if (obas[i].getCAN_ALIVE() == true) {
						if (cans[i].getCAN_COLOR() > days[day - 1].bom_pro && cans[i].getCAN_COLOR() <= days[day - 1].oba_pro) {//おばさん
							if (HITCHECK_THING(&obas[i], obas[i].getCAN_SCALE().x * obas[i].getCAN_TEXTSIZE().x,
								obas[i].getCAN_SCALE().y * obas[i].getCAN_TEXTSIZE().y) == true) {
								//横向きに変更
								if (obas[i].getOBA_HIT() == false) {
									obas[i].setOBA_HIT(true);
									control_stop_timer = 120;
									obaeffect_timer = 30;
									//obas[i].setCAN_ALIVE(false);

									can.MINUSsetKIGEN(KIGEN_MINUS);

								}
							}
						}

					}

					if (ojis[i].getCAN_ALIVE() == true) {
						if (cans[i].getCAN_COLOR() > days[day - 1].oba_pro && cans[i].getCAN_COLOR() <= days[day - 1].oji_pro) {//おじさん吹っ飛び
							if (HITCHECK_THING(&ojis[i], ojis[i].getCAN_SCALE().x * ojis[i].getCAN_TEXTSIZE().x * 1.5f,
								ojis[i].getCAN_SCALE().y * ojis[i].getCAN_TEXTSIZE().y) == true) {
								if (ojis[i].getOJI_HIT() == false) {
									ojis[i].setOJI_HIT(true);
									ojis[i].setOJI_JUMP(true);
								}
								music::play(OJI);
							}
						}
					}

					if (cans[i].getCAN_ALIVE() == true) {
						if (cans[i].getCAN_COLOR() > days[day - 1].oji_pro && cans[i].getCAN_COLOR() <= days[day - 1].errorcan_pro) {//不正解の缶
							if (HITCHECK_THING(&cans[i], cans[i].getCAN_SCALE().x * cans[i].getCAN_TEXTSIZE().x,
								cans[i].getCAN_SCALE().y * cans[i].getCAN_TEXTSIZE().y) == true) {
								//音を鳴らす
								if (day == 1)
									music::play(NO_CAN1);
								if (day == 2) {
									int sound = rand() % 2 + 1;
									if (sound == 1)
										music::play(NO_CAN1);
									if (sound == 2)
										music::play(NO_CAN2);
								}
								if (day == 3) {
									int sound = rand() % 4 + 1;
									if (sound == 1)
										music::play(NO_CAN1);
									if (sound == 2)
										music::play(NO_CAN2);
									if (sound == 3)
										music::play(NO_CAN3);
									if (sound == 4)
										music::play(NO_CAN4);
								}
							}
						}

						if (cans[i].getCAN_COLOR() > days[day - 1].errorcan_pro && cans[i].getCAN_COLOR() <= days[day - 1].can_pro) {//缶
							if (HITCHECK_THING(&cans[i], cans[i].getCAN_SCALE().x * cans[i].getCAN_TEXTSIZE().x,
								cans[i].getCAN_SCALE().y * cans[i].getCAN_TEXTSIZE().y) == true) {
								//音を鳴らす
								music::play(OK_CAN);
								music::setVolume(OK_CAN, 1.0f);//BGMの音量調
							}
						}

					}
				}
			}
			//叩いたおばさんが演出後に消える処理
			if (obas[i].getOBA_HIT() == true && obaeffect_timer <= 0) {
				obas[i].setCAN_ALIVE(false);
			}
		}
		//おじさんが飛んでいく処理
		if (ojis[i].getOJI_JUMP() == true) {
			ojis->OJI_JUMP(&ojis[i]);
		}
	}

	obaeffect_timer--;
	if (obaeffect_timer <= 0) {
		obaeffect_timer = 0;
	}
	if (obaeffect_timer == 1) {
		music::play(RAGE);
	}
	//プレイヤーが操作できないタイムの減少
	if (control_stop_timer > 0 && obaeffect_timer <= 0) {
		ObachanUpdate();
		control_stop_timer--;
	}
	if (control_stop_timer2 > 0) {
		control_stop_timer2--;
	}

	hit_timer--;
	if (hit_timer <= 0)
		hit_timer = 0;
	if (TRG(0) & PAD_TRG1 && control_stop_timer <= 0) {
		hit_timer = HIT_HUND_RENDER_TIMER;
	}
}

//缶と叩くエリアの当たり判定関数
//bool playerController::HITCHECK_CAN(Can* can) {
//	float areaL = hitarea_pos.x;
//	float areaR = hitarea_pos.x + hitarea_scale.x;
//	float areaU = hitarea_pos.y;
//	float areaD = hitarea_pos.y + hitarea_scale.y;
//
//	float canL = can->getCAN_POS().x;
//	float canR = can->getCAN_POS().x + can->getCAN_SCALE().x * can->getCAN_TEXTSIZE().x;
//	float canU = can->getCAN_POS().y;
//	float canD = can->getCAN_POS().y + can->getCAN_SCALE().y * can->getCAN_TEXTSIZE().y;
//
//	if (areaR > canL && areaL < canR &&
//		areaU<canD && areaD > canU) {
//
//		return true;
//	}
//
//	return false;
//}
//
//おばさんと叩くエリアの当たり判定関数
//bool playerController::HITCHECK_OBA(Can* oba) {
//	float areaL = hitarea_pos.x;
//	float areaR = hitarea_pos.x + hitarea_scale.x;
//	float areaU = hitarea_pos.y;
//	float areaD = hitarea_pos.y + hitarea_scale.y;
//
//	float obaL = oba->getCAN_POS().x;
//	float obaR = oba->getCAN_POS().x + 130;//oba->getCAN_SCALE().x * oba->getOBA_TEXTSIZE().x;
//	float obaU = oba->getCAN_POS().y;
//	float obaD = oba->getCAN_POS().y + oba->getCAN_SCALE().y * oba->getOBA_TEXTSIZE().y;
//
//	if (areaR > obaL && areaL < obaR &&
//		areaU<obaD && areaD > obaU) {
//
//		return true;
//	}
//
//	return false;
//}
//
//おじさんと叩くエリアの当たり判定関数
//bool playerController::HITCHECK_OJI(Can* oji) {
//	float areaL = hitarea_pos.x;
//	float areaR = hitarea_pos.x + hitarea_scale.x;
//	float areaU = hitarea_pos.y;
//	float areaD = hitarea_pos.y + hitarea_scale.y;
//
//	float ojiL = oji->getCAN_POS().x;
//	float ojiR = oji->getCAN_POS().x + 180;//oba->getCAN_SCALE().x * oba->getOBA_TEXTSIZE().x;
//	float ojiU = oji->getCAN_POS().y;
//	float ojiD = oji->getCAN_POS().y + oji->getCAN_SCALE().y * oji->getOJI_TEXTSIZE().y;
//
//	if (areaR > ojiL && areaL < ojiR &&
//		areaU<ojiD && areaD > ojiU) {
//
//		return true;
//	}
//
//	return false;
//}
//
////爆弾と叩くエリアの当たり判定関数
//bool playerController::HITCHECK_BOM(Can* bom) {
//	float areaL = hitarea_pos.x;
//	float areaR = hitarea_pos.x + hitarea_scale.x;
//	float areaU = hitarea_pos.y;
//	float areaD = hitarea_pos.y + hitarea_scale.y;
//
//	float bomL = bom->getCAN_POS().x;
//	float bomR = bom->getCAN_POS().x + bom->getCAN_SCALE().x * bom->getOBA_TEXTSIZE().x;
//	float bomU = bom->getCAN_POS().y;
//	float bomD = bom->getCAN_POS().y + bom->getCAN_SCALE().y * bom->getOJI_TEXTSIZE().y;
//
//	if (areaR > bomL && areaL < bomR &&
//		areaU<bomD && areaD > bomU) {
//
//		return true;
//	}
//
//	return false;
//}

//流れている物と叩くエリアの当たり判定関数
bool playerController::HITCHECK_THING(Can* thing, float textX, float textY) {
	float areaL = hitarea_pos.x;
	float areaR = hitarea_pos.x + hitarea_scale.x;
	float areaU = hitarea_pos.y;
	float areaD = hitarea_pos.y + hitarea_scale.y;

	float thingL = thing->getCAN_POS().x;
	float thingR = thing->getCAN_POS().x + textX;
	float thingU = thing->getCAN_POS().y;
	float thingD = thing->getCAN_POS().y + textY;

	if (areaR > thingL && areaL < thingR &&
		areaU<thingD && areaD > thingU) {

		return true;
	}

	return false;
}

//左右の手と爆弾の左右のボタンの当たり判定関数
bool playerController::HITCHECK_HUND_BUTTON(
	VECTOR2 hund_pos, VECTOR2 hund_size, VECTOR2 button_pos, VECTOR2 button_size) {
	float hundL = hund_pos.x;
	float hundR = hund_pos.x + hund_size.x;
	float hundU = hund_pos.y;
	float hundD = hund_pos.y + hund_size.y;

	float buttonL = button_pos.x;
	float buttonR = button_pos.x + button_size.x;
	float buttonU = button_pos.y;
	float buttonD = button_pos.y + button_size.y;

	if (hundR > buttonL && hundL < buttonR &&
		hundU<buttonD && hundD > buttonU) {

		return true;
	}

	return false;

}

//playerの弾く動作関数
void playerController::PLAYER_FLICK_CAN(Can* cans, Can* obas, Can* ojis, Can* boms, int day) {
	debug::setString("flick_error_can:%i", flick_errorcan_count);
	debug::setString("flick_other:%i", flick_other_count);

	for (int i = 0; i < days[day - 1].CAN_NUM; i++) {
		if (control_stop_timer <= 0) {
			if (main_conveyor == false) {
				if (TRG(0) & PAD_TRG1) {
					if (boms[i].getCAN_ALIVE() == true && cans[i].getCAN_COLOR() <= days[day - 1].bom_pro) {//爆弾
						if (FLICKCHECK_THING(&boms[i], boms[i].getCAN_SCALE().x * boms[i].getCAN_TEXTSIZE().x * 1.6f,
							boms[i].getCAN_SCALE().y * boms[i].getCAN_TEXTSIZE().y) == true && boms[i].getFLICK_FLAG() == false) {
							if (boms[i].getBOMB_HIT() == true) {
								//爆弾を弾く、消す
								flick_other_count++;
								can.PLUSsetKIGEN(KIGEN_PLUS);
								boms[i].setGRA_FLAG(true);
								boms[i].setFLICK_FLAG(true);
							}

							if (boms[i].getBOMB_HIT() == false) {
								if (boms[i].getBOMB_HIT() == false) {
									//爆発
									if (boms[i].getBOM_EFFECT() == false) {
										boms[i].setEFC_TIMER(0);
										boms[i].setBOM_EFFECT(true);
									}
									control_stop_timer2 = 250;
									//can.MINUSsetKIGEN(100);
									music::play(BOM);
								}
							}
						}
					}

					if (obas[i].getCAN_ALIVE() == true && cans[i].getCAN_COLOR() > days[day - 1].bom_pro && cans[i].getCAN_COLOR() <= days[day - 1].oba_pro) {//おばさん
						if (FLICKCHECK_THING(&obas[i], obas[i].getCAN_SCALE().x * obas[i].getCAN_TEXTSIZE().x,
							obas[i].getCAN_SCALE().y * obas[i].getCAN_TEXTSIZE().y) == true && obas[i].getFLICK_FLAG() == false) {
							//おばさんを弾く、消す
							flick_other_count++;
							can.PLUSsetKIGEN(KIGEN_PLUS);
							obas[i].setGRA_FLAG(true);
							obas[i].setFLICK_FLAG(true);

						}
					}

					if (ojis[i].getCAN_ALIVE() == true && cans[i].getCAN_COLOR() > days[day - 1].oba_pro && cans[i].getCAN_COLOR() <= days[day - 1].oji_pro) {//おじさん
						if (FLICKCHECK_THING(&ojis[i], ojis[i].getCAN_SCALE().x * ojis[i].getCAN_TEXTSIZE().x * 1.5f,
							ojis[i].getCAN_SCALE().y * ojis[i].getCAN_TEXTSIZE().y) == true && ojis[i].getFLICK_FLAG() == false) {
							//おじさんを弾く、消す
							flick_other_count++;
							can.PLUSsetKIGEN(KIGEN_PLUS);
							ojis[i].setGRA_FLAG(true);
							ojis[i].setFLICK_FLAG(true);

						}
					}

					if (cans[i].getCAN_ALIVE() == true && cans[i].getCAN_COLOR() > days[day - 1].oji_pro && cans[i].getCAN_COLOR() <= days[day - 1].errorcan_pro) {//不正解の缶
						if (FLICKCHECK_THING(&cans[i], cans[i].getCAN_SCALE().x * cans[i].getCAN_TEXTSIZE().x,
							cans[i].getCAN_SCALE().y * cans[i].getCAN_TEXTSIZE().y) == true && cans[i].getFLICK_FLAG() == false) {
							//缶を弾く、消す
							flick_errorcan_count++;
							can.PLUSsetKIGEN(KIGEN_PLUS);
							cans[i].setGRA_FLAG(true);
							cans[i].setFLICK_FLAG(true);

						}
					}

					if (cans[i].getCAN_ALIVE() == true && cans[i].getCAN_COLOR() > days[day - 1].errorcan_pro && cans[i].getCAN_COLOR() <= days[day - 1].can_pro) {//缶
						if (FLICKCHECK_THING(&cans[i], cans[i].getCAN_SCALE().x * cans[i].getCAN_TEXTSIZE().x,
							cans[i].getCAN_SCALE().y * cans[i].getCAN_TEXTSIZE().y) == true && cans[i].getFLICK_FLAG() == false) {
							//缶を弾く、消す
							can.MINUSsetKIGEN(KIGEN_MINUS);
							cans[i].setGRA_FLAG(true);
							cans[i].setFLICK_FLAG(true);

						}
					}
				}
			}
		}
	}
	flick_timer--;
	if (flick_timer <= 0)
		flick_timer = 0;
	if (TRG(0) & PAD_TRG1 && control_stop_timer <= 0) {
		flick_timer = FLICK_HUND_RENDER_TIMER;
	}
}

//流れている物と弾くエリアの当たり判定関数
bool playerController::FLICKCHECK_THING(Can* thing, float textX, float textY) {
	float areaL = flickarea_pos.x;
	float areaR = flickarea_pos.x + flickarea_scale.x;
	float areaU = flickarea_pos.y;
	float areaD = flickarea_pos.y + flickarea_scale.y;

	float thingL = thing->getCAN_POS().x;
	float thingR = thing->getCAN_POS().x + textX;
	float thingU = thing->getCAN_POS().y;
	float thingD = thing->getCAN_POS().y + textY;

	if (areaR > thingL && areaL < thingR &&
		areaU<thingD && areaD > thingU) {

		return true;
	}

	return false;
}

//缶と弾くエリアの当たり判定関数
//bool playerController::FLICKCHECK_CAN(Can* can) {
//	float areaL = flickarea_pos.x;
//	float areaR = flickarea_pos.x + flickarea_scale.x;
//	float areaU = flickarea_pos.y;
//	float areaD = flickarea_pos.y + flickarea_scale.y;
//
//	float canL = can->getCAN_POS().x;
//	float canR = can->getCAN_POS().x + can->getCAN_SCALE().x * can->getCAN_TEXTSIZE().x;
//	float canU = can->getCAN_POS().y;
//	float canD = can->getCAN_POS().y + can->getCAN_SCALE().y * can->getCAN_TEXTSIZE().y;
//
//	if (areaR > canL && areaL < canR &&
//		areaU<canD && areaD > canU) {
//
//		return true;
//	}
//	return false;
//}
//
////おじさんと弾くエリアの当たり判定関数
//bool playerController::FLICKCHECK_OJI(Can* oji) {
//	float areaL = flickarea_pos.x;
//	float areaR = flickarea_pos.x + flickarea_scale.x;
//	float areaU = flickarea_pos.y;
//	float areaD = flickarea_pos.y + flickarea_scale.y;
//
//	float ojiL = oji->getCAN_POS().x;
//	float ojiR = oji->getCAN_POS().x + (oji->getCAN_SCALE().x * 1.5) * oji->getCAN_TEXTSIZE().x;
//	float ojiU = oji->getCAN_POS().y;
//	float ojiD = oji->getCAN_POS().y + oji->getCAN_SCALE().y * oji->getCAN_TEXTSIZE().y;
//
//	if (areaR > ojiL && areaL < ojiR &&
//		areaU<ojiD && areaD > ojiU) {
//
//		return true;
//	}
//	return false;
//}
//
////おばさんと弾くエリアの当たり判定関数
//bool playerController::FLICKCHECK_OBA(Can* oba) {
//	float areaL = flickarea_pos.x;
//	float areaR = flickarea_pos.x + flickarea_scale.x;
//	float areaU = flickarea_pos.y;
//	float areaD = flickarea_pos.y + flickarea_scale.y;
//
//	float obaL = oba->getCAN_POS().x;
//	float obaR = oba->getCAN_POS().x + oba->getCAN_SCALE().x * oba->getCAN_TEXTSIZE().x;
//	float obaU = oba->getCAN_POS().y;
//	float obaD = oba->getCAN_POS().y + oba->getCAN_SCALE().y * oba->getCAN_TEXTSIZE().y;
//
//	if (areaR > obaL && areaL < obaR &&
//		areaU<obaD && areaD > obaU) {
//
//		return true;
//	}
//	return false;
//}
//
////爆弾と弾くエリアの当たり判定関数
//bool playerController::FLICKCHECK_BOM(Can* bom) {
//	float areaL = flickarea_pos.x;
//	float areaR = flickarea_pos.x + flickarea_scale.x;
//	float areaU = flickarea_pos.y;
//	float areaD = flickarea_pos.y + flickarea_scale.y;
//
//	float bomL = bom->getCAN_POS().x;
//	float bomR = bom->getCAN_POS().x + (bom->getCAN_SCALE().x * 1.6f) * bom->getCAN_TEXTSIZE().x;
//	float bomU = bom->getCAN_POS().y;
//	float bomD = bom->getCAN_POS().y + bom->getCAN_SCALE().y * bom->getCAN_TEXTSIZE().y;
//
//	if (areaR > bomL && areaL < bomR &&
//		areaU<bomD && areaD > bomU) {
//
//		return true;
//	}
//	return false;
//}

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

VECTOR2 playerController::getRHUND_POS() {
	return Rhund_pos;
}

VECTOR2 playerController::getLHUND_POS() {
	return Lhund_pos;
}

VECTOR2 playerController::getRHUND_SCALE() {
	return Rhund_scale;
}

VECTOR2 playerController::getLHUND_SCALE() {
	return Lhund_scale;
}

//不正解の缶の回収数のゲッター関数
int playerController::getFLICK_ERRORCAN_COUNT() {
	return flick_errorcan_count;
}

//缶以外の物の回収した合計数のゲッター関数
int playerController::getFLICK_OTHERCAN_COUNT() {
	return flick_other_count;
}

// 左右のみの切替
void playerController::TUTORIAL_HITAREA_CHANGE()
{
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

void playerController::PLAYER_RESET()
{
	control_stop_timer = 0;
	control_stop_timer2 = 0;
	flick_errorcan_count = 0;
	flick_other_count = 0;

	hit_timer = 0;
	flick_timer = 0;
	obaeffect_timer = 0;
}
