#pragma once

// ここにextern
extern Sprite* back; // 背景
extern Sprite* judgeArea; // 赤いエリア
extern Sprite* conveyor1; // コンベア（動かないほう）
extern Sprite* conveyor2; // コンベア（動くほう）

void spriteload_init();

void spriteload_deinit();