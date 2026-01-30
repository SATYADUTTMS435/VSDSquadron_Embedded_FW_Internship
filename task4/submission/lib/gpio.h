#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO_OUTPUT 1

void gpio_init(uint8_t pin, uint8_t mode);
void gpio_toggle(uint8_t pin);

#endif
