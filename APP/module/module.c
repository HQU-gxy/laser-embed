#include "function.h"
#include "string.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "stm32f10x.h"
#include "SysTick.h"
#include "usart.h"
#include "module.h"
#include "hwjs.h"
#include "nrf24l01.h"
#include "spi.h"
#include "gps.h"
#include "time.h"
u8 netflag=1;
u8 netflag1=1;
u8 netflag2=1;
u8 netflag3=1;
char string[]="";
char *dest_string="";
char *dest_string1="";
char*p;
char*NetMessage;
u8 i,s;
int fport,bytes_length;
u8 lorasendflag=8;	
u8 data=0;
u8  y=0;
u8 port=0;
u16 USART1_RX_STA=0;       //接收状态标记	
u8 USART1_RX_BUF[USART1_REC_LEN]; 
u8 test=2;
u8 count=0;
u8 count1=0;
u8 beat_count=0;
u8 INITFLAG=1;
uint32_t jk=0;

u8 Res;
		u8 netdata[]={11,61,97,78,78,0x00,0x7b,62};
char *delim=",";
char dest[10] = {""};
char dest1[10] = {""};	
uint8_t converted[8];
u8 rx_buf[33]={0};
u16 color=0;

char str[20]="";
char str1[20]="";
char str2[20]="";
char str3[20]="";
char str0[20]="";
char str4[100]="";
char str5[100]="";
u8 a[40]={0};

 char *merged;
 char joinCmd [] = "at+join\r\n";
 char testCmd [] = "at+send=lora:1:5A00\r\n";
char joinmode []="at+set_config=lora:confirm:1\r\n";
char joinfrequent []="at+set_config=lora:region:CN470\r\n";
char position []	= "at+send=lora:1:008000002e3e04d109980dd1007b8a\r\n";
char position1 []	= "at+send=lora:1:008000002e58119309bd1964007b8a\r\n";
char FeedbackOrder[]="OK Join Success\r\n";
char FeedbackOrder1[]="OK \r\n";
char FeedbackOrder2[]=",\r\n";
const int bufferSize1=15;
const int bufferSize2=6;
	unsigned char buffer1[]={0x00,0x80,0x00,0x00,0x43,0x53,0x12,0xF6,0x10,0xEC,0x1B,0x0E,0x00,0x7b,0x8A};//
	unsigned char buffer2[]={0x40,0x01,0xc8,0x00,0x7b,0x5b};//3 and 4 no change

void Jion_Net(){
//join the net initial
//initial
delay_ms(1500);
delay_ms(1500);

delay_ms(1000);

USART_ClearFlag(USART1,USART_FLAG_TC); 
USART1_printf("%s",joinCmd);
while(netflag==1){



if(USART1_FINISH){
//		ret=strstr(string ,FeedbackOrder);
//		USART1_printf("%d",strncmp(string ,FeedbackOrder,2));
if(strncmp(string ,FeedbackOrder,2)==0)
{							

netflag=0;

for(jk=0;jk<jkl;jk++)
{
string[jk]=0x00;
}
jkl = 0;

}else{
delay_ms(1500);
delay_ms(1000);
delay_ms(1500);

USART1_printf("%s",joinCmd);
delay_ms(1000);
for(jk=0;jk<jkl;jk++)
{
string[jk]=0x00;
}
jkl = 0;
}
USART1_FINISH = 0;
}

}

delay_ms(1000);
delay_ms(1500);
delay_ms(1000);

USART1_printf("%s",position);
while(netflag1==1){

//USART1_printf("%jaksjd");

if(USART1_FINISH){
//		ret=strstr(string ,FeedbackOrder);
//		USART1_printf("%d",strncmp(string ,FeedbackOrder1,4));
if(strncmp(string ,FeedbackOrder1,2)==0)
{							

netflag1=0;
for(jk=0;jk<jkl;jk++)
{
string[jk]=0x00;
}
jkl = 0;
}else{
delay_ms(1500);
delay_ms(1000);
delay_ms(1500);
delay_ms(1000);
USART1_printf("%s",position);

for(jk=0;jk<jkl;jk++)
{
string[jk]=0x00;
}
jkl = 0;
}	
USART1_FINISH = 0;
}
}


}




void Usart_Receive(){
//lora recevive
if(USART1_FINISH)
{
//USART2_printf("111 : %s\r\n",string);

if(strstr(string,":"))
{
	lorasendflag=1;
dest_string = strstr(string,":");
strncpy(dest, dest_string+1, 6);
//USART1_printf("333 : %s\r\n",dest);
bytes_length=strlen(dest) / 2;
strHexToUint8Array(dest,converted,bytes_length);
//USART1_printf("converted:%d\r\n",converted[0]);
}
if(strstr(string,"at"))
{
dest_string1 = strstr(string,"=");
p=strtok(dest_string1, delim);
//	printf("string : %s\r\n",p);
strncpy(dest1, p+1, 16);
fport=atoi(dest1);
//USART1_printf("fport:%d\r\n",fport);
//printf("222 : %s\r\n",dest1);
}




for(jk=0;jk<jkl;jk++)
{
string[jk]=0x00;
}

jkl = 0;
USART1_FINISH = 0;
}
}

void IR_Poll(){
//irRemote receive	
if(hw_jsbz==1)	//如果红外接收到
{
hw_jsbz=0;	   //清零


data_u8[0] = (hw_jsm >> 24) & 0xff;	 
data_u8[1] = (hw_jsm >> 16) & 0xff; 	   
data_u8[2] = (hw_jsm >> 8)  & 0xff;
data_u8[3] =  hw_jsm       & 0xff;
hw_jsm=0;					//接收码清零
data_u8[0]= reverse_bit8(data_u8[0]);
data_u8[1]= reverse_bit8(data_u8[1]);
data_u8[2]= reverse_bit8(data_u8[2]);
data_u8[3]= reverse_bit8(data_u8[3]);

buffer2[1]=data_u8[0];//0x01
buffer2[2]=data_u8[1];//0xc8
	
//buffer2[3]=data_u8[2];//00
//buffer2[4]=data_u8[3];//123
	
	
	switch(irflag){
	case 5:
			buffer2[0]=0x80;
			buffer1[2]++;
			break;
	case 0:
			buffer2[0]=0x08;
			buffer1[2]++;
			break;
	case 4:
			buffer2[0]=0x10;
			buffer1[2]++;
			break;
	case 3:
			buffer2[0]=0x20;
			buffer1[2]++;
			break;
	case 2:
			buffer2[0]=0x04;
			buffer1[2]++;
			break;
	case 1:
			buffer2[0]=0x40;
			buffer1[2]++;
			break;


}	


merged=newMergedData(buffer2,bufferSize2);
USART1_printf("%s",merged);
//beat_count++;
////TIM4_Init(20000,36000-1);  //定时10s
//while(beat_count!=0){

//	
//if(USART1_FINISH){

////		ret=strstr(string ,FeedbackOrder);
////		USART1_printf("%d",strncmp(string ,FeedbackOrder1,4));
////if((string [0]==0x61)||(string [1]==0x4b))
//	delay_ms(200);
//if(strncmp(string ,FeedbackOrder1,4)==0)	
//{							

//beat_count--;
//TIM4_Init(10000,36000-1);  //定时10ss
//for(jk=0;jk<jkl;jk++)
//{
//string[jk]=0x00;
//}
//jkl = 0;
//if(beat_count!=0){
//	netflag2=2;}
//}else{
////delay_ms(1500);
////delay_ms(800);




//for(jk=0;jk<jkl;jk++)
//{
//string[jk]=0x00;
//}
//jkl = 0;
//USART1_printf("%s\n",merged);

//}	
//USART1_FINISH = 0;
//}

//if(netflag2==1||netflag2==2){
//TIM4_Init(10000,36000-1);  //定时10ss
//	netflag2=0;
//}

//}

free(merged);


}	

}

void Gps_RecToSend()
{
// send gps message 
if(gpssendflag==1){
gpssendflag=0;
	
//longtidu
buffer1[4] = gpsposition[6];
buffer1[5] = gpsposition[7];
buffer1[6] = gpsposition[4];
buffer1[7] = gpsposition[5];

//latitude
buffer1[8] = gpsposition[2];
buffer1[9] = gpsposition[3];
buffer1[10] = gpsposition[0];
buffer1[11] = gpsposition[1];

merged=newMergedData(buffer1,bufferSize1);
USART1_printf("%s",merged);
free(merged);
}
}

void Nrf_RecToSend(){
//nrf24l01  receive

if(NRF24L01_RxPacket(rx_buf)==0) //接收到数据显示
{
	if(rx_buf[0]==22&&rx_buf[5]==0x00&&rx_buf[6]==0x7b)
{
//head nrf send message	
rx_buf[32]=0;
buffer1[1]=rx_buf [1];
buffer1[2]++;
//position		
buffer2[0]=0x01;
//gun people id		
buffer2[1]=rx_buf[3];
buffer2[2]=rx_buf[4];			
//unsigned char buffer2[]={0x40,0x01,0xc8,0x00,0x7b,0x5b};//3 and 4 no change
merged=newMergedData(buffer2,bufferSize2);
USART1_printf("%s",merged);
//USART2_printf("222%d\r\n",buffer2[2]);
free(merged);
}

//gun nrf send message
if(rx_buf[0]==11&&rx_buf[5]==0x00&&rx_buf[6]==0x7b)
{
buffer1[1]=rx_buf [1];// gun egg number
buffer1[2]++;
//	USART1_printf("333%d\r\n",buffer1[1]);
}
}	
}

void Nrf_Send(){

// send message from nrf2401
if(lorasendflag==1){

//22 means send to head;
//11 means send to gun;
//78 means people number
	lorasendflag=0;
NRF24L01_TX_Mode();
netdata[1]=fport;
netdata[2]=	converted[0];
//USART3_printf("%d",lorasendflag);
//send to gun 
if(fport==3)
{netdata[0]=22;
NRF24L01_TxPacket( netdata );	
}

//send to gun 
if(fport==5)
{netdata[0]=11;
NRF24L01_TxPacket( netdata );	
}
NRF24L01_RX_Mode();	


}



}

void GPS_LogIn()
{

parseGpsBuffer();
printGpsBuffer();
}





