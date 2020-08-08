#include <CNCDataCollector.h>
#include <CNCDataMonitor.h>


struct CNCData_t CNCData[MAXData] = {
   {35.0, *CNCTempCheck},
   {0.05, *ToolDimCheck},
   {360.00, *CNCDurationCheck}
};

bool StartUpCheck(void)
{
    bool status = true;
    /* Check all parameters to ensure the machine
     * is good to start. If any params goes wrong
     * return FALSE, else TRUE */
    if(CNCStartUpStatus != ALL_OK)
    {
        status = false;
    }
    return status;
}

void CNCTempCheck(void)
{
    if (CNCTemperature > CNCData[Temperatue].DataLimit)
    {
        TempExceeded = true;
    }
    else{
        TempExceeded = false;
    }
}

/* Register this function as a callback when a tool is
 * produced in CNC Machine, to check the correctness of
 * part dimention */
void ToolDimCheck(void)
{
    if(PartDimVariation > CNCData[PartDimention].DataLimit)
    {
        PartDimWrong = true;
    }
    else{
        PartDimWrong = false;
    }
}

void CNCDurationCheck(void)
{

    if (OperatingTime > CNCData[CNCDuration].DataLimit)
    {
        DurationExceeded = true;
    }
    else{
        DurationExceeded = false;
    }
}
