//Includes
#include <stdio.h>


//Defines


#define NOTEFREQUENCY 0.0158		//frequency of saw wave: f0 = 0.5 * NOTEFREQUENCY * 48000 (=sample rate)
#define NOTEFREQUENCY2 0.0458
#define NOTEAMPLITUDE 750.0		//amplitude of the saw wave


typedef struct {
	float tabs[8];
	float params[8];
	uint8_t currIndex;
} fir_8;


float updateFilter(fir_8* theFilter, float newValue);

void initFilter(fir_8* theFilter);
