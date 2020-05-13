/*
 * Rafael Laya
 * 1975274
 * April 16th, 2020
 * Contains necessary definitions for tm4c1294ncpdt_gpio.c to use
 * TM4C1294NCPDT
 */

#ifndef __TM4C1294NCPDT_GPIO_H__
#define __TM4C1294NCPDT_GPIO_H__

#include "tm4c1294ncpdt.h"

// Holds information related to Interrupt Configuration for a GPIO Pin
typedef struct {
    uint8_t GPIO_PinSense;           /* Value from @GPIO_PinSense */
    uint8_t GPIO_PinEdge;            /* Value from @GPIO_PinEdge */
} GPIO_PinITConfig_t;

// Holds information related to a GPIO Pin Configuration
typedef struct {
    uint8_t GPIO_PinMode;           /* Value from @GPIO_PinMode */
    uint8_t GPIO_PinPuPdControl;    /* Value from @GPIO_PinPuPdControl */
} GPIO_PinConfig_t;

// Holds information necessary to turn initialize a GPIO Pin
typedef struct {
    GPIO_PinConfig_t GPIO_PinConfig;
    GPIO_PinITConfig_t GPIO_PinITConfig;
    uint8_t ConfigIT;                         /* ENABLE or DISABLE (See GPIO_Init() for more information)*/
} GPIO_InitDef_t;

/* @GPIO_PinSense */
#define GPIO_PinSense_EDGE      0U
#define GPIO_PinSense_LEVEL     1U

/* @GPIO_PinEdge */
#define GPIO_PinEdge_BOTH       0U
#define GPIO_PinEdge_FALLING    1U
#define GPIO_PinEdge_RISING     2U
#define GPIO_PinEdge_HIGH       GPIO_PinEdge_RISING
#define GPIO_PinEdge_LOW        GPIO_PinEdge_FALLING

/* @GPIO_PinNumber */
#define GPIO_PinNumber_0        0U
#define GPIO_PinNumber_1        1U
#define GPIO_PinNumber_2        2U
#define GPIO_PinNumber_3        3U
#define GPIO_PinNumber_4        4U
#define GPIO_PinNumber_5        5U
#define GPIO_PinNumber_6        6U
#define GPIO_PinNumber_7        7U

/* @GPIO_PinPuPdControl */
#define GPIO_PinPuPdControl_NOPULL          0x0U
#define GPIO_PinPuPdControl_PULLUP          0x1U
#define GPIO_PinPuPdControl_PULLDOWN        0x2U
#define GPIO_PinPuPdControl_OPENDRAIN       0x4U

/* @GPIO_PinAltFuncMode */
#define GPIO_PinAltFuncMode_1                1U
#define GPIO_PinAltFuncMode_2                2U
#define GPIO_PinAltFuncMode_3                3U
#define GPIO_PinAltFuncMode_4                4U
#define GPIO_PinAltFuncMode_5                5U
#define GPIO_PinAltFuncMode_6                6U
#define GPIO_PinAltFuncMode_7                7U
#define GPIO_PinAltFuncMode_8                8U
#define GPIO_PinAltFuncMode_9                9U
#define GPIO_PinAltFuncMode_10               10U
#define GPIO_PinAltFuncMode_11               11U
#define GPIO_PinAltFuncMode_12               12U
#define GPIO_PinAltFuncMode_13               13U
#define GPIO_PinAltFuncMode_14               14U
#define GPIO_PinAltFuncMode_15               15U

/* @GPIO_PinMode */
#define GPIO_PinMode_ALTFN1             GPIO_PinAltFuncMode_1
#define GPIO_PinMode_ALTFN2             GPIO_PinAltFuncMode_2
#define GPIO_PinMode_ALTFN3             GPIO_PinAltFuncMode_3
#define GPIO_PinMode_ALTFN4             GPIO_PinAltFuncMode_4
#define GPIO_PinMode_ALTFN5             GPIO_PinAltFuncMode_5
#define GPIO_PinMode_ALTFN6             GPIO_PinAltFuncMode_6
#define GPIO_PinMode_ALTFN7             GPIO_PinAltFuncMode_7
#define GPIO_PinMode_ALTFN8             GPIO_PinAltFuncMode_8
#define GPIO_PinMode_ALTFN9             GPIO_PinAltFuncMode_9
#define GPIO_PinMode_ALTFN10            GPIO_PinAltFuncMode_10
#define GPIO_PinMode_ALTFN11            GPIO_PinAltFuncMode_11
#define GPIO_PinMode_ALTFN12            GPIO_PinAltFuncMode_12
#define GPIO_PinMode_ALTFN13            GPIO_PinAltFuncMode_13
#define GPIO_PinMode_ALTFN14            GPIO_PinAltFuncMode_14
#define GPIO_PinMode_ALTFN15            GPIO_PinAltFuncMode_15
#define GPIO_PinMode_IN                 (GPIO_PinAltFuncMode_15 + 1U)
#define GPIO_PinMode_OUT                (GPIO_PinAltFuncMode_15 + 2U)
#define GPIO_PinMode_ANALOG             (GPIO_PinAltFuncMode_15 + 3U)
#define GPIO_PinMode_ALTFN_ANALOG       (GPIO_PinAltFuncMode_15 + 4U)

/* @GPIO_PinDir */
#define GPIO_PinDir_OUT                      1U
#define GPIO_PinDir_IN                       0U

// For checking configuration and detecting mistakes during development
#define GPIO_IS_GPIO(X)             ((X) == GPIOA || \
                                     (X) == GPIOB || \
                                     (X) == GPIOC || \
                                     (X) == GPIOD || \
                                     (X) == GPIOE || \
                                     (X) == GPIOF || \
                                     (X) == GPIOG || \
                                     (X) == GPIOH || \
                                     (X) == GPIOJ || \
                                     (X) == GPIOK || \
                                     (X) == GPIOL || \
                                     (X) == GPIOM || \
                                     (X) == GPION || \
                                     (X) == GPIOP || \
                                     (X) == GPIOQ)
#define GPIO_IS_PINSENSE(X)         ((X) == GPIO_PinSense_EDGE || (X) == GPIO_PinSense_LEVEL)
#define GPIO_IS_PINEDGE(X)          ((X) == GPIO_PinEdge_BOTH    || \
                                     (X) == GPIO_PinEdge_FALLING || \
                                     (X) == GPIO_PinEdge_RISING)
#define GPIO_IS_PIN_NUMBER(X)       (GPIO_PinNumber_0 <= (X) && (X) <= GPIO_PinNumber_7)
#define GPIO_IS_PIN_PUPD_CTRL(X)    (GPIO_PinPuPdControl_NOPULL <= (X) && (X) <= GPIO_PinPuPdControl_OPENDRAIN)
#define GPIO_IS_PIN_AF_MODE(X)      (GPIO_PinAltFuncMode_1 <= (X) && (X) <= GPIO_PinAltFuncMode_15)
#define GPIO_IS_PIN_MODE(X)         (GPIO_PinMode_ALTFN1 <= (X) && (X) <= GPIO_PinMode_ANALOG)
#define GPIO_IS_PIN_DIR(X)          ((X) == GPIO_PinDir_OUT || (X) == GPIO_PinDir_IN)
#define GPIO_IS_PIN_VAL(X)          ((X) == SET || (X) == RESET)

/**
  * @brief  Enables/Disables the clock for the given GPIO
  * @param  mask: Value from @SYSCTL_RCGCGPIO_MASK
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PeriphClockCtrlByMask(uint32_t mask, uint8_t Command);

/**
  * @brief  Enables/Disables the clock for the given GPIO
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PeriphClockCtrl(GPIO_RegDef_t *pGPIO, uint8_t Command);

/**
  * @brief  Initializes a given GPIO Pin. Note that the ConfigIT value
  *         inside the GPIO_InitDef_t refers to configuring IT related
  *         settings -- It doesn't enable Interrupts. Enabling interrupts
  *         Enabling interrupts is responsability of GPIO_IRQConfig() (and
  *         the NVIC drivers). 
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  pGPIOInit: A structure that holds information about initialization
  *
  * @retval None
  */
void GPIO_Init(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, GPIO_InitDef_t *pGPIOInit);

/**
  * @brief  Configures the alternate function of a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  AltFunc: Values from @GPIO_PinAltFuncMode
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PinAFConfig(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t AltFunc, uint8_t Command);

/**
  * @brief  Configures the Mode of a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  Mode: Values from @GPIO_PinMode
  * @retval None
  */
void GPIO_PinSetMode(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Mode);

/**
  * @brief  Configures Pull-up/Down resistors or Open Drain configuration of a
  *         GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  PuPd: Values from @GPIO_PinPuPdControl
  * @retval None
  */
void GPIO_PinSetPuPd(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t PuPd);

/**
  * @brief  Reads data from a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Values from @GPIO_PinNumber
  * @retval Value read from the GPIO Pin: SET or RESET
  */
uint8_t GPIO_PinRead(GPIO_RegDef_t *pGPIO, uint8_t PinNumber);

/**
  * @brief  Reads data from a GPIO Port
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @retval Value read from the GPIO Port: From 0x0 to 0xFF
  */
uint8_t GPIO_PortRead(GPIO_RegDef_t *pGPIO);

/**
  * @brief  Writes data in a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Values from @GPIO_PinNumber
  * @param  Value: Value to write (SET or RESET)
  * @retval None
  */
void GPIO_PinWrite(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Value);

/**
  * @brief  Writes data in a GPIO Port
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  Value: Value to Write (0x00 to 0xFF)
  * @retval None
  */
void GPIO_PortWrite(GPIO_RegDef_t *pGPIO, uint8_t Value);

/**
  * @brief  Toggles the output of a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Values from @GPIO_PinNumber
  * @retval None
  */
void GPIO_PinToggle(GPIO_RegDef_t *pGPIO, uint8_t PinNumber);

/**
  * @brief  Configures a GPIO Pin for interrupts
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  pITConfig: A structure that holds information about IT related
  *         settings for a GPIO Pin.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @retval None
  */
void GPIO_PinITConfig(GPIO_RegDef_t *pGPIO, GPIO_PinITConfig_t *pITConfig, uint8_t PinNumber);

/**
  * @brief  Enables or Disables a GPIO to send interrupts to the NVIC
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_IRQConfig(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command);

/**
  * @brief  Clears an interrupt after it has occured 
  *         (usually called early within an ISR) for a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @retval None
  */
void GPIO_PinClearIT(GPIO_RegDef_t *pGPIO, uint8_t PinNumber);

/**
  * @brief  Clears an interrupt after it has occured 
  *         (usually called within an ISR) for a GPIO Port
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @retval None
  */
void GPIO_PortClearIT(GPIO_RegDef_t *pGPIO);

/**
  * @brief  Checks the interrupt status register of a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @retval SET if interrupt ocurred, else RESET
  */
uint8_t GPIO_PinReadITStatus(GPIO_RegDef_t *pGPIO, uint8_t PinNumber);

/**
  * @brief  Checks the interrupt status register of a GPIO Port
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @retval Returns the contents of the interrupt status register
            Thus Bit {i} is set iff Pin {i} issued an interrupt.
            Bit 8 corresponds to DMA
  */
uint16_t GPIO_PortReadITStatus(GPIO_RegDef_t *pGPIO);

/**
  * @brief  Sets the direction of a GPIO Port
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  Dir: Value from @GPIO_PinDir
  * @retval None
  */
void GPIO_PinSetDir(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Dir);

/**
  * @brief  Configures the Interrupt Sense Register
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  PinSense: Value from @GPIO_PinSense
  * @retval None
  */
void GPIO_PinSetITSense(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t PinSense);

/**
  * @brief  Configures the Interrupt Edge Register
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  PinEdge: Value from @GPIO_PinEdge
  * @retval None
  */
void GPIO_PinSetEdge(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t PinEdge);

/**
  * @brief  Configures the Digital Enable Register
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PinSetDen(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command);

/**
  * @brief  Configures the Analog Mode of a GPIO Pin
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PinSetAnalog(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command);

/**
  * @brief  Configures the ADC Control Register
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PinSetADCControl(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command);

/**
  * @brief  Configures the DMA Control Register
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void GPIO_PinSetDMAControl(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command);

/**
  * @brief  Unlocks and Enables Changes in GPIOAFSEL, GPIOPUR, GPIOPDR and
  *         GPIODEN. Note: Only useful for NMI and JTAG/SWD Pins
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @retval None
  */
void GPIO_PinUnlockAndCommit(GPIO_RegDef_t *pGPIO, uint8_t PinNumber);

/**
  * @brief  Locks a GPIO Register
  *         Note: Only available for NMI and JTAG/SWD Pins
  * @param  pGPIO: GPIOx where x can be (A ... Q) except I or O.
  * @param  PinNumber: Value from @GPIO_PinNumber
  * @retval None
  */
void GPIO_Lock(GPIO_RegDef_t *pGPIO, uint8_t PinNumber);

 #endif // __TM4C1294NCPDT_GPIO_H__
