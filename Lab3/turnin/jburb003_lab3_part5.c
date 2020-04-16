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
DDRD = 0x00; PORTD = 0xFF;
DDRB = 0xFE; PORTB = 0x01;

short weight;

while(1){
weight =( PIND & 0xFF) << 1;
weight = weight +(PINB & 0x01);

if(weight <= 5)
{
PORTB = 0x00;
}

else if((weight > 5) && (weight < 70))
{
PORTB = 0x04;
}

else
{
PORTB = 0x02;
}

}



    return 1;
}
