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

#ifndef _Hardserial_H
#define _Hardserial_H

void DebugUartInit(void);

void DebugPrintf(UINT8 *pData);


#endif


