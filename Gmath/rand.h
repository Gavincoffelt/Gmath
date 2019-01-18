#pragma once
#include <iostream>
extern unsigned int seed;
// returns a random value between min and max
template<typename T>
T rand(T min, T max);

// returns a random value between min and max
//  - the value may contain decimal components
template<typename T>
T randDecimal(T min, T max);

// seed the random number generator
void seedRand(int seedValue);

// returns the seed used for the random number generator
int getRandSeed();

template<typename T>
inline T rand(T min, T max)
{
	unsigned long long temp = NULL;
	temp = seed % max;
	while (temp > max) {
		temp -=max;
	}
	if (min > temp && temp <= max) {
		temp += min;
	}
	getRandSeed();
	std::cout << temp << std::endl;
	return temp;
}
//
//template<typename T>
//inline T randDecimal(T min, T max)
//{
//	
//}
