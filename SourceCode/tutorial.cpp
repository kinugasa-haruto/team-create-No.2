#include "all.h"

int tutorial_state;
int tutorial_timer;

float inv;

void tutorial_init()
{
	tutorial_state = 0;
	tutorial_timer = 0;
}

void tutorial_deinit()
{


}

void tutorial_update()
{
	switch (tutorial_state)
	{
	case 0:
		//////// ‰Šúİ’è ////////


		tutorial_state++;
		/*fallthrough*/

	case 1:
		//////// ƒpƒ‰ƒ[ƒ^‚Ìİ’è ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);

		inv = 1.0f;

		tutorial_state++;
		/*fallthrough*/

	case 2:
		//////// ’Êí ////////

		inv -= 0.01f;
		if (inv <= 0.01f) inv = 0;
		break;
	}


	tutorial_timer++;
}

void tutorial_render()
{
	// ‰æ–Ê‚ğÂ‚Å“h‚è‚Â‚Ô‚·
	GameLib::clear(1, 1, 1);

	back_render();
	primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 0, 0, 0, inv);
	
}
