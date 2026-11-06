#include "all.h"

int back_state;
int back_timer;

Conveyor conveyor[2] = { {{0, SCREEN_HALF_H - 50},{SCREEN_W, 100, 0, 0}},{{0, SCREEN_W - 150},{SCREEN_W, 100, 0, 0}} };

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
	
	for (int i = 0; i < 2; i++)
	{
		primitive::rect(conveyor[i].GetPosition().x, conveyor[i].GetPosition().y,  conveyor[i].GetRect().x,conveyor[i].GetRect().y , conveyor[i].GetRect().z,conveyor[i].GetRect().w, ToRadian(0), 0.6f, 0.8f, 0.6f);
	}

}
