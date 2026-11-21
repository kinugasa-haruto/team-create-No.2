#ifndef AUDIO_H
#define AUDIO_H

//******************************************************************************
//
//
//      audio.h
//
//
//******************************************************************************

// 定数の定義
#define OK_CAN	0
#define NO_CAN1	1
#define OJI		2
#define PAPER	3
#define CLICK	4
#define GAME_BGM	5
#define RAGE	6
#define FIRE	7
#define BOM		8
#define NO_CAN2	9
#define NO_CAN3	10
#define NO_CAN4	11
#define BOM_BOTTON	12


// XWBの種類
#define XWB_SYSTEM          0
#define XWB_STAGE1          1

// SYSTEMの効果音
#define XWB_SYSTEM_KATI     0
#define XWB_SYSTEM_START    1

// STAGE1の効果音
#define XWB_STAGE1_COIN     0
#define XWB_STAGE1_JUMP     1
#define XWB_STAGE1_SHOT     2
#define XWB_STAGE1_MISSILE  3
#define XWB_STAGE1_LASER    4
#define XWB_STAGE1_BOMB     5

// 関数のプロトタイプ宣言
void audio_init();
void audio_deinit();

#endif//AUDIO_H
