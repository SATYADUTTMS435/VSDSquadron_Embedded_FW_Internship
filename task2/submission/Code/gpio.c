#include <ch32v00x.h>
#include "gpio.h"

#define LED_PORT GPIOD
#define LED_PIN  GPIO_Pin_6   // On-board blue LED (PD6)

void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = LED_PIN;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &gpio);
}

void gpio_toggle(void)
{
    GPIO_WriteBit(
        LED_PORT,
        LED_PIN,
        !GPIO_ReadOutputDataBit(LED_PORT, LED_PIN)
    );
}
