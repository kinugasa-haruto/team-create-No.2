#pragma once

class playerController
{
private:
	VECTOR2 hitarea_pos;	//叩くエリアのpos
	VECTOR2 hitarea_scale;	//叩くエリアのscale
	VECTOR2 flickarea_pos;	//弾くエリアのscale
	VECTOR2 flickarea_scale;//弾くエリアのscale
	bool main_conveyor;		//メインコンベアかの判断
	bool right_hit_area;		//右の叩くエリアかの判断
	float main_conveyor_color;	//メインベルトコンベアの色
	float sub_conveyor_color;	//サブベルトコンベアの色

public:
	playerController();				//コンストラクタ
	~playerController();				//デストラクタ
	void HITAREA_FLICKAREA_RENDER();		//叩くエリアと弾くエリアの描画関数
	void PLAYER_HIT_CAN(Can* can, int day);	//playerの叩く動作関数
	bool HITCHECK_CAN(Can* cans, int day);	//缶と叩くエリアの当たり判定関数
	void PLAYER_FLICK_CAN(Can* can, int day);//playerの弾く動作関数
	bool FLICKCHECK_CAN(Can* cans, int day);	//缶と弾くエリアの当たり判定関数
	void BELTCONVEYOR_HITAREA_CHANGE();		//ベルトコンベアの上下切り替え関数
};


