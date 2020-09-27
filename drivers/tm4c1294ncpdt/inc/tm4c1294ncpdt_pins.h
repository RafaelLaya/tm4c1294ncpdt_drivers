
#pragma once

// Location of LEDs D1, D2, D3, and D4 in our TM4C1294NCPDT board for Task 1
#define GPIO_D1_D2_PORT              GPION
#define GPIO_D1_PORT                 GPIO_D1_D2_PORT
#define GPIO_D2_PORT                 GPIO_D1_D2_PORT
#define GPIO_D3_D4_PORT              GPIOF
#define GPIO_D3_PORT                 GPIO_D3_D4_PORT
#define GPIO_D4_PORT                 GPIO_D3_D4_PORT
#define GPIO_D1_PIN                  GPIO_PinNumber_1
#define GPIO_D2_PIN                  GPIO_PinNumber_0
#define GPIO_D3_PIN                  GPIO_PinNumber_4
#define GPIO_D4_PIN                  GPIO_PinNumber_0
#define SYSCTL_PRGPIO_D1_D2_POS      SYSCTL_PRGPIO_PORTN_POS  
#define SYSCTL_PRGPIO_D3_D4_POS      SYSCTL_PRGPIO_PORTF_POS

// Location and IRQ Number of Switches SW1 and SW2 in our TM4C1294NCPDT board for Task 1
#define GPIO_SW1_SW2_PORT           GPIOJ
#define GPIO_SW1_PORT               GPIO_SW1_SW2_PORT
#define GPIO_SW2_PORT               GPIO_SW1_SW2_PORT
#define GPIO_SW_PORT                GPIO_SW1_SW2_PORT
#define GPIO_SW1_PIN                GPIO_PinNumber_0
#define GPIO_SW2_PIN                GPIO_PinNumber_1
#define SYSCTL_PRGPIO_SW1_SW2_POS   SYSCTL_PRGPIO_PORTJ_POS
#define SYSCTL_PRGPIO_SW1_POS       SYSCTL_PRGPIO_SW1_SW2_POS
#define SYSCTL_PRGPIO_SW2_POS       
#define SYSCTL_RCGCGPIO_SW1_SW2_POS   SYSCTL_PRGPIO_PORTJ_POS
#define SYSCTL_RCGCGPIO_SW1_POS       SYSCTL_PRGPIO_SW1_SW2_POS
#define SYSCTL_RCGCGPIO_SW2_POS       SYSCTL_PRGPIO_SW1_SW2_POS
#define GPIO_SW1_SW2_IRQNUMBER        GPIOJ_IRQNumber
#define GPIO_SW_IRQNUMBER             GPIO_SW1_SW2_IRQNUMBER

