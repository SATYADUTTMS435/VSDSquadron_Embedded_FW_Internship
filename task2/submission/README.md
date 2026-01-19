# Task-2: VSDSquadron Mini Board Bring-Up, UART & GPIO Validation

## Overview
This task demonstrates real hardware bring-up on the VSDSquadron Mini RISC-V board.

The objective was to flash firmware on actual hardware, validate UART communication, map physical GPIO pins to firmware definitions, and follow a clean layered firmware structure.

UART and GPIO were validated on real hardware in separate firmware runs.  
The submission code represents the final integrated application structure.

---

## Hardware Platform
- **Board:** VSDSquadron Mini (CH32V003 – RISC-V)
- **Debug Interface:** WCH-Link
- **Host OS:** Windows 11

---

## UART Validation
- **Interface:** Debug UART via WCH-Link
- **Serial Port:** COM3
- **Baud Rate:** 9600

### Behavior
- UART prints a startup message after reset
- Board name and firmware version are displayed
- A continuously increasing counter is printed

### Verification
- More than 10 consecutive readable UART messages observed
- Output captured using a serial terminal after pressing reset

---

## GPIO Validation
- **GPIO Pin:** PD6
- **Firmware Mapping:** GPIOD, GPIO_Pin_6
- **Hardware Connection:** On-board blue LED

### Behavior
- GPIO configured as output
- LED toggles periodically (visible blink)

### Verification
- LED blinking observed directly on the board

---

## Firmware Structure
The firmware follows a layered architecture:
- `main.c` contains only application logic
- `uart.c / uart.h` implement UART abstraction
- `gpio.c / gpio.h` implement GPIO abstraction
- No direct hardware register access is done inside `main.c`

---

## Build and Flash
Firmware was built and flashed using PlatformIO.

Separate PlatformIO projects were used for UART and GPIO validation.  
The submission folder contains the final, clean source code for evaluation.

---

## Notes
All hardware interactions were validated on the actual VSDSquadron Mini board.

Evidence screenshots and videos are provided in the `images` and `videos` folders.
