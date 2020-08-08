#include "stdint.h"
#include "stddef.h"
#include "stdbool.h"

#define MAXData 3
enum{
    Temperatue = 0,
    PartDimention,
    CNCDuration
}CNCParams;

struct CNCData_t{
float DataLimit;
void (*DataCheck)(void);
};

bool TempExceeded;
bool DurationExceeded;
bool PartDimWrong;

bool StartUpCheck(void);
void CNCDurationCheck(void);
void ToolDimCheck(void);
void CNCTempCheck(void);
