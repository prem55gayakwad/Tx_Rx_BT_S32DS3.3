/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "S32K148.h" /* include peripheral declarations S32K148 */
#include "clocks_and_modes.h"
#include "LPUART.h"
char data=0;
void PORT_init (void) {
PCC->PCCn[PCC_PORTC_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTC */
PORTC->PCR[6]|=PORT_PCR_MUX(2); /* Port C6: MUX = ALT2,UART1 TX (Rx) */
PORTC->PCR[7]|=PORT_PCR_MUX(2); /* Port C7: MUX = ALT2,UART1 RX (Tx) */
}
void WDOG_disable (void){
WDOG->CNT=0xD928C520; /* Unlock watchdog */
WDOG->TOVAL=0x0000FFFF; /* Maximum timeout value */
WDOG->CS = 0x00002100; /* Disable watchdog */
}
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/
WDOG_disable(); /* Disable WDGO*/
SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
SPLL_init_160MHz(); /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
//RUNmode_80MHz(); /* Init clocks: 80 MHz SPLL & core, 40 MHz bus, 20 MHz flash */
NormalRUNmode_80MHz(); /* Init clocks: 80 MHz SPLL & core, 40 MHz bus, 20 MHz flash */
PORT_init(); /* Configure ports */
LPUART1_init(); /* Initialize LPUART @ 9600*/
LPUART1_transmit_string("Running LPUART\n\r"); /* Transmit char string */
LPUART1_transmit_string("Tx_Rx_Bluetooth"); /* Transmit char string */
for(;;) {
LPUART1_transmit_char('>'); /* Transmit prompt character*/

LPUART1_receive_and_echo_char();/* Wait for input char, receive & echo it*/
}
}

