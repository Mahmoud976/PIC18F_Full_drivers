# PIC18F Custom Bare-Metal Drivers Framework

[![Release](https://img.shields.io/github/v/release/Mahmoud976/Custom-RTOS)](https://github.com/Mahmoud976/Custom-RTOS/releases/tag/v1.0.0)

[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A robust, production-grade Peripheral Driver Library (MCAL) developed from scratch for the Microchip 8-bit PIC18F microcontroller architecture. This repository highlights strict bare-metal hardware manipulation through explicit bitwise operations on hardware registers, eliminating any reliance on vendor-specific code configurators (such as MCC).

The architecture is carefully structured to follow standard layered software design conventions used in critical embedded systems.

---

## 📂 Repository Structure & Architecture

The repository enforces a clean separation of concerns, dividing peripheral management, compiler directives, and automated build scripts.

```microshield
├── PIC18F_Drivers/         # Core Firmware Modules
│   ├── MCAL/               # Microcontroller Abstraction Layer
│   │   ├── GPIO/           # Digital I/O Register configurations
│   │   ├── Interrupt/      # IVT, Priority levels, Peripheral interrupts
│   │   ├── Timers/         # Timer0, Timer1, Timer2/3 hardware tickers
│   │   ├── ADC/            # Analog-to-Digital Converter modules
│   │   ├── EEPROM/         # Internal Non-volatile Data EEPROM
│   │   └── Communication/  # Hardware Serials (UART, SPI, I2C)
│   └── ECU_HAL/            # Hardware Abstraction Layer (External Components)
│       ├── LCD/            # Character displays interfacing
│       ├── Keypad/         # Matrix scanning configuration
│       └── SevenSegment/   # Multiplexed display controls
├── .gitignore              # Ignores compiler output artifacts (.o, .d, .hex)
├── Makefile                # Multi-target build script for automation
└── README.md               # Embedded firmware framework documentation
```

---

## 🚀 Key Technical Highlights

- **Pure Register-Level Layering:** Implemented step-by-step using pure C syntax, referencing memory mappings directly from the official Microchip datasheets.
- **Hardware-Software Decoupling:** Complete implementation of an isolated Electronic Control Unit (ECU) layer that communicates strictly through the underlying Microcontroller Abstraction Layer (MCAL).
- **Automated Toolchain Integration:** Integrated with an explicit `Makefile` that controls dependency building, header inclusion paths, and links object files directly using the **XC8 compiler**.

---

## 🛠️ Toolchain and Environment Prerequisites

To compile, download, or flash this codebase locally, verify that your workspace includes:
- **IDE:** Microchip MPLAB X IDE (v6.00 or higher recommended).
- **Compiler:** Microchip XC8 Compiler (v2.30+).
- **Build System:** GNU Make (integrated within standard Linux systems or via MinGW on Windows Environments).

---

## 🔧 Building from Source

The firmware utilizes the repository-level `Makefile` to trigger deterministic compilation workflows.

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd PIC18F_Full_drivers
   ```

2. **Compile the entire project hierarchy:**
   ```bash
   make all
   ```

3. **Clean up intermediate compiler objects (`.o`, `.d`):**
   ```bash
   make clean
   ```

---

## 📋 Coding Standard & Driver Sample

Every peripheral driver is built on decoupled pointer architectures to provide reusability, keeping structural initializations predictable:

```c
/* Standard Initialization Layout Met across MCAL Peripherals */
gpio_pin_config_t led_pin = {
    .port = PORTD_INDEX,
    .pin = PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW
};

// Initialize peripheral with atomic register manipulation
std_return_type ret = gpio_pin_initialize(&led_pin);
```

---

## 📄 License
This codebase is distributed under the **MIT License**. Check the [LICENSE](LICENSE) file for complete compliance documentation.



# Author

Mahmoud Saleh

Embedded Systems Engineer

