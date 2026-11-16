#pragma once

// ここにextern
extern Sprite* back; // 背景
extern Sprite* judgeArea; // 赤いエリア
extern Sprite* conveyor1; // コンベア（動かないほう）
extern Sprite* conveyor2; // コンベア（動くほう）

extern Sprite* sabaCan;		//サバ缶
extern Sprite* ojisan;		//おじ
extern Sprite* ojisan_push;//ぶっ飛びおじ
extern Sprite* tie;			//ネクタイ
extern Sprite* hand;		//手
extern Sprite* hand_hold;	//回収用の手
extern Sprite* obasan;		//おばさん
extern Sprite* Bom;			//爆弾

extern Sprite* hannya; // おばちゃんレイジモード
extern Sprite* fire; // 背景炎


void spriteload_init();

void spriteload_deinit();