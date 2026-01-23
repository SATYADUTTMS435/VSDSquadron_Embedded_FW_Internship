#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum{
    GPIO_INPUT = 0,
    GPIO_OUTPUT
} gpio_direction_t;

void gpio_init(uint8_t pin, gpio_direction_t);
void gpio_set(uint8_t pin);
void gpio_clear(uint8_t pin);
uint8_t gpio_read(uint8_t pin);
void gpio_toggle(uint8_t pin);

#endif