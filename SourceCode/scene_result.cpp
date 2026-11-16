#include "all.h"

int result_state;
int result_timer;

void result_init()
{
	result_state = 0;
	result_timer = 0;
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
		resultBinder.Update();

		if (resultBinder.GetScale() == 1.0f && TRG(0) & PAD_START)
		{
			nextScene = SCENE_TITLE;
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
	GameLib::clear(0,0,0);
	resultBinder.Render();

}
