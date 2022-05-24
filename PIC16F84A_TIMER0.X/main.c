#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

int sayac;

void main(void) {

    OPTION_REG = 0x07;          // Prescaler = 256 for TMR0
    TMR0 = 236;                   // De?er verildi?i an ba?lar
    TRISB = 0x00;               // PORTB output
    PORTB = 0x00;               // PORTB lojik 0
    
    while(1)
    {
        if(TMR0 ==0)
        {
            TMR0 = 236;         // Yapmazsan art?k 0'dan ba?lar.
            sayac+=1;
        }
        
        if(sayac == 200)
        {
            RB0 = RB0 ^ 1;      // RB0 tersle
            sayac = 0;
        }
    }
}

