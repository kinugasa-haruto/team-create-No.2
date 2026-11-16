#include "all.h"

Sprite* back; // 背景
Sprite* judgeArea; // 赤いエリア
Sprite* conveyor1; // コンベア（動かないほう）
Sprite* conveyor2; // コンベア（動くほう）

Sprite* sabaCan;	//サバ缶
Sprite* ojisan;		//おじ
Sprite* ojisan_push;//ぶっ飛びおじ
Sprite* tie;		//ネクタイ
Sprite* hand;		//手
Sprite* hand_hold;	//回収用の手
Sprite* obasan;		//おばさん
Sprite* Bom;		//爆弾

Sprite* hannya; // おばちゃんレイジモード
Sprite* fire; // 背景の炎


void spriteload_init()
{
	back = sprite_load(L"./Data/Images/gamen.png");
	judgeArea = sprite_load(L"./Data/Images/judge_area.png");
	conveyor1 = sprite_load(L"./Data/Images/konbea_1.png");
	conveyor2 = sprite_load(L"./Data/Images/konbea_2.png");

	sabaCan = sprite_load(L"./Data/Images/saba_can.png");
	ojisan = sprite_load(L"./Data/Images/ojisan.png");
	ojisan_push = sprite_load(L"./Data/Images/ojisan_push.png");
	tie = sprite_load(L"./Data/Images/tie.png");
	hand = sprite_load(L"./Data/Images/player_hand.png");
	hand_hold = sprite_load(L"./Data/Images/player_hold.png");
	obasan = sprite_load(L"./Data/Images/obasan.png");
	Bom = sprite_load(L"./Data/Images/bom.png");

}

void spriteload_deinit()
{
	safe_delete(conveyor1);
	safe_delete(conveyor2);
	safe_delete(back);
	safe_delete(judgeArea);

	safe_delete(sabaCan);
	safe_delete(ojisan);
	safe_delete(ojisan_push);
	safe_delete(tie);
	safe_delete(hand);
	safe_delete(hand_hold);
	safe_delete(obasan);
	safe_delete(Bom);
}
