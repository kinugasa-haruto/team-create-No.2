#include "can.h"
Can num[CIRCLE_NUM];

Can::Can() {
	generate_num = 0;
	generate_timer = 60;

	for (int i = 0; i < CIRCLE_NUM; i++) {
		num[i].pos = { SCREEN_W,SCREEN_H * 0.4 };
		num[i].speed = { 3,0 };
		num[i].scale = { 10,10 };
	}
}

 int Can::GENERATE(int generate_timer,int generate_num) {
	 debug::setString("posX:%fposX:%f", num[0].pos.x, num[0].pos.y);
	 debug::setString("generate:%i", generate_timer);
	 generate_timer--;
	 if (generate_timer < 0) {
		 generate_num++;
		 generate_timer = 60;
	 }

	 if (generate_num > CIRCLE_NUM) {
		 generate_num = CIRCLE_NUM;
	 }


	 for (int i = 0; i < generate_num; i++) {
		 if (num[i].pos.y == SCREEN_H * 0.4) {
			 num[i].pos.x -= num[i].speed.x;
		 }

		 if (num[i].pos.x <= 0 - (num[i].scale.x * 2)) {
			 num[i].pos.y = SCREEN_H * 0.7;
		 }

		 if (num[i].pos.y >= SCREEN_H * 0.7) {
			 num[i].pos.x += num[i].speed.x;
		 }
	 }
 }