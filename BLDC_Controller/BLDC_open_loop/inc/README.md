# BLDC Controller Library for Open-Loop Control

This library provides the necessary interfaces and definitions for controlling a Brushless DC (BLDC) motor using an open-loop control scheme. It is designed for use in the Shell Eco-marathon electric prototype race, targeting custom controller boards.

## Overview

The library consists of two main header files:

- `bldc_controller.h`: Defines the main structures, constants, and function prototypes for BLDC motor control. It abstracts the hardware-specific details to provide a uniform interface for motor control.
- `bldc_pinout.h`: Contains the definitions of GPIO pins used by the BLDC motor controller, offering a hardware abstraction layer that makes the controller code portable across different hardware platforms.

## Getting Started

1. **Hardware Platform Configuration**: Begin by selecting your target hardware platform in `bldc_pinout.h`. Uncomment the corresponding define statement for your platform (e.g., `#define STM32_HAL` for STM32 boards).

2. **Pinout Configuration**: Adjust the pin definitions in `bldc_pinout.h` to match your hardware setup. This includes defining GPIO pins for hall sensors, high/low side transistors, throttle input, and sensor inputs for voltage and current measurement.

3. **Library Integration**: Include `bldc_controller.h` in your project to access the BLDC control functionalities. Use the provided function prototypes to initialize the motor, read sensor values, and control the motor phases.

## Key Features

- Support for multiple hardware platforms including STM32, Raspberry Pi Pico, Arduino, and ESP32.
- Configurable pinout definitions to adapt to various custom controller board designs.
- Open-loop control scheme with provisions for future enhancements towards closed-loop control.

## Usage

Refer to the function declarations in `bldc_controller.h` for motor initialization, sensor readings, and motor control. The library provides a flexible API to accommodate various control strategies tailored for the Shell Eco-marathon electric prototype race.

## Contributions

Contributions to this project are welcome. Please submit pull requests or raise issues for enhancements, bug fixes, or documentation improvements.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
