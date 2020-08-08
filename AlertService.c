/*
 * AlertService.c
 *
 *  Created on: Aug 8, 2020
 *      Author: sot1cob
 */
#include "AlertService.h"
#include <CNCDataCollector.h>

typedef void AlertFunctions(void);

void AlertNone(void);
void AlertMachineAttention(void);
void AlertEnvnmAttention(void);
void AlertTimerFailure(void);
void AlertStartUpCheckError(void);

int CurrentAlertType = ALERT_NONE;
int StartUpCheckStatus = NO_DATA;

AlertFunctions *const AlertTable[NUMALERTTYPES] = {
       AlertNone, AlertMachineAttention, AlertEnvnmAttention, AlertTimerFailure, AlertStartUpCheckError
};

void AlertNone (void)
{
    CurrentAlertType = ALERT_NONE;
    /* Do nothing */
}

void AlertMachineAttention (void)
{
    /* Attention is required for the Machine,
     * Part Dimension Variation is high/ Operating
     * Duration exceeds the limit.
     * send a warning messsage
     */
    CurrentAlertType = ALERT_NONE;
}

void AlertEnvnmAttention (void)
{
    /* Attention is required for the Environment
     * Temperature is high
     * send a warning messsage
     */
    CurrentAlertType = ALERT_NONE;
}

void AlertTimerFailure (void)
{
    /* Attention is required for device
     * Issue with the device Hardware
     * send a warning messsage
     */
    CurrentAlertType = ALERT_NONE;
}

void AlertStartUpCheckError (void)
{
    /* Attention is required for CNC Machine
     * Issue with the device Hardware
     * send a warning messsage
     */
    switch (CNCStartUpStatus)
    {
        case NO_DATA: /* no power, no connection to the data-collector */
            /* Send warning message: Machine has no Power/no connection */
            break;
        case MACHINE_NOT_OK:
            /* Send warning message: Controller board in the machine is not ok */
            break;
        case MACHINE_CURRUPTED:
            /* Send warning message: Configuration data in the machine is corrupted */
            break;
        case ALL_OK:
            /* Do Nothing */
        break;
    }
    CurrentAlertType = ALERT_NONE;
}

void AlertServicefunc(void)
{
    *AlertTable[CurrentAlertType];
}
