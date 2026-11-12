#include "all.h"

Hannya hannyA;

void ObachanUpdate()
{
	// 炎アニメーション
	static int timer = 0;

	timer++;


	// 般若アニメーション
	static float animeTimer = 0;
	static float scale = 1;
	static bool h = false;
	

	if (!h) animeTimer += 0.1f;
	if (h) animeTimer -= 0.1f;

	if (animeTimer >= 1)
	{
		h = true;
		scale = 1;
	}
	if (animeTimer <= 0)
	{
		h = false;
		scale = 0;
	}

	scale = sinf(animeTimer) * 0.2f + 1.05f;
	hannyA.SetScale(scale);
	debug::setString("scale:%f", hannyA.GetScale());
}

void ObachanRender()
{
	//sprite_render(hannya, SCREEN_HALF_W, SCREEN_HALF_H, hannyA.GetScale(), hannyA.GetScale(), 0, 0, SCREEN_W, SCREEN_H, SCREEN_HALF_W, SCREEN_HALF_H);
	//sprite_render(fire, 0, 0, 1, 1, SCREEN_W, 0, SCREEN_W, SCREEN_H);
}