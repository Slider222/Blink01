#include "funct.h"

volatile unsigned char pressedKey = 0;
volatile unsigned int comp = 0;





void buttonIn(void)
{   
   unsigned char key;
    
   if (~GPIO & (1 << 5))
   {
	   key = keyLeft;
   }
   else if (~GPIO & (1 << 4))                                                             
   {
	   key = keyRight;
   }   
   else{
	    key = 0;	
   }
   
   if (key)
   {
	   if (comp > 7000)
	   {
		   comp = 1000;
		   pressedKey = key + longTup; 		  
		   return;
	   }
	   else comp++;

//	   if (comp == 10)
//	   {
//		   pressedKey = key;
//		   return;
//	   } 	   
   }
   else{ 
	   comp = 0;	   
   }  
 }

unsigned char BUT_GetKey(void)
{
	unsigned char key = pressedKey;	
	pressedKey = 0;
	return key;
}

uint8_t ptrigLeft(void){	
		volatile static uint16_t bcount = 0;
		volatile static uint8_t block = 0;
		volatile uint8_t butUp = 0;
		if (~GPIO & (1 << 4)){                         //if (~GPIO & (1 << 5))
			if (bcount < 100){
				bcount++; 
			 }
			 else {
				if (!block){
					butUp = 1;
					block = 1; 
				}
			}
		 
		  }
		  else{
			   if (bcount > 0){
			   	   bcount--;
		           }
				   else {
					    block = 0;
					 } 				  
          }
		  return butUp;
}

uint8_t ptrigRight(void){
	volatile static uint16_t bcount = 0;
	volatile static uint8_t block = 0;
	volatile uint8_t butUp = 0;
	if (~GPIO & (1 << 5)){                        //if (~GPIO & (1 << 4))
		if (bcount < 100){
			bcount++;
	}
		else {
			if (!block){
				butUp = 1;
				block = 1;
	         }
		}
		
	}
	else{
		if (bcount > 0){
			bcount--;
		}
		else {
			block = 0;
		}
	}
	return butUp;
}


