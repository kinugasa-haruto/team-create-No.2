#include "all.h"
#include <vector>

int game_state;
int game_timer;

Can cans[20];
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
		can.CAN_GENERATE(cans,1);		//缶の生成関数
		can.CAN_MOVE(cans);			//缶の移動関数
		player.HITCHECK_CAN(cans,1);	//缶と叩くエリアの当たり判定関数
		player.PLAYER_HIT_CAN(cans,1);//playerの叩く動作関数
		player.FLICKCHECK_CAN(cans,1);//缶と弾くエリアの当たり判定関数
		player.PLAYER_FLICK_CAN(cans,1);//playerの弾く動作関数
		player.BELTCONVEYOR_HITAREA_CHANGE();//ベルトコンベアの上下と叩くエリアの左右切り替え関数


		
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
	player.HITAREA_FLICKAREA_RENDER();	//叩くエリアの描画//弾くエリアの描画
	can.CAN_RENDER(cans);		//缶の描画関数

}
