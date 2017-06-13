#include "ThreadRunOnce.h"

ThreadRunOnce::ThreadRunOnce(void (*callback)(void), unsigned long _interval) : Thread(callback, _interval)
{
	enabled = false;
};

void ThreadRunOnce::runned(unsigned long time){
	Thread::runned(time);

	// If runned() in runOnce mode, cleanup now
	if (runOnce) {
		runOnce = false;
		enabled = false;
	}
}

void ThreadRunOnce::setRunOnce(unsigned long timeout){
	// Set flags
	runOnce = true;
	enabled = true;

	// Cache the next run
	_cached_next_run = millis() + timeout;
}

void ThreadRunOnce::run(){
	if(_onRun != NULL)
		_onRun();

	// Update last_run and _cached_next_run
	runned();
}
