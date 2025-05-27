#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    BCSCTL1 = CALBC1_1MHZ;      // Set DCO to 1MHz
    DCOCTL = CALDCO_1MHZ;

    P1DIR |= 0x01;              // Set P1.0 as output

    while (1)
    {
        P1OUT ^= 0x01;          // Toggle P1.0
        __delay_cycles(100000); // Delay
    }
}
