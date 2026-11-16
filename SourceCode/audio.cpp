#include "all.h"

void audio_init()
{
	// 音楽の読み込み
	
	// // ステージ用のSE
	music::load(1, L"./Data/Sounds/canhit.wav");//缶の音
	music::load(2, L"./Data/Sounds/no_canhit.wav");//間違った缶の音

}

void audio_deinit()
{
	// 音楽を全て解放
	music::clear();
}
