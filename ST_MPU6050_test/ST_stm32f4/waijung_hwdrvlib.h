/*
 * File: waijung_hwdrvlib.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model st.
 *
 * Model version                        : 1.151
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Sat Jul 12 02:02:51 2014
 * TLC version                          : 8.5 (Aug  6 2013)
 * C/C++ source code generated on       : Sat Jul 12 02:02:52 2014
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_waijung_hwdrvlib_h_
#define RTW_HEADER_waijung_hwdrvlib_h_
#include "rtwtypes.h"
#include "stm32f4xx.h"

/*
 * Bit banding
 *
 * The Cortex memory map includes two bit-band regions.
 * These regions map each word in an alias region of memory to a bit in
 * a bit-band region of memory. Writing to a word in the alias region
 * has the same effect as a read-modify-write operation on the targeted bit
 * in the bit-band region.
 *
 * In the STM32F4xxx both peripheral registers and SRAM are mapped in
 * a bit-band region. This allows single bit-band write and read operations
 * to be performed.
 *
 * A mapping formula shows how to reference each word in the alias region
 * to a corresponding bit in the bit-band region. The mapping formula is:
 * bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)
 *
 * BB_base      is the base address of the bit-band region for a register. (PERIPH_BB_BASE at 0x42000000 or SRAM_BB_BASE at 0x22000000)
 * Reg_base     is the base address of a register in the memory region. (PERIPH_BASE at 0x40000000 or SRAM_BASE at 0x20000000)
 * Register     is a register in the memory region that contains the targeted bit.
 * Bit_number   is the targeted bit number (0 - 31).
 *
 * PERIPH_BB_BASE, SRAM_BB_BASE, PERIPH_BASE, and SRAM_BASE are defined in stm32f10x.h
 *
 * Example for determining bit banding bit.
 * Determine DMA Transfer Complete Flag using bit banding.
 * TCIFx is the flag for DMA Channel x
 * This bit is set by hardware. It is cleared by software writing 1 to
 * the corresponding bit in the DMA_IFCR register.
 * TCIFx = 0: No transfer complete (TC) event on channel x
 * TCIFx = 1: A transfer complete (TC) event occurred on channel x
 *
 * DMA Channel:       1 2 3  4  5  6  7
 * Flag bit position: 1 5 9 13 17 21 25 (in DMA_ISR register)
 * (For DMA2 Channel 6 and 7 is irrelevant since it only has 5 channels.)
 *
 * CTCIFx: Channel x transfer complete clear (x = 1 ..7)
 * This bit is set and cleared by software.
 * CTCIFx = 0: No effect
 * CTCIFx = 1: Clear the corresponding TCIF flag in the DMA_ISR register
 *
 */
#define BitBanding(Register, Bit_number, Reg_base, BB_base) ((volatile uint32_t*) ((BB_base) + (((uint32_t) &(Register)) - ((Reg_base))<<5) + ((Bit_number)<<2)))
#define Peripheral_BB(Register, Bit_number) BitBanding(Register, Bit_number, PERIPH_BASE, PERIPH_BB_BASE)
#define SRAM_BB(Register, Bit_number)  BitBanding(Register, Bit_number, SRAM_BASE, SRAM_BB_BASE)

/*
 * Sample usage:
 * USART1->SR can be found from "stm32f4xx.h" and USART_FLAG_TC (6) can be found from "stm32f4xx_usart.h"
 * #define USART1_TC Peripheral_BB(USART1->SR, 6) USART_SR.TC bit
 *
 * Another example:
 * #define GPIOC_8 Peripheral_BB(GPIOC->ODR, 8)
 * *GPIOC_8 = 1;
 */

/*
 * Systick is configured such that the SysTick interrupt every 0.01 sec
 * which is the base sample time of the system.
 */
#define SYSTICKRELOADVALUE             1680000

/*
 * HCLK (Hz)
 */
#define HCLK                           168000000

/*
 * Each Systick counter is TIMEPERSYSTICK sec.
 */
#define TIMEPERSYSTICK                 0.01 / 1680000

extern volatile unsigned int systick_count;

/* ########################################################################
 * UART Utilities for packet processing
 * ########################################################################
 */
/* UART packet process struct */
typedef enum {
  txIdle = 0,
  txBusy
} UART_TX_STATE;

/* Data read structure */
typedef struct {
  uint16_t index;                      /* Index of data in buffer */
  uint16_t count;                      /* Return data count */
  uint8_t *buffer;                     /* Return buffer pointer of valid data */
} UARTRX_BUFFER_READ_STRUCT;

/* ########################################################################
 * Name: <S3>/UART Tx
 * Id: FailUARTTx
 * ########################################################################
 */
void enable_FailUARTTx(void);

/* ########################################################################
 * I2C transaction processing
 * ########################################################################
 */
typedef enum {
  I2C_OK = 0,
  I2C_TIMEOUT,
  I2C_NAK                              /* No ACK from device */
} I2C_RESULT;

#define I2C_OPTION_STOPBEFORE_RESTART  0x01

typedef struct {
  uint8_t options;
  uint8_t slaveaddress;
  uint8_t *readbuffer;
  uint8_t *writebuffer;
  uint16_t writecount;
  uint16_t readcount;
  uint32_t waitwritetime;              /* us */
} I2C_TRANSACTION;

I2C_RESULT i2c_trans_proc(I2C_TypeDef* I2Cx, uint32_t timeout, I2C_TRANSACTION
  *transaction);

/* ************************************************************************
 ** Name: <S8>/I2C Master Read//Write
 ** Id: L3G4200DInitL3G4200DI2CMasterReadWrite
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite;
extern uint8_t I2CMasterReadWrite_WBuffer[];
void enable_L3G4200DInitL3G4200DI2CMasterReadWrite(void);

/* ************************************************************************
 ** Name: <S8>/I2C Master Read//Write1
 ** Id: L3G4200DInitL3G4200DI2CMasterReadWrite1
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite1;
extern uint8_t I2CMasterReadWrite1_WBuffer[];
void enable_L3G4200DInitL3G4200DI2CMasterReadWrite1(void);

/* ************************************************************************
 ** Name: <S8>/I2C Master Read//Write2
 ** Id: L3G4200DInitL3G4200DI2CMasterReadWrite2
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite2_m;
extern uint8_t I2CMasterReadWrite2_m_WBuffer[];
void enable_L3G4200DInitL3G4200DI2CMasterReadWrite2(void);

/* ************************************************************************
 ** Name: <S9>/I2C Master Read//Write
 ** Id: L3G4200DReadL3G4200DI2CMasterReadWrite
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite_f;
extern uint8_t I2CMasterReadWrite_f_WBuffer[];
extern uint8_t I2CMasterReadWrite_f_RBuffer[];
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite(void);

/* ************************************************************************
 ** Name: <S9>/I2C Master Read//Write1
 ** Id: L3G4200DReadL3G4200DI2CMasterReadWrite1
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite1_f;
extern uint8_t I2CMasterReadWrite1_f_WBuffer[];
extern uint8_t I2CMasterReadWrite1_f_RBuffer[];
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite1(void);

/* ************************************************************************
 ** Name: <S9>/I2C Master Read//Write2
 ** Id: L3G4200DReadL3G4200DI2CMasterReadWrite2
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite2_g;
extern uint8_t I2CMasterReadWrite2_g_WBuffer[];
extern uint8_t I2CMasterReadWrite2_g_RBuffer[];
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite2(void);

/* ************************************************************************
 ** Name: <S9>/I2C Master Read//Write3
 ** Id: L3G4200DReadL3G4200DI2CMasterReadWrite3
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite3_g;
extern uint8_t I2CMasterReadWrite3_g_WBuffer[];
extern uint8_t I2CMasterReadWrite3_g_RBuffer[];
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite3(void);

/* ************************************************************************
 ** Name: <S9>/I2C Master Read//Write4
 ** Id: L3G4200DReadL3G4200DI2CMasterReadWrite4
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite4_e;
extern uint8_t I2CMasterReadWrite4_e_WBuffer[];
extern uint8_t I2CMasterReadWrite4_e_RBuffer[];
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite4(void);

/* ************************************************************************
 ** Name: <S9>/I2C Master Read//Write5
 ** Id: L3G4200DReadL3G4200DI2CMasterReadWrite5
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite5;
extern uint8_t I2CMasterReadWrite5_WBuffer[];
extern uint8_t I2CMasterReadWrite5_RBuffer[];
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite5(void);

/* ########################################################################
 * Name: <S5>/UART Tx
 * Id: SuccessUARTTx
 * ########################################################################
 */
void enable_SuccessUARTTx(void);

/* ########################################################################
 * Name: <Root>/UART Setup
 * Id: UARTSetup
 * ########################################################################
 */
#define UTX2_BUFFER_SIZE               512

extern uint8_t UART2_Tx_Buffer[];
extern UART_TX_STATE UARTSetup_Tx_State;
extern void UART2_TxUpdate(uint16_t count);
extern uint16_t UART2_GetInitNDTR(void);
void UART2_Read(UARTRX_BUFFER_READ_STRUCT *read_struct);
void UART2_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count);
extern void UART2_Write(uint8_t* data, uint16_t count);
extern UART_TX_STATE UART2_FlushTxBuffer(void);
void enable_UARTSetup(void);

/* ########################################################################
 * Timer
 * ########################################################################
 */
#define SYS_CURRENT_TICK               (SysTick->VAL)
#define SYS_TICKSTEP                   0.01f

typedef struct {
  uint32_t start;
  uint32_t length;
} SYS_TIMER_STRUCT;

#define SYSTIMER_FLAGS_TIMEOUT         0x01

typedef struct {
  uint8_t flags;
  uint32_t tid;                        /* Tick count */
  uint32_t tick;                       /* Capture cuttent tick */
  uint32_t target_us;                  /* Target of systick */
} SYS_TIMER_uS_STRUCT;

extern volatile unsigned int systick_count;
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms);
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us);
int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer);
int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer);
void SysTimer_delay_us(uint32_t us);

/* ************************************************************************
 ** Name: <S7>/I2C Master Read//Write2
 ** Id: L3G4200DGetInitL3G4200D1I2CMasterReadWrite2
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite2;
extern uint8_t I2CMasterReadWrite2_WBuffer[];
extern uint8_t I2CMasterReadWrite2_RBuffer[];
void enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite2(void);

/* ************************************************************************
 ** Name: <S7>/I2C Master Read//Write3
 ** Id: L3G4200DGetInitL3G4200D1I2CMasterReadWrite3
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite3;
extern uint8_t I2CMasterReadWrite3_WBuffer[];
extern uint8_t I2CMasterReadWrite3_RBuffer[];
void enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite3(void);

/* ************************************************************************
 ** Name: <S7>/I2C Master Read//Write4
 ** Id: L3G4200DGetInitL3G4200D1I2CMasterReadWrite4
 ** ************************************************************************
 */
extern I2C_TRANSACTION I2CMasterReadWrite4;
extern uint8_t I2CMasterReadWrite4_WBuffer[];
extern uint8_t I2CMasterReadWrite4_RBuffer[];
void enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite4(void);

/* ************************************************************************
 ** Name: <Root>/I2C Master Setup
 ** Id: I2CMasterSetup
 ** ************************************************************************
 */
#define I2C1_TIMEOUT_uS                25000                     /* Timeout, uS */
#define I2C1_TRANSACTION(t)            (i2c1_trans_proc(t))

I2C_RESULT i2c1_trans_proc(uint8_t slaveaddress, I2C_TRANSACTION *transaction);
void enable_I2CMasterSetup(void);
void disable_I2CMasterSetup(void);

#endif                                 /* RTW_HEADER_waijung_hwdrvlib_h_ */

/* [EOF] */
