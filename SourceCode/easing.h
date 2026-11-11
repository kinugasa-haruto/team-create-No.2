#pragma once
class Easing
{
public:
	// 前半早く後半ゆっくり
	static float easeOut2(float t);

	// 前半早く後半ゆっくりv2(さらに差がある)
	static float easeOut3(float t);

	// 前半ゆっくり後半早く
	static float easeIn2(float t);

	// 前半ゆっくり後半早くv2(さらに差がある）
	static float easeIn3(float t);
};

