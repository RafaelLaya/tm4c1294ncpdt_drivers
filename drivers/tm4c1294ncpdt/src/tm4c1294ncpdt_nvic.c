/*
 * Rafael Laya
 * 1975274
 * April 16th, 2020
 * NVIC Drivers for tm4c1294ncpdt
 */

#include "tm4c1294ncpdt_nvic.h"

void NVIC_EnableIRQ(IRQNumber_type IRQNumber) {
    #if ASSERT_ENABLED
    assert(NVIC_IS_IRQ_NUMBER(IRQNumber));
    #endif

    NVIC->EN[IRQNumber >> 5U] |= (0x1U << (IRQNumber & 0x1FU));
}

void NVIC_DisableIRQ(IRQNumber_type IRQNumber) {
    #if ASSERT_ENABLED
    assert(NVIC_IS_IRQ_NUMBER(IRQNumber));
    #endif

    NVIC->DIS[IRQNumber >> 5U] |= (0x1U << (IRQNumber & 0x1FU));
}

void NVIC_SetPendingIRQ(IRQNumber_type IRQNumber) {
    #if ASSERT_ENABLED
    assert(NVIC_IS_IRQ_NUMBER(IRQNumber));
    #endif

    NVIC->PEND[IRQNumber >> 5U] |= (0x1U << (IRQNumber & 0x1FU));
}

void NVIC_ClearPendingIRQ(IRQNumber_type IRQNumber) {
    #if ASSERT_ENABLED
    assert(NVIC_IS_IRQ_NUMBER(IRQNumber));
    #endif

    NVIC->UNPEND[IRQNumber >> 5U] |= (0x1U << (IRQNumber & 0x1FU));
}

void NVIC_SetPriority(IRQNumber_type IRQNumber, uint8_t Priority) {
    #if ASSERT_ENABLED
    assert(NVIC_IS_IRQ_NUMBER(IRQNumber));
    assert(NVIC_IS_PRIO(Priority));
    #endif

    uint32_t tempreg = NVIC->PRI[IRQNumber >> 2U];

    // Find the starting bit position
    uint8_t pos = (IRQNumber & 0x3U) << 3U;

    // Clear the priority
    uint8_t mask = (0xFFU & (0xFFU << (8U - NVIC_PRIO_BITS_IMPLEMENTED))) << pos;
    tempreg &= ~mask;

    // Set the priority
    tempreg |= ((Priority << (8U - NVIC_PRIO_BITS_IMPLEMENTED)) << pos) & mask;
    NVIC->PRI[IRQNumber >> 2U] = tempreg;
}
