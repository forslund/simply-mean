// mean.h
#include "config.h"
#define MEAN_FULL 0x08

typedef struct meanStruct {
	MEAN_TYPE *s;  // Sample-array
	MEAN_TYPE *m;  // array of sub-mean-values
	unsigned char sLen; // Number of samples before a new sub-mean is generated
	unsigned char mLen; // total number of sub-means
	unsigned char sPtr; // pointer to current sample
	unsigned char mPtr; // pointer to current mean
	unsigned char status;
} mean_t;


void meanInit(mean_t *mean, MEAN_TYPE *meanArr, 
			  unsigned char maLen, MEAN_TYPE *sampleArr, 
			  unsigned char saLen);

void meanAddSample(mean_t *mean, MEAN_TYPE sample);

MEAN_TYPE meanGet(mean_t mean);
