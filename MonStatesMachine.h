#include "stdint.h"
#include "stdbool.h"
#include "AlertService.h"

#define NUMSTATE  4

typedef enum{
    STATE_INIT_TIMER,
    STATE_STARTUP_CHECK,
    STATE_MONITOR,
    STATE_ALERT
}state_t;





