#ifndef SCENE_TUTORIAL_H
#define SCENE_TUTORIAL_H

//******************************************************************************
//
//
//      scene_tutorial.h
//
//
//******************************************************************************

#define TEXT_LINE 860 / 8.0f

class SkipButton
{
public:

	static SkipButton Instance()
	{
		SkipButton instance;
		return instance;
	}

	void Reset()
	{
		pos = { SCREEN_W - 300, SCREEN_H - 150 };
		rect = { 0, 0, 150, 50 };
		timer = 0;
		inv = 0;
		progress = 0;
	}

	void Update();

	void Render()
	{
		primitive::rect(pos.x, pos.y, rect.z * progress, rect.w, 0, 0, ToRadian(0), 1, 1, 0, 0.5f);
		
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

class TutorialText
{
public:

	static TutorialText Instance()
	{
		TutorialText instance;
		return instance;
	}

	void SetProgress(int progress) { this->progress = progress; }
	int GetProgress() { return progress; }

	void Render()
	{
		switch (progress)
		{
		default:
			break;
		case 0:
			sprite_render(tutorialBubble, 0, 0, 1.15f, 0.7f, 0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 1, 1, 1, 0.5f);
			sprite_render(tutorialText, 160, 60, 1, 1, 0, 0, SCREEN_W, TEXT_LINE * 3);
			break;
			
		case 1:
			sprite_render(tutorialBubble, 0, 0, 1.15f, 0.7f, 0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 1, 1, 1, 0.5f);
			sprite_render(tutorialText, 160, 60, 1, 1, 0, TEXT_LINE * 3, SCREEN_W, TEXT_LINE * 3, 0, 0);
			break;
		case 2:
			sprite_render(tutorialBubble, 0, 0, 1.15f, 0.7f, 0, 0, SCREEN_W, SCREEN_H, 0, 0, ToRadian(0), 1, 1, 1, 0.5f);
			sprite_render(tutorialText, 160, 60, 1, 1, 0, TEXT_LINE * 6, SCREEN_W, TEXT_LINE * 2, 0, 0);
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		}
	}


private:
	TutorialText() 
	{
		progress = 2;
	};
	int progress;


};


// 関数のプロトタイプ宣言
void tutorial_init();
void tutorial_deinit();
void tutorial_update();
void tutorial_render();

#endif//SCENE_tutorial_H
