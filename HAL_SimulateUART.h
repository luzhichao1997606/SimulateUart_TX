/*
 * @Descripttion: 
 * @version: 
 * @Author: lzc
 * @Date: 2020-06-20 14:03:51
 * @LastEditors: lzc
 * @LastEditTime: 2020-06-20 17:58:59
 */  
#ifndef __HAL_SIMULATEUART_H 
#define	__HAL_SIMULATEUART_H 

#include "nrf51.h"
//包含需要的头文件
#include <stdio.h>
#include <stdarg.h>
#include "string.h"       

#include "nrf_gpio.h" 
#include "nrf_delay.h"

#define Simulate_Pin_Num 18

void GPIO_Simulate_Uart_Init(void); 

void UART_Debug_Printf(const char* fmt, ...);

#endif /* __HAL_SIMULATEUART_H */
