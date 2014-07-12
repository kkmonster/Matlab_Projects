/*
 * File: st.h
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

#ifndef RTW_HEADER_st_h_
#define RTW_HEADER_st_h_
#ifndef st_COMMON_INCLUDES_
# define st_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* st_COMMON_INCLUDES_ */

#include "st_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T Gain[3];                    /* '<S5>/Gain' */
  uint32_T DataTypeConversion;         /* '<S3>/Data Type Conversion' */
  uint8_T I2CMasterReadWrite2_o1;      /* '<S7>/I2C Master Read//Write2' */
  uint8_T I2CMasterReadWrite2_o2;      /* '<S7>/I2C Master Read//Write2' */
  uint8_T I2CMasterReadWrite3_o1;      /* '<S7>/I2C Master Read//Write3' */
  uint8_T I2CMasterReadWrite3_o2;      /* '<S7>/I2C Master Read//Write3' */
  uint8_T I2CMasterReadWrite4_o1;      /* '<S7>/I2C Master Read//Write4' */
  uint8_T I2CMasterReadWrite4_o2;      /* '<S7>/I2C Master Read//Write4' */
  uint8_T I2CMasterReadWrite_o1;       /* '<S9>/I2C Master Read//Write' */
  uint8_T I2CMasterReadWrite_o2;       /* '<S9>/I2C Master Read//Write' */
  uint8_T I2CMasterReadWrite1_o1;      /* '<S9>/I2C Master Read//Write1' */
  uint8_T I2CMasterReadWrite1_o2;      /* '<S9>/I2C Master Read//Write1' */
  uint8_T I2CMasterReadWrite2_o1_n;    /* '<S9>/I2C Master Read//Write2' */
  uint8_T I2CMasterReadWrite2_o2_c;    /* '<S9>/I2C Master Read//Write2' */
  uint8_T I2CMasterReadWrite3_o1_o;    /* '<S9>/I2C Master Read//Write3' */
  uint8_T I2CMasterReadWrite3_o2_c;    /* '<S9>/I2C Master Read//Write3' */
  uint8_T I2CMasterReadWrite4_o1_i;    /* '<S9>/I2C Master Read//Write4' */
  uint8_T I2CMasterReadWrite4_o2_c;    /* '<S9>/I2C Master Read//Write4' */
  uint8_T I2CMasterReadWrite5_o1;      /* '<S9>/I2C Master Read//Write5' */
  uint8_T I2CMasterReadWrite5_o2;      /* '<S9>/I2C Master Read//Write5' */
  uint8_T I2CMasterReadWrite;          /* '<S8>/I2C Master Read//Write' */
  uint8_T I2CMasterReadWrite1;         /* '<S8>/I2C Master Read//Write1' */
  uint8_T I2CMasterReadWrite2;         /* '<S8>/I2C Master Read//Write2' */
} BlockIO_st;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T Fail_MODE;                 /* '<Root>/Fail' */
  boolean_T Success_MODE;              /* '<Root>/Success' */
  boolean_T InitL3G4200D_MODE;         /* '<S4>/Init L3G4200D' */
} D_Work_st;

/* Parameters (auto storage) */
struct Parameters_st_ {
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S5>/Gain'
                                        */
  int16_T ShiftArithmetic_Power2Exponent;/* Computed Parameter: ShiftArithmetic_Power2Exponent
                                          * Referenced by: '<S13>/Shift Arithmetic'
                                          */
  int16_T ShiftArithmetic_Power2Exponen_d;/* Computed Parameter: ShiftArithmetic_Power2Exponen_d
                                           * Referenced by: '<S14>/Shift Arithmetic'
                                           */
  int16_T ShiftArithmetic_Power2Exponen_g;/* Computed Parameter: ShiftArithmetic_Power2Exponen_g
                                           * Referenced by: '<S15>/Shift Arithmetic'
                                           */
  uint8_T CNTRL_REG1_Value;            /* Computed Parameter: CNTRL_REG1_Value
                                        * Referenced by: '<S8>/CNTRL_REG1'
                                        */
  uint8_T CNTRL_REG2_Value;            /* Computed Parameter: CNTRL_REG2_Value
                                        * Referenced by: '<S8>/CNTRL_REG2'
                                        */
  uint8_T CNTRL_REG4_Value;            /* Computed Parameter: CNTRL_REG4_Value
                                        * Referenced by: '<S8>/CNTRL_REG4'
                                        */
  uint8_T Enable_Value;                /* Computed Parameter: Enable_Value
                                        * Referenced by: '<S8>/Enable'
                                        */
  uint8_T FS1_Value;                   /* Computed Parameter: FS1_Value
                                        * Referenced by: '<S8>/FS 1'
                                        */
  uint8_T FS250_Value;                 /* Computed Parameter: FS250_Value
                                        * Referenced by: '<S8>/FS 250'
                                        */
  uint8_T OUT_X_L_Value;               /* Computed Parameter: OUT_X_L_Value
                                        * Referenced by: '<S9>/OUT_X_L'
                                        */
  uint8_T OUT_X_H_Value;               /* Computed Parameter: OUT_X_H_Value
                                        * Referenced by: '<S9>/OUT_X_H'
                                        */
  uint8_T OUT_Y_L_Value;               /* Computed Parameter: OUT_Y_L_Value
                                        * Referenced by: '<S9>/OUT_Y_L'
                                        */
  uint8_T OUT_Y_H_Value;               /* Computed Parameter: OUT_Y_H_Value
                                        * Referenced by: '<S9>/OUT_Y_H'
                                        */
  uint8_T OUT_Z_L_Value;               /* Computed Parameter: OUT_Z_L_Value
                                        * Referenced by: '<S9>/OUT_Z_L'
                                        */
  uint8_T OUT_Z_H_Value;               /* Computed Parameter: OUT_Z_H_Value
                                        * Referenced by: '<S9>/OUT_Z_H'
                                        */
  uint8_T SlvAddr1_Value;              /* Computed Parameter: SlvAddr1_Value
                                        * Referenced by: '<S4>/SlvAddr1'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint8_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T CNTRL_REG2_Value_p;          /* Computed Parameter: CNTRL_REG2_Value_p
                                        * Referenced by: '<S7>/CNTRL_REG2'
                                        */
  uint8_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint8_T CNTRL_REG5_Value;            /* Computed Parameter: CNTRL_REG5_Value
                                        * Referenced by: '<S7>/CNTRL_REG5'
                                        */
  uint8_T Constant_Value_m;            /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T CNTRL_REG3_Value;            /* Computed Parameter: CNTRL_REG3_Value
                                        * Referenced by: '<S7>/CNTRL_REG3'
                                        */
  uint8_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T Constant_Value_n;            /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S6>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_st {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_st st_P;

/* Block signals (auto storage) */
extern BlockIO_st st_B;

/* Block states (auto storage) */
extern D_Work_st st_DWork;

/* Model entry point functions */
extern void st_initialize(void);
extern void st_step(void);
extern void st_terminate(void);

/* Real-time Model object */
extern RT_MODEL_st *const st_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'st'
 * '<S1>'   : 'st/Compare To Zero1'
 * '<S2>'   : 'st/Compare To Zero2'
 * '<S3>'   : 'st/Fail'
 * '<S4>'   : 'st/L3G4200D'
 * '<S5>'   : 'st/Success'
 * '<S6>'   : 'st/L3G4200D/Compare To Zero'
 * '<S7>'   : 'st/L3G4200D/Get Init L3G4200D1'
 * '<S8>'   : 'st/L3G4200D/Init L3G4200D'
 * '<S9>'   : 'st/L3G4200D/Read L3G4200D'
 * '<S10>'  : 'st/L3G4200D/Get Init L3G4200D1/Compare To Constant4'
 * '<S11>'  : 'st/L3G4200D/Get Init L3G4200D1/Compare To Constant5'
 * '<S12>'  : 'st/L3G4200D/Get Init L3G4200D1/Compare To Constant6'
 * '<S13>'  : 'st/L3G4200D/Read L3G4200D/Subsystem'
 * '<S14>'  : 'st/L3G4200D/Read L3G4200D/Subsystem1'
 * '<S15>'  : 'st/L3G4200D/Read L3G4200D/Subsystem2'
 */
#endif                                 /* RTW_HEADER_st_h_ */

/* [EOF] */
