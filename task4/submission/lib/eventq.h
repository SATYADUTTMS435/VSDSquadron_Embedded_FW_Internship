#ifndef EVENTQ_H
#define EVENTQ_H

#include <stdint.h>
#include <stdbool.h>

/* Event types */
typedef enum {
    EVENT_TIMER_TICK = 0,
    EVENT_LED_STEP   = 1
} event_type_t;

/* Event structure */
typedef struct {
    event_type_t type;
    uint8_t data;
} event_t;

/* APIs */
void eventq_init(void);
bool event_push_high(event_t e);
bool event_push_low(event_t e);
bool event_get_next(event_t *e);

#endif
