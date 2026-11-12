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
private:
	VECTOR2 pos;
	VECTOR4 rect;
	float scale;
};

