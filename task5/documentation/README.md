# Task-5: Event Queue Based Embedded Application Docs 
VSDSquadron Mini – Multi-Driver Integration Project

---

## Project Overview

This project demonstrates an **event-driven embedded firmware architecture** implemented on the **VSDSquadron Mini (CH32V003 RISC-V)** board.  
The system integrates **GPIO, UART, and a custom Event Queue** to mimic how a simple operating system handles asynchronous events.

Instead of directly performing actions in the main loop, **events are generated, queued, and later dispatched**, similar to how OS schedulers and interrupt handlers work.

This approach improves modularity, scalability, and aligns with real-world embedded firmware design used in industry.

---

## Target Hardware

- **Board:** VSDSquadron Mini  
- **MCU:** CH32V003 (RISC-V, 48 MHz)  
- **On-board LED:** PD5  
- **Debug Interface:** WCH-Link  
- **UART Output:** Debug UART via WCH-Link  

---

## Drivers Used

| Driver | Purpose |
|------|--------|
| GPIO | LED control (toggle output pin) |
| UART | Debug logging and event tracing |
| Event Queue | Decouples event producers and consumers |

---

## UART Configuration

- **Baud Rate:** 115200  
- **Port:** COM3 (via WCH-Link)  
- **Terminal:** PuTTY Serial Monitor  

UART is used to:
- Log when events are queued
- Log when events are handled
- Observe system behavior in real time

---

## Event Types

The system uses the following events:

| Event | Description |
|------|------------|
| EVENT_TIMER_TICK | Periodic timing event |
| EVENT_LED_STEP | LED toggle request |

Events are stored in FIFO queues and processed later by the dispatcher.

---

## Application Logic (How It Works)

1. **Initialization**
   - UART initialized for logging
   - GPIO initialized for LED output
   - Event Queue initialized

2. **Event Producers**
   - Timer logic generates `EVENT_TIMER_TICK`
   - LED logic generates `EVENT_LED_STEP`
   - Events are **queued**, not handled immediately

3. **Event Dispatcher**
   - Runs slower than producers
   - Fetches events from the queue
   - Executes actions based on event type

4. **LED Control**
   - LED toggles only when `EVENT_LED_STEP` is handled
   - GPIO is never directly accessed by producers

---

## Example UART Output

- EVENT QUEUE STARTED
- QUEUED: TIMER_TICK
- QUEUED: LED_STEP
- QUEUED: TIMER_TICK
- QUEUED: LED_STEP
- HANDLED: LED_STEP
- ACTION: LED TOGGLED
- HANDLED: TIMER_TICK

  
This clearly shows:
- Events are queued first
- Handling happens later
- Producers and consumers are decoupled

---

## Why This Mimics an Operating System

This project reflects OS principles:

- **Event Queue** → Message queue / FIFO
- **Producers** → Interrupts / tasks
- **Dispatcher** → Scheduler / event loop
- **Handlers** → Task execution

No busy-wait logic directly controls hardware.  
All actions occur **only after event dispatch**, similar to cooperative multitasking.

---

## Limitations (Known & Accepted)

- No strict priority scheduling (FIFO-based)
- No interrupts (polling-based design)
- No preemption

These limitations are intentional for clarity and learning.

---

## How This Can Be Improved

Future enhancements:
- Add priority queues (HIGH / MEDIUM / LOW)
- Convert event queue into interrupt-driven model
- Implement cooperative scheduler
- Add timestamped events
- Add software timers

---

## Relevance to Digital VLSI / Computer Architecture

This design maps naturally to hardware concepts:
- FIFO → Register-based queue in Verilog
- Event dispatcher → FSM
- Scheduler → Control unit
- Event types → Opcode decoding

The same logic can be **re-implemented in Verilog/SystemVerilog** for:
- Event controllers
- Embedded accelerators
- Custom micro-architectures

---



