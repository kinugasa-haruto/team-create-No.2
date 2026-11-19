#include "all.h"

Hannya hannyA;

void ObachanUpdate()
{
	// 炎アニメーション
	static int timer = 0;

	timer++;

	hannyA.SetAnime(timer / 5 % 3);
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
	sprite_render(fire, 0, 0, 1, 1, SCREEN_W * hannyA.GetAnime(), 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 1, 1, 1, 0.5f);
	sprite_render(hannya, SCREEN_HALF_W, SCREEN_HALF_H, hannyA.GetScale(), hannyA.GetScale(), 0, 0, SCREEN_W, SCREEN_H, SCREEN_HALF_W, SCREEN_HALF_H);
}

Binder resultBinder;

void Binder::Up()
{
	timer += 1.0f / (60 * 2);

	scale = Easing::easeOut3(timer);
	if (scale >= 0.999f)
	{
		scale = 1;
		NumberUpdate();
	}
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

gameNumber maxCan;
gameNumber collectCan;

gameNumber maxOther;
gameNumber collectOther;

void Binder::NumberUpdate()
{
	//collectCan += Easing::easeOut3(collectCan / );// ここにゲッター；
	//if (collectCan >= // ここにゲッター) collectCan = // ここにげったー

	collectCan.Update({ 727, 500 }, 11, 1, 1);
	goNext = true;
}

void Binder::Render()
{
	sprite_render(binder, 0, 1080 - 1080 * scale, 1, 1, 0, 0, 1980, 1080, 0, 0, ToRadian(0));

	if (scale == 1.0f)
	{
		text_out(1, "Go NextDay", SCREEN_W - 700, SCREEN_H - 75, 1.2f, 1.2f, 0, 0, 0);
		collectCan.Render();
	}
}

void NextDay::Update()
{
	if (!swap)
	{
		timer += 1 / 120.0f;
	}
	else
	{
		timer -= 1 / 120.0f;
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
	sprite_render(nowday, SCREEN_HALF_W - 250, SCREEN_HALF_H - 50, 1, 1, 0, gameDay * (1300 / 7.0f), 150, 1300 / 7.0f, 0, 0, ToRadian(0), 1, 1, 1, inv);
	sprite_render(nowday, SCREEN_HALF_W - 50, SCREEN_HALF_H - 50, 1, 1, 150, 0, 400, 1300 / 7.0f, 0, 0, ToRadian(0), 1, 1, 1, inv);
	//primitive::rect(SCREEN_HALF_W - 200, SCREEN_HALF_H - 50, 400, 100, 0, 0, ToRadian(0), 1, 1, 1, inv);
}

void TitleIcon::Update()
{
	timer++;
	scaleTimer++;
	if (scaleTimer <= 10)
	{
		scale += 0.01f;
	}
	if (timer % 30 == 0)
	{
		scaleTimer = 0;
		scale = 1.0f;
	}
	debug::setString("scale:%f", scale);
}

void TitleIcon::Render()
{
	sprite_render(titleIcon, pos.x, pos.y, scale, scale, 0, 0, 931, 314, 931 * 0.5f,  314 * 0.5f);
}