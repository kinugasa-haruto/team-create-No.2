#include "all.h"

int tutorial_state;
int tutorial_timer;


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
		//////// ‰ŠúÝ’è ////////


		tutorial_state++;
		/*fallthrough*/

	case 1:
		//////// ƒpƒ‰ƒ[ƒ^‚ÌÝ’è ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);


		tutorial_state++;
		/*fallthrough*/

	case 2:
		//////// ’ÊíŽž ////////

		break;
	}


	tutorial_timer++;
}

void tutorial_render()
{
	// ‰æ–Ê‚ðÂ‚Å“h‚è‚Â‚Ô‚·
	GameLib::clear(1, 1, 1);



	for (float inv = 1.0f; inv > 0; inv *= 0.8f)
	{
		if (inv <= 0.1f) inv = 0;
		primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 0, 0, 0, inv);
	}
}
