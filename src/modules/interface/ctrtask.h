//
// This program create the custom task to execute
//

#ifndef CRAZYFLIE_FIRMWARE_CTRTASK_H
#define CRAZYFLIE_FIRMWARE_CTRTASK_H

#include <stdint.h>

/* FreeRtos includes */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

// Debugging library
#include "debug.h"

// System waiting
#include "system.h"

// Custom macros
#define CTR_TASK_NAME           "CTR-TASK"
#define CTR_TASK_PRI            0
#define PERIOD_SLEEP_TIME_IN_MS 1000

// Function definitions
void customTaskCreator(void);

#endif //CRAZYFLIE_FIRMWARE_CTRTASK_H
