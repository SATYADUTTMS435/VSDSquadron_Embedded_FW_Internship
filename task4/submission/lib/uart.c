#include "uart.h"
#include <debug.h>
#include <stdio.h>

void uart_init(void)
{
    /* WCH-Link debug UART */
    USART_Printf_Init(115200);
}

void uart_print(const char *msg)
{
    printf("%s", msg);
}
