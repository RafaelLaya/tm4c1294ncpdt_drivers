/*
 * Rafael Laya
 * 1975274
 * April 12th, 2020
 * Contains device-specific definitions for registers based on the
 * TM4C1294NCPDT
 */

#ifndef __TM4C1294NCPDT_H__
#define __TM4C1294NCPDT_H__

/*************************** Dependencies ************************************/
#include <stdint.h>
#include "tm4c1294ncpdt_config.h"

#if (ASSERT_ENABLED)
#include <assert.h>
#endif
/*************************** END Dependencies ********************************/

/*************************** Short-Hand notations ****************************/
// Signify Read, Write, Read-Write permissions (respectively)
#define __R         volatile const
#define __W         volatile
#define __RW        volatile

// Short-hand for volatile
#define __vo        volatile
/*********************** END Short-Hand notations ****************************/

/***************************** Base Addresses *******************************/
#define SYSCTL_BASE                     0x400FE000UL

#define NVIC_BASE                       0xE000E000UL

#define GPIO_PORTA_BASE                      0x40058000UL
#define GPIO_PORTB_BASE                      0x40059000UL
#define GPIO_PORTC_BASE                      0x4005A000UL
#define GPIO_PORTD_BASE                      0x4005B000UL
#define GPIO_PORTE_BASE                      0x4005C000UL
#define GPIO_PORTF_BASE                      0x4005D000UL
#define GPIO_PORTG_BASE                      0x4005E000UL
#define GPIO_PORTH_BASE                      0x4005F000UL
#define GPIO_PORTJ_BASE                      0x40060000UL
#define GPIO_PORTK_BASE                      0x40061000UL
#define GPIO_PORTL_BASE                      0x40062000UL
#define GPIO_PORTM_BASE                      0x40063000UL
#define GPIO_PORTN_BASE                      0x40064000UL
#define GPIO_PORTP_BASE                      0x40065000UL
#define GPIO_PORTQ_BASE                      0x40066000UL

#define TIM_TIMER0_BASE                     0x40030000UL
#define TIM_TIMER1_BASE                     0x40031000UL
#define TIM_TIMER2_BASE                     0x40032000UL
#define TIM_TIMER3_BASE                     0x40033000UL
#define TIM_TIMER4_BASE                     0x40034000UL
#define TIM_TIMER5_BASE                     0x40035000UL
#define TIM_TIMER6_BASE                     0x400E0000UL
#define TIM_TIMER7_BASE                     0x400E1000UL

#define ADC_ADC0_BASE                       0x40038000UL
#define ADC_ADC1_BASE                       0x40039000UL

#define UART_UART0_BASE                     0x4000C000UL
#define UART_UART1_BASE                     0x4000D000UL
#define UART_UART2_BASE                     0x4000E000UL
#define UART_UART3_BASE                     0x4000F000UL
#define UART_UART4_BASE                     0x40010000UL
#define UART_UART5_BASE                     0x40011000UL
#define UART_UART6_BASE                     0x40012000UL
#define UART_UART7_BASE                     0x40013000UL

/**************************** END Base Addresses ****************************/

/**************************** IRQ Numbers  ************************************/
/* @IRQNumber_type */
typedef enum {
    GPIOA_IRQNumber = 0,
    GPIOB_IRQNumber = 1,
    GPIOC_IRQNumber = 2,
    GPIOD_IRQNumber = 3,
    GPIOE_IRQNumber = 4,
    UART0_IRQNumber = 5,
    UART1_IRQNumber = 6,
    ADC0_Sequence0_IRQNumber = 14,
    ADC0_Sequence1_IRQNumber = 15,
    ADC0_Sequence2_IRQNumber = 16,
    ADC0_Sequence3_IRQNumber = 17,
    TIM0A_IRQNumber = 19,
    TIM0B_IRQNumber = 20,
    TIM1A_IRQNumber = 21,
    TIM1B_IRQNumber = 22,
    TIM2A_IRQNumber = 23,
    TIM2B_IRQNumber = 24,
    GPIOF_IRQNumber = 30,
    GPIOG_IRQNumber = 31,
    GPIOH_IRQNumber = 32,
    UART2_IRQNumber = 33,
    TIM3A_IRQNumber = 35,
    TIM3B_IRQNumber = 36,
    ADC1_Sequence0_IRQNumber = 46,
    ADC1_Sequence1_IRQNumber = 47,
    ADC1_Sequence2_IRQNumber = 48,
    ADC1_Sequence3 = 49,
    GPIOJ_IRQNumber = 51,
    GPIOK_IRQNumber = 52,
    GPIOL_IRQNumber = 53,
    UART3_IRQNumber = 56,
    UART4_IRQNumber = 57,
    UART5_IRQNumber = 58,
    UART6_IRQNumber = 59,
    UART7_IRQNumber = 60,
    TIM4A_IRQNumber = 63,
    TIM4B_IRQNumber = 64,
    TIM5A_IRQNumber = 65,
    TIM5B_IRQNumber = 66,
    GPIOM_IRQNumber = 72,
    GPION_IRQNumber = 73,
    GPIOP_IRQNumber = 76,
    GPIOP1_IRQNumber = 77,
    GPIOP2_IRQNumber = 78,
    GPIOP3_IRQNumber = 79,
    GPIOP4_IRQNumber = 80,
    GPIOP5_IRQNumber = 81,
    GPIOP6_IRQNumber = 82,
    GPIOP7_IRQNumber = 83,
    GPIOQ_IRQNumber = 84,
    GPIOQ1_IRQNumber = 85,
    GPIOQ2_IRQNumber = 86,
    GPIOQ3_IRQNumber = 87,
    GPIOQ4_IRQNumber = 88,
    GPIOQ5_IRQNumber = 89,
    GPIOQ6_IRQNumber = 90,
    GPIOQ7_IRQNumber = 91,
    TIM6A_IRQNumber = 98,
    TIM6B_IRQNumber = 99,
    TIM7A_IRQNumber = 100,
    TIM7B_IRQNumber = 101
} IRQNumber_type;
/**************************** END IRQ Numbers *********************************/

/***************************** SYSCTL *****************************/
#define SYSCTL_RCGCGPIO_OFFSET      0x608U
#define SYSCTL_RCGCGPIO_ADDR       (SYSCTL_BASE + SYSCTL_RCGCGPIO_OFFSET)
#define SYSCTL_RCGCGPIO            (*((__vo uint32_t *) (SYSCTL_RCGCGPIO_ADDR)))

#define SYSCTL_SRGPIO_OFFSET        0x508U
#define SYSCTL_SRGPIO_ADDR         (SYSCTL_BASE + SYSCTL_SRGPIO_OFFSET)
#define SYSCTL_SRGPIO              (*((__vo uint32_t *) (SYSCTL_SRGPIO_ADDR)))

#define SYSCTL_PRGPIO_OFFSET        0xA08
#define SYSCTL_PRGPIO_ADDR         (SYSCTL_BASE + SYSCTL_PRGPIO_OFFSET)
#define SYSCTL_PRGPIO              (*((__vo uint32_t *) (SYSCTL_PRGPIO_ADDR)))

#define SYSCTL_RCGCUART_OFFSET      0x618U
#define SYSCTL_RCGCUART_ADDR       (SYSCTL_BASE + SYSCTL_RCGCUART_OFFSET)
#define SYSCTL_RCGCUART            (*((__vo uint32_t *) (SYSCTL_RCGCUART_ADDR)))

#define SYSCTL_SRUART_OFFSET        0x518U
#define SYSCTL_SRUART_ADDR         (SYSCTL_BASE + SYSCTL_SRUART_OFFSET)
#define SYSCTL_SRUART              (*((__vo uint32_t *) (SYSCTL_SRUART_ADDR)))

#define SYSCTL_PRUART_OFFSET        0xA18
#define SYSCTL_PRUART_ADDR         (SYSCTL_BASE + SYSCTL_PRUART_OFFSET)
#define SYSCTL_PRUART              (*((__vo uint32_t *) (SYSCTL_PRUART_ADDR)))


#define SYSCTL_RCGCTIMER_OFFSET      0x604U
#define SYSCTL_RCGCTIMER_ADDR        (SYSCTL_BASE + SYSCTL_RCGCTIMER_OFFSET)
#define SYSCTL_RCGCTIMER             (*((__vo uint32_t *) (SYSCTL_RCGCTIMER_ADDR)))

#define SYSCTL_SRTIMER_OFFSET        0x504U
#define SYSCTL_SRTIMER_ADDR          (SYSCTL_BASE + SYSCTL_SRTIMER_OFFSET)
#define SYSCTL_SRTIMER               (*((__vo uint32_t *) (SYSCTL_SRTIMER_ADDR)))

#define SYSCTL_PRTIMER_OFFSET        0xA04
#define SYSCTL_PRTIMER_ADDR          (SYSCTL_BASE + SYSCTL_PRTIMER_OFFSET)
#define SYSCTL_PRTIMER               (*((__vo uint32_t *) (SYSCTL_PRTIMER_ADDR)))


#define SYSCTL_RCGCADC_OFFSET      0x638U
#define SYSCTL_RCGCADC_ADDR        (SYSCTL_BASE + SYSCTL_RCGCADC_OFFSET)
#define SYSCTL_RCGCADC             (*((__vo uint32_t *) (SYSCTL_RCGCADC_ADDR)))

#define SYSCTL_SRADC_OFFSET        0x538U
#define SYSCTL_SRADC_ADDR          (SYSCTL_BASE + SYSCTL_SRADC_OFFSET)
#define SYSCTL_SRADC               (*((__vo uint32_t *) (SYSCTL_SRADC_ADDR)))

#define SYSCTL_PRADC_OFFSET        0xA38U
#define SYSCTL_PRADC_ADDR          (SYSCTL_BASE + SYSCTL_PRADC_OFFSET)
#define SYSCTL_PRADC               (*((__vo uint32_t *) (SYSCTL_PRADC_ADDR)))



/**************************** END SYSCTL *************************************/

/********************************** GPIO *************************************/

// GPIO_RegDef simplifies access to registers from each GPIO port
// Ex: GPIOA->DIR accesses the DIR register in port A
typedef struct {
    __R uint32_t __res0[1];
    __RW uint32_t PIN0;
    __RW uint32_t PIN1;
    __R uint32_t __res1[1];
    __RW uint32_t PIN2;
    __R uint32_t __res2[3];
    __RW uint32_t PIN3;
    __R uint32_t __res4[7];
    __RW uint32_t PIN4;
    __R uint32_t __res5[15];
    __RW uint32_t PIN5;
    __R uint32_t __res6[31];
    __RW uint32_t PIN6;
    __R uint32_t __res7[63];
    __RW uint32_t PIN7;
    __R uint32_t __res8[126];
    __RW uint32_t PINS;
    __RW uint32_t DIR;
    __RW uint32_t IS;
    __RW uint32_t IBE;
    __RW uint32_t IEV;
    __RW uint32_t IM;
    __R uint32_t RIS;
    __R uint32_t MIS;
    __W uint32_t ICR;
    __RW uint32_t AFSEL;
    __R uint32_t __res9[55];
    __RW uint32_t DR2R;
    __RW uint32_t DR4R;
    __RW uint32_t DR8R;
    __RW uint32_t ODR;
    __RW uint32_t PUR;
    __RW uint32_t PDR;
    __RW uint32_t SLR;
    __RW uint32_t DEN;
    __RW uint32_t LOCK;
    __RW uint32_t CR;
    __RW uint32_t AMSEL;
    __RW uint32_t PCTL;
    __RW uint32_t ADCCTL;
    __RW uint32_t DMACTL;
    __RW uint32_t SI;
    __RW uint32_t DR12R;
    __RW uint32_t WAKEPEN;
    __RW uint32_t WAKELVL;
    __R uint32_t WAKESTAT;
    __R uint32_t __res10[669];
    __R uint32_t PP;
    __RW uint32_t PC;
    __R uint32_t __res11[2];
    __R uint32_t PeriphID4;
    __R uint32_t PeriphID5;
    __R uint32_t PeriphID6;
    __R uint32_t PeriphID7;
    __R uint32_t PeriphID0;
    __R uint32_t PeriphID1;
    __R uint32_t PeriphID2;
    __R uint32_t PeriphID3;
    __R uint32_t CellID0;
    __R uint32_t CellID1;
    __R uint32_t CellID2;
    __R uint32_t CellID3;
} GPIO_RegDef_t;

// Each GPIOx points to the corresponding GPIO Port x
#define GPIOA           ((GPIO_RegDef_t *) (GPIO_PORTA_BASE))
#define GPIOB           ((GPIO_RegDef_t *) (GPIO_PORTB_BASE))
#define GPIOC           ((GPIO_RegDef_t *) (GPIO_PORTC_BASE))
#define GPIOD           ((GPIO_RegDef_t *) (GPIO_PORTD_BASE))
#define GPIOE           ((GPIO_RegDef_t *) (GPIO_PORTE_BASE))
#define GPIOF           ((GPIO_RegDef_t *) (GPIO_PORTF_BASE))
#define GPIOG           ((GPIO_RegDef_t *) (GPIO_PORTG_BASE))
#define GPIOH           ((GPIO_RegDef_t *) (GPIO_PORTH_BASE))
#define GPIOJ           ((GPIO_RegDef_t *) (GPIO_PORTJ_BASE))
#define GPIOK           ((GPIO_RegDef_t *) (GPIO_PORTK_BASE))
#define GPIOL           ((GPIO_RegDef_t *) (GPIO_PORTL_BASE))
#define GPIOM           ((GPIO_RegDef_t *) (GPIO_PORTM_BASE))
#define GPION           ((GPIO_RegDef_t *) (GPIO_PORTN_BASE))
#define GPIOP           ((GPIO_RegDef_t *) (GPIO_PORTP_BASE))
#define GPIOQ           ((GPIO_RegDef_t *) (GPIO_PORTQ_BASE))
/******************************** END GPIO ************************************/

/************************************ NVIC ************************************/
typedef struct {
    __R uint32_t __res0[64];
    __RW uint32_t EN[4];
    __R uint32_t __res1[28];
    __RW uint32_t DIS[4];
    __R uint32_t __res2[28];
    __RW uint32_t PEND[4];
    __R uint32_t __res3[28];
    __RW uint32_t UNPEND[4];
    __R uint32_t __res4[28];
    __RW uint32_t ACTIVE[4];
    __R uint32_t __res5[60];
    __RW uint32_t PRI[29];
    __R uint32_t __res6[675];
    __W uint32_t SWTRIG;
} NVIC_RegDef_t;

#define NVIC                ((NVIC_RegDef_t *) NVIC_BASE)

/******************************** END NVIC ************************************/

/************************** GENERAL PURPOSE TIMERS *****************************/

typedef struct {
    __RW uint32_t CFG;
    __RW uint32_t TAMR;
    __RW uint32_t TBMR;
    __RW uint32_t CTL;
    __RW uint32_t SYNC;
    __R uint32_t __res0[1];
    __RW uint32_t IMR;
    __R uint32_t RIS;
    __R uint32_t MIS;
    __W uint32_t ICR;
    __RW uint32_t TAILR;
    __RW uint32_t BILR;
    __RW uint32_t AMATCHR;
    __RW uint32_t BMATCHR;
    __RW uint32_t APR;
    __RW uint32_t BPR;
    __RW uint32_t APMR;
    __RW uint32_t BPMR;
    __R uint32_t TAR;
    __R uint32_t TBR;
    __RW uint32_t TAV;
    __RW uint32_t TBV;
    __R uint32_t RTCPD;
    __R uint32_t TAPS;
    __R uint32_t TBPS;
    __R uint32_t __res1[2];
    __RW uint32_t DMAEV;
    __RW uint32_t ADCEV;
    __R uint32_t __res2[979];
    __R uint32_t PP;
    __R uint32_t __res3[1];
    __RW uint32_t CC;
} TIM_RegDef_t;

#define TIM0                ((TIM_RegDef_t *) TIM_TIMER0_BASE)
#define TIM1                ((TIM_RegDef_t *) TIM_TIMER1_BASE)
#define TIM2                ((TIM_RegDef_t *) TIM_TIMER2_BASE)
#define TIM3                ((TIM_RegDef_t *) TIM_TIMER3_BASE)
#define TIM4                ((TIM_RegDef_t *) TIM_TIMER4_BASE)
#define TIM5                ((TIM_RegDef_t *) TIM_TIMER5_BASE)
#define TIM6                ((TIM_RegDef_t *) TIM_TIMER6_BASE)
#define TIM7                ((TIM_RegDef_t *) TIM_TIMER7_BASE)

#define IS_TIMER(X)         ((X) == TIM0 || \
                             (X) == TIM1 || \
                             (X) == TIM2 || \
                             (X) == TIM3 || \
                             (X) == TIM4 || \
                             (X) == TIM5 || \
                             (X) == TIM6 || \
                             (X) == TIM7)

/********************** END GENERAL PURPOSE TIMERS *****************************/

/********************** ANALOG TO DIGITAL CONVERTER ****************************/

typedef struct {
    __RW uint32_t SSMUX;
    __RW uint32_t SSCTL;
    __R uint32_t SSFIFO;
    __R uint32_t SSFSTAT;
    __RW uint32_t SSOP;
    __RW uint32_t SSDC;
    __RW uint32_t SSEMUX;
    __RW uint32_t SSTSH; 
} ADC_SS_t;

typedef struct {
    __RW uint32_t ACTSS;
    __R uint32_t RIS;
    __RW uint32_t IM;
    __RW uint32_t ISC;
    __RW uint32_t OSTAT;
    __RW uint32_t EMUX;
    __RW uint32_t USTAT;
    __RW uint32_t SSEL;
    __RW uint32_t SSPRI;
    __RW uint32_t SPC;
    __RW uint32_t PSSI;
    __R uint32_t __res0[1];
    __RW uint32_t SAC;
    __RW uint32_t DCISC;
    __RW uint32_t CTL;
    __R uint32_t __res1[1];
    ADC_SS_t SS[4]; 
    __R uint32_t __res2[784];
    __W uint32_t DCRIC;
    __R uint32_t __res3[63];
    __RW uint32_t DCCTL[8];
    __R uint32_t __res4[8];
    __RW uint32_t DCCMP[8];
    __R uint32_t __res5[88];
    __R uint32_t CPP;
    __RW uint32_t CPC;
    __RW uint32_t CC;
} ADC_RegDef_t;

#define ADC0                     ((ADC_RegDef_t *) ADC_ADC0_BASE)
#define ADC1                     ((ADC_RegDef_t *) ADC_ADC1_BASE)

#define IS_ADC(X)               ((X) == ADC0 || (X) == ADC1)
/********************** END ANALOG TO DIGITAL CONVERTER ************************/

/********************************** UART **************************************/

typedef struct {
    __RW uint32_t DR;
    __RW uint32_t RSR_ECR;
    __R uint32_t __res0[4];
    __R uint32_t FR;
    __R uint32_t __res1[1];
    __RW uint32_t ILPR;
    __RW uint32_t IBRD;
    __RW uint32_t FBRD;
    __RW uint32_t LCRH;
    __RW uint32_t CTL;
    __RW uint32_t IFLS;
    __RW uint32_t IM;
    __R uint32_t RIS;
    __R uint32_t MIS;
    __W uint32_t ICR;
    __RW uint32_t DMACTL;
    __R uint32_t __res2[22];
    __RW uint32_t BITADDR9;
    __RW uint32_t BITAMASK9; 
    __R uint32_t __res3[965];
    __R uint32_t PP;
    __R uint32_t __res4[1];
    __RW uint32_t CC;
    __R uint32_t __res5[1];
    __R uint32_t PeriphID4;
    __R uint32_t PeriphID5;
    __R uint32_t PeriphID6;
    __R uint32_t PeriphID7;
    __R uint32_t PeriphID0;
    __R uint32_t PeriphID1;
    __R uint32_t PeriphID2;
    __R uint32_t PeriphID3;
    __R uint32_t PCellID0;
    __R uint32_t PCellID1;
    __R uint32_t PCellID2;
    __R uint32_t PCellID3;
} UART_RegDef_t;

#define UART0                   ((UART_RegDef_t *) UART_UART0_BASE)
#define UART1                   ((UART_RegDef_t *) UART_UART1_BASE)
#define UART2                   ((UART_RegDef_t *) UART_UART2_BASE)
#define UART3                   ((UART_RegDef_t *) UART_UART3_BASE)
#define UART4                   ((UART_RegDef_t *) UART_UART4_BASE)
#define UART5                   ((UART_RegDef_t *) UART_UART5_BASE)
#define UART6                   ((UART_RegDef_t *) UART_UART6_BASE)
#define UART7                   ((UART_RegDef_t *) UART_UART7_BASE)

#define IS_UART(X)                 ((X) == UART0 || \
                                    (X) == UART1 || \
                                    (X) == UART2 || \
                                    (X) == UART3 || \
                                    (X) == UART4 || \
                                    (X) == UART5 || \
                                    (X) == UART6 || \
                                    (X) == UART7)

/****************************** END OF UART ***********************************/

/******************************** MISCELLANEOUS *******************************/
#define ENABLE          1U
#define DISABLE         0U
#define SET             1U
#define RESET           0U

#define IS_COMMAND(X)       ((X) == ENABLE || (X) == DISABLE)
/***************************** END MISCELLANEOUS ******************************/

#if INCLUDE_ALL_AUTOMATICALLY
#include "tm4c1294ncpdt_sysctl.h"
#include "tm4c1294ncpdt_nvic.h"
#include "tm4c1294ncpdt_gpio.h"
#include "tm4c1294ncpdt_tim.h"
#include "tm4c1294ncpdt_adc.h"
#include "tm4c1294ncpdt_uart.h"
#endif

#endif
