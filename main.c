/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: DELL
 */

#include "DIO.h"
#include "UART.h"
#include "BIT_MATH.h"
int main()
{
	DIO_Init();
	UART_Init();
	uint8 x;

	while(1){

		x=UART_GetChar();
		if(x=='t')
		{
			//TOGGLE_BIT(PORTA,0);
			DIO_WriteChannel(PORTA0 , 1);
			//UART_SendChar(x);
		}
		else if(x=='o')
		{
			//CLEAR_BIT(PORTA,0);
			DIO_WriteChannel(PORTA1 , 1);
			//UART_SendChar(x);
		}
		else if(x=='p')
		{
			//SET_BIT(PORTA,0);
			DIO_WriteChannel(PORTA2 , 1);
		}
		UART_SendChar(x);
	}
}

