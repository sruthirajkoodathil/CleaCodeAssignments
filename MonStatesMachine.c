#include "CNCDataMonitor.h"
#include "MonStatesMachine.h"
#include "../hdr/SystemTimer.h"
#include "AlertService.h"


state_t InitializeTimer(void);
state_t CNCStartupCheck(void);
state_t CNCMonitoring(void);
state_t AlertFunctions(void);

typedef state_t (*StateFunctions)(void);

StateFunctions StateFunctionTable[NUMSTATE] = {
        InitializeTimer, CNCStartupCheck, CNCMonitoring, AlertFunctions
};

state_t InitializeTimer(void)
{
    state_t NextState;
    bool Status;
    Status = InitSysTimer();
    if (!Status){
     CurrentAlertType = ALERT_TIMER_ERROR;
     NextState = STATE_ALERT;
    }
    else{
        NextState = STATE_STARTUP_CHECK;
    }
    return NextState;
}

state_t CNCStartupCheck(void)
{
    state_t NextState;
    bool Status;
    Status = StartUpCheck();
    if (!Status){
     CurrentAlertType = ALERT_STARTUP_ERROR;
     NextState = STATE_ALERT;
    }
    else{
        NextState = STATE_MONITOR;
    }
    return NextState;
}

state_t CNCMonitoring(void)
{
     state_t NextState = STATE_MONITOR;
     if (TempExceeded)
     {
        /* Alert Environment */
        CurrentAlertType = ALERT_ENVNM_ERROR;
        NextState = STATE_ALERT;
        TempExceeded = false;
     }
     if(PartDimWrong || DurationExceeded)
     {
        /* Alert Machine */
         CurrentAlertType = ALERT_MACHINE_ERROR;
         NextState = STATE_ALERT;
         PartDimWrong = false;
         DurationExceeded = false;
     }
     return NextState;
}

state_t AlertFunctions(void)
{
    state_t NextState = STATE_ALERT;
    AlertServicefunc();
    return NextState;
}


state_t Runstate (state_t currentState)
{
    return (StateFunctionTable[currentState]());

}

void CNC_Monitoring(void)
{
    state_t currentState = STATE_INIT_TIMER;
    while(1){
    currentState = Runstate (currentState);
    }

}
