#ifndef ThreadRunOnce_h
#define ThreadRunOnce_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include <inttypes.h>
#include "Thread.h"


class ThreadRunOnce : public Thread {
protected:
	bool runOnce;	

public:
	ThreadRunOnce(void (*callback)(void) = NULL, unsigned long _interval = 0);
	
	/*
		IMPORTANT! Run after all calls to run()
		Updates last_run and cache next run.
		NOTE: This MUST be called if extending
		this class and implementing run() method
	*/
	void runned(unsigned long time);
	// Default is to mark it runned "now"
	void runned() { runned(millis()); }

	// Set timout for next (and only) run
	virtual void setRunOnce(unsigned long timeout);

	// Runs Thread
	virtual void run();
};

#endif
