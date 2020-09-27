#pragma once

#include "tm4c1294ncpdt.h"


/* @SYSCTL_RCGCGPIO_MASKS */
// These constants set the bit corresponding to each Port in the RCGCGPIO
// register of the SYSCTL
#define SYSCTL_RCGCGPIO_PORTA_MASK      0x0001U
#define SYSCTL_RCGCGPIO_PORTB_MASK      0x0002U
#define SYSCTL_RCGCGPIO_PORTC_MASK      0x0004U
#define SYSCTL_RCGCGPIO_PORTD_MASK      0x0008U
#define SYSCTL_RCGCGPIO_PORTE_MASK      0x0010U
#define SYSCTL_RCGCGPIO_PORTF_MASK      0x0020U
#define SYSCTL_RCGCGPIO_PORTG_MASK      0x0040U
#define SYSCTL_RCGCGPIO_PORTH_MASK      0x0080U
#define SYSCTL_RCGCGPIO_PORTJ_MASK      0x0100U
#define SYSCTL_RCGCGPIO_PORTK_MASK      0x0200U
#define SYSCTL_RCGCGPIO_PORTL_MASK      0x0400U
#define SYSCTL_RCGCGPIO_PORTM_MASK      0x0800U
#define SYSCTL_RCGCGPIO_PORTN_MASK      0x1000U
#define SYSCTL_RCGCGPIO_PORTP_MASK      0x2000U
#define SYSCTL_RCGCGPIO_PORTQ_MASK      0x4000U

// These masks correspond to the port where the user switches are: J
#define SYSCTL_RCGCGPIO_SW_MASK     SYSCTL_RCGCGPIO_PORTJ_MASK
#define SYSCTL_RCGCGPIO_SW1_MASK    SYSCTL_RCGCGPIO_SW_MASK
#define SYSCTL_RCGCGPIO_SW2_MASK    SYSCTL_RCGCGPIO_SW_MASK

// These masks correspond to the port where LEDS 1 and 2 are: N
#define SYSCTL_RCGCGPIO_D1_D2_MASK  SYSCTL_RCGCGPIO_PORTN_MASK
#define SYSCTL_RCGCGPIO_D1_MASK     SYSCTL_RCGCGPIO_D1_D2_MASK
#define SYSCTL_RCGCGPIO_D2_MASK     SYSCTL_RCGCGPIO_D1_D2_MASK

// These masks correspond to the port where LEDS 3 and 4 are: F
#define SYSCTL_RCGCGPIO_D3_D4_MASK  SYSCTL_RCGCGPIO_PORTF_MASK
#define SYSCTL_RCGCGPIO_D3_MASK     SYSCTL_RCGCGPIO_D3_D4_MASK
#define SYSCTL_RCGCGPIO_D4_MASK     SYSCTL_RCGCGPIO_D3_D4_MASK

// These constants set the corresponding bit of each port in the SRGPIO
// register of SYSCTL
#define SYSCTL_SRGPIO_PORTA_MASK      0x0001U
#define SYSCTL_SRGPIO_PORTB_MASK      0x0002U
#define SYSCTL_SRGPIO_PORTC_MASK      0x0004U
#define SYSCTL_SRGPIO_PORTD_MASK      0x0008U
#define SYSCTL_SRGPIO_PORTE_MASK      0x0010U
#define SYSCTL_SRGPIO_PORTF_MASK      0x0020U
#define SYSCTL_SRGPIO_PORTG_MASK      0x0040U
#define SYSCTL_SRGPIO_PORTH_MASK      0x0080U
#define SYSCTL_SRGPIO_PORTJ_MASK      0x0100U
#define SYSCTL_SRGPIO_PORTK_MASK      0x0200U
#define SYSCTL_SRGPIO_PORTL_MASK      0x0400U
#define SYSCTL_SRGPIO_PORTM_MASK      0x0800U
#define SYSCTL_SRGPIO_PORTN_MASK      0x1000U
#define SYSCTL_SRGPIO_PORTP_MASK      0x2000U
#define SYSCTL_SRGPIO_PORTQ_MASK      0x4000U

// These constants set the corresponding bit of each port in the PRGPIO
// register of SYSCTL
#define SYSCTL_PRGPIO_PORTA_MASK      0x0001U
#define SYSCTL_PRGPIO_PORTB_MASK      0x0002U
#define SYSCTL_PRGPIO_PORTC_MASK      0x0004U
#define SYSCTL_PRGPIO_PORTD_MASK      0x0008U
#define SYSCTL_PRGPIO_PORTE_MASK      0x0010U
#define SYSCTL_PRGPIO_PORTF_MASK      0x0020U
#define SYSCTL_PRGPIO_PORTG_MASK      0x0040U
#define SYSCTL_PRGPIO_PORTH_MASK      0x0080U
#define SYSCTL_PRGPIO_PORTJ_MASK      0x0100U
#define SYSCTL_PRGPIO_PORTK_MASK      0x0200U
#define SYSCTL_PRGPIO_PORTL_MASK      0x0400U
#define SYSCTL_PRGPIO_PORTM_MASK      0x0800U
#define SYSCTL_PRGPIO_PORTN_MASK      0x1000U
#define SYSCTL_PRGPIO_PORTP_MASK      0x2000U
#define SYSCTL_PRGPIO_PORTQ_MASK      0x4000U

// These masks correspond to the user switches for the PRGPIO register of SYSCTL
#define SYSCTL_PRGPIO_SW_MASK     SYSCTL_PRGPIO_PORTJ_MASK
#define SYSCTL_PRGPIO_SW1_MASK    SYSCTL_PRGPIO_SW_MASK
#define SYSCTL_PRGPIO_SW2_MASK    SYSCTL_PRGPIO_SW_MASK

// These masks correspond to the LEDs 1 and 2 for the PRGPIO register of SYSCTL
#define SYSCTL_PRGPIO_D1_D2_MASK  SYSCTL_PRGPIO_PORTN_MASK
#define SYSCTL_PRGPIO_D1_MASK     SYSCTL_PRGPIO_D1_D2_MASK
#define SYSCTL_PRGPIO_D2_MASK     SYSCTL_PRGPIO_D1_D2_MASK

// These masks correspond to the LEDs 3 and 4 for the PRGPIO register of SYSCTL
#define SYSCTL_PRGPIO_D3_D4_MASK  SYSCTL_PRGPIO_PORTF_MASK
#define SYSCTL_PRGPIO_D3_MASK     SYSCTL_PRGPIO_D3_D4_MASK
#define SYSCTL_PRGPIO_D4_MASK     SYSCTL_PRGPIO_D3_D4_MASK
#define SYSCTL_PRGPIO_D1_D2_POS      SYSCTL_PRGPIO_PORTN_POS  
#define SYSCTL_PRGPIO_D3_D4_POS      SYSCTL_PRGPIO_PORTF_POS
#define SYSCTL_PRGPIO_SW_POS         SYSCTL_PRGPIO_PORTJ_POS

// These correspond to the position of each bit corresponding to a GPIO port at the SYSCTL_PRGPIO port
#define SYSCTL_PRGPIO_PORTA_POS               0U
#define SYSCTL_PRGPIO_PORTB_POS               1U 
#define SYSCTL_PRGPIO_PORTC_POS               2U 
#define SYSCTL_PRGPIO_PORTD_POS               3U 
#define SYSCTL_PRGPIO_PORTE_POS               4U 
#define SYSCTL_PRGPIO_PORTF_POS               5U 
#define SYSCTL_PRGPIO_PORTG_POS               6U 
#define SYSCTL_PRGPIO_PORTH_POS               7U 
#define SYSCTL_PRGPIO_PORTJ_POS               8U 
#define SYSCTL_PRGPIO_PORTK_POS               9U 
#define SYSCTL_PRGPIO_PORTL_POS               10U 
#define SYSCTL_PRGPIO_PORTM_POS               11U 
#define SYSCTL_PRGPIO_PORTN_POS               12U 
#define SYSCTL_PRGPIO_PORTP_POS               13U 
#define SYSCTL_PRGPIO_PORTQ_POS               14U   


/* @SYSCTL_RCGCTIMER_MASKS */
// These constants set the bit corresponding to each Port in the RCGCTIMER
// register of the SYSCTL
#define SYSCTL_RCGCTIMER_TIM0_MASK      0x0001U
#define SYSCTL_RCGCTIMER_TIM1_MASK      0x0002U
#define SYSCTL_RCGCTIMER_TIM2_MASK      0x0004U
#define SYSCTL_RCGCTIMER_TIM3_MASK      0x0008U
#define SYSCTL_RCGCTIMER_TIM4_MASK      0x0010U
#define SYSCTL_RCGCTIMER_TIM5_MASK      0x0020U
#define SYSCTL_RCGCTIMER_TIM6_MASK      0x0040U
#define SYSCTL_RCGCTIMER_TIM7_MASK      0x0080U

/* @SYSCTL_SRTIMER_MASKS */
// These constants set the bit corresponding to each Port in the SRTIMER
// register of the SYSCTL
#define SYSCTL_SRTIMER_TIM0_MASK      0x0001U
#define SYSCTL_SRTIMER_TIM1_MASK      0x0002U
#define SYSCTL_SRTIMER_TIM2_MASK      0x0004U
#define SYSCTL_SRTIMER_TIM3_MASK      0x0008U
#define SYSCTL_SRTIMER_TIM4_MASK      0x0010U
#define SYSCTL_SRTIMER_TIM5_MASK      0x0020U
#define SYSCTL_SRTIMER_TIM6_MASK      0x0040U
#define SYSCTL_SRTIMER_TIM7_MASK      0x0080U

/* @SYSCTL_PRTIMER_POSITIONS */
#define SYSCTL_PRTIMER_TIM0_POS      0U
#define SYSCTL_PRTIMER_TIM1_POS      1U
#define SYSCTL_PRTIMER_TIM2_POS      2U
#define SYSCTL_PRTIMER_TIM3_POS      3U
#define SYSCTL_PRTIMER_TIM4_POS      4U
#define SYSCTL_PRTIMER_TIM5_POS      5U
#define SYSCTL_PRTIMER_TIM6_POS      6U
#define SYSCTL_PRTIMER_TIM7_POS      7U

/* @SYSCTL_PRADC_POSITIONS */
#define SYSCTL_PRADC_ADC0_POS           0U
#define SYSCTL_PRADC_ADC1_POS           1U

/* @SYSCTL_RCGCADC_MASK */
#define SYSCTL_RCGCADC_ADC0_MASK                0x1U
#define SYSCTL_RCGCADC_ADC1_MASK                0x2U

/* @SYSCTL_SRADC_MASK */
#define SYSCTL_SRADC_ADC0_MASK                0x1U
#define SYSCTL_SRADC_ADC1_MASK                0x2U

/* @SYSCTL_PRUART_POSITIONS */
#define SYSCTL_PRUART_UART0_POS                     0U
#define SYSCTL_PRUART_UART1_POS                     1U
#define SYSCTL_PRUART_UART2_POS                     2U
#define SYSCTL_PRUART_UART3_POS                     3U
#define SYSCTL_PRUART_UART4_POS                     4U
#define SYSCTL_PRUART_UART5_POS                     5U
#define SYSCTL_PRUART_UART6_POS                     6U
#define SYSCTL_PRUART_UART7_POS                     7U

/* @SYSCTL_RCGCUART_MASK */
#define SYSCTL_RCGCUART_UART0_MASK                  0x1U
#define SYSCTL_RCGCUART_UART1_MASK                  0x2U
#define SYSCTL_RCGCUART_UART2_MASK                  0x4U
#define SYSCTL_RCGCUART_UART3_MASK                  0x8U
#define SYSCTL_RCGCUART_UART4_MASK                  0x10U
#define SYSCTL_RCGCUART_UART5_MASK                  0x20U
#define SYSCTL_RCGCUART_UART6_MASK                  0x40U
#define SYSCTL_RCGCUART_UART7_MASK                  0x80U

/* @SYSCTL_SRUART_MASK */
#define SYSCTL_SRUART_UART0_MASK                  0x1U
#define SYSCTL_SRUART_UART1_MASK                  0x2U
#define SYSCTL_SRUART_UART2_MASK                  0x4U
#define SYSCTL_SRUART_UART3_MASK                  0x8U
#define SYSCTL_SRUART_UART4_MASK                  0x10U
#define SYSCTL_SRUART_UART5_MASK                  0x20U
#define SYSCTL_SRUART_UART6_MASK                  0x40U
#define SYSCTL_SRUART_UART7_MASK                  0x80U



// Macro for accessing the SRGPIO register
#define SYSCTL_SRGPIO_CMD(MASK, CMD)  do {                                     \
                                            if((CMD) == (SET)) {               \
                                                SYSCTL_SRGPIO |= (MASK);       \
                                            } else  {                          \
                                                SYSCTL_SRGPIO &= ~(MASK);      \
                                            }                                  \
                                        } while (0)

// Macro for accessing the RCGCGPIO register
#define SYSCTL_RCGCGPIO_CMD(MASK, CMD)  do {                                   \
                                            if((CMD) == (SET)) {               \
                                                SYSCTL_RCGCGPIO |= (MASK);     \
                                            } else  {                          \
                                                SYSCTL_RCGCGPIO &= ~(MASK);    \
                                            }                                  \
                                        } while (0)

// Macro for reading the PRGPIO register
#define SYSCTL_PRGPIO_READ(POS)             ((SYSCTL_PRGPIO >> (POS)) & 0x1U)

// Macro for accessing RCGCTIMER register
#define SYSCTL_RCGCTIMER_CMD(MASK, CMD)  do {                                           \
                                                if((CMD) == (SET)) {                    \
                                                    SYSCTL_RCGCTIMER |= (MASK);         \
                                                } else  {                               \
                                                    SYSCTL_RCGCTIMER &= ~(MASK);        \
                                                }                                       \
                                        } while (0)

// Macro for accessing SRTIMER register
#define SYSCTL_SRTIMER_CMD(MASK, CMD)  do {                                             \
                                                if((CMD) == (SET)) {                    \
                                                    SYSCTL_SRTIMER |= (MASK);           \
                                                } else  {                               \
                                                    SYSCTL_SRTIMER &= ~(MASK);          \
                                                }                                       \
                                        } while (0)

// Macro for reading PRTIMER register
#define SYSCTL_PRTIMER_READ(POS)                ((SYSCTL_PRTIMER >> (POS)) & 0x1U)

// Macros for asserts
#define SYSCTL_IS_GPIO_MASK(X)                      (((X) & ~(0x7FFFU)) == 0U)
#define SYSCTL_IS_TIM_MASK(X)                       (((X) & ~(0xFFU))   == 0U)



// Macro for accessing RCGCADC register
#define SYSCTL_RCGCADC_CMD(MASK, CMD)  do {                                           \
                                                if((CMD) == (SET)) {                  \
                                                    SYSCTL_RCGCADC |= (MASK);         \
                                                } else  {                             \
                                                    SYSCTL_RCGCADC &= ~(MASK);        \
                                                }                                     \
                                        } while (0)

// Macro for accessing SRADC register
#define SYSCTL_SRADC_CMD(MASK, CMD)  do {                                             \
                                                if((CMD) == (SET)) {                  \
                                                    SYSCTL_SRADC |= (MASK);           \
                                                } else  {                             \
                                                    SYSCTL_SRADC &= ~(MASK);          \
                                                }                                     \
                                        } while (0)

// Macro for reading PRADC register
#define SYSCTL_PRADC_READ(POS)                ((SYSCTL_PRADC >> (POS)) & 0x1U)

// Macro for accessing RCGCUART register
#define SYSCTL_RCGCUART_CMD(MASK, CMD)  do {                                           \
                                                if((CMD) == (SET)) {                   \
                                                    SYSCTL_RCGCUART |= (MASK);         \
                                                } else  {                              \
                                                    SYSCTL_RCGCUART &= ~(MASK);        \
                                                }                                      \
                                        } while (0)

// Macro for accessing SRUART register
#define SYSCTL_SRUART_CMD(MASK, CMD)  do {                                             \
                                                if((CMD) == (SET)) {                   \
                                                    SYSCTL_SRUART |= (MASK);           \
                                                } else  {                              \
                                                    SYSCTL_SRUART &= ~(MASK);          \
                                                }                                      \
                                        } while (0)

// Macro for reading PRUART register
#define SYSCTL_PRUART_READ(POS)                ((SYSCTL_PRUART >> (POS)) & 0x1U)
