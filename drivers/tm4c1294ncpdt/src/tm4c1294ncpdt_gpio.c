/*
 * Rafael Laya
 * 1975274
 * April 16th, 2020
 * GPIO Drivers for tm4c1294ncpdt
 */

#include "tm4c1294ncpdt_gpio.h"

void GPIO_PeriphClockCtrlByMask(uint32_t mask, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(IS_COMMAND(Command));
    assert(SYSCTL_IS_GPIO_MASK(mask));
    #endif 

    SYSCTL_RCGCGPIO_CMD(mask, Command);
}

void GPIO_PeriphClockCtrl(GPIO_RegDef_t *pGPIO, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(IS_COMMAND(Command));
    #endif

    if (pGPIO == GPIOA) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTA_MASK, Command);
    } else if (pGPIO == GPIOB) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTB_MASK, Command);
    } else if (pGPIO == GPIOC) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTC_MASK, Command);
    } else if (pGPIO == GPIOD) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTD_MASK, Command);
    } else if (pGPIO == GPIOE) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTE_MASK, Command);
    } else if (pGPIO == GPIOF) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTF_MASK, Command);
    } else if (pGPIO == GPIOG) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTG_MASK, Command);
    } else if (pGPIO == GPIOH) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTH_MASK, Command);
    } else if (pGPIO == GPIOJ) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTJ_MASK, Command);
    } else if (pGPIO == GPIOK) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTK_MASK, Command);
    } else if (pGPIO == GPIOL) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTL_MASK, Command);
    } else if (pGPIO == GPIOM) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTM_MASK, Command);
    } else if (pGPIO == GPION) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTN_MASK, Command);
    } else if (pGPIO == GPIOP) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTP_MASK, Command);
    } else if (pGPIO == GPIOQ) {
        SYSCTL_RCGCGPIO_CMD(SYSCTL_RCGCGPIO_PORTQ_MASK, Command);
    } else {

    }
}

void GPIO_Init(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, GPIO_InitDef_t *pGPIOInit) {
    GPIO_PinSetMode(pGPIO,
                    PinNumber,
                    pGPIOInit->GPIO_PinConfig.GPIO_PinMode);
    GPIO_PinSetPuPd(pGPIO,
                    PinNumber,
                    pGPIOInit->GPIO_PinConfig.GPIO_PinPuPdControl);

    if (pGPIOInit->ConfigIT == ENABLE) {
        GPIO_PinITConfig(pGPIO,
                        (GPIO_PinITConfig_t *) (&(pGPIOInit->GPIO_PinITConfig)),
                        PinNumber);
    } 
}

void GPIO_PinAFConfig(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t AltFunc, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_PIN_AF_MODE(AltFunc));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_GPIO(pGPIO));
    assert(IS_COMMAND(Command));
    #endif

    uint32_t tempreg = pGPIO->PCTL;
    tempreg &= ~(0xFU << (PinNumber << 2));
    tempreg |= (AltFunc << (PinNumber << 2));
    pGPIO->PCTL = tempreg;

    if (Command == ENABLE) {
        pGPIO->AFSEL |= (0x1 << PinNumber);
    }
}

void GPIO_PinSetMode(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Mode) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_PIN_MODE(Mode));
    #endif

    if (Mode != GPIO_PinMode_ANALOG && Mode != GPIO_PinMode_ALTFN_ANALOG) {
        // Config as digital
        GPIO_PinSetDen(pGPIO, PinNumber, ENABLE);

        // Either Digital input, output, or an alternate function
        if (Mode == GPIO_PinMode_IN) {
            GPIO_PinSetDir(pGPIO, PinNumber, GPIO_PinDir_IN);
        } else if (Mode == GPIO_PinMode_OUT) {
            GPIO_PinSetDir(pGPIO, PinNumber, GPIO_PinDir_OUT);
        } else {
            GPIO_PinAFConfig(pGPIO, PinNumber, Mode, ENABLE);
        }
    } else {
        // Config as analog, or analog with alternate functionality
        if (Mode == GPIO_PinMode_ALTFN_ANALOG) {
            GPIO_PinAFConfig(pGPIO, PinNumber, 0x0U, ENABLE);
        } else {
            GPIO_PinAFConfig(pGPIO, PinNumber, 0x0U, DISABLE);
        }
        
        GPIO_PinSetAnalog(pGPIO, PinNumber, ENABLE);
    }
}

void GPIO_PinSetPuPd(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t PuPd) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_PIN_PUPD_CTRL(PuPd));
    #endif 

    pGPIO->PUR &= ~(0x1 << PinNumber);
    pGPIO->PDR &= ~(0x1 << PinNumber);
    pGPIO->ODR &= ~(0x1 << PinNumber);
    if(PuPd == GPIO_PinPuPdControl_PULLUP) {
        pGPIO->PUR |= (0x1 << PinNumber);
    } else if (PuPd == GPIO_PinPuPdControl_PULLDOWN) {
        pGPIO->PDR |= (0x1 << PinNumber);
    } else if (PuPd == GPIO_PinPuPdControl_OPENDRAIN) {
        pGPIO->ODR |= (0x1 << PinNumber);
    }
}

uint8_t GPIO_PinRead(GPIO_RegDef_t *pGPIO, uint8_t PinNumber) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    #endif 
    return (pGPIO->PINS >> PinNumber) & 0x1;
}

uint8_t GPIO_PortRead(GPIO_RegDef_t *pGPIO) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    #endif 
    return pGPIO->PINS & 0xFFU;
}

void GPIO_PinWrite(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Value) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_PIN_VAL(Value));
    #endif 

    if (Value == SET) {
        pGPIO->PINS |= (0x1 << PinNumber);
    } else {
        pGPIO->PINS &= ~(0x1 << PinNumber);
    }
}

void GPIO_PortWrite(GPIO_RegDef_t *pGPIO, uint8_t Value) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_VAL(Value));
    #endif 
    pGPIO->PINS = Value;
}

void GPIO_PinToggle(GPIO_RegDef_t *pGPIO, uint8_t PinNumber) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    #endif 

    pGPIO->PINS ^= (0x1 << PinNumber);
}

void GPIO_PinITConfig(GPIO_RegDef_t *pGPIO, GPIO_PinITConfig_t *pITConfig, uint8_t PinNumber) {
    GPIO_PinSetEdge(pGPIO, PinNumber, pITConfig->GPIO_PinEdge);
    GPIO_PinSetITSense(pGPIO, PinNumber, pITConfig->GPIO_PinSense);
}

void GPIO_IRQConfig(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(IS_COMMAND(Command));
    #endif 
    if (Command == ENABLE) {
        pGPIO->IM |= (0x1 << PinNumber);
    } else {
        pGPIO->IM &= ~(0x1 << PinNumber);
    }
}

void GPIO_PinClearIT(GPIO_RegDef_t *pGPIO, uint8_t PinNumber) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    #endif 
    pGPIO->ICR |= (0x1 << PinNumber);
}

void GPIO_PortClearIT(GPIO_RegDef_t *pGPIO) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    #endif 
    pGPIO->ICR |= 0x1FFU;
}

uint8_t GPIO_PinReadITStatus(GPIO_RegDef_t *pGPIO, uint8_t PinNumber) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    #endif 
    return (pGPIO->MIS >> PinNumber) & 0x1U;
}

uint16_t GPIO_PortReadITStatus(GPIO_RegDef_t *pGPIO) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    #endif 
    return pGPIO->MIS & 0x1FF;
}

void GPIO_PinSetDir(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Dir) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_PIN_DIR(Dir));
    #endif 
    if (Dir == GPIO_PinDir_OUT) {
        pGPIO->DIR |= (0x1 << PinNumber);
    } else {
        pGPIO->DIR &= ~(0x1 << PinNumber);
    }
}

void GPIO_PinSetITSense(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t PinSense) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_PINSENSE(PinSense));
    #endif 
    if (PinSense == GPIO_PinSense_EDGE) {
        pGPIO->IS &= ~(0x1 << PinNumber);
    } else {
        pGPIO->IS |= (0x1 << PinNumber);
    }
}

void GPIO_PinSetEdge(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t PinEdge) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(GPIO_IS_PINEDGE(PinEdge));
    #endif 
    if (PinEdge == GPIO_PinEdge_BOTH) {
        pGPIO->IBE |= (0x1 << PinNumber);
    } if (PinEdge == GPIO_PinEdge_LOW) {
        pGPIO->IBE &= ~(0x1 << PinNumber);
        pGPIO->IEV &= ~(0x1 << PinNumber);
    } else {
        pGPIO->IBE &= ~(0x1 << PinNumber);
        pGPIO->IEV |= (0x1 << PinNumber);
    }
}

void GPIO_PinSetDen(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(IS_COMMAND(Command));
    #endif 

    if (Command == ENABLE) {
        // Clear analog mode if configuring as digital
        pGPIO->AMSEL &= ~(0x1 << PinNumber);
        pGPIO->DEN |= (0x1 << PinNumber);
    } else {
        pGPIO->DEN &= ~(0x1 << PinNumber);
    }
}

void GPIO_PinSetAnalog(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(IS_COMMAND(Command));
    #endif 

    if (Command == ENABLE) {
        // Clear digital if configuring as analog
        pGPIO->DEN &= ~(0x1 << PinNumber);
        pGPIO->AMSEL |= (0x1 << PinNumber);
    } else {
        pGPIO->AMSEL &= ~(0x1 << PinNumber);
    }
}

void GPIO_PinSetADCControl(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(IS_COMMAND(Command));
    #endif 

    if (Command == ENABLE) {
        pGPIO->ADCCTL |= (0x1 << PinNumber);
    } else {
        pGPIO->ADCCTL &= ~(0x1 << PinNumber);
    }
}

void GPIO_PinSetDMAControl(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    assert(IS_COMMAND(Command));
    #endif

    if (Command == ENABLE) {
        pGPIO->DMACTL |= (0x1 << PinNumber);
    } else {
        pGPIO->DMACTL &= ~(0x1 << PinNumber);
    }
}

void GPIO_PinUnlockAndCommit(GPIO_RegDef_t *pGPIO, uint8_t PinNumber) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    #endif 
    pGPIO->LOCK = 0x4C4F434B;
    pGPIO->CR |= 0x1 << PinNumber;
}

void GPIO_Lock(GPIO_RegDef_t *pGPIO, uint8_t PinNumber) {
    #if ASSERT_ENABLED
    assert(GPIO_IS_GPIO(pGPIO));
    assert(GPIO_IS_PIN_NUMBER(PinNumber));
    #endif 
    pGPIO->CR &= ~(0x1 << PinNumber);
    pGPIO->LOCK = DISABLE;
}
