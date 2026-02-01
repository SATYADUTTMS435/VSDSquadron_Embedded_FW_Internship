
# Task-4 Evidence: Event Queue Embedded Application
VSDSquadron Mini

This document provides proof of correct execution of the event-driven firmware on real hardware.

---

## UART Evidence

### Setup
- **UART Interface:** Debug UART via WCH-Link
- **Port:** COM3
- **Baud Rate:** 115200
- **Terminal Tool:** PuTTY

---

### Observed Output
After pressing the RESET button, the following output is observed:

- EVENT QUEUE STARTED
- QUEUED: TIMER_TICK
- QUEUED: LED_STEP
- QUEUED: TIMER_TICK
- QUEUED: LED_STEP
- HANDLED: LED_STEP
- ACTION: LED TOGGLED
- HANDLED: TIMER_TICK


This confirms:
- Events are queued independently
- Multiple events accumulate before handling
- Handling occurs later via dispatcher
- UART accurately reflects system state

---

## GPIO Evidence

### Setup
- **GPIO Pin:** PD5
- **Hardware:** External LED

---

### Observation
- LED toggles only when `EVENT_LED_STEP` is handled
- LED behavior matches UART logs
- Confirms correct event-to-hardware execution

---

### Proof
- Image:
  - `Media/<image_name>.jpg`
- Video:
  - `Media/<video_name>.mp4`

---

## Verification Summary
- Real hardware execution verified
- UART logging validated
- Event queue behavior confirmed
- OS-like scheduling demonstrated
- Task-4 requirements satisfied



