#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "picture.h"
#include "hwjs.h"
#include "string.h"
#include "hexify.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "stm32f10x.h"
#include "nrf24l01.h"
#include "spi.h"
#include "gps.h"
#include "module.h"
#include "function.h"
#include "time.h"


unsigned char gpstest33[]={0xb5, 0x62, 0x06, 0x00, 0x14, 0x00, 0x01, 0x00, 0x00 ,0x00 ,0xd0, 0x08, 0x00 ,0x00 ,0x00, 0xc2 ,0x01 ,0x00 ,0x01 , 0x00, 0x02 ,0x00, 0x00  ,0x00  ,0x00  ,0x00  ,0xb9 ,0x48};//115200


int main()
{

//initial
SysTick_Init(72);
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
USART1_Init(115200);
USART3_Init(115200);
Hwjs_InitA15();
Hwjs_InitC13();
Hwjs_InitB9( );
Hwjs_InitA8( );
Hwjs_InitA12();
Hwjs_InitA11();


NRF24L01_Init();
NRF24L01_RX_Mode();	
delay_ms(1000);
	
Jion_Net();	
	
//ublox gps
USART2_Init(9600);	
	delay_us(50);
	clrStruct();
		delay_us(50);
	UART_PutBytes(USART2 ,gpstest33,sizeof(gpstest33));

		delay_us(50);
UART_PutBytes(USART2 ,gpstest33,sizeof(gpstest33));
		delay_us(50);
USART2_Init(115200);
		delay_us(50);
ublox_gpsinit();

//delay_ms(1000);
//USART1_printf("at+set_config=lora:confirm:1\r\n");
//delay_us(50);
//USART1_printf("at+set_config=lora:confirm:1\r\n");
	

//taidou gps
//delay_us(50);
//USART2_Init(9600);
	//clrStruct();
//USART2_printf("$CCCAS,1,5*55\r\n");
//delay_us(50);
//USART2_printf("$CCCAS,1,5*55\r\n");
//delay_us(50);
//USART2_Init(115200);	 //串口初始化为9600
//delay_us(50);

delay_us(50);

//USART2_printf("%d\r\n",	NRF24L01_Check());
//USART2_printf("%d\r\n",	NRF24L01_Check());


	TIM4_Init(10000,360-1);  //定时50ms
//Lora jion the net


delay_ms(1000);
//gpsinit ();


while(1)
{


//net send message to Soldier	
Usart_Receive();
//	
////send GPS message	
Gps_RecToSend();	

////check Nrf24l01 receive message	
Nrf_RecToSend();

//////Nrf24l01 send message when receivr Net message	
 Nrf_Send();

////check soldier IR headr
IR_Poll();	
//		
////check GPS message weather useful	
parseGpsBuffer();
printGpsBuffer();


}
}





