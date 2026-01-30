#include <ch32v00x.h>
#include "uart.h"
#include "eventq.h"
#include "gpio.h"

#define LED_PIN 5   // PD5

void delay_ms(uint32_t ms)
{
    volatile uint32_t i;
    while (ms--) {
        i = 80000;
        while (i--);
    }
}

int main(void)
{
    SystemCoreClockUpdate();
    uart_init();
    eventq_init();
    gpio_init(LED_PIN, GPIO_OUTPUT);

    uart_print("EVENT QUEUE STARTED\r\n");

    uint32_t tick = 0;

    while (1)
    {
        tick++;

        /* ---------- PRODUCERS (FAST) ---------- */

        if (tick % 2 == 0) {
            event_t evt = { EVENT_TIMER_TICK, 0 };
            event_push_low(evt);
            uart_print("QUEUED: TIMER_TICK\r\n");
        }

        if (tick % 3 == 0) {
            event_t evt = { EVENT_LED_STEP, 0 };
            event_push_high(evt);
            uart_print("QUEUED: LED_STEP\r\n");
        }

        /* ---------- DISPATCHER (SLOW) ---------- */
        if (tick % 5 == 0) {
            event_t event;
            if (event_get_next(&event)) {

                if (event.type == EVENT_LED_STEP) {
                    uart_print("HANDLED: LED_STEP\r\n");
                    gpio_toggle(LED_PIN);
                    uart_print("ACTION: LED TOGGLED\r\n");
                }
                else if (event.type == EVENT_TIMER_TICK) {
                    uart_print("HANDLED: TIMER_TICK\r\n");
                }
            }
        }

        delay_ms(300);
    }
}
