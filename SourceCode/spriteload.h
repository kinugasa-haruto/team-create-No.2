#pragma once

// ここにextern
extern Sprite* back; // 背景
extern Sprite* judgeArea; // 赤いエリア
extern Sprite* conveyor1; // コンベア（動かないほう）
extern Sprite* conveyor2; // コンベア（動くほう）

extern Sprite* sabaCan;	//サバ缶
extern Sprite* ojisan;	//おじ
extern Sprite* ojisan_push;//ぶっ飛びおじ
extern Sprite* hand;	//手

extern Sprite* hannya; // おばちゃんレイジモード


void spriteload_init();

void spriteload_deinit();