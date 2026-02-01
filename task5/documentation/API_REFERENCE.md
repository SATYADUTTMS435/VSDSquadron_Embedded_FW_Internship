# API Reference  
Event Queue Based Embedded Application – VSDSquadron Mini

This document describes the **public driver APIs** used in the Task-4 project.  
All APIs are designed to be **simple, reusable, and hardware-agnostic** from the application layer.

---

## GPIO Driver API

### gpio_init

```c
void gpio_init(uint8_t pin, uint8_t mode);
```

**Description**  
Initializes a GPIO pin as input or output.

**Parameters**
- `pin` – GPIO pin number (board-specific mapping)
- `mode` – `GPIO_OUTPUT` or `GPIO_INPUT`

**Return Value**  
None

**Notes**
- Internally configures GPIO registers
- Application code never accesses registers directly

**Example**
```c
gpio_init(5, GPIO_OUTPUT);
```

---

### gpio_toggle

```c
void gpio_toggle(uint8_t pin);
```

**Description**  
Toggles the state of a GPIO output pin.

**Parameters**
- `pin` – GPIO pin number

**Return Value**  
None

**Example**
```c
gpio_toggle(5);
```

---

## UART Driver API

### uart_init

```c
void uart_init(void);
```

**Description**  
Initializes UART for debug communication using WCH-Link.

**Configuration**
- Baud Rate: 115200
- Data Bits: 8
- Stop Bits: 1
- Parity: None

**Return Value**  
None

**Example**
```c
uart_init();
```

---

### uart_print

```c
void uart_print(const char *msg);
```

**Description**  
Prints a null-terminated string over UART.

**Parameters**
- `msg` – Pointer to string

**Return Value**  
None

**Example**
```c
uart_print("EVENT QUEUE STARTED\r\n");
```

---

## Event Queue API

### eventq_init

```c
void eventq_init(void);
```

**Description**  
Initializes the event queue data structure.

**Return Value**  
None

**Notes**
- Must be called before pushing or fetching events

---

### event_push_high

```c
void event_push_high(event_t event);
```

**Description**  
Pushes a high-priority event into the event queue.

**Parameters**
- `event` – Event structure containing type and data

**Return Value**  
None

**Example**
```c
event_t evt = { EVENT_LED_STEP, 0 };
event_push_high(evt);
```

---

### event_push_low

```c
void event_push_low(event_t event);
```

**Description**  
Pushes a low-priority event into the event queue.

**Parameters**
- `event` – Event structure

**Return Value**  
None

---

### event_get_next

```c
int event_get_next(event_t *event);
```

**Description**  
Fetches the next available event from the queue.

**Parameters**
- `event` – Pointer to event structure to be filled

**Return Value**
- `1` – Event fetched successfully
- `0` – No event available

**Example**
```c
event_t event;
if (event_get_next(&event)) {
    // handle event
}
```

---

## Event Types

```c
typedef enum {
    EVENT_TIMER_TICK,
    EVENT_LED_STEP
} event_type_t;
```

| Event | Description |
|-----|------------|
| EVENT_TIMER_TICK | Periodic timer-generated event |
| EVENT_LED_STEP | Requests LED toggle action |

---

## Design Notes

- APIs are **non-blocking**
- Drivers are **decoupled from application logic**
- Event queue enables **scalable system expansion**
- Suitable for conversion into FSM / Verilog modules

---

End of API Reference

