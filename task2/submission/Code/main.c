#include <ch32v00x.h>
#include <debug.h>

#include "uart.h"
#include "gpio.h"

/*
 * Task-2 Combined Application
 * UART and GPIO were validated on hardware in separate runs.
 * This main.c shows the logical integration using API layers.
 */

int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();

    /* Initialize peripherals via API layers */
    uart_init();
    gpio_init();

    /* UART startup messages */
    uart_print("VSDSquadron Mini");
    uart_print("FW Version: 1.0");
    uart_print("Boot successful");

    while (1)
    {
        /* Periodic UART output */
        uart_print_counter();

        /* GPIO toggle (LED blink) */
        gpio_toggle();

        Delay_Ms(1000);
    }
}
