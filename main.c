#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-Up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN =  OFF       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)


#include "funct.h"


#define VERSION   2


volatile unsigned char buttonName = 0;
uint8_t countMass = 1;  
//uint8_t variant;


void blinkLed(uint8_t count){
    for (uint8_t i = 0; i < count; i++){
       //myDelayms(400);
       __delay_ms(400);  
       GPIO |= (1 << GP1);
       __delay_ms(200);
       //myDelayms(200);
       GPIO &= ~(1 << GP1);
    }
}



void timer0Init(){
    INTCON |= (1 << 5)|(1 << 7)|(1 << 6);
    OPTION_REG = (1 << 1)|(1 << 6)|(1 << 7);
    TMR0 = 131;
}

int main(void) {   
    TRISIO |= (1 << GP4)|(1 << GP5);   //входы
    TRISIO &= ~(1 << GP2) & ~(1 << GP1) & ~(1 << GP3) & ~(1 << GP0);   //выходы   
    GPIO &= ~(1 << GP0) & ~(1 << GP3) &~(1 << GP2) &~(1 << GP1);    
    
    volatile uint8_t left = 0; 
	volatile uint8_t right = 0;
   
    while (1) {
        buttonIn();        
        left = ptrigLeft();
        right = ptrigRight();
        
         if (right){
            #if (VERSION == 1)  
                pwm_V1(countMass); 
            #elif (VERSION == 2)    
                pwm_V2(countMass);
            #endif

        }
        
        
        if (left){
            countMass++;            
        #if (VERSION == 1)
           #define VARIANT  7
        #elif (VERSION == 2)
           #define VARIANT  3
        #endif    
    
              if (countMass > VARIANT){
                  countMass = 1;
              }
              blinkLed(countMass);            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        

        
    buttonName = BUT_GetKey();   
    
}
    
}

