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
	
  USART_InitConfig();	 //����1��ʼ�������ڴ�ӡ�ӿ�
  SysTick_init(72);		 //SysTickʱ�ӳ�ʼ��
  I2C_GPIOInitConfig();  //I2C��ʼ��
  TIM2_InitConfig();     //��ʱ��2��ʼ��
  LED_Init();
  InitRc522();           //RFID_RC522ģ���ʼ������Ƶ��������
  SG90_Init();
  Key_InitConfig();
  
  //Bluetooth_Init();
  
  //USART2_InitConfig();	

  eeprom_rdwr_rfid();    //������eeprom�ж����������Ƶ��id
  
  
  printf("LED_Init\r\n");		
  
 
	
  while (1)
  {
  
  	Read_cardID();
	//Key_Scan(Get_KeyType());
  }
  
}
