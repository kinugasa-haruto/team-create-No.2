#pragma once
#include"all.h"

#define CIRCLE_NUM (10)

class Can{
private:
	VECTOR2 pos;//circle‚Ìpos
	VECTOR2 speed;//circle‚Ìspeed
	VECTOR2 scale;//circle‚Ìscale

	int generate_num;
	int generate_timer;

public:
	Can();
	int GENERATE(int generate_timer, int generate_num);
};




