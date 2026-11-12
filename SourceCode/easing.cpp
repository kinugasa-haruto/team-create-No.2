#include "easing.h"

// ‘O”¼‘‚­Œã”¼‚ä‚Á‚­‚è
float Easing::easeOut2(float t)
{
	return 1.0f - (1.0f - t) * (1.0f - t);
}

float Easing::easeOut3(float t)
{
	return 1.0f - (1.0f - t) * (1.0f - t) * (1.0f - t);
}

// ‘O”¼‚ä‚Á‚­‚èŒã”¼‘‚­
float Easing::easeIn2(float t)
{
	return  t * t;
}

float Easing::easeIn3(float t)
{
	return t * t * t;
}
