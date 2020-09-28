# Drivers

This repository contains a simple set of drivers for the tm4c1294ncpdt board from Texas Instruments and written by an Electrical Engineering undergraduate student. These drivers were written parallel to an introductory course to the field of embedded systems. I took the extra time to write my own drivers and test my drivers by solving the assignments with them. This set of drivers include polling and interrupt based solutions for the following peripherals:
* Analog to Digital Converters (ADC)
* GPIO Pins and Ports (GPIO)
* Timers (TIM)
* Universal Asynchronous Receiver/Transmitter (UART)
* Nested Vectored Interrupt Controller (NVIC)
* Partial drivers for SYSCTL (To enable/disable clock to portions of the system and to check if the change has been made)

# Examples
* Please find examples of all peripherals in the repo where I solve the assignments https://github.com/RafaelLaya/Introduction_To_Embedded_Systems 
* The docstrings in the header file describe exactly what each method is doing, what the parameters mean, and how to use it

# Dependencies 
No dependencies. The drivers are bare-metal and self-contained in this repository. 

## Configuration Options
Please find the following constants in tm4c1294ncpdt_config.h: 
* ASSERT_ENABLED: If non-zero, enables assertions of valid parameters inside the drivers. Can be useful for debugging.
* INCLUDE_ALL_AUTOMATICALLY: If non-zero, then including tm4c1294ncpdt.h also includes the other drivers inside this set of drivers (ADC, GPIO, TIM, UART, NVIC, and SYSCTL)

