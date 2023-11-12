#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"
void initPWM();

int main(void)
{
    
	int16_t counter;
	
    while (1) 
    {
		counter = 255;
		while(counter>0){
			OCR2 = counter;
			counter--;
		_delay_ms(10);
		}
		_delay_ms(100);
		counter = 0;
		while(counter<256){
			OCR2 = counter;
			counter++;
			_delay_ms(10);
		}
		_delay_ms(100);
		
    }
}

void initPWM(){
	    DDRB |= (1<<7);
	    TCCR2 = 0;
	    TCCR2 |= (1<<WGM20);
	    TCCR2 |= (1<<COM20) | (1<<COM21);
	    TCCR2 |= (1<<CS20);
}
