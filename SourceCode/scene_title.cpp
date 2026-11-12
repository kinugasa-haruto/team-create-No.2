#include "all.h"

int title_state;
int title_timer;

Title title = Title::Instance();

Sprite* titleCan;

void title_init()
{
	title_state = 0;
	title_timer = 0;
	titleCan = sprite_load(L"./Data/Images/can.png");
}

void title_deinit()
{
	safe_delete(titleCan);
}

void title_update()
{
	switch (title_state)
	{
	case 0:
		//////// èâä˙ê›íË ////////


		title_state++;
		/*fallthrough*/

	case 1:
		//////// ÉpÉâÉÅÅ[É^ÇÃê›íË ////////
	
		GameLib::setBlendMode(Blender::BS_ALPHA);
		

		title_state++;
		/*fallthrough*/

	case 2:
		//////// í èÌéû ////////
		if (title.GetSelected() == 0 && TRG(0) & PAD_START)
		{
			//nextScene = SCENE_TUTORIAL;
			music::play(1, false);
			title.SetSelect(true);
		}
		if (title.GetSelect() == true)
		{
			title.AddTimer(1.0f);
			if (title.GetTimer() <= 30)
			{
				static float timer = 0;
				timer += 1.0f / 30;
				if (timer >= 1) timer = 1;
				title.SetScale(sinf(PI * timer));
			}
			if (title.GetTimer() >= 120)
			{
				static float timer = 0;
				timer += 0.01f;
				title.SetInv(Easing::easeOut3(timer));
			}
			if (title.GetInv() >= 0.98f) nextScene = SCENE_TUTORIAL;
		}
		debug::setString("scale:%f", title.GetScale());
		//if (title.GetSelected() == 0 && TRG(0) & PAD_RIGHT)
		//{
		//	title.ChangeSelected(1);
		//}
		//else if (title.GetSelected() == 1 && TRG(0) & PAD_LEFT)
		//{
		//	title.ChangeSelected(0);
		//}


		back_update();

		break;
	}


	title_timer++;
}

void title_render()
{
	// âÊñ Çê¬Ç≈ìhÇËÇ¬Ç‘Ç∑
	GameLib::clear(0.3f, 0.5f, 1.0f);

	back_render();

	primitive::rect(SCREEN_W - 700, 150, 300, 300, 0, 0, ToRadian(0), 1, 1, 0);
	sprite_render(titleCan, SCREEN_W - 700, 150 + (125 * 0.1f) * title.GetScale() , 2.5f, 2.5f - 0.1f * title.GetScale(), 0, 0, 125, 125);

	primitive::rect(0, 0, SCREEN_W, SCREEN_H * title.GetInv(), 0, 0, ToRadian(0), 0, 0, 0);
	//switch (title.GetSelected())
	//{
	//case 0:
	//	primitive::rect(SCREEN_W - 900, 150, 300, 300, 0, 0, ToRadian(0), 1, 1, 0);
	//	primitive::rect(SCREEN_W - 500, 150, 300, 300, 0, 0, ToRadian(0), 1, 0, 1);
	//	break;
	//
	//case 1:
	//	primitive::rect(SCREEN_W - 900, 150, 300, 300, 0, 0, ToRadian(0), 1, 0, 1);
	//	primitive::rect(SCREEN_W - 500, 150, 300, 300, 0, 0, ToRadian(0), 1, 1, 0);
	//	break;
	//}


}
