/*
 * main.c
 *
 *  Created on: Feb 23, 2018
 *      Author: hsb2790
 */

#include "system.h"                     // for Qsys #defines
#include <stdbool.h>

unsigned long  *ButtonBase_ptr = (unsigned long *)BUTTON_BASE;
		unsigned long *raminfr_ptr = (unsigned long *)RAMINFR_BE_0_BASE;
		unsigned long *LEDS_ptr = (unsigned long *) LEDS_BASE ;


        bool truth;

        bool ramConfidenceTest(unsigned long  *ramLocation_ptr,unsigned long numBytesToCheck){
        	unsigned long read_value=0;
        	int a;
        	int b;
             unsigned long Increment_addr=1;
        			for(a=0;a<numBytesToCheck;a++){
        				*raminfr_ptr=*raminfr_ptr+a;
        				read_value=*raminfr_ptr;
        				raminfr_ptr++;
        			}
        			for (int b=numBytesToCheck;b<0;b--){
        				raminfr_ptr=b;
        				if (read_value!=*raminfr_ptr){
        				truth=false;
        				}
        				else(truth=true);
        			}
        return truth;
        		 };

		bool ramTestByte(char *ramLocation_ptr, unsigned char numBytesToCheck){
			int a;
        	int b;
        	unsigned char read_value=0;
             unsigned long Increment_addr=1;
        			for(a=0;a<numBytesToCheck;a++){
        				*raminfr_ptr=*raminfr_ptr+a;
        				read_value=*raminfr_ptr;
        				raminfr_ptr++;
        			}
        			for (int b=numBytesToCheck;b<0;b--){
        				raminfr_ptr=b;
        				if (read_value!=*raminfr_ptr){
        				truth=false;
        				}
        				else(truth=true);
        			}
        return truth;
		};

	bool ramTestHalfWork(unsigned short *ramLocation_ptr, unsigned short numBytesToCheck){
		int a;
        	int b;
        	unsigned short read_value=0;
             truth=true;
        			for(a=0;a<numBytesToCheck;a++){
        				*raminfr_ptr=*raminfr_ptr+a;
        				read_value=*raminfr_ptr;
        				if (read_value!=*raminfr_ptr){
        				     truth=false;
        				        }
        				raminfr_ptr++;
        			}
        return truth;
	}


void main(){
unsigned long button_val;
//while(1){
//
//
//		if(*ButtonBase_ptr==1){
//			*raminfr_ptr+=1;
//			raminfr_ptr++;
//			read_value=*raminfr_ptr;
//		}
//		for(int a=0;a<5;a++){
//
//			if(read_value!=*raminfr_ptr){
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
		 if (ramTestByte(raminfr_ptr,4)){
	*LEDS_ptr=255;

//		 if (ramTestHalfWork(raminfr_ptr,2)){
//					*LEDS_ptr=255;
//				}
	}
	}

	}
		return;
}
