

#define FCY 4000000
#include <stdio.h> 
#include <string.h> 
#include <libpic30.h>
#include "config.h"
#include "lcd.h"
#include <math.h>


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
    char NUM= 'A';
    int i = 0;
    char n_1 [15] = "";
    char n_2 [15] = "";
    char op_1 []= "                ";
    int n_1_r = 0;
    int j = 0;
    int k = 0;
    int g = 0;
    char op;
    int b_op = 0;
    int b_r = 0;
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
            if (b_op == 0){
                LCDPutStr(n_1);
                LCDGoto(0,0);
            }
            else if (b_op == 1){
                LCDPutStr(op_1);
                LCDGoto(0,0);
                b_op = 2;
                }
            else if (b_op == 2){
                LCDPutStr(n_2);
                LCDGoto(0,0);
            }
            }
        
        NUM = 'A';
        
        
        
        
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
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA1==1) {
                NUM='8';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA2==1) {
                NUM='9';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            
            if(PORTAbits.RA3==1) {
                NUM='/';
                op_1[0]= '/';
                b_op = 1;
                i=0;
            }
         __delay_ms(30);
         
         PORTB=PORTB<<1;
            if(PORTAbits.RA0==1) {
                NUM='4';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA1==1) {
                NUM='5';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA2==1) {
                NUM='6';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }       
            }
            if(PORTAbits.RA3==1) {
                NUM='x';
                op_1[0] ='x';
                b_op = 1;
                i=0;
            }
         __delay_ms(30);
         
         PORTB=PORTB<<1;
            if(PORTAbits.RA0==1) {
                NUM='1';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA1==1) {
                NUM='2';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA2==1) {
                NUM='3';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA3==1) {
                NUM='-';
                op_1[0]= '-';
                b_op = 1;
                i=0;
            }
         __delay_ms(30);
         PORTB=PORTB<<1;
            if(PORTAbits.RA0==1) {
                DisplayClr();
                i = 0;
            }
            if(PORTAbits.RA1==1) {
                NUM='0';
                if (b_op == 0){
                    n_1[i] = NUM;
                    i++;
                }
                else {
                    n_2[i] = NUM;
                    i++;
                }
            }
            if(PORTAbits.RA2==1) {
                NUM='=';
                i++;
            }
            if(PORTAbits.RA3==1) {
                NUM='+';
                op_1[0]= '+';
                b_op = 1;
                i=0;
            }
         __delay_ms(30);         
         
                
         
         // guarda numeros
         for (j = i; j==0; j--){
             n_1_r = n_1_r +(n_1[i]*pow(10,k));
             k++;
         }
    }
}
