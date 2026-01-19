Part A: Understand firmware libraries (conceptual) 

Q. What is embedded firmware?
- It is the brain that directly controls the hardware of a device.It interacts with the physical components like sensors,processors, or motors.

Its a set of instructions written such that device runs smoothly (like booting up a device). It is usually not changed once written/programmed to the device,as updating firmware is a complex process.

<img width="817" height="548" alt="Image" src="https://github.com/user-attachments/assets/a5bbe3ab-fb1a-4af3-9c48-8233aa470aef" />

* Role / Characteristics :-

1.Stored in Non-Volatile Memory - like ROM,EEPROM,Flash, such that device is powered off,storage types ensure firmware is retained thus reponsible for core functions of hardware as it doesnt get wiped out or reset.

2.Booting the Device - Primary task is booting the device,without this hardware will be clueless how to function. It prepares hardware components and sets up communication between device hardware and software.

* Difference between Application code and Embedded Hardware -

<img width="862" height="522" alt="Image" src="https://github.com/user-attachments/assets/8cf00fac-3595-419a-9b93-e98960d5a250" />

Q. What is firmware library/API ?
- A firmware library (or API — Application Programming Interface) is a collection of ready-made functions developers can use in their embedded code so they don’t have to write low-level hardware code from scratch. It provides a defined set of routines and interfaces for controlling hardware and implementing common tasks in firmware.

Functions such as digitalWrite(), delay(), and Serial.write() are part of firmware libraries (like Arduino’s API). They provide simple, human-friendly usage code so you can perform common actions (setting a pin high/low, waiting, sending data over serial) without dealing with the hardware registers. These APIs make development faster and easier for programmers.

These library functions call into a hardware abstraction layer (HAL) or similar drivers that directly manipulate memory-mapped registers and hardware peripherals. The API hides all of this complexity so WE don’t need to know the exact register addresses or bit manipulation for each hardware component.

Usable APIs are essential because:

They reduce development effort by letting engineers reuse tested and stable code.

They make firmware portable — the same high-level code can run on different microcontrollers by changing only the underlying library/HAL implementation.

They improve maintainability and scalability in large projects with many developers.

<img width="276" height="183" alt="Image" src="https://github.com/user-attachments/assets/f02bacaf-8c5c-4d67-8c18-755d75904233" />

Q. Bare-metal firmware basics 
-Bare-metal firmware means writing code that runs directly on the microcontroller hardware without any operating system (no RTOS, no scheduler). The firmware has full control of the hardware registers, peripherals, and timing, and there’s no OS layer managing tasks for you.

An RTOS (Real-Time Operating System) adds layers for task scheduling, inter-task communication, and timing services, but also uses extra memory and CPU overhead. In small embedded programs , the functionality is simple and doesn’t require multitasking or complex OS features, so using bare-metal keeps the system lightweight, fast, and predictable.

Timing: Firmware often uses hardware timers set up by the programmer. These timers can count time ticks, and the code checks (polls) or handles these events based on elapsed time.

Polling: This is a simple method where the firmware repeatedly checks (in a loop) whether a condition or event has occurred (like a button press). Polling wastes CPU cycles but is easy to implement for simple systems.

Interrupts: Instead of constantly checking for events, hardware peripherals can interrupt the CPU when something important happens. When an interrupt occurs, the CPU stops the main loop and runs a small Interrupt Service Routine (ISR) to handle that event immediately, then returns to the main code. Interrupts allow fast, efficient responses to asynchronous events without an OS.

Part B: Development environment setup (hands-on).

<img width="532" height="418" alt="Image" src="https://github.com/user-attachments/assets/612fe849-a931-4255-a7ec-f989a1a42fe0" />

Part C: Lab – Understanding a simple firmware library.

These three code sections together form a complete simulated GPIO firmware application in C. The header file gpio.h defines GPIO direction constants (GPIO_INPUT and GPIO_OUTPUT) and declares the functions gpio_init, gpio_write, and gpio_read with include guards to prevent multiple inclusions. The implementation file provides definitions for these functions: gpio_init configures a pin as input or output and prints the action, gpio_write sets a simulated output value for a pin, and gpio_read returns a fixed simulated input value while printing the read action. The main program demonstrates using this library by initializing an LED pin as output and a button pin as input, turning the LED on and off, reading the button state, and printing all actions to the console, effectively simulating how a firmware application would control hardware GPIOs.

<img width="947" height="327" alt="Image" src="https://github.com/user-attachments/assets/c1fa0bd6-d34e-4010-983c-528ef252aacb" />




