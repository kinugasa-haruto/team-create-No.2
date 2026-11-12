#include "all.h"
#include <vector>

int game_state;
int game_timer;

// 1ƒQ[ƒ€‚Ì’·‚³i•bj
#define GAME_LENGTH 90

//Can cans[CAN_NUM];
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
		//////// ‰Šúİ’è ////////


		game_state++;
		/*fallthrough*/

	case 1:
		//////// ƒpƒ‰ƒ[ƒ^‚Ìİ’è ////////
		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;
		/*fallthrough*/

	case 2:
		//////// ’Êí ////////
		back_update();
		can.CAN_GENERATE(cans,1);		//ŠÊ‚Ì¶¬ŠÖ”
		can.CAN_MOVE(cans,1);			//ŠÊ‚ÌˆÚ“®ŠÖ”
		player.HITCHECK_CAN(cans,1);	//ŠÊ‚Æ’@‚­ƒGƒŠƒA‚Ì“–‚½‚è”»’èŠÖ”
		player.PLAYER_HIT_CAN(cans,1);//player‚Ì’@‚­“®ìŠÖ”
		player.FLICKCHECK_CAN(cans,1);//ŠÊ‚Æ’e‚­ƒGƒŠƒA‚Ì“–‚½‚è”»’èŠÖ”
		player.PLAYER_FLICK_CAN(cans,1);//player‚Ì’e‚­“®ìŠÖ”

		
		break;
	}

	game_timer++;
}

//--------------------------------------
//  •`‰æˆ—
//--------------------------------------
void game_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	back_render();
	player.HITAREA_FLICKAREA_RENDER();	//’@‚­,’e‚­ƒGƒŠƒA‚Ì•`‰æ
	can.CAN_RENDER(cans,1);		//ŠÊ‚Ì•`‰æŠÖ”

}
