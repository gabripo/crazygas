//
// This program creates the custom task to execute
//

#include "ctrtask.h"

// Pre-defining functions
static void customTask(void *arg);

// Read variable
static float value = 0;

void customTaskCreator(void) {

	xTaskCreate(customTask, CTR_TASK_NAME,
	            configMINIMAL_STACK_SIZE, NULL,
	            CTR_TASK_PRI, NULL);

}

void customTask(void *arg) {
  // Waiting until the system task completely starts
	systemWaitStart();
	DEBUG_PRINT("Starting the CTR-TASK..");

  // Defining ticks number
  TickType_t xLastWakeTime;

  while (1) {
		  // Getting the ticks number in this moment (when the function starts)
		  xLastWakeTime = xTaskGetTickCount();

		  /* STARTING THE TASK */

		  // Defining the pin input, referring to the deck_constants.h file - A0
			pinMode(DECK_GPIO_TX2, INPUT);

		  // Updating the value: remember that the read occurs ONLY when the analogRead is called!
		  value = analogRead(DECK_GPIO_TX2);

		  // Printing on the console (double conversion is mandatory because is the only allowed variable type from DEBUG_PRINT)
		  DEBUG_PRINT("CTR-TASK read value: %f \n", (double) value);

		  // Adding to the client parameters
			LOG_GROUP_START(CTR)
			LOG_ADD(LOG_FLOAT, readValue, &value)
			LOG_GROUP_STOP(CTR)

		  /* ENDING THE TASK */

		  // Wait execution repeating until PERIOD_SLEEP_TIME_IN_MS is elapsed
		  vTaskDelayUntil(&xLastWakeTime, M2T(PERIOD_SLEEP_TIME_IN_MS));
  }

}

