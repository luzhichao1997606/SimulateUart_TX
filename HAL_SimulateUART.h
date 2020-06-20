/*
 * @Descripttion: 
 * @version: 
 * @Author: lzc
 * @Date: 2020-06-20 14:03:51
 * @LastEditors: lzc
 * @LastEditTime: 2020-06-20 15:42:39
 */  
#ifndef __HAL_SIMULATEUART_H 
#define	__HAL_SIMULATEUART_H 

#include "nrf51.h"
#include "stdio.h" 
#include "nrf_gpio.h" 
#include "nrf_delay.h"

#define Simulate_Pin_Num 18

void GPIO_Simulate_Uart_Init(void);
void MUSART1_SendData(uint8_t data);
#endif /* __HAL_SIMULATEUART_H */
