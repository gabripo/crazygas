//
// This program create the custom task to execute
//

#include "ctrtask.h"

// Pre-defining functions
static void customTask(void *arg);
static void enableIO1(void);
static void disableIO1(void);

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

		  // Enabling the LED
			enableIO1();

		  // Waiting for the half of the period
		  vTaskDelay(M2T(PERIOD_SLEEP_TIME_IN_MS/2));

		  // Disabling the LED
		  disableIO1();

		  // ENDING THE TASK

		  // Wait execution repeating until PERIOD_SLEEP_TIME_IN_MS is elapsed
		  vTaskDelayUntil(&xLastWakeTime, M2T(PERIOD_SLEEP_TIME_IN_MS));
  }

}

static void enableIO1(void) {
		// Switching on the LED
		pinMode(DECK_GPIO_IO1, OUTPUT);
		digitalWrite(DECK_GPIO_IO1, 1);
}

static void disableIO1(void) {
		// Switching off the LED
		pinMode(DECK_GPIO_IO1, OUTPUT);
		digitalWrite(DECK_GPIO_IO1, 0);
}
