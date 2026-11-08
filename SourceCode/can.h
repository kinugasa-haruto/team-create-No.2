#pragma once

class Can{
private:
	VECTOR2 pos;	//缶のpos
	VECTOR2 speed;	//缶のspeed
	VECTOR2 scale;	//缶のscale

	int generate_timer;	//缶の生成間隔
	int generate_num;	//生成した缶の数
	int can_num;		//乱数を入れる変数
	int can_color;		//缶の生成番号
	bool can_alive;		//缶の描画判断

public:
	Can();//コンストラクタ
	void CAN_GENERATE(Can* can);	//缶の生成関数
	void CAN_RENDER(Can* can);		//缶の描画関数
	void CAN_MOVE(Can* can);		//缶の移動関数
	VECTOR2 getCAN_POS();			//posのゲッター関数
	VECTOR2 getCAN_SCALE();			//scaleのゲッター関数
	void setCAN_ALIVE(bool alive);	//can_aliveのセッター関数
};