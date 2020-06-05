//-----------------------------------------------------------------------------
// \file    OV5640 .c
// \brief   implementation of a camera driver for the C6748 EVM.
//
//-----------------------------------------------------------------------------
#include "stdio.h"
#include "types.h"
#include "rk6748.h"
#include "rk6748_timer.h"
#include "rk6748_i2c.h"
#include "ov5640cfg.h"
#include "ov5640af.h"


//OV5640相关寄存器定义  
#define OV5640_CHIPIDH          0X300A  	//OV5640芯片ID高字节
#define OV5640_CHIPIDL          0X300B  	//OV5640芯片ID低字节
#define OV5640_ID               0X5640  	//OV5640的芯片ID
 

//-----------------------------------------------------------------------------
// Private Defines and Macros
//-----------------------------------------------------------------------------

// i2c defines.
#define I2C_PORT_OV5640      (I2C0)
#define I2C_ADDR_OV5640      (0x78>>1)

#define I2C_ADDR_BUSSW        (0x0073)
// i2c bus switch defines.
#define I2C_BUSSW_CH0EN       (0x01)
#define I2C_BUSSW_CH1EN       (0x02)



UINT32 OV5640_readRegister(UINT16 in_reg_addr, UINT8 *dest_buffer)
{
	UINT32 rtn;
	UINT8 i2c_data[2];
	
	i2c_data[0] = (UINT8)((in_reg_addr & 0xFF00) >> 8);
	i2c_data[1] = (UINT8)(in_reg_addr & 0x00FF);

   // write the register address that we want to read.
   rtn = I2C_write(I2C0, I2C_ADDR_OV5640, i2c_data, 2, SKIP_STOP_BIT_AFTER_WRITE);
   if (rtn != ERR_NO_ERROR)
      return (rtn);

   // clock out the register data.
   rtn = I2C_read(I2C0, I2C_ADDR_OV5640, i2c_data, 1, SKIP_BUSY_BIT_CHECK);
   if (rtn != ERR_NO_ERROR)
      return (rtn);

   *dest_buffer = i2c_data[0];
   
   return (rtn);
}

//OV5640读寄存器
//返回值:读到的寄存器值
UINT8 OV5640_RD_Reg(UINT16 reg)
{
	UINT32 rtn;
	UINT8  i2c_data[2];
	
	i2c_data[0] = (UINT8)((reg & 0xFF00) >> 8);
	i2c_data[1] = (UINT8)(reg & 0x00FF);

   // write the register address that we want to read.
   rtn = I2C_write(I2C_PORT_OV5640, I2C_ADDR_OV5640, i2c_data, 2, SKIP_STOP_BIT_AFTER_WRITE);
   if (rtn != ERR_NO_ERROR)
      return (rtn);

   // clock out the register data.
   I2C_read(I2C_PORT_OV5640, I2C_ADDR_OV5640, i2c_data, 1, SKIP_BUSY_BIT_CHECK);
   
   return (i2c_data[0]);
}

//OV5640写寄存器
//返回值:0,成功;1,失败.
UINT8 OV5640_WR_Reg(UINT16 reg,UINT8 data)
{
	 UINT32 rtn;
	 UINT8	i2c_data[3];
	 
	 i2c_data[0] = (UINT8)((reg & 0xFF00) >> 8);
	 i2c_data[1] = (UINT8)(reg & 0x00FF);
	 i2c_data[2] = data;
	
	// write the register that we want to read.
	rtn = I2C_write(I2C_PORT_OV5640, I2C_ADDR_OV5640, i2c_data, 3, SET_STOP_BIT_AFTER_WRITE);
	
	return (rtn);
}


UINT16 OV5640_Init(void)
{
	UINT16 i=0;
	UINT16 reg;
	
   	RK6748_pinmuxConfig(13, 0xF0F00000, 0x80800000);
   	GPIO_setDir(6,8,0);  //RST
   	GPIO_setDir(6,10,0); //POWER
   
   	GPIO_setOutput(6,8,0);	//必须先拉低OV5640的RST脚,再上电
   	MsDelay(500);
   	GPIO_setDir(6,10,0);    //POWER ON
   	MsDelay(500);
   	GPIO_setOutput(6,8,1);	
   	MsDelay(500);
 
   	I2C_init(I2C0, I2C_CLK_100K);//初始化SCCB 的IO口 
   	MsDelay(100);	

	reg=OV5640_RD_Reg(OV5640_CHIPIDH);	//读取ID 高八位
	reg<<=8;
	reg|=OV5640_RD_Reg(OV5640_CHIPIDL);	//读取ID 低八位
	
	printf("ID:0x%04X\r\n",reg);
	
	if(reg!=OV5640_ID)
	{
		printf("ID:0x%04X\r\n",reg);
		return 1;
	} 

	//reg write test
	/*
	reg=OV5640_RD_Reg(0x3c01);
	printf("ID:0x%02X\r\n",reg);
	OV5640_WR_Reg(0x3c01,0X34);	//system clock from pad, bit[1]
	reg=OV5640_RD_Reg(0x3c01);
	printf("ID:0x%02X\r\n",reg);
	*/
	
	OV5640_WR_Reg(0x3103,0X11);	//system clock from pad, bit[1]
	OV5640_WR_Reg(0X3008,0X82);	//软复位
	MsDelay(10);
 	//初始化 OV5640 
	for(i=0;i<sizeof(ov5640_init_reg_tbl)/4;i++)
	{
	   	OV5640_WR_Reg(ov5640_init_reg_tbl[i][0],ov5640_init_reg_tbl[i][1]);
 	}    
	//检查闪光灯是否正常
//	OV5640_Flash_Ctrl(1);//打开闪光灯
//	MsDelay(50);
//	OV5640_Flash_Ctrl(0);//关闭闪光灯
  	return 0x00; 	//ok
	
}
 
//OV5640切换为JPEG模式
void OV5640_JPEG_Mode(void) 
{
	UINT16 i=0; 
	//设置:输出JPEG数据
	for(i=0;i<(sizeof(OV5640_jpeg_reg_tbl)/4);i++)
	{
		OV5640_WR_Reg(OV5640_jpeg_reg_tbl[i][0],OV5640_jpeg_reg_tbl[i][1]);  
	}  
}
//OV5640切换为RGB565模式
void OV5640_RGB565_Mode(void) 
{
	UINT16 i=0;
	//设置:RGB565输出
	for(i=0;i<(sizeof(ov5640_rgb565_reg_tbl)/4);i++)
	{
		OV5640_WR_Reg(ov5640_rgb565_reg_tbl[i][0],ov5640_rgb565_reg_tbl[i][1]); 
	} 
} 
//EV曝光补偿设置参数表，支持7个等级
const static UINT8 OV5640_EXPOSURE_TBL[7][6]=
{
    0x10,0x08,0x10,0x08,0x20,0x10,//-3  
    0x20,0x18,0x41,0x20,0x18,0x10,//-
    0x30,0x28,0x61,0x30,0x28,0x10,//-1 
    0x38,0x30,0x61,0x38,0x30,0x10,//0  
    0x40,0x38,0x71,0x40,0x38,0x10,//+1 
    0x50,0x48,0x90,0x50,0x48,0x20,//+2   
    0x60,0x58,0xa0,0x60,0x58,0x20,//+3    
};

//EV曝光补偿
//exposure:0~6,代表补偿-3~3. 
void OV5640_Exposure(UINT8 exposure)
{
    OV5640_WR_Reg(0x3212,0x03);	//start group 3
    OV5640_WR_Reg(0x3a0f,OV5640_EXPOSURE_TBL[exposure][0]); 
	OV5640_WR_Reg(0x3a10,OV5640_EXPOSURE_TBL[exposure][1]); 
    OV5640_WR_Reg(0x3a1b,OV5640_EXPOSURE_TBL[exposure][2]); 
	OV5640_WR_Reg(0x3a1e,OV5640_EXPOSURE_TBL[exposure][3]); 
    OV5640_WR_Reg(0x3a11,OV5640_EXPOSURE_TBL[exposure][4]); 
    OV5640_WR_Reg(0x3a1f,OV5640_EXPOSURE_TBL[exposure][5]); 
    OV5640_WR_Reg(0x3212,0x13); //end group 3
	OV5640_WR_Reg(0x3212,0xa3); //launch group 3
}

//灯光模式参数表,支持5个模式
const static UINT8 OV5640_LIGHTMODE_TBL[5][7]=
{ 
	0x04,0X00,0X04,0X00,0X04,0X00,0X00,//Auto,自动 
	0x06,0X1C,0X04,0X00,0X04,0XF3,0X01,//Sunny,日光
	0x05,0X48,0X04,0X00,0X07,0XCF,0X01,//Office,办公室
	0x06,0X48,0X04,0X00,0X04,0XD3,0X01,//Cloudy,阴天 
	0x04,0X10,0X04,0X00,0X08,0X40,0X01,//Home,室内
}; 
//白平衡设置
//0:自动
//1:日光sunny
//2,办公室office
//3,阴天cloudy
//4,家里home
void OV5640_Light_Mode(UINT8 mode)
{
	UINT8 i;
	OV5640_WR_Reg(0x3212,0x03);	//start group 3
	for(i=0;i<7;i++)OV5640_WR_Reg(0x3400+i,OV5640_LIGHTMODE_TBL[mode][i]);//设置饱和度 
	OV5640_WR_Reg(0x3212,0x13); //end group 3
	OV5640_WR_Reg(0x3212,0xa3); //launch group 3	
}

//色彩饱和度设置参数表,支持7个等级
const static UINT8 OV5640_SATURATION_TBL[7][6]=
{ 
	0X0C,0x30,0X3D,0X3E,0X3D,0X01,//-3 
	0X10,0x3D,0X4D,0X4E,0X4D,0X01,//-2	
	0X15,0x52,0X66,0X68,0X66,0X02,//-1	
	0X1A,0x66,0X80,0X82,0X80,0X02,//+0	
	0X1F,0x7A,0X9A,0X9C,0X9A,0X02,//+1	
	0X24,0x8F,0XB3,0XB6,0XB3,0X03,//+2
 	0X2B,0xAB,0XD6,0XDA,0XD6,0X04,//+3
}; 

//色度设置
//sat:0~6,代表饱和度-3~3. 
void OV5640_Color_Saturation(UINT8 sat)
{ 
	UINT8 i;
	OV5640_WR_Reg(0x3212,0x03);	//start group 3
	OV5640_WR_Reg(0x5381,0x1c);
	OV5640_WR_Reg(0x5382,0x5a);
	OV5640_WR_Reg(0x5383,0x06);
	for(i=0;i<6;i++)OV5640_WR_Reg(0x5384+i,OV5640_SATURATION_TBL[sat][i]);//设置饱和度 
	OV5640_WR_Reg(0x538b, 0x98);
	OV5640_WR_Reg(0x538a, 0x01);
	OV5640_WR_Reg(0x3212, 0x13); //end group 3
	OV5640_WR_Reg(0x3212, 0xa3); //launch group 3	
}

//亮度设置
//bright:0~8,代表亮度-4~4.
void OV5640_Brightness(UINT8 bright)
{
	UINT8 brtval;
	if(bright<4)brtval=4-bright;
	else brtval=bright-4;
	OV5640_WR_Reg(0x3212,0x03);	//start group 3
	OV5640_WR_Reg(0x5587,brtval<<4);
	if(bright<4)OV5640_WR_Reg(0x5588,0x09);
	else OV5640_WR_Reg(0x5588,0x01);
	OV5640_WR_Reg(0x3212,0x13); //end group 3
	OV5640_WR_Reg(0x3212,0xa3); //launch group 3
}

//对比度设置
//contrast:0~6,代表亮度-3~3.
void OV5640_Contrast(UINT8 contrast)
{
	UINT8 reg0val=0X00;//contrast=3,默认对比度
	UINT8 reg1val=0X20;
  	switch(contrast)
	{
		case 0://-3
			reg1val=reg0val=0X14;	 	 
			break;	
		case 1://-2
			reg1val=reg0val=0X18; 	 
			break;	
		case 2://-1
			reg1val=reg0val=0X1C;	 
			break;	
		case 4://1
			reg0val=0X10;	 	 
			reg1val=0X24;	 	 
			break;	
		case 5://2
			reg0val=0X18;	 	 
			reg1val=0X28;	 	 
			break;	
		case 6://3
			reg0val=0X1C;	 	 
			reg1val=0X2C;	 	 
			break;	
	} 
	OV5640_WR_Reg(0x3212,0x03); //start group 3
	OV5640_WR_Reg(0x5585,reg0val);
	OV5640_WR_Reg(0x5586,reg1val); 
	OV5640_WR_Reg(0x3212,0x13); //end group 3
	OV5640_WR_Reg(0x3212,0xa3); //launch group 3
}

//锐度设置
//sharp:0~33,0,关闭;33,auto;其他值,锐度范围.
void OV5640_Sharpness(UINT8 sharp)
{
	if(sharp<33)//设置锐度值
	{
		OV5640_WR_Reg(0x5308,0x65);
		OV5640_WR_Reg(0x5302,sharp);
	}else	//自动锐度
	{
		OV5640_WR_Reg(0x5308,0x25);
		OV5640_WR_Reg(0x5300,0x08);
		OV5640_WR_Reg(0x5301,0x30);
		OV5640_WR_Reg(0x5302,0x10);
		OV5640_WR_Reg(0x5303,0x00);
		OV5640_WR_Reg(0x5309,0x08);
		OV5640_WR_Reg(0x530a,0x30);
		OV5640_WR_Reg(0x530b,0x04);
		OV5640_WR_Reg(0x530c,0x06);
	}
	
}
//特效设置参数表,支持7个特效
const static UINT8 OV5640_EFFECTS_TBL[7][3]=
{ 
	0X06,0x40,0X10,//正常 
	0X1E,0xA0,0X40,//冷色
	0X1E,0x80,0XC0,//暖色
	0X1E,0x80,0X80,//黑白
	0X1E,0x40,0XA0,//泛黄 
	0X40,0x40,0X10,//反色
	0X1E,0x60,0X60,//偏绿
}; 
//特效设置
//0:正常    
//1,冷色
//2,暖色   
//3,黑白
//4,偏黄
//5,反色
//6,偏绿	    
void OV5640_Special_Effects(UINT8 eft)
{ 
	OV5640_WR_Reg(0x3212,0x03); //start group 3
	OV5640_WR_Reg(0x5580,OV5640_EFFECTS_TBL[eft][0]);
	OV5640_WR_Reg(0x5583,OV5640_EFFECTS_TBL[eft][1]);// sat U
	OV5640_WR_Reg(0x5584,OV5640_EFFECTS_TBL[eft][2]);// sat V
	OV5640_WR_Reg(0x5003,0x08);
	OV5640_WR_Reg(0x3212,0x13); //end group 3
	OV5640_WR_Reg(0x3212,0xa3); //launch group 3
}

//测试序列
//mode:0,关闭
//     1,彩条 
//     2,色块
void OV5640_Test_Pattern(UINT8 mode)
{
	if(mode==0)OV5640_WR_Reg(0X503D,0X00);
	else if(mode==1)OV5640_WR_Reg(0X503D,0X80);
	else if(mode==2)OV5640_WR_Reg(0X503D,0X82);
} 
//闪光灯控制
//mode:0,关闭
//     1,打开 
void OV5640_Flash_Ctrl(UINT8 sw)
{
	OV5640_WR_Reg(0x3016,0X02);
	OV5640_WR_Reg(0x301C,0X02); 
	if(sw)OV5640_WR_Reg(0X3019,0X02); 
	else OV5640_WR_Reg(0X3019,0X00);
} 
//设置图像输出大小
//OV5640输出图像的大小(分辨率),完全由该函数确定
//offx,offy,为输出图像在OV5640_ImageWin_Set设定窗口(假设长宽为xsize和ysize)上的偏移
//由于开启了scale功能,用于输出的图像窗口为:xsize-2*offx,ysize-2*offy
//width,height:实际输出图像的宽度和高度
//实际输出(width,height),是在xsize-2*offx,ysize-2*offy的基础上进行缩放处理.
//一般设置offx和offy的值为16和4,更小也是可以,不过默认是16和4 
//返回值:0,设置成功
//    其他,设置失败
UINT8 OV5640_OutSize_Set(UINT16 offx,UINT16 offy,UINT16 width,UINT16 height)
{ 
    OV5640_WR_Reg(0X3212,0X03);  	//开始组3
    //以下设置决定实际输出尺寸(带缩放)
    OV5640_WR_Reg(0x3808,width>>8);	//设置实际输出宽度高字节
    OV5640_WR_Reg(0x3809,width&0xff);//设置实际输出宽度低字节  
    OV5640_WR_Reg(0x380a,height>>8);//设置实际输出高度高字节
    OV5640_WR_Reg(0x380b,height&0xff);//设置实际输出高度低字节
	//以下设置决定输出尺寸在ISP上面的取图范围
	//范围:xsize-2*offx,ysize-2*offy
    OV5640_WR_Reg(0x3810,offx>>8);	//设置X offset高字节
    OV5640_WR_Reg(0x3811,offx&0xff);//设置X offset低字节
	
    OV5640_WR_Reg(0x3812,offy>>8);	//设置Y offset高字节
    OV5640_WR_Reg(0x3813,offy&0xff);//设置Y offset低字节
	
    OV5640_WR_Reg(0X3212,0X13);		//结束组3
    OV5640_WR_Reg(0X3212,0Xa3);		//启用组3设置
	return 0; 
}

//设置图像开窗大小(ISP大小),非必要,一般无需调用此函数
//在整个传感器上面开窗(最大2592*1944),用于OV5640_OutSize_Set的输出
//注意:本函数的宽度和高度,必须大于等于OV5640_OutSize_Set函数的宽度和高度
//     OV5640_OutSize_Set设置的宽度和高度,根据本函数设置的宽度和高度,由DSP
//     自动计算缩放比例,输出给外部设备.
//width,height:宽度(对应:horizontal)和高度(对应:vertical)  
//返回值:0,设置成功
//    其他,设置失败
UINT8 OV5640_ImageWin_Set(UINT16 offx,UINT16 offy,UINT16 width,UINT16 height)
{
	UINT16 xst,yst,xend,yend;
	xst=offx;
	yst=offy;
	xend=offx+width-1;
	yend=offy+height-1;  
    OV5640_WR_Reg(0X3212,0X03);		//开始组3
	OV5640_WR_Reg(0X3800,xst>>8);	
	OV5640_WR_Reg(0X3801,xst&0XFF);	
	OV5640_WR_Reg(0X3802,yst>>8);	
	OV5640_WR_Reg(0X3803,yst&0XFF);	
	OV5640_WR_Reg(0X3804,xend>>8);	
	OV5640_WR_Reg(0X3805,xend&0XFF);
	OV5640_WR_Reg(0X3806,yend>>8);	
	OV5640_WR_Reg(0X3807,yend&0XFF);
    OV5640_WR_Reg(0X3212,0X13);		//结束组3
    OV5640_WR_Reg(0X3212,0Xa3);		//启用组3设置	 
	return 0;
}   
//初始化自动对焦
//返回值:0,成功;1,失败.
UINT8 OV5640_Focus_Init(void)
{ 
	UINT16 i; 
	UINT16 addr=0x8000;
	UINT8 state=0x8F;
	OV5640_WR_Reg(0x3000, 0x20);			//reset MCU	 
	for(i=0;i<sizeof(OV5640_AF_Config);i++) //发送配置数组
	{
		OV5640_WR_Reg(addr,OV5640_AF_Config[i]);
		addr++;
	}  
	OV5640_WR_Reg(0x3022,0x00);
	OV5640_WR_Reg(0x3023,0x00);
	OV5640_WR_Reg(0x3024,0x00);
	OV5640_WR_Reg(0x3025,0x00);
	OV5640_WR_Reg(0x3026,0x00);
	OV5640_WR_Reg(0x3027,0x00);
	OV5640_WR_Reg(0x3028,0x00);
	OV5640_WR_Reg(0x3029,0x7f);
	OV5640_WR_Reg(0x3000,0x00); 
	i=0;
	do
	{
		state=OV5640_RD_Reg(0x3029);	
		MsDelay(5);
		i++;
		if(i>1000)return 1;
	}while(state!=0x70); 
	return 0;    
}  
//执行一次自动对焦
//返回值:0,成功;1,失败.
UINT8 OV5640_Focus_Single(void)
{
	UINT8 temp; 
	UINT16 retry=0; 
	OV5640_WR_Reg(0x3022,0x03);		//触发一次自动对焦 
	while(1)
	{
		retry++;
		temp=OV5640_RD_Reg(0x3029);	//检查对焦完成状态
		if(temp==0x10)break;		// focus completed
		MsDelay(5);
		if(retry>1000)return 1;
	}
	return 0;	 		
}
//持续自动对焦,当失焦后,会自动继续对焦
//返回值:0,成功;其他,失败.
UINT8 OV5640_Focus_Constant(void)
{
	UINT8 temp=0;   
	UINT16 retry=0; 
	OV5640_WR_Reg(0x3023,0x01);
	OV5640_WR_Reg(0x3022,0x08);//发送IDLE指令 
	do 
	{
		temp=OV5640_RD_Reg(0x3023); 
		retry++;
		if(retry>1000)return 2;
		MsDelay(5);
	} while(temp!=0x00);   
	OV5640_WR_Reg(0x3023,0x01);
	OV5640_WR_Reg(0x3022,0x04);//发送持续对焦指令 
	retry=0;
	do 
	{
		temp=OV5640_RD_Reg(0x3023); 
		retry++;
		if(retry>1000)return 2;
		MsDelay(5);
	}while(temp!=0x00);//0,对焦完成;1:正在对焦
	return 0;
} 






