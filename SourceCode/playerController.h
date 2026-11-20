#pragma once

class playerController
{
private:
	VECTOR2 hitarea_pos;	//叩くエリアのpos
	VECTOR2 hitarea_scale;	//叩くエリアのscale
	VECTOR2 flickarea_pos;	//弾くエリアのpos
	VECTOR2 flickarea_scale;//弾くエリアのscale

	VECTOR2 Rhund_pos;		//右手のpos
	VECTOR2 Lhund_pos;		//左手のpos
	VECTOR2 Rhund_scale;	//右手のscale
	VECTOR2 Lhund_scale;	//左手のscale

	bool main_conveyor;			//メインコンベアかの判断
	bool right_hit_area;		//右の叩くエリアかの判断
	float main_conveyor_color;	//メインベルトコンベアの色
	float sub_conveyor_color;	//サブベルトコンベアの色

	int control_stop_timer;		//プレイヤーの停止時間
	int flick_errorcan_count;	//不正解の缶を回収した合計変数
	int flick_other_count;		//缶以外の物を回収した合計変数

	float hit_timer;			//叩いた時に手の画像位置を変える時間
	float flick_timer;			//弾いた時に手の画像位置を変える時間

public:
	playerController();					//コンストラクタ
	~playerController();				//デストラクタ
	void HITAREA_FLICKAREA_RENDER();	//叩くエリアと弾くエリアの描画関数
	void PLAYER_HIT_CAN(Can* can, Can* oba, Can* oji, Can* bom, int day);	//playerの缶を叩く動作関数
	
	//bool HITCHECK_CAN(Can* can);	//缶と叩くエリアの当たり判定関数
	//bool HITCHECK_OBA(Can* oba);	//おばさんと叩くエリアの当たり判定関数
	//bool HITCHECK_OJI(Can* oji);	//おじさんと叩くエリアの当たり判定関数
	//bool HITCHECK_BOM(Can* bom);	//爆弾と叩くエリアの当たり判定関数

	bool HITCHECK_THING(Can* thing, float textX, float textY);	//流れている物と叩くエリアの当たり判定関数
	bool HITCHECK_HUND_BUTTON(VECTOR2 hund_pos, VECTOR2 hund_size, VECTOR2 button_pos, VECTOR2 button_size);//左右の手と爆弾の左右のボタンの当たり判定関数


	void PLAYER_FLICK_CAN(Can* can, Can* oba, Can* oji, Can* bom, int day);//playerの弾く動作関数
	bool FLICKCHECK_THING(Can* thing, float textX, float textY);	//流れている物と弾くエリアの当たり判定関数
	//bool FLICKCHECK_CAN(Can* cans);	//缶と弾くエリアの当たり判定関数
	//bool FLICKCHECK_OJI(Can* ojis);	//おじさんと弾くエリアの当たり判定関数
	//bool FLICKCHECK_OBA(Can* obas);	//おばさんと弾くエリアの当たり判定関数
	//bool FLICKCHECK_BOM(Can* boms);	//爆弾と弾くエリアの当たり判定関数
	void BELTCONVEYOR_HITAREA_CHANGE();		//ベルトコンベアの上下切り替え関数

	VECTOR2 getRHUND_POS();
	VECTOR2 getLHUND_POS();
	VECTOR2 getRHUND_SCALE();
	VECTOR2 getLHUND_SCALE();
	int getFLICK_ERRORCAN_COUNT();		//不正解の缶の回収数のゲッター関数
	int getFLICK_OTHERCAN_COUNT();		//缶以外の物の回収した合計数のゲッター関数


	void TUTORIAL_HITAREA_CHANGE(); // 左右のみの切替
	bool GetMAIN_CONVEYOR() { return main_conveyor; } // メインコンベアゲッター関数
};

#define HIT_HUND_RENDER_TIMER (5)	//叩いた時に手の画像位置を変える時間
#define FLICK_HUND_RENDER_TIMER (5)	//弾いた時に手の画像位置を変える時間

