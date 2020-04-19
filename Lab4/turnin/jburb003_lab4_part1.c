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

enum States{Start, light1, light2}state;
void Tick(){

switch(state){
//State transitions
case Start:
state = light1;
break;

case light1:
if(PINA & 1)
{
state = light1;
}
else
{
state = light2;
}
break;

case light2:
if(!(PINA & 1))
{
state = light2;
}

else
{
state = light1;
}
break;


default:
break;
}
switch(state){
//state actions
case light1:

PORTB = 1;
break;

case light2:
PORTB = 2;
break;

default:
break;
}

}


int main(void) {
    
DDRB = 0xFF; PORTB = 0x00;
DDRA = 0x00; PORTA = 0xFF;
    /* Insert your solution below */
    while (1) {
PINB = 0x01;
state = Start;

	while(1) {
	Tick();
    }
    
}

return 1;
}
