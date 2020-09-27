
#pragma once
#include "tm4c1294ncpdt.h"

// Priority-limits Macros
#define NVIC_PRIO_BITS_IMPLEMENTED              3U
#define NVIC_PRIO_HIGHEST                       0U
#define NVIC_PRIO_LOWEST                        7U
#define NVIC_PRIO_MAX_NUMBER                    7U
#define NVIC_PRIO_MIN_NUMBER                    0U

// Special IRQ Numbers
#define NVIC_IRQ_MIN_NUMBER                     0U
#define NVIC_IRQ_MAX_NUMBER                     110U
#define NVIC_IRQ_RESERVED0                      68U
#define NVIC_IRQ_RESERVED1                      69U
#define NVIC_IRQ_RESERVED2                      74U
#define NVIC_IRQ_RESERVED3                      92U
#define NVIC_IRQ_RESERVED4                      93U
#define NVIC_IRQ_RESERVED5                      94U
#define NVIC_IRQ_RESERVED6                      95U
#define NVIC_IRQ_RESERVED7                      96U
#define NVIC_IRQ_RESERVED8                      97U
#define NVIC_IRQ_RESERVED9                      104U
#define NVIC_IRQ_RESERVED10                     105U
#define NVIC_IRQ_RESERVED11                     106U
#define NVIC_IRQ_RESERVED12                     107U
#define NVIC_IRQ_RESERVED13                     108U

// For checking parameters during development
#define NVIC_IS_PRIO(X)                          (NVIC_PRIO_MIN_NUMBER <= (X) && (X) <= NVIC_PRIO_MAX_NUMBER)
#define NVIC_IS_IRQ_NUMBER(X)                    (NVIC_IRQ_MIN_NUMBER <= (X) && \
                                                  (X) <= NVIC_IRQ_MAX_NUMBER && \
                                                  (X) != NVIC_IRQ_RESERVED0 &&  \
                                                  (X) != NVIC_IRQ_RESERVED1 &&  \
                                                  (X) != NVIC_IRQ_RESERVED2 &&  \
                                                  (X) != NVIC_IRQ_RESERVED3 &&  \
                                                  (X) != NVIC_IRQ_RESERVED4 &&  \
                                                  (X) != NVIC_IRQ_RESERVED5 &&  \
                                                  (X) != NVIC_IRQ_RESERVED6 &&  \
                                                  (X) != NVIC_IRQ_RESERVED7 &&  \
                                                  (X) != NVIC_IRQ_RESERVED8 &&  \
                                                  (X) != NVIC_IRQ_RESERVED9 &&  \
                                                  (X) != NVIC_IRQ_RESERVED10 && \
                                                  (X) != NVIC_IRQ_RESERVED11 && \
                                                  (X) != NVIC_IRQ_RESERVED12 && \
                                                  (X) != NVIC_IRQ_RESERVED13)

/**
  * @brief  Enables an IRQ within the NVIC by its IRQ Number
  * @param  IRQNumber: The Interrupt Number to enable. This is different from
                       the Vector Number. See  @IRQNumber_type for possible
                       values
  * @retval None
  */
void NVIC_EnableIRQ(IRQNumber_type IRQNumber);

/**
  * @brief  Disables an IRQ within the NVIC by its IRQ Number
  * @param  IRQNumber: The Interrupt Number to disable. This is different from
                       the Vector Number. See  @IRQNumber_type for possible
                       values
  * @retval None
  */
void NVIC_DisableIRQ(IRQNumber_type IRQNumber);

/**
  * @brief  Sets a pending IRQ within the NVIC by its IRQ Number
  * @param  IRQNumber: The Interrupt Number to disable. This is different from
                       the Vector Number. See  @IRQNumber_type for possible
                       values
  * @retval None
  */
void NVIC_SetPendingIRQ(IRQNumber_type IRQNumber);

/**
  * @brief  Clears a pending IRQ within the NVIC by its IRQ Number
  * @param  IRQNumber: The Interrupt Number to disable. This is different from
                       the Vector Number. See  @IRQNumber_type for possible
                       values
  * @retval None
  */
void NVIC_ClearPendingIRQ(IRQNumber_type IRQNumber);

/**
  * @brief  Sets the Priority of an IRQ within the NVIC
  * @param  IRQNumber: The Interrupt Number to disable. This is different from
                       the Vector Number. See  @IRQNumber_type for possible
                       values.
  * @param  Priority: Value from 0 to 7. Lower Priority Number results in
  *                   Higher priority.
  * @retval None
  */
void NVIC_SetPriority(IRQNumber_type IRQNumber, uint8_t Priority);
