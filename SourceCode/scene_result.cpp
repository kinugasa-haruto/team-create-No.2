#include "all.h"

int result_state;
int result_timer;

extern Can cans[500];
extern Can obas[500];
extern Can ojis[500];
extern Can boms[500];
extern Can can;

bool Clear;
static bool click;

Result result = Result::Instance();


void result_init()
{
	result_state = 0;
	result_timer = 0;
	can.CAN_RESET(cans, obas, ojis, boms);
	back_init();
	result.Reset();
	click = false;
}

void result_deinit()
{

}

void result_update()
{
	switch (result_state)
	{
	case 0:
		//////// ‰Šúİ’è ////////

		result_state++;
		/*fallthrough*/

	case 1:
		//////// ƒpƒ‰ƒ[ƒ^‚Ìİ’è ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);



		result_state++;
		/*fallthrough*/

	case 2:
		//////// ’Êí ////////
		if (result.ShutterUpdate()) result_state++;
		break;
	case 3:
		if (result.Update(Clear))
		{
			if (TRG(0) & PAD_TRG1)
			{
				if (!click)
				{
					music::play(CLICK);
					click = true;
				}
				spacebar.Reset();
				nextScene = SCENE_TITLE;
			}
		}




		break;
	}

	result_timer++;
}

//--------------------------------------
//  •`‰æˆ—
//--------------------------------------
void result_render()
{
	GameLib::clear(0, 0, 0);

	result.Render();
}
