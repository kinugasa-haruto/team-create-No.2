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

SkipButton skipbutton = SkipButton::Instance();

void SkipButton::Update()
{
	if (STATE(0) & PAD_START)
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

		inv = 0;

		tutorial_state++;
		/*fallthrough*/

	case 2:
		//////// 通常時 ////////
		if (inv < 1)
		{
			static float timer = 0;
			timer += 0.01f;
			inv = Easing::easeIn3(timer);
			if (inv >= 9.99f) inv = 1;
		}

		back_update();
		skipbutton.Update();

		//缶の移動関数はずっと呼んでいて欲しい、正しい缶と不正解の缶のUPDATE関数は必要に応じて呼んでほしい
		can.CAN_MOVE(cans, obas, ojis, boms, 1);//缶の移動関数

		TUTORIAL_CAN_UPDATE();		//正しい缶の生成と缶を叩く、弾く動作を入れた関数
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

	//正しい缶と不正解の缶のRENDER関数は必要に応じて呼んでほしい
	can.CAN_RENDER(cans, obas, ojis, boms, 8);		//正解の缶の描画関数
	//can.CAN_RENDER(cans, obas, ojis, boms, 9);	//不正解の缶の描画関数
	player.HITAREA_FLICKAREA_RENDER();			//手の描画


	primitive::rect(0, 0, SCREEN_W, SCREEN_H - SCREEN_H * inv, 0, 0, ToRadian(0), 0, 0, 0);
	skipbutton.Render();
	
}
