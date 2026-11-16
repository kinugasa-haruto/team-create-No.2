#include "all.h"

gameNumber::gameNumber()
{
	map_["0"] = {0 , 0, 100, 100};
	map_["1"] = {100, 100, 100, 100};
	map_["2"] = {200, 200, 100, 100};
	map_["3"] = {300, 300, 100, 100};
	map_["4"] = {400, 400, 100, 100};
	map_["5"] = {500, 500, 100, 100};
	map_["6"] = {600, 600, 100, 100};
	map_["7"] = {700, 700, 100, 100};
	map_["8"] = {800, 800, 100, 100};
	map_["9"] = {900, 900, 100, 100};
}

void gameNumber::NumberRender(VECTOR2 pos ,int number)
{
	auto str_num = std::to_string(number);

	this->pos = pos;

	for (const auto& str : str_num) {
		auto& data = map_[&str];
		textPos = { data.pos_x, data.pos_y };
		size = { data.width, data.height };
	}

}

void gameNumber::Render()
{
	sprite_render(number, pos.x, pos.y, 0.5f, 0.5f, textPos.x, textPos.y, size.x, size.y, 0, 0);
}