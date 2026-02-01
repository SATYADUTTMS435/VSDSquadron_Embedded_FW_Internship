# Demo Guide  
Event Queue Framework Demo – VSDSquadron Mini

This document explains **how to run, observe, and verify** the demo application.

---

## Hardware Setup

### Board
- VSDSquadron Mini (CH32V003)

### Connections
- **LED**: On-board LED connected to PD5
- **Debugger**: WCH-Link
- **UART Interface**: Debug UART via WCH-Link

No external USB-TTL adapter is required.

---

## UART Configuration

| Parameter | Value |
|--------|-------|
| Baud Rate | 115200 |
| Data Bits | 8 |
| Stop Bits | 1 |
| Parity | None |
| Port | COM3 |
| Terminal | PuTTY |

---

## Build and Flash Steps

1. Open the project in VS Code
2. Ensure `platformio.ini` is configured for `vsdsquadronMini`
3. Connect the board using WCH-Link
4. Build and upload:
   ```bash
   pio run --target upload
   ```
5. Open PuTTY with the UART settings above

---

## How to Run the Demo

1. Press the **RESET** button on the board
2. Observe UART output immediately after reset
3. Watch the LED behavior on the board

---

## Expected UART Output

After reset, UART should display logs similar to:

```
EVENT QUEUE STARTED
QUEUED: TIMER_TICK
QUEUED: LED_STEP
QUEUED: TIMER_TICK
HANDLED: LED_STEP
ACTION: LED TOGGLED
HANDLED: TIMER_TICK
```

---

## What to Observe

### UART
- Events are **queued faster** than they are handled
- Multiple `QUEUED` messages appear before `HANDLED`
- Event handling order depends on queue state

### LED
- LED toggles only when `EVENT_LED_STEP` is handled
- LED behavior matches UART logs

---

## Verification Checklist

- [x] UART prints are readable and stable
- [x] Event queue messages appear in correct order
- [x] LED toggles based on event handling
- [x] Application runs continuously without crash
- [x] No direct register access in `main.c`

---

## Demo Purpose

This demo verifies:
- Event-driven firmware design
- Multi-driver integration
- OS-like scheduling behavior
- Producer–consumer decoupling

---

## Known Limitations

- No hardware interrupts used
- No preemptive scheduling
- Single event handled per dispatch cycle
- Priority handling not implemented (future work)

---

## Future Demo Extensions

- Interrupt-based event producers
- Priority-aware scheduling
- Multi-LED support
- RTOS migration

---

End of Demo Guide

