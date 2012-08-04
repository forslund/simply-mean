// mean.h

#define MEAN_FULL 0x08

typedef struct meanStruct {
	signed short *s;  // Sample-array
	signed short *m;  // array of sub-mean-values
	unsigned char sLen; // Number of samples before a new sub-mean is generated
	unsigned char mLen; // total number of sub-means
	unsigned char sPtr; // pointer to current sample
	unsigned char mPtr; // pointer to current mean
	unsigned char status;
} mean_t;


void meanInit(mean_t *mean, signed short *meanArr, 
			  unsigned char maLen, signed short *sampleArr, 
			  unsigned char saLen);

void meanAddSample(mean_t *mean, signed short sample);

signed short meanGet(mean_t mean);
