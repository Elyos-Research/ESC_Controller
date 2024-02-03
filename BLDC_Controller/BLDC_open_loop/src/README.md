# BLDC Controller Implementation

## Overview
This document describes the implementation details of the BLDC (Brushless DC) motor controller, focusing on the `bldc_controller.c` file. This file contains the core logic for motor control, including initialization, sensor readings, phase control, and PWM management.

## Key Features
- **Initialization**: Sets up the motor controller, initializing PWM channels, ADC readings, and GPIO pins as per the configurations defined in `bldc_pinout.h`.
- **Sensor Readings**: Implements functions to read throttle position, motor current, and voltage to ensure safe and efficient motor operation.
- **Phase Control**: Contains logic to adjust the motor phases based on hall sensor readings, optimizing the motor's performance.
- **PWM Management**: Manages PWM signals for the motor phases to control speed and direction.

## Usage
1. Ensure that `bldc_controller.h` and `bldc_pinout.h` are included and correctly configured for your hardware platform.
2. Call `bldc_init()` at the start of your program to initialize the motor controller.
3. Use the provided functions to control the motor based on your application requirements.

## Contributing
Contributions to enhance the implementation, add new features, or extend compatibility with other hardware platforms are welcome.

## Note
This file is part of a larger project aimed at creating an open-source motor controller for educational and competitive use in events like the Shell Eco Marathon.
