#pragma once

class Can {
private:
	VECTOR2 pos;	//缶のpos
	VECTOR2 oba_pos;//おばさんのpos
	VECTOR2 oji_pos;//おじさんのpos
	VECTOR2 bom_pos;//爆弾のpos

	VECTOR2 speed;	//缶のspeed
	VECTOR2 scale;	//缶のscale

	VECTOR2 can_textsize;//缶の画像の大きさ
	VECTOR2 oba_textsize;//おばさんの画像の大きさ
	VECTOR2 oji_textsize;//おじさんの画像の大きさ
	VECTOR2 bom_textsize;//爆弾の画像の大きさ

	VECTOR2 Bbom_pos;//爆弾の青ボタンのpos
	VECTOR2 Rbom_pos;//爆弾の赤ボタンのpos
	VECTOR2 Bbom_scale;//爆弾の青ボタンのscale
	VECTOR2 Rbom_scale;//爆弾の赤ボタンのscale

	float effect_scale;//爆弾エフェクトのscale

	float generate_timer;	//缶の生成間隔
	int generate_num;	//生成した缶の数

	int can_num;		//乱数を入れる変数
	int can_color;		//缶の生成番号
	bool can_alive;		//缶の描画判断

	//おじさんがベルトコンベアの後ろに行くための変数
	float oji_speed;
	float oji_jump_power;
	bool oji_jump;
	float oji_gra;
	bool oji_hit;
	bool oji_back;

	bool oba_hit;//おばさんが叩かれたかの変数

	float kigen;

	int errorcan_count;//不正解の缶の生成した数の変数
	int othercan_count;//缶以外の物を生成した数の変数

	float gravity;//回収時に流れているものに対する重力
	bool gravity_flag;//重力をかけ始める判断

	VECTOR2 gauge_pos;
	VECTOR2 gauge_scale;
	float gaugeW;

	VECTOR2 Beffect_textsize;//爆弾エフェクトの画像サイズ
	bool Bomeffect_flag;//爆弾のエフェクト開始時のflag
	int efc_timer ;//エフェクトのタイマー

	bool flick_flag;//回収したかの判断
	bool bom_dropped;//爆弾を流したかの判断

	bool bomBhit; // 青いボタンを叩いたかの判断
	bool bomRhit;  // 赤いボタンを叩いたかの判断
	bool bom_kigen_down;  // 赤いボタンを叩いたかの判断

	bool sound_choice;

	bool gameClear; // クリあ
	bool gameOver; // オーバー
public:
	Can();//コンストラクタ
	~Can();//デストラクタ
	void OJI_BACK_RENDER(Can* can, Can* oji, int day);	//おじさんがコンベアの後ろに消える処理
	//void OJI_FRONT_RENDER(Can*can,Can* oji);//おじさんがコンベアよりも前の時の処理
	void CAN_GENERATE(Can* cans, Can* obas, Can* ojis, Can* boms, int day);				//缶の生成関数
	void CAN_RENDER(Can* can, Can* oba, Can* oji, Can* bom, int day);	//缶の描画関数

	void CAN_MOVE(Can* can, Can* oba, Can* oji, Can* bom, int day);		//缶の移動関数
	void OJI_JUMP(Can* oji);		//おじさんが飛んでいく処理
	void BOM_EFFECT_UPDATE(Can*bom);
	void BOM_EFFECT_RENDER(Can*bom);
	bool CHECK_IMPURITY_FLOW();		//間違った物がレーンを流れ切った時の処理

	bool CAN_ALL_VANISH(Can* can, Can* oba, Can* oji, Can* bom);//１日に流れるものが全部消えたかの処理
	//void DAY_CLEAR(Can* can, Can* oba, Can* oji, Can* bom, int day);//CLEAR時の関数
	void GAUGE_UPDATE();//ゲージの処理関数
	void GAUGE_RENDER();//ゲージの描画関数

	void setCAN_ALIVE(bool alive);	//can_aliveのセッター関数
	bool getCAN_ALIVE();			//can_aliveのゲッター関数
	void setOJI_JUMP(bool jump);	//oji_jumpのセッター関数
	void setOJI_HIT(bool hit);		//oji_jumpのセッター関数
	bool getOJI_JUMP();				//oji_jumpのゲッター関数
	bool getOJI_HIT();				//oji_hitのゲッター関数
	bool getOBA_HIT();				//oba_hitのゲッター関数
	void setOBA_HIT(bool hit);		//oba_hitのセッター関数
	void setFLICK_FLAG(bool flick);//flick_flagのセッター関数
	bool getFLICK_FLAG();//flick_flagのセッター関数
	int getCAN_COLOR();				//缶のcolorのゲッター関数
	int getERRORCAN_COUNT();		//不正解の缶の生成数のゲッター関数
	int getOTHERCAN_COUNT();		//缶以外の生成合計数のゲッター関数
	VECTOR2 getCAN_POS();			//缶のposのゲッター関数
	VECTOR2 getOBA_POS();			//おばさんのposのゲッター関数
	VECTOR2 getOJI_POS();			//おじさんのposのゲッター関数
	VECTOR2 getBBOM_POS();			//青ボタンのposのゲッター関数
	VECTOR2 getRBOM_POS();			//赤ボタンのposのゲッター関数
	VECTOR2 getBBOM_SCALE();		//青ボタンのscaleのゲッター関数
	VECTOR2 getRBOM_SCALE();		//赤ボタンのscaleのゲッター関数
	VECTOR2 getCAN_SCALE();			//scaleのゲッター関数
	VECTOR2 getCAN_SPEED();			//speedのゲッター関数
	VECTOR2 getCAN_TEXTSIZE();		//缶の画像の大きさのゲッター関数
	VECTOR2 getOBA_TEXTSIZE();		//おばさんの画像の大きさのゲッター関数
	VECTOR2 getOJI_TEXTSIZE();		//おじさんの大きさのゲッター関数

	void MINUSsetKIGEN(int k);//kigenのーセッター関数
	void PLUSsetKIGEN(int k);//kigenの＋セッター関数

	void setGRA_FLAG(bool gra);
	void setBOM_EFFECT(bool effect);
	bool getBOM_EFFECT();
	void setEFC_TIMER(int timer);

	void setBOMB_HIT(bool hit);
	bool getBOMB_HIT();
	void setBOMR_HIT(bool hit);
	bool getBOMR_HIT();

	void setSOUND_CHOICE(bool choice);
	bool getSOUND_CHOICE();

	bool getCAN_GAMECLEAR() { return gameClear; }  // kuri
	bool getCAN_GAMEOVER() { return gameOver; }  //  oba

	void CAN_RESET(Can* can, Can* oba, Can* oji, Can* bom); // 缶のリセット
	void TUTORIAL_RESET();
	void TUTORIAL_GENERATE(bool impure, int day, Can* cans);
	void DEBUG_OVER() { gameOver = true; }
	void KIGEN_RESET() {kigen = 60;}
};

//日にち事の設定
struct Day
{
	float timer;//缶の生成間隔
	int CAN_NUM;//1日の缶の生成数
	float speed;//缶の速度
	int bom_pro;//爆弾の確率
	int oba_pro;//おばさんの確率
	int oji_pro;//おじさんの確率
	int errorcan_pro;//不正解の缶の確率
	int can_pro;//缶の確率
};

void GAME_DAY(int num);
void GAME_DAY_RENDER(int num);
//void TUTORIAL_RENDER();
//void TUTORIAL_UPDATE();
//void TITLE_CAN_UPDATE();
//void TITLE_CAN_RENDER();
void TUTORIAL_CAN_UPDATE();
//void TUTORIAL_CAN_RENDER();
void TUTORIAL_MISSCAN_UPDATE();
//void TUTORIAL_MISSCAN_RENDER();

