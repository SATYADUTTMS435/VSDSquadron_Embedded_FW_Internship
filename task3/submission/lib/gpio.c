#include "gpio.h"
#include <ch32v00x.h>

/* Fixed GPIO port for Task-3 (can be extended later) */
#define GPIO_PORT        GPIOD
#define GPIO_PIN_MASK(p) (1U << (p))

void gpio_init(uint8_t pin, gpio_direction_t direction)
{
    /* Enable clock for GPIO Port D */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio_init;

    /* Select the pin */
    gpio_init.GPIO_Pin = GPIO_PIN_MASK(pin);

    /* Configure direction */
    if (direction == GPIO_OUTPUT)
    {
        gpio_init.GPIO_Mode  = GPIO_Mode_Out_PP;
        gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    }
    else
    {
        gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    }

    /* Apply configuration */
    GPIO_Init(GPIO_PORT, &gpio_init);
}

void gpio_set(uint8_t pin)
{
    GPIO_SetBits(GPIO_PORT, GPIO_PIN_MASK(pin));
}

void gpio_clear(uint8_t pin)
{
    GPIO_ResetBits(GPIO_PORT, GPIO_PIN_MASK(pin));
}

void gpio_toggle(uint8_t pin)
{
    GPIO_PORT->OUTDR ^= GPIO_PIN_MASK(pin);
}

uint8_t gpio_read(uint8_t pin)
{
    return (GPIO_ReadInputDataBit(GPIO_PORT, GPIO_PIN_MASK(pin)) != 0);
}
