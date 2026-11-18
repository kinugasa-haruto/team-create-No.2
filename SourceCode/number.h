#pragma once

#include <unordered_map>
#include <vector>

class gameNumber
{
	struct Numbers
	{
		VECTOR2 pos;
		VECTOR2 textPos;
		VECTOR2 size;
		float inv;
		float scale;
	};

	struct Data {
		float pos_x{};
		float pos_y{};
		float width{};
		float height{};
	};
public:
	gameNumber();
	~gameNumber() = default;
	void Update(VECTOR2 pos,const int number, const float inv = 1.0f, const float scale = 0.5f);
	void Render();

	void reset();

private:

	VECTOR2 pos;
	VECTOR2 textPos;
	VECTOR2 size;
	float inv;
	float scale;

	std::unordered_map<char, Data> map_;
	std::vector<Numbers> numbers_;
};