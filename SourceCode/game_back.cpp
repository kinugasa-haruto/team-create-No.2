#include "all.h"

int back_state;
int back_timer;

Conveyor conveyor_1[2] = { { {0, SCREEN_HALF_H - 50},{0, 0, SCREEN_W, 238}},{ {0, SCREEN_H - 300},{SCREEN_W, 0, SCREEN_W * 2, 238}} };
Conveyor conveyor_2[2][2] = { {{ {0, SCREEN_HALF_H - 50},{0, 0, SCREEN_W, 238}}, {{SCREEN_W, SCREEN_HALF_H - 50},{SCREEN_W, 0, SCREEN_W * 2, 238} }},
							{{ {0, SCREEN_H - 300},{0, 0, SCREEN_W, 238}},{{-SCREEN_W, SCREEN_H - 300},{SCREEN_W, 0, SCREEN_W * 2, 238}}}};


void back_init()
{

}

void back_deinit()
{
	
}

void back_update()
{
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

		sprite_render(judgeArea, conveyor_1[i].GetPosition().x + SCREEN_HALF_W, conveyor_1[i].GetPosition().y, 1, 1, 0, 0, 330, 238, 0, 0, ToRadian(0));
	}

	
	

}
