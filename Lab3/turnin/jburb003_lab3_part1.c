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
DDRC = 0xFF; PORTC = 0x00;

unsigned char cnt = 0;
unsigned char i = 0;
unsigned char tempA, tempB;
    /* Insert your solution below */
    while (1) {
tempA = PINA & 0xFF;
tempB = PINB & 0xFF;
cnt = 0;
for(i = 0; i < 8; ++i)
{
if((tempA & 0x01) == 1)
{
cnt++;
}
tempA = tempA >> 1;
}

for(i = 0; i < 8; ++i)
{
if((tempB & 0x01) == 1)
{
cnt++;
}
tempB = tempB >> 1;
}

PORTC = cnt;
    }
    return 1;
}
