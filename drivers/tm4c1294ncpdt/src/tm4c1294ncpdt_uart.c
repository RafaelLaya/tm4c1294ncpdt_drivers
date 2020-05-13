/*
 * Rafael Laya
 * 1975274
 * April 25th, 2020
 * Drivers for the general purpose timers of the tm4c1294ncpdt board
 */

#include "tm4c1294ncpdt_uart.h"


void UART_SendPacket(UART_RegDef_t *pUART, uint8_t Data) {
    pUART->DR = Data;
}

uint16_t UART_ReadPacket(UART_RegDef_t *pUART) {
    return pUART->DR;
}

void UART_ClearRecvErrorAll(UART_RegDef_t *pUART) {
    pUART->RSR_ECR |= 0xFU;
}

uint8_t UART_ReadError(UART_RegDef_t *pUART, uint8_t Error) {
    return (pUART->RSR_ECR >> Error) & 0x1U;
}

uint8_t UART_ReadStatus(UART_RegDef_t *pUART, uint8_t Flag) {
    return (pUART->FR >> Flag) & 0x1U;
}

void __UART_SetBaudRateIntegerDivisor(UART_RegDef_t *pUART, uint16_t IntegerDivisor) {
    pUART->IBRD = (pUART->IBRD & ~0xFFFFU) | IntegerDivisor;
}

void __UART_SetBaudRateFractionDivisor(UART_RegDef_t *pUART, uint8_t FractionDivisor) {
    pUART->FBRD = (pUART->FBRD & ~0x1FU) | FractionDivisor;
}

void UART_ConfigParity(UART_RegDef_t *pUART, uint8_t Parity) {
    if (Parity == UART_Parity_Disabled) {
        pUART->LCRH &= ~(SET << UART_LCRH_PEN_POS);
    } else if(Parity == UART_Parity_Even) {
        pUART->LCRH &= ~(SET << UART_LCRH_SPS_POS);
        pUART->LCRH |= (SET << UART_LCRH_EPS_POS);
        pUART->LCRH |= (SET << UART_LCRH_PEN_POS);
    } else if(Parity == UART_Parity_Odd) {
        pUART->LCRH &= ~(SET << UART_LCRH_SPS_POS);
        pUART->LCRH &= ~(SET << UART_LCRH_EPS_POS);
        pUART->LCRH |= (SET << UART_LCRH_PEN_POS);
    } else if(Parity == UART_Parity_Stick0) {
        pUART->LCRH |= (SET << UART_LCRH_SPS_POS);
        pUART->LCRH |= (SET << UART_LCRH_EPS_POS);
        pUART->LCRH |= (SET << UART_LCRH_PEN_POS);
    } else if(Parity == UART_Parity_Stick1) {
        pUART->LCRH |= (SET << UART_LCRH_SPS_POS);
        pUART->LCRH &= ~(SET << UART_LCRH_EPS_POS);
        pUART->LCRH |= (SET << UART_LCRH_PEN_POS);
    }
}

void UART_ConfigWordLength(UART_RegDef_t *pUART, uint8_t Len) {
    pUART->LCRH = (pUART->LCRH & ~(UART_LCRH_WLEN_MASK)) | (Len << UART_LCRH_WLEN_POS);
}

void UART_ConfigFifo(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->LCRH |= (SET << UART_LCRH_FEN_POS);
    } else {
        pUART->LCRH &= ~(SET << UART_LCRH_FEN_POS);
    }
}

void UART_ConfigStop(UART_RegDef_t *pUART, uint8_t StopLength) {
    if(StopLength == UART_StopLen_2) {
        pUART->LCRH |= (SET << UART_LCRH_STP2_POS);
    } else {
        pUART->LCRH &= ~(SET << UART_LCRH_STP2_POS);
    }
}

void UART_ConfigBreak(UART_RegDef_t *pUART, uint8_t Command) {
    pUART->LCRH = (pUART->LCRH & ~SET) | Command;
}

void UART_ConfigHardwareCTS(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= (SET << UART_CTL_CTSEN_POS);
    } else {
        pUART->CTL &= ~(SET << UART_CTL_CTSEN_POS);
    }
}

void UART_ConfigHardwareRTS(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= (SET << UART_CTL_RTSEN_POS);
    } else {
        pUART->CTL &= ~(SET << UART_CTL_RTSEN_POS);
    }
}

void UART_RequestToSend(UART_RegDef_t *pUART, uint8_t Value) {
    pUART->CTL = (pUART->CTL & ~(SET << UART_CTL_RTS_POS)) | (Value << UART_CTL_RTS_POS);
}

void UART_DataTerminalReady(UART_RegDef_t *pUART, uint8_t Value) {
    pUART->CTL = (pUART->CTL & ~(SET << UART_CTL_DTR_POS)) | (Value << UART_CTL_DTR_POS);
}

void UART_RxCommand(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= SET << UART_CTL_RXE_POS;
    } else {
        pUART->CTL &= ~(SET << UART_CTL_RXE_POS);
    }
}

void UART_TxCommand(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= SET << UART_CTL_TXE_POS;
    } else {
        pUART->CTL &= ~(SET << UART_CTL_TXE_POS);
    }
}

void UART_Command(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= SET << UART_CTL_UARTEN_POS;
    } else {
        pUART->CTL &= ~(SET << UART_CTL_UARTEN_POS);
    }
}

void UART_ConfigLoopBack(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= SET << UART_CTL_LBE_POS;
    } else {
        pUART->CTL &= ~(SET << UART_CTL_LBE_POS);
    }
}

void UART_ConfigHighSpeed(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= SET << UART_CTL_HSE_POS;
    } else {
        pUART->CTL &= ~(SET << UART_CTL_HSE_POS);
    }
}

void UART_ConfigEOT(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        pUART->CTL |= SET << UART_CTL_EOT_POS;
    } else {
        pUART->CTL &= ~(SET << UART_CTL_EOT_POS);
    }
}

void UART_ConfigRxTriggerLevel(UART_RegDef_t *pUART, uint8_t RxLevel) {
    pUART->IFLS = (pUART->IFLS & ~(UART_IFLS_RXIFLSEL_MASK)) | (RxLevel << UART_IFLS_RXIFLSEL_POS);
}

void UART_ConfigTxTriggerLevel(UART_RegDef_t *pUART, uint8_t TxLevel) {
    pUART->IFLS = (pUART->IFLS & ~(UART_IFLS_TXIFLSEL_MASK)) | (TxLevel << UART_IFLS_TXIFLSEL_POS);
}

void UART_ConfigSmartCard(UART_RegDef_t *pUART, uint8_t Command) {
    if(Command == ENABLE) {
        // Stop bits are forced to 2
        UART_ConfigStop(pUART, UART_StopLen_2);

        // High speed is off
        UART_ConfigHighSpeed(pUART, DISABLE);

        // Word length must be 8 bits
        UART_ConfigWordLength(pUART, UART_WordLen_8);

        // Set IrDA Off
        UART_ConfigIrDA(pUART, DISABLE, 0U, 0U);

        // Enable SmartCard
        pUART->CTL |= (SET << UART_CTL_SMART_POS);
    } else {
        pUART->CTL &= ~(SET << UART_CTL_SMART_POS);
    }
}

void UART_IRQConfig(UART_RegDef_t *pUART, uint8_t Command, uint32_t IRQConfig) {
    if(Command == ENABLE) {
        pUART->IM |= IRQConfig;
    } else {
        pUART->IM &= ~(IRQConfig);
    }
}

uint8_t UART_ReadRawIT(UART_RegDef_t *pUART, uint8_t Pos) {
    return (pUART->RIS >> Pos) & SET;
}

uint8_t UART_ReadITStatus(UART_RegDef_t *pUART, uint8_t Pos) {
    return (pUART->MIS >> Pos) & SET;
}

void UART_ClearIT(UART_RegDef_t *pUART, uint8_t Pos) {
    pUART->ICR |= (SET << Pos);
}

void UART_ClearITByMask(UART_RegDef_t *pUART, uint32_t Mask) {
    pUART->ICR |= Mask;
}

void UART_Config9BitMode(UART_RegDef_t *pUART, uint8_t Command, uint8_t Addr, uint8_t Mask) {
    if(Command != ENABLE) {
        pUART->BITADDR9 &= ~(SET << UART_9BITADDR_9BITEN_POS);
        return;
    } 

    pUART->BITADDR9 |= (SET << UART_9BITADDR_9BITEN_POS);
    
    pUART->BITADDR9 = (pUART->BITADDR9 & ~(UART_9BITADDR_MASK)) | (Addr);
    pUART->BITAMASK9 = (pUART->BITAMASK9 & ~(UART_9BITAMASK_MASK)) | (Mask);
}

void UART_ConfigDMA(UART_RegDef_t *pUART, uint8_t Command, uint8_t Mask) {
    if(Command == ENABLE) {
        pUART->DMACTL |= Mask;
    } else {
        pUART->DMACTL &= ~(Mask);
    }
}

void UART_ConfigIrDA(UART_RegDef_t *pUART, uint8_t Command, uint8_t LowPowerCommand, uint8_t Divisor) {
    if(Command == DISABLE) {
        pUART->CTL &= ~(SET << UART_CTL_SIREN_POS);
        return;
    } 

    // Disable SmartCard
    UART_ConfigSmartCard(pUART, DISABLE);

    // Configure IrDA
    pUART->CTL |= (SET << UART_CTL_SIREN_POS);
    
    if(LowPowerCommand == ENABLE) {
        pUART->CTL |= (SET << UART_CTL_SIRLP_POS);
    } else {
        pUART->CTL &= ~(SET << UART_CTL_SIRLP_POS);
        pUART->ILPR = (pUART->ILPR & ~(UART_ILPR_MASK)) | Divisor;
    }
}

void UART_ConfigClockSource(UART_RegDef_t *pUART, uint8_t ClockSource) {
    pUART->CC = (pUART->CC & ~(UART_CC_CS_MASK)) | ClockSource;
}

void UART_SetBaudRate(UART_RegDef_t *pUART, uint32_t BaudRate, uint32_t ClockFreq, uint8_t HighSpeed) {
    // Save LCRH in order to make a dummy write,
    // This updates the baud rate settings
    uint32_t tempreg = pUART->LCRH;

    UART_ConfigHighSpeed(pUART, HighSpeed);

    // uint32_t Can overflow when multiplying by 10000U
    uint64_t BRDivisor = ClockFreq;
    
    // Divide by 16 if on High-speed mode. Otherwise divide by 8
    if(HighSpeed == RESET) {
        BRDivisor = BRDivisor >> 4U;
    } else {
        BRDivisor = BRDivisor >> 3U;
    }

    // Avoids floating point arithmetic
    BRDivisor = (BRDivisor * 10000U) / BaudRate;

    // But introduces some heavy integer arithmetic
    uint16_t BRInteger = BRDivisor / 10000U;
    uint8_t BRFraction = ((((BRDivisor % 10000U) << 6U) / 1000U) + 5U) / 10U;

    __UART_SetBaudRateIntegerDivisor(pUART, BRInteger);
    __UART_SetBaudRateFractionDivisor(pUART, BRFraction);

    // Dummy write
    pUART->LCRH = tempreg;
}

void UART_Config(UART_RegDef_t *pUART, UART_Config_t *pConfig) {
    // Make sure the UART is disabled
    UART_Command(pUART, DISABLE);

    // Configure Baud Rate
    UART_SetBaudRate(pUART, pConfig->BaudRate, pConfig->ClockFreq, pConfig->HighSpeedCommand);

    // Write LCRH
    UART_ConfigParity(pUART, pConfig->Parity);
    UART_ConfigWordLength(pUART, pConfig->WordLen);
    UART_ConfigStop(pUART, pConfig->StopBits);
    UART_ConfigFifo(pUART, pConfig->FifoCommand);
    UART_ConfigBreak(pUART, pConfig->BreakCommand);
   
    // Write to CTL
    UART_ConfigLoopBack(pUART, pConfig->LoopbackCommand);
    UART_ConfigHardwareRTS(pUART, pConfig->HardwareRTS);
    UART_ConfigHardwareCTS(pUART, pConfig->HardwareCTS);

    // Config Clock Source
    UART_ConfigClockSource(pUART, pConfig->ClockSource);
}

void UART_SendData(UART_RegDef_t *pUART, uint8_t *pData, uint32_t DataLen) {
    UART_TxCommand(pUART, ENABLE);

    for (uint32_t index = 0; index < DataLen; index++) {
        while((UART_ReadStatus(pUART, UART_StatusFlag_TxFifoFull)));
        UART_SendPacket(pUART, *pData);
        pData++;
    }

    while(!(UART_ReadStatus(pUART, UART_StatusFlag_TxFifoEmpty)));
    while(UART_ReadStatus(pUART, UART_StatusFlag_Busy));

    UART_TxCommand(pUART, DISABLE);  
}

void UART_ReceiveDataSimple(UART_RegDef_t *pUART, uint8_t *pData, uint32_t DataLen) {
    UART_RxCommand(pUART, ENABLE);

    for (uint32_t index = 0; index < DataLen; index++) {
        while((UART_ReadStatus(pUART, UART_StatusFlag_RxFifoEmpty)));
        *pData = UART_PACKET_EXTRACT_DATA(UART_ReadPacket(pUART));
        pData++;
    }
    UART_RxCommand(pUART, DISABLE);
    return;
}

UART_RcvPolling_t UART_ReceiveData(UART_RegDef_t *pUART, uint8_t *pData, uint32_t DataLen) {
    UART_RcvPolling_t Status;

    UART_RxCommand(pUART, ENABLE);

    for (uint32_t index = 0; index < DataLen; index++) {
        while((UART_ReadStatus(pUART, UART_StatusFlag_RxFifoEmpty)));
        uint16_t packet = UART_ReadPacket(pUART);

        if (UART_PACKET_EXTRACT_BREAK_ERR(packet)) {
            Status.DataLen = DataLen - index;
            Status.pData = pData;
            Status.Status = UART_PollingRcvStatus_BreakErr;
            return Status;
        } else if (UART_PACKET_EXTRACT_PARITY_ERR(packet)) {
            Status.DataLen = DataLen - index;
            Status.pData = pData;
            Status.Status = UART_PollingRcvStatus_ParityErr;
            return Status;
        } else if (UART_PACKET_EXTRACT_FRAMING_ERR(packet)) {
            Status.DataLen = DataLen - index;
            Status.pData = pData;
            Status.Status = UART_PollingRcvStatus_FramingErr;
            return Status;
        } else if(UART_PACKET_EXTRACT_OVERRUN_ERR(packet)) {
            Status.DataLen = DataLen - index;
            Status.pData = pData;
            Status.Status = UART_PollingRcvStatus_OverrunErr;
            return Status;
        }

        *pData = UART_PACKET_EXTRACT_DATA(packet);
        pData++;
    }

    Status.DataLen = 0;
    Status.pData = pData;
    Status.Status = UART_PollingRcvStatus_Success;
    UART_RxCommand(pUART, DISABLE);
    return Status;
}

IRQNumber_type UART_GetIRQNumber(UART_RegDef_t *pUART) {
    if(pUART == UART0) {
        return UART0_IRQNumber;
    } else if (pUART == UART1) {
        return UART1_IRQNumber;
    } else if (pUART == UART2) {
        return UART2_IRQNumber;
    } else if (pUART == UART3) {
        return UART3_IRQNumber;
    } else if (pUART == UART4) {
        return UART4_IRQNumber;
    } else if (pUART == UART5) {
        return UART5_IRQNumber;
    } else if (pUART == UART6) {
        return UART6_IRQNumber;
    } else {
        return UART7_IRQNumber;
    }
}

 uint8_t UART_SendDataIT(UART_Handle_t *pHandle, uint8_t *pData, uint32_t DataLen) {
     if(pHandle->TxBuffer.Status == UART_MSGStatus_BUSY) {
         return UART_MSGStatus_BUSY;
     } else if (DataLen == 0) {
         return UART_MSGStatus_READY;
     }

    UART_ConfigFifo(pHandle->pUART, DISABLE);
    pHandle->TxBuffer.DataLen = DataLen;
    pHandle->TxBuffer.pData = pData;
    pHandle->TxBuffer.Status = UART_MSGStatus_BUSY;

    UART_Command(pHandle->pUART, ENABLE);
    UART_TxCommand(pHandle->pUART, ENABLE);
    UART_IRQConfig(pHandle->pUART, ENABLE, UART_IRQConfig_Transmit);

    __asm volatile("cpsid i\t\n");
    UART_SendPacket(pHandle->pUART, *(pHandle->TxBuffer.pData));
    pHandle->TxBuffer.pData++;
    pHandle->TxBuffer.DataLen--;

    NVIC_EnableIRQ(UART_GetIRQNumber(pHandle->pUART));
    __asm volatile("cpsie i\t\n");
    return UART_MSGStatus_READY;
}

 void UART_ITHandleMSG(UART_Handle_t *pHandle) {
    uint32_t temp = pHandle->pUART->MIS;

    if((temp >> UART_ReadITPos_Transmit) & SET) {
        UART_ClearIT(pHandle->pUART, UART_ReadITPos_Transmit);
        if(pHandle->TxBuffer.DataLen > 0U) {
            UART_SendPacket(pHandle->pUART, *(pHandle->TxBuffer.pData));
            pHandle->TxBuffer.pData++;
            pHandle->TxBuffer.DataLen--;
        } else {
            UART_IRQConfig(pHandle->pUART, DISABLE, UART_IRQConfig_Transmit);
            pHandle->TxBuffer.Status = UART_MSGStatus_READY;
            UART_TxMSGCallback(pHandle, UART_TxCallbackEvents_Finished);
        }
    }

    if((temp >> UART_ReadITPos_Receive) & SET) {
        UART_ClearIT(pHandle->pUART, UART_ReadITPos_Receive);

        if(pHandle->RxBuffer.DataLen > 0) {
            *(pHandle->RxBuffer.pData) = UART_PACKET_EXTRACT_DATA(UART_ReadPacket(pHandle->pUART));
            pHandle->RxBuffer.pData++;
            pHandle->RxBuffer.DataLen--;
        }

        if(pHandle->RxBuffer.DataLen == 0) {
            UART_IRQConfig(pHandle->pUART, DISABLE, UART_IRQConfig_Receive);
            pHandle->RxBuffer.Status = UART_MSGStatus_READY;
            UART_RxMSGCallback(pHandle, UART_RxCallbackEvents_Finished);
        }
    }
 }

 __weak void UART_TxMSGCallback(UART_Handle_t *pHandle, uint8_t Event) {

 }

uint8_t UART_ReceiveDataIT(UART_Handle_t *pHandle, uint8_t *pData, uint32_t DataLen) {
     if (pHandle->RxBuffer.Status == UART_MSGStatus_BUSY) {
         return UART_MSGStatus_BUSY;
     } else if(DataLen == 0) {
         return UART_MSGStatus_READY;
     }

    UART_ConfigFifo(pHandle->pUART, DISABLE);
    pHandle->RxBuffer.DataLen = DataLen;
    pHandle->RxBuffer.pData = pData;
    pHandle->RxBuffer.Status = UART_MSGStatus_BUSY;

    UART_Command(pHandle->pUART, ENABLE);
    UART_RxCommand(pHandle->pUART, ENABLE);
    UART_IRQConfig(pHandle->pUART, ENABLE, UART_IRQConfig_Receive);
    NVIC_EnableIRQ(UART_GetIRQNumber(pHandle->pUART));

    return UART_MSGStatus_READY;
}

 __weak void UART_RxMSGCallback(UART_Handle_t *pHandle, uint8_t Event) {

 }