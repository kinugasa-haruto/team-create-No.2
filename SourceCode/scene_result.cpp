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



		break;
	}

	result_timer++;
}

//--------------------------------------
//  •`‰æˆ—
//--------------------------------------
void result_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);


}
