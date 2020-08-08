#include "stdint.h"
#include "stdbool.h"


typedef enum{
    NO_DATA,
    MACHINE_NOT_OK,
    MACHINE_CURRUPTED,
    ALL_OK
}StartUpError_t;

extern StartUpError_t CNCStartUpStatus;

extern float CNCTemperature;
extern float OperatingTime;
extern float PartDimVariation;
extern bool PartDimVarAvailable;





