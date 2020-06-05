//------------------------------------------------------------------------------
// \file    test_image_sensor.c
// \brief   implementation of C6748 image sensor test.
//
//-----------------------------------------------------------------------------

#include "stdio.h"
#include "types.h"
#include "rk6748.h"
#include "rk6748_timer.h"
#include "rk6748_gpio.h"
#include "rk6748_i2c.h"
#include "rk6748_vpif.h"
#include "test_camera.h"



//RGB565����
//RGB����ֱ����ʾ��LCD����

void rgb565_test(void)
{ 
/*
	u8 key;
	u8 effect=0,contrast=2,fac;
	u8 scale=1;		//Ĭ����ȫ�ߴ�����
	u8 msgbuf[15];	//��Ϣ������ 
	LCD_Clear(WHITE);
  	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"ALIENTEK STM32F4");
	LCD_ShowString(30,70,200,16,16,"OV5640 RGB565 Mode");
	
	LCD_ShowString(30,100,200,16,16,"KEY0:Contrast");			//�Աȶ�
	LCD_ShowString(30,130,200,16,16,"KEY1:Saturation"); 	//ɫ�ʱ��Ͷ�
	LCD_ShowString(30,150,200,16,16,"KEY2:Effects"); 			//��Ч 
	LCD_ShowString(30,170,200,16,16,"KEY_UP:FullSize/Scale");	//1:1�ߴ�(��ʾ��ʵ�ߴ�)/ȫ�ߴ�����
*/
	//�Զ��Խ���ʼ��
	OV5640_RGB565_Mode();	//RGB565ģʽ 
	OV5640_Focus_Init();
	
	OV5640_Light_Mode(0);	//�Զ�ģʽ
	OV5640_Color_Saturation(3);//ɫ�ʱ��Ͷ�0
	OV5640_Brightness(4);	//����0
	OV5640_Contrast(3);		//�Աȶ�0
	OV5640_Sharpness(33);	//�Զ����
	OV5640_Focus_Constant();//���������Խ�
 	OV5640_OutSize_Set(4,0,640,480); 

	/*
	while(1)
	{ 
		key=KEY_Scan(0); 
		if(key)
		{ 
			if(key!=KEY1_PRES)DCMI_Stop(); //��KEY1����,ֹͣ��ʾ
			switch(key)
			{				    
				case KEY0_PRES:	//�Աȶ�����
					contrast++;
					if(contrast>6)contrast=0;
					OV5640_Contrast(contrast);
					sprintf((char*)msgbuf,"Contrast:%d",(signed char)contrast-3);
					break;
				case KEY1_PRES:	//ִ��һ���Զ��Խ�
					OV5640_Focus_Single();
					break;
				case KEY2_PRES:	//��Ч����				 
					effect++;
					if(effect>6)effect=0;
					OV5640_Special_Effects(effect);//������Ч
					sprintf((char*)msgbuf,"%s",EFFECTS_TBL[effect]);
					break;
				case WKUP_PRES:	//1:1�ߴ�(��ʾ��ʵ�ߴ�)/����	    
					scale=!scale;  
					if(scale==0)
					{
						fac=800/lcddev.height;//�õ���������
 						OV5640_OutSize_Set((1280-fac*lcddev.width)/2,(800-fac*lcddev.height)/2,lcddev.width,lcddev.height); 	 
						sprintf((char*)msgbuf,"Full Size 1:1");
					}else 
					{
						OV5640_OutSize_Set(4,0,lcddev.width,lcddev.height);
 						sprintf((char*)msgbuf,"Scale");
					}
					break;
			}
			if(key!=KEY1_PRES)	//��KEY1����
			{
				LCD_ShowString(30,50,210,16,16,msgbuf);//��ʾ��ʾ����
				delay_ms(800); 
				DCMI_Start();	//���¿�ʼ����
			}
		} 
		delay_ms(10);		
	}   
	*/
} 


//-----------------------------------------------------------------------------
// \brief   tests the camera interface.
//
// \param   none.
//
// \return  UINT32
//-----------------------------------------------------------------------------
UINT32 TEST_imageSensor(void)
{
   UINT32 rtn = ERR_NO_ERROR;
   UINT32 i=0;

   DebugPrintf("------------------------------------------------------------\r\n");
   DebugPrintf("                C6748 Image Sensor OV5640 Test\r\n\r\n");

   //-------------------------------------
	// initialize the required bsl modules.
   //-------------------------------------
   DebugPrintf("Initialize the Required BSL Modules\r\n");
   DebugPrintf("-----------------------------------\r\n\r\n");

   RK6748_configCache();
   OV5640_Init();
   rgb565_test(); 

   MsDelay(500);
   rtn = VPIF_initReceive(VIDEO_CONN_CAMERA);
   MsDelay(500);

   if (rtn != ERR_NO_ERROR)
   {
      DebugPrintf("error initializing vpif receive!\r\n");
      return (rtn);
   }

   DebugPrintf("\r\n\r\n");
   DebugPrintf("				C6748 Image Sensor OV5640 Test OK!\r\n\r\n");
   DebugPrintf("------------------------------------------------------------\r\n");

   return (rtn);
}

//-----------------------------------------------------------------------------
// Private Function Definitions
//-----------------------------------------------------------------------------

