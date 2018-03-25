#include "stm32f10x.h"
#include "led_driver.h"
#include "usart_driver.h"
#include "rtl8710_driver.h"
#include "rc522_add.h"
#include "rc522.h"
#include "eeprom.h"
#include "i2c_driver.h"
#include "systick.h"
#include "timer.h"
#include "sg90_driver.h"
#include "key_driver.h"
#include "bluetooth_driver.h"

int main(void)
{
	
  USART_InitConfig();	 //串口1初始化，串口打印接口
  SysTick_init(72);		 //SysTick时钟初始化
  I2C_GPIOInitConfig();  //I2C初始化
  TIM2_InitConfig();     //定时器2初始化
  LED_Init();
  InitRc522();           //RFID_RC522模块初始化，射频卡读卡器
  SG90_Init();
  Key_InitConfig();
  
  //Bluetooth_Init();
  
  //USART2_InitConfig();	

  eeprom_rdwr_rfid();    //开机从eeprom中读出记忆的射频卡id
  
  
  printf("LED_Init\r\n");		
  
 
	
  while (1)
  {
  
  	Read_cardID();
	//Key_Scan(Get_KeyType());
  }
  
}
