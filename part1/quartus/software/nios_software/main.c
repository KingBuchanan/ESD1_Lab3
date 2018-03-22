/*
 * main.c
 *
 *  Created on: Feb 23, 2018
 *      Author: hsb2790
 */
#include "system.h"                     // for Qsys #defines
#include <stdbool.h>

unsigned long  *ButtonBase_ptr = (unsigned long *)BUTTON_BASE;
unsigned long *inferred_Base_ptr = (unsigned long *)INFERRED_RAM_BASE;
unsigned long *LEDS_ptr = (unsigned long *) LEDS_BASE ;


bool truth;

bool ramConfidenceTest(unsigned long  *ramLocation_ptr,unsigned long numBytesToCheck){
	unsigned long read_value=0;
	int a=0;

	for(a=0;a<(numBytesToCheck/4);a++){    // increments the loop up until the number of bytes requested.
		*ramLocation_ptr=*inferred_Base_ptr+a;   //Adds a value to the data within the address.
		read_value=*ramLocation_ptr; // assigns variable the same data that's in the address
		if (read_value!=*ramLocation_ptr){
			truth=false;
		}
		else(truth=true);
		ramLocation_ptr++;
	}


	return truth;
};
bool ramTestByte(char *ramLocation_ptr, char numBytesToCheck){
	char read_value=0;
			int a;
        		for(a=0;a<numBytesToCheck;a++){
        				*ramLocation_ptr=*ramLocation_ptr+a;
        				read_value=*ramLocation_ptr;
        				if (read_value!=*ramLocation_ptr){
        							truth=false;
        						}
        						else(truth=true);
        				ramLocation_ptr++;
        			}
        return truth;
		};

	bool ramTestHalfWord(unsigned short *ramLocation_ptr, unsigned short numBytesToCheck){
		unsigned short read_value=0;
		int a;
        			for(a=0;a<numBytesToCheck;a++){
        				*ramLocation_ptr=*ramLocation_ptr+a;
        				read_value=*ramLocation_ptr;
        				if (read_value!=*ramLocation_ptr){
        							truth=false;
        						}
        						else(truth=true);
        				ramLocation_ptr++;
        			}

        return truth;
	}


void main(){
	unsigned long button_val;
	//while(1){
	//
	//
	//		if(*ButtonBase_ptr==1){
	//			*inferred_Base_ptr+=1;
	//			inferred_Base_ptr++;
	//			read_value=*inferred_Base_ptr;
	//		}
	//		for(int a=0;a<5;a++){
	//
	//			if(read_value!=*inferred_Base_ptr){
	//				*LEDS_ptr=0;  //All eight leds light up.
	//			}
	//				else {
	//					*LEDS_ptr=255;
	//				}
	//			}
	//		}
	while(1){
		button_val=*ButtonBase_ptr;
		//	 numBytesToCheck=4096;
		if(button_val){
			*LEDS_ptr=0;
//			if (ramConfidenceTest(inferred_Base_ptr,16)){
//				*LEDS_ptr=255;
//			}
			if (ramTestHalfWord(inferred_Base_ptr,2)){
							*LEDS_ptr=255;
						}
		}

	}
	return;
}



