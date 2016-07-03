#include <avr/interrupt.h>
#include <avr/wdt.h>



void wdtSetup() 
{
    cli();
    MCUSR = 0;
    WDTCSR |= (1 << WDE) | (1 << WDCE);
    WDTCSR = (1 << WDIE) | ( 1 << WDP2) | (1 << WDP1) | (1 << WDP0); 
    sei();
}


/*
 * Watchdog Timer Interrupt
 */
ISR(WDT_vect)
{
   //put interrupt code here
}
