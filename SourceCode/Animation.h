#pragma once

void ObachanUpdate();
void ObachanRender();


class Hannya
{
public:
	float GetScale() { return scale; }
	void SetScale(float scale) { this->scale = scale; }

	const VECTOR4 GetRect() { return rect; }

	void SetRect(VECTOR4 rect) { this->rect = rect; }

	void AddRectX(const float rect) { this->rect.x = this->rect.x + rect; }
	void AddRectZ(const float rect) { this->rect.z = this->rect.z + rect; }

	const VECTOR2 GetPosition() { return pos; }

	const int GetAnime() { return anime; }
	void SetAnime(int anime) { this->anime = anime; }
private:
	VECTOR2 pos;
	VECTOR4 rect;
	float scale;
	int anime;
};


class Binder
{
public:
	float GetScale() { return scale; }
	void SetScale(float scale) { this->scale = scale; }

	bool GetNext() { return goNext; }

	int GetBinderType() { return binderType; }
	void SetBinderType(int binderType) { this->binderType = binderType; }

	float GetTimer() { return timer; }
	void SetTimer(float timer) { this->timer = timer; }

	const VECTOR4 GetRect() { return rect; }

	void SetRect(VECTOR4 rect) { this->rect = rect; }

	void AddRectX(const float rect) { this->rect.x = this->rect.x + rect; }
	void AddRectZ(const float rect) { this->rect.z = this->rect.z + rect; }

	const VECTOR2 GetPosition() { return pos; }

	const int GetAnime() { return anime; }
	void SetAnime(int anime) { this->anime = anime; }

	void Up();
	void Down();
	void Render();

	void NumberUpdate();

	void reset()
	{
		scale = 0;
		timer = 0;
		binderType = 0;
		anime = 0;
		goNext = false;
	}

private:
	VECTOR2 pos;
	VECTOR4 rect;
	int binderType;
	float timer;
	float scale;
	int anime;
	bool goNext;
};

extern Binder resultBinder;

class NextDay
{
public:

	static NextDay Instance()
	{
		NextDay instance;
		return instance;
	}

	float GetTimer() { return timer; }
	void SetTimer(float timer) { this->timer = timer; }

	const VECTOR4 GetRect() { return rect; }

	void SetRect(VECTOR4 rect) { this->rect = rect; }

	void AddRectX(const float rect) { this->rect.x = this->rect.x + rect; }
	void AddRectZ(const float rect) { this->rect.z = this->rect.z + rect; }

	const VECTOR2 GetPosition() { return pos; }

	const int GetAnime() { return anime; }
	void SetAnime(int anime) { this->anime = anime; }

	void Update();
	void Render();

	void Reset()
	{
		pos = {};
		rect = {};
		timer = 0;
		anime = 0;
		inv = 0;
		swap = false;
		
	}

private:
	NextDay()
	{
		pos = {};
		rect = {};
		timer = 0;
		anime = 0;
		inv = 0;
		swap = false;
	}

	bool swap;
	VECTOR2 pos;
	VECTOR4 rect;
	float timer;
	int anime;
	float inv;
};

class TitleIcon
{
public:
	static TitleIcon Instance()
	{
		TitleIcon instance;
		return instance;
	}

	void Update();
	
	void Render();

	float GetScale() { return scale; }
private:
	TitleIcon()
	{
		timer = 0;
		scaleTimer = 0;
		scale = 1.0f;
		pos = { 80 + 931 * 0.5f,  100 + 314 * 0.5f };
	}
	
	int timer; // ‘S‘ÌŽžŠÔ
	int scaleTimer; // ‚Å‚©‚­‚·‚éŽžŠÔ
	float scale;
	VECTOR2 pos;
};

class SpaceBar
{
public:
	static SpaceBar Instance()
	{
		SpaceBar instance;
		return instance;
	}


	void Update(VECTOR2 pos, float scale = 0.3f);

	void Render();

	void Reset()
	{
		push = false;
		pos = {};
		scale = 0.2f;
		timer = 0;
		exist = false;
	}
private:
	SpaceBar()
	{
		push = false;
		pos = {};
		timer = 0;
		exist = false;
		scale = 0.2f;
	}
	bool exist;
	bool push;
	int timer;
	float scale;
	VECTOR2 pos;

};

extern SpaceBar spacebar;

class Wkey
{
public:
	static Wkey Instance()
	{
		Wkey instance;
		return instance;
	}


	void Update(VECTOR2 pos, float scale = 0.3f);

	void Render();

	void Reset()
	{
		push = false;
		pos = {};
		scale = 0.2f;
		timer = 0;
		exist = false;
	}
private:
	Wkey()
	{
		push = false;
		pos = {};
		timer = 0;
		exist = false;
		scale = 0.2f;
	}
	bool exist;
	bool push;
	int timer;
	float scale;
	VECTOR2 pos;

};

extern Wkey wKey;

class Skey
{
public:
	static Skey Instance()
	{
		Skey instance;
		return instance;
	}


	void Update(VECTOR2 pos, float scale = 0.2f);

	void Render();

	void Reset()
	{
		push = false;
		pos = {};
		scale = 0.2f;
		timer = 0;
		exist = false;
	}
private:
	Skey()
	{
		push = false;
		pos = {};
		timer = 0;
		exist = false;
		scale = 0.2f;
	}
	bool exist;
	bool push;
	int timer;
	float scale;
	VECTOR2 pos;

};

extern Skey sKey;

class StartTimer
{
public:
	static StartTimer Instance()
	{
		StartTimer instance;
		return instance;
	}

	bool Update();

	void Render();

	void Reset()
	{
		timer = 0;
		count = 3;
		countTimer = 0;
		inv = 0;
	}
private:
	StartTimer()
	{
		timer = 0;
		count = 3;
		countTimer = 0;
		inv = 0;
	}
	int count;
	int countTimer;
	float timer;
	float inv;
};