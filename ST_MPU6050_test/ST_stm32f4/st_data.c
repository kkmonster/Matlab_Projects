/*
 * File: st_data.c
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

/* Block parameters (auto storage) */
Parameters_st st_P = {
  0.00762939453F,                      /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S5>/Gain'
                                        */
  8,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponent
                                        * Referenced by: '<S13>/Shift Arithmetic'
                                        */
  8,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponen_d
                                        * Referenced by: '<S14>/Shift Arithmetic'
                                        */
  8,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponen_g
                                        * Referenced by: '<S15>/Shift Arithmetic'
                                        */
  27U,                                 /* Computed Parameter: CNTRL_REG1_Value
                                        * Referenced by: '<S8>/CNTRL_REG1'
                                        */
  2U,                                  /* Computed Parameter: CNTRL_REG2_Value
                                        * Referenced by: '<S8>/CNTRL_REG2'
                                        */
  28U,                                 /* Computed Parameter: CNTRL_REG4_Value
                                        * Referenced by: '<S8>/CNTRL_REG4'
                                        */
  0U,                                  /* Computed Parameter: Enable_Value
                                        * Referenced by: '<S8>/Enable'
                                        */
  0U,                                  /* Computed Parameter: FS1_Value
                                        * Referenced by: '<S8>/FS 1'
                                        */
  0U,                                  /* Computed Parameter: FS250_Value
                                        * Referenced by: '<S8>/FS 250'
                                        */
  89U,                                 /* Computed Parameter: OUT_X_L_Value
                                        * Referenced by: '<S9>/OUT_X_L'
                                        */
  96U,                                 /* Computed Parameter: OUT_X_H_Value
                                        * Referenced by: '<S9>/OUT_X_H'
                                        */
  97U,                                 /* Computed Parameter: OUT_Y_L_Value
                                        * Referenced by: '<S9>/OUT_Y_L'
                                        */
  98U,                                 /* Computed Parameter: OUT_Y_H_Value
                                        * Referenced by: '<S9>/OUT_Y_H'
                                        */
  99U,                                 /* Computed Parameter: OUT_Z_L_Value
                                        * Referenced by: '<S9>/OUT_Z_L'
                                        */
  100U,                                /* Computed Parameter: OUT_Z_H_Value
                                        * Referenced by: '<S9>/OUT_Z_H'
                                        */
  210U,                                /* Computed Parameter: SlvAddr1_Value
                                        * Referenced by: '<S4>/SlvAddr1'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S1>/Constant'
                                        */
  27U,                                 /* Computed Parameter: CNTRL_REG2_Value_p
                                        * Referenced by: '<S7>/CNTRL_REG2'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S10>/Constant'
                                        */
  28U,                                 /* Computed Parameter: CNTRL_REG5_Value
                                        * Referenced by: '<S7>/CNTRL_REG5'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S11>/Constant'
                                        */
  2U,                                  /* Computed Parameter: CNTRL_REG3_Value
                                        * Referenced by: '<S7>/CNTRL_REG3'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S12>/Constant'
                                        */
  0U                                   /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S6>/Constant'
                                        */
};

/* [EOF] */
