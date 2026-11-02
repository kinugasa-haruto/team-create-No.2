#include "all.h"

int back_state;
int back_timer;


void back_init()
{
	back_state = 0;
	back_timer = 0;
}

void back_deinit()
{


}

void back_update()
{
	switch (back_state)
	{
	case 0:
		//////// ‰Šúİ’è ////////


		back_state++;
		/*fallthrough*/

	case 1:
		//////// ƒpƒ‰ƒ[ƒ^‚Ìİ’è ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);


		back_state++;
		/*fallthrough*/

	case 2:
		//////// ’Êí ////////

		break;
	}


	back_timer++;
}

void back_render()
{
	// ‰æ–Ê‚ğÂ‚Å“h‚è‚Â‚Ô‚·
	GameLib::clear(0.3f, 0.5f, 1.0f);

}
