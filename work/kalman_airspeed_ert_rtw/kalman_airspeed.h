//
// File: kalman_airspeed.h
//
// Code generated for Simulink model 'kalman_airspeed'.
//
// Model version                  : 1.49
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Thu Mar 19 11:39:42 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. Safety precaution
//    3. RAM efficiency
//    4. ROM efficiency
//    5. MISRA C:2012 guidelines
//    6. Polyspace
// Validation result: Passed (30), Warnings (2), Error (0)
//
#ifndef RTW_HEADER_kalman_airspeed_h_
#define RTW_HEADER_kalman_airspeed_h_
#include <math.h>
#include <string.h>
#ifndef kalman_airspeed_COMMON_INCLUDES_
# define kalman_airspeed_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 // kalman_airspeed_COMMON_INCLUDES_

#include "kalman_airspeed_types.h"

// Macros for accessing real-time model data structure

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  real32_T PDelay_DSTATE[81];          // '<S1>/P Delay'
  real32_T XDelay1_DSTATE[9];          // '<S1>/X Delay1'
  real32_T Delay2_DSTATE;              // '<S1>/Delay2'
  uint8_T is_active_c1_AirspeedSyntheticI;// '<S1>/Chart'
  uint8_T is_c1_AirspeedSyntheticImprove;// '<S1>/Chart'
  boolean_T InitParam;                 // '<S1>/Chart'
  boolean_T PauseKalman;               // '<S1>/Chart'
  boolean_T Subsystem_MODE;            // '<S1>/Subsystem'
} DW_kalman_airspeed_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState PDelay_Reset_ZCE;         // '<S1>/P Delay'
  ZCSigState XDelay1_Reset_ZCE;        // '<S1>/X Delay1'
} PrevZCX_kalman_airspeed_T;

// Constant parameters (auto storage)
typedef struct {
  // Expression: single(diag([10^-2 10^-2 10^-4 10^-5 10^-5 10^-5 10^-5 10^-1 10^-9]));
  //  Referenced by: '<S1>/P Delay'

  real32_T PDelay_InitialCondition[81];

  // Expression: single([0 0 0 0 0 0 0 1 1]')
  //  Referenced by: '<S1>/X Delay1'

  real32_T XDelay1_InitialCondition[9];
} ConstP_kalman_airspeed_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  boolean_T uORB[5];                   // '<Root>/uORB'
  boolean_T isR;                       // '<Root>/isR'
  boolean_T isT;                       // '<Root>/isT'
  boolean_T TransitionToFw;            // '<Root>/TransitionToFw'
  real32_T dT;                         // '<Root>/dT'
  real32_T hk;                         // '<Root>/hk'
  real32_T T_bn[9];                    // '<Root>/T_bn'
  real32_T rho;                        // '<Root>/rho'
  real32_T u_b;                        // '<Root>/u_b'
  real32_T v_b;                        // '<Root>/v_b'
  real32_T w_b;                        // '<Root>/w_b'
  real32_T Ax;                         // '<Root>/Ax'
  real32_T Az;                         // '<Root>/Az'
  real32_T V_W6;                       // '<Root>/V_W6'
  real32_T actuatorControlThrust;      // '<Root>/actuatorControlThrust'
  real32_T covR[2];                    // '<Root>/covR'
  int8_T version;                      // '<Root>/version'
} ExtU_kalman_airspeed_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real32_T x_hat[9];                   // '<Root>/x_hat'
  real32_T P_hat[81];                  // '<Root>/P_hat'
  real32_T IAS_hat;                    // '<Root>/IAS_hat'
  boolean_T valid;                     // '<Root>/valid'
  real32_T State;                      // '<Root>/State'
} ExtY_kalman_airspeed_T;

// Constant parameters (auto storage)
extern const ConstP_kalman_airspeed_T kalman_airspeed_ConstP;

// Class declaration for model kalman_airspeed
class kalman_airspeedModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_kalman_airspeed_T kalman_airspeed_U;

  // External outputs
  ExtY_kalman_airspeed_T kalman_airspeed_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  kalman_airspeedModelClass();

  // Destructor
  ~kalman_airspeedModelClass();

  // private data and function members
 private:
  // Block signals and states
  DW_kalman_airspeed_T kalman_airspeed_DW;
  PrevZCX_kalman_airspeed_T kalman_airspeed_PrevZCX;// Triggered events

  // private member function(s) for subsystem '<Root>'
  void kalman_airspeed_stateDetermine(boolean_T RotaryWingTB, boolean_T
    TransitionToFwTB, real32_T IAS_hatTB, real32_T hkTB, boolean_T *InitParamTB,
    boolean_T *PauseKalmanTB, real32_T *StateTB);
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'kalman_airspeed'
//  '<S1>'   : 'kalman_airspeed/ASS_SF'
//  '<S2>'   : 'kalman_airspeed/ASS_SF/Chart'
//  '<S3>'   : 'kalman_airspeed/ASS_SF/IAS_calculate'
//  '<S4>'   : 'kalman_airspeed/ASS_SF/Subsystem'
//  '<S5>'   : 'kalman_airspeed/ASS_SF/Subsystem/FunctionOfModule'


//-
//  Requirements for '<Root>': kalman_airspeed

#endif                                 // RTW_HEADER_kalman_airspeed_h_

//
// File trailer for generated code.
//
// [EOF]
//
