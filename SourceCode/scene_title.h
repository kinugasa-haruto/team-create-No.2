#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H

//******************************************************************************
//
//
//      scene_title.h
//
//
//******************************************************************************

class Title
{
public:

	static Title Instance()
	{
		Title instance;
		return instance;
	}

	int GetSelected() { return selected; }
	void ChangeSelected(const int select) { selected = select; }

	bool GetSelect() { return select; }
	void SetSelect(bool select) { this->select = select; }

	float GetTimer() { return selectTimer; }
	void AddTimer(float timer) { selectTimer += timer; }

	float GetInv() { return inv; }
	void AddInv(float inv) { this->inv += inv; }

	float GetScale() { return scale; }
	void SetScale(float scale) { this->scale = scale; }

private:
	Title()
	{
		selected = 0;
		select = false;
		selectTimer = 0;
		inv = 0;
		scale = 0;
	}

	float scale;
	float inv;
	int selected;
	bool select;
	float selectTimer;
};

// 関数のプロトタイプ宣言
void title_init();
void title_deinit();
void title_update();
void title_render();

#endif//SCENE_TITLE_H
