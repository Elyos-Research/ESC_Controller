# BLDC Motor Controller for Electric Prototype - Open Loop Version

This repository contains the open-loop control software for a Brushless DC (BLDC) motor, designed specifically for electric prototypes participating in competitions like the Shell Eco-marathon. The controller utilizes a custom hardware board, and this documentation covers the library files necessary for operating the BLDC motor in an open-loop configuration.

## Overview

The BLDC motor controller software is designed to interface with custom hardware to control a BLDC motor without feedback, providing basic motor functions essential for electric vehicle prototypes. This version is optimized for simplicity and reliability, focusing on applications where precise control over speed or position is less critical.

## Files Description

- `bldc_controller.h`: Header file defining the structure, constants, and function prototypes for BLDC motor control. It includes hardware abstraction layers for different platforms such as STM32, Raspberry Pi Pico, and more.

- `bldc_pinout.h`: Header file containing the definitions of GPIO pins used by the BLDC motor controller. It abstracts the hardware-specific pin configurations to make the software portable across different hardware platforms.

- `bldc_controller.c`: The implementation file for the BLDC motor control. It includes functions for initializing the motor controller, reading hall sensor values, controlling motor phases, and handling interrupts.

## Hardware Compatibility

The controller software is designed to be compatible with multiple hardware platforms, including STM32 HAL, Raspberry Pi Pico, and potentially others with minimal adjustments. Pinout and peripheral configurations are abstracted in `bldc_pinout.h` to facilitate porting to different hardware.

## Getting Started

To use this controller software:
1. Ensure your hardware platform is supported and configured correctly in `bldc_pinout.h`.
2. Include the library files in your project.
3. Initialize the motor controller using `bldc_init()` function.
4. Use the provided functions to control the motor according to your application needs.

## Contributing

Contributions to improve the software, add new features, or extend hardware compatibility are welcome. Please submit pull requests or open issues to discuss proposed changes.
