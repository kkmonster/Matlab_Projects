/*
 * File: waijung_hwdrvlib.c
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

#include "waijung_hwdrvlib.h"

/* ########################################################################
 * Name: <S3>/UART Tx
 * Id: FailUARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_FailUARTTx(void)
{
}

/* ########################################################################
 * I2C transaction processing
 * ########################################################################
 */
SYS_TIMER_uS_STRUCT i2c_processing_timer;
I2C_RESULT i2c_trans_proc(I2C_TypeDef* I2Cx, uint32_t timeout, I2C_TRANSACTION
  *transaction)
{
  volatile uint16_t tmp;
  uint16_t NumByteWritten;
  uint16_t NumByteToRead;
  uint16_t i;
  I2C_RESULT sta = I2C_OK;

  /* Enable Acknowledgement */
  I2C_AcknowledgeConfig(I2Cx, ENABLE);

  /* WRITE */
  if ((transaction->writecount > 0) || ((transaction->writecount == 0) &&
       (transaction->readcount == 0))) {
    /* Check Busy flag */
    SysTimer_uS_Start(&i2c_processing_timer, timeout);
    while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY)) {
      if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {/* Timeout */
        sta = I2C_TIMEOUT;
        goto ____i2c_error;
      }
    }

    /* Clear I2C status */
    I2C_ClearFlag(I2Cx, I2C_FLAG_AF);

    /* Generate START */
    I2C_GenerateSTART(I2Cx, ENABLE);

    /* Test on EV5 and clear it */
    SysTimer_uS_Start(&i2c_processing_timer, timeout);
    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT)) {
      if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {/* Timeout */
        sta = I2C_TIMEOUT;
        goto ____i2c_error;
      }
    }

    /* Slave address */
    I2C_Send7bitAddress(I2Cx, (transaction->slaveaddress),
                        I2C_Direction_Transmitter);

    /* Test on EV6 and clear it */
    SysTimer_uS_Start(&i2c_processing_timer, timeout);
    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) {
      if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {/* Timeout */
        sta = I2C_TIMEOUT;
        goto ____i2c_error;
      } else {
        if (I2C_GetFlagStatus(I2Cx, I2C_FLAG_AF) == SET) {
          sta = I2C_NAK;
          goto ____i2c_error;
        }
      }
    }

    /* Write data */
    for (NumByteWritten=0; NumByteWritten<transaction->writecount;
         NumByteWritten++) {
      /* Send byte */
      I2C_SendData(I2Cx, transaction->writebuffer[NumByteWritten]);

      /* Test on BTF and clear it */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_BTF)) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {/* Timeout */
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        } else {
          if (I2C_GetFlagStatus(I2Cx, I2C_FLAG_AF) == SET) {
            sta = I2C_NAK;
            goto ____i2c_error;
          }
        }
      }
    }

    /* Wait till all data have been physically transferred on the bus */
    SysTimer_uS_Start(&i2c_processing_timer, timeout);
    while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_BTF)
           && (SysTimer_uS_IsTimeout(&i2c_processing_timer) == 0)) {
      /* Do nothing */
    }

    /* Send STOP condition, if no Read */
    if ((transaction->readcount <= 0) || SysTimer_uS_IsTimeout
        (&i2c_processing_timer) || ((transaction->options &
          I2C_OPTION_STOPBEFORE_RESTART) > 0)) {
      I2C_GenerateSTOP(I2Cx, ENABLE);
    }

    /* Check timeout */
    if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
      sta = I2C_TIMEOUT;
      goto ____i2c_error;
    }

    /* Write delay */
    SysTimer_uS_Start(&i2c_processing_timer, transaction->waitwritetime);
    while (SysTimer_uS_IsTimeout(&i2c_processing_timer) == 0) ;
  }

  /* READ */
  if (transaction->readcount == 0) {
    /* Do nothing */
  } else {
    if (transaction->writecount == 0) {/* Bus will Busy if previous transactio is WRITE */
      /* Check Busy flag */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY)) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {/* Timeout */
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        }
      }
    }

    /* Clear I2C status */
    I2C_ClearFlag(I2Cx, I2C_FLAG_AF);

    /* Set POS bit if read count is 2 */
    if (transaction->readcount == 2) {
      I2Cx->CR1 |= 0x0800;
    }

    /* Generate START */
    I2C_GenerateSTART(I2Cx, ENABLE);

    /* Test on EV5 and clear it */
    SysTimer_uS_Start(&i2c_processing_timer, timeout);
    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT)) {
      if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
        sta = I2C_TIMEOUT;
        goto ____i2c_error;
      }
    }

    /* Slave address */
    I2C_Send7bitAddress(I2Cx, (transaction->slaveaddress),
                        I2C_Direction_Receiver);

    /* Wait on ADDR flag to be set (ADDR is still not cleared at this level) */
    SysTimer_uS_Start(&i2c_processing_timer, timeout);
    while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_ADDR) == RESET) {
      if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
        sta = I2C_TIMEOUT;
        goto ____i2c_error;
      } else {
        if (I2C_GetFlagStatus(I2Cx, I2C_FLAG_AF) == SET) {
          I2C_GenerateSTOP(I2Cx, ENABLE);
          sta = I2C_NAK;
          goto ____i2c_error;
        }
      }
    }

    switch (transaction->readcount) {
      /* Read 1 byte */
     case 1:
      /* It is last byte, disable Acknowledgement */
      I2C_AcknowledgeConfig(I2Cx, DISABLE);

      /* Disable all active IRQs around ADDR clearing and STOP programming because the EV6_3
         software sequence must complete before the current byte end of transfer */
      __disable_irq();

      /* Clear ADDR register by reading SR1 then SR2 register (SR1 has already been read) */
      tmp = I2Cx->SR2;

      /* Send STOP Condition */
      I2C_GenerateSTOP(I2Cx, ENABLE);

      /* Re-enable IRQs */
      __enable_irq();

      /* Wait for the byte to be received */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_RXNE) == RESET) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        }
      }

      /* Read the byte received from the Slave */
      transaction->readbuffer[0] = I2C_ReceiveData(I2Cx);

      /* Wait to make sure that STOP control bit has been cleared */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (I2Cx->CR1 & I2C_CR1_STOP) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        }
      }
      break;

      /* Read 2 bytes */
     case 2:
      /* EV6_1: The acknowledge disable should be done just after EV6,
         that is after ADDR is cleared, so disable all active IRQs around ADDR clearing and
         ACK clearing */
      __disable_irq();

      /* Clear ADDR by reading SR2 register  */
      tmp = I2Cx->SR2;

      /* Clear ACK */
      I2C_AcknowledgeConfig(I2Cx, DISABLE);

      /*Re-enable IRQs */
      __enable_irq();

      /* Test on BTF and clear it */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_BTF)) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        }
      }

      /* Disable IRQs around STOP programming and data reading because of the limitation ?*/
      __disable_irq();

      /* Program the STOP */
      I2C_GenerateSTOP(I2Cx, ENABLE);

      /* Read first data */
      transaction->readbuffer[0] = I2Cx->DR;

      /* Re-enable IRQs */
      __enable_irq();

      /* Read second data */
      transaction->readbuffer[1] = I2Cx->DR;

      /* Wait to make sure that STOP control bit has been cleared */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (I2Cx->CR1 & I2C_CR1_STOP) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        }
      }

      /* Enable Acknowledgement to be ready for another reception */
      I2C_AcknowledgeConfig(I2Cx, ENABLE);

      /* Clear POS bit */
      I2Cx->CR1 &= 0xF7FF;
      break;

      /* Read more than 2 bytes */
     default:
      /* Clear ADDR by reading SR2 status register */
      tmp = I2Cx->SR2;

      /* While there is data to be read */
      NumByteToRead = transaction->readcount;
      i = 0;
      while (NumByteToRead > 0) {
        /* Poll on BTF to receive data because in polling mode we can not guarantee the
           EV7 software sequence is managed before the current byte transfer completes */
        SysTimer_uS_Start(&i2c_processing_timer, timeout);
        while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_BTF)) {
          if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
            sta = I2C_TIMEOUT;
            goto ____i2c_error;
          }
        }

        /* Receive bytes from first byte until byte N-3 */
        if (NumByteToRead != 3) {
          /* Read data */
          transaction->readbuffer[i] = I2Cx->DR;

          /* */
          i++;

          /* Decrement the read bytes counter */
          NumByteToRead--;
        } else {                       /* it remains to read three data: data N-2, data N-1, Data N */
          /* Clear ACK */
          I2C_AcknowledgeConfig(I2Cx, DISABLE);

          /* Disable IRQs around data reading and STOP programming because of the limitation ? */
          __disable_irq();

          /* Read Data N-2 */
          transaction->readbuffer[i] = I2Cx->DR;

          /* Increment */
          i++;

          /* Program the STOP */
          I2C_GenerateSTOP(I2Cx, ENABLE);

          /* Read DataN-1 */
          transaction->readbuffer[i] = I2Cx->DR;

          /* Re-enable IRQs */
          __enable_irq();

          /* Increment */
          i++;

          /* Wait until RXNE is set (DR contains the last data) */
          SysTimer_uS_Start(&i2c_processing_timer, timeout);
          while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_RXNE) == RESET) {
            if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
              sta = I2C_TIMEOUT;
              goto ____i2c_error;
            }
          }

          /* Read DataN */
          transaction->readbuffer[i] = I2Cx->DR;

          /* Reset the number of bytes to be read by master */
          NumByteToRead = 0;
        }
      }

      /* Wait to make sure that STOP control bit has been cleared */
      SysTimer_uS_Start(&i2c_processing_timer, timeout);
      while (I2Cx->CR1 & I2C_CR1_STOP) {
        if (SysTimer_uS_IsTimeout(&i2c_processing_timer)) {
          sta = I2C_TIMEOUT;
          goto ____i2c_error;
        }
      }

      /* Enable Acknowledgement to be ready for another reception */
      I2C_AcknowledgeConfig(I2Cx, ENABLE);
      break;
    }
  }

  /* No Error */
  return I2C_OK;

  /* Error */
 ____i2c_error:
  /* Generate STOP */
  I2C_GenerateSTOP(I2Cx, ENABLE);

  /* Wait to make sure that STOP control bit has been cleared */
  SysTimer_uS_Start(&i2c_processing_timer, timeout);
  while ((I2Cx->CR1 & I2C_CR1_STOP) && (SysTimer_uS_IsTimeout
          (&i2c_processing_timer) == 0)) ;

  /* Return fail status */
  return sta;
}

/* ########################################################################
 * Name: <S8>/I2C Master Read//Write
 * Id: L3G4200DInitL3G4200DI2CMasterReadWrite
 * (I2CMasterReadWrite)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite;
uint8_t I2CMasterReadWrite_WBuffer[2];

/* Enable module */
void enable_L3G4200DInitL3G4200DI2CMasterReadWrite(void)
{
  I2CMasterReadWrite.options = 0;
  I2CMasterReadWrite.writecount = 2;
  I2CMasterReadWrite.writebuffer = I2CMasterReadWrite_WBuffer;
  I2CMasterReadWrite.readcount = 0;
  I2CMasterReadWrite.readbuffer = (uint8_t*)0;
  I2CMasterReadWrite.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S8>/I2C Master Read//Write1
 * Id: L3G4200DInitL3G4200DI2CMasterReadWrite1
 * (I2CMasterReadWrite1)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite1;
uint8_t I2CMasterReadWrite1_WBuffer[2];

/* Enable module */
void enable_L3G4200DInitL3G4200DI2CMasterReadWrite1(void)
{
  I2CMasterReadWrite1.options = 0;
  I2CMasterReadWrite1.writecount = 2;
  I2CMasterReadWrite1.writebuffer = I2CMasterReadWrite1_WBuffer;
  I2CMasterReadWrite1.readcount = 0;
  I2CMasterReadWrite1.readbuffer = (uint8_t*)0;
  I2CMasterReadWrite1.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S8>/I2C Master Read//Write2
 * Id: L3G4200DInitL3G4200DI2CMasterReadWrite2
 * (I2CMasterReadWrite2_m)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite2_m;
uint8_t I2CMasterReadWrite2_m_WBuffer[2];

/* Enable module */
void enable_L3G4200DInitL3G4200DI2CMasterReadWrite2(void)
{
  I2CMasterReadWrite2_m.options = 0;
  I2CMasterReadWrite2_m.writecount = 2;
  I2CMasterReadWrite2_m.writebuffer = I2CMasterReadWrite2_m_WBuffer;
  I2CMasterReadWrite2_m.readcount = 0;
  I2CMasterReadWrite2_m.readbuffer = (uint8_t*)0;
  I2CMasterReadWrite2_m.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S9>/I2C Master Read//Write
 * Id: L3G4200DReadL3G4200DI2CMasterReadWrite
 * (I2CMasterReadWrite_f)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite_f;
uint8_t I2CMasterReadWrite_f_WBuffer[1];
uint8_t I2CMasterReadWrite_f_RBuffer[1];

/* Enable module */
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite(void)
{
  I2CMasterReadWrite_f.options = 0;
  I2CMasterReadWrite_f.writecount = 1;
  I2CMasterReadWrite_f.writebuffer = I2CMasterReadWrite_f_WBuffer;
  I2CMasterReadWrite_f.readcount = 1;
  I2CMasterReadWrite_f.readbuffer = I2CMasterReadWrite_f_RBuffer;
  I2CMasterReadWrite_f.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S9>/I2C Master Read//Write1
 * Id: L3G4200DReadL3G4200DI2CMasterReadWrite1
 * (I2CMasterReadWrite1_f)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite1_f;
uint8_t I2CMasterReadWrite1_f_WBuffer[1];
uint8_t I2CMasterReadWrite1_f_RBuffer[1];

/* Enable module */
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite1(void)
{
  I2CMasterReadWrite1_f.options = 0;
  I2CMasterReadWrite1_f.writecount = 1;
  I2CMasterReadWrite1_f.writebuffer = I2CMasterReadWrite1_f_WBuffer;
  I2CMasterReadWrite1_f.readcount = 1;
  I2CMasterReadWrite1_f.readbuffer = I2CMasterReadWrite1_f_RBuffer;
  I2CMasterReadWrite1_f.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S9>/I2C Master Read//Write2
 * Id: L3G4200DReadL3G4200DI2CMasterReadWrite2
 * (I2CMasterReadWrite2_g)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite2_g;
uint8_t I2CMasterReadWrite2_g_WBuffer[1];
uint8_t I2CMasterReadWrite2_g_RBuffer[1];

/* Enable module */
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite2(void)
{
  I2CMasterReadWrite2_g.options = 0;
  I2CMasterReadWrite2_g.writecount = 1;
  I2CMasterReadWrite2_g.writebuffer = I2CMasterReadWrite2_g_WBuffer;
  I2CMasterReadWrite2_g.readcount = 1;
  I2CMasterReadWrite2_g.readbuffer = I2CMasterReadWrite2_g_RBuffer;
  I2CMasterReadWrite2_g.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S9>/I2C Master Read//Write3
 * Id: L3G4200DReadL3G4200DI2CMasterReadWrite3
 * (I2CMasterReadWrite3_g)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite3_g;
uint8_t I2CMasterReadWrite3_g_WBuffer[1];
uint8_t I2CMasterReadWrite3_g_RBuffer[1];

/* Enable module */
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite3(void)
{
  I2CMasterReadWrite3_g.options = 0;
  I2CMasterReadWrite3_g.writecount = 1;
  I2CMasterReadWrite3_g.writebuffer = I2CMasterReadWrite3_g_WBuffer;
  I2CMasterReadWrite3_g.readcount = 1;
  I2CMasterReadWrite3_g.readbuffer = I2CMasterReadWrite3_g_RBuffer;
  I2CMasterReadWrite3_g.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S9>/I2C Master Read//Write4
 * Id: L3G4200DReadL3G4200DI2CMasterReadWrite4
 * (I2CMasterReadWrite4_e)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite4_e;
uint8_t I2CMasterReadWrite4_e_WBuffer[1];
uint8_t I2CMasterReadWrite4_e_RBuffer[1];

/* Enable module */
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite4(void)
{
  I2CMasterReadWrite4_e.options = 0;
  I2CMasterReadWrite4_e.writecount = 1;
  I2CMasterReadWrite4_e.writebuffer = I2CMasterReadWrite4_e_WBuffer;
  I2CMasterReadWrite4_e.readcount = 1;
  I2CMasterReadWrite4_e.readbuffer = I2CMasterReadWrite4_e_RBuffer;
  I2CMasterReadWrite4_e.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S9>/I2C Master Read//Write5
 * Id: L3G4200DReadL3G4200DI2CMasterReadWrite5
 * (I2CMasterReadWrite5)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite5;
uint8_t I2CMasterReadWrite5_WBuffer[1];
uint8_t I2CMasterReadWrite5_RBuffer[1];

/* Enable module */
void enable_L3G4200DReadL3G4200DI2CMasterReadWrite5(void)
{
  I2CMasterReadWrite5.options = 0;
  I2CMasterReadWrite5.writecount = 1;
  I2CMasterReadWrite5.writebuffer = I2CMasterReadWrite5_WBuffer;
  I2CMasterReadWrite5.readcount = 1;
  I2CMasterReadWrite5.readbuffer = I2CMasterReadWrite5_RBuffer;
  I2CMasterReadWrite5.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S5>/UART Tx
 * Id: SuccessUARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_SuccessUARTTx(void)
{
}

/* ########################################################################
 * Name: <Root>/UART Setup
 * Id: UARTSetup
 * ########################################################################
 */

/* Tx buffer */
uint8_t UART2_Tx_Buffer[UTX2_BUFFER_SIZE];
UART_TX_STATE UARTSetup_Tx_State;

/* DMA Init struct */
DMA_InitTypeDef UARTSetup_DMA_Init;

/* Init buffer read */

/* Wait for DMA transfer to completion */
UART_TX_STATE UART2_FlushTxBuffer(void)
{
  if (UARTSetup_Tx_State != txIdle) {
    /* Chehck last DMA transmit */
    while ((DMA_GetFlagStatus(DMA1_Stream6, DMA_FLAG_TCIF6) == RESET)
           || (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)) {
    }

    /* Clear DMA Streams flags */
    DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_HTIF6 | DMA_FLAG_TCIF6);

    /* Disable the DMA Streams */
    DMA_Cmd(DMA1_Stream6, DISABLE);

    /* Disable the USART Tx DMA request */
    USART_DMACmd(USART2, USART_DMAReq_Tx, DISABLE);

    /* Update state */
    UARTSetup_Tx_State = txIdle;
  }

  return UARTSetup_Tx_State;
}

/* Write to DMA buffer */
void UART2_Write(uint8_t* data, uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART2_FlushTxBuffer();

    /* Setup */
    memcpy(UART2_Tx_Buffer, data, count);

    /* Update */
    UART2_TxUpdate(count);
  }
}

/* Update transmit buffer */
void UART2_TxUpdate(uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART2_FlushTxBuffer();
    UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)count;
    DMA_Init(DMA1_Stream6, &UARTSetup_DMA_Init);

    /* Enable */
    USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART2, USART_FLAG_TC);
    DMA_Cmd(DMA1_Stream6, ENABLE);

    /* Tx is busy */
    UARTSetup_Tx_State = txBusy;
  }
}

/* Enable UART-DMA module */
void enable_UARTSetup(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Enable UART clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  /* Enable the DMA clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

  /* Connect PXx to USARTx_Tx*/
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_USART2);

  /* Configure USART pin as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

  /* Configure USART Tx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* USART Configuration */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx;

  /* Over sampling x8 */
  USART_OverSampling8Cmd(USART2, ENABLE);

  /* USART configuration */
  USART_Init(USART2, &USART_InitStructure);

  /* Enable USART */
  USART_Cmd(USART2, ENABLE);

  /* DMA init struct configuration */
  UARTSetup_DMA_Init.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
  UARTSetup_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  UARTSetup_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
  UARTSetup_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  UARTSetup_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  UARTSetup_DMA_Init.DMA_FIFOMode = DMA_FIFOMode_Disable;
  UARTSetup_DMA_Init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
  UARTSetup_DMA_Init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  UARTSetup_DMA_Init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

  /* Configure DMA controller to manage TX DMA request */
  UARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
  UARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART2_Tx_Buffer;
  UARTSetup_DMA_Init.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)UTX2_BUFFER_SIZE;
  UARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Normal;
  UARTSetup_DMA_Init.DMA_Priority = DMA_Priority_High;

  /* Init Tx state */
  UARTSetup_Tx_State = txIdle;
}

/* ########################################################################
 * Timer
 * ########################################################################
 */

/* Low precision non-Blocking delay timer.
 ** Relolution of timer is one TICK step interrupt.
 */
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms)
{
  /* Calculate amount of tick count */
  timer->length = (uint32_t)((float)ms/(1000*SYS_TICKSTEP));

  /* Capture current tick */
  timer->start = (uint32_t)systick_count;
}

int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer)
{
  uint32_t Capture;

  /* Capture current tick */
  Capture = (uint32_t)systick_count;

  /* Check */
  if (Capture >= timer->start) {
    if ((Capture - timer->start) >= timer->length)
      return 1;
  } else {
    if (((0xFFFFFFFF - timer->start)+Capture) >= timer->length)
      return 1;
  }

  return 0;
}

/* Improved precision non-Blocking delay timer.
 ** Relolution of timer is 1uS.
 */
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us)
{
  /* Tick */
  timer->tick = SYS_CURRENT_TICK;

  /* Tick overflow count */
  timer->tid = (uint32_t)systick_count;

  /* Target */
  timer->target_us = us*((uint32_t)HCLK/1000000);
}

int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer)
{
  uint32_t curr_tick;
  uint32_t curr_tid;

  /* Already timeout ? */
  if (timer->target_us == 0) {
    return 1;
  }

  /* Capture current tick */
  curr_tick = SYS_CURRENT_TICK;
  curr_tid = systick_count;

  /* Processing TID*/
  while (timer->tid != curr_tid) {
    if (timer->target_us > timer->tick) {
      timer->target_us -= timer->tick;
      timer->tid ++;
      timer->tick = SYSTICKRELOADVALUE-1;
    } else {
      timer->target_us = 0;
      return 1;                        /* Timeout */
    }
  }

  /* Processing Tick */
  if ((timer->tick > curr_tick) && ((timer->tick - curr_tick) > timer->target_us))
  {
    timer->target_us = 0;
    return 1;                          /* Timeout */
  }

  /* Need wait */
  return 0;
}

/* Blocking delay, uS */
void SysTimer_delay_us(uint32_t us)
{
  SYS_TIMER_uS_STRUCT timer;
  SysTimer_uS_Start(&timer, us);
  while (SysTimer_uS_IsTimeout(&timer) == 0) ;
}

/* Blocking delay, mS */
void SysTimer_delay_ms(uint32_t ms)
{
  SYS_TIMER_STRUCT timer;
  SysTimer_Start(&timer, ms);
  while (SysTimer_IsTimeout(&timer) == 0) ;
}

/* ########################################################################
 * Name: <S7>/I2C Master Read//Write2
 * Id: L3G4200DGetInitL3G4200D1I2CMasterReadWrite2
 * (I2CMasterReadWrite2)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite2;
uint8_t I2CMasterReadWrite2_WBuffer[1];
uint8_t I2CMasterReadWrite2_RBuffer[1];

/* Enable module */
void enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite2(void)
{
  I2CMasterReadWrite2.options = 0;
  I2CMasterReadWrite2.writecount = 1;
  I2CMasterReadWrite2.writebuffer = I2CMasterReadWrite2_WBuffer;
  I2CMasterReadWrite2.readcount = 1;
  I2CMasterReadWrite2.readbuffer = I2CMasterReadWrite2_RBuffer;
  I2CMasterReadWrite2.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S7>/I2C Master Read//Write3
 * Id: L3G4200DGetInitL3G4200D1I2CMasterReadWrite3
 * (I2CMasterReadWrite3)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite3;
uint8_t I2CMasterReadWrite3_WBuffer[1];
uint8_t I2CMasterReadWrite3_RBuffer[1];

/* Enable module */
void enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite3(void)
{
  I2CMasterReadWrite3.options = 0;
  I2CMasterReadWrite3.writecount = 1;
  I2CMasterReadWrite3.writebuffer = I2CMasterReadWrite3_WBuffer;
  I2CMasterReadWrite3.readcount = 1;
  I2CMasterReadWrite3.readbuffer = I2CMasterReadWrite3_RBuffer;
  I2CMasterReadWrite3.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <S7>/I2C Master Read//Write4
 * Id: L3G4200DGetInitL3G4200D1I2CMasterReadWrite4
 * (I2CMasterReadWrite4)
 * ########################################################################
 */
I2C_TRANSACTION I2CMasterReadWrite4;
uint8_t I2CMasterReadWrite4_WBuffer[1];
uint8_t I2CMasterReadWrite4_RBuffer[1];

/* Enable module */
void enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite4(void)
{
  I2CMasterReadWrite4.options = 0;
  I2CMasterReadWrite4.writecount = 1;
  I2CMasterReadWrite4.writebuffer = I2CMasterReadWrite4_WBuffer;
  I2CMasterReadWrite4.readcount = 1;
  I2CMasterReadWrite4.readbuffer = I2CMasterReadWrite4_RBuffer;
  I2CMasterReadWrite4.waitwritetime = 0*1000UL;/* uS */
}

/* ########################################################################
 * Name: <Root>/I2C Master Setup
 * Id: I2CMasterSetup
 * (I2CMasterSetup)
 * ########################################################################
 */
I2C_RESULT i2c1_trans_proc(uint8_t slaveaddress, I2C_TRANSACTION *transaction)
{
  uint8_t i;
  I2C_RESULT res;

  /* Update Slave address */
  transaction->slaveaddress = slaveaddress;

  /* Transaction processing */
  if ((res = i2c_trans_proc(I2C1, I2C1_TIMEOUT_uS, transaction)) != I2C_OK) {
    /* Temporary disable module to reset I2C */
    disable_I2CMasterSetup();

    /* Detect if Slave hold low SDA line (this cause stuck on I2C bus),
     ** use GPIO toggle to generate clock on SCL line until slave release SDA.
     */
    i = 0;
    while ((i++<16) && (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == Bit_RESET))
    {
      GPIO_ResetBits(GPIOB, GPIO_Pin_8);
      SysTimer_delay_us(5);            /* 5uS */
      GPIO_SetBits(GPIOB, GPIO_Pin_8);
      SysTimer_delay_us(4);            /* 4uS */
    }

    /* Re-enable I2C */
    enable_I2CMasterSetup();
  }

  return res;
}

/* Enable module */
void enable_I2CMasterSetup(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  I2C_InitTypeDef I2C_InitStructure;

  /* I2C Periph clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

  /* I2C_SCL_GPIO_CLK and I2C_SDA_GPIO_CLK Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Reset I2C IP */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);

  /* Release reset signal of I2C IP */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);

  /* GPIO configuration */
  /* Connect PB8 to I2C_SCL*/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);

  /* Connect PB9 to I2C_SDA*/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);

  /* Configure I2C pins: SCL */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure sEE_I2C pins: SDA */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* I2C configuration */
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
  I2C_InitStructure.I2C_OwnAddress1 = 0xA0;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_ClockSpeed = 100000;/* 100kHz */

  /* I2C Peripheral Enable */
  I2C_Cmd(I2C1, ENABLE);

  /* Apply I2C1 configuration after enabling it */
  I2C_Init(I2C1, &I2C_InitStructure);
}

/* Disable module */
void disable_I2CMasterSetup(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* I2C Peripheral Disable */
  I2C_Cmd(I2C1, DISABLE);

  /* I2C DeInit */
  I2C_DeInit(I2C1);

  /* I2C Periph clock disable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, DISABLE);

  /* GPIO configuration */
  /* Configure I2C pins: SCL */
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_SetBits(GPIOB, GPIO_Pin_8);
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure I2C pins: SDA */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/* [EOF] */
