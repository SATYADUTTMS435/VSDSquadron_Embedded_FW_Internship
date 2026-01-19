# Task 1 – Firmware Library Exploration

This folder contains the **Task 1 lab** for the VSDSquadron Mini RISC-V Internship.

The objective of this task is to understand:
- How embedded firmware libraries are structured
- How application code interacts with hardware through APIs
- How low-level hardware details are abstracted using reusable functions

This task is **board-independent** and is intended to build foundational knowledge before working with the actual RISC-V SoC.

---

## Folder Purpose

The files in this directory demonstrate a **simple GPIO firmware library** using C.  
The code structure mirrors real-world embedded firmware design practices.

---

## File Description

- **gpio.h**  
  Declares the GPIO API (function prototypes).  
  Represents the interface exposed to application code.

- **gpio.c**  
  Implements the GPIO functions.  
  Simulates how firmware would interact with hardware registers.

- **main.c**  
  Acts as application code.  
  Uses the GPIO API without knowing internal implementation details.

---

## Key Learning Outcome

This lab demonstrates the separation between:
- **Application layer**
- **Firmware/driver layer**

Such separation improves code reuse, maintainability, and scalability in embedded systems.

---

## Build and Run

To compile and run the lab:

```bash
gcc main.c gpio.c -o task1_demo
./task1_demo

