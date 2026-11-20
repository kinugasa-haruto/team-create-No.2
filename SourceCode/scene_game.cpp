#include "all.h"
#include <vector>
#include <sstream>

int game_state;
int game_timer;

// 1ゲームの長さ（秒）
#define GAME_LENGTH 90
GameTimer gameTimer = GameTimer::Instance();
NextDay nextday = NextDay::Instance();
StartTimer starttimer = StartTimer::Instance();

Can cans[500];
Can obas[500];
Can ojis[500];
Can boms[500];
Can can;
playerController player;

extern int debug_flick;
extern int debug_miss;

bool nextDay; // 次の日に行ったかどうか
int gameDay; // 現在の日付
gameNumber gamenumber;

void game_init()
{
	game_state      = 0;
	game_timer      = 0;
	gameDay = 1;
	nextDay = false;
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
		if (!nextDay)
		{
			// ここに初期化処理
			can.CAN_RESET(cans, obas, ojis, boms);
			back_init();
			starttimer.Reset();
			gamenumber.Update({ SCREEN_HALF_W - 300, SCREEN_HALF_H - 50 }, gameDay, 0);
			nextday.Reset();
			gameTimer.reset();
			resultBinder.reset();
			GAME_DAY(gameDay);
			nextDay = true;
		}
		if (starttimer.Update()) {}
		else
		{

			if (!can.CAN_ALL_VANISH(cans, obas, ojis, boms))
			{
			 	GAME_DAY(gameDay);
			}
			else
			{
				if (gameTimer.timerUpdate() == true) {}
				else
				{
					if (resultBinder.GetNext() && TRG(0) & PAD_TRG1)
					{
						resultBinder.SetBinderType(1);
					}

					if (resultBinder.GetBinderType() == 0) resultBinder.Up();
					if (resultBinder.GetBinderType() == 1) resultBinder.Down();

					
					if (resultBinder.GetBinderType() == 1 && resultBinder.GetScale() == 0)
					{
						nextday.Update();
					}
					
				}
			}

			can.getERRORCAN_COUNT();//不正解の缶の生成数のゲッター関数
			can.getOTHERCAN_COUNT();//缶以外の生成合計数のゲッター関数
			player.getFLICK_ERRORCAN_COUNT();//不正解の缶の回収数のゲッター関数
			player.getFLICK_OTHERCAN_COUNT();//缶以外の物の回収した合計数のゲッター関数


			break;
		}

	}

	game_timer++;
}

//--------------------------------------
//  描画処理
//--------------------------------------
void game_render()
{
	GAME_DAY_RENDER(gameDay);
	gameTimer.timerRender();
	resultBinder.Render();
	starttimer.Render();
	nextday.Render();
}
