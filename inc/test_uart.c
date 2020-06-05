/*========================================================*
 * 文件模块说明:
 *C6748的串口   
 * 文件版本: V1.0.0
 * 开发人员: Rock
 * 创建时间: 2013-11-01 
 * Copyright(c) 2013-2015  Rock-Embed Limited Co.
 *========================================================*
 * 程序修改记录：
 * <版本号> <修改日期>, <修改人员>: <修改功能概述>
 *      V1.0.0           2013-11-01              Rock                        创建
 *========================================================*/
#include "types.h"
#include "test_uart.h"
#include <stdio.h>
#include <string.h>
#include "interrupt.h"


#define DEBUG_PORT           (1)//uart1
#define DEBUG_PORT_BaudRate  (57600)//uart1


extern void RK6748_uartRxInt0(void);
extern void RK6748_uartRxInt1(void);
extern void RK6748_uartRxInt2(void);

/****************************************************************************/
/*                                                                          */
/*             设置中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void SetupInt(void)
{	
	// Initialize the DSP INTC
	IntDSPINTCInit();
	// Enable DSP interrupts globally
	IntGlobalEnable();
}

/****************************************************************************/
/*                                                                          */
/*              设置UART0中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void ConfigureIntUART0(void)
{
	IntRegister(C674X_MASK_INT4, RK6748_uartRxInt0);
	IntEventMap(C674X_MASK_INT4, SYS_INT_UART0_INT);
	IntEnable(C674X_MASK_INT4);
}

/****************************************************************************/
/*                                                                          */
/*              设置UART1中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void ConfigureIntUART1(void)
{
	IntRegister(C674X_MASK_INT5, RK6748_uartRxInt1);
	IntEventMap(C674X_MASK_INT5, SYS_INT_UART1_INT);
	IntEnable(C674X_MASK_INT5);
}

/****************************************************************************/
/*                                                                          */
/*              设置UART2中断                                                 										*/
/*                                                                          */
/****************************************************************************/
static void ConfigureIntUART2(void)
{
	IntRegister(C674X_MASK_INT6, RK6748_uartRxInt2);
	IntEventMap(C674X_MASK_INT6, SYS_INT_UART2_INT);
	IntEnable(C674X_MASK_INT6);
}


//调试串口uart1初始化
void DebugUartInit(void)
{  
	RK6748_uartInit(DEBUG_PORT,DEBUG_PORT_BaudRate);
	RK6748_uartIntEnable(DEBUG_PORT);
	SetupInt();
	ConfigureIntUART1();
}


void DebugPrintf(UINT8 *pData)
{
	RK6748_uartSend(DEBUG_PORT,pData);
	printf(pData);
}

//串口uart2初始化
void Uart2Init(void)
{  
	RK6748_uartInit(2,57600);
	RK6748_uartIntEnable(2);
	SetupInt();
	ConfigureIntUART2();
}

