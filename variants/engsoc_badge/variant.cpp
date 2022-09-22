/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[] =
    {
        // Onboard LED
        // -----------------
        // 0..2 - RED, GREEN, BLUE
        {PORTA, 18, PIO_PWM, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM), No_ADC_Channel, PWM0_CH2, TCC0_CH2, EXTERNAL_INT_2},
        {PORTA, 17, PIO_PWM, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM), No_ADC_Channel, PWM0_CH7, TCC0_CH7, EXTERNAL_INT_1},
        {PORTA, 16, PIO_PWM, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM), No_ADC_Channel, PWM0_CH6, TCC0_CH6, EXTERNAL_INT_0},

        // USB
        // --------------------
        {PORTA, 28, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB Host enable
        {PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB/DM
        {PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB/DP

        // ----------------------
        {PORTA, 2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2}, // ADC/AIN[0]
                                                                                                         // 43 - Alternate use of A0 (DAC output)
        {PORTA, 2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2}, // DAC/VOUT

        // Shift Register (RGB Chaos Carrier)
        // -----------------
        // 8..11
        {PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15},   // PA_27 LATCH  (DIGITAL)
        {PORTB, 2, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2},  // PB_02 DATA   SERCOM5/PAD[0] (MOSI)
        {PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7}, // PB_23 CLOCK  SERCOM5/PAD[3] (SCK)
        {PORTA, 20, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4},      // PA_20 MISO    SERCOM5/PAD[2]

        // Buttons
        // 12..13
        {PORTA, 14,PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15} 
        };

const void *g_apTCInstances[TCC_INST_NUM + TC_INST_NUM] = {TCC0, TCC1, TCC2, TC3, TC4, TC5};

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);
SERCOM sercom4(SERCOM4);
SERCOM sercom5(SERCOM5);

Uart Serial1(&sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX);
// // Uart Serial5( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;
// void SERCOM0_Handler()
// {
//   Serial1.IrqHandler();
// }

// void SERCOM5_Handler()
// {
//   Serial5.IrqHandler();
// }
