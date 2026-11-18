#ifndef game_back_H
#define game_back_H

//******************************************************************************
//
//
//      game_back.h
//
//
//******************************************************************************

class BackAngle
{
public:
	BackAngle(float angle) : angle(angle) {};
	float GetAngle() { return angle; }
	void SetAngle(float angle) { this->angle = angle; }
private:
	float angle;
};

class Conveyor
{

public:
	

	Conveyor(VECTOR2 pos, VECTOR4 rect) : pos(pos), rect(rect) {};
	
	//~Conveyor();
	
	const VECTOR2 GetPosition() { return pos; }

	const VECTOR4 GetRect() { return rect; }
	
	void SetRect(VECTOR4 rect) { this->rect = rect; }

	void AddRectX(const float rect) { this->rect.x = this->rect.x + rect;}
	void AddRectZ(const float rect) { this->rect.z = this->rect.z + rect;}

	void SetPositionX(const float pos) { this->pos.x = pos; }

	void AddPositionX(const float pos) { this->pos.x += pos; }


private:
	VECTOR2 pos;
	VECTOR4 rect;
};


// 関数のプロトタイプ宣言
void back_update(float speed);
void back_render();
void conveyor_render();
void judgearea_render();
void back_init();
void back_deinit();
#endif//game_back_H
