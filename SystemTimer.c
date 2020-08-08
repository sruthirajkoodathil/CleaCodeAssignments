#include "CNCDataMonitor.h"
#include "SystemTimer.h"
#include "CNCDataCollector.h"

#define TIMERMAX15  0x0F
#define TIMERMAX30  0x1E
#define TIMERMAX05  0x05

bool InitSysTimer(void)
{
    bool status = true;
    /* Hardware related checks need to be done */
    return status;
}

/* This function will run in every minute*/
void TimerProcess05(void)
{
    static int TimerCount05 = 0;
    if (TimerCount05 == TIMERMAX05)
    {
        /* Part Dimension Variation shall check every
         * 5Minute, if data available
         */
        TimerCount05 = 0;
        if (PartDimVarAvailable)
        {
            ToolDimCheck();
            PartDimVarAvailable = false;
        }
    }
    else
    {
        TimerCount05++;
    }
}

/* This function will run in every minute*/
void TimerProcess15(void)
{
  static int TimerCount15 = 0;
  if(TimerCount15 == TIMERMAX15)
  {
    TimerCount15 = 0;
    CNCTempCheck();
  }
  else{
    TimerCount15++;
  }
}

/* This function will run in every minute*/
void TimerProcess30(void)
{
  static int TimerCount30 = 0;
  if(TimerCount30 == TIMERMAX30){
    TimerCount30 = 0;
    CNCDurationCheck();
  }
  else{
    TimerCount30++;
  }
}

