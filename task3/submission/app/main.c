#include "gpio.h"
#include <ch32v00x.h>
#include "debug.h"
#include "uart.h"

int main(void){
    SystemCoreClockUpdate();
    Delay_Init();
    uart_init();
    uart_print("System started\n");
    Delay_Ms(1000);
    uart_print("Waiting for (3)s ..\n");
    Delay_Ms(1000);
    uart_print("Waiting for (2)s ..\n");
    Delay_Ms(1000);
    uart_print("Waiting for (1)s ..\n");
    Delay_Ms(1000);
    uart_print("Disco lights starting\n");
  
    uint8_t led_pin1 = 2;
    uint8_t led_pin2 = 4;
    uint8_t led_pin3 = 3;
    uint8_t button_pin = 6;
    gpio_init(led_pin1,GPIO_OUTPUT);
    gpio_init(led_pin2,GPIO_OUTPUT);
    gpio_init(led_pin3,GPIO_OUTPUT);
    gpio_init(button_pin,GPIO_INPUT);
   
   

while (1)
{
    if(gpio_read(button_pin))   // on-board button is ACTIVE LOW
 
    {  
        gpio_toggle(led_pin1);
      
        Delay_Ms(50);
        gpio_toggle(led_pin2);
        
        Delay_Ms(50);
        gpio_toggle(led_pin3);
       

    }
    
  
}
}