#pragma once

#define CIRCLE_NUM (10)
#define CAN_TYPES (3)

class Can{
private:
	VECTOR2 pos;//circle‚Ìpos
	VECTOR2 speed;//circle‚Ìspeed
	VECTOR2 scale;//circle‚Ìscale

	int generate_timer;
	int generate_num;
	int can_num;
	int can_color;
	bool alive = false;


public:
	Can();
	~Can();
	void CAN_GENERATE();
	void CAN_RENDER();
	void CAN_MOVE();
};