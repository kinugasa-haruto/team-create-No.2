#include "all.h"

int back_state;
int back_timer;
Sprite* back;
Sprite* conveyor1;
Sprite* conveyor2;

Conveyor conveyor[2] = { {{0, SCREEN_HALF_H - 50},{0, 0, SCREEN_W, 238}},{{0, SCREEN_W - 150},{0, 0, SCREEN_W, 238}} };

void back_init()
{
	back_state = 0;
	back_timer = 0;
	back = sprite_load(L"./Data/Images/gamen.png");
	conveyor1 = sprite_load(L"./Data/Images/Konbea_1.png");
	conveyor2 = sprite_load(L"./Data/Images/Konbea_2.png");
}

void back_deinit()
{
	safe_delete(conveyor1);
	safe_delete(conveyor2);
	safe_delete(back);
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

	sprite_render(back, 0, 0, 1, 1, 0, 0, SCREEN_W, SCREEN_H, 0, 0);
	
	for (int i = 0; i < 2; i++)
	{
		sprite_render(conveyor1, conveyor[i].GetPosition().x, conveyor[i].GetPosition().y, 1, 1, conveyor[i].GetRect().x,conveyor[i].GetRect().y , conveyor[i].GetRect().z,conveyor[i].GetRect().w, ToRadian(0));
		sprite_render(conveyor2, conveyor[i].GetPosition().x, conveyor[i].GetPosition().y, 1, 1, conveyor[i].GetRect().x,conveyor[i].GetRect().y , conveyor[i].GetRect().z,conveyor[i].GetRect().w, ToRadian(0));
	
	}
	

}
