cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(controlador C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(controlador_openLoop
controlador_openLoop.c
)

target_link_libraries(controlador_openLoop pico_stdlib hardware_pwm hardware_adc hardware_irq hardware_gpio)

pico_enable_stdio_usb(controlador_openLoop 1)		# Enable USB printf output
pico_enable_stdio_uart(controlador_openLoop 0)	# Disable serial printf output

pico_add_extra_outputs(controlador_openLoop)
