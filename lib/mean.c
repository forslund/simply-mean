#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mean.h"


void shortDiv(void * nominator, void * denominator, void * result)
{
#ifdef DEBUG
	printf("shortDiv: %d / %d = ", *(short *)nominator, *(short *)denominator);
#endif
	*(short *)result = *(short *) nominator / *(short *)denominator;
#ifdef DEBUG
	printf("%d\n", *(short *)result);
#endif
}


void shortAdd(void * num1, void * num2, void * result)
{
#ifdef DEBUG
	printf("shortAdd: %d + %d = ", *(short *)num1, *(short *)num2);
#endif
	*(short *)result =  *(short *)num1 + *(short *)num2;
#ifdef DEBUG
	printf("%d\n", *(short *)result);
#endif
}


void meanInit(mean_t *mean, void *meanArr, 
			  unsigned char maLen, void *sampleArr, 
			  unsigned char saLen, unsigned char typeSize)
{
	mean->mLen = maLen;
	mean->sLen = saLen;
	mean->sSize = typeSize;
	mean->mPtr = 0;
	mean->sPtr = 0;

	mean->m = meanArr;
	mean->s = sampleArr;

	mean->status = 0x00;
#ifdef DEBUG
	printf("mLen: %d sLen: %d sSize: %d\n", mean->mLen, mean->sLen, mean->sSize);
#endif
}


void meanAddSample(mean_t *mean, void * sample)
{
	unsigned char index;
	signed long subMean = 0;
	
	memcpy(mean->s + (mean->sPtr * mean->sSize),  sample, mean->sSize);
#ifdef DEBUG
	printf("meanAddSample: %d\n", *(short *)(mean->s + (mean->sPtr * mean->sSize)));
#endif

	mean->sPtr++;

	if (mean->sPtr >= mean->sLen)
	{
		mean->sPtr = 0; // reset sample pointer
		// Calculate sub-mean
		for (index = 0; index < mean->sLen; index++)
			shortAdd(&subMean, mean->s + (index * mean->sSize), &subMean);
		shortDiv(&subMean,  &mean->sLen, &subMean);
#ifdef DEBUG
		printf("mean->m[%d] = %d\n", mean->mPtr, subMean);
#endif // DEBUG
		//update subMean-array
		memcpy(mean->m + mean->mPtr * mean->sSize, &subMean, mean->sSize); 
		mean->mPtr++;
		if (mean->mPtr >= mean->mLen)
		{
			mean->status |= MEAN_FULL;
			mean->mPtr = 0;
		}
	}
}

signed short meanGet(mean_t mean, void * retval)
{
	unsigned short index, stop;
	signed short sum = 0;
	if (mean.status & MEAN_FULL)
		stop = mean.mLen;
	else
		stop = mean.mPtr;
	// get mean-value from sub-means
	for (index = 0; index < stop; index++)
		shortAdd(&sum, mean.m + index * mean.sSize, &sum);
	if(stop > 0)
		shortDiv(&sum, &stop, retval);
	else
		return -1; // UNDEFINED
	return 0;
}

