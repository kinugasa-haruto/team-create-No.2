#pragma once

// 1ÉQÅ[ÉÄÇÃí∑Ç≥ÅiïbÅj
#define GAME_LENGTH 90

class GameTimer
{
public:
	static GameTimer Instance()
	{
		GameTimer instance;
		return instance;
	}
	void timerUpdate();
	void timerRender();

	void reset()
	{
		timer = 0;
		animeTimer = 0;
		max_timer = GAME_LENGTH;
		scaleY = 0;
	}

private:
	GameTimer()
	{
		timer = 0;
		animeTimer = 0;
		max_timer = GAME_LENGTH;
		scaleY = 0;
	}

	float timer = 0;
	float animeTimer;
	float scaleY;
	float max_timer = GAME_LENGTH;
};

