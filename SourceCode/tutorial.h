#ifndef SCENE_TUTORIAL_H
#define SCENE_TUTORIAL_H

//******************************************************************************
//
//
//      scene_tutorial.h
//
//
//******************************************************************************

class SkipButton
{
public:

	static SkipButton Instance()
	{
		SkipButton instance;
		return instance;
	}

	void Update();

	void Render()
	{
		primitive::rect(pos.x, pos.y, rect.z * (progress * progress * progress), rect.w, 0, 0, ToRadian(0), 1, 1, 0, 0.5f);
		
		text_out(1, "skip", pos.x + 10, pos.y + 10, 1, 1, 1, 1, 1);
		primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 0, 0, 0, inv);
		debug::setString("timerRender:%d", timer);
	}

private:
	SkipButton()
	{
		pos = { SCREEN_W - 300, SCREEN_H - 150 };
		rect = { 0, 0, 150, 50 };
		timer = 0;
		inv = 0;
		progress = 0;
	}
	VECTOR2 pos;
	VECTOR4 rect;
	float progress;
	float inv;
	int timer;
};

// 関数のプロトタイプ宣言
void tutorial_init();
void tutorial_deinit();
void tutorial_update();
void tutorial_render();

#endif//SCENE_tutorial_H
