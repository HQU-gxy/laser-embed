#include "hwjs.h"
#include "SysTick.h"
#include "function.h"
#include "usart.h"

u8 irflag;
u8 readflg;
u32 hw_jsm=0x00de21ee;	  //����һ��32λ���ݱ��������������
u8  hw_jsbz;  //����һ��8λ���ݵı���������ָʾ���ձ�־
u8 data_u8[4];

u8 Lead_Low_Flag=8;
u8 Lead_High_Flag=8;

/*******************************************************************************
* �� �� ��         : Hwjs_Init
* ��������		   : ����˿ڳ�ʼ������	  ʱ�Ӷ˿ڼ��ⲿ�жϳ�ʼ�� 
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void Hwjs_InitA15()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource15); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(EXTI_Line15);
	
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

	/* ����NVIC���� */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;   //��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 	 //��Ӧ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //ʹ��
	NVIC_Init(&NVIC_InitStructure);
}

void Hwjs_InitC13()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(GPIO_Pin_13);
	
	/* �����ⲿ�жϵ�ģʽ */ 
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

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource12); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(GPIO_Pin_12);
	
	/* �����ⲿ�жϵ�ģʽ */ 
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

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource9); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(GPIO_Pin_9);
	
	/* �����ⲿ�жϵ�ģʽ */ 
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

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(GPIO_Pin_11);
	
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=GPIO_Pin_11;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

}

/*******************************************************************************
* �� �� ��         : HW_jssj
* ��������		   : �ߵ�ƽ����ʱ�䣬����¼��ʱ�䱣����t�з��أ�����һ�δ�Լ20us 
* ��    ��         : ��
* ��    ��         : t
*******************************************************************************/
void Hwjs_InitA8()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(EXTI_Line8);
	
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

	/* ����NVIC���� */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;   //��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 	 //��Ӧ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //ʹ��
	NVIC_Init(&NVIC_InitStructure);
}




u8 HW_jssj(GPIO_TypeDef *GPIO,uint16_t GPIO_Pin )
{
	u8 t=0;
	while(GPIO_ReadInputDataBit(GPIO,GPIO_Pin)==1)//�ߵ�ƽ
	{
		t++;
		delay_us(20);
		if(t>=250) return t;//��ʱ���
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

		if((irCOUN[i]>1700) && (irCOUN[i]<1900))			//�жϵ͵�ƽ�����Ƿ���8.5ms-9.5ms֮��
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


			 Tim=HW_jssj(exit_AB[Lead_High_Flag],exit_io[Lead_High_Flag]);//��ô˴θߵ�ƽʱ��
			 if(Tim>=250) break;//�������õ��ź�

			 if((Tim>=200 && Tim<250))
			 {
			 	Ok=1;//�յ���ʼ�ź�
	
				
			 }
			 else if(Tim>=60 && Tim<95)		//60~90   73~95
			 {
			 	Data=1;//�յ����� 1
			 }
			 else if(Tim>=10 && Tim<39)  //10~50  17~39
			 {
			 	Data=0;//�յ����� 0
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



void EXTI15_10_IRQHandler(void)	  //����ң���ⲿ�ж�
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




void EXTI9_5_IRQHandler(void)	  //����ң���ⲿ�ж�
{
		Lead_Low_Time( );
	if(Lead_Low_Flag==1){
		Lead_Low_Flag=0;
	EXIT_15( Lead_High_Flag);}
	 
   EXTI_ClearITPendingBit(EXTI_Line8);	
   EXTI_ClearITPendingBit(EXTI_Line9);	
}





































