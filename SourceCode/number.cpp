#include "all.h"

gameNumber::gameNumber()
{
	map_["0"] = {0 , 0, 100, 100};
	map_["1"] = {100, 0, 100, 100};
	map_["2"] = {200, 0, 100, 100};
	map_["3"] = {300, 0, 100, 100};
	map_["4"] = {400, 0, 100, 100};
	map_["5"] = {500, 0, 100, 100};
	map_["6"] = {600, 0, 100, 100};
	map_["7"] = {700, 0, 100, 100};
	map_["8"] = {800, 0, 100, 100};
	map_["9"] = {900, 0, 100, 100};
}

void gameNumber::NumberRender(VECTOR2 pos ,int number, float inv)
{
	auto str_num = std::to_string(number);

	this->inv = inv;
	this->pos = pos;

	for (const auto& str : str_num) {
		auto& data = map_[&str];
		textPos = { data.pos_x, data.pos_y };
		size = { data.width, data.height };
	}

}

void gameNumber::Render()
{
	sprite_render(number, pos.x, pos.y, 0.5f, 0.5f, textPos.x, textPos.y, size.x, size.y, 0, 0, ToRadian(0), 1, 1, 1, inv);
}