//
// File: kalman_airspeed_data.cpp
//
// Code generated for Simulink model 'kalman_airspeed'.
//
// Model version                  : 1.56
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Mon May 11 09:28:48 2020
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
#include "kalman_airspeed.h"
#include "kalman_airspeed_private.h"

// Constant parameters (auto storage)
const ConstP_kalman_airspeed_T kalman_airspeed_ConstP = {
  // Expression: single(diag([10^-2 10^-2 10^-4 10^-5 10^-5 10^-5 10^-5 10^-1 10^-9]));
  //  Referenced by: '<S1>/P Delay'

  { 0.01F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0001F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 1.0E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    1.0E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.1F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0E-9F },

  // Expression: single([0 0 0 0 0 0 0 1 1]')
  //  Referenced by: '<S1>/X Delay1'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
