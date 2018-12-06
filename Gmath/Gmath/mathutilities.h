#pragma once
const double PI = 3.141592653589793238;

const double DEG_TO_RAD = PI / 180.0f;

const double RAD_TO_DEG = 180.0f/ PI;




int min(int a, int b);

int max(int a, int b);

int clamp(int value, int min, int max);

int abs(int val);

int pow(int base, int power);

bool isPowerOfTwo(int val);

float moveTowards(float current, float target, float maxDelta);