#include "all.h"

Sprite* back; // 背景
Sprite* sprTime; // 窓の外の景色
Sprite* judgeArea; // 赤いエリア
Sprite* conveyor1; // コンベア（動かないほう）
Sprite* conveyor2; // コンベア（動くほう）
Sprite* flyer1; // おじさん張り紙
Sprite* flyer2; // おばさん張り紙

Sprite* sabaCan;	//サバ缶
Sprite* ojisan;		//おじ
Sprite* ojisan_push;//ぶっ飛びおじ
Sprite* tie;		//ネクタイ
Sprite* hand;		//手
Sprite* hand_hold;	//回収用の手
Sprite* obasan;		//おばさん
Sprite* Bom;		//爆弾
Sprite* Bom_effect;	//爆弾

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
Sprite* shutter; // シャッター
Sprite* nowday; // 何日目か表示

Sprite* number; // 数字
Sprite* space; // スペースキー
Sprite* wkey; // Wキー
Sprite* skey; // Sキー
Sprite* endwork; // 業務終了
Sprite* leavework; // 退勤
Sprite* skip; // スキップ

Sprite* startCan; // スタートボタン
Sprite* titleIcon; // タイトルアイコン

Sprite* gameclear; // ゲームクリア画面
Sprite* gameover; // ゲームオーバー画面

Sprite* tutorialBubble; // チュートリアル吹き出し
Sprite* tutorialText; // チュートリアル文言

void spriteload_init()
{
	back = sprite_load(L"./Data/Images/game_2.png");
	sprTime = sprite_load(L"./Data/Images/view.png");
	judgeArea = sprite_load(L"./Data/Images/judge_area.png");
	conveyor1 = sprite_load(L"./Data/Images/konbea_1.png");
	conveyor2 = sprite_load(L"./Data/Images/konbea_2.png");
	flyer1 = sprite_load(L"./Data/Images/flyer_1.png");
	flyer2 = sprite_load(L"./Data/Images/flyer_2.png");

	sabaCan = sprite_load(L"./Data/Images/saba_can.png");
	ojisan = sprite_load(L"./Data/Images/ojisan.png");
	ojisan_push = sprite_load(L"./Data/Images/ojisan_push.png");
	tie = sprite_load(L"./Data/Images/tie.png");
	hand = sprite_load(L"./Data/Images/player_hand.png");
	hand_hold = sprite_load(L"./Data/Images/player_hold.png");
	obasan = sprite_load(L"./Data/Images/obasan.png");
	Bom = sprite_load(L"./Data/Images/bom.png");
	Bom_effect = sprite_load(L"./Data/Images/boom.png");

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
	shutter = sprite_load(L"./Data/Images/shutter.png");
	nowday = sprite_load(L"./Data/Images/day.png");

	number = sprite_load(L"./Data/Images/number.png");
	space = sprite_load(L"./Data/Images/space_key.png");
	wkey = sprite_load(L"./Data/Images/key_w.png");
	skey = sprite_load(L"./Data/Images/key_s.png");
	endwork = sprite_load(L"./Data/Images/end_of_work.png");
	leavework = sprite_load(L"./Data/Images/leave_work.png");
	skip = sprite_load(L"./Data/Images/skip.png");

	startCan = sprite_load(L"./Data/Images/start.png");
	titleIcon = sprite_load(L"./Data/Images/logo_2.png");

	gameclear = sprite_load(L"./Data/Images/gameclear.png");
	gameover = sprite_load(L"./Data/Images/gameover.png");

	tutorialBubble = sprite_load(L"./Data/Images/text_bublle.png");
	tutorialText = sprite_load(L"./Data/Images/tutorial_text.png");
}

void spriteload_deinit()
{
	safe_delete(back);
	safe_delete(sprTime);
	safe_delete(conveyor1);
	safe_delete(conveyor2);
	safe_delete(judgeArea);
	safe_delete(flyer1);
	safe_delete(flyer2);

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
	safe_delete(shutter);
	safe_delete(nowday);

	safe_delete(number);
	safe_delete(space);
	safe_delete(wkey);
	safe_delete(skey);
	safe_delete(endwork);
	safe_delete(leavework);
	safe_delete(skip);

	safe_delete(startCan);
	safe_delete(titleIcon);

	safe_delete(gameclear);
	safe_delete(gameover);

	safe_delete(tutorialBubble);
	safe_delete(tutorialText);
}
