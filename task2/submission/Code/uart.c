#include "uart.h"
#include <debug.h>
#include <stdio.h>

static int counter = 0;

void uart_init(void)
{
    /* Initialize debug UART via WCH-Link (COM3) */
    USART_Printf_Init(115200);
}

void uart_print(const char *msg)
{
    printf("%s\r\n", msg);
}

void uart_print_counter(void)
{
    counter++;
    printf("Count: %d\r\n", counter);
}
