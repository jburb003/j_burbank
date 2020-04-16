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
DDRC = 0xFF; PORTC = 0x00;

//unsigned char cnt = 0;

unsigned char tempA;
unsigned char temp_status;
    /* Insert your solution below */
    while (1) {

tempA = PINA & 0x0F; //copies the number on PINA while zeroing out the P4 thru p6
temp_status = PINA & 0xF0; //copies only the upper nibble into another variable.
if(tempA < 1)
PORT = 64;

else if((tempA <= 2) && (tempA >= 1))
{
PORTC = 32 + 64;
}

else if((tempA >= 3) && (tempA  <= 4)){
PORTC= 48+64;
}




else if((tempA >= 5) && (tempA <= 6))
{

PORTC = 56;
}

else if((tempA >= 7) && (tempA <= 9))

{

PORTC = 60;
}

else if((tempA >= 10) && (tempA <=12))
{
PORTC = 62;
//then 63
}

else
{
PORTC = 63;
}

//check for status of upper nibble
if(temp_status == 0x30)
{
PORTC =( PORTC | 0x80);
} 
}

    return 1;
}
