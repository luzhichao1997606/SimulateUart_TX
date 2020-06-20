/*
 * @Descripttion: 
 * @version: 
 * @Author: lzc
 * @Date: 2020-06-20 14:02:11
 * @LastEditors: lzc
 * @LastEditTime: 2020-06-20 15:38:08
 */ 
//此过程为NRF51822程序C文件
//功能：单线模拟PB18作为串口
//波特率 9600
//暂时只有串口功能，之后会做成模块 
#include "HAL_SimulateUART.h"

uint32_t  delayTime =99;	//!<9600，理论值为104但实际测下来99时效果最好


/*******************************************/
/*************需要自己实现的接口**************/
/*******************************************/

//Ⅰ GPIO初始化
void GPIO_Output_Config(uint8_t GPIO_Num)
{
    nrf_gpio_cfg_output(GPIO_Num);
}
//Ⅱ 引脚的拉低拉高
void GPIO_Set_High(uint8_t Pin_Num_TX_Set)
{
    nrf_gpio_pin_set(Pin_Num_TX_Set);
}

void GPIO_Set_Low(uint8_t Pin_Num_TX_Set)
{
    nrf_gpio_pin_clear(Pin_Num_TX_Set);
}
//Ⅲ 微秒延时函数的实现

void Delay_us_Normol(uint16_t Delay_us_Num)
{
    nrf_delay_us(Delay_us_Num);
}


/*******************************************/
/*************不需要自己实现的接口************/
/*******************************************/

//初始化GPIO,设置为输出
void GPIO_Simulate_Uart_Init()
{
    GPIO_Output_Config(Simulate_Pin_Num);
}

//引脚拉低
void TX_L(uint8_t Pin_Num_TX)
{
    GPIO_Set_Low(Pin_Num_TX);

}

//引脚拉高
void TX_H(uint8_t Pin_Num_TX)
{
    GPIO_Set_High(Pin_Num_TX);
}

/*!
 * @brief 	模拟串口发送一个字节
 * @param	
 * @return	none
 * @note	数据低位在前高位在后
 */
void MUSART1_SendData(uint8_t data)
{
	uint8_t i = 0;
	TX_L(Simulate_Pin_Num);		//!<起始位
	Delay_us_Normol(delayTime);
	for(i = 0; i < 8; i++){
        
		if(data & 0x01)
			TX_H(Simulate_Pin_Num);
		else
			TX_L(Simulate_Pin_Num); 

        Delay_us_Normol(delayTime);
		data >>= 1;
	}
	TX_H(Simulate_Pin_Num);		//!<停止位
	Delay_us_Normol(delayTime);
}
 

/*!
 * @brief 	重定向c库函数printf到USART
 * @param	
 * @return	none
 * @note	 
 */
int fputc(int ch, FILE *f)
{
        /*发送一个字节数据USART1 */
        MUSART1_SendData((uint8_t) ch); 
        return (ch);
}
