#include "all.h"

Sprite* back; // 背景
Sprite* judgeArea; // 赤いエリア
Sprite* conveyor1; // コンベア（動かないほう）
Sprite* conveyor2; // コンベア（動くほう）

Sprite* sabaCan;//サバ缶
Sprite* ojisan;//おじ
Sprite* ojisan_push;//ぶっ飛びおじ
Sprite* hand;//手

Sprite* hannya; // おばちゃんレイジモード

void spriteload_init()
{
	back = sprite_load(L"./Data/Images/gamen.png");
	judgeArea = sprite_load(L"./Data/Images/judge_area.png");
	conveyor1 = sprite_load(L"./Data/Images/konbea_1.png");
	conveyor2 = sprite_load(L"./Data/Images/konbea_2.png");

	sabaCan = sprite_load(L"./Data/Images/saba_can.png");
	ojisan = sprite_load(L"./Data/Images/ojisan.png");
	ojisan_push = sprite_load(L"./Data/Images/ojisan_push.png");
	hand= sprite_load(L"./Data/Images/player_hand.png");
	
	hannya = sprite_load(L"./Data/Images/hannya.png");
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
	safe_delete(hand);
}
