#pragma once

#include "tm4c1294ncpdt.h"

typedef struct {
  uint8_t Sequencer;                  /* Value from @ADC_Sequencer */
  uint8_t Sample;                     /* Value from @ADC_Sample */
  uint8_t Input;                      /* Value from @ADC_Sample_Input */
  uint8_t ITCommand;                  /* ENABLE or DISABLE */
  uint8_t EndOfSequenceCommand;       /* ENABLE or DISABLE */
  uint8_t Comparator;                 /* Value from @ADC_Sample_Comparator */
  uint8_t HoldWidth;                  /* Value from @ADC_Sample_HoldWidth */
} ADC_Sample_t;

typedef struct {
  uint8_t Comparator;                   /* Value from @ADC_Sample_Comparator */
  uint8_t ITComparisonMode;             /* Value from @ADC_ComparisonMode */
  uint8_t ITComparisonBand;             /* Value from @ADC_ComparisonBand */
  uint8_t ITComparisonCommand;          /* ENABLE or DISABLE */
  uint8_t ComparisonTriggerMode;        /* Value from @ADC_ComparisonMode */
  uint8_t ComparisonTriggerBand;        /* Value from @ADC_ComparisonBand */
  uint8_t ComparisonTriggerCommand;     /* ENABLE or DISABLE */
} ADC_Comparator_t;

/* Miscellaneous */
#define ADC_IS_PHASE(X)             ((X) >= 0U && (X) <= 15U)
#define ADC_IS_PLLVCO_DIVISOR(X)    ((X) >= 0U && (X) <= 0x3FU)

/* @ADC_ClockSource */
#define ADC_ClockSource_PLLVCO_DIV_CLKDIV     0x0U
#define ADC_ClockSource_AltClk                0x1U
#define ADC_ClockSource_MOSC                  0x2U

#define ADC_IS_CLOCKSOURCE(X)               ((X) == ADC_ClockSource_PLLVCO_DIV_CLKDIV || \
                                             (X) == ADC_ClockSource_AltClk || \
                                             (X) == ADC_ClockSource_MOSC)

/* @ADC_ComparisonBand */
#define ADC_ComparisonBand_Low                  0x0U
#define ADC_ComparisonBand_Mid                  0x1U
#define ADC_ComparisonBand_High                 0x3U

#define ADC_IS_COMPARISON_BAND(X)           ((X) >= ADC_ComparisonBand_Low && (X) <= ADC_ComparisonBand_High)

/* @ADC_ComparisonMode */
#define ADC_ComparisonMode_Always               0x0U
#define ADC_ComparisonMode_Once                 0x1U
#define ADC_ComparisonMode_HysteresisAlways     0x2U
#define ADC_ComparisonMode_HysteresisOnce       0x3U

#define ADC_IS_COMPARISON_MODE(X)         ((X) >= ADC_ComparisonMode_Always && (X) <= ADC_ComparisonMode_HysteresisOnce)

/* @ADC_Sample_Comparator */
#define ADC_Sample_Comparator0              0U
#define ADC_Sample_Comparator1              1U
#define ADC_Sample_Comparator2              2U
#define ADC_Sample_Comparator3              3U
#define ADC_Sample_Comparator4              4U
#define ADC_Sample_Comparator5              5U
#define ADC_Sample_Comparator6              6U
#define ADC_Sample_Comparator7              7U
#define ADC_Sample_Comparator_Disabled      8U

#define ADC_IS_SAMPLE_COMPARATOR(X)           ((X) >= ADC_Sample_Comparator0 && (X) <=ADC_Sample_Comparator_Disabled)

/* @ADC_Sample_HoldWidth */
#define ADC_Sample_HoldWidth4               0x0U
#define ADC_Sample_HoldWidth8               0x2U
#define ADC_Sample_HoldWidth16              0x4U
#define ADC_Sample_HoldWidth32              0x6U
#define ADC_Sample_HoldWidth64              0x8U
#define ADC_Sample_HoldWidth128             0xAU
#define ADC_Sample_HoldWidth256             0xCU

#define ADC_IS_SAMPLE_HOLDWIDTH(X)            ((X) == ADC_Sample_HoldWidth4   || \
                                               (X) == ADC_Sample_HoldWidth8   || \
                                               (X) == ADC_Sample_HoldWidth16  || \
                                               (X) == ADC_Sample_HoldWidth32  || \
                                               (X) == ADC_Sample_HoldWidth64  || \
                                               (X) == ADC_Sample_HoldWidth128 || \
                                               (X) == ADC_Sample_HoldWidth256 )

/* @ADC_Sample_Input */
#define ADC_Sample_Input_Analog0             0U
#define ADC_Sample_Input_Analog1             1U
#define ADC_Sample_Input_Analog2             2U
#define ADC_Sample_Input_Analog3             3U
#define ADC_Sample_Input_Analog4             4U
#define ADC_Sample_Input_Analog5             5U
#define ADC_Sample_Input_Analog6             6U
#define ADC_Sample_Input_Analog7             7U
#define ADC_Sample_Input_Analog8             8U
#define ADC_Sample_Input_Analog9             9U
#define ADC_Sample_Input_Analog10            10U
#define ADC_Sample_Input_Analog11            11U
#define ADC_Sample_Input_Analog12            12U
#define ADC_Sample_Input_Analog13            13U
#define ADC_Sample_Input_Analog14            14U
#define ADC_Sample_Input_Analog15            15U
#define ADC_Sample_Input_Analog16            16U
#define ADC_Sample_Input_Analog17            17U
#define ADC_Sample_Input_Analog18            18U
#define ADC_Sample_Input_Analog19            19U
#define ADC_Sample_Input_Temp                20U
#define ADC_Sample_Input_Pair0               30U
#define ADC_Sample_Input_Pair1               31U
#define ADC_Sample_Input_Pair2               32U
#define ADC_Sample_Input_Pair3               33U
#define ADC_Sample_Input_Pair4               34U
#define ADC_Sample_Input_Pair5               35U
#define ADC_Sample_Input_Pair6               36U
#define ADC_Sample_Input_Pair7               37U
#define ADC_Sample_Input_Pair8               38U
#define ADC_Sample_Input_Pair9               39U

#define ADC_IS_SAMPLE_INPUT(X)                ( ((X) >= ADC_Sample_Input_Analog0 && (X) <= ADC_Sample_Input_Temp )      || \
                                                ((X) >= ADC_Sample_Input_Pair0   && (X) <= ADC_Sample_Input_Pair9) )

/* @ADC_Sequencer */
#define ADC_Sequencer0      0U
#define ADC_Sequencer1      1U
#define ADC_Sequencer2      2U
#define ADC_Sequencer3      3U

#define ADC_IS_SEQUENCER(X)                   ((X) >= ADC_Sequencer0 && (X) <= ADC_Sequencer3)

/* @ADC_Sample */
#define ADC_Sample0         0U
#define ADC_Sample1         1U
#define ADC_Sample2         2U
#define ADC_Sample3         3U
#define ADC_Sample4         4U
#define ADC_Sample5         5U
#define ADC_Sample6         6U
#define ADC_Sample7         7U

#define ADC_IS_SAMPLE(X)                          ((X) >= ADC_Sample0 && (X) <= ADC_Sample7)

/* @ADC_Sequencer_Prio */
#define ADC_Sequencer_Prio0             0U
#define ADC_Sequencer_Prio1             1U
#define ADC_Sequencer_Prio2             2U
#define ADC_Sequencer_Prio3             3U

#define ADC_IS_SEQUENCER_PRIO(X)              ((X) >= ADC_Sequencer_Prio0 && (X) <= ADC_Sequencer_Prio3)
#define ADC_IS_ONEHOT_PRIO(X,Y,Z,W)            ( ((X) | (Y) | (W) | (Z)) == 0xFU && \
                                                 ADC_IS_SEQUENCER_PRIO(X) &&        \
                                                 ADC_IS_SEQUENCER_PRIO(Y) &&        \
                                                 ADC_IS_SEQUENCER_PRIO(Z) &&        \
                                                 ADC_IS_SEQUENCER_PRIO(W) )
                                                

/* @ADC_ITReadPos */
#define ADC_ITReadPos_Sequencer0            0U
#define ADC_ITReadPos_Sequencer1            1U
#define ADC_ITReadPos_Sequencer2            2U
#define ADC_ITReadPos_Sequencer3            3U
#define ADC_ITReadPos_DMA_Sequencer0        8U
#define ADC_ITReadPos_DMA_Sequencer1        9U
#define ADC_ITReadPos_DMA_Sequencer2        10U
#define ADC_ITReadPos_DMA_Sequencer3        11U
#define ADC_ITReadPos_ComparatorOnSS0       16U
#define ADC_ITReadPos_ComparatorOnSS1       17U
#define ADC_ITReadPos_ComparatorOnSS2       18U
#define ADC_ITReadPos_ComparatorOnSS3       19U

#define ADC_IS_IT_READ_POS(X)                       ((X) >= ADC_ITReadPos_Sequencer0 && (X) <= ADC_ITReadPos_ComparatorOnSS3)

/* @ADC_ITMask */
#define ADC_ITMask_Sequencer0            (0x1 << ADC_ITReadPos_Sequencer0)
#define ADC_ITMask_Sequencer1            (0x1 << ADC_ITReadPos_Sequencer1)
#define ADC_ITMask_Sequencer2            (0x1 << ADC_ITReadPos_Sequencer2)
#define ADC_ITMask_Sequencer3            (0x1 << ADC_ITReadPos_Sequencer3)
#define ADC_ITMask_DMA_Sequencer0        (0x1 << ADC_ITReadPos_DMA_Sequencer0)
#define ADC_ITMask_DMA_Sequencer1        (0x1 << ADC_ITReadPos_DMA_Sequencer1)
#define ADC_ITMask_DMA_Sequencer2        (0x1 << ADC_ITReadPos_DMA_Sequencer2)
#define ADC_ITMask_DMA_Sequencer3        (0x1 << ADC_ITReadPos_DMA_Sequencer3)
#define ADC_ITMask_ComparatorOnSS0       (0x1 << ADC_ITReadPos_Comparator0)
#define ADC_ITMask_ComparatorOnSS1       (0x1 << ADC_ITReadPos_Comparator1)
#define ADC_ITMask_ComparatorOnSS2       (0x1 << ADC_ITReadPos_Comparator2)
#define ADC_ITMask_ComparatorOnSS3       (0x1 << ADC_ITReadPos_Comparator3)
#define ADC_ITMask_All                   0x10F0FU

#define ADC_IS_ITMASK(X)              (((X) & ~ADC_ITMask_All) == 0U)

/* @ADC_Fifo */
#define ADC_FIFO0               0U
#define ADC_FIFO1               1U
#define ADC_FIFO2               2U
#define ADC_FIFO3               3U

#define ADC_IS_FIFO(X)              ((X) >= ADC_FIFO0 && (X) <= ADC_FIFO3)

/* @ADC_TriggerEvent */
#define ADC_TriggerEvent_Software           0x0U
#define ADC_TriggerEvent_Comparator0        0x1U
#define ADC_TriggerEvent_Comparator1        0x2U
#define ADC_TriggerEvent_Comparator2        0x3U
#define ADC_TriggerEvent_GPIOPin            0x4U
#define ADC_TriggerEvent_Timer              0x5U
#define ADC_TriggerEvent_PWM0               0x6U
#define ADC_TriggerEvent_PWM1               0x7U
#define ADC_TriggerEvent_PWM2               0x8U
#define ADC_TriggerEvent_PWM3               0x9U
#define ADC_TriggerEvent_Never              0xEU
#define ADC_TriggerEvent_Always             0xFU

#define ADC_IS_TRIGGER_EVENT(X)               ((X) >= ADC_TriggerEvent_Software && (X) <= ADC_TriggerEvent_Always)

/* @ADC_Oversampling */
#define ADC_Oversampling_No             0x0U
#define ADC_Oversampling_2              0x1U
#define ADC_Oversampling_4              0x2U
#define ADC_Oversampling_8              0x3U
#define ADC_Oversampling_16             0x4U
#define ADC_Oversampling_32             0x5U
#define ADC_Oversampling_64             0x6U

#define ADC_IS_OVERSAMPLING(X)                ((X) >= ADC_Oversampling_No && (X) <= ADC_Oversampling_64)

/* @ADC_Comparator */
#define ADC_Comparator0             0U
#define ADC_Comparator1             1U
#define ADC_Comparator2             2U
#define ADC_Comparator3             3U
#define ADC_Comparator4             4U 
#define ADC_Comparator5             5U
#define ADC_Comparator6             6U
#define ADC_Comparator7             7U

#define ADC_IS_COMPARATOR(X)                ((X) >= ADC_Comparator0 && (X) <= ADC_Comparator7)

/* @ADC_CACTSS */
#define ADC_CACTSS_DMA_OFFSET       8U

/* @ADC_SSPRI */
#define ADC_SSPRI_PRIO0_POS               0U
#define ADC_SSPRI_PRIO1_POS               4U
#define ADC_SSPRI_PRIO2_POS               8U
#define ADC_SSPRI_PRIO3_POS               12U
#define ADC_SSPRI_PRIO_ALL_MASK           0x3333U

/* @ADC_SPC */
#define ADC_SPC_MASK                0xFU

/* @ADC_PSSI */
#define ADC_PSSI_GSYNC_POS          31U
#define ADC_PSSI_SYNCWAIT_POS       27U

/* @ADC_SAC */
#define ADC_SAC_MASK                0x7U

/* @ADC_SSFSTAT */
#define ADC_SSFSTAT_FULL_POS        12U
#define ADC_SSFSTAT_EMPTY_POS       8U

/* @ADC_DCRIC */
#define ADC_DCRIC_TRIG_OFFSET       16U

/* @ADC_CC */
#define ADC_CC_CLKDIV_POS           4U
#define ADC_CC_CLKDIV_MASK          (0x3FU << ADC_CC_CLKDIV_POS)
#define ADC_CC_CS_MASK              0xFU

/* @ADC_DCCTL */
#define ADC_DCCTL_CIM_POS                 0U
#define ADC_DCCTL_CIM_MASK                0x3U
#define ADC_DCCTL_CIC_POS                 2U
#define ADC_DCCTL_CIC_MASK                (0x3U << ADC_DCCTL_CIC_POS)
#define ADC_DCCTL_CIE_POS                 4U
#define ADC_DCCTL_CIE_MASK                (0x1U << ADC_DCCTL_CIE_POS)
#define ADC_DCCTL_CTM_POS                 8U
#define ADC_DCCTL_CTM_MASK                (0x3U << ADC_DCCTL_CTM_POS)
#define ADC_DCCTL_CTC_POS                 10U
#define ADC_DCCTL_CTC_MASK                (0x3U << ADC_DCCTL_CTC_POS)
#define ADC_DCCTL_CTE_POS                 12U
#define ADC_DCCTL_CTE_MASK                (0x1 << ADC_DCCTL_CTE_POS)
#define ADC_DCCTL_MASK_ALL                (0x1F1FU)

/* @ADC_DCCMP */
#define ADC_DCCMP_COMP0_POS               0U
#define ADC_DCCMP_COMP0_MASK              (0xFFFU << ADC_DCCMP_COMP0_POS)
#define ADC_DCCMP_COMP1_POS               16U
#define ADC_DCCMP_COMP1_MASK              (0xFFFU << ADC_DCCMP_COMP1_POS)

/* @ADC_SSCTL */
#define ADC_SSCTL_D_OFFSET                0U
#define ADC_SSCTL_END_OFFSET              1U
#define ADC_SSCTL_IE_OFFSET               2U
#define ADC_SSCTL_TS_OFFSET               3U

/**
  * @brief  Enables/Disables one of the four ADC sequencers
  * @param  pADC: ADC0 or ADC1
  * @param  Sequencer: Value from @ADC_Sequencer
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void ADC_SequencerCommand(ADC_RegDef_t *pADC, uint8_t Command, uint8_t Sequencer);

/**
  * @brief  Enables/Disables DMA for one of the four ADC sequencers
  * @param  pADC: ADC0 or ADC1
  * @param  Sequencer: Value from @ADC_Sequencer
  * @param  Command: ENABLE or DISABLE
  * @retval None
  */
void ADC_EnableSequencer(ADC_RegDef_t *pADC, uint8_t Command,  uint8_t Sequencer);

/**
  * @brief  Reads the status of the RAW Interrupt status of an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Pos: Value from @ADC_ITReadPos, except ADC_ITReadPos_ComparatorOnSS1, SS2, and SS3
  * @retval SET if interrupt has been asserted, otherwise RESET
  * @note   This is the RAW value. For values sent ot the NVIC, see ADC_ReadITStatus()
  * @note   The values for ADC_ITReadPos_ComparatorOnSSX are merged into one bit (OR-ed)
  */
uint8_t ADC_ReadITRawStatus(ADC_RegDef_t *pADC, uint8_t Pos);

/**
  * @brief  Reads the status of the RAW Interrupt status of an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Mask: OR-ed combination of values from @ADC_ITMask, except ADC_ITMask_ComparatorX for X in (1, 2, 3)
  * @retval OR-ed combination of values from @ADC_ITMask, except ADC_ITMask_ComparatorX for X in (1, 2, 3). 
  *         The corresponding bit is SET if the interupt has been asserted, otherwise RESET
  * @note   This is the RAW value. For values sent ot the NVIC, see ADC_ReadITStatusByMask()
  * @note   The values for ADC_ITReadPos_ComparatorOnSSX are merged into one bit (OR-ed)
  */
uint32_t ADC_ReadITRawStatusByMask(ADC_RegDef_t *pADC, uint32_t Mask);

/**
  * @brief  Reads the Interrupt status register of an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Pos: Value from @ADC_ITReadPos
  * @retval SET if interrupt has been asserted, otherwise RESET
  */
uint8_t ADC_ReadITStatus(ADC_RegDef_t *pADC, uint8_t Pos);

/**
  * @brief  Reads the Interrupt status register of an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Mask: OR-ed combination of values from @ADC_ITMask
  * @retval OR-ed combination of values from @ADC_ITMask. The corresponding bit
  *         is SET if the interupt has been asserted, otherwise RESET
  */
uint32_t ADC_ReadITStatusByMask(ADC_RegDef_t *pADC, uint32_t Mask);

/**
  * @brief  Enables or disables delivery to interrupts to the NVIC for an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Command: ENABLE or DISABLE
  * @param  Pos: Value from @ADC_ITReadPos
  * @retval None
  */
void ADC_IRQConfig(ADC_RegDef_t *pADC, uint8_t Command, uint8_t Pos);

/**
  * @brief  Clears an interrupt flag for an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Pos: Value from @ADC_ITReadPos
  * @retval None
  */
void ADC_ClearIT(ADC_RegDef_t *pADC, uint8_t Pos);

/**
  * @brief  Clears one or more interrupt flag for an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Mask: OR-ed combination of values from @ADC_ITReadMask
  * @retval None
  */
void ADC_ClearITByMask(ADC_RegDef_t *pADC, uint32_t Mask);

/**
  * @brief  Reads the comparator IT status register
  * @param  pADC: ADC0 or ADC1
  * @param  Comparator: Value from @ADC_Comparator
  * @retval SET if the interrupt has been generated, otherwise RESET
  */
uint8_t ADC_ReadComparatorITStatus(ADC_RegDef_t *pADC, uint8_t Comparator);

/**
  * @brief  Clears one bit from the comparator IT status register
  * @param  pADC: ADC0 or ADC1
  * @param  Comparator: Value from @ADC_Comparator
  * @retval None
  * @note   Clears IT from a specific comparator. ADC_ClearIT() can clear
  *         IT flags for a given sequencer
  */
void ADC_ClearComparatorIT(ADC_RegDef_t *pADC, uint8_t Comparator);

/**
  * @brief  Reads the overflow status register
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval SET if the corresponding FIFO has overflown, otherwise RESET
  */
uint8_t ADC_CheckOverflow(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Clears the overflow status register
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval none
  */
void ADC_ClearOverflow(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Reads the underflow status register
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval SET if the corresponding FIFO has underflown, otherwise RESET
  */
uint8_t ADC_CheckUnderflow(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Clears the underflow status register
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval none
  */
void ADC_ClearUnderflow(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Configures the trigger event for a sequencer within an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Sequencer: Value from @ADC_Sequencer
  * @param  Event: Value from @ADC_TriggerEvent
  * @retval none
  * @note   If Event is ADC_TriggerEvent_PWMX then User must also configure
  *         the PWMXINTEN register in the dedicated PWM Module (page 1713; Not
  *         the timers section). The responsability of such configuration 
  *         lies on drivers for that peripheral. 
  */
void ADC_ConfigTriggerEvent(ADC_RegDef_t *pADC, uint8_t Sequencer, uint8_t Event);

/**
  * @brief  Configures the sample sequencer priority
  * @param  pADC: ADC0 or ADC1
  * @param  Prio0: Value from @ADC_Sequencer_Prio
  * @param  Prio1: Value from @ADC_Sequencer_Prio
  * @param  Prio2: Value from @ADC_Sequencer_Prio
  * @param  Prio3: Value from @ADC_Sequencer_Prio
  * @retval none
  * @note   Each priority value must be different for the ADC to operate properly
  * @note   Lower priority value means higher urgency
  */
void ADC_ConfigSequencerPriority(ADC_RegDef_t *pADC, uint8_t Prio0, uint8_t Prio1, uint8_t Prio2, uint8_t Prio3);

/**
  * @brief  Configures the sampling delay/phase respect to the standard for the ADC
  *         modules in this board
  * @param  pADC: ADC0 or ADC1
  * @param  Phase: Value from 0U to 15U, measured in ADC clock cycles of delay,
  *                where 0 is the standard.
  * @retval none
  */
void ADC_ConfigSamplingPhase(ADC_RegDef_t *pADC, uint8_t Phase);

/**
  * @brief  Initiates sampling on ADC modules that have been initialized and are
  *         waiting for synchronization (see ADC_ConfigSync)
  * @param  pADC: ADC0 or ADC1
  * @retval none
  */
void ADC_GlobalSyncStart(ADC_RegDef_t *pADC);

/**
  * @brief  Enables or disables waiting for synchronization
  * @param  pADC: ADC0 or ADC1
  * @param  Command: ENABLE or DISABLE
  * @retval none
  */
void ADC_ConfigSync(ADC_RegDef_t *pADC, uint8_t Command);

/**
  * @brief  Begins sampling on a given sequencer within an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Sequencer: Value from @ADC_Sequencer
  * @retval none
  */
void ADC_InitiateSequencer(ADC_RegDef_t *pADC, uint8_t Sequencer);

/**
  * @brief  Configures hardware oversampling for an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Oversampling: Value from @ADC_Oversampling
  * @retval none
  */
void ADC_ConfigOversampling(ADC_RegDef_t *pADC, uint8_t Oversampling);

/**
  * @brief  Configures Interrupts based on Digital Comparators
  * @param  pADC: ADC0 or ADC1
  * @param  Command: ENABLE or DISABLE
  * @param  Comparator: Value from @ADC_Comparator
  * @retval none
  */
void ADC_ConfigComparatorIT(ADC_RegDef_t *pADC, uint8_t Command, uint8_t Comparator);

/**
  * @brief  Enables or Disables external references
  * @param  pADC: ADC0 or ADC1
  * @param  Command: ENABLE or DISABLE
  * @retval none
  * @note   This value applies to all ADC modules
  */
void ADC_ConfigExternalReference(ADC_RegDef_t *pADC, uint8_t Command);

/**
  * @brief  Configures a given Sample within a Sequencer for an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  pSample: A configuration structure that holds information about the sample
  * @retval none
  */
void ADC_ConfigSample(ADC_RegDef_t *pADC, ADC_Sample_t* pSample);

/**
  * @brief  Reads a value from a given FIFO in an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval Value in the requested FIFO buffer
  * @note   The value in FIFON corresponds to SequencerN
  */
uint16_t ADC_ReadValue(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Checks if a given FIFO is full
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval SET if full, otherwise RESET
  * @note   The value in FIFON corresponds to SequencerN
  */
uint8_t ADC_CheckFifoFullness(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Checks if a given FIFO is empty
  * @param  pADC: ADC0 or ADC1
  * @param  Fifo: Value from @ADC_FIFO
  * @retval SET if empty, otherwise RESET
  * @note   The value in FIFON corresponds to SequencerN
  */
uint8_t ADC_CheckFifoEmptiness(ADC_RegDef_t *pADC, uint8_t Fifo);

/**
  * @brief  Resets initial conditions of a digital comparator within
  *         an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  Comparator: Value from @ADC_Comparator
  * @retval none
  * @note   It is important to clear initial conditions to avoid stale data
  */
 void ADC_ComparatorResetInitialCond(ADC_RegDef_t *pADC, uint8_t Comparator);

/**
  * @brief  Configures a comparator within an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  pCOMP: A pointer to a structure that holds information about the comparator 
  *                and its configuration properties
  * @param  low: Threshold for the low-band region
  * @param  high: Threshold for the high-band region
  * @retval none
  */
void ADC_ConfigComparator(ADC_RegDef_t *pADC, ADC_Comparator_t *pComp, uint16_t low, uint16_t high);

/**
  * @brief  Selects the PLL VCO divider
  * @param  pADC: ADC0 or ADC1
  * @param  Divisor: Value from 0U to 0x3FU. The value programmed
  *         into this register is added by one. For example:
  *         Divisor = 0 causes a division by 1
  *         Divisor = 1 causes a divison by 2
  *         Divisor = 2 causes a divison by 3
  *         Divisor = N causes a division by (N+1)
  * @retval none
  * @note   Only applies to PLL VCO (see ADC_ConfigClockSource())
  */
void ADC_ConfigClockDivisor(ADC_RegDef_t *pADC, uint8_t Divisor);

/**
  * @brief  Selects the clock source for an ADC module
  * @param  pADC: ADC0 or ADC1
  * @param  ClockSource: Value from @ADC_ClockSource
  * @retval none
  */
void ADC_ConfigClockSource(ADC_RegDef_t *pADC, uint8_t ClockSource);
