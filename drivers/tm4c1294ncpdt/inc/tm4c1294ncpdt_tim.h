/*
 * Rafael Laya
 * 1975274
 * April 25th, 2020
 * Contains definitions for tm4c1294ncpdt_tim.h
 * @note: The terms Port A and Port B will be used to refer to Timer A and Timer B (respectively) in this driver 
 */

#ifndef __TM4C1294NCPDT_TIM_H__
#define __TM4C1294NCPDT_TIM_H__

#include "tm4c1294ncpdt.h"

typedef struct {
    uint8_t PeriodicModeCommand;                    /* ENABLE or DISABLE */
    uint8_t TIM_Direction;                          /* Value from @TIM_Direction */
    uint8_t TIM_SnapshotCommand;                    /* ENABLE or DISABLE */
    uint8_t TIM_WaitOnTriggerCommand;               /* ENABLE or DISABLE */
    uint8_t TIM_CompareAction;                      /* Value from @TIM_CompareAction */
} TIM_Init_t;

typedef struct {
    uint8_t TIM_Direction;                          /* Value From @TIM_Direction */
    uint8_t TIM_EdgeEvent;                          /* Value from @TIM_EventMode */
    uint8_t TIM_EdgeCaptureMode;                    /* TIM_Mode_Capture_EdgeX where X is Count or Time */      
} TIM_InitEdgeCount_t;

/* @TIM_ModuleConfig */
#define TIM_ModuleConfig_32BIT              0x0U
#define TIM_ModuleConfig_RTC                0x1U
#define TIM_ModuleConfig_16BIT              0x4U

/* @TIM_Mode */
#define TIM_Mode_OneShot                0x1U
#define TIM_Mode_Periodic               0x2U
#define TIM_Mode_Capture_EdgeCount      0x3U
#define TIM_Mode_Capture_EdgeTime       0x4U
#define TIM_Mode_PWM                    0x5U
#define TIM_Mode_RTC                    0x6U

#define TIM_IS_MODE(X)                ((X) >= TIM_Mode_OneShot && (X) <= TIM_Mode_RTC)

// GPTMCFG Masks
#define TIM_GPTMCFG_MASK                    0x7U
#define TIM_IS_MODULE_CONFIG(X)              ((X) == TIM_ModuleConfig_32BIT     ||     \
                                              (X) == TIM_ModuleConfig_RTC       ||     \
                                              (X) == TIM_ModuleConfig_16BIT)

/* @TIM_Direction */
#define TIM_Direction_UP            0x1U
#define TIM_Direction_DOWN          0x0U

#define TIM_IS_DIRECTION(X)                    ((X) == TIM_Direction_UP || \
                                             (X) == TIM_Direction_DOWN)

/* @TIM_Port */
#define TIM_Port_A                      0x1U
#define TIM_Port_B                      0x2U
#define TIM_Port_Concatenated           0x3U

#define TIM_IS_PORT(X)                             ((X) == TIM_Port_A ||  \
                                                    (X) == TIM_Port_B ||  \
                                                    (X) == TIM_Port_Concatenated)

#define TIM_IS_INDIVIDUAL_PORT(X)                      ((X) == TIM_Port_A || \
                                                        (X) == TIM_Port_B)

#define TIM_IS_CONCATENATED_PORT(X)                    ((X) == TIM_Port_Concatenated)

/* @TIM_Match_Update */
#define TIM_MatchUpdate_NextCycle       0x1U
#define TIM_MatchUpdate_NextTimeout     0x2U

#define TIM_IS_MATCH_UPDATE(X)                          ((X) == TIM_MatchUpdate_NextCycle || \
                                                         (X) == TIM_MatchUpdate_NextTimeout)

/* @TIM_CompareAction */ 
#define TIM_CompareAction_Disable                       0x0U
#define TIM_CompareAction_ToggleOnTimeout               0x1U
#define TIM_CompareAction_ClearOnTimeout                0x2U
#define TIM_CompareAction_SetOnTimeout                  0x3U
#define TIM_CompareAction_SetNowToggleOnTimeout         0x4U
#define TIM_CompareAction_ClearNowToggleOnTimeout       0x5U
#define TIM_CompareAction_SetNowClearOnTimeout          0x6U
#define TIM_CompareAction_ClearNowSetOnTimeout          0x7U

#define TIM_IS_COMPARE_ACTION(X)                        ((X) >= TIM_CompareAction_Disable && \
                                                         (X) <= TIM_CompareAction_ClearNowSetOnTimeout)

/* @TIM_EventMode */ 
#define TIM_EventMode_PositiveEdge          0x0U
#define TIM_EventMode_NegativeEdge          0x1U
#define TIM_EventMode_BothEdges             0x3U

#define TIM_IS_EVENT_MODE(X)                               ((X) == TIM_EventMode_PositiveEdge || \
                                                            (X) == TIM_EventMode_NegativeEdge || \
                                                            (X) == TIM_EventMode_BothEdges)

/* @TIM_IRQ */
#define TIM_IRQ_TimeoutA                    TIM_IMR_TATOIM_MASK
#define TIM_IRQ_CaptureMatchA               TIM_IMR_CAMIM_MASK
#define TIM_IRQ_CaptureEventA               TIM_IMR_CAEIM_MASK
#define TIM_IRQ_RTC                         TIM_IMR_RTCIM_MASK
#define TIM_IRQ_MatchA                      TIM_IMR_TAMIM_MASK
#define TIM_IRQ_DMADoneA                    TIM_IMR_DMAAIM_MASK
#define TIM_IRQ_TimeoutB                    TIM_IMR_TBTOIM_MASK
#define TIM_IRQ_CaptureMatchB               TIM_IMR_CBEIM_MASK
#define TIM_IRQ_CaptureEventB               TIM_IMR_CBEIM_MASK   
#define TIM_IRQ_MatchB                      TIM_IMR_TBMIM_MASK
#define TIM_IRQ_DMADoneB                    TIM_IMR_DMABIM_MASK
#define TIM_IRQ_ALL                         (TIM_IRQ_TimeoutA | TIM_IRQ_CaptureMatchA | TIM_IRQ_CaptureEventA |  \
                                             TIM_IRQ_RTC      | TIM_IRQ_MatchA        | TIM_IRQ_DMADoneA      |  \
                                             TIM_IRQ_TimeoutB | TIM_IRQ_CaptureMatchB | TIM_IRQ_CaptureEventB |  \
                                             TIM_IRQ_MatchB   | TIM_IRQ_DMADoneB)

// Allows for zero 
#define TIM_IS_IRQ_MASK_COMBINATION(X)      (((X) & ~(0x2F3FU)) == 0U)

/* @TIM_ITReadPos */ 
#define TIM_ITReadPos_TimeoutA              0U
#define TIM_ITReadPos_CaptureMatchA         1U
#define TIM_ITReadPos_CaptureEventA         2U
#define TIM_ITReadPos_RTC                   3U
#define TIM_ITReadPos_MatchA                4U
#define TIM_ITReadPos_DMADoneA              5U
#define TIM_ITReadPos_TimeoutB              8U
#define TIM_ITReadPos_CaptureMatchB         9U
#define TIM_ITReadPos_CaptureEventB         10U
#define TIM_ITReadPos_MatchB                11U
#define TIM_ITReadPos_DMADoneB              13U

#define TIM_IS_ITREAD_POS(X)                ((X) >= TIM_ITReadPos_TimeoutA && \
                                             (X) <= TIM_ITReadPos_DMADoneB && \
                                             (X) !=  6U                    && \
                                             (X) !=  7U                    && \
                                             (X) != 12U)

/* @TIM_ADCEV_Masks */
#define TIM_ADCEvent_TimeoutA                  0x1U
#define TIM_ADCEvent_CaptureMatchA             0x2U
#define TIM_ADCEvent_CaptureEventA             0x4U
#define TIM_ADCEvent_RTCMatch                  0x8U
#define TIM_ADCEvent_MatchA                    0x10U
#define TIM_ADCEvent_TimeoutB                  0x100U
#define TIM_ADCEvent_CaptureMatchB             0x200U
#define TIM_ADCEvent_CaptureEventB             0x400U
#define TIM_ADCEvent_MatchB                    0x800U
    
// Allows for zero
#define TIM_IS_ADC_EVENT_MASK_COMBINATION(X)                (((X) & ~(0xF1FU)) == 0U)     

/* @TIM_DMAEvent */
#define TIM_DMAEvent_TimeoutA                   0x1U
#define TIM_DMAEvent_CaptureMatchA              0x2U
#define TIM_DMAEvent_CaptureEventA              0x4U
#define TIM_DMAEvent_RTCMatch                   0x8U
#define TIM_DMAEvent_MatchA                     0x10U
#define TIM_DMAEvent_TimeoutB                   0x100U
#define TIM_DMAEvent_CaptureMatchB              0x200U
#define TIM_DMAEvent_CaptureEventB              0x400U
#define TIM_DMAEvent_MatchB                     0x800U

#define TIM_IS_DMA_EVENT_MASK_COMBINATION(X)                (((X) & ~(0xF1FU)) == 0U)

// Compare Action Bit Position and Mask
#define TIM_CompareAction_Pos                           13U
#define TIM_CompareAction_MASK                          (0x7 << TIM_CompareAction_Pos)

// TnMR Definitions
#define TIM_TNMR_MR_POS             0U
#define TIM_TNMR_CMR_POS            2U
#define TIM_TNMR_AMS_POS            3U
#define TIM_TNMR_DIR_POS            4U
#define TIM_TNMR_MIE_POS            5U
#define TIM_TNMR_TAWOT_POS          6U
#define TIM_TNMR_SNAPS_POS          7U
#define TIM_TNMR_ILD_POS            8U
#define TIM_TNMR_PWMIE_POS          9U
#define TIM_TNMR_MRSU_POS           10U
#define TIM_TNMR_PLO_POS            11U
#define TIM_TNMR_CICNTD_POS         12U
#define TIM_TNMR_TCACT_POS          13U
#define TIM_TNMR_MR_MASK            (0x3U << TIM_TNMR_MR_POS)
#define TIM_TNMR_CMR_MASK           (0x1U << TIM_TNMR_CMR_POS)       
#define TIM_TNMR_AMS_MASK           (0x1U << TIM_TNMR_AMS_POS)
#define TIM_TNMR_DIR_MASK           (0x1U << TIM_TNMR_DIR_POS)
#define TIM_TNMR_MIE_MASK           (0x1U << TIM_TNMR_MIE_POS)
#define TIM_TNMR_TAWOT_MASK         (0x1U << TIM_TNMR_TAWOT_POS)
#define TIM_TNMR_SNAPS_MASK         (0x1U << TIM_TNMR_SNAPS_POS)
#define TIM_TNMR_ILD_MASK           (0x1U << TIM_TNMR_ILD_POS)
#define TIM_TNMR_PWMIE_MASK         (0x1U << TIM_TNMR_PWMIE_POS)
#define TIM_TNMR_MRSU_MASK          (0x1U << TIM_TNMR_MRSU_POS)
#define TIM_TNMR_PLO_MASK           (0x1U << TIM_TNMR_PLO_POS)
#define TIM_TNMR_CICNTD_MASK        (0x1U << TIM_TNMR_CICNTD_POS)
#define TIM_TNMR_TCACT_MASK         (0x7U << TIM_TNMR_TCACT_POS)
#define TIM_TNMR_MR_ONESHOT         (0x1U << TIM_TNMR_MR_POS)
#define TIM_TNMR_MR_PERIODIC        (0x2U << TIM_TNMR_MR_POS)
#define TIM_TNMR_MR_CAPTURE         (0x3U << TIM_TNMR_MR_POS)

// CTL Bit positions and masks
#define TIM_CTL_TAEN_POS            0U
#define TIM_CTL_TASTALL_POS         1U
#define TIM_CTL_TAEVENT_POS         2U
#define TIM_CTL_RTCEN_POS           4U
#define TIM_CTL_TAOTE_POS           5U
#define TIM_CTL_TAPWML_POS          6U
#define TIM_CTL_TBEN_POS            8U
#define TIM_CTL_TBSTALL_POS         9U
#define TIM_CTL_TBEVENT_POS         10U
#define TIM_CTL_TBOTE_POS           13U
#define TIM_CLT_TBPWML_POS          14U
#define TIM_CTL_TAEN_MASK            (0x1U << TIM_CTL_TAEN_POS)
#define TIM_CTL_TASTALL_MASK         (0x1U << TIM_CTL_TASTALL_POS)
#define TIM_CTL_TAEVENT_MASK         (0x3U << TIM_CTL_TAEVENT_POS)
#define TIM_CTL_RTCEN_MASK           (0x1U << TIM_CTL_RTCEN_POS)
#define TIM_CTL_TAOTE_MASK           (0x1U << TIM_CTL_TAOTE_POS)
#define TIM_CTL_TAPWML_MASK          (0x1U << TIM_CTL_TAPWML_POS)
#define TIM_CTL_TBEN_MASK            (0x1U << TIM_CTL_TBEN_POS)
#define TIM_CTL_TBSTALL_MASK         (0x1U << TIM_CTL_TBSTALL_POS)
#define TIM_CTL_TBEVENT_MASK         (0x3U << TIM_CTL_TBEVENT_POS)
#define TIM_CTL_TBOTE_MASK           (0x1U << TIM_CTL_TBOTE_POS)
#define TIM_CTL_TBPWML_MASK          (0x1U << TIM_CLT_TBPWML_POS)

// IMR Bit positions and masks
#define TIM_IMR_TATOIM_POS                  0U
#define TIM_IMR_CAMIM_POS                   1U
#define TIM_IMR_CAEIM_POS                   2U
#define TIM_IMR_RTCIM_POS                   3U
#define TIM_IMR_TAMIM_POS                   4U
#define TIM_IMR_DMAAIM_POS                  5U
#define TIM_IMR_TBTOIM_POS                  8U
#define TIM_IMR_CBMIM_POS                   9U
#define TIM_IMR_CBEIM_POS                   10U
#define TIM_IMR_TBMIM_POS                   11U
#define TIM_IMR_DMABIM_POS                  13U
#define TIM_IMR_TATOIM_MASK                  (0x1U << TIM_IMR_TATOIM_POS)
#define TIM_IMR_CAMIM_MASK                   (0x1U << TIM_IMR_CAMIM_POS)
#define TIM_IMR_CAEIM_MASK                   (0x1U << TIM_IMR_CAEIM_POS)
#define TIM_IMR_RTCIM_MASK                   (0x1U << TIM_IMR_RTCIM_POS)
#define TIM_IMR_TAMIM_MASK                   (0x1U << TIM_IMR_TAMIM_POS)
#define TIM_IMR_DMAAIM_MASK                  (0x1U << TIM_IMR_DMAAIM_POS)
#define TIM_IMR_TBTOIM_MASK                  (0x1U << TIM_IMR_TBTOIM_POS)
#define TIM_IMR_CBMIM_MASK                   (0x1U << TIM_IMR_CBMIM_POS)
#define TIM_IMR_CBEIM_MASK                   (0x1U << TIM_IMR_CBEIM_POS)
#define TIM_IMR_TBMIM_MASK                   (0x1U << TIM_IMR_TBMIM_POS)
#define TIM_IMR_DMABIM_MASK                  (0x1U << TIM_IMR_DMABIM_POS)

/**
  * @brief  Enables/Disables the clock for the given Timer
  * @param  mask: Value from @SYSCTL_RCGCTIMER_MASKS
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void TIM_PeriphClockCtrlByMask(uint32_t Mask, uint8_t Command);

/**
  * @brief  Initializes configuration parameters for a given Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_Init(TIM_RegDef_t *pTIM, TIM_Init_t *InitDef, uint8_t Port);

/**
  * @brief  Initializes configuration parameters for a given Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Port: Value from @ModuleConfig
  * @retval None
  */
void TIM_ConfigModule(TIM_RegDef_t *pTIM, uint8_t ModuleConfig);

/**
  * @brief  Configures the mode for a Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  ModeConfig: Value from @TIM_Mode 
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigMode(TIM_RegDef_t *pTIM, uint8_t ModeConfig, uint8_t Port);

/**
  * @brief  Configures snaptshot mode for a given Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_SnapshotCommand(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Configures direction for a given Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  DirectionConfig: Value from @TIM_Direction
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigDirection(TIM_RegDef_t *pTIM, uint8_t DirectionConfig, uint8_t Port);

/**
  * @brief  Configures IT corresponding to MATCH events
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  * @note   To enable Interrupt Requests, see TIM_IRQConfig()
  */
void TIM_ConfigMatchIT(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Configures Wait On Trigger Setting
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigWaitOnTrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Enables PWM Interrupts
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  * @note   See
  */
void TIM_ConfigPWM_IT(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Enables PWM Interrupts 
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  MatchUpdate: Value from @TIM_Match_Update
  * @param  Port: Value from @TIM_Port
  * @retval None
  * @note   See TIM_ConfigEventMode() to set the interrupt event
  */
void TIM_ConfigMatchUpdate(TIM_RegDef_t *pTIM, uint8_t MatchUpdate, uint8_t Port);

/**
  * @brief  Enables Timeout Interrupts
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigTimeoutIT(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Configures Compare Action on Timeout
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  CompareAction: Value from @TIM_CompareAction
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigCompareAction(TIM_RegDef_t *pTIM, uint8_t CompareAction, uint8_t Port);

/**
  * @brief  Enables/Disables a Timer to start/stop counting
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_Command(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Configures Event Mode Regards to Edge Detection
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  EventMode: Value from @TIM_EventMode
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigEventMode(TIM_RegDef_t *pTIM, uint8_t EventMode, uint8_t Port);

/**
  * @brief  Enables or Disables ADC Triggers by a Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_EnableADCTrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Enables or Disables Output Inversion for PWM
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval None
  */
void TIM_ConfigInvertPWM(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Enables/Disables interrupt requests 
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  IRQConfig: Mask by OR'ing values from @TIM_IRQ
  * @retval None
  */
void TIM_IRQConfig(TIM_RegDef_t *pTIM, uint8_t Command, uint32_t IRQConfig);

/**
  * @brief  Reads the masked interrupt status register for a given Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval Contents of the masked interrupt status register
  * @note   User must mask the bits they care about, otherwise call TIM_ReadITStatus()
  */
uint16_t TIM_ReadITStatusAll(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads a bit from the masked interrupt status register for a given Timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  ITReadPos: Value from @TIM_ITReadPos
  * @retval SET if the register is masked (interrupt occured), otherwise RESET
  */
uint8_t TIM_ReadITStatus(TIM_RegDef_t *pTIM, uint8_t ITReadPos);

/**
  * @brief  Clears the masked interrupt register
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval none
  */
void TIM_ClearITAll(TIM_RegDef_t *pTIM);

/**
  * @brief  Clears one bit from the masked interrupt register
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  ITReadPos: Value from @TIM_ITReadPos
  * @retval none
  */
void TIM_ClearIT(TIM_RegDef_t *pTIM, uint8_t ITReadPos);

/**
  * @brief  Configures the Interval Load Register of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Value to store in the Interval Load Register
  * @retval none
  */
void TIM_ConfigIntervalA(TIM_RegDef_t *pTIM, uint16_t val);

/**
  * @brief  Configures the Interval Load Register in concatenated mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Value to store in the Interval Load Register
  * @retval none
  */
void TIM_ConfigIntervalConc(TIM_RegDef_t *pTIM, uint32_t val);

/**
  * @brief  Loads the Interval Load Register of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Value to store in the Interval Load Register
  * @retval none
  */
void TIM_ConfigIntervalB(TIM_RegDef_t *pTIM, uint16_t val);

/**
  * @brief  Loads the Match Register of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Value to load for MATCH events
  *              0 upto 0xFFFF for 16 bit individual mode
  *              0 upto 0xFFFFFFFF for concatenated mode
  * @retval none
  */
void TIM_ConfigMatchA(TIM_RegDef_t *pTIM, uint16_t val);

/**
  * @brief  Loads the Match Register of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Value to load for MATCH events
  *              0 upto 0xFFFF for 16 bit individual mode
  *              0 upto 0xFFFFFFFF for concatenated mode
  * @retval none
  */
void TIM_ConfigMatchB(TIM_RegDef_t *pTIM, uint16_t val);

/**
  * @brief  Loads a prescaler Value for Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Prescaler (0 upto 0xFF)
  * @retval none
  * @note   not available in concatenated mode
  */
void TIM_ConfigPrescaleA(TIM_RegDef_t *pTIM, uint8_t val);

/**
  * @brief  Loads a prescaler Value for Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Prescaler (0 upto 0xFF)
  * @retval none
  * @note   not available in concatenated mode
  */
void TIM_ConfigPrescaleB(TIM_RegDef_t *pTIM, uint8_t val);

/**
  * @brief  Loads a prescaler Value for Timer A Match Events
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Prescaler (0 upto 0xFF)
  * @retval none
  * @note   not available in concatenated mode
  */
void TIM_ConfigPrescaleMatchA(TIM_RegDef_t *pTIM, uint8_t val);

/**
  * @brief  Loads a prescaler Value for Timer B Match Events
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  val: Prescaler (0 upto 0xFF)
  * @retval none
  * @note   not available in concatenated mode
  */
void TIM_ConfigPrescaleMatchB(TIM_RegDef_t *pTIM, uint8_t val);

/**
  * @brief  Reads the RTC predivider in RTC Mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval none
  * @note   Has no meaning in any mode other than RTC mode
  */
uint16_t TIM_ReadRTCPrediv(TIM_RegDef_t *pTIM);

/**
  * @brief  Enables/Disables an alternate clock (instead of System Clock)
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  * @note   First configure the alternate source through SYSCTL's ALTCLKCFG register
  */
void TIM_ConfigAltClk(TIM_RegDef_t *pTIM, uint8_t Command);

/**
  * @brief  Enables/Disables Triggers of DMA
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  * @note   See TIM_ConfigADCTrigger() for DMA Trigger configuration
  */
void TIM_ConfigDMATrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint32_t Mask);

/**
  * @brief  
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Mask: OR'ed values from @TIM_DMAEvent
  * @retval none
  */
void TIM_ConfigADCTrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint32_t Mask);

/**
  * @brief  Enables/Disables freezes a given Timer when the CPU is halted
  *         by the debugger
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @param  Port: Value from @TIM_Port
  * @retval none
  */
void TIM_HaltOnDebug(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port);

/**
  * @brief  Enables/Disables freezes a given Timer configured as RTC
  *         when the CPU is halted by the debugger
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void TIM_RTCHaltOnDebug(TIM_RegDef_t *pTIM, uint8_t Command);

/**
  * @brief  Initializes a given Timer in RTC Mode 
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  MatchValue: Value used for MATCH events
  * @param  Presc: Prescalar used for RTC MATCH events
  * @retval none
  */
void TIM_RTCInit(TIM_RegDef_t *pTIM, uint32_t MatchValue, uint8_t Presc);

/**
  * @brief  Initializes a given Timer in Edge-Count or Edge-Time mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  pInitDef: Holds basic initialization information
  * @param  Port: Value from @TIM_Port
  * @retval none
  */
void TIM_EdgeInit(TIM_RegDef_t *pTIM, TIM_InitEdgeCount_t *pInitDef, uint8_t Port);

/**
  * @brief  Initializes a given Timer in PWM Mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  InvertedPWMCommand: ENABLE or DISABLE. ENABLE means the PWM output is inverted
  * @param  Port: Value from @TIM_Port
  * @retval none
  */
void TIM_PWMInit(TIM_RegDef_t *pTIM, uint8_t InvertedPWMCommand, uint8_t Port);

/**
  * @brief  Reads the Interval Load Register of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the interval load register
  */
uint16_t TIM_ReadIntervalA(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Interval Load Register of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the interval load register
  */
uint16_t TIM_ReadIntervalB(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Interval Load Register in concatenated mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the interval load register
  */
uint32_t TIM_ReadIntervalConc(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Register of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Match Register
  */
uint16_t TIM_ReadMatchA(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Register of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Match Register
  */
uint16_t TIM_ReadMatchB(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Register in concatenated mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Match Register
  */
uint32_t TIM_ReadMatchConc(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Prescaler Register of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Prescaler Register
  */
uint8_t TIM_ReadPrescA(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Prescaler Register of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Prescaler Register
  */
uint8_t TIM_ReadPrescB(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Prescaler Register of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Prescaler Register
  */
uint8_t TIM_ReadMatchPrescA(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Prescaler Register of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Prescaler Register
  */
uint8_t TIM_ReadMatchPrescB(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Prescaler Register of Timer A 
  *         in snapshot mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Snapshot Prescaler Register
  */
uint16_t TIM_ReadSnapshotPrescA(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the Match Prescaler Register of Timer B
  *         in snapshot mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval The value in the Snapshot Prescaler Register
  */
uint16_t TIM_ReadSnapshotPrescB(TIM_RegDef_t *pTIM);

/**
  * @brief  Loads the Count of Timer A
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  count: The value to load
  */
void TIM_LoadCountA(TIM_RegDef_t *pTIM, uint16_t count);

/**
  * @brief  Loads the Count of Timer B
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  count: The value to load
  */
void TIM_LoadCountB(TIM_RegDef_t *pTIM, uint16_t count);

/**
  * @brief  Loads the Count in concatenated mode
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  count: The value to load
  */
void TIM_LoadCountConc(TIM_RegDef_t *pTIM, uint32_t count);

/**
  * @brief  Reads a bit from the Raw Interrupt Status Register
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  ITReadPos: Value from @TIM_ITReadPos
  * @retval SET if the event has happened
  * @note   See TIM_ReadITStatus() for information about an interrupt
  *         request
  */
uint8_t TIM_ReadRawITStatus(TIM_RegDef_t *pTIM, uint8_t ITReadPos);


/**
  * @brief  Reads the Raw Interrupt Status Register
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @retval Contents of the raw interrupt status register
  * @note   User must mask the bits they care about, otherwise call TIM_ReadITStatus()
  *         See TIM_ReadITStatusAll() for information about interrupt requests
  */
uint16_t TIM_ReadRawITStatusAll(TIM_RegDef_t *pTIM);

/**
  * @brief  Reads the enable bit of a timer
  * @param  pTIM: TIMx where x is in (0 ... 7)
  * @param  Port: Value from @TIM_Port
  * @retval The value of the TAEN bit
  */
 uint8_t TIM_ReadCounterStatus(TIM_RegDef_t *pTIM, uint8_t Port);

#endif // __TM4C1294NCPDT_TIM_H__