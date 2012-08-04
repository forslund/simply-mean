#include <stdio.h>
#include <stdlib.h>
#include "lib/mean.h"

int main(int argc, char *argv[])
{
	mean_t test;
	signed short means[3], samples[10], index;
	signed long compare = 0;
	meanInit(&test, means, 3, samples, 10);
	for(index = 0; index < 30; index++)
	{
		compare += index * 2;
		meanAddSample(&test, (index * 2));
	}
	compare /= 30;
	printf("Orig: %ld Test: %d\n", compare, meanGet(test));

	return 0;
}
