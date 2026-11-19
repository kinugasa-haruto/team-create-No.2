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

Sprite* sub_gauge;	//ゲージの枠
Sprite* main_gauge;	//ゲージの本体
Sprite* jousi1;		//上司1
Sprite* jousi2;		//上司2
Sprite* jousi3;		//上司3
Sprite* jousi4;		//上司4
Sprite* jousi5;		//上司5
Sprite* jousi6;		//上司6

Sprite* hannya; // おばちゃんレイジモード
Sprite* fire; // 背景の炎

Sprite* binder; // バインダー

Sprite* number; // 数字

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

	sub_gauge= sprite_load(L"./Data/Images/gauge_1.png");
	main_gauge= sprite_load(L"./Data/Images/gauge_2.png");
	jousi1= sprite_load(L"./Data/Images/face_1.png");
	jousi2= sprite_load(L"./Data/Images/face_2.png");
	jousi3= sprite_load(L"./Data/Images/face_3.png");
	jousi4= sprite_load(L"./Data/Images/face_4.png");
	jousi5= sprite_load(L"./Data/Images/face_5.png");
	jousi6= sprite_load(L"./Data/Images/face_6.png");

	hannya = sprite_load(L"./Data/Images/hannya.png");
	fire = sprite_load(L"./Data/Images/fire.png");

	binder = sprite_load(L"./Data/Images/binder.png");

	number = sprite_load(L"./Data/Images/number.png");
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

	safe_delete(sub_gauge);
	safe_delete(main_gauge);
	safe_delete(jousi1);
	safe_delete(jousi2);
	safe_delete(jousi3);
	safe_delete(jousi4);
	safe_delete(jousi5);
	safe_delete(jousi6);

	safe_delete(hannya);
	safe_delete(fire);

	safe_delete(binder);

	safe_delete(number);
}
