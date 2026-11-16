#pragma once

class Can{
private:
	VECTOR2 pos;	//缶のpos
	VECTOR2 oba_pos;//おばさんのpos
	VECTOR2 oji_pos;//おじさんのpos
	VECTOR2 speed;	//缶のspeed
	VECTOR2 scale;	//缶のscale
	VECTOR2 can_textsize;//缶の画像の大きさ
	VECTOR2 oba_textsize;//おばさんの画像の大きさ
	VECTOR2 oji_textsize;//おじさんの画像の大きさ

	int generate_timer;	//缶の生成間隔
	int generate_num;	//生成した缶の数
	int can_num;		//乱数を入れる変数
	int can_color;		//缶の生成番号
	bool can_alive;		//缶の描画判断
	float oji_speed;
	float oji_jump_power;
	bool oji_jump;
	float oji_gra;
	bool oji_hit;
	bool oji_back;

	bool oba_hit;


public:
	Can();//コンストラクタ
	~Can();//デストラクタ
	void OJI_BACK_RENDER(Can*can,Can* oji);
	//void OJI_FRONT_RENDER(Can*can,Can* oji);
	void CAN_GENERATE(Can* can,int day);	//缶の生成関数
	void CAN_RENDER(Can* can,Can*oba,Can*oji,int day);		//缶の描画関数
	void CAN_MOVE(Can* can,Can*oba,Can*oji,int day);		//缶の移動関数
	void OJI_JUMP(Can*oji);//おじさんが飛んでいく処理
	bool CHECK_IMPURITY_FLOW();		//間違った物がレーンを流れ切った時の処理


	void setCAN_ALIVE(bool alive);	//can_aliveのセッター関数
	void setOJI_JUMP(bool jump);	//oji_jumpのセッター関数
	void setOJI_HIT(bool hit);	//oji_jumpのセッター関数
	bool getOJI_JUMP();				//oji_jumpのゲッター関数
	bool getOJI_HIT();				//oji_hitのゲッター関数
	bool getOBA_HIT();				//oba_hitのゲッター関数
	void setOBA_HIT(bool hit);				//oba_hitのセッター関数
	int getCAN_COLOR();				//缶のcolorのゲッター関数
	VECTOR2 getCAN_POS();			//缶のposのゲッター関数
	VECTOR2 getOBA_POS();			//おばさんのposのゲッター関数
	VECTOR2 getOJI_POS();			//おじさんのposのゲッター関数
	VECTOR2 getCAN_SCALE();			//scaleのゲッター関数
	VECTOR2 getCAN_SPEED();			//speedのゲッター関数
	VECTOR2 getCAN_TEXTSIZE();		//缶の画像の大きさのゲッター関数
	VECTOR2 getOBA_TEXTSIZE();		//おばさんの画像の大きさのゲッター関数
	VECTOR2 getOJI_TEXTSIZE();		//おじさんの大きさのゲッター関数

};


struct Day
{
	float timer;//缶の生成間隔
	int CAN_NUM;//1日の缶の生成数
	float speed;//缶の速度
	int type;//１日に流す物の種類
};

