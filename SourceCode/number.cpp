#include "all.h"

Number::Number()
{
	map_["0"] = {};
	map_["1"] = {};
	map_["2"] = {};
	map_["3"] = {};
	map_["4"] = {};
	map_["5"] = {};
	map_["6"] = {};
	map_["7"] = {};
	map_["8"] = {};
	map_["9"] = {};
}

void Number::NumberRender(VECTOR2 pos ,int number)
{
	auto str_num = std::to_string(number);

	this->pos = pos;

	for (const auto& str : str_num) {
		auto& data = map_[&str];
		textPos = { data.pos_x, data.pos_y };
		size = { data.width, data.height };
	}
}

void Number::Render()
{

}