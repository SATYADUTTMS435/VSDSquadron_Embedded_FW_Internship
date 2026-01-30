#include "gpio.h"
#include <ch32v00x.h>

void gpio_init(uint8_t pin, uint8_t mode)
{
    GPIO_InitTypeDef gpio = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    gpio.GPIO_Pin = (1U << pin);
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOD, &gpio);
}

void gpio_toggle(uint8_t pin)
{
    GPIOD->OUTDR ^= (1U << pin);
}
