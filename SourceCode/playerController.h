#pragma once
#define CAN_NUM (10)

class playerController
{
private:
	VECTOR2 hitarea_pos;	//叩くエリアのpos
	VECTOR2 hitarea_scale;	//叩くエリアのscale
	VECTOR2 flickarea_pos;	//弾くエリアのscale
	VECTOR2 flickarea_scale;//弾くエリアのscale

public:
	playerController();				//コンストラクタ
	void HITAREA_RENDER();			//叩くエリアの描画関数
	void PLAYER_HIT_CAN(Can* can);	//playerの叩く動作関数
	bool HITCHECK_CAN(Can* cans);	//缶と叩くエリアの当たり判定関数
	void FLICKAREA_RENDER();		//弾くエリアの描画関数
	void PLAYER_FLICK_CAN(Can* can);//playerの弾く動作関数
	bool FLICKCHECK_CAN(Can* cans);	//缶と弾くエリアの当たり判定関数
};

