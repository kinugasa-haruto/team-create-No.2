#include "all.h"

Sprite* back; // 背景
Sprite* judgeArea; // 赤いエリア
Sprite* conveyor1; // コンベア（動かないほう）
Sprite* conveyor2; // コンベア（動くほう）

void spriteload_init()
{
	back = sprite_load(L"./Data/Images/gamen.png");
	judgeArea = sprite_load(L"./Data/Images/judge_area.png");
	conveyor1 = sprite_load(L"./Data/Images/konbea_1.png");
	conveyor2 = sprite_load(L"./Data/Images/konbea_2.png");
}

void spriteload_deinit()
{
	safe_delete(conveyor1);
	safe_delete(conveyor2);
	safe_delete(back);
	safe_delete(judgeArea);
}
