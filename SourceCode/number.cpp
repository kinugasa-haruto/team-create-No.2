#include "all.h"

gameNumber::gameNumber()
{
	map_['0'] = {0 , 0,  60, 100};
	map_['1'] = {60, 0, 60, 100};
	map_['2'] = {120, 0, 60, 100};
	map_['3'] = {180, 0, 60, 100};
	map_['4'] = {240, 0, 60, 100};
	map_['5'] = {300, 0, 60, 100};
	map_['6'] = {360, 0, 60, 100};
	map_['7'] = {420, 0, 60, 100};
	map_['8'] = {480, 0, 60, 100};
	map_['9'] = {540, 0, 60, 100};
}

void gameNumber::Update(VECTOR2 pos ,const int number, const float inv, const float scale)
{
	auto str_num = std::to_string(number);

	numbers_.clear();
	int index = 0;

	for (const auto& str : str_num) {
		auto& data = map_[str];
		Numbers num;
		num.inv = inv;
		num.scale = scale;
		num.pos = { pos.x + index * data.width , pos.y };
		num.textPos = { data.pos_x, data.pos_y };
		num.size = { data.width, data.height };
		numbers_.push_back(num);

		index++;
	}

}

void gameNumber::Render()
{
	for (const auto& num : numbers_)
	{
		sprite_render(number, num.pos.x, num.pos.y, num.scale, num.scale, num.textPos.x, num.textPos.y, num.size.x, num.size.y, 0, 0, ToRadian(0), 1, 1, 1, num.inv);
	}
}