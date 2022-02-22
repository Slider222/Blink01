/*
 * File:   pwm.c
 * Author: Sergey
 *
 * Created on 19 ������ 2022 �., 8:22
 */


#include "funct.h"



void pwm_V1(uint8_t count){
    uint16_t j = 0;    
        switch (count){                
            default: 
            break;                        
                case 1:                         //7000 ��(80%)    ���������  (�������� 231, 230-��03.)                    
                    for (; j < 500; j++){                        
                        __delay_us(29);      //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);                        
                        __delay_us(113);      //work
                        GPIO &= ~( 1 << GP2);                        
                    }                    
                    GPIO &= ~(1 << GP1);  
                break;
                
                case 2:                          //7000 ��(50%)   ��������� ���� ������
                    for (; j < 600; j++){
                        __delay_us(29);          //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(113);          //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);  
                break;
                
                
                case 3:                         //7000 ��(50%)   
                     for (; j < 700; j++){
                        __delay_us(29); //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(113);      //work
                        GPIO &= ~( 1 << GP2);                        
                     } 
                    GPIO &= ~(1 << GP1);  
                break;
                
                
                
                case 4:                             //7000 ��(80%)  ����������    (�������� 230 ��-02 - ������ ��������� � � �����������)
                    for (; j < 1200; j++){ 
                        __delay_us(33);             //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(133);            //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);  
                break;
                
                
                
                
                case 5:                          //6000 ��(80%)   ��������� 
                   for (; j < 2000; j++){               //7000 �� (90%)
                        __delay_us(17);       //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(125);      //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);
                break;
                
                
                 case 6:                             
                   for (; j < 8000; j++){                         //12000 �� (83�����)
                        __delay_us(41);             //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(41);             //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);
                break;
                
                
                case 7:                                  
                    for (; j < 1000; j++){                         //12000 �� (83�����)
                        __delay_us(41);             //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(41);             //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);               
                break;
                
                
                
                case 8:
                    for (; j < 150; j++){            //1000 ��   
                        __delay_us(800);             //pause
                        GPIO |= ( 1 << GP2);
                        __delay_us(113);            //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);  
                break;
                
                case 9:
                    for (; j < 1000; j++){               //7000 �� (90%)
                        __delay_us(17);       //pause
                        GPIO |= ( 1 << GP2);
                        __delay_us(125);      //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);
                break;
                
                case 10:                                 //3000 ��   /50
                    for (; j < 300; j++){
                        __delay_us(166); //pause
                        GPIO |= ( 1 << GP2);
                        __delay_us(166);      //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);  
                break;
                
                case 11:
                    for (; j < 300; j++){            // 3000 / 70
                        __delay_us(100);       //pause
                        GPIO |= ( 1 << GP2);
                        __delay_us(233);      //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);
                break;
                
                case 12:
                    for (; j < 2500; j++){
                        __delay_us(5);       //pause
                        GPIO |= ( 1 << GP2);
                        __delay_us(5);      //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);
                break;
                
                case 13:
                    for (; j < 8000; j++){                         //12000 �� (83�����)
                        __delay_us(41);             //pause
                        GPIO |= ( 1 << GP2);
                        __delay_us(41);             //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);
                break;   
            } 
}

void pwm_V2(uint8_t count){
    uint16_t j = 0;    
        switch (count){                
            default: 
            break;                        
                case 1:                                             
                    for (; j < 500; j++){ 
                        __delay_us(16);             //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(150);            //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);  
                break;
                
                case 2:                          //7000 ��(50%)   ��������� ���� ������
                    for (; j < 1000; j++){ 
                        __delay_us(33);             //pause
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(133);            //work
                        GPIO &= ~( 1 << GP2);
                    }
                    GPIO &= ~(1 << GP1);  
                break;
                
                
                case 3:                           
                     for (; j < 500; j++){
                        __delay_us(6);        //pause 29
                        GPIO |= ( 1 << GP2) | (1 << GP1);
                        __delay_us(160);      //work
                        GPIO &= ~( 1 << GP2);                        
                     } 
                    GPIO &= ~(1 << GP1);  
                break;
                
        }   
                
                
}