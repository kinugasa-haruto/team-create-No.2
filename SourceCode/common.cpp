#include "common.h"

//  定数
const FLOAT PI{ DirectX::XM_PI };
const FLOAT SCREEN_W{ 1920 };
const FLOAT SCREEN_H{ 1080 };
const FLOAT SCREEN_HALF_W{ SCREEN_W * 0.5f };
const FLOAT SCREEN_HALF_H{ SCREEN_H * 0.5f };
const BOOL FULLSCREEN{ TRUE };
const LPCWSTR APPLICATION_NAME{ L"C++ project template" };

//  関数ポインタ
float(* const ToRadian)(float) = DirectX::XMConvertToRadians;  // 角度をラジアンに
float(* const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ラジアンを角度に
