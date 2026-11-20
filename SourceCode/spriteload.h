#pragma once

// ここにextern
extern Sprite* back; // 背景
extern Sprite* sprTime; // 窓の外の景色
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

extern Sprite* sub_gauge;	//ゲージの枠
extern Sprite* main_gauge;	//ゲージの本体
extern Sprite* jousi1;		//上司1
extern Sprite* jousi2;		//上司2
extern Sprite* jousi3;		//上司3
extern Sprite* jousi4;		//上司4
extern Sprite* jousi5;		//上司5
extern Sprite* jousi6;		//上司6

extern Sprite* hannya; // おばちゃんレイジモード
extern Sprite* fire; // 背景炎

extern Sprite* binder; // バインダー
extern Sprite* shutter; // シャッター
extern Sprite* nowday; // 今日が何日目か

extern Sprite* number; // 数字
extern Sprite* endwork; // 業務終了
extern Sprite* leavework; // 退勤
extern Sprite* skip; // スキップ

extern Sprite* startCan; // スタート 鯖缶
extern Sprite* titleIcon; // タイトルアイコン

extern Sprite* tutorialBubble; // 吹き出しチュートリアル
extern Sprite* tutorialText; // チュートリアル言葉

void spriteload_init();

void spriteload_deinit();