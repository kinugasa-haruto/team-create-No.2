#include "all.h"

extern Can can;
extern playerController player;

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
	//debug::setString("scale:%f", hannyA.GetScale());

}


void ObachanRender()
{
	sprite_render(fire, 0, 0, 1, 1, SCREEN_W * hannyA.GetAnime(), 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 1, 1, 1, 0.5f);
	sprite_render(hannya, SCREEN_HALF_W, SCREEN_HALF_H, hannyA.GetScale(), hannyA.GetScale(), 0, 0, SCREEN_W, SCREEN_H, SCREEN_HALF_W, SCREEN_HALF_H);
}

Binder resultBinder;

void Binder::Up()
{
	if (!music && scale <= 0.1f)
	{
		music::play(PAPER);//バインダーが出てくるときの音
		music = true;
	}

	timer += 1.0f / (60 * 2);

	scale = Easing::easeOut3(timer);
	if (scale >= 0.999f)
	{
		scale = 1;
		NumberUpdate();
		spacebar.Update({ SCREEN_W - 225, SCREEN_H - 250 });
		if (!musicresult)
		{
			music::play(GAME_RESULT);
			music::setVolume(GAME_RESULT, 0.1f);
			musicresult = true;
		}
		if (music)
		{
			music::stop(PAPER);//バインダーが出てくるときの音
			music = false;
		}

	}
	if (timer >= 1) timer = 1;
}

void Binder::Down()
{

	if (!music && scale >= 0.9f)
	{
		music::play(PAPER);//バインダーが出てくるときの音
		music::stop(GAME_RESULT);
		music = true;
	}
	if (scale >= 0.999f) scale = 1;
	timer -= 1.0f / (60 * 2);

	scale = 1 - Easing::easeOut3(1 - timer);
	if (scale <= 0.001f)
	{
		scale = 0;
		if (music)
		{
			music::stop(PAPER);//バインダーが出てくるときの音
			music = false;
		}
	}
	//debug::setString("scale:%f", GetScale());
}

gameNumber maxCan;
gameNumber collectCan;

gameNumber maxOther;
gameNumber collectOther;

void Binder::NumberUpdate()
{
	//collectCan += Easing::easeOut3(collectCan / );// ここにゲッター；
	//if (collectCan >= // ここにゲッター) collectCan = // ここにげったー
	maxOther.Update({ 934 , 850 }, can.getOTHERCAN_COUNT(), 1, 0.6f);
	collectOther.Update({ 760 , 850 }, player.getFLICK_OTHERCAN_COUNT(), 1, 0.6f);
	maxCan.Update({ 934 , 510 }, can.getERRORCAN_COUNT(), 1, 0.6f);
	collectCan.Update({ 760 , 510 }, player.getFLICK_ERRORCAN_COUNT(), 1, 0.6f);
	goNext = true;
}

void Binder::Render()
{
	sprite_render(binder, 0, 1080 - 1080 * scale, 1, 1, 0, 0, 1980, 1080, 0, 0, ToRadian(0));

	if (scale == 1.0f)
	{
		spacebar.Render();
		sprite_render(leavework, SCREEN_W - 300, SCREEN_H - 175, 1, 1, 0, 0, 200, 100, 0, 0);
		//text_out(1, "Go NextDay", SCREEN_W - 700, SCREEN_H - 75, 1.2f, 1.2f, 0, 0, 0);
		maxCan.Render();
		collectCan.Render();
		maxOther.Render();
		collectOther.Render();
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
	if (!swap && inv >= 0.998f)
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
	sprite_render(nowday, SCREEN_HALF_W - 300, SCREEN_HALF_H - 50, 1, 1, 0, gameDay * (1300 / 7.0f), 150, 1300 / 7.0f, 0, 0, ToRadian(0), 1, 1, 1, inv);
	sprite_render(nowday, SCREEN_HALF_W - 100, SCREEN_HALF_H - 50, 1, 1, 150, 0, 400, 1300 / 7.0f, 0, 0, ToRadian(0), 1, 1, 1, inv);
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
	//debug::setString("scale:%f", scale);
}

void TitleIcon::Render()
{
	sprite_render(titleIcon, pos.x, pos.y, 1, 1, 0, 0, 931, 314, 931 * 0.5f, 314 * 0.5f);
}

SpaceBar spacebar = SpaceBar::Instance();

void SpaceBar::Update(VECTOR2 pos, float scale) 
{
	exist = true;
	this->scale = scale;
	this->pos = pos;
	timer += push ? -1 : +1;
	if (timer > 20) push = true;
	if (timer < 0) push = false;
	//debug::setString("push:%d", push);
}

void SpaceBar::Render()
{
	if (!exist) return;
	if (push) sprite_render(space, pos.x, pos.y, scale, scale, 450, 0, 450, 200, 0, 0);
	else sprite_render(space, pos.x, pos.y, scale, scale, 0, 0, 450, 200, 0, 0);
}

Wkey wKey = Wkey::Instance();

void Wkey::Update(VECTOR2 pos, float scale)
{
	exist = true;
	this->scale = scale;
	this->pos = pos;
	timer += push ? -1 : +1;
	if (timer > 20) push = true;
	if (timer < 0) push = false;
	//debug::setString("push:%d", push);
}

void Wkey::Render()
{
	if (!exist) return;
	if (push) sprite_render(wkey, pos.x, pos.y, scale, scale, 110, 0, 110, 100, 0, 0);
	else sprite_render(wkey, pos.x, pos.y, scale, scale, 0, 0, 110, 100, 0, 0);
}

Skey sKey = Skey::Instance();

void Skey::Update(VECTOR2 pos, float scale)
{
	exist = true;
	this->scale = scale;
	this->pos = pos;
	timer += push ? -1 : +1;
	if (timer > 20) push = true;
	if (timer < 0) push = false;
	//debug::setString("push:%d", push);
}

void Skey::Render()
{
	if (!exist) return;
	if (push) sprite_render(skey, pos.x, pos.y, scale, scale, 110, 0, 110, 100, 0, 0);
	else sprite_render(skey, pos.x, pos.y, scale, scale, 0, 0, 110, 100, 0, 0);
}


gameNumber starttimer;

bool StartTimer::Update()
{
	if (inv < 1)
	{
		timer += 0.01f;
		inv = Easing::easeIn3(timer);
		if (inv >= 9.99f)
		{
			inv = 1;
			timer = 0;
		}
	}
	else
	{
		countTimer++;
		if (countTimer % 60 == 0)
		{
			count--;
			countTimer = 0;
		}
		if (count > 0) starttimer.Update({ SCREEN_HALF_W - 20, SCREEN_HALF_H - 20 }, count, 1, 1);
		else starttimer.Update({ SCREEN_HALF_W - 20, SCREEN_HALF_H - 20 }, count, 0, 1);
	}
	return count > 0;

}

void StartTimer::Render()
{
	sprite_render(shutter, 0, 0 - SCREEN_H * inv, 1, 1, 0, 0, SCREEN_W, SCREEN_H, 0, 0);
	starttimer.Render();
}