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

enum States{Start,Init, check1, check2, unlock, lock}state;
void Tick(){

switch(state){
//State transitions
case Start:
state = Init;
break;
//Init state transition
case Init:
if((PINA & 0xFF) == 4)
{
state = check1;
}


else
{
state = Init;
}

break;

//check1 state 
case check1:
if((PINA & 0xFF) == 4)
{
state = check1;
}

else if((PINA & 0xFF) == 0)
{
state = check2;
}
break;

//check2
case check2:
if((PINA & 0xFF) == 2)
{
state = unlock;
}

else 
{
state = Init;
}
break;

//unlock state
case unlock:
if((PINA & 0x80) == 128)
{state = lock;}

else
state = unlock;
break;

//lock state
case lock:
state = Init;
break;

default:
state = Start;
break;
}

//state actions
switch(state){

case Init:
PORTB = 0;
PORTC = 0;
break;

case check1:
PORTC = 1;
break;

case check2:
PORTC = 2;
break;

case unlock:
PORTB = 1;
PORTC = 3;

case lock:
PORTB = 0;
PORTC = 4;


default:
break;
}
}
int main(void) {
DDRB = 0xFF; PORTB = 0x00;    
DDRC = 0xFF; PORTC = 0x00;
DDRA = 0x00; PORTA = 0xFF;
state = Start;
    /* Insert your solution below */
    while (1) {
	Tick();
    
    
}

return 1;
}
