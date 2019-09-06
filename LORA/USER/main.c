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

 //主函数
 int main(void)
 { 
  NVIC_Configuration();	 
	delay_init();	    	         //延时函数初始化	  
	uart_init(115200);	 	         //串口初始化为9600	
  //usmart_dev.init(72);		     //初始化USMART		 
	LED_Init();         	         //LED初始化	 
	KEY_Init();				         //按键初始化	 
  RELAY_Init();
 	mem_init();				         //初始化内存池	    
 	exfuns_init();			         //为fatfs相关变量申请内存  
  //f_mount(fs[0],"0:",1); 	         //挂载SD卡 
 	//f_mount(fs[1],"1:",1); 	         //挂载FLASH. 

	Lora_Test();//主测试
}

