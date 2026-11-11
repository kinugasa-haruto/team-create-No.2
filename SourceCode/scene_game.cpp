#include "all.h"

int game_state;
int game_timer;

// 1ゲームの長さ（秒）
#define GAME_LENGTH 90

Can cans[CAN_NUM];
Can can;
playerController player;

void game_init()
{
	game_state      = 0;
	game_timer      = 0;
}

void game_deinit()
{

}

void game_update()
{
	switch (game_state)
	{
	case 0:
		//////// 初期設定 ////////


		game_state++;
		/*fallthrough*/

	case 1:
		//////// パラメータの設定 ////////
		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;
		/*fallthrough*/

	case 2:
		//////// 通常時 ////////
		back_update();
		// ゲームの経過時間
		static int gameTimer = 0;

		// 1フレームの長さ（60フレーム＝1）
		gameTimer += 1.0f / 60;

		// 経過時間が1ゲームの長さを超えたらリザルトへ
		if (gameTimer > GAME_LENGTH)
		{
			nextScene = SCENE_RESULT;
		}
		
		
		
		can.CAN_GENERATE(cans);		//缶の生成関数
		can.CAN_MOVE(cans);			//缶の移動関数
		player.HITCHECK_CAN(cans);	//缶と叩くエリアの当たり判定関数
		player.PLAYER_HIT_CAN(cans);//playerの叩く動作関数
		player.FLICKCHECK_CAN(cans);//缶と弾くエリアの当たり判定関数
		player.PLAYER_FLICK_CAN(cans);//playerの弾く動作関数
		
		
		break;
	}

	game_timer++;
}

//--------------------------------------
//  描画処理
//--------------------------------------
void game_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	back_render();
	player.HITAREA_RENDER();	//叩くエリアの描画
	player.FLICKAREA_RENDER();	//弾くエリアの描画
	can.CAN_RENDER(cans);		//缶の描画関数

}
