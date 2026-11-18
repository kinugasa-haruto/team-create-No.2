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

Binder resultBinder;

void ObachanRender()
{
	sprite_render(hannya, SCREEN_HALF_W, SCREEN_HALF_H, hannyA.GetScale(), hannyA.GetScale(), 0, 0, SCREEN_W, SCREEN_H, SCREEN_HALF_W, SCREEN_HALF_H);
	sprite_render(fire, 0, 0, 1, 1, SCREEN_W, 0, SCREEN_W, SCREEN_H);
}

void Binder::Up()
{
	timer += 1.0f / (60 * 2);

	scale = Easing::easeOut3(timer);
	if (scale >= 0.999f) scale = 1;
	if (timer >= 1) timer = 1;
}

void Binder::Down()
{

	if (scale >= 0.999f) scale = 1;
	timer -= 1.0f / (60 * 2);

	scale = 1 - Easing::easeOut3(1 - timer);
	if (scale <= 0.001f) scale = 0;
	debug::setString("scale:%f", GetScale());
}

void Binder::Render()
{
	sprite_render(binder, 0, 1080 - 1080 * scale, 1, 1, 0, 0, 1980, 1080, 0, 0, ToRadian(0));

	if (scale == 1.0f) text_out(1, "Enter To Title", SCREEN_W - 700, SCREEN_H - 75, 1.2f, 1.2f, 0, 0, 0);
}

void NextDay::Update()
{
	if (!swap)
	{
		timer += 1 / 240.0f;
	}
	else
	{
		timer -= 1 / 240.0f;
	}
	if (!swap)
	{
		inv = Easing::easeIn3(timer);
	}
	else
	{
		inv = Easing::easeOut3(timer);
	}
	if (!swap &&inv >= 0.998f)
	{
		inv = 1;
		swap = true;
	}
	if (swap && inv <= 0.002f)
	{
		inv = 0;
		gameDay++;
		nextDay = false;
	}
}

void NextDay::Render()
{
	primitive::rect(SCREEN_HALF_W - 200, SCREEN_HALF_H - 50, 400, 100, 0, 0, ToRadian(0), 1, 1, 1, inv);
	gamenumber.Render();
}