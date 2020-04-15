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
DDRC = 0xFF; PORTC = 0X00;
unsigned char cntavail = 0;
    /* Insert your solution below */
    while (1) {

cntavail = 4;

if((PINA & 0x01) == 0x01)
{
cntavail--;
}

if((PINA & 0x02) == 0x02)
{
cntavail--;
}

if((PINA & 0x04) == 0x04)
{
cntavail--;
}

if((PINA & 0x08) == 0x08)
{
cntavail--;
}

PORTC = cntavail;
if(cntavail == 0)
PORTC = 0x8F;
}
}
