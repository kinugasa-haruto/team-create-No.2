#ifndef SCENE_RESULT_H
#define SCENE_RESULT_H

//******************************************************************************
//
//
//      scene_result.h
//
//
//******************************************************************************

extern bool Clear;

class Result
{
public:
	static Result Instance()
	{
		Result instance;
		return instance;
	}

	bool ShutterUpdate()
	{
		timer += 0.01f;
		inv = Easing::easeIn3(timer);
		if (inv >= 0.99f)
		{
			inv = 1;
			timer = 0;
			return true;
		}
		return false;
	}

	bool Update(bool Clear)
	{
		if (Clear)
		{

		}
		else
		{
			animeTimer++;
			if (animeTimer >= 1 * 60 && animeTimer < 2.5f * 60)
			{
				rect = { SCREEN_HALF_W - 100, 400 };
			}
			else if (animeTimer >= 2.5f * 60)
			{
				rect = { SCREEN_W, SCREEN_H };
				return true;
			}

		}
		return false;
		
	}

	void Render()
	{
		if (Clear) sprite_render(gameclear, 0, 0, 1, 1, 0, 0, rect.x, rect.y, 0, 0);
		else sprite_render(gameover, 0, 0, 1, 1, 0, 0, rect.x, rect.y, 0, 0);

		sprite_render(shutter, 0, 0 - SCREEN_H * inv, 1, 1, 0, 0, SCREEN_W, SCREEN_H, 0, 0);


	}

	void Reset()
	{
		timer = 0;
		inv = 0;
		animeTimer = 0;
		rect = {};
	}

private:
	Result()
	{
		timer = 0;
		inv = 0;
		animeTimer = 0;
		rect = {};
	}

	float timer;
	float inv;
	float animeTimer;
	VECTOR2 rect;



};

// 関数のプロトタイプ宣言
void result_init();
void result_deinit();
void result_update();
void result_render();

#endif//SCENE_RESULT_H
