\# Task-2 Evidence: VSDSquadron Mini



This document provides proof of successful hardware execution for Task-2,

including UART communication and GPIO pin control on the VSDSquadron Mini board.



---



\## UART Evidence



\### Setup

\- Interface: Debug UART via WCH-Link

\- Serial Port: COM3

\- Baud Rate: 9600

\- Terminal Tool: PuTTY / Serial Monitor



\### Observation

\- After pressing the RESET button on the board, UART output is printed.

\- The output includes:

&nbsp; - Board name

&nbsp; - Firmware version

&nbsp; - A continuously increasing counter

\- More than 10 consecutive readable lines are observed without corruption.



\### Proof

\- Screenshot showing 10+ UART messages:

&nbsp; - `images/uart/uart\_output.png`

\- Video showing reset and UART output:

&nbsp; - `videos/uart/uart\_reset\_output.mp4`



---



\## GPIO Evidence



\### Setup

\- GPIO Pin: PD6

\- Firmware Mapping: GPIOD, GPIO\_Pin\_6

\- Hardware: On-board blue LED



\### Observation

\- GPIO pin configured as output.

\- The on-board blue LED toggles periodically, producing a visible blink.



\### Proof

\- Photo of board with LED:

&nbsp; - `images/gpio/gpio\_led\_pd6.jpg`

\- Video showing LED blinking:

&nbsp; - `videos/gpio/gpio\_led\_blink.mp4`



---



\## Verification Summary

\- UART and GPIO were tested on real hardware.

\- Correct hardware–software interaction was observed.

\- GPIO pin mapping matches the board datasheet.

\- UART output is stable and readable.



This evidence confirms successful completion of Task-2 requirements.



