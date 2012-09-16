/*
 * config file for selecting variable type
 * 
 * 		MEAN_TYPE 	is used to set the type the samples and mean value
 * 		MEAN_L_TYPE	is used if the gathered samples threaten to overflow
 * 					when they are added up to form a mean value.
 * 	
 * 	Example for signed short values is provided, change types below to suit
 * 	your needs.
*/

#ifndef CONFIG_H

#define MEAN_TYPE signed short
#define MEAN_L_TYPE	signed long

#endif

