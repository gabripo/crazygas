//
// This program create the custom task to execute
//

#ifndef CRAZYFLIE_FIRMWARE_CTRTASK_H
#define CRAZYFLIE_FIRMWARE_CTRTASK_H

#include <stdint.h>

/* FreeRTOS includes */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

// Debugging library
#include "debug.h"

// System waiting
#include "system.h"

// Including deck API
#include "deck.h"

// Including the processor tools
#include "stm32fxxx.h"

// Including the log utility
#include "log.h"

// Custom macros
#define CTR_TASK_NAME           "CTR-TASK"
#define CTR_TASK_PRI            0
#define PERIOD_SLEEP_TIME_IN_MS 500

// Function definitions
void customTaskCreator(void);

#endif //CRAZYFLIE_FIRMWARE_CTRTASK_H
