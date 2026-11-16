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

void game_init()
{
	game_state      = 0;
	game_timer      = 0;
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
		back_update();
		can.CAN_GENERATE(cans, obas, ojis, boms, 1);			//缶の生成関数
		can.CAN_MOVE(cans,obas,ojis,boms,1);//缶の移動関数

		//流れている物と叩くエリアの当たり判定関数
		player.HITCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);
		player.HITCHECK_THING(ojis, ojis->getCAN_TEXTSIZE().x, ojis->getCAN_TEXTSIZE().y);
		player.HITCHECK_THING(obas, obas->getCAN_TEXTSIZE().x, obas->getCAN_TEXTSIZE().y);
		player.HITCHECK_HUND_BUTTON(player.getRHUND_POS(), player.getRHUND_SCALE(), boms->getBBOM_POS(), boms->getBBOM_SCALE());//右手と青ボタンの当たり判定
		player.PLAYER_HIT_CAN(cans,obas,ojis,boms,1);//playerの叩く動作関数

		//流れている物と弾くエリアの当たり判定関数
		player.FLICKCHECK_THING(cans, cans->getCAN_TEXTSIZE().x, cans->getCAN_TEXTSIZE().y);
		player.FLICKCHECK_THING(ojis, ojis->getCAN_TEXTSIZE().x, ojis->getCAN_TEXTSIZE().y);
		player.FLICKCHECK_THING(obas, obas->getCAN_TEXTSIZE().x, obas->getCAN_TEXTSIZE().y);
		player.FLICKCHECK_THING(boms, boms->getCAN_TEXTSIZE().x, boms->getCAN_TEXTSIZE().y);
		player.PLAYER_FLICK_CAN(cans,obas,ojis,boms,1);//playerの弾く動作関数

		player.BELTCONVEYOR_HITAREA_CHANGE();//ベルトコンベアの上下と叩くエリアの左右切り替え関数

		can.CAN_ALL_VANISH(cans, obas, ojis, boms);//１日に流れるものが全部消えたかの処理
		debug::setString("FLICK:%d MISS:%d", debug_flick, debug_miss);
		gameTimer.timerUpdate();



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
	can.OJI_BACK_RENDER(cans,ojis,1);//おじさんがコンベアの後ろに消える処理
	conveyor_render();
	can.CAN_RENDER(cans,obas,ojis,boms,1);		//缶の描画関数
	player.HITAREA_FLICKAREA_RENDER();	//叩く,弾くエリアの描画
	can.DAY_CLEAR(cans, obas, ojis, boms, 1);//CLEAR時の関数	ゲージの描画

	gameTimer.timerRender();
}
