#include "hwjs.h"
#include "SysTick.h"
#include "function.h"
#include "usart.h"

u8 irflag;
u8 readflg;
u32 hw_jsm=0x00de21ee;	  //定义一个32位数据变量，保存接收码
u8  hw_jsbz;  //定义一个8位数据的变量，用于指示接收标志
u8 data_u8[4];

u8 Lead_Low_Flag=8;
u8 Lead_High_Flag=8;

/*******************************************************************************
* 函 数 名         : Hwjs_Init
* 函数功能		   : 红外端口初始化函数	  时钟端口及外部中断初始化 
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Hwjs_InitA15()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* 开启GPIO时钟及管脚复用时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;//红外接收
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource15); //选择GPIO管脚用作外部中断线路
	EXTI_ClearITPendingBit(EXTI_Line15);
	
	/* 设置外部中断的模式 */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

	/* 设置NVIC参数 */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;   //打开全局中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 	 //响应优先级为1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //使能
	NVIC_Init(&NVIC_InitStructure);
}

void Hwjs_InitC13()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* 开启GPIO时钟及管脚复用时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;//红外接收
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13); //选择GPIO管脚用作外部中断线路
	EXTI_ClearITPendingBit(GPIO_Pin_13);
	
	/* 设置外部中断的模式 */ 
	EXTI_InitStructure.EXTI_Line=GPIO_Pin_13;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

}

void Hwjs_InitA12()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* 开启GPIO时钟及管脚复用时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;//红外接收
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource12); //选择GPIO管脚用作外部中断线路
	EXTI_ClearITPendingBit(GPIO_Pin_12);
	
	/* 设置外部中断的模式 */ 
	EXTI_InitStructure.EXTI_Line=GPIO_Pin_12;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

}

void Hwjs_InitB9()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* 开启GPIO时钟及管脚复用时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//红外接收
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource9); //选择GPIO管脚用作外部中断线路
	EXTI_ClearITPendingBit(GPIO_Pin_9);
	
	/* 设置外部中断的模式 */ 
	EXTI_InitStructure.EXTI_Line=GPIO_Pin_9;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

}
void Hwjs_InitA11()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* 开启GPIO时钟及管脚复用时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//红外接收
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11); //选择GPIO管脚用作外部中断线路
	EXTI_ClearITPendingBit(GPIO_Pin_11);
	
	/* 设置外部中断的模式 */ 
	EXTI_InitStructure.EXTI_Line=GPIO_Pin_11;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

}

/*******************************************************************************
* 函 数 名         : HW_jssj
* 函数功能		   : 高电平持续时间，将记录的时间保存在t中返回，其中一次大约20us 
* 输    入         : 无
* 输    出         : t
*******************************************************************************/
void Hwjs_InitA8()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* 开启GPIO时钟及管脚复用时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;//红外接收
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8); //选择GPIO管脚用作外部中断线路
	EXTI_ClearITPendingBit(EXTI_Line8);
	
	/* 设置外部中断的模式 */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

	/* 设置NVIC参数 */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;   //打开全局中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 	 //响应优先级为1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //使能
	NVIC_Init(&NVIC_InitStructure);
}




u8 HW_jssj(GPIO_TypeDef *GPIO,uint16_t GPIO_Pin )
{
	u8 t=0;
	while(GPIO_ReadInputDataBit(GPIO,GPIO_Pin)==1)//高电平
	{
		t++;
		delay_us(20);
		if(t>=250) return t;//超时溢出
	}
	return t;
}


void	Lead_Low_Time( )
{	
	u8 i,io_input,k=0;
	u16 irCOUN[6]={3};
	u8 ir_instead[6]={3};
	u8 t=0,j;


TIM_SetCounter(TIM4,0);
while(PAin(8)==0||PAin(11)==0||PBin(9)==0||PAin(12)==0||PCin(13)==0||PAin(15)==0)
{
	
	for(i=0;i<6;i++)
	{
		switch(i){
			case 0:io_input=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8);break;
			case 1:io_input=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9);break;		
			case 2:io_input=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);break;
			case 3:io_input=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12);break;
			case 4:io_input=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);break;		
			case 5:io_input=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15);break;			
		}
	
	if(io_input==0)
	{
	irCOUN[i]=TIM_GetCounter(TIM4);

		if((irCOUN[i]>1700) && (irCOUN[i]<1900))			//判断低电平脉宽是否在8.5ms-9.5ms之间
			{
				
				Lead_Low_Flag=1;
				Lead_High_Flag=i;

				break;
//				switch (i)//lilun xuyao jiashang danshi xiaoguo buhao
//				{
//					case 0:	while(PAin(8)==0);break;
//					case 1:	while(PBin(9)==0);break;		
//					case 2:	while(PAin(11)==0);break;
//					case 3:	while(PAin(12)==0);break;
//					case 4:	while(PCin(13)==0);break;		
//					case 5:	while(PAin(15)==0);break;		
//				}	
//								
			}
			
				
	
	}
}
}
}


void EXIT_15(u8 Lead_High_Flag)
{
	u32 exit[6];u32 exit_io[6];GPIO_TypeDef* exit_AB[6];
	
	
	switch(Lead_High_Flag){
case 0: exit[0]=EXTI_Line8;exit_io[0]=GPIO_Pin_8;exit_AB[0]=GPIOA;break;
case 1: exit[1]=EXTI_Line9;exit_io[1]=GPIO_Pin_9;exit_AB[1]=GPIOB;break;
case 2: exit[2]=EXTI_Line11;exit_io[2]=GPIO_Pin_11;exit_AB[2]=GPIOA;break;
case 3: exit[3]=EXTI_Line12;exit_io[3]=GPIO_Pin_12;exit_AB[3]=GPIOA;break;
case 4: exit[4]=EXTI_Line13;exit_io[4]=GPIO_Pin_13;exit_AB[4]=GPIOC;break;
case 5: exit[5]=EXTI_Line15;exit_io[5]=GPIO_Pin_15;exit_AB[5]=GPIOA;break;		
	}
	
		u8 Tim=0,Ok=0,Data,Num=0;
		while(EXTI_GetITStatus(exit[Lead_High_Flag]) != RESET)
		{
			
		 if(GPIO_ReadInputDataBit(exit_AB[Lead_High_Flag],exit_io[Lead_High_Flag])==1)
		{  


			 Tim=HW_jssj(exit_AB[Lead_High_Flag],exit_io[Lead_High_Flag]);//获得此次高电平时间
			 if(Tim>=250) break;//不是有用的信号

			 if((Tim>=200 && Tim<250))
			 {
			 	Ok=1;//收到起始信号
	
				
			 }
			 else if(Tim>=60 && Tim<95)		//60~90   73~95
			 {
			 	Data=1;//收到数据 1
			 }
			 else if(Tim>=10 && Tim<39)  //10~50  17~39
			 {
			 	Data=0;//收到数据 0
			 }
			 else break;

			 if(Ok==1)
			 {
			 	hw_jsm<<=1;
				hw_jsm+=Data;

				if(Num>=32)
				{
					hw_jsbz=1;
				  	break;
				}
			 }

			 Num++;
		
		}	
   }
}



void EXTI15_10_IRQHandler(void)	  //红外遥控外部中断
{


	Lead_Low_Time( );
	if(Lead_Low_Flag==1){
		 irflag=Lead_High_Flag;
	EXIT_15( Lead_High_Flag);}

	
   EXTI_ClearITPendingBit(EXTI_Line15);		
	 EXTI_ClearITPendingBit(EXTI_Line13);
	 EXTI_ClearITPendingBit(EXTI_Line12);	
	 EXTI_ClearITPendingBit(EXTI_Line11);

}




void EXTI9_5_IRQHandler(void)	  //红外遥控外部中断
{
		Lead_Low_Time( );
	if(Lead_Low_Flag==1){
		Lead_Low_Flag=0;
	EXIT_15( Lead_High_Flag);}
	 
   EXTI_ClearITPendingBit(EXTI_Line8);	
   EXTI_ClearITPendingBit(EXTI_Line9);	
}





































