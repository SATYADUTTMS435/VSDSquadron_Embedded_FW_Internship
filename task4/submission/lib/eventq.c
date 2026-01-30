#include "eventq.h"

#define HIGH_Q_SIZE 8
#define LOW_Q_SIZE  8

static event_t high_q[HIGH_Q_SIZE];
static event_t low_q[LOW_Q_SIZE];

static uint8_t high_cnt = 0;
static uint8_t low_cnt  = 0;

void eventq_init(void)
{
    high_cnt = 0;
    low_cnt  = 0;
}

bool event_push_high(event_t e)
{
    if (high_cnt >= HIGH_Q_SIZE)
        return false;

    high_q[high_cnt++] = e;
    return true;
}

bool event_push_low(event_t e)
{
    if (low_cnt >= LOW_Q_SIZE)
        return false;

    low_q[low_cnt++] = e;
    return true;
}

bool event_get_next(event_t *e)
{
    if (high_cnt > 0) {
        *e = high_q[0];
        for (int i = 1; i < high_cnt; i++)
            high_q[i - 1] = high_q[i];
        high_cnt--;
        return true;
    }

    if (low_cnt > 0) {
        *e = low_q[0];
        for (int i = 1; i < low_cnt; i++)
            low_q[i - 1] = low_q[i];
        low_cnt--;
        return true;
    }

    return false;
}
