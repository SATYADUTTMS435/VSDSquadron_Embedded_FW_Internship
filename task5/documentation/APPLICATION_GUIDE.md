# Application Guide  
Event Queue Based Embedded Application – VSDSquadron Mini

This document explains **how the application works**, focusing on **application logic**, not driver internals.

---

## Application Overview

The application demonstrates an **event-driven embedded system** using:
- UART for logging
- GPIO for LED control
- An event queue to decouple producers and consumers

The system mimics **basic OS-like behavior** using:
- Asynchronous event generation
- Deferred event handling
- Separation between event producers and dispatcher

---

## Application Components

### 1. Event Producers
Event producers generate events independently of when they are handled.

#### Timer-Based Producer
- Periodically generates `EVENT_TIMER_TICK`
- Represents a system timer or heartbeat

```c
if (tick % 2 == 0) {
    event_t evt = { EVENT_TIMER_TICK, 0 };
    event_push_low(evt);
}
```

#### LED Request Producer
- Generates `EVENT_LED_STEP` at a different rate
- Represents a request for hardware action

```c
if (tick % 3 == 0) {
    event_t evt = { EVENT_LED_STEP, 0 };
    event_push_high(evt);
}
```

---

## Event Dispatcher (Consumer)

The dispatcher is responsible for **handling queued events**.

- Runs slower than producers
- Fetches one event at a time
- Executes actions based on event type

```c
if (event_get_next(&event)) {
    if (event.type == EVENT_LED_STEP) {
        gpio_toggle(LED_PIN);
    }
}
```

This intentional delay allows:
- Multiple events to queue up
- Observable separation between **event generation** and **event handling**

---

## Application Timing Behavior

| Component | Timing |
|---------|--------|
| Event generation | Every loop iteration |
| Dispatcher execution | Every 5 ticks |
| Base delay | ~300 ms |

This creates a visible pattern:
```
QUEUED
QUEUED
HANDLED
QUEUED
HANDLED
HANDLED
```

---

## UART Logging Behavior

UART logs provide real-time visibility into system behavior:

### Example Output
```
EVENT QUEUE STARTED
QUEUED: TIMER_TICK
QUEUED: LED_STEP
QUEUED: TIMER_TICK
HANDLED: LED_STEP
ACTION: LED TOGGLED
HANDLED: TIMER_TICK
```

This confirms:
- Events are queued independently
- Handling order is decoupled from generation order

---

## LED Control Logic

- LED is connected to `PD5`
- LED toggles **only** when `EVENT_LED_STEP` is handled
- No direct GPIO access outside dispatcher

This enforces:
- Centralized hardware control
- Deterministic behavior

---

## Edge Cases Considered

- Empty event queue → dispatcher does nothing
- Multiple queued events → handled one per dispatcher cycle
- No blocking calls inside event handlers

---

## OS-Like Behavior Demonstrated

This application mimics core OS concepts:

| OS Concept | Implemented As |
|----------|---------------|
| Task separation | Producers vs Dispatcher |
| Scheduling | Time-sliced dispatcher |
| Deferred execution | Event queue |
| Interrupt abstraction | Event producers |

---

## Limitations

- No preemption
- No true priority scheduling
- Single-threaded execution

These limitations are intentional to keep the design simple and educational.

---

## Expansion Possibilities

- Add priority queues
- Replace delay with hardware timer interrupts
- Convert event dispatcher into FSM
- Reimplement event queue in Verilog
- Extend into cooperative scheduler or RTOS

---

End of Application Guide

