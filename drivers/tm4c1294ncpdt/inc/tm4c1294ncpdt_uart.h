/*
 * Rafael Laya
 * 1975274
 * April 25th, 2020
 * Contains definitions for tm4c1294ncpdt_uart.h
 */

#ifndef __TM4C1294NCPDT_UART_H__
#define __TM4C1294NCPDT_UART_H__

#include "tm4c1294ncpdt.h"

typedef struct {
  uint32_t DataLen;                 
  uint8_t *pData;   
  uint8_t Status;                   /* Value from @UART_PollingStatus */
} UART_RcvPolling_t;

typedef struct {
  uint32_t ClockFreq;               /* Frequency of the UART Clock in Hz */ 
  uint32_t BaudRate;                /* Desired Baud Rate in Hz */
  uint8_t HighSpeedCommand;         /* ENABLE or DISABLE */
  uint8_t Parity;                   /* Value from @UART_Parity */
  uint8_t WordLen;                  /* Value from @UART_WordLen */
  uint8_t StopBits;                 /* Value from @UART_StopLen */
  uint8_t BreakCommand;             /* ENABLE or DISABLE */
  uint8_t HardwareCTS;              /* ENABLE or DISABLE */
  uint8_t HardwareRTS;              /* ENABLE or DISABLE */
  uint8_t LoopbackCommand;          /* ENABLE or DISABLE */
  uint8_t FifoCommand;              /* ENABLE or DISABLE */
  uint8_t ClockSource;              /* Value from @UART_ClockSource */
} UART_Config_t;

typedef struct {
  uint8_t *pData;
  uint32_t DataLen;
  uint8_t Status;                   /* Value from @UART_MSGStatus */
} UART_Buffer_t;

typedef struct {
  UART_RegDef_t *pUART;
  UART_Buffer_t TxBuffer;
  UART_Buffer_t RxBuffer;
} UART_Handle_t;

/* @UART_MSGStatus */
#define UART_MSGStatus_BUSY                 1U
#define UART_MSGStatus_READY                2U

/* @UART_TxCallbackEvents */
#define UART_TxCallbackEvents_Finished        1U

/* @UART_RxCallbackEvents */
#define UART_RxCallbackEvents_Finished          1U
#define UART_RxCallbackEvents_OverrunErr        2U
#define UART_RxCallbackEvents_FramingErr        3U
#define UART_RxCallbackEvents_BreakErr          4U
#define UART_RxCallbackEvents_ParityErr         5U

/* @UART_PollingStatus */
#define UART_PollingRcvStatus_Success         0x1U
#define UART_PollingRcvStatus_OverrunErr      0x2U
#define UART_PollingRcvStatus_FramingErr      0x3U
#define UART_PollingRcvStatus_BreakErr        0x4U
#define UART_PollingRcvStatus_ParityErr       0x5U

/* @UART_ClockSource */
#define UART_ClockSource_SYSCLK               0x0U
#define UART_ClockSource_ALTCLK               0x5U

/* @UART_DMA */
#define UART_DMA_Enable                       0x1U
#define UART_DMA_Transmit                     0x2U
#define UART_DMA_Error                        0x4U

/* @UART_ITReadPos */
#define UART_ReadITPos_TransmitDMA            17U
#define UART_ReadITPos_ReceiveDMA             16U
#define UART_ReadITPos_9BitMode               12U
#define UART_ReadITPos_EndOfTransmission      11U
#define UART_ReadITPos_OverrunError           10U
#define UART_ReadITPos_BreakError             9U
#define UART_ReadITPos_ParityError            8U
#define UART_ReadITPos_FramingError           7U
#define UART_ReadITPos_ReceiveTimeout         6U
#define UART_ReadITPos_Transmit               5U
#define UART_ReadITPos_Receive                4U
#define UART_ReadITPos_DataSetReady           3U
#define UART_ReadITPos_DataCarrierDetect      2U
#define UART_ReadITPos_ClearToSend            1U
#define UART_ReadITPos_RingIndicatir          0U

/* @UART_IRQConfig */
#define UART_IRQConfig_RingIndicator              0x1U
#define UART_IRQConfig_ClearToSend                0x2U
#define UART_IRQConfig_DataCarrierDetect          0x4U
#define UART_IRQConfig_DataSetReady               0x8U
#define UART_IRQConfig_Receive                    0x10U
#define UART_IRQConfig_Transmit                   0x20U
#define UART_IRQConfig_ReceiveTimeout             0x40U
#define UART_IRQConfig_FramingError               0x80U
#define UART_IRQConfig_ParityError                0x100U
#define UART_IRQConfig_BreakError                 0x200U
#define UART_IRQConfig_OverrunError               0x400U
#define UART_IRQConfig_EndOfTransmission          0x800U
#define UART_IRQConfig_9BitMode                   0x1000U
#define UART_IRQConfig_ReceiveDMA                 0x10000U
#define UART_IRQConfig_TransmitDMA                0x20000U
#define UART_IRQConfig_All                        0x31FFFU

/* @UART_ITMask */
#define UART_ITMask_RingIndicator              0x1U
#define UART_ITMask_ClearToSend                0x2U
#define UART_ITMask_DataCarrierDetect          0x4U
#define UART_ITMask_DataSetReady               0x8U
#define UART_ITMask_Receive                    0x10U
#define UART_ITMask_Transmit                   0x20U
#define UART_ITMask_ReceiveTimeout             0x40U
#define UART_ITMask_FramingError               0x80U
#define UART_ITMask_ParityError                0x100U
#define UART_ITMask_BreakError                 0x200U
#define UART_ITMask_OverrunError               0x400U
#define UART_ITMask_EndOfTransmission          0x800U
#define UART_ITMask_9BitMode                   0x1000U
#define UART_ITMask_ReceiveDMA                 0x10000U
#define UART_ITMask_TransmitDMA                0x20000U
#define UART_ITMask_All                        0x31FFFU

/* @UART_RxTriggerLevel */
#define UART_RxTriggerLevel_OneEight              0x0U
#define UART_RxTriggerLevel_OneQuarter            0x1U
#define UART_RxTriggerLevel_OneHalf               0x2U
#define UART_RxTriggerLevel_ThreeQuarters         0x3U
#define UART_RxTriggerLevel_SevenEights           0x4U

/* @UART_TxTriggerLevel */
#define UART_TxTriggerLevel_SevenEights         0x0U
#define UART_TxTriggerLevel_ThreeQuarters       0x1U
#define UART_TxTriggerLevel_OneHalf             0x2U
#define UART_TxTriggerLevel_OneQuarter          0x3U
#define UART_TxTriggerLevel_OneEight            0x4U

/* @UART_StopLen */
#define UART_StopLen_1          1U
#define UART_StopLen_2          2U

/* @UART_WordLen */
#define UART_WordLen_5          0x0U
#define UART_WordLen_6          0x1U
#define UART_WordLen_7          0x2U
#define UART_WordLen_8          0x3U

/* @UART_Parity */
#define UART_Parity_Even          1U
#define UART_Parity_Odd           2U
#define UART_Parity_Stick0        3U
#define UART_Parity_Stick1        4U
#define UART_Parity_Disabled      5U

/* @UART_Error */
#define UART_Error_Framing       0U
#define UART_Error_Parity        1U
#define UART_Error_Break         2U
#define UART_Error_Overrun       3U

/* @UART_StatusFlag */
#define UART_StatusFlag_Ring                    8U
#define UART_StatusFlag_TxFifoEmpty             7U
#define UART_StatusFlag_RxFifoFull              6U
#define UART_StatusFlag_TxFifoFull              5U
#define UART_StatusFlag_RxFifoEmpty             4U
#define UART_StatusFlag_Busy                    3U
#define UART_StatusFlag_DataCarrierDetect       2U
#define UART_StatusFlag_DataCarrierReady        1U
#define UART_StatusFlag_ClearToSend             0U         

/* @UART_DR */
#define UART_DR_OVERRUN_POS           11U
#define UART_DR_BREAK_POS             10U
#define UART_DR_PARITY_POS            9U
#define UART_DR_FRAMING_POS           8U

/* @UART_PACKET_EXTRACT */
#define UART_PACKET_EXTRACT_DATA(X)                 ((X) & 0xFFU)
#define UART_PACKET_EXTRACT_OVERRUN_ERR(X)          (((X) >> UART_DR_OVERRUN_POS) & SET)
#define UART_PACKET_EXTRACT_BREAK_ERR(X)            (((X) >> UART_DR_BREAK_POS) & SET)
#define UART_PACKET_EXTRACT_PARITY_ERR(X)           (((X) >> UART_DR_PARITY_POS) & SET)
#define UART_PACKET_EXTRACT_FRAMING_ERR(X)          (((X) >> UART_DR_FRAMING_POS) & SET)
#define UART_PACKET_EXTRACT_FLAGS_ERR(X)            (((X) >> UART_DR_FRAMING_POS) & 0xFU)

/* @UART_RSR/ECR */
#define UART_RSR_ECR_OVERRUN_POS          3U
#define UART_RSR_ECR_BREAK_POS            2U
#define UART_RSR_ECR_PARITY_POS           1U
#define UART_RSR_ECR_FRAMING_POS          0U

#define UART_ERROR_EXTRACT_OVERRUN_ERR            (((X) >> UART_RSR_ECR_OVERRUN_POS) & SET)
#define UART_ERROR_EXTRACT_BREAK_ERR              (((X) >> UART_RSR_ECR_BREAK_POS) & SET)
#define UART_ERROR_EXTRACT_PARITY_ERR             (((X) >> UART_RSR_ECR_PARITY_POS) & SET)
#define UART_ERROR_EXTRACT_FRAMING_ERR            (((X) >> UART_RSR_ECR_FRAMING_POS) & SET)

/* @UART_FR */
#define UART_FR_RI_POS              8U
#define UART_FR_TXFE_POS            7U
#define UART_FR_RXFF_POS            6U
#define UART_FR_TXFF_POS            5U
#define UART_FR_RXFE_POS            4U
#define UART_FR_BUSY_POS            3U
#define UART_FR_DCD_POS             2U
#define UART_FR_DSR_POS             1U
#define UART_FR_CTS_POS             0U

/* @UART_LCRH */
#define UART_LCRH_SPS_POS             7U
#define UART_LCRH_WLEN_POS            5U
#define UART_LCRH_FEN_POS             4U
#define UART_LCRH_STP2_POS            3U
#define UART_LCRH_EPS_POS             2U
#define UART_LCRH_PEN_POS             1U
#define UART_LCRH_BRK_POS             0U
#define UART_LCRH_WLEN_MASK           (0x3U << UART_LCRH_WLEN_POS)

/* @UART_CTL */
#define UART_CTL_CTSEN_POS          15U
#define UART_CTL_RTSEN_POS          14U
#define UART_CTL_RTS_POS            11U
#define UART_CTL_DTR_POS            10U
#define UART_CTL_RXE_POS            9U
#define UART_CTL_TXE_POS            8U
#define UART_CTL_LBE_POS            7U
#define UART_CTL_HSE_POS            5U
#define UART_CTL_EOT_POS            4U
#define UART_CTL_SMART_POS          3U
#define UART_CTL_SIRLP_POS          2U
#define UART_CTL_SIREN_POS          1U
#define UART_CTL_UARTEN_POS         0U

/* @UART_IFLS */
#define UART_IFLS_RXIFLSEL_POS      3U
#define UART_IFLS_TXIFLSEL_POS      0U
#define UART_IFLS_RXIFLSEL_MASK     (0x7U << UART_IFLS_RXIFLSEL_POS)
#define UART_IFLS_TXIFLSEL_MASK     0x7U

/* @UART_9BITADDR */
#define UART_9BITADDR_9BITEN_POS        15U
#define UART_9BITADDR_MASK              0xFFU

/* @UART_9BITAMASK */
#define UART_9BITAMASK_MASK             0xFFU

/* @UART_ILPR */
#define UART_ILPR_MASK                0xFFU

/* @UART_CC */
#define UART_CC_CS_MASK               0xFU                    

/**
  * @brief  Sends a packet through UART
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Data: Data to send
  * @retval None
  * @note   Hardware puts start, stop, and parity bits as configured. 
  *         User shall only provide the raw byte of data to send
  */
void UART_SendPacket(UART_RegDef_t *pUART, uint8_t Data);

/**
  * @brief  Reads a packet through UART
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @retval A packet, including data (bits [7:0]) and receive error flags (bits [11:8])
  * @note   Use Macros from @UART_PACKET_EXTRACT to extract information from a packet
  */
uint16_t UART_ReadPacket(UART_RegDef_t *pUART);


/**
  * @brief  Clears all receive error flags
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @retval none
  */
void UART_ClearRecvErrorAll(UART_RegDef_t *pUART);

/**
  * @brief  Reads a receive error flag
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Error: Value from @UART_Error
  * @retval SET if the error flag is SET, otherwise RESET
  * @note   This value corresponds to the latest value read from UART_ReadPacket
  *         or any read to the DR register done by the user
  */
uint8_t UART_ReadError(UART_RegDef_t *pUART, uint8_t Error);

/**
  * @brief  Reads a status flag
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Flag: Value from @UART_StatusFlag
  * @retval SET if the status flag is SET, otherwise RESET
  */
uint8_t UART_ReadStatus(UART_RegDef_t *pUART, uint8_t Flag);

/**
  * @brief  Sets the Baud Rate Integer Divisor
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  IntegerDivisor: Integer part of the divisor. 
  *         Divisor = UARTSysClk / (ClkDiv * Baud Rate)
  *         Where UARTSysClk is the frequency of the clock to the UART, 
  *         ClkDiv is 16 on Normal mode and 8 on high speed mode, and
  *         Baud Rate is the desired Baud Rate. IntegerDivisor is the 
  *         integer part of this calculation.
  * @retval none
  * @note   For automatic baud rate calculations, use UART_SetBaudRate()
  * @note   Requires a write to LCRH to update
  */
void __UART_SetBaudRateIntegerDivisor(UART_RegDef_t *pUART, uint16_t IntegerDivisor);

/**
  * @brief  Sets the Baud Rate Fractional Divisor
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  FractionDivisor: Fractional part of the divisor. 
  *         Divisor = UARTSysClk / (ClkDiv * Baud Rate)
  *         Where UARTSysClk is the frequency of the clock to the UART, 
  *         ClkDiv is 16 on Normal mode and 8 on high speed mode, and
  *         Baud Rate is the desired Baud Rate. Finally:
  *         FractionDivisor = Integer(Fraction(Divisor) * 64 + 0.5)
  * @retval none
  * @note   For automatic baud rate calculations, use UART_SetBaudRate()
  * @note   High Speed mode is not available for SmartCard mode
  * @note   Requires a write to LCRH to update
  */
void __UART_SetBaudRateFractionDivisor(UART_RegDef_t *pUART, uint8_t FractionDivisor);

/**
  * @brief  Sets the Baud Rate 
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  BaudRate: Desired Frequency in Hz
  * @param  ClockFreq: Clock Frequency of the given UART
  * @param  HighSpeed: SET if high speed enabled, otherwise RESET
  * @retval none
  * @note   The accuracy of the baud rate setting will depend on the accuracy of ClockFreq and
  *         HighSpeed supplied by the user. Failure to provide correct values will result in 
  *         incorrect baud rate settings
  * @note   High Speed mode is not available for SmartCard mode
  */
void UART_SetBaudRate(UART_RegDef_t *pUART, uint32_t BaudRate, uint32_t ClockFreq, uint8_t HighSpeed);

/**
  * @brief  Configures Parity
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Parity: Value from @UART_Parity
  * @retval none
  */
void UART_ConfigParity(UART_RegDef_t *pUART, uint8_t Parity);

/**
  * @brief  Configures Word Length
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Len: Value from @UART_WordLen
  * @retval none
  */
void UART_ConfigWordLength(UART_RegDef_t *pUART, uint8_t Len);

/**
  * @brief  Enables/Disables FIFOs
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_ConfigFifo(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Configures quantity of stop bits
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  StopLength: Value from @UART_StopLen
  * @retval none
  */
void UART_ConfigStop(UART_RegDef_t *pUART, uint8_t StopLength);

/**
  * @brief  Enables or Disables Sending Break
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_ConfigBreak(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables Hardware Clear to Send
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_ConfigHardwareCTS(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables Hardware Request to Send
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_ConfigHardwareRTS(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  When Request to Send Hardware control is DISABLED, user can
  *         manually control the Request to Send pin through this register
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Value: SET or RESET
  * @retval none
  */
void UART_RequestToSend(UART_RegDef_t *pUART, uint8_t Value);

/**
  * @brief  Controls the Data Terminal Ready Pin
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Value: SET or RESET
  * @retval none
  */
void UART_DataTerminalReady(UART_RegDef_t *pUART, uint8_t Value);

/**
  * @brief  Enables or Disables Receiver
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_RxCommand(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables Transmitter
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_TxCommand(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables the UART 
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_Command(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables Loopback mode
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void UART_ConfigLoopBack(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables High-Speed mode
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  * @note   This is invalid in SmartCard mode. 
  */
void UART_ConfigHighSpeed(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Configures the end of transmission event 
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: SET causes end of transmission events when all transmitted data has been transmitted
  *                  RESET causes end of transmission events based on the FIFO. See UART_ConfigTxTriggerLevel()
  * @retval none
  */
void UART_ConfigEOT(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Configures the Transmitter trigger level 
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  RxLevel: Value from @UART_RxTriggerLevel
  * @retval none
  */
void UART_ConfigRxTriggerLevel(UART_RegDef_t *pUART, uint8_t RxLevel);

/**
  * @brief  Configures the Transmitter trigger level 
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  RxLevel: Value from @UART_TxTriggerLevel
  * @retval none
  * @note   Ignored if UART_ConfigEOT() is called with SET 
  */
void UART_ConfigTxTriggerLevel(UART_RegDef_t *pUART, uint8_t TxLevel);

/**
  * @brief  Enables or Disables Smart Card Support
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  * @note   In this mode, stopbits are forced to 2, high speed mode is off, 
  *         and 8 bits per frame. Any previous configuration different from
  *         these will be overwritten after a call to this function
  */
void UART_ConfigSmartCard(UART_RegDef_t *pUART, uint8_t Command);

/**
  * @brief  Enables or Disables Interrupt Delivery to the NVIC
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  IRQConfig: Value from OR-ing values from @UART_IRQConfig
  * @retval none
  */
void UART_IRQConfig(UART_RegDef_t *pUART, uint8_t Command, uint32_t IRQConfig);

/**
  * @brief  Reads the raw interrupt status register
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Pos: Value from @UART_ITReadPos
  * @retval none
  * @note   For interrupts actually sent to the NVIC see UART_ReadITStatus()
  */
uint8_t UART_ReadRawIT(UART_RegDef_t *pUART, uint8_t Pos);

/**
  * @brief  Reads the interrupt status register
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Pos: Value from @UART_ITReadPos
  * @retval none
  */
uint8_t UART_ReadITStatus(UART_RegDef_t *pUART, uint8_t Pos);

/**
  * @brief  Clears an interrupt flag
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Pos: Value from @UART_ITReadPos
  * @retval none
  */
void UART_ClearIT(UART_RegDef_t *pUART, uint8_t Pos);

/**
  * @brief  Clears interrupt flags
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Mask: OR-ed values from @UART_ITMask
  * @retval none
  */
void UART_ClearITByMask(UART_RegDef_t *pUART, uint32_t Mask);

/**
  * @brief  Configures 9-bit mode
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE to enable/disable 9bit mode
  * @param  Addr: The address to match
  * @param  Mask: The mask value (bits set refer to bits that need to match in Addr)
  * @retval none
  * @note  Addr and Mask are ignored if Command is DISABLE
  */
void UART_Config9BitMode(UART_RegDef_t *pUART, uint8_t Command, uint8_t Addr, uint8_t Mask);

/**
  * @brief  Configures DMA control
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Mask: OR-ed values from @UART_DMA
  * @retval none
  */
void UART_ConfigDMA(UART_RegDef_t *pUART, uint8_t Command, uint8_t Mask);

/**
  * @brief  Configures DMA control
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  Divisor: The 8-bit low-power divisor
  * @param  LowPowerCommand: ENABLE or DISABLE the low power SIR mode
  * @param  Command: ENABLE or DISABLE the SIR mode
  * @retval none
  * @note   Divisor is ignored if LowPowerCommand is DISABLE
  */
void UART_ConfigIrDA(UART_RegDef_t *pUART, uint8_t Command, uint8_t LowPowerCommand, uint8_t Divisor);

/**
  * @brief  Configures the UART clock source
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  ClockSource: Value from @UART_ClockSource
  * @retval none
  * @note   UART_ClockSource_ALTCLK configures the UART module to use
  *         an alternate clock, as given by the ALTCLKCFG register. 
  *         The ALTCLKCFG register can be managed by the user, or 
  *         clock control drivers
  */
void UART_ConfigClockSource(UART_RegDef_t *pUART, uint8_t ClockSource);

/**
  * @brief  Configures basic parameters of the UART communication
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  pConfig: A structure with configurable items
  * @retval none
  * @note   After configuring basic parameters, the user can 
  *         configure the UART unit in SmartCard Mode, IrDA Mode 
  *         or 9-Bit mode through UART_ConfigSmartCard(), 
  *         UART_ConfigIrDA(), or UART_Config9BitMode() 
  */
void UART_Config(UART_RegDef_t *pUART, UART_Config_t *pConfig);

/**
  * @brief  Simple routine to sends data through UART in polling mode
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  pData: A pointer to the data to send
  * @param  DataLen: The length of the data to send in bytes
  * @retval none
  * @note   Do not forget to enable the UART before starting transmission
  */
void UART_SendData(UART_RegDef_t *pUART, uint8_t *pData, uint32_t DataLen);

/**
  * @brief  Simple routine that Receives data through UART in polling mode
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  pData: A pointer to where the data will be stored
  * @param  DataLen: The length of the data to receive in bytes
  * @retval A structure that holds the status of the transaction. The Status will 
  *         be a value from @UART_PollingStatus
  *         If there was an error, pData will point to the location that we couldn't
  *         write due to a receival error 
  *         DataLen will be the remaining bytes that could not be received. 
  *         The user can continue immediately by calling UART_ReceiveData using the
  *         returned pData and DataLen if desired.
  * @note   Do not forget to enable the UART before starting transmission
  */
UART_RcvPolling_t UART_ReceiveData(UART_RegDef_t *pUART, uint8_t *pData, uint32_t DataLen);

/**
  * @brief  Simple routine that Receives data through UART in polling mode
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @param  pData: A pointer to where the data will be stored
  * @param  DataLen: The length of the data to receive in bytes
  * @retval none
  * @note   Do not forget to enable the UART before starting transmission
  */
void UART_ReceiveDataSimple(UART_RegDef_t *pUART, uint8_t *pData, uint32_t DataLen);

/**
  * @brief  Simple routine that sends data in interrupt mode
  * @param  pHandle: A handle structure that holds information related to the use of
  *         this function
  * @retval Value from @UART_MSGStatus which indicates the value in which
  *         the handle was found on entry. A UART_MSGStatus_READY indicates
  *         that the message will be sent. UART_MSGStatus_BUSY means the 
  *         handle was found busy and the message will not be sent. 
  * @note   User must call UART_ITHandleMSG() within the ISR using this handle
  */
 uint8_t UART_SendDataIT(UART_Handle_t *pHandle, uint8_t *pData, uint32_t DataLen);

/**
  * @brief  Handles the ISR side of UART_SendDataIT
  * @param  pHandle: A handle structure that holds information related to the use of
  *         this function
  * @retval none
  * @note   User can manage events by implementing TxMSGCallback
  */
 void UART_ITHandleMSG(UART_Handle_t *pHandle);

 /**
  * @brief  Notifies the user of what is happening during communication
  * @param  pHandle: A handle structure that holds information related to the use of
  *         this function
  * @param  Event: Value from @UART_TxCallbackEvents
  * @retval none
  * @note   User can manage events by implementing TxMSGCallback
  * @note   Since this is called within an ISR, user must be quick
  *         not to block the system
  */
 __weak void UART_TxMSGCallback(UART_Handle_t *pHandle, uint8_t Event);

 /**
  * @brief  Gets the IRQ Number of a given UART
  * @param  pUART: UARTx where x is in (0 ... 7)
  * @retval an IRQNumber
  */
IRQNumber_type UART_GetIRQNumber(UART_RegDef_t *pUART); 

/**
  * @brief  Simple routine that receives data in interrupt mode
  * @param  pHandle: A handle structure that holds information related to the use of
  *         this function
  * @param  pData: A pointer to where the data will be stored
  * @param  DataLen: The length of the data to receive in bytes
  * @retval Value from @UART_MSGStatus which indicates the value in which
  *         the handle was found on entry. A UART_MSGStatus_READY indicates
  *         that we'll try to get the message. UART_MSGStatus_BUSY means the 
  *         handle was found busy. 
  * @note   User must call UART_ITHandleMSG() within the ISR using this handle
  */
 uint8_t UART_ReceiveDataIT(UART_Handle_t *pHandle, uint8_t *pData, uint32_t DataLen);

 /**
  * @brief  Handles the ISR side of UART_ReceiveDataIT
  * @param  pHandle: A handle structure that holds information related to the use of
  *         this function
  * @retval none
  * @note   User can manage events by implementing TxMSGCallback
  */
 void UART_ITHandleMSG(UART_Handle_t *pHandle);

 /**
  * @brief  Notifies the user of what is happening during communication
  * @param  pHandle: A handle structure that holds information related to the use of
  *         this function
  * @param  Event: Value from @UART_RxCallbackEvents
  * @retval none
  * @note   User can manage events by implementing RxMSGCallback
  * @note   Since this is called within an ISR, user must be quick
  *         not to block the system
  */
 __weak void UART_RxMSGCallback(UART_Handle_t *pHandle, uint8_t Event);

#endif // __TM4C1294NCPDT_UART_H__