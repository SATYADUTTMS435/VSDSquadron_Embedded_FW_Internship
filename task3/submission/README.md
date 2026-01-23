# Task-3: Advanced GPIO Driver Library + Application

## Overview
This task demonstrates the design and implementation of a reusable GPIO driver library and a working application on the VSDSquadron Mini RISC-V board.  
The application uses the GPIO library to control multiple LEDs and logs system activity over UART.

---

## Library Implemented
**Advanced GPIO Driver Library**

### GPIO APIs
- `gpio_init(pin, mode)`  
  Initializes a GPIO pin as input or output.

- `gpio_set(pin)`  
  Sets the GPIO pin to logic HIGH.

- `gpio_clear(pin)`  
  Clears the GPIO pin to logic LOW.

- `gpio_toggle(pin)`  
  Toggles the current state of the GPIO pin.

- `gpio_read(pin)`  
  Reads the logic level of a GPIO pin configured as input.

---

## Application Description
The application demonstrates:
- System startup with UART messages
- A startup delay after reset
- A multi-LED disco pattern using GPIO APIs
- Button-based control of LED toggling

On every reset:
1. The system prints startup messages on UART
2. Waits for a few seconds
3. Starts toggling multiple LEDs in a visible pattern

All GPIO operations are performed using the GPIO driver library, and no hardware registers are accessed directly in `main.c`.

---

## UART Configuration
- Baud rate: 115200
- Serial Port : COM3
- Interface: On-board UART via USB
- Used for startup and status messages

---

## Build and Flash Instructions
1. Open the PlatformIO project
2. Connect the VSDSquadron Mini board
3. Build the project
4. Upload the firmware using WCH-Link
5. Open a serial terminal to view UART logs

---

## Hardware Used
- VSDSquadron Mini RISC-V board
- On-board push button 

