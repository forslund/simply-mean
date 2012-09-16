#include <stdio.h>
#include <stdlib.h>
#include "lib/mean.h"

int main(int argc, char *argv[])
{
	mean_t test;
	signed short means[3], samples[10], index;
	signed long compare = 0;
	signed short result = 0;
	signed short temp;
	meanInit(&test, means, 3, samples, 10, sizeof(short));
	for(index = 0; index < 30; index++)
	{
		temp = index * 2;
		compare += temp;
		meanAddSample(&test, &temp);
	}
	compare /= 30;
	meanGet(test, &result);
	printf("Orig: %ld Test: %d\n", compare, result);

	return 0;
}
