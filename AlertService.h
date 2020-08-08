/*
 * AlertService.h
 *
 *  Created on: Aug 8, 2020
 *      Author: sot1cob
 */

#ifndef HDR_ALERTSERVICE_H_
#define HDR_ALERTSERVICE_H_

#define NUMALERTTYPES 5

extern int CurrentAlertType;
extern int StartUpCheckStatus;

typedef enum {
    ALERT_NONE,
    ALERT_MACHINE_ERROR,
    ALERT_ENVNM_ERROR,
    ALERT_TIMER_ERROR,
    ALERT_STARTUP_ERROR
}AlertType_t;

void AlertServicefunc(void);

#endif /* HDR_ALERTSERVICE_H_ */
