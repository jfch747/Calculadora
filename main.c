

#define FCY 4000000
#include <stdio.h> 
#include <string.h> 
#include <libpic30.h>
#include "config.h"
#include "lcd.h"


void system_init(){
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001F;
    TRISB = 0x0000;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPU1 = 0x0000;
    CNPU2 = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    //AD1PCFG = 0x0E3C;
     AD1PCFG = 0xFFFF;
  
}


void main(){
    //Declaracion de variables
    int LCD_AUXILIAR=0;
    char NUM= '&';
    int i = 0;
    char n_1 [15] = "";
    char n_2 [15] = "";
    int n_1_r = 0;
    int j = 0;
    int k = 0;
    int g = 0;
    char op;
    system_init();
    /*CONFIGURACION INICIAL DE LCD*/
    LCD_Initialize(); //Preder, configurar a 4 bits
    DisplayClr();  // borrar lo que tenga la pantalla
    LCDGoto(0,0); //poner el cursor en la posicion inicial
    
    while(1){
        LCD_PORT=LCD_AUXILIAR;
        
//        if(NUM != '&'){
//            LCDPutChar(NUM);
//            LCDGoto(i,0);
//        }
//        NUM='&';

        if(NUM != 'A'){
            LCDPutStr(n_1);
            LCDGoto(i,0);
        }
        NUM='A';        
        
        
        
        
        //Rutina del display
         /*LCDPutStr("Hello Word");
        __delay_ms(30);
        LCDGoto(0,1); 
        LCDPutStr("Valentina");
        __delay_ms(30);
         LCDGoto(0,0);*/
         
         LCD_AUXILIAR=LCD_PORT;
         //Rutina de salida del teclado
         PORTB=0x100;
            if(PORTAbits.RA0==1) {
                NUM='7';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA1==1) {
                NUM='8';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA2==1) {
                NUM='9';
                n_1_r [i] = NUM;
                i++;
            }
            
            if(PORTAbits.RA3==1) {
                NUM='/';
                op= '/';
                i++;
            }
         __delay_ms(30);
         
         PORTB=PORTB<<1;
            if(PORTAbits.RA0==1) {
                NUM='4';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA1==1) {
                NUM='5';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA2==1) {
                NUM='6';
                n_1_r [i] = NUM;
                i++;        
            }
            if(PORTAbits.RA3==1) {
                NUM='x';
                op ='x';
                i++;
            }
         __delay_ms(30);
         
         PORTB=PORTB<<1;
            if(PORTAbits.RA0==1) {
                NUM='1';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA1==1) {
                NUM='2';
                i++;
            }
            if(PORTAbits.RA2==1) {
                NUM='3';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA3==1) {
                NUM='-';
                op= '-';
                i++;
            }
         __delay_ms(30);
         PORTB=PORTB<<1;
            if(PORTAbits.RA0==1) {
                DisplayClr();
                i = 0;
            }
            if(PORTAbits.RA1==1) {
                NUM='0';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA2==1) {
                NUM='=';
                n_1_r [i] = NUM;
                i++;
            }
            if(PORTAbits.RA3==1) {
                NUM='+';
                op= '+';
                i++;
            }
         __delay_ms(30);
         
        
         
         
         
         // agregar a string
         
         for (g = 0; g == i; g++){
             n_1 [g] = NUM;
         }
         
         // guarda numeros
         for (j = i; j==0; j--){
             n_1_r = n_1_r +(n_1[i]*(10^k));
             k++;
         }
         
         
         
         
         
         //0 = 48 dec
         
         
         
         
    }
}

