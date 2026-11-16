#pragma once

#include <unordered_map>

class Number
{
	struct Data {
		float pos_x{};
		float pos_y{};
		float width{};
		float height{};
	};
public:
	Number();
	~Number() = default;
	void NumberRender(VECTOR2 pos,int number);
	void Render();


private:

	VECTOR2 pos;
	VECTOR2 textPos;
	VECTOR2 size;
	
	std::unordered_map<std::string, Data> map_;
};