// mean.h

#define MEAN_FULL 0x08

typedef struct meanStruct {
	void *s;  // Sample-array
	void *m;  // array of sub-mean-values
	unsigned short sLen; // Number of samples before a new sub-mean is generated
	unsigned short mLen; // total number of sub-means
	unsigned short sPtr; // pointer to current sample
	unsigned short mPtr; // pointer to current mean
	unsigned char status;
	unsigned short sSize;
} mean_t;

void meanInit(mean_t *mean, void *meanArr, 
			  unsigned char maLen, void *sampleArr, 
			  unsigned char saLen, unsigned char typeSize);

void meanAddSample(mean_t *mean, void * sample);

signed short meanGet(mean_t mean, void *returnValue);
