# Task-3 Evidence: Advanced GPIO Driver Library

This document provides proof of successful hardware execution for Task-3,  
demonstrating a reusable GPIO driver library and a working application on the VSDSquadron Mini RISC-V board.

---

## UART Evidence

### Setup
- **Interface:** On-board UART via WCH-Link  
- **Serial Port:** COM3  
- **Baud Rate:** 115200 
- **Terminal Tool:** PuTTY  

### Observation
- After pressing the RESET button on the board, UART output is printed.
- The output includes:
  - System startup message
  - Startup delay messages
  - Application start indication

---

## GPIO Evidence

### Setup
- **GPIO Pins Used:** PD2, PD3, PD4  
- **Firmware Mapping:** GPIOD, GPIO_Pin_2 / GPIO_Pin_3 / GPIO_Pin_4  
- **Hardware:** External LEDs connected to GPIO pins
- **Input:** On-board push button  

### Observation
- GPIO pins are configured using a reusable GPIO driver library.
- After reset, the firmware waits for a startup delay of 3 seconds and then begins toggling multiple LEDs in a disco pattern.
- LED toggling is controlled using GPIO APIs (`gpio_init`, `gpio_toggle`, `gpio_read`).
- Button input is read correctly and controls LED behavior.

### Proof
- Photo of board with LED connections:
  - `images/gpio/<gpio_image_name>.jpg`
- Video showing startup delay and LED disco pattern:
  - `videos/gpio/<gpio_video_name>.mp4`

---

## Verification Summary
- A reusable GPIO driver library was implemented and used by the application.
- No direct hardware register access was performed in `main.c`.
- GPIO input and output functionality was verified on real hardware.
- UART logs confirm correct firmware execution and application flow.
- LED behavior confirms correct hardware–software interaction.

This evidence confirms successful completion of Task-3 requirements.
