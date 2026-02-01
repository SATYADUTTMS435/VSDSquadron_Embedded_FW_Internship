# Task-4: Event Queue–Based Embedded System
VSDSquadron Mini | Embedded Firmware Internship

## Project Description
This project implements an **event-driven embedded system** on the VSDSquadron Mini (CH32V003 RISC-V MCU).  
The system uses a **FIFO-based event queue** to decouple event generation from event handling, mimicking **operating system scheduling behavior** in a **bare-metal environment** (no RTOS).

The design integrates **UART, GPIO, and an Event Queue framework**, fulfilling Task-4 requirements while maintaining clean API separation and real hardware execution.

---

## Drivers Used
- **UART Driver** – System logging and observability
- **GPIO Driver** – LED control
- **Event Queue Module** – FIFO-based event storage and dispatch

---

## Event Types
- `EVENT_TIMER_TICK`
- `EVENT_LED_STEP`

---

## System Architecture (Theory)

### 1. Event Producers
Event producers are code sections that **generate events only**.
They do **not** perform hardware actions.

In this project:
- Timer logic generates `EVENT_TIMER_TICK`
- LED logic generates `EVENT_LED_STEP`

Events are pushed into a FIFO queue.

This is equivalent to **interrupts or tasks becoming ready** in an operating system.

---

### 2. Event Queue (FIFO)
- Events are stored in **First-In First-Out order**
- Multiple events can accumulate before being processed
- No priority scheduling is implemented in this version

This FIFO queue directly represents an **OS ready queue**.

---

### 3. Dispatcher (Event Consumer)
The dispatcher:
- Runs slower than producers
- Pulls one event at a time from the queue
- Executes actions based on event type

This mimics a **cooperative scheduler** where tasks are executed when CPU time is available.

---

## OS Scheduling Analogy (Important Theory)

| OS Concept | Implemented Here |
|-----------|------------------|
| Interrupt / Task | Event Producer |
| Ready Queue | FIFO Event Queue |
| Scheduler | Dispatcher Loop |
| Context Execution | Event Handler |
| Cooperative Multitasking | Time-sliced main loop |

This demonstrates **how an OS works internally**, without using an RTOS.

---

## Why Queued and Handled Are Separated
- Events are **queued fast**
- Events are **handled slowly**
- This causes visible interleaving:

