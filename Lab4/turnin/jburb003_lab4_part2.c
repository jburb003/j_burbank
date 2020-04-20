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

enum States{Start,Init, wait, clear}state;
void Tick(){

switch(state){
//State transitions
case Start:
state = Init;
break;

case Init:
if((PINA & 0xFF) == 0)
{
state = Init;

}

else if((PINA & 0xFF) == 1)
{
PORTC++;
state = wait;

}

else if((PINA & 0xFF) == 2)
{
PORTC--;
state = wait;
}

else
{
state = clear;
}


break;

case wait:
if(((PINA & 0xFF) == 1) && (PORTC < 9))
{
PORTC++;
state = wait;

}

else if(((PINA & 0xFF) == 2) && (PORTC > 0))
{
PORTC--;
state = wait;

}

else if((PINA & 0xFF) == 3) 
{
state = clear;
}

else
{
state = wait;
}

break;


case clear:
state = wait;

default:
state = wait;
break;
}

//state actions
switch(state) {

case Init:
PORTC = 7;
break;

case clear:
PORTC = 0;
break;

default:
break;
}


}


int main(void) {
    
DDRC = 0xFF; PORTC = 0x00;
DDRA = 0x00; PORTA = 0xFF;
PORTC = 0x07;
state = Start;
    /* Insert your solution below */
    while (1) {
	Tick();
    
    
}

return 1;
}
