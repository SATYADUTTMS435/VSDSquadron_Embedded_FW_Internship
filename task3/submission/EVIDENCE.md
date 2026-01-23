# Task-3 Evidence

## UART Evidence
The UART output demonstrates correct firmware execution and system behavior.

Observed UART messages:
- System started
- Startup delay messages
- Disco lights starting

These messages confirm that the firmware runs from reset and executes the application logic correctly.



---

## Hardware Evidence
The hardware demonstration shows:
- VSDSquadron Mini board powered and running
- Multiple LEDs connected to GPIO pins
- LEDs toggling in a visible pattern after reset
- Button interaction controlling LED behavior



---

## Verification Explanation
- GPIO pins were configured using the GPIO driver library
- LED states were controlled using `gpio_toggle()`
- Button state was read using `gpio_read()`
- UART logs verified correct firmware execution

The successful LED operation and UART output confirm proper hardware–software interaction on the real board.

