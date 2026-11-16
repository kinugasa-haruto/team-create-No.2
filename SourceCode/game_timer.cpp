#include "all.h"

bool GameTimer::timerUpdate()
{
	//1ƒtƒŒ[ƒ€‚Ì•b”‚ð‚Â‚¢‚©
	timer += 1 / 60.0f;

	if (timer > 2)
	{
		animeTimer += 0.01f;
		scaleY = Easing::easeOut3(animeTimer);
		if (scaleY >= 0.98f) return false;
	}
	return true;
	debug::setString("gametimer:%f", timer);
}

void GameTimer::timerRender()
{
	if (timer < 2)
	{
		text_out(2, "FiNISH", SCREEN_HALF_W - 200, SCREEN_HALF_H - 100, 1, 1, 0, 0, 0);
	}
	if (timer > 2)
	{
		primitive::rect(0, 0, SCREEN_W, SCREEN_H * scaleY, 0, 0, ToRadian(0), 0, 0, 0);
	}
}