//
// File: kalman_airspeed.cpp
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
#include "kalman_airspeed.h"
#include "kalman_airspeed_private.h"

// Named constants for Chart: '<S1>/Chart'
#define kalman_airsp_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define kalman_airspeed_IN_kalman_off  ((uint8_T)1U)
#define kalman_airspeed_IN_kalman_on   ((uint8_T)2U)

// Function for Chart: '<S1>/Chart'
void kalman_airspeedModelClass::kalman_airspeed_stateDetermine(boolean_T
  RotaryWingTB, boolean_T TransitionToFwTB, real32_T IAS_hatTB, real32_T hkTB,
  boolean_T *InitParamTB, boolean_T *PauseKalmanTB, real32_T *StateTB)
{
  boolean_T aVarTruthTableCondition_4;
  boolean_T aVarTruthTableCondition_5;
  aVarTruthTableCondition_4 = ((IAS_hatTB > 0.0F) && (IAS_hatTB < 50.0F));
  aVarTruthTableCondition_5 = (hkTB > 0.0F);
  if ((!aVarTruthTableCondition_4) && (!aVarTruthTableCondition_5)) {
    *InitParamTB = true;
    *PauseKalmanTB = true;
    *StateTB = 6.0F;
  } else if (aVarTruthTableCondition_4 && (!aVarTruthTableCondition_5)) {
    *InitParamTB = false;
    *PauseKalmanTB = true;
    *StateTB = 5.0F;
  } else if ((!aVarTruthTableCondition_4) && aVarTruthTableCondition_5) {
    *InitParamTB = true;
    *PauseKalmanTB = false;
    *StateTB = 4.0F;
  } else if (((RotaryWingTB && TransitionToFwTB) && aVarTruthTableCondition_4) &&
             aVarTruthTableCondition_5) {
    *InitParamTB = true;
    *PauseKalmanTB = false;
    *StateTB = 1.0F;
  } else if (((RotaryWingTB && (!TransitionToFwTB)) && aVarTruthTableCondition_4)
             && aVarTruthTableCondition_5) {
    *InitParamTB = false;
    *PauseKalmanTB = true;
    *StateTB = 3.0F;
  } else {
    *InitParamTB = false;
    *PauseKalmanTB = false;
    *StateTB = 2.0F;
  }
}

// Model step function
void kalman_airspeedModelClass::step()
{
  real_T S_ref;
  real_T CD_mean;
  real32_T V_rb[3];
  real32_T V_a;
  real32_T Vbar_rb[3];
  real32_T Vbar_a;
  real32_T L_u;
  real32_T sigma_u;
  real32_T dt2;
  real_T Q[81];
  real32_T F[81];
  real32_T x_hat[9];
  real_T R[4];
  real32_T H[18];
  real32_T P_hat[81];
  real32_T Innov[4];
  real32_T Kgain[18];
  real32_T y[18];
  int32_T r1;
  int32_T r2;
  static const int8_T c[9] = { 1, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[9] = { 0, 1, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T e[9] = { 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  static const int8_T f[9] = { 0, 0, 0, 0, 0, 0, 1, 0, 0 };

  static const int8_T g[9] = { 0, 0, 0, 0, 0, 0, 0, 1, 0 };

  static const int8_T h[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  real32_T rtb_Delay2;
  real32_T rtb_UnitConversion;
  int32_T i;
  real32_T tmp[3];
  int32_T i_0;
  real32_T F_0[81];
  real_T cToRps_idx_0;
  real_T cToRps_idx_1;
  real_T f1_idx_6;
  real_T f1_idx_7;
  real_T h1_idx_1;
  real_T h1_idx_2;
  real_T Thrust_coe_idx_1;
  real_T h1_idx_10;
  real_T Thrust_coe_idx_0;
  real32_T x_hat_idx_2_tmp;
  real32_T h1_idx_1_tmp;
  real32_T h1_idx_1_tmp_0;
  real32_T h1_idx_1_tmp_1;
  real32_T h1_idx_5_tmp;
  int32_T P_hat_tmp;
  int32_T Kgain_tmp;

  // Delay: '<S1>/Delay2'
  rtb_Delay2 = kalman_airspeed_DW.Delay2_DSTATE;

  // Chart: '<S1>/Chart' incorporates:
  //   Inport: '<Root>/uORB'

  if (((uint32_T)kalman_airspeed_DW.is_active_c1_AirspeedSyntheticI) == 0U) {
    kalman_airspeed_DW.is_active_c1_AirspeedSyntheticI = 1U;
    kalman_airspeed_DW.is_c1_AirspeedSyntheticImprove =
      kalman_airspeed_IN_kalman_off;
    kalman_airspeed_DW.InitParam = true;
    kalman_airspeed_DW.PauseKalman = true;

    // Outport: '<Root>/State'
    kalman_airspeed_Y.State = 0.0F;
  } else if (((uint32_T)kalman_airspeed_DW.is_c1_AirspeedSyntheticImprove) ==
             kalman_airspeed_IN_kalman_off) {
    if ((kalman_airspeed_U.uORB[0]) && ((kalman_airspeed_U.uORB[1]) &&
         ((kalman_airspeed_U.uORB[2]) && ((kalman_airspeed_U.uORB[3]) &&
           (kalman_airspeed_U.uORB[4]))))) {
      kalman_airspeed_DW.is_c1_AirspeedSyntheticImprove =
        kalman_airspeed_IN_kalman_on;

      // Outport: '<Root>/State' incorporates:
      //   Inport: '<Root>/TransitionToFw'
      //   Inport: '<Root>/hk'
      //   Inport: '<Root>/isR'
      //   Inport: '<Root>/isT'

      kalman_airspeed_stateDetermine(kalman_airspeed_U.isR,
        kalman_airspeed_U.TransitionToFw, rtb_Delay2, kalman_airspeed_U.hk,
        &kalman_airspeed_DW.InitParam, &kalman_airspeed_DW.PauseKalman,
        &kalman_airspeed_Y.State);
    }
  } else {
    // Outport: '<Root>/State' incorporates:
    //   Inport: '<Root>/TransitionToFw'
    //   Inport: '<Root>/hk'
    //   Inport: '<Root>/isR'
    //   Inport: '<Root>/isT'

    kalman_airspeed_stateDetermine(kalman_airspeed_U.isR,
      kalman_airspeed_U.TransitionToFw, rtb_Delay2, kalman_airspeed_U.hk,
      &kalman_airspeed_DW.InitParam, &kalman_airspeed_DW.PauseKalman,
      &kalman_airspeed_Y.State);
  }

  // End of Chart: '<S1>/Chart'

  // Delay: '<S1>/P Delay'
  if (((((int32_T)(kalman_airspeed_DW.InitParam ? 1 : 0)) != ((int32_T)
         ((((uint32_T)kalman_airspeed_PrevZCX.PDelay_Reset_ZCE) == POS_ZCSIG) ?
          1 : 0))) && (((uint32_T)kalman_airspeed_PrevZCX.PDelay_Reset_ZCE) !=
                       UNINITIALIZED_ZCSIG)) || (kalman_airspeed_DW.InitParam))
  {
    memcpy(&kalman_airspeed_DW.PDelay_DSTATE[0],
           kalman_airspeed_ConstP.PDelay_InitialCondition, 81U * (sizeof
            (real32_T)));
  }

  kalman_airspeed_PrevZCX.PDelay_Reset_ZCE = kalman_airspeed_DW.InitParam ? 1U :
    0U;

  // Delay: '<S1>/X Delay1'
  if (((((int32_T)(kalman_airspeed_DW.InitParam ? 1 : 0)) != ((int32_T)
         ((((uint32_T)kalman_airspeed_PrevZCX.XDelay1_Reset_ZCE) == POS_ZCSIG) ?
          1 : 0))) && (((uint32_T)kalman_airspeed_PrevZCX.XDelay1_Reset_ZCE) !=
                       UNINITIALIZED_ZCSIG)) || (kalman_airspeed_DW.InitParam))
  {
    for (i = 0; i < 9; i++) {
      kalman_airspeed_DW.XDelay1_DSTATE[i] =
        kalman_airspeed_ConstP.XDelay1_InitialCondition[(i)];
    }
  }

  kalman_airspeed_PrevZCX.XDelay1_Reset_ZCE = kalman_airspeed_DW.InitParam ? 1U :
    0U;

  // Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  // Logic: '<S1>/Logical Operator1'
  if (!kalman_airspeed_DW.PauseKalman) {
    if (!kalman_airspeed_DW.Subsystem_MODE) {
      kalman_airspeed_DW.Subsystem_MODE = true;
    }

    // UnitConversion: '<S4>/Unit Conversion' incorporates:
    //   Inport: '<Root>/dT'

    // Unit Conversion - from: us to: sec
    // Expression: output = (1e-06*input) + (0)
    rtb_UnitConversion = 1.0E-6F * kalman_airspeed_U.dT;

    // MATLAB Function: '<S4>/FunctionOfModule' incorporates:
    //   Delay: '<S1>/P Delay'
    //   Delay: '<S1>/X Delay1'
    //   Inport: '<Root>/Ax'
    //   Inport: '<Root>/Az'
    //   Inport: '<Root>/T_bn'
    //   Inport: '<Root>/V_W6'
    //   Inport: '<Root>/actuatorControlThrust'
    //   Inport: '<Root>/covR'
    //   Inport: '<Root>/hk'
    //   Inport: '<Root>/rho'
    //   Inport: '<Root>/u_b'
    //   Inport: '<Root>/v_b'
    //   Inport: '<Root>/version'
    //   Inport: '<Root>/w_b'

    switch (kalman_airspeed_U.version) {
     case 40:
      i = 42;
      S_ref = 1.4;
      CD_mean = 0.0891;
      Thrust_coe_idx_0 = 0.0382;
      cToRps_idx_0 = 54.9707;
      Thrust_coe_idx_1 = -0.1314;
      cToRps_idx_1 = 53.5937;
      break;

     case 60:
      i = 60;
      S_ref = 1.714;
      CD_mean = 0.09;
      Thrust_coe_idx_0 = 0.0477;
      cToRps_idx_0 = 33.5563;
      Thrust_coe_idx_1 = -0.1101;
      cToRps_idx_1 = 49.8235;
      break;

     default:
      i = 42;
      S_ref = 1.4;
      CD_mean = 0.0891;
      Thrust_coe_idx_0 = 0.0382;
      cToRps_idx_0 = 54.9707;
      Thrust_coe_idx_1 = -0.1314;
      cToRps_idx_1 = 53.5937;
      break;
    }

    rtb_Delay2 = (kalman_airspeed_U.actuatorControlThrust * ((real32_T)
      cToRps_idx_0)) + ((real32_T)cToRps_idx_1);
    tmp[0] = kalman_airspeed_U.u_b;
    tmp[1] = kalman_airspeed_U.v_b;
    tmp[2] = kalman_airspeed_U.w_b;
    Vbar_a = kalman_airspeed_DW.XDelay1_DSTATE[0] +
      kalman_airspeed_DW.XDelay1_DSTATE[3];
    V_a = kalman_airspeed_DW.XDelay1_DSTATE[1] +
      kalman_airspeed_DW.XDelay1_DSTATE[4];
    dt2 = kalman_airspeed_DW.XDelay1_DSTATE[2] +
      kalman_airspeed_DW.XDelay1_DSTATE[5];
    for (i_0 = 0; i_0 < 3; i_0++) {
      V_rb[i_0] = tmp[i_0] - (((kalman_airspeed_U.T_bn[i_0] * Vbar_a) +
        (kalman_airspeed_U.T_bn[i_0 + 3] * V_a)) + (kalman_airspeed_U.T_bn[i_0 +
        6] * dt2));
    }

    tmp[0] = kalman_airspeed_U.u_b;
    tmp[1] = kalman_airspeed_U.v_b;
    tmp[2] = kalman_airspeed_U.w_b;
    for (i_0 = 0; i_0 < 3; i_0++) {
      Vbar_rb[i_0] = tmp[i_0] - (((kalman_airspeed_U.T_bn[i_0] *
        kalman_airspeed_DW.XDelay1_DSTATE[0]) + (kalman_airspeed_U.T_bn[i_0 + 3]
        * kalman_airspeed_DW.XDelay1_DSTATE[1])) + (kalman_airspeed_U.T_bn[i_0 +
        6] * kalman_airspeed_DW.XDelay1_DSTATE[2]));
    }

    Vbar_a = sqrtf(((Vbar_rb[0] * Vbar_rb[0]) + (Vbar_rb[1] * Vbar_rb[1])) +
                   (Vbar_rb[2] * Vbar_rb[2]));
    V_a = 0.177F + (0.000823F * kalman_airspeed_U.hk);
    L_u = kalman_airspeed_U.hk / powf(V_a, 1.2F);
    dt2 = rtb_UnitConversion * rtb_UnitConversion;
    memset(&Q[0], 0, 81U * (sizeof(real_T)));
    Q[0] = (real_T)((real32_T)(dt2 * 1.0E-7F));
    Q[10] = (real_T)((real32_T)(dt2 * 1.0E-7F));
    Q[20] = (real_T)((real32_T)(dt2 * 1.0E-10F));
    sigma_u = (2.0F * rtb_UnitConversion) * sqrtf(((V_rb[0] * V_rb[0]) + (V_rb[1]
      * V_rb[1])) + (V_rb[2] * V_rb[2]));
    cToRps_idx_0 = (real_T)((real32_T)(((dt2 * 0.01F) * ((kalman_airspeed_U.V_W6
      * 0.1F) / powf(V_a, 0.4F))) * sqrtf(sigma_u / L_u)));
    Q[30] = cToRps_idx_0;
    Q[40] = cToRps_idx_0;
    Q[50] = (real_T)((real32_T)(((dt2 * 0.02F) * (kalman_airspeed_U.V_W6 * 0.1F))
      * sqrtf(sigma_u / kalman_airspeed_U.hk)));
    Q[60] = (real_T)((real32_T)(dt2 * 1.0E-10F));
    Q[70] = (real_T)((real32_T)(dt2 * 1.0E-8F));
    Q[80] = (real_T)((real32_T)(dt2 * 1.0E-15F));
    V_a = (((kalman_airspeed_U.T_bn[0] * kalman_airspeed_DW.XDelay1_DSTATE[0]) -
            kalman_airspeed_U.u_b) + (kalman_airspeed_U.T_bn[3] *
            kalman_airspeed_DW.XDelay1_DSTATE[1])) + (kalman_airspeed_U.T_bn[6] *
      kalman_airspeed_DW.XDelay1_DSTATE[2]);
    dt2 = (((kalman_airspeed_U.T_bn[1] * kalman_airspeed_DW.XDelay1_DSTATE[0]) -
            kalman_airspeed_U.v_b) + (kalman_airspeed_U.T_bn[4] *
            kalman_airspeed_DW.XDelay1_DSTATE[1])) + (kalman_airspeed_U.T_bn[7] *
      kalman_airspeed_DW.XDelay1_DSTATE[2]);
    sigma_u = (((kalman_airspeed_U.T_bn[2] * kalman_airspeed_DW.XDelay1_DSTATE[0])
                - kalman_airspeed_U.w_b) + (kalman_airspeed_U.T_bn[5] *
                kalman_airspeed_DW.XDelay1_DSTATE[1])) +
      (kalman_airspeed_U.T_bn[8] * kalman_airspeed_DW.XDelay1_DSTATE[2]);
    cToRps_idx_0 = 1.0 / sqrt((real_T)((real32_T)(((V_a * V_a) + (dt2 * dt2)) +
      (sigma_u * sigma_u))));
    cToRps_idx_1 = (real_T)((real32_T)((((2.0F * kalman_airspeed_U.T_bn[6]) *
      V_a) + ((2.0F * kalman_airspeed_U.T_bn[7]) * dt2)) + ((2.0F *
      kalman_airspeed_U.T_bn[8]) * sigma_u)));
    f1_idx_6 = (real_T)((real32_T)((((2.0F * kalman_airspeed_U.T_bn[3]) * V_a) +
      ((2.0F * kalman_airspeed_U.T_bn[4]) * dt2)) + ((2.0F *
      kalman_airspeed_U.T_bn[5]) * sigma_u)));
    f1_idx_7 = (real_T)((real32_T)((((2.0F * kalman_airspeed_U.T_bn[0]) * V_a) +
      ((2.0F * kalman_airspeed_U.T_bn[1]) * dt2)) + ((2.0F *
      kalman_airspeed_U.T_bn[2]) * sigma_u)));
    V_a = (rtb_UnitConversion * kalman_airspeed_DW.XDelay1_DSTATE[3]) *
      ((real32_T)cToRps_idx_0);
    F[3] = (-(V_a * ((real32_T)f1_idx_7))) / (2.0F * L_u);
    F[12] = (-(V_a * ((real32_T)f1_idx_6))) / (2.0F * L_u);
    F[21] = (-(V_a * ((real32_T)cToRps_idx_1))) / (2.0F * L_u);
    V_a = 1.0F - (rtb_UnitConversion / (L_u * ((real32_T)cToRps_idx_0)));
    F[30] = V_a;
    F[39] = 0.0F;
    F[48] = 0.0F;
    F[57] = 0.0F;
    F[66] = 0.0F;
    F[75] = 0.0F;
    dt2 = (rtb_UnitConversion * kalman_airspeed_DW.XDelay1_DSTATE[4]) *
      ((real32_T)cToRps_idx_0);
    F[4] = (-(dt2 * ((real32_T)f1_idx_7))) / (2.0F * L_u);
    F[13] = (-(dt2 * ((real32_T)f1_idx_6))) / (2.0F * L_u);
    F[22] = (-(dt2 * ((real32_T)cToRps_idx_1))) / (2.0F * L_u);
    F[31] = 0.0F;
    F[40] = V_a;
    F[49] = 0.0F;
    F[58] = 0.0F;
    F[67] = 0.0F;
    F[76] = 0.0F;
    V_a = (rtb_UnitConversion * kalman_airspeed_DW.XDelay1_DSTATE[5]) *
      ((real32_T)cToRps_idx_0);
    F[5] = (-(V_a * ((real32_T)f1_idx_7))) / (2.0F * kalman_airspeed_U.hk);
    F[14] = (-(V_a * ((real32_T)f1_idx_6))) / (2.0F * kalman_airspeed_U.hk);
    F[23] = (-(V_a * ((real32_T)cToRps_idx_1))) / (2.0F * kalman_airspeed_U.hk);
    F[32] = 0.0F;
    F[41] = 0.0F;
    F[50] = 1.0F - (rtb_UnitConversion / (kalman_airspeed_U.hk * ((real32_T)
      cToRps_idx_0)));
    F[59] = 0.0F;
    F[68] = 0.0F;
    F[77] = 0.0F;
    for (i_0 = 0; i_0 < 9; i_0++) {
      F[9 * i_0] = (real32_T)c[i_0];
      F[1 + (9 * i_0)] = (real32_T)d[i_0];
      F[2 + (9 * i_0)] = (real32_T)e[i_0];
      F[6 + (9 * i_0)] = (real32_T)f[i_0];
      F[7 + (9 * i_0)] = (real32_T)g[i_0];
      F[8 + (9 * i_0)] = (real32_T)h[i_0];
    }

    x_hat[0] = kalman_airspeed_DW.XDelay1_DSTATE[0];
    x_hat[1] = kalman_airspeed_DW.XDelay1_DSTATE[1];
    x_hat[2] = kalman_airspeed_DW.XDelay1_DSTATE[2];
    x_hat[3] = kalman_airspeed_DW.XDelay1_DSTATE[3] -
      (((kalman_airspeed_DW.XDelay1_DSTATE[3] * rtb_UnitConversion) * Vbar_a) /
       L_u);
    x_hat[4] = kalman_airspeed_DW.XDelay1_DSTATE[4] -
      (((kalman_airspeed_DW.XDelay1_DSTATE[4] * rtb_UnitConversion) * Vbar_a) /
       L_u);
    x_hat[5] = kalman_airspeed_DW.XDelay1_DSTATE[5] -
      (((kalman_airspeed_DW.XDelay1_DSTATE[5] * rtb_UnitConversion) * Vbar_a) /
       kalman_airspeed_U.hk);
    x_hat[6] = kalman_airspeed_DW.XDelay1_DSTATE[6];
    x_hat[7] = kalman_airspeed_DW.XDelay1_DSTATE[7];
    x_hat[8] = kalman_airspeed_DW.XDelay1_DSTATE[8];
    tmp[0] = kalman_airspeed_U.u_b;
    tmp[1] = kalman_airspeed_U.v_b;
    tmp[2] = kalman_airspeed_U.w_b;
    L_u = kalman_airspeed_DW.XDelay1_DSTATE[0] + x_hat[3];
    sigma_u = kalman_airspeed_DW.XDelay1_DSTATE[1] + x_hat[4];
    x_hat_idx_2_tmp = kalman_airspeed_DW.XDelay1_DSTATE[2] + x_hat[5];
    for (i_0 = 0; i_0 < 3; i_0++) {
      V_rb[i_0] = tmp[i_0] - (((kalman_airspeed_U.T_bn[i_0] * L_u) +
        (kalman_airspeed_U.T_bn[i_0 + 3] * sigma_u)) +
        (kalman_airspeed_U.T_bn[i_0 + 6] * x_hat_idx_2_tmp));
    }

    V_a = sqrtf(((V_rb[0] * V_rb[0]) + (V_rb[1] * V_rb[1])) + (V_rb[2] * V_rb[2]));
    tmp[0] = kalman_airspeed_U.u_b;
    tmp[1] = kalman_airspeed_U.v_b;
    tmp[2] = kalman_airspeed_U.w_b;
    for (i_0 = 0; i_0 < 3; i_0++) {
      Vbar_rb[i_0] = tmp[i_0] - (((kalman_airspeed_U.T_bn[i_0] *
        kalman_airspeed_DW.XDelay1_DSTATE[0]) + (kalman_airspeed_U.T_bn[i_0 + 3]
        * x_hat[1])) + (kalman_airspeed_U.T_bn[i_0 + 6] * x_hat[2]));
    }

    Vbar_a = sqrtf(((Vbar_rb[0] * Vbar_rb[0]) + (Vbar_rb[1] * Vbar_rb[1])) +
                   (Vbar_rb[2] * Vbar_rb[2]));
    R[1] = 0.0;
    R[2] = 0.0;
    R[0] = (real_T)kalman_airspeed_U.covR[0];
    R[3] = (real_T)kalman_airspeed_U.covR[1];
    dt2 = 2.0F * ((real32_T)i);
    rtb_UnitConversion = (kalman_airspeed_U.rho * ((real32_T)S_ref)) / dt2;
    f1_idx_7 = (real_T)((real32_T)((((kalman_airspeed_U.T_bn[0] * L_u) -
      kalman_airspeed_U.u_b) + (kalman_airspeed_U.T_bn[3] * sigma_u)) +
      (kalman_airspeed_U.T_bn[6] * x_hat_idx_2_tmp)));
    h1_idx_1_tmp = kalman_airspeed_U.T_bn[2] * L_u;
    h1_idx_1_tmp_0 = kalman_airspeed_U.T_bn[5] * sigma_u;
    h1_idx_1_tmp_1 = kalman_airspeed_U.T_bn[8] * x_hat_idx_2_tmp;
    h1_idx_1 = (real_T)((real32_T)(((h1_idx_1_tmp - kalman_airspeed_U.w_b) +
      h1_idx_1_tmp_0) + h1_idx_1_tmp_1));
    h1_idx_2 = (real_T)((real32_T)((((kalman_airspeed_U.T_bn[1] * L_u) -
      kalman_airspeed_U.v_b) + (kalman_airspeed_U.T_bn[4] * sigma_u)) +
      (kalman_airspeed_U.T_bn[7] * x_hat_idx_2_tmp)));
    L_u = atan2f(((kalman_airspeed_U.w_b - h1_idx_1_tmp) - h1_idx_1_tmp_0) -
                 h1_idx_1_tmp_1, (real32_T)((real_T)(-f1_idx_7)));
    cToRps_idx_1 = f1_idx_7 * f1_idx_7;
    f1_idx_6 = cToRps_idx_1 + (h1_idx_1 * h1_idx_1);
    cToRps_idx_0 = f1_idx_6 + (h1_idx_2 * h1_idx_2);
    h1_idx_1_tmp_0 = (-rtb_UnitConversion) * (kalman_airspeed_DW.XDelay1_DSTATE
      [6] + (((180.0F * kalman_airspeed_DW.XDelay1_DSTATE[7]) * L_u) /
             3.14159274F));
    h1_idx_1_tmp_1 = (((180.0F * kalman_airspeed_DW.XDelay1_DSTATE[7]) *
                       rtb_UnitConversion) * ((real32_T)cToRps_idx_1)) *
      ((real32_T)cToRps_idx_0);
    h1_idx_5_tmp = (real32_T)((real_T)(3.1415926535897931 * f1_idx_6));
    sigma_u = (((2.0F * kalman_airspeed_U.T_bn[6]) * ((real32_T)f1_idx_7)) +
               ((2.0F * kalman_airspeed_U.T_bn[7]) * ((real32_T)h1_idx_2))) +
      ((2.0F * kalman_airspeed_U.T_bn[8]) * ((real32_T)h1_idx_1));
    cToRps_idx_1 = (real_T)((real32_T)((h1_idx_1_tmp_0 * sigma_u) -
      ((h1_idx_1_tmp_1 * ((kalman_airspeed_U.T_bn[8] / ((real32_T)f1_idx_7)) -
                          ((kalman_airspeed_U.T_bn[6] * ((real32_T)h1_idx_1)) /
      ((real32_T)((real_T)(f1_idx_7 * f1_idx_7)))))) / h1_idx_5_tmp)));
    x_hat_idx_2_tmp = (((2.0F * kalman_airspeed_U.T_bn[3]) * ((real32_T)f1_idx_7))
                       + ((2.0F * kalman_airspeed_U.T_bn[4]) * ((real32_T)
      h1_idx_2))) + ((2.0F * kalman_airspeed_U.T_bn[5]) * ((real32_T)h1_idx_1));
    f1_idx_6 = (real_T)((real32_T)((h1_idx_1_tmp_0 * x_hat_idx_2_tmp) -
      ((h1_idx_1_tmp_1 * ((kalman_airspeed_U.T_bn[5] / ((real32_T)f1_idx_7)) -
                          ((kalman_airspeed_U.T_bn[3] * ((real32_T)h1_idx_1)) /
      ((real32_T)((real_T)(f1_idx_7 * f1_idx_7)))))) / h1_idx_5_tmp)));
    h1_idx_1_tmp = (((2.0F * kalman_airspeed_U.T_bn[0]) * ((real32_T)f1_idx_7))
                    + ((2.0F * kalman_airspeed_U.T_bn[1]) * ((real32_T)h1_idx_2)))
      + ((2.0F * kalman_airspeed_U.T_bn[2]) * ((real32_T)h1_idx_1));
    f1_idx_7 = (real_T)((real32_T)((h1_idx_1_tmp_0 * h1_idx_1_tmp) -
      ((h1_idx_1_tmp_1 * ((kalman_airspeed_U.T_bn[2] / ((real32_T)f1_idx_7)) -
                          ((kalman_airspeed_U.T_bn[0] * ((real32_T)h1_idx_1)) /
      ((real32_T)((real_T)(f1_idx_7 * f1_idx_7)))))) / h1_idx_5_tmp)));
    h1_idx_1_tmp_0 = rtb_Delay2 * ((real32_T)Thrust_coe_idx_1);
    h1_idx_1_tmp_1 = (real32_T)((real_T)((2.0 * ((real_T)i)) * sqrt(cToRps_idx_0)));
    h1_idx_1 = (real_T)((real32_T)((h1_idx_1_tmp_0 * sigma_u) / h1_idx_1_tmp_1));
    h1_idx_2 = (real_T)((real32_T)((h1_idx_1_tmp_0 * x_hat_idx_2_tmp) /
      h1_idx_1_tmp_1));
    h1_idx_10 = (real_T)((real32_T)((h1_idx_1_tmp_0 * h1_idx_1_tmp) /
      h1_idx_1_tmp_1));
    H[0] = (real32_T)f1_idx_7;
    H[2] = (real32_T)f1_idx_6;
    H[4] = (real32_T)cToRps_idx_1;
    H[6] = (real32_T)f1_idx_7;
    H[8] = (real32_T)f1_idx_6;
    H[10] = (real32_T)cToRps_idx_1;
    H[12] = (-rtb_UnitConversion) * ((real32_T)cToRps_idx_0);
    H[14] = (-(((180.0F * rtb_UnitConversion) * ((real32_T)cToRps_idx_0)) * L_u))
      / 3.14159274F;
    H[16] = 0.0F;
    H[1] = (real32_T)h1_idx_10;
    H[3] = (real32_T)h1_idx_2;
    H[5] = (real32_T)h1_idx_1;
    H[7] = (real32_T)h1_idx_10;
    H[9] = (real32_T)h1_idx_2;
    H[11] = (real32_T)h1_idx_1;
    H[13] = 0.0F;
    H[15] = 0.0F;
    H[17] = 0.0F;
    for (i_0 = 0; i_0 < 9; i_0++) {
      for (r1 = 0; r1 < 9; r1++) {
        r2 = i_0 + (9 * r1);
        F_0[r2] = 0.0F;
        for (P_hat_tmp = 0; P_hat_tmp < 9; P_hat_tmp++) {
          F_0[r2] += F[i_0 + (9 * P_hat_tmp)] *
            kalman_airspeed_DW.PDelay_DSTATE[P_hat_tmp + (9 * r1)];
        }
      }

      for (r1 = 0; r1 < 9; r1++) {
        L_u = F_0[i_0] * F[r1];
        for (P_hat_tmp = 0; P_hat_tmp < 8; P_hat_tmp++) {
          L_u += F_0[i_0 + (9 * (P_hat_tmp + 1))] * F[r1 + (9 * (P_hat_tmp + 1))];
        }

        P_hat_tmp = i_0 + (9 * r1);
        P_hat[P_hat_tmp] = L_u + ((real32_T)Q[P_hat_tmp]);
      }
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      for (r1 = 0; r1 < 9; r1++) {
        Kgain[i_0 + (r1 * 2)] = 0.0F;
        for (P_hat_tmp = 0; P_hat_tmp < 9; P_hat_tmp++) {
          Kgain[i_0 + (r1 * 2)] += H[i_0 + (P_hat_tmp * 2)] * P_hat[P_hat_tmp +
            (9 * r1)];
        }
      }

      for (r1 = 0; r1 < 2; r1++) {
        L_u = Kgain[i_0] * H[r1];
        for (P_hat_tmp = 0; P_hat_tmp < 8; P_hat_tmp++) {
          L_u += Kgain[i_0 + ((P_hat_tmp + 1) * 2)] * H[r1 + ((P_hat_tmp + 1) *
            2)];
        }

        Innov[i_0 + (r1 * 2)] = L_u + ((real32_T)R[i_0 + (r1 * 2)]);
      }
    }

    for (i_0 = 0; i_0 < 9; i_0++) {
      for (r1 = 0; r1 < 2; r1++) {
        r2 = i_0 + (9 * r1);
        y[r2] = 0.0F;
        for (P_hat_tmp = 0; P_hat_tmp < 9; P_hat_tmp++) {
          y[r2] += P_hat[i_0 + (9 * P_hat_tmp)] * H[r1 + (P_hat_tmp * 2)];
        }
      }
    }

    if (fabsf(Innov[1]) > fabsf(Innov[0])) {
      r1 = 1;
      r2 = 0;
    } else {
      r1 = 0;
      r2 = 1;
    }

    L_u = Innov[r2] / Innov[r1];
    sigma_u = Innov[2 + r2] - (L_u * Innov[2 + r1]);
    for (i_0 = 0; i_0 < 9; i_0++) {
      P_hat_tmp = i_0 + (9 * r1);
      Kgain[P_hat_tmp] = y[i_0] / Innov[r1];
      Kgain_tmp = i_0 + (9 * r2);
      Kgain[Kgain_tmp] = (y[9 + i_0] - (Kgain[P_hat_tmp] * Innov[2 + r1])) /
        sigma_u;
      Kgain[P_hat_tmp] = Kgain[i_0 + (9 * r1)] - (Kgain[Kgain_tmp] * L_u);
    }

    Vbar_a = kalman_airspeed_U.Az - (((-rtb_UnitConversion) * (Vbar_a * Vbar_a))
      * (kalman_airspeed_DW.XDelay1_DSTATE[6] +
         (kalman_airspeed_DW.XDelay1_DSTATE[7] * (57.2957802F * atan2f(V_rb[2],
      V_rb[0])))));
    V_a = kalman_airspeed_U.Ax - ((((((real32_T)Thrust_coe_idx_0) * (rtb_Delay2 *
      rtb_Delay2)) + ((((real32_T)Thrust_coe_idx_1) * rtb_Delay2) * V_a)) /
      ((real32_T)i)) + ((((kalman_airspeed_U.rho * (V_a * V_a)) * ((real32_T)
      S_ref)) * ((real32_T)CD_mean)) / dt2));
    for (i_0 = 0; i_0 < 9; i_0++) {
      // Outport: '<Root>/x_hat' incorporates:
      //   MATLAB Function: '<S4>/FunctionOfModule'

      kalman_airspeed_Y.x_hat[i_0] = x_hat[i_0] + ((Kgain[i_0] * Vbar_a) +
        (Kgain[i_0 + 9] * V_a));

      // MATLAB Function: '<S4>/FunctionOfModule'
      for (r1 = 0; r1 < 9; r1++) {
        P_hat_tmp = i_0 + (9 * r1);
        F[P_hat_tmp] = 0.0F;
        F[P_hat_tmp] += Kgain[i_0] * H[r1 * 2];
        F[P_hat_tmp] = F[i_0 + (9 * r1)] + (Kgain[i_0 + 9] * H[1 + (r1 * 2)]);
      }

      for (r1 = 0; r1 < 9; r1++) {
        // Outport: '<Root>/P_hat' incorporates:
        //   MATLAB Function: '<S4>/FunctionOfModule'

        L_u = F[i_0] * P_hat[9 * r1];
        for (P_hat_tmp = 0; P_hat_tmp < 8; P_hat_tmp++) {
          L_u += F[i_0 + (9 * (P_hat_tmp + 1))] * P_hat[(P_hat_tmp + (9 * r1)) +
            1];
        }

        // MATLAB Function: '<S4>/FunctionOfModule'
        P_hat_tmp = i_0 + (9 * r1);

        // Outport: '<Root>/P_hat' incorporates:
        //   MATLAB Function: '<S4>/FunctionOfModule'

        kalman_airspeed_Y.P_hat[P_hat_tmp] = P_hat[P_hat_tmp] - L_u;
      }
    }
  } else {
    if (kalman_airspeed_DW.Subsystem_MODE) {
      kalman_airspeed_DW.Subsystem_MODE = false;
    }
  }

  // End of Logic: '<S1>/Logical Operator1'
  // End of Outputs for SubSystem: '<S1>/Subsystem'

  // Sum: '<S3>/Sum of Elements2' incorporates:
  //   Outport: '<Root>/x_hat'

  rtb_Delay2 = kalman_airspeed_Y.x_hat[0] + kalman_airspeed_Y.x_hat[3];

  // Sum: '<S3>/Sum of Elements1' incorporates:
  //   Outport: '<Root>/x_hat'

  rtb_UnitConversion = kalman_airspeed_Y.x_hat[1] + kalman_airspeed_Y.x_hat[4];

  // Sum: '<S3>/Sum of Elements3' incorporates:
  //   Outport: '<Root>/x_hat'

  Vbar_a = kalman_airspeed_Y.x_hat[2] + kalman_airspeed_Y.x_hat[5];

  // Reshape: '<S3>/Reshape1' incorporates:
  //   Inport: '<Root>/u_b'
  //   Inport: '<Root>/v_b'
  //   Inport: '<Root>/w_b'

  tmp[0] = kalman_airspeed_U.u_b;
  tmp[1] = kalman_airspeed_U.v_b;
  tmp[2] = kalman_airspeed_U.w_b;

  // Sum: '<S3>/Vb-Wb' incorporates:
  //   Inport: '<Root>/T_bn'
  //   Product: '<S3>/Product'
  //   Reshape: '<S3>/Reshape'

  for (i_0 = 0; i_0 < 3; i_0++) {
    V_rb[i_0] = tmp[i_0] - (((kalman_airspeed_U.T_bn[i_0] * rtb_Delay2) +
      (kalman_airspeed_U.T_bn[i_0 + 3] * rtb_UnitConversion)) +
      (kalman_airspeed_U.T_bn[i_0 + 6] * Vbar_a));
  }

  // End of Sum: '<S3>/Vb-Wb'

  // Outport: '<Root>/IAS_hat'
  kalman_airspeed_Y.IAS_hat = V_rb[0];

  // Outport: '<Root>/valid' incorporates:
  //   Logic: '<S1>/Logical Operator'

  kalman_airspeed_Y.valid = !kalman_airspeed_DW.InitParam;

  // Update for Delay: '<S1>/Delay2'
  kalman_airspeed_DW.Delay2_DSTATE = V_rb[0];

  // Update for Delay: '<S1>/P Delay' incorporates:
  //   Outport: '<Root>/P_hat'

  memcpy(&kalman_airspeed_DW.PDelay_DSTATE[0], &kalman_airspeed_Y.P_hat[0], 81U *
         (sizeof(real32_T)));

  // Update for Delay: '<S1>/X Delay1' incorporates:
  //   Outport: '<Root>/x_hat'

  for (i = 0; i < 9; i++) {
    kalman_airspeed_DW.XDelay1_DSTATE[i] = kalman_airspeed_Y.x_hat[i];
  }

  // End of Update for Delay: '<S1>/X Delay1'
}

// Model initialize function
void kalman_airspeedModelClass::initialize()
{
  // Registration code

  // states (dwork)
  (void) memset((void *)&kalman_airspeed_DW, 0,
                sizeof(DW_kalman_airspeed_T));

  // external inputs
  (void)memset((void *)(&kalman_airspeed_U), 0, sizeof(ExtU_kalman_airspeed_T));

  // external outputs
  (void) memset((void *)&kalman_airspeed_Y, 0,
                sizeof(ExtY_kalman_airspeed_T));

  {
    int32_T i;
    kalman_airspeed_PrevZCX.PDelay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    kalman_airspeed_PrevZCX.XDelay1_Reset_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Delay: '<S1>/P Delay'
    memcpy(&kalman_airspeed_DW.PDelay_DSTATE[0],
           kalman_airspeed_ConstP.PDelay_InitialCondition, 81U * (sizeof
            (real32_T)));

    // InitializeConditions for Delay: '<S1>/X Delay1'
    for (i = 0; i < 9; i++) {
      kalman_airspeed_DW.XDelay1_DSTATE[i] =
        kalman_airspeed_ConstP.XDelay1_InitialCondition[(i)];
    }

    // End of InitializeConditions for Delay: '<S1>/X Delay1'

    // SystemInitialize for Chart: '<S1>/Chart'
    kalman_airspeed_DW.is_active_c1_AirspeedSyntheticI = 0U;
    kalman_airspeed_DW.is_c1_AirspeedSyntheticImprove =
      kalman_airsp_IN_NO_ACTIVE_CHILD;
  }
}

// Constructor
kalman_airspeedModelClass::kalman_airspeedModelClass()
{
}

// Destructor
kalman_airspeedModelClass::~kalman_airspeedModelClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
