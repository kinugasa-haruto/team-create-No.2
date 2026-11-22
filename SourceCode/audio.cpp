#include "all.h"

void audio_init()
{
	// 音楽の読み込み
	music::load(GAME_BGM, L"./Data/Sounds/BGM2.wav");			//ゲームBGM〇
	music::load(OK_CAN, L"./Data/Sounds/正解の缶の音.wav");		//正解の缶の音〇
	music::load(NO_CAN1, L"./Data/Sounds/不正解の缶の音1.wav");	//不正解の缶の音1
	music::load(NO_CAN2, L"./Data/Sounds/不正解の缶の音2.wav");	//不正解の缶の音2
	music::load(NO_CAN3, L"./Data/Sounds/不正解の缶の音3.wav");	//不正解の缶の音3
	music::load(NO_CAN4, L"./Data/Sounds/不正解の缶の音4.wav");	//不正解の缶の音4
	music::load(OJI, L"./Data/Sounds/おじさんを叩く音.wav");	//おじさんを叩いた時の音〇
	music::load(PAPER, L"./Data/Sounds/リザルトの紙.wav");		//リザルト画面の紙の音〇
	music::load(CLICK, L"./Data/Sounds/決定音.wav");			//決定音〇
	music::load(RAGE, L"./Data/Sounds/怒り状態1.wav");			//般若の演出開始時の音〇
	music::load(BOM, L"./Data/Sounds/爆発音.wav");				//爆弾の爆発音〇
    music::load(BOM_BOTTON, L"./Data/Sounds/爆弾ボタン.wav");	//爆弾のボタン音〇
    music::load(TITLE_BGM, L"./Data/Sounds/BGM1.wav");			//タイトルBGM〇
	//music::load(FIRE, L"./Data/Sounds/怒り状態2.wav");		//般若演出時の炎の音

	
	// // ステージ用のSE

}

void audio_deinit()
{
	// 音楽を全て解放
	music::clear();
}
