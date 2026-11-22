#include "all.h"

int title_state;
int title_timer;

Title title = Title::Instance();
TitleIcon icon = TitleIcon::Instance();

extern Can cans[500];
extern Can obas[500];
extern Can ojis[500];
extern Can boms[500];
extern Can can;



void title_init()
{
	title_state = 0;
	title_timer = 0;
	can.CAN_RESET(cans, obas, ojis, boms);
	back_init();
	title.Reset();
	music::play(TITLE_BGM, true);
	music::setVolume(TITLE_BGM, 0.1f);
	gameDay = 0;
}

void title_deinit()
{
	music::stop(TITLE_BGM);
	spacebar.Reset();
}

void title_update()
{
	switch (title_state)
	{
	case 0:
		//////// ‰Šúİ’è ////////

		GameLib::setBlendMode(Blender::BS_ALPHA);

		title_state++;
		/*fallthrough*/

	case 1:
		//////// ƒpƒ‰ƒ[ƒ^‚Ìİ’è ////////

		
	
		title_state++;
		/*fallthrough*/

	case 2:
		//////// ’Êí ////////
		if (title.GetSelected() == 0 && TRG(0) & PAD_TRG1 && !title.GetSelect() && title_timer > 60)
		{
			//nextScene = SCENE_TUTORIAL;
			music::play(1, false);
			title.SetSelect(true);
		}
		spacebar.Update({ SCREEN_W - 575, 40 });

		if (title.GetSelect())
		{
			title.AddTimer(1.0f);
			static float timer = 0;
			timer += 1.0f / 30;
			if (timer >= 1) timer = 1;
			title.SetScale(sinf(PI * timer));
			if (title.GetInv() >= 0.99f) timer = 0;

			if (title.GetTimer() >= 30)
			{
				static float timer = 0;
				timer += 0.01f;
				title.SetInv(Easing::easeOut3(timer));
				if (title.GetInv() >= 0.99f) timer = 0;
			}
			if (title.GetInv() >= 0.99f) nextScene = SCENE_TUTORIAL;

		}

		
		//if (title.GetSelected() == 0 && TRG(0) & PAD_RIGHT)
		//{
		//	title.ChangeSelected(1);
		//}
		//else if (title.GetSelected() == 1 && TRG(0) & PAD_LEFT)
		//{
		//	title.ChangeSelected(0);
		//}

		icon.Update();
		back_update(2.0f);

		can.CAN_GENERATE(cans, obas, ojis, boms, 5);//‚P‚Â‚ÌŠÊ‚Ì¶¬ŠÖ”
		can.CAN_MOVE(cans, obas, ojis, boms, 5);	//‚P‚Â‚ÌŠÊ‚ÌˆÚ“®ŠÖ”

		break;
	}
	title_timer++;

}

void title_render()
{
	// ‰æ–Ê‚ğÂ‚Å“h‚è‚Â‚Ô‚·
	GameLib::clear(0.3f, 0.5f, 1.0f);

	back_render();

	//primitive::rect(SCREEN_W - 700, 150, 300, 300, 0, 0, ToRadian(0), 1, 1, 0);
	if (title.GetSelect())	sprite_render(startCan, SCREEN_W - 500, 260 + (125 * 0.1f) * title.GetScale(), 2.5f, 2.5f - 0.1f * title.GetScale(), 0, 0, 125, 125, 125 * 0.5f, 125 * 0.5f);
	else sprite_render(startCan, SCREEN_W - 500, 260, 2.5f + 1 - icon.GetScale(), 2.5f + 1 - icon.GetScale(),  0, 0, 125, 125, 125 * 0.5f, 125 * 0.5f);
	conveyor_render();
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

	can.CAN_RENDER(cans, ojis, obas, boms, 5);//1‚Â‚ÌŠÊ‚Ì•`‰æŠÖ”
	icon.Render();
	spacebar.Render();

	sprite_render(shutter, 0, -SCREEN_H + SCREEN_H * title.GetInv(), 1, 1, 0, 0, SCREEN_W, SCREEN_H, 0, 0);

	//primitive::rect(0, 0, SCREEN_W, SCREEN_H * title.GetInv(), 0, 0, ToRadian(0), 0, 0, 0);
}
