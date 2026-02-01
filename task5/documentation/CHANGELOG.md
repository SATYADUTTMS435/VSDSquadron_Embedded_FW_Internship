# Changelog

All notable changes to this project are documented in this file.

This project follows a simple semantic versioning scheme for clarity.

---

## v1.0.0 – Initial Release

### Added
- Implemented UART driver for logging and debugging
- Implemented GPIO driver for LED control
- Implemented software-based event queue framework
- Integrated multi-driver application using GPIO + UART
- Added event producer–consumer architecture
- Demonstrated asynchronous event handling
- Verified execution on VSDSquadron Mini hardware

### Application Features
- Timer-based event generation
- LED control through event dispatching
- UART logs showing queued vs handled events
- Cooperative scheduling behavior

---

## v1.1.0 – Architecture Refinement

### Improved
- Clear separation between event producers and dispatcher
- Controlled timing differences to simulate task scheduling
- Improved UART log readability
- Reduced blocking inside event handling

---

## v1.2.0 – Final Submission Version

### Finalized
- Stable event queue behavior
- Reliable UART output at 115200 baud
- Hardware-validated LED toggling
- Documentation prepared for internship submission

---

End of Changelog

