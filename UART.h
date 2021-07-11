/*
 * UART.h
 *
 *  Created on: Mar 26, 2021
 *      Author: DELL
 */

#ifndef UART_H_
#define UART_H_

void UART_Init(void);

//extern void UART_SendChar(uint8 data);

//extern uint8 UART_GetChar(void);
extern void UART_SendChar(uint8 data);

extern uint8 UART_GetChar(void);

#endif /* UART_H_ */
