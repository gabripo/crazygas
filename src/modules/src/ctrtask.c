//
// This program create the custom task to execute
//

#include "ctrtask.h"

// Pre-defining functions
static void customTask(void *arg);

void customTaskCreator(void) {

	xTaskCreate(customTask, CTR_TASK_NAME,
	            configMINIMAL_STACK_SIZE, NULL,
	            CTR_TASK_PRI, NULL);

}

void customTask(void *arg) {
  // Waiting until the system task completely starts
	systemWaitStart();

  // Defining ticks number
  TickType_t xLastWakeTime;

  while (1) {
		  // Getting the ticks number in this moment (when the function starts)
		  xLastWakeTime = xTaskGetTickCount();

		  // STARTING THE TASK

		  // Starting to play a melody after 4 seconds
		  vTaskDelay(M2T(4000));
		  soundSetEffect((uint32_t) 11);

		  // ENDING THE TASK

		  // Wait execution repeating until PERIOD_SLEEP_TIME_IN_MS is elapsed
		  vTaskDelayUntil(&xLastWakeTime, M2T(PERIOD_SLEEP_TIME_IN_MS));
  }

}

