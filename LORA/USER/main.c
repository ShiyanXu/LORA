#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"
#include "usmart.h" 
#include "malloc.h"  
#include "MMC_SD.h" 
#include "ff.h"  
#include "exfuns.h"
#include "fontupd.h"
#include "text.h"		
#include "touch.h"	
#include "usart2.h"	
#include "lora_app.h"
#include "relay.h"


int distance_now = 100;
int distance_threshold = 10;

 //������
 int main(void)
 { 
  NVIC_Configuration();	 
	delay_init();	    	         //��ʱ������ʼ��	  
	uart_init(115200);	 	         //���ڳ�ʼ��Ϊ9600	
  //usmart_dev.init(72);		     //��ʼ��USMART		 
	LED_Init();         	         //LED��ʼ��	 
	KEY_Init();				         //������ʼ��	 
  RELAY_Init();
 	mem_init();				         //��ʼ���ڴ��	    
 	exfuns_init();			         //Ϊfatfs��ر��������ڴ�  
  //f_mount(fs[0],"0:",1); 	         //����SD�� 
 	//f_mount(fs[1],"1:",1); 	         //����FLASH. 

	Lora_Test();//������
}

