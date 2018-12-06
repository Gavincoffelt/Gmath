#include "mathutilities.h"

int min(int a, int b)
{
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}

int max(int a, int b)
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int clamp(int value, int min, int max)
{
	if (value > min && value < max) {
		return value;
	} 
	else if (value < min) {
		return min;
	}
	else if (value > max) {
		return max;
	}
}

int abs(int val)
{
	if (val >= 0) {
		return val;
	}
	else if (val < 0) {
		return -val;
	}


}

int pow(int base, int power)
{
	int beginning = base;
	for (int i = 1; i < power; i++) {
		base = base * beginning;

	}
	return base;
}

bool isPowerOfTwo(int val)
{
	
}
