Extends [ArduinoThread](https://github.com/ivanseidel/ArduinoThread) library.

	#include <Thread.h>
	#include <ThreadRunOnce.h>
	#include <ThreadController.h>

Define and use:

	// Create Therad to run just one time
	runOnceThread.onRun(oneTimeCallback);

	// Adds both threads to the controller
	controll.add(&runOnceThread);

	// Set Thread to execute once in 5s
	runOnceThread.setRunOnce(5000);
