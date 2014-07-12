/*
 * File: st.c
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
#include "st.h"
#include "st_private.h"

/* Block signals (auto storage) */
BlockIO_st st_B;

/* Block states (auto storage) */
D_Work_st st_DWork;

/* Real-time model */
RT_MODEL_st st_M_;
RT_MODEL_st *const st_M = &st_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (st_M->Timing.TaskCounters.TID[1])++;
  if ((st_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    st_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void st_step(void)
{
  uint8_T rtb_BitwiseOperator_m;
  if (st_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<S4>/Read L3G4200D' */

    /* I2C Transaction, Name: <S9>/I2C Master Read//Write
     * ID : I2CMasterReadWrite_f (L3G4200DReadL3G4200DI2CMasterReadWrite)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite_f.writebuffer[0] = st_P.OUT_X_L_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite_o1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
        &I2CMasterReadWrite_f);

      /* Update output */
      st_B.I2CMasterReadWrite_o2 = I2CMasterReadWrite_f.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S9>/I2C Master Read//Write1
     * ID : I2CMasterReadWrite1_f (L3G4200DReadL3G4200DI2CMasterReadWrite1)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite1_f.writebuffer[0] = st_P.OUT_X_H_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite1_o1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
        &I2CMasterReadWrite1_f);

      /* Update output */
      st_B.I2CMasterReadWrite1_o2 = I2CMasterReadWrite1_f.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S9>/I2C Master Read//Write2
     * ID : I2CMasterReadWrite2_g (L3G4200DReadL3G4200DI2CMasterReadWrite2)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite2_g.writebuffer[0] = st_P.OUT_Y_L_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite2_o1_n = (uint8_T)i2c1_trans_proc
        (st_P.SlvAddr1_Value, &I2CMasterReadWrite2_g);

      /* Update output */
      st_B.I2CMasterReadWrite2_o2_c = I2CMasterReadWrite2_g.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S9>/I2C Master Read//Write3
     * ID : I2CMasterReadWrite3_g (L3G4200DReadL3G4200DI2CMasterReadWrite3)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite3_g.writebuffer[0] = st_P.OUT_Y_H_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite3_o1_o = (uint8_T)i2c1_trans_proc
        (st_P.SlvAddr1_Value, &I2CMasterReadWrite3_g);

      /* Update output */
      st_B.I2CMasterReadWrite3_o2_c = I2CMasterReadWrite3_g.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S9>/I2C Master Read//Write4
     * ID : I2CMasterReadWrite4_e (L3G4200DReadL3G4200DI2CMasterReadWrite4)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite4_e.writebuffer[0] = st_P.OUT_Z_L_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite4_o1_i = (uint8_T)i2c1_trans_proc
        (st_P.SlvAddr1_Value, &I2CMasterReadWrite4_e);

      /* Update output */
      st_B.I2CMasterReadWrite4_o2_c = I2CMasterReadWrite4_e.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S9>/I2C Master Read//Write5
     * ID : I2CMasterReadWrite5 (L3G4200DReadL3G4200DI2CMasterReadWrite5)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite5.writebuffer[0] = st_P.OUT_Z_H_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite5_o1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
        &I2CMasterReadWrite5);

      /* Update output */
      st_B.I2CMasterReadWrite5_o2 = I2CMasterReadWrite5.readbuffer[0];/* Rd0 */
    }

    /* S-Function (sfix_bitop): '<S9>/Bitwise Operator' */
    rtb_BitwiseOperator_m = (uint8_T)((uint8_T)((uint8_T)((uint8_T)((uint8_T)
      (st_B.I2CMasterReadWrite_o1 | st_B.I2CMasterReadWrite1_o1) |
      st_B.I2CMasterReadWrite2_o1_n) | st_B.I2CMasterReadWrite3_o1_o) |
      st_B.I2CMasterReadWrite4_o1_i) | st_B.I2CMasterReadWrite5_o1);

    /* End of Outputs for SubSystem: '<S4>/Read L3G4200D' */

    /* Outputs for Enabled SubSystem: '<Root>/Fail' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (rtb_BitwiseOperator_m != st_P.Constant_Value) {
      if (!st_DWork.Fail_MODE) {
        /* Level2 S-Function Block: '<S3>/UART Tx' (stm32f4_usart) */
        enable_FailUARTTx();
        st_DWork.Fail_MODE = TRUE;
      }

      /* DataTypeConversion: '<S3>/Data Type Conversion' */
      st_B.DataTypeConversion = rtb_BitwiseOperator_m;

      /* FailUARTTx: '<S3>/UART Tx' */
      {
        UART2_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART2_Tx_Buffer, "Fail code: %u\r\n" ,
                st_B.DataTypeConversion );
        UART2_TxUpdate(strlen((char*)UART2_Tx_Buffer));

        /* Blocking, wait for DMA buffer */
        UART2_FlushTxBuffer();
      }
    } else {
      if (st_DWork.Fail_MODE) {
        st_DWork.Fail_MODE = FALSE;
      }
    }

    /* End of RelationalOperator: '<S2>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Fail' */

    /* Outputs for Enabled SubSystem: '<Root>/Success' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (rtb_BitwiseOperator_m == st_P.Constant_Value_d) {
      if (!st_DWork.Success_MODE) {
        /* Level2 S-Function Block: '<S5>/UART Tx' (stm32f4_usart) */
        enable_SuccessUARTTx();
        st_DWork.Success_MODE = TRUE;
      }

      /* Outputs for Atomic SubSystem: '<S4>/Read L3G4200D' */
      /* Gain: '<S5>/Gain' incorporates:
       *  ArithShift: '<S13>/Shift Arithmetic'
       *  ArithShift: '<S14>/Shift Arithmetic'
       *  ArithShift: '<S15>/Shift Arithmetic'
       *  DataTypeConversion: '<S13>/Data Type Conversion'
       *  DataTypeConversion: '<S13>/Data Type Conversion1'
       *  DataTypeConversion: '<S14>/Data Type Conversion'
       *  DataTypeConversion: '<S14>/Data Type Conversion1'
       *  DataTypeConversion: '<S15>/Data Type Conversion'
       *  DataTypeConversion: '<S15>/Data Type Conversion1'
       *  DataTypeConversion: '<S5>/Data Type Conversion'
       *  S-Function (sfix_bitop): '<S13>/Bitwise Operator'
       *  S-Function (sfix_bitop): '<S14>/Bitwise Operator'
       *  S-Function (sfix_bitop): '<S15>/Bitwise Operator'
       */
      st_B.Gain[0] = (real32_T)(int16_T)(st_B.I2CMasterReadWrite1_o2 << 8 |
        st_B.I2CMasterReadWrite_o2) * st_P.Gain_Gain;
      st_B.Gain[1] = (real32_T)(int16_T)(st_B.I2CMasterReadWrite3_o2_c << 8 |
        st_B.I2CMasterReadWrite2_o2_c) * st_P.Gain_Gain;
      st_B.Gain[2] = (real32_T)(int16_T)(st_B.I2CMasterReadWrite5_o2 << 8 |
        st_B.I2CMasterReadWrite4_o2_c) * st_P.Gain_Gain;

      /* End of Outputs for SubSystem: '<S4>/Read L3G4200D' */

      /* SuccessUARTTx: '<S5>/UART Tx' */
      {
        UART2_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART2_Tx_Buffer, "L3G4200D: X=%1.3f,Y=%1.3f,Z=%1.3f\r\n" ,
                st_B.Gain[0] ,st_B.Gain[1] ,st_B.Gain[2] );
        UART2_TxUpdate(strlen((char*)UART2_Tx_Buffer));

        /* Blocking, wait for DMA buffer */
        UART2_FlushTxBuffer();
      }
    } else {
      if (st_DWork.Success_MODE) {
        st_DWork.Success_MODE = FALSE;
      }
    }

    /* End of RelationalOperator: '<S1>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Success' */

    /* I2C Transaction, Name: <S7>/I2C Master Read//Write2
     * ID : I2CMasterReadWrite2 (L3G4200DGetInitL3G4200D1I2CMasterReadWrite2)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite2.writebuffer[0] = st_P.CNTRL_REG2_Value_p;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite2_o1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
        &I2CMasterReadWrite2);

      /* Update output */
      st_B.I2CMasterReadWrite2_o2 = I2CMasterReadWrite2.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S7>/I2C Master Read//Write3
     * ID : I2CMasterReadWrite3 (L3G4200DGetInitL3G4200D1I2CMasterReadWrite3)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite3.writebuffer[0] = st_P.CNTRL_REG5_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite3_o1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
        &I2CMasterReadWrite3);

      /* Update output */
      st_B.I2CMasterReadWrite3_o2 = I2CMasterReadWrite3.readbuffer[0];/* Rd0 */
    }

    /* I2C Transaction, Name: <S7>/I2C Master Read//Write4
     * ID : I2CMasterReadWrite4 (L3G4200DGetInitL3G4200D1I2CMasterReadWrite4)
     * Info: Write byte(s)= 1, Read byte(s)= 1, Wait write time(mS)= 0,
     */
    {
      /* Collect data */
      I2CMasterReadWrite4.writebuffer[0] = st_P.CNTRL_REG3_Value;/* Wr0 */

      /* I2C Transaction processing */
      st_B.I2CMasterReadWrite4_o1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
        &I2CMasterReadWrite4);

      /* Update output */
      st_B.I2CMasterReadWrite4_o2 = I2CMasterReadWrite4.readbuffer[0];/* Rd0 */
    }

    /* Outputs for Enabled SubSystem: '<S4>/Init L3G4200D' incorporates:
     *  EnablePort: '<S8>/Enable1'
     */
    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S4>/SlvAddr1'
     *  Constant: '<S6>/Constant'
     *  Constant: '<S8>/CNTRL_REG1'
     *  Constant: '<S8>/CNTRL_REG2'
     *  Constant: '<S8>/CNTRL_REG4'
     *  Constant: '<S8>/Enable'
     *  Constant: '<S8>/FS 1'
     *  Constant: '<S8>/FS 250'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S12>/Compare'
     *  S-Function (sfix_bitop): '<S7>/Bitwise Operator'
     */
    if (((st_B.I2CMasterReadWrite2_o2 == st_P.Constant_Value_o) &
         (st_B.I2CMasterReadWrite3_o2 == st_P.Constant_Value_m) &
         (st_B.I2CMasterReadWrite4_o2 == st_P.Constant_Value_g)) ==
        st_P.Constant_Value_n) {
      if (!st_DWork.InitL3G4200D_MODE) {
        st_DWork.InitL3G4200D_MODE = TRUE;
      }

      /* I2C Transaction, Name: <S8>/I2C Master Read//Write
       * ID : I2CMasterReadWrite (L3G4200DInitL3G4200DI2CMasterReadWrite)
       * Info: Write byte(s)= 2, Read byte(s)= 0, Wait write time(mS)= 0,
       */
      {
        /* Collect data */
        I2CMasterReadWrite.writebuffer[0] = st_P.CNTRL_REG1_Value;/* Wr0 */
        I2CMasterReadWrite.writebuffer[1] = st_P.Enable_Value;/* Wr1 */

        /* I2C Transaction processing */
        st_B.I2CMasterReadWrite = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
          &I2CMasterReadWrite);
      }

      /* I2C Transaction, Name: <S8>/I2C Master Read//Write1
       * ID : I2CMasterReadWrite1 (L3G4200DInitL3G4200DI2CMasterReadWrite1)
       * Info: Write byte(s)= 2, Read byte(s)= 0, Wait write time(mS)= 0,
       */
      {
        /* Collect data */
        I2CMasterReadWrite1.writebuffer[0] = st_P.CNTRL_REG4_Value;/* Wr0 */
        I2CMasterReadWrite1.writebuffer[1] = st_P.FS250_Value;/* Wr1 */

        /* I2C Transaction processing */
        st_B.I2CMasterReadWrite1 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
          &I2CMasterReadWrite1);
      }

      /* I2C Transaction, Name: <S8>/I2C Master Read//Write2
       * ID : I2CMasterReadWrite2_m (L3G4200DInitL3G4200DI2CMasterReadWrite2)
       * Info: Write byte(s)= 2, Read byte(s)= 0, Wait write time(mS)= 0,
       */
      {
        /* Collect data */
        I2CMasterReadWrite2_m.writebuffer[0] = st_P.CNTRL_REG2_Value;/* Wr0 */
        I2CMasterReadWrite2_m.writebuffer[1] = st_P.FS1_Value;/* Wr1 */

        /* I2C Transaction processing */
        st_B.I2CMasterReadWrite2 = (uint8_T)i2c1_trans_proc(st_P.SlvAddr1_Value,
          &I2CMasterReadWrite2_m);
      }
    } else {
      if (st_DWork.InitL3G4200D_MODE) {
        st_DWork.InitL3G4200D_MODE = FALSE;
      }
    }

    /* End of RelationalOperator: '<S6>/Compare' */
    /* End of Outputs for SubSystem: '<S4>/Init L3G4200D' */
  }

  rate_scheduler();
}

/* Model initialize function */
void st_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)st_M, 0,
                sizeof(RT_MODEL_st));

  /* block I/O */
  (void) memset(((void *) &st_B), 0,
                sizeof(BlockIO_st));

  /* states (dwork) */
  (void) memset((void *)&st_DWork, 0,
                sizeof(D_Work_st));

  /* Start for Atomic SubSystem: '<S4>/Read L3G4200D' */

  /* S-Function Block: <S9>/I2C Master Read//Write */
  enable_L3G4200DReadL3G4200DI2CMasterReadWrite();

  /* S-Function Block: <S9>/I2C Master Read//Write1 */
  enable_L3G4200DReadL3G4200DI2CMasterReadWrite1();

  /* S-Function Block: <S9>/I2C Master Read//Write2 */
  enable_L3G4200DReadL3G4200DI2CMasterReadWrite2();

  /* S-Function Block: <S9>/I2C Master Read//Write3 */
  enable_L3G4200DReadL3G4200DI2CMasterReadWrite3();

  /* S-Function Block: <S9>/I2C Master Read//Write4 */
  enable_L3G4200DReadL3G4200DI2CMasterReadWrite4();

  /* S-Function Block: <S9>/I2C Master Read//Write5 */
  enable_L3G4200DReadL3G4200DI2CMasterReadWrite5();

  /* End of Start for SubSystem: '<S4>/Read L3G4200D' */

  /* S-Function Block: <S7>/I2C Master Read//Write2 */
  enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite2();

  /* S-Function Block: <S7>/I2C Master Read//Write3 */
  enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite3();

  /* S-Function Block: <S7>/I2C Master Read//Write4 */
  enable_L3G4200DGetInitL3G4200D1I2CMasterReadWrite4();

  /* Start for Enabled SubSystem: '<S4>/Init L3G4200D' */

  /* S-Function Block: <S8>/I2C Master Read//Write */
  enable_L3G4200DInitL3G4200DI2CMasterReadWrite();

  /* S-Function Block: <S8>/I2C Master Read//Write1 */
  enable_L3G4200DInitL3G4200DI2CMasterReadWrite1();

  /* S-Function Block: <S8>/I2C Master Read//Write2 */
  enable_L3G4200DInitL3G4200DI2CMasterReadWrite2();

  /* End of Start for SubSystem: '<S4>/Init L3G4200D' */

  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();

  /* Level2 S-Function Block: '<Root>/I2C Master Setup' (stm32f4_i2c) */
  enable_I2CMasterSetup();
}

/* Model terminate function */
void st_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<S4>/Read L3G4200D' */

  /* Terminate for S-Function (stm32f4_i2c): '<S9>/I2C Master Read//Write' */

  /* terminate_L3G4200DReadL3G4200DI2CMasterReadWrite(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S9>/I2C Master Read//Write1' */

  /* terminate_L3G4200DReadL3G4200DI2CMasterReadWrite1(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S9>/I2C Master Read//Write2' */

  /* terminate_L3G4200DReadL3G4200DI2CMasterReadWrite2(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S9>/I2C Master Read//Write3' */

  /* terminate_L3G4200DReadL3G4200DI2CMasterReadWrite3(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S9>/I2C Master Read//Write4' */

  /* terminate_L3G4200DReadL3G4200DI2CMasterReadWrite4(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S9>/I2C Master Read//Write5' */

  /* terminate_L3G4200DReadL3G4200DI2CMasterReadWrite5(); */

  /* End of Terminate for SubSystem: '<S4>/Read L3G4200D' */

  /* Terminate for S-Function (stm32f4_i2c): '<S7>/I2C Master Read//Write2' */

  /* terminate_L3G4200DGetInitL3G4200D1I2CMasterReadWrite2(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S7>/I2C Master Read//Write3' */

  /* terminate_L3G4200DGetInitL3G4200D1I2CMasterReadWrite3(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S7>/I2C Master Read//Write4' */

  /* terminate_L3G4200DGetInitL3G4200D1I2CMasterReadWrite4(); */

  /* Terminate for Enabled SubSystem: '<S4>/Init L3G4200D' */

  /* Terminate for S-Function (stm32f4_i2c): '<S8>/I2C Master Read//Write' */

  /* terminate_L3G4200DInitL3G4200DI2CMasterReadWrite(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S8>/I2C Master Read//Write1' */

  /* terminate_L3G4200DInitL3G4200DI2CMasterReadWrite1(); */

  /* Terminate for S-Function (stm32f4_i2c): '<S8>/I2C Master Read//Write2' */

  /* terminate_L3G4200DInitL3G4200DI2CMasterReadWrite2(); */

  /* End of Terminate for SubSystem: '<S4>/Init L3G4200D' */

  /* Terminate for S-Function (stm32f4_i2c): '<Root>/I2C Master Setup' */

  /* terminate_I2CMasterSetup(); */
}

/* [EOF] */
