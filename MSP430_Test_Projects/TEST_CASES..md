\# 🔘 Blink LED Test Plan – MSP430

\## 📌 Test Name  
\*\*Blink LED on P1.0\*\*

\---

\## 📟 Purpose  
To verify the basic functionality of \*\*GPIO output\*\* on the MSP430 by toggling LED connected to P1.0.

\---

\## 🔧 Test Environment

| Component        | Details                     |  
|------------------|-----------------------------|  
| Microcontroller  | MSP430G2553                 |  
| Development Board| MSP430 LaunchPad            |  
| IDE              | Energia / Code Composer Studio |  
| Clock Frequency  | 1 MHz (calibrated DCO)      |  
| Power Supply     | USB via LaunchPad           |

\---

\## 🧪 Test Procedure

1\. Disable the watchdog timer.  
2\. Configure system clock to 1 MHz.  
3\. Set \`P1.0\` as output.  
4\. In a loop:  
  - Toggle \`P1.0\`.  
  - Delay for ~100ms.

\---

\## 💻 Code Reference

\`\`\`c  
#include \<msp430.h>

void main(void)  
{  
   WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

   BCSCTL1 = CALBC1\_1MHZ;      // Set DCO to 1MHz  
   DCOCTL = CALDCO\_1MHZ;

   P1DIR |= 0x01;              // Set P1.0 as output

   while (1)  
   {  
       P1OUT ^= 0x01;          // Toggle P1.0  
       \_\_delay\_cycles(100000); // Delay  
   }  
}  
  
\## ✅ Expected Result

\* The on-board LED connected to \`P1.0\` should \*\*blink continuously\*\* at an interval of \\~0.1 seconds.

\---

\## 📌 Actual Result

\* ✅ \*\*PASS\*\*: LED toggles at expected rate.

\* Observed LED blinking on P1.0 pin visually.

\* Board setup verified and repeatable.

\---

\## 📓 Notes

\* Tested on Energia and MSP430G2553.

\* No compilation or runtime errors.

\* Timer delay is sufficient for visible blink.

\---

\## 🔚 Conclusion

The test confirms GPIO P1.0 output is functional and toggling as expected. This establishes the baseline for future GPIO input/output-based testing.

\`\`\`

\---