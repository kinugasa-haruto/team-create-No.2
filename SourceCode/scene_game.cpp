#include "all.h"
#include <vector>

int game_state;
int game_timer;

// 1ゲームの長さ（秒）
#define GAME_LENGTH 90
GameTimer gameTimer = GameTimer::Instance();
NextDay nextday = NextDay::Instance();

Can cans[500];
Can obas[500];
Can ojis[500];
Can boms[500];
Can can;
playerController player;

extern int debug_flick;
extern int debug_miss;

bool nextDay;
int gameDay;
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
		switch (gameDay)
		{
		case 1:
			if (!nextDay)
			{
				// ここに初期化処理

				GAME_DAY(1);
				nextDay = true;
			}
			if (!can.CAN_ALL_VANISH(cans, obas, ojis, boms))
			{
         				GAME_DAY(1);
			}
			else
			{
				if (gameTimer.timerUpdate() == true) {}
				else
				{
					resultBinder.Up();

					if (resultBinder.GetScale() == 1.0f && TRG(0) & PAD_START)
					{
						resultBinder.SetBinderType(1);
						gameTimer.reset();
						gameDay++;
					}
					if (resultBinder.GetBinderType() == 1)resultBinder.Down();
					
					if (resultBinder.GetBinderType() == 1 && resultBinder.GetScale() == 0)
					{
						gamenumber.NumberRender({ SCREEN_HALF_W - 300, SCREEN_HALF_H - 50 }, gameDay);
						nextday.Update();
					}
					
				}
			}
			break;
		case 2:
			GAME_DAY(2);
			break;
		}




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
	resultBinder.Render();
	gamenumber.Render();
	nextday.Render();
}
