#include "all.h"
#include <vector>

int game_state;
int game_timer;

// 1ゲームの長さ（秒）
#define GAME_LENGTH 90
GameTimer gameTimer = GameTimer::Instance();

Can cans[500];
Can obas[500];
Can ojis[500];
Can boms[500];
Can can;
playerController player;

extern int debug_flick;
extern int debug_miss;

int Day;

void game_init()
{
	game_state      = 0;
	game_timer      = 0;
	Day = 1;
}

void game_deinit()
{
	gameTimer.reset();
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
		GAME_DAY(1);

		can.getERRORCAN_COUNT();//不正解の缶の生成数のゲッター関数
		can.getOTHERCAN_COUNT();//缶以外の生成合計数のゲッター関数
		player.getFLICK_ERRORCAN_COUNT();//不正解の缶の回収数のゲッター関数
		player.getFLICK_OTHERCAN_COUNT();//缶以外の物の回収した合計数のゲッター関数


		break;
	}

	game_timer++;
}

//--------------------------------------
//  描画処理
//--------------------------------------
void game_render()
{
	GAME_DAY_RENDER(1);

}
