# Task-2 Evidence: VSDSquadron Mini

This document provides proof of successful hardware execution for Task-2,  
including UART communication and GPIO pin control on the VSDSquadron Mini board.

---

## UART Evidence

### Setup
- **Interface:** Debug UART via WCH-Link
- **Serial Port:** COM3
- **Baud Rate:** 115200
- **Terminal Tool:** PuTTY 

### Observation
- After pressing the RESET button on the board, UART output is printed.
- The output includes:
  - Board name
  - Firmware version
  - A continuously increasing counter
- More than 10 consecutive readable lines are observed without corruption.

### Proof
- Screenshot showing 10+ UART messages:
  - `images/uart/IMG20260119230338.jpg`
- Video showing reset and UART output:
  - `videos/uart/VID_20260119234732.mp4`

---

## GPIO Evidence

### Setup
- **GPIO Pin:** PD6
- **Firmware Mapping:** GPIOD, GPIO_Pin_6
- **Hardware:** On-board blue LED and an external yellow LED connected through 220ohm resistor.

### Observation
- GPIO pin configured as output.
- The on-board blue LED and yellow LED toggles periodically, producing a visible blink.

### Proof
- Photo of board with LED:
  - `images/gpio/IMG20260119230033.jpg`
- Video showing LED blinking:
  - `videos/gpio/VID_20260119235101.mp4`

---

## Verification Summary
- UART and GPIO were tested on real hardware.
- Correct hardware–software interaction was observed.
- GPIO pin mapping matches the board datasheet.
- UART output is stable and readable.

This evidence confirms successful completion of Task-2 requirements.
