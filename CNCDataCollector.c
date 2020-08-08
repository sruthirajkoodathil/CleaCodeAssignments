#include <CNCDataCollector.h>

StartUpError_t CNCStartUpStatus = ALL_OK;
float CNCTemperature = 0.00;
float OperatingTime = 0.00;
float PartDimVariation = 0.00;
bool PartDimVarAvailable = false;

void getCNCTemperature(float CNCTemp);
void getCNCPartDimVariation(float Var);
float getCNCDuration(float duration);

/* The data shall monitor and pass to the program with
 * callback function: CNCStartupCheckReport
 */
void CNCStartupCheckReport(StartUpError_t CNCStatus)
{
    CNCStartUpStatus = CNCStatus;
}

/* The temperature of machine shall monitor and pass to the program with
 * callback function: getCNCTemperature
 */
void getCNCTemperature(float CNCTemp)
{
    CNCTemperature = CNCTemp;
}

/* The Part dimension variation of tool produced shall pass to the program with
 * callback function: getCNCPartDimVariation
 */
void getCNCPartDimVariation(float Var)
{
    PartDimVariation = Var;
    PartDimVarAvailable = true;
}

/* The operating duration of CNC shall pass to the program with
 * callback function: getCNCDuration
 */
float getCNCDuration(float duration)
{
    OperatingTime = duration;
}
