#include "mathutilities.h"

int sum(int a, int b)
{
	return a+b;
}

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

int nextPowerOfTwo(int val)
{
	if (isPowerOfTwo(val)) {
		return val * 2;
	}
	return 0;
}

bool isPowerOfTwo(int val)
{
	if (val == 0) {
		return 0;
	}
	while (val != 1) {
		if (val % 2 != 0) {
			return 0;
		}
		val /= 2;

	}
	return 1;
}

float moveTowards(float current, float target, float maxDelta)
{
	if ((target - current) <= maxDelta) {
		return target;
	}
	else {
		return maxDelta;
	}

}

bool assert(const char * testName, bool expression)
{
	if (expression == true) {
		std::cout << "[PASS]" << testName << std::endl;
		return true;
	}
	else {
		std::cout << "[FAIL]" << testName << std::endl;
		return false;
	}
	
}

bool assert(const char * testName, int expected, int actual)
{
	if (expected == actual) {
		std::cout << "[PASS]" << testName << std::endl;
		return true;
	}
	else {
		std::cout << "[FAIL]" << testName << std::endl;
		return false;
	}
}

bool assert(const char * testName, float expected, float actual, float tolerance)
{
	if (expected >= (actual - tolerance) && expected <= (actual + tolerance)) {
		std::cout << "[PASS]" << testName << std::endl;
		return true;
	}
	else {

		std::cout << "[FAIL]" << testName << std::endl;
		return false;
	}

}
