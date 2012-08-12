simply-mean
===========

_simply-mean_ is a simple library to produce (at least semi-accurate) mean values of a sliding window of samples without using extensive amounts of memory. This could for example be used in small micro controllers.

A window could for example be the mean temperature the last 24 hours with samples taken every second (86400 samples). The trivial solution requires an array with a size of at least 86400 bytes (if temperatures are stored as 8-bit values).

The library creates partial mean values and stores these in an array. Initing the library to create a partial mean value evert minute results in a memory need of 1500 bytes. The trade of is a slightly larger error.

Usage
-----
simply include lib/mean.c in your project and add

`#include "lib/mean.h"`

to the source file.

Init the mean value object

    
        mean_t hourMean;
        int partialMeanValues[60]; // partial mean every minute
        int samples[60];           // samples every second
        
	    meanInit(hourMean, partialMeanValues, 60, samples, 60);
    

To add a sample to the mean simply call

`    meanAddSample(&hourMean, newSample);`

To retreive the mean value call

`    meanGet(hourMean);`


Limitations
-----------

* The current version only works with a integers, this will be remedied in future updates
* Trunkation isn't handled correctly which will add a small error

