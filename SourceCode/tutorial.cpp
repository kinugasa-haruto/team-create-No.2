#include "all.h"



int tutorial_state;
int tutorial_timer;

extern Can cans[500];
extern Can obas[500];
extern Can ojis[500];
extern Can boms[500];
extern Can can;
extern playerController player;

float inv;
static float timer;
static int tutorialTimer;

SkipButton skipbutton = SkipButton::Instance();
TutorialText tt = TutorialText::Instance();

void SkipButton::Update()
{
	if (STATE(0) & PAD_TRG1)
	{
		timer++;

	}
	else timer = 0;

	progress = Easing::easeIn3(timer / 120.0f);

	if (progress >= 1)
	{
		inv += 0.5f / 4;
		if (inv >= 0.5f) nextScene = SCENE_GAME;
	}
	debug::setString("timer:%d", timer);
}

void tutorial_init()
{
	tutorial_state = 0;
	tutorial_timer = 0;
	skipbutton.Reset();
	can.CAN_RESET(cans, obas, ojis, boms);  // 試験的に追加したやつ
	timer = 0;
	tutorialTimer = 0;
}

void tutorial_deinit()
{
	

}

void tutorial_update()
{
	switch (tutorial_state)
	{
	case 0:
		//////// 初期設定 ////////


		tutorial_state++;
		/*fallthrough*/

	case 1:
		//////// パラメータの設定 ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);

		tt.SetProgress(-1);
		inv = 0;

		tutorial_state++;
		/*fallthrough*/

	case 2:
		//////// 通常時 ////////
		if (inv < 1)
		{
			timer += 0.01f;
			inv = Easing::easeIn3(timer);
			if (inv >= 9.99f) inv = 1;
		}
		//缶の移動関数はずっと呼んでいて欲しい、正しい缶と不正解の缶のUPDATE関数は必要に応じて呼んでほしい
		can.CAN_MOVE(cans, obas, ojis, boms, 1);//缶の移動関数
		back_update(2.0f);
		skipbutton.Update();
		tutorialTimer++;
		if (tutorialTimer > 5 * 60 && tt.GetProgress() == -1)
		{
			tt.SetProgress(0);
		}
		if (tutorialTimer > 9 * 60 && tt.GetProgress() == 0)
		{
			can.CAN_GENERATE(cans, obas, ojis, boms, 9); //缶の生成関数
		}
		if (player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y) && tt.GetProgress() == 0)//缶と叩くエリアの当たり判定関数
		{
			
				if (TRG(0) & PAD_TRG1)
				{
					player.PLAYER_HIT_CAN(cans, obas, ojis, boms, 9); //playerの缶を叩く動作関数
					tt.SetProgress(1);
					tutorialTimer = 0;
				}
				return;
			
		}									
		if (tutorialTimer > 9 && tt.GetProgress() == 1)
		{

		}
		//player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);//缶と弾くエリアの当たり判定関数
		//player.PLAYER_FLICK_CAN(cans, obas, ojis, boms, 8);



		//TUTORIAL_CAN_UPDATE();		//正しい缶の生成と缶を叩く、弾く動作を入れた関数
		//TUTORIAL_MISSCAN_UPDATE();//不正解の缶の生成と缶を叩く、弾く動作を入れた関数
		
		player.BELTCONVEYOR_HITAREA_CHANGE();//ベルトコンベアの上下と叩くエリアの左右切り替え関数
		can.getCAN_POS();					//缶のposのゲッター関数

		break;
	}


	tutorial_timer++;
}

void tutorial_render()
{
	// 画面を青で塗りつぶす
	GameLib::clear(1, 1, 1);

	back_render();
	conveyor_render();
	tt.Render();
	//正しい缶と不正解の缶のRENDER関数は必要に応じて呼んでほしい
	can.CAN_RENDER(cans, obas, ojis, boms, 8);		//正解の缶の描画関数
	//can.CAN_RENDER(cans, obas, ojis, boms, 9);	//不正解の缶の描画関数
	judgearea_render();
	player.HITAREA_FLICKAREA_RENDER();			//手の描画
	
	skipbutton.Render();
	
	sprite_render(shutter, 0, 0 - SCREEN_H * inv, 1, 1, 0, 0, SCREEN_W, SCREEN_H, 0, 0);
	//primitive::rect(0, 0, SCREEN_W, SCREEN_H - SCREEN_H * inv, 0, 0, ToRadian(0), 0, 0, 0);

}


