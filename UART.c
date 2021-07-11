/*
 * UART.c
 *
 *  Created on: Mar 26, 2021
 *      Author: DELL
 */

#include "BIT_MATH.h"
#include "DIO_reg.h"
#include "STD_TYPES.h"
#include "UART.h"
#include <avr/io.h>

#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)


void UART_Init(void)
{
  // Set BaudRate -> 9600/12MhZ
  UBRRL = 51;
  //UBRRH = 0;
//  UBRRH = (BAUDRATE>>8);

  UCSRC=(1<<7)|(1<<1)|(1<<2);
 //UCSRC = 0xc0;
 //UCSRC = 0x86;

 //enable tx and rx
 //UCSRB = 0x18;
 UCSRB=(1<<3)|(1<<4);

}

void UART_SendChar(uint8 data)
{
  // Wait until transmission Register Empty
  //while((UCSRA&0x20) == 0x00);
  while (!(UCSRA & (1<<5)));
  UDR = data;
}

uint8 UART_GetChar(void)
{
  uint8 Result;
  // Wait until Reception Complete
  //while((UCSRA&0x80) == 0x00);
  while (!(UCSRA & (1<<7)));
  Result = UDR;

  /* Clear Flag */
  SET_BIT(UCSRA,7);

  return Result;

}

