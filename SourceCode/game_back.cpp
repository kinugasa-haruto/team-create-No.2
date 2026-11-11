#include "all.h"

int back_state;
int back_timer;
Sprite* back;
Sprite* judgeArea;
Sprite* conveyor1;
Sprite* conveyor2;

Conveyor conveyor_1[2] = { { {0, SCREEN_HALF_H - 50},{0, 0, SCREEN_W, 238}},{ {0, SCREEN_H - 300},{SCREEN_W, 0, SCREEN_W * 2, 238}} };
Conveyor conveyor_2[2][2] = { {{ {0, SCREEN_HALF_H - 50},{0, 0, SCREEN_W, 238}}, {{SCREEN_W, SCREEN_HALF_H - 50},{SCREEN_W, 0, SCREEN_W * 2, 238} }},
							{{ {0, SCREEN_H - 300},{0, 0, SCREEN_W, 238}},{{-SCREEN_W, SCREEN_H - 300},{SCREEN_W, 0, SCREEN_W * 2, 238}}}};

void back_init()
{
	back_state = 0;
	back_timer = 0;
	back = sprite_load(L"./Data/Images/gamen.png");
	judgeArea = sprite_load(L"./Data/Images/judge_area.png");
	conveyor1 = sprite_load(L"./Data/Images/Konbea_1.png");
	conveyor2 = sprite_load(L"./Data/Images/Konbea_2.png");
}

void back_deinit()
{
	safe_delete(conveyor1);
	safe_delete(conveyor2);
	safe_delete(back);
	safe_delete(judgeArea);
}

void back_update()
{
	switch (back_state)
	{
	case 0:
		//////// èâä˙ê›íË ////////


		back_state++;
		/*fallthrough*/

	case 1:
		//////// ÉpÉâÉÅÅ[É^ÇÃê›íË ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);

		back_state++;
		/*fallthrough*/

	case 2:
		//////// í èÌéû ////////
		
		for (int i = 0; i < 2; i++)
		{
			conveyor_2[0][i].AddPositionX(-3.0f);
			if (conveyor_2[0][i].GetPosition().x <= -SCREEN_W)
			{
				conveyor_2[0][i].SetPositionX(SCREEN_W);
			}

			conveyor_2[1][i].AddPositionX(3.0f);
			if (conveyor_2[1][i].GetPosition().x >= SCREEN_W)
			{
				conveyor_2[1][i].SetPositionX(-SCREEN_W);
			}
		}

		break;
	}


	back_timer++;
}

void back_render()
{
	// âÊñ Çê¬Ç≈ìhÇËÇ¬Ç‘Ç∑

	sprite_render(back, 0, 0, 1, 1, 0, 0, SCREEN_W, SCREEN_H, 0, 0);
	
	for (int i = 0; i < 2; i++)
	{
		sprite_render(conveyor1, conveyor_1[i].GetPosition().x, conveyor_1[i].GetPosition().y, 1, 1, 0, conveyor_1[i].GetRect().y, SCREEN_W, conveyor_1[i].GetRect().w, ToRadian(0));
		for (int j = 0; j < 2; j++)
		{
			sprite_render(conveyor2, conveyor_2[i][j].GetPosition().x, conveyor_2[i][j].GetPosition().y, 1, 1, 0 ,conveyor_2[i][j].GetRect().y, SCREEN_W, conveyor_2[i][j].GetRect().w, ToRadian(0));
			sprite_render(conveyor2, conveyor_2[i][j].GetPosition().x, conveyor_2[i][j].GetPosition().y, 1, 1, conveyor_2[i][j].GetRect().x, conveyor_2[i][j].GetRect().y, conveyor_2[i][j].GetRect().z, conveyor_2[i][j].GetRect().w, ToRadian(0));
		}
		sprite_render(judgeArea, conveyor_1[i].GetPosition().x, conveyor_1[i].GetPosition().y, 1, 1, 0, conveyor_1[i].GetRect().y, SCREEN_W, conveyor_1[i].GetRect().w, ToRadian(0));
	}

	
	

}
