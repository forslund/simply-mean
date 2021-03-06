#include <stdio.h>
#include <stdlib.h>
#include "mean.h"
#include "config.h"

void meanInit(mean_t *mean, MEAN_TYPE *meanArr, 
			  unsigned char maLen, MEAN_TYPE *sampleArr, 
			  unsigned char saLen)
{
	mean->mLen = maLen;
	mean->sLen = saLen;

	mean->mPtr = 0;
	mean->sPtr = 0;

	mean->m = meanArr;
	mean->s = sampleArr;

	mean->status = 0x00;
}


void meanAddSample(mean_t *mean, MEAN_TYPE sample)
{
	unsigned char index;
	MEAN_L_TYPE subMean = 0;

	mean->s[mean->sPtr] = sample;

	mean->sPtr++;

	if (mean->sPtr >= mean->sLen)
	{
		mean->sPtr = 0; // reset sample pointer
		// Calculate sub-mean
		for (index = 0; index < mean->sLen; index++)
		{
			 subMean += (MEAN_L_TYPE)mean->s[index];
		}
		subMean /= (MEAN_L_TYPE) mean->sLen;
#ifdef DEBUG
		printf("mean->m[%d] = %d\n", mean->mPtr, subMean);
#endif // DEBUG
		mean->m[mean->mPtr] = subMean; //update subMean-array
		mean->mPtr++;
		if (mean->mPtr >= mean->mLen)
		{
			mean->status |= MEAN_FULL;
			mean->mPtr = 0;
		}
	}
}

MEAN_TYPE meanGet(mean_t mean)
{
	unsigned char index, stop;
	MEAN_TYPE sum = 0;

	if (mean.status & MEAN_FULL)
		stop = mean.mLen;
	else
		stop = mean.mPtr;
	// get mean-value from sub-means
	for (index = 0; index < stop; index++)
    	sum += mean.m[index];
    if(stop > 0)
		return sum / stop;
	else
		return 0x8000; // UNDEFINED
}

