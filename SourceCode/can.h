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
	~Can();//デストラクタ
	void CAN_GENERATE(Can* can,int day);	//缶の生成関数
	void CAN_RENDER(Can* can,int day);		//缶の描画関数
	void CAN_MOVE(Can* can,int day);		//缶の移動関数
	void setCAN_ALIVE(bool alive);	//can_aliveのセッター関数
	bool CHECK_IMPURITY_FLOW();		//間違った物がレーンを流れ切った時の処理

	VECTOR2 getCAN_POS();			//posのゲッター関数
	VECTOR2 getCAN_SCALE();			//scaleのゲッター関数
	VECTOR2 getCAN_SPEED();			//speedのゲッター関数

	//void CAN_SET_VARIABLE();//画像の変数にデータを入れる関数
	//void CAN_SAFE_DELETE();	//画像をsafe_deleteする関数

};


struct Day
{
	float timer;//缶の生成間隔
	int CAN_NUM;//1日の缶の生成数
	float speed;//缶の速度
	int type;//１日に流す物の種類
};

