/*========================================================*
 * �ļ�ģ��˵��:
 *C6748�Ĵ���   
 * �ļ��汾: V1.0.0
 * ������Ա: Rock
 * ����ʱ��: 2013-11-01 
 * Copyright(c) 2013-2015  Rock-Embed Limited Co.
 *========================================================*
 * �����޸ļ�¼��
 * <�汾��> <�޸�����>, <�޸���Ա>: <�޸Ĺ��ܸ���>
 *      V1.0.0           2013-11-01              Rock                        ����
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
/*             �����ж�                                                 										*/
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
/*              ����UART0�ж�                                                 										*/
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
/*              ����UART1�ж�                                                 										*/
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
/*              ����UART2�ж�                                                 										*/
/*                                                                          */
/****************************************************************************/
static void ConfigureIntUART2(void)
{
	IntRegister(C674X_MASK_INT6, RK6748_uartRxInt2);
	IntEventMap(C674X_MASK_INT6, SYS_INT_UART2_INT);
	IntEnable(C674X_MASK_INT6);
}


//���Դ���uart1��ʼ��
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

//����uart2��ʼ��
void Uart2Init(void)
{  
	RK6748_uartInit(2,57600);
	RK6748_uartIntEnable(2);
	SetupInt();
	ConfigureIntUART2();
}

