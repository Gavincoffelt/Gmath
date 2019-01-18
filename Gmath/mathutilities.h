#pragma once
#include <iostream>
const double PI = 3.141592653589793238;

const double DEG_TO_RAD = PI / 180.0f;

const double RAD_TO_DEG = 180.0f/ PI;


int sum(int a, int b);

int min(int a, int b);

int max(int a, int b);

int clamp(int value, int min, int max);

int abs(int val);

int pow(int base, int power);

int nextPowerOfTwo(int val);

bool isPowerOfTwo(int val);

float moveTowards(float current, float target, float maxDelta);

bool assert(const char * testName, bool expression);

bool assert(const char * testName, int expected, int actual);

bool assert(const char * testName, float expected, float actual, float tolerance);


template<typename T>
inline T lerp(const T & a, const T & b, float t)
{
	
	//return a + (b - a) * t;
	
	return a * (1 - t) + b * t;
}


namespace Tweening {
	
	template <typename T>
	T linearEase(float t, const T& b, const T& c, float d)
	{
	return b + c * (t / d);
	}


	template <typename T>
	T easeInSine(float t, const T& b, const T& c, float d)
	{
		return b + c - c * cosf(t / d * HALF_PI);
	}

	template <typename T>
	T easeInCubic(float t, const T& b, const T& c, float d)
	{
		t /= d;
		return c * t*t*t + b;

	}
	template <typename T>
	T easeOutCubic(float t, const T& b, const T& c, float d)
	{
		t /= d;
		t--;
		return c * (t*t*t+1) + b;

	}
}
template <typename T>
T quadraticBezier(const T& a, const T& b, const T& c, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	return lerp(x, y, t);
}

template <typename T>
T cubicBezier(const T& a, const T& b, const T& c,const T& d, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	T z = lerp(c, d, t);

	return quadraticBezier(x, y, z, t);
}

template <typename T>
T catmullRomSpline(const T* controlpoints, size_t count, float t) {
	assert("counter", counter > 1);

		if (t <= 0)
			return controlpointsp[0];
		if (t >= 1)
		    return controlpoints[count - 1];

}