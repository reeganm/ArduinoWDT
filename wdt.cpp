#include <avr/interrupt.h>
#include <avr/wdt.h>


/*
 * Pointer function for interrupt request
 */
void (*functionPtr)(void);

void wdtSetup(Ptr) 
{
    //set pointer function
    functionPtr = Ptr;
    
    //start wdr
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
   //run pointer function
   (*functionPtr)();
}
