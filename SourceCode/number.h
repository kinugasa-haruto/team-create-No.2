#pragma once

#include <unordered_map>

class gameNumber
{
	struct Data {
		float pos_x{};
		float pos_y{};
		float width{};
		float height{};
	};
public:
	gameNumber();
	~gameNumber() = default;
	void NumberRender(VECTOR2 pos,int number, float inv);
	void Render();

	void reset();

private:

	VECTOR2 pos;
	VECTOR2 textPos;
	VECTOR2 size;
	float inv;

	std::unordered_map<std::string, Data> map_;
};