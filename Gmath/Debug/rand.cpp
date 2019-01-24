#include "rand.h"
#include <stdint.h>
unsigned int seed = 154;
void seedRand(int seedValue)
{
	seed = seedValue;
	
}

int getRandSeed()
{
	unsigned int w = 0, s = 0xb5ad4eceda1ce2a9;
	seed *= seed;
	seed += (w += s);
	
	return seed = (seed >> 16) | (seed << 16);
}
