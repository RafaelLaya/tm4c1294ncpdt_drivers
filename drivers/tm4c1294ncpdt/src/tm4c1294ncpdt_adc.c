/*
 * Rafael Laya
 * 1975274
 * April 25th, 2020
 * Drivers for the analog to digital converter of the tm4c1294ncpdt board
 */

#include "tm4c1294ncpdt_adc.h"

void ADC_SequencerCommand(ADC_RegDef_t *pADC, uint8_t Command, uint8_t Sequencer) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(IS_COMMAND(Command));
    assert(ADC_IS_SEQUENCER(Sequencer));
    #endif
    pADC->ACTSS = (pADC->ACTSS & ~(SET << Sequencer)) | (Command << Sequencer);
}

void ADC_EnableDMA(ADC_RegDef_t *pADC, uint8_t Command,  uint8_t Sequencer) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(IS_COMMAND(Command));
    assert(ADC_IS_SEQUENCER(Sequencer));
    #endif
    uint8_t shiftVal = Sequencer + ADC_CACTSS_DMA_OFFSET;
    pADC->ACTSS = (pADC->ACTSS & ~(SET << shiftVal)) | (Command << shiftVal);
}

uint8_t ADC_ReadITRawStatus(ADC_RegDef_t *pADC, uint8_t Pos) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_IT_READ_POS(Pos));
    #endif
    return (pADC->RIS >> Pos) & SET;
}

uint32_t ADC_ReadITRawStatusByMask(ADC_RegDef_t *pADC, uint32_t Mask) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_ITMASK(Mask));
    #endif
    return (pADC->RIS & Mask) & ADC_ITMask_All;
}

uint8_t ADC_ReadITStatus(ADC_RegDef_t *pADC, uint8_t Pos) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_IT_READ_POS(Pos));
    #endif
    return (pADC->ISC >> Pos) & SET;
}

uint32_t ADC_ReadITStatusByMask(ADC_RegDef_t *pADC, uint32_t Mask) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_ITMASK(Mask));
    #endif
    return (pADC->ISC & Mask) & ADC_ITMask_All;
}

void ADC_IRQConfig(ADC_RegDef_t *pADC, uint8_t Command, uint8_t Pos) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(IS_COMMAND(Command));
    assert(ADC_IS_IT_READ_POS(Pos));
    #endif
    pADC->IM = (pADC->IM & ~(SET << Pos)) | (Command << Pos);
}

void ADC_ClearIT(ADC_RegDef_t *pADC, uint8_t Pos) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_IT_READ_POS(Pos));
    #endif
    pADC->ISC |= (SET << Pos);
}

void ADC_ClearITByMask(ADC_RegDef_t *pADC, uint32_t Mask) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_ITMASK(Mask));
    #endif
    pADC->ISC |= (Mask);
}

uint8_t ADC_CheckOverflow(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    return (pADC->OSTAT >> Fifo) & SET;
}

void ADC_ClearOverflow(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    pADC->OSTAT |= (SET << Fifo);
}

uint8_t ADC_CheckUnderflow(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    return (pADC->USTAT >> Fifo) & SET;
}

void ADC_ClearUnderflow(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    pADC->USTAT |= (SET << Fifo);
}

void ADC_ConfigTriggerEvent(ADC_RegDef_t *pADC, uint8_t Sequencer, uint8_t Event) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_SEQUENCER(Sequencer));
    assert(ADC_IS_TRIGGER_EVENT(Event));
    #endif
    uint8_t shiftVal = Sequencer << 2U;
    pADC->EMUX = (pADC->EMUX & ~(0xFU << shiftVal)) | (Event << shiftVal);
}

void ADC_ConfigSequencerPriority(ADC_RegDef_t *pADC, uint8_t Prio0, uint8_t Prio1, uint8_t Prio2, uint8_t Prio3) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_ONEHOT_PRIO(Prio0, Prio1, Prio2, Prio3));
    #endif
    uint32_t temp = pADC->SSPRI;
    temp = temp & ~(ADC_SSPRI_PRIO_ALL_MASK);
    temp = temp | (Prio0 << ADC_SSPRI_PRIO0_POS) | (Prio1 << ADC_SSPRI_PRIO1_POS) | \
                  (Prio2 << ADC_SSPRI_PRIO2_POS) | (Prio3 << ADC_SSPRI_PRIO3_POS);
}

void ADC_ConfigSamplingPhase(ADC_RegDef_t *pADC, uint8_t Phase) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_PHASE(Phase));
    #endif
    pADC->SPC = (pADC->SPC & ~(ADC_SPC_MASK)) | Phase;
}

void ADC_GlobalSyncStart(ADC_RegDef_t *pADC) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    #endif
    pADC->PSSI |= (SET << ADC_PSSI_GSYNC_POS);
}

void ADC_ConfigSync(ADC_RegDef_t *pADC, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(IS_COMMAND(Command));
    #endif
    pADC->PSSI = (pADC->PSSI & ~(SET << ADC_PSSI_SYNCWAIT_POS)) | (Command << ADC_PSSI_SYNCWAIT_POS);
}

void ADC_InitiateSequencer(ADC_RegDef_t *pADC, uint8_t Sequencer) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_SEQUENCER(Sequencer));
    #endif
    pADC->PSSI |= (SET << Sequencer);
}

void ADC_ConfigOversampling(ADC_RegDef_t *pADC, uint8_t Oversampling) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_OVERSAMPLING(Oversampling));
    #endif
    pADC->SAC = (pADC->SAC & ~(ADC_SAC_MASK)) | Oversampling;
}

uint8_t ADC_ReadComparatorITStatus(ADC_RegDef_t *pADC, uint8_t Comparator) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_COMPARATOR(Comparator));
    #endif
    return ((pADC->DCISC) >> Comparator) & SET;
}

void ADC_ClearComparatorIT(ADC_RegDef_t *pADC, uint8_t Comparator) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_COMPARATOR(Comparator));
    #endif
    pADC->DCISC &= ~(SET << Comparator);
}

void ADC_ConfigExternalReference(ADC_RegDef_t *pADC, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(IS_COMMAND(Command));
    #endif
    pADC->CTL = (pADC->CTL & ~(SET)) | Command;
}

uint16_t ADC_ReadValue(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    return (pADC->SS[Fifo].SSFIFO) & 0xFFFU;
}

uint8_t ADC_CheckFifoFullness(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    return ((pADC->SS[Fifo].SSFSTAT) >> ADC_SSFSTAT_FULL_POS) & SET;
}

uint8_t ADC_CheckFifoEmptiness(ADC_RegDef_t *pADC, uint8_t Fifo) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_FIFO(Fifo));
    #endif
    return ((pADC->SS[Fifo].SSFSTAT) >> ADC_SSFSTAT_EMPTY_POS) & SET;
}

 void ADC_ComparatorResetInitialCond(ADC_RegDef_t *pADC, uint8_t Comparator) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_COMPARATOR(Comparator));
    #endif
     pADC->DCRIC |= (SET << Comparator) | (SET << (Comparator + ADC_DCRIC_TRIG_OFFSET));
 }

void ADC_ConfigClockDivisor(ADC_RegDef_t *pADC, uint8_t Divisor) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_PLLVCO_DIVISOR(Divisor));
    #endif
    pADC->CC = (pADC->CC & ~(ADC_CC_CLKDIV_MASK)) | (Divisor << ADC_CC_CLKDIV_POS);
}

void ADC_ConfligClockSource(ADC_RegDef_t *pADC, uint8_t ClockSource) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_CLOCKSOURCE(ClockSource));
    #endif
    pADC->CC = (pADC->CC & ~(ADC_CC_CS_MASK)) | (ClockSource);
}

void ADC_ConfigComparator(ADC_RegDef_t *pADC, ADC_Comparator_t *pComp, uint16_t low, uint16_t high) {
    #if ASSERT_ENABLED
    assert(IS_ADC(pADC));
    assert(ADC_IS_SAMPLE_COMPARATOR(pComp->Comparator));
    assert(ADC_IS_COMPARISON_MODE(pComp->ITComparisonMode));
    assert(ADC_IS_COMPARISON_BAND(pComp->ITComparisonBand));
    assert(IS_COMMAND(pComp->ITComparisonCommand));
    assert(ADC_IS_COMPARISON_MODE(pComp->ComparisonTriggerMode));
    assert(ADC_IS_COMPARISON_BAND(pComp->ComparisonTriggerBand));
    assert(IS_COMMAND(pComp->ComparisonTriggerCommand));
    #endif

    // Set each one of the flags
    uint32_t temp = pADC->DCCTL[pComp->Comparator] & ~(ADC_DCCTL_MASK_ALL);
    temp |= pComp->ITComparisonMode << ADC_DCCTL_CIM_POS;
    temp |= pComp->ITComparisonBand << ADC_DCCTL_CIC_POS;
    temp |= pComp->ITComparisonCommand << ADC_DCCTL_CIE_POS;
    temp |= pComp->ComparisonTriggerMode << ADC_DCCTL_CTM_POS;
    temp |= pComp->ComparisonTriggerBand << ADC_DCCTL_CTC_POS;
    temp |= pComp->ComparisonTriggerCommand << ADC_DCCTL_CTE_POS;

    // Save the new register
    pADC->DCCTL[pComp->Comparator] = temp;

    // Configure the high and low thresholds
    temp = pADC->DCCMP[pComp->Comparator] & ~(ADC_DCCMP_COMP0_MASK) & ~(ADC_DCCMP_COMP1_MASK);
    temp |= low << ADC_DCCMP_COMP0_POS;
    temp |= high << ADC_DCCMP_COMP1_POS;
    pADC->DCCMP[pComp->Comparator] = temp;
}

void ADC_ConfigSample(ADC_RegDef_t *pADC, ADC_Sample_t* pSample) {
    #if ASSERT_ENABLED
    assert(ADC_IS_SEQUENCER(pSample->Sequencer));
    assert(ADC_IS_SAMPLE(pSample->Sample));
    assert(ADC_IS_SAMPLE_INPUT(pSample->Input));
    assert(IS_COMMAND(pSample->ITCommand));
    assert(IS_COMMAND(pSample->EndOfSequenceCommand));
    assert(ADC_IS_SAMPLE_COMPARATOR(pSample->Comparator));
    assert(ADC_IS_SAMPLE_HOLDWIDTH(pSample->HoldWidth));
    #endif

    // Find the correct sequencer
    ADC_SS_t *pSequencer = &(pADC->SS[pSample->Sequencer]);
    
    // It is common to shift by SampleNumber*4 within many of these registers
    uint8_t shiftVal = pSample->Sample << 2U;

    if (pSample->Input == ADC_Sample_Input_Temp) {
        // If on temperature mode, set temperature sensor and clear differential
        pSequencer->SSCTL &= ~(SET << (shiftVal + ADC_SSCTL_D_OFFSET));
        pSequencer->SSCTL |= (SET << (shiftVal + ADC_SSCTL_TS_OFFSET));
    } else {
        // Not in temperature mode, so clear this bit
        pSequencer->SSCTL &= ~(SET << (shiftVal + ADC_SSCTL_TS_OFFSET));

        // clear the MUX and EMUX values before settings these to the right values
        pSequencer->SSMUX &= ~(0xFU << shiftVal);
        pSequencer->SSEMUX &= ~(0x1 << shiftVal);

        if (pSample->Input >= ADC_Sample_Input_Pair0) {
            // If differential, set as differential
            pSequencer->SSCTL |= (SET << (shiftVal + ADC_SSCTL_D_OFFSET));

            // In differential mode there is never need for an extended MUX
            pSequencer->SSMUX = (pSequencer->SSMUX & ~(0xFU << shiftVal)) | ((pSample->Input - 30U) << shiftVal);
        } else {
            // If not differential, clear differential
            pSequencer->SSCTL &= ~(SET << (shiftVal + ADC_SSCTL_D_OFFSET));

            if (pSample->Input < ADC_Sample_Input_Analog16) {
                // If no need for extended MUX, set this directly
                pSequencer->SSMUX = (pSequencer->SSMUX & ~(0xFU << shiftVal)) | (pSample->Input << shiftVal);
            } else {
                // Otherwise, use the extended MUX
                pSequencer->SSEMUX |= SET << shiftVal;
                pSequencer->SSMUX = (pSequencer->SSMUX & ~(0xFU << shiftVal)) | ((pSample->Input - 16U) << shiftVal);
            }
        }
    }

    // Now set the rest of the settings individually
    if (pSample->ITCommand == ENABLE) {
        pSequencer->SSCTL |= SET << (shiftVal + ADC_SSCTL_IE_OFFSET);
    } else {
        pSequencer->SSCTL &= ~(SET << (shiftVal + ADC_SSCTL_IE_OFFSET));
    }

    if (pSample->EndOfSequenceCommand == ENABLE) {
        pSequencer->SSCTL |= SET << (shiftVal + ADC_SSCTL_END_OFFSET);
    } else {
        pSequencer->SSCTL &= ~(SET << (shiftVal + ADC_SSCTL_END_OFFSET));
    }

    if(pSample->Comparator != ADC_Sample_Comparator_Disabled) {
        pSequencer->SSOP |= (SET << shiftVal);
        pSequencer->SSDC = (pSequencer->SSDC & ~(0xF << shiftVal)) | (pSample->Comparator << shiftVal);
    } else {
        pSequencer->SSOP &= ~(SET << shiftVal);
    }

    pSequencer->SSTSH = (pSequencer->SSTSH & ~(0xF << shiftVal)) | (pSample->HoldWidth << shiftVal);
}