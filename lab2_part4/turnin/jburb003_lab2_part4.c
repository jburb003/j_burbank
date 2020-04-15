/*	Author: jburb003
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0x00; PORTB = 0xFF;
DDRC = 0x00; PORTC = 0XFF;
DDRD = 0xFF; PORTD = 0x00;

unsigned tempA = 0;
unsigned tempB = 0;
unsigned tempC = 0;
unsigned tempD = 0;
unsigned total = 0;

    /* Insert your solution below */
    while (1) {
/*8 bit sensor for ports A B and C
 PD0 is 1 if A + B + C > 140kg
 PD1 is 1 if A - C
 PD2 - PD7 is a representation of the total weight
*/

tempA = PINA & 0xFF;
tempB = PINB & 0xFF;
tempC = PINC & 0xFF;
tempD = 0;
if((tempA + tempB + tempC) > 140) 
{ tempD++;}

if(tempA > tempC)
{
     if((tempA - tempC) > 80 )
        {tempD = tempD + 2;}
}

else if((tempC - tempA) > 80)
{tempD = tempD + 2;}

total = tempA + tempB + tempC;
total = total & 0xFC;

tempD = tempD + total;

PORTD = tempD;





}
    
    return 1;
}
