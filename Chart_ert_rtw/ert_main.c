/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Apr 11 00:22:33 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Chart.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  Chart_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.8;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(rtM, 0);
  Chart_initialize();
  configureArduinoAVRTimer();
  runModel =
    rtmGetErrorStatus(rtM) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    runModel =
      rtmGetErrorStatus(rtM) == (NULL);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Chart_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
