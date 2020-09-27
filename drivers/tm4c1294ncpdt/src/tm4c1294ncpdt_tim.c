
#include "tm4c1294ncpdt_tim.h"

void TIM_PeriphClockCtrlByMask(uint32_t Mask, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(SYSCTL_IS_TIM_MASK(Mask));
    assert(IS_COMMAND(Command));
    #endif 
    SYSCTL_RCGCTIMER_CMD(Mask, Command);
}

void TIM_Init(TIM_RegDef_t *pTIM, TIM_Init_t *InitDef, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_PORT(Port));
    #endif

    // Clear the correct Timer before configuring
    if(Port == TIM_Port_A) {
        pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
    } else if(Port == TIM_Port_B) {
        pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
    } else if(Port == TIM_Port_Concatenated) {
        pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
        pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
    }

    // Select 32-bits (concatenated) or 16-bits (individual) mode
    if(Port == TIM_Port_A || Port == TIM_Port_B) {
        TIM_ConfigModule(pTIM, TIM_ModuleConfig_16BIT);
    } else {
        TIM_ConfigModule(pTIM, TIM_ModuleConfig_32BIT);
    }

    // Configure as Periodic or Oneshot
    if(InitDef->PeriodicModeCommand == ENABLE) {
        TIM_ConfigMode(pTIM, TIM_Mode_Periodic, Port);
    } else {
        TIM_ConfigMode(pTIM, TIM_Mode_OneShot, Port);
    }

    TIM_SnapshotCommand(pTIM, InitDef->TIM_SnapshotCommand, Port);
    TIM_ConfigWaitOnTrigger(pTIM, InitDef->TIM_WaitOnTriggerCommand, Port);
    TIM_ConfigDirection(pTIM, InitDef->TIM_Direction, Port);
    TIM_ConfigCompareAction(pTIM, InitDef->TIM_CompareAction, Port);
}

void TIM_EdgeInit(TIM_RegDef_t *pTIM, TIM_InitEdgeCount_t *pInitDef, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_INDIVIDUAL_PORT(Port));
    #endif

    // Clear the correct timer before configuring
    if(Port == TIM_Port_A) {
        pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
    } else if(Port == TIM_Port_B) {
        pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
    } else if(Port == TIM_Port_Concatenated) {
        pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
        pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
    }

    // Edge-count and edge-time only support individual timers
    TIM_ConfigModule(pTIM, TIM_ModuleConfig_16BIT);

    // Configure as edge-count or edg-etime
    if(pInitDef->TIM_EdgeCaptureMode == TIM_Mode_Capture_EdgeCount) {
        TIM_ConfigMode(pTIM, TIM_Mode_Capture_EdgeCount, Port);
    } else {
        TIM_ConfigMode(pTIM, TIM_Mode_Capture_EdgeTime, Port);
    }
    
    TIM_ConfigEventMode(pTIM, pInitDef->TIM_EdgeEvent, Port);
    TIM_ConfigDirection(pTIM, pInitDef->TIM_Direction, Port);
}

void TIM_PWMInit(TIM_RegDef_t *pTIM, uint8_t InvertedPWMCommand, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_INDIVIDUAL_PORT(Port));
    assert(IS_COMMAND(InvertedPWMCommand));
    #endif

    // Clear the correct timer before configuring
    if(Port == TIM_Port_A) {
        pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
    } else if(Port == TIM_Port_B) {
        pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
    } else if(Port == TIM_Port_Concatenated) {
        pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
        pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
    }

    TIM_ConfigModule(pTIM, TIM_ModuleConfig_16BIT);
    TIM_ConfigMode(pTIM, TIM_Mode_PWM, Port);
    TIM_ConfigInvertPWM(pTIM, InvertedPWMCommand, Port);
}

void TIM_ConfigModule(TIM_RegDef_t *pTIM, uint8_t ModuleConfig) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_MODULE_CONFIG(ModuleConfig));
    #endif

    pTIM->CFG = (pTIM->CFG & ~TIM_GPTMCFG_MASK) | ModuleConfig;
}

void TIM_ConfigMode(TIM_RegDef_t *pTIM, uint8_t ModeConfig, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_MODE(ModeConfig));
    assert(TIM_IS_PORT(Port));

    if(ModeConfig == TIM_Mode_Capture_EdgeCount || ModeConfig == TIM_Mode_Capture_EdgeTime || ModeConfig == TIM_Mode_PWM) {
        assert(TIM_IS_INDIVIDUAL_PORT(Port));
    } else if(ModeConfig == TIM_Mode_RTC) {
        assert(TIM_IS_CONCATENATED_PORT(Port));
    }
    #endif

    // Select the mode
    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        // First clear mode
        pTIM->TAMR &= ~(TIM_TNMR_MR_MASK);

        // Pick between Oneshort, Periodic, Edge-count, Edge-time, or RTC
        if(ModeConfig == TIM_Mode_OneShot) {
            pTIM->TAMR |= TIM_TNMR_MR_ONESHOT;
        } else if(ModeConfig == TIM_Mode_Periodic) {
            pTIM->TAMR |= TIM_TNMR_MR_PERIODIC;
        } else if(ModeConfig == TIM_Mode_Capture_EdgeCount) {
            pTIM->TAMR |= TIM_TNMR_MR_CAPTURE;
            // CMR differentiates between edge-count and edge-time
            pTIM->TAMR &= ~(TIM_TNMR_CMR_MASK);
        } else if(ModeConfig == TIM_Mode_Capture_EdgeTime) {
            pTIM->TAMR |= TIM_TNMR_MR_CAPTURE;
            // CMR differentiates between edge-count and edge-time
            pTIM->TAMR |= TIM_TNMR_CMR_MASK;
        } else if(ModeConfig == TIM_Mode_PWM) {
            // Enable PWM mode and clear CMR
            pTIM->TAMR |= TIM_TNMR_AMS_MASK;
            pTIM->TAMR &= ~(TIM_TNMR_CMR_MASK);
            // Set as periodic and clear the PWM Legacy Operation bit
            pTIM->TAMR |= TIM_TNMR_MR_PERIODIC;
            pTIM->TAMR &= ~(TIM_TNMR_PLO_MASK);
        } else if(ModeConfig == TIM_Mode_RTC) {
            // Module config is responsible for the CFG register
            // Here we only clear TAMR
            pTIM->TAMR &= ~(0xFFFFU);
        }
    } else {
        // Exactly as above, but for Timer B
        pTIM->TBMR &= ~(TIM_TNMR_MR_MASK);
        if(ModeConfig == TIM_Mode_OneShot) {
            pTIM->TBMR |= TIM_TNMR_MR_ONESHOT;
        } else if(ModeConfig == TIM_Mode_Periodic) {
            pTIM->TBMR |= TIM_TNMR_MR_PERIODIC;
        } else if(ModeConfig == TIM_Mode_Capture_EdgeCount) {
            pTIM->TBMR |= TIM_TNMR_MR_CAPTURE;
            pTIM->TBMR &= ~(TIM_TNMR_CMR_MASK);
        } else if(ModeConfig == TIM_Mode_Capture_EdgeTime) {
            pTIM->TBMR |= TIM_TNMR_MR_CAPTURE;
            pTIM->TBMR |= TIM_TNMR_CMR_MASK;
        } else if(ModeConfig == TIM_Mode_PWM) {
            pTIM->TBMR |= TIM_TNMR_AMS_MASK;
            pTIM->TBMR &= ~(TIM_TNMR_CMR_MASK);
            pTIM->TBMR |= TIM_TNMR_MR_PERIODIC;
            pTIM->TBMR &= ~(TIM_TNMR_PLO_MASK);
        } else if(ModeConfig == TIM_Mode_RTC) {
            pTIM->TBMR &= ~(0xFFFFU);
        }
    }
}

void TIM_SnapshotCommand(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->TAMR |= TIM_TNMR_SNAPS_MASK;
        } else {
            pTIM->TAMR &= ~(TIM_TNMR_SNAPS_MASK);
        } 
    } else {
        if(Command == ENABLE) {
            pTIM->TBMR |= TIM_TNMR_SNAPS_MASK;
        } else {
            pTIM->TBMR &= ~(TIM_TNMR_SNAPS_MASK);
        } 
    }
}
void TIM_ConfigDirection(TIM_RegDef_t *pTIM, uint8_t DirectionConfig, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_DIRECTION(DirectionConfig));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(DirectionConfig == TIM_Direction_UP) {
            pTIM->TAMR |= TIM_TNMR_DIR_MASK;
        } else {
            pTIM->TAMR &= ~(TIM_TNMR_DIR_MASK);
        }
    } else {
        if(DirectionConfig == TIM_Direction_UP) {
            pTIM->TBMR |= TIM_TNMR_DIR_MASK;
        } else {
            pTIM->TBMR &= ~(TIM_TNMR_DIR_MASK);
        }
    }
}

void TIM_ConfigMatchIT(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->TAMR |= TIM_TNMR_MIE_MASK;
        } else {
            pTIM->TAMR &= ~(TIM_TNMR_MIE_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->TBMR |= TIM_TNMR_MIE_MASK;
        } else {
            pTIM->TBMR &= ~(TIM_TNMR_MIE_MASK);
        }
    }
}

void TIM_ConfigWaitOnTrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->TAMR |= TIM_TNMR_TAWOT_MASK;
        } else {
            pTIM->TAMR &= ~(TIM_TNMR_TAWOT_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->TBMR |= TIM_TNMR_TAWOT_MASK;
        } else {
            pTIM->TBMR &= ~(TIM_TNMR_TAWOT_MASK);
        }
    }
}

void TIM_ConfigPWM_IT(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_INDIVIDUAL_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->TAMR |= TIM_TNMR_PWMIE_MASK;
        } else {
            pTIM->TAMR &= ~(TIM_TNMR_PWMIE_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->TBMR |= TIM_TNMR_PWMIE_MASK;
        } else {
            pTIM->TBMR &= ~(TIM_TNMR_PWMIE_MASK);
        }
    }
}

void TIM_ConfigMatchUpdate(TIM_RegDef_t *pTIM, uint8_t MatchUpdate, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_MATCH_UPDATE(MatchUpdate));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(MatchUpdate == TIM_MatchUpdate_NextCycle) {
            pTIM->TAMR &= ~(TIM_TNMR_MRSU_MASK);
        } else {
            pTIM->TAMR |= TIM_TNMR_MRSU_MASK;
        }
    } else {
        if(MatchUpdate == TIM_MatchUpdate_NextCycle) {
            pTIM->TBMR &= ~(TIM_TNMR_MRSU_MASK);
        } else {
            pTIM->TBMR |= TIM_TNMR_MRSU_MASK;
        }
    }
}

void TIM_ConfigTimeoutIT(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == DISABLE) {
            pTIM->TAMR |= TIM_TNMR_CICNTD_MASK;
        } else {
            pTIM->TAMR &= ~(TIM_TNMR_CICNTD_MASK);
        }
    } else {
        if(Command == DISABLE) {
            pTIM->TBMR |= TIM_TNMR_CICNTD_MASK;
        } else {
            pTIM->TBMR &= ~(TIM_TNMR_CICNTD_MASK);
        }
    }
}

void TIM_ConfigCompareAction(TIM_RegDef_t *pTIM, uint8_t CompareAction, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_COMPARE_ACTION(CompareAction));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        pTIM->TAMR = (pTIM->TAMR & ~(TIM_TNMR_TCACT_MASK)) | (CompareAction << TIM_TNMR_TCACT_POS);
    } else {
        pTIM->TBMR = (pTIM->TBMR & ~(TIM_TNMR_TCACT_MASK)) | (CompareAction << TIM_TNMR_TCACT_POS);
    }
}

void TIM_Command(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A) {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TAEN_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
        }
    } else if(Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TAEN_MASK;
            pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
        } else {
            pTIM->CTL &= ~(TIM_CTL_TAEN_MASK);
            pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TBEN_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TBEN_MASK);
        }
    }
}

void TIM_ConfigEventMode(TIM_RegDef_t *pTIM, uint8_t EventMode, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_EVENT_MODE(EventMode));
    assert(TIM_IS_PORT(Port));
    #endif
    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        pTIM->CTL = (pTIM->CTL & ~(TIM_CTL_TAEVENT_MASK)) | (EventMode << TIM_CTL_TAEVENT_POS);
    } else {
        pTIM->CTL = (pTIM->CTL & ~(TIM_CTL_TBEVENT_MASK)) | (EventMode << TIM_CTL_TBEVENT_POS);
    }
}

void TIM_EnableADCTrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TAOTE_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TAOTE_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TBOTE_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TBOTE_MASK);
        }
    }
}

void TIM_ConfigInvertPWM(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_INDIVIDUAL_PORT(Port));
    #endif

    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TAPWML_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TAPWML_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TBPWML_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TBPWML_MASK);
        }
    }
}

void TIM_IRQConfig(TIM_RegDef_t *pTIM, uint8_t Command, uint32_t IRQConfig) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_IRQ_MASK_COMBINATION(IRQConfig));
    #endif

    if(Command == ENABLE) {
        pTIM->IMR |= IRQConfig;
    } else {
        pTIM->IMR &= ~(IRQConfig);
    }
}

uint16_t TIM_ReadITStatusAll(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif

    return pTIM->MIS & 0xFFFFU;
}

uint8_t TIM_ReadITStatus(TIM_RegDef_t *pTIM, uint8_t ITReadPos) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_ITREAD_POS(ITReadPos));
    #endif
    return (pTIM->MIS >> ITReadPos) & 0x1U;
}

uint8_t TIM_ReadRawITStatus(TIM_RegDef_t *pTIM, uint8_t ITReadPos) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_ITREAD_POS(ITReadPos));
    #endif
    return (pTIM->RIS >> ITReadPos) & 0x1U;
}

uint16_t TIM_ReadRawITStatusAll(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif

    return pTIM->RIS & 0xFFFFU;
}

void TIM_ClearITAll(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->ICR |= (0x3FU | (0xFU << 8U) | (0x1U << 13U));
}

void TIM_ClearIT(TIM_RegDef_t *pTIM, uint8_t ITReadPos) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(TIM_IS_ITREAD_POS(ITReadPos));
    #endif
    pTIM->ICR |= (0x1 << ITReadPos);
}

void TIM_ConfigIntervalA(TIM_RegDef_t *pTIM, uint16_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->TAILR = val;
}

void TIM_ConfigIntervalB(TIM_RegDef_t *pTIM, uint16_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->BILR = val;
}

void TIM_ConfigIntervalConc(TIM_RegDef_t *pTIM, uint32_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->TAILR = val;
}

void TIM_ConfigMatchA(TIM_RegDef_t *pTIM, uint16_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->AMATCHR = val;
}

void TIM_ConfigMatchB(TIM_RegDef_t *pTIM, uint16_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->BMATCHR = val;
}

void TIM_ConfigPrescaleA(TIM_RegDef_t *pTIM, uint8_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->APR = val;
}

void TIM_ConfigPrescaleB(TIM_RegDef_t *pTIM, uint8_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->BPR = val;
}

void TIM_ConfigPrescaleMatchA(TIM_RegDef_t *pTIM, uint8_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->APMR = val;
}

void TIM_ConfigPrescaleMatchB(TIM_RegDef_t *pTIM, uint8_t val) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->BPMR = val;
}

uint16_t TIM_ReadRTCPrediv(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    uint32_t pre = (pTIM->RTCPD) & 0xFFFFU;

    // Make a read like stated in the datasheet (Page 1016.)
    (void) pTIM->TAR;
    (void) pTIM->TBR;
    (void) pTIM->RTCPD;
    return pre;
}

void TIM_ConfigAltClk(TIM_RegDef_t *pTIM, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    #endif
    if(Command == ENABLE) {
        pTIM->CC |= 0x1U;
    } else {
        pTIM->CC &= ~(0x1U);
    }
}

void TIM_ConfigDMATrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint32_t Mask) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_DMA_EVENT_MASK_COMBINATION(Mask));
    #endif
    if(Command == ENABLE) {
        pTIM->DMAEV |= Mask;
    } else {
        pTIM->DMAEV &= ~(Mask);
    }
}

void TIM_ConfigADCTrigger(TIM_RegDef_t *pTIM, uint8_t Command, uint32_t Mask) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_ADC_EVENT_MASK_COMBINATION(Mask));
    #endif
    if(Command == ENABLE) {
        pTIM->ADCEV |= Mask;
    } else {
        pTIM->ADCEV &= ~(Mask);
    }
}

void TIM_HaltOnDebug(TIM_RegDef_t *pTIM, uint8_t Command, uint8_t Port) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    assert(TIM_IS_PORT(Port));
    #endif
    if(Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TASTALL_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TASTALL_MASK);
        }
    } else {
        if(Command == ENABLE) {
            pTIM->CTL |= TIM_CTL_TBSTALL_MASK;
        } else {
            pTIM->CTL &= ~(TIM_CTL_TBSTALL_MASK);
        }
    }
}

void TIM_RTCHaltOnDebug(TIM_RegDef_t *pTIM, uint8_t Command) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    assert(IS_COMMAND(Command));
    #endif
    if(Command == ENABLE) {
        pTIM->CTL |= TIM_CTL_RTCEN_MASK;
    } else {
        pTIM->CTL &= ~(TIM_CTL_RTCEN_MASK);
    }
}

void TIM_RTCInit(TIM_RegDef_t *pTIM, uint32_t MatchValue, uint8_t Presc) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->CTL &= ~(TIM_CTL_TAEN_MASK | TIM_CTL_TBEN_MASK);

    TIM_ConfigMode(pTIM, TIM_Mode_RTC, TIM_Port_Concatenated);
    TIM_ConfigModule(pTIM, TIM_ModuleConfig_RTC);

    TIM_ConfigMatchA(pTIM, MatchValue);
    TIM_ConfigPrescaleMatchA(pTIM, Presc);
}

uint16_t TIM_ReadIntervalA(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->TAILR & 0xFFFFU;
}

uint16_t TIM_ReadIntervalB(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->BILR & 0xFFFFU;
}

uint32_t TIM_ReadIntervalConc(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->TAILR;
}

uint16_t TIM_ReadMatchA(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->AMATCHR & 0xFFFFU;
}

uint16_t TIM_ReadMatchB(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->BMATCHR & 0xFFFFU;
}

uint32_t TIM_ReadMatchConc(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->AMATCHR;
}

uint8_t TIM_ReadPrescA(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->APR & 0xFFU;
}

uint8_t TIM_ReadPrescB(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->BPR & 0xFFU;
}

uint8_t TIM_ReadMatchPrescA(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->APMR & 0xFFU;
}

uint8_t TIM_ReadMatchPrescB(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->BPMR & 0xFFU;
}

uint16_t TIM_ReadSnapshotPrescA(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->TAPS & 0xFFFFU;
}

uint16_t TIM_ReadSnapshotPrescB(TIM_RegDef_t *pTIM) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    return pTIM->TBPS & 0xFFFFU;
}

void TIM_LoadCountA(TIM_RegDef_t *pTIM, uint16_t count) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->TAV = (pTIM->TAR & ~(0xFFFFU)) | count;
}

void TIM_LoadCountB(TIM_RegDef_t *pTIM, uint16_t count) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->TBV = (pTIM->TBR & ~(0xFFFFU)) | count;
}

void TIM_LoadCountConc(TIM_RegDef_t *pTIM, uint32_t count) {
    #if ASSERT_ENABLED
    assert(IS_TIMER(pTIM));
    #endif
    pTIM->TAV = count;
}

 uint8_t TIM_ReadCounterStatus(TIM_RegDef_t *pTIM, uint8_t Port) {
     if (Port == TIM_Port_A || Port == TIM_Port_Concatenated) {
         return pTIM->TAMR & 0x1U;
     } else {
         return pTIM->TBMR & 0x1U;
     }
 }