# Task-4: Event Queue Framework + GPIO Application  
VSDSquadron Mini Embedded FW Internship

## Project Overview
This project implements a **priority-based Event Queue framework** on the VSDSquadron Mini RISC-V board and demonstrates it using a real hardware application.

Multiple firmware modules (UART, GPIO, Event Queue) are integrated to simulate an **OS-like event-driven architecture**, where events are produced and consumed asynchronously.

The application clearly separates:
- **Event producers**
- **Event dispatcher (consumer)**
- **Hardware actions**

This mirrors real embedded firmware and computer-architecture style designs.

---

## Drivers Used
- **UART** – Logging and visibility of system behavior
- **GPIO** – LED output control
- **Event Queue** – Priority-based FIFO event management

(Three drivers integrated ✔️)

---

## Event Queue Design
Two event types are used:
- `EVENT_TIMER_TICK` → Low priority  
- `EVENT_LED_STEP` → High priority  

Events are queued by producers at different rates and handled later by a dispatcher, demonstrating:
- Queueing vs handling decoupling
- Priority-based servicing
- Real-time embedded behavior

---

## Application Behavior
- Firmware starts and prints a startup message
- Events are queued continuously:
  - Timer events (low priority)
  - LED step events (high priority)
- Dispatcher runs slower than producers
- High-priority LED events are handled first
- LED toggles only when LED events are handled
- UART logs clearly show:
  - When events are **queued**
  - When events are **handled**
  - Hardware action taken

---

## GPIO Configuration
- **LED Pin:** PD5  
- **Mode:** Output  
- LED toggles only when `EVENT_LED_STEP` is handled

---

## UART Configuration
- **Interface:** Debug UART via WCH-Link
- **Baud Rate:** 115200
- **Terminal:** PuTTY / Arduino Serial Monitor

---

## Build & Flash Steps
```bash
pio run
pio run --target upload

