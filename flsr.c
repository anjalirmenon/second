#include <stdint.h>
#include<msp430.h>
#include<stdio.h>
#define LED1 BIT0
//#define TOGGLE_LED1 (P1OUT ^= LED1)
uint16_t lfsr = 0xACE1u;
unsigned bit;
unsigned period = 0;
void delay()
{
                unsigned int i = 0;
                while(++i < 30000);
}
main()
{
do {
          bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
          lfsr =  (lfsr >> 1) | (bit << 15);
          ++period;
         // printf("%d",bit);
          P1OUT = 0;
          P1DIR = 1;
          while(1) {
                //      TOGGLE_LED1;
                        delay();
                }
} while(lfsr != 0xACE1u);
}

