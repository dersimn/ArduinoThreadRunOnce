#include <Thread.h>
#include <ThreadRunOnce.h>
#include <ThreadController.h>

// ThreadController that will controll all threads
ThreadController controll = ThreadController();

//My Thread (as a pointer)
Thread* myThread = new Thread();
//His Thread (not pointer)
Thread hisThread = Thread();
//RunOnce Thread
ThreadRunOnce runOnceThread = ThreadRunOnce();

// callback for myThread
void niceCallback(){
	Serial.print("COOL! I'm running on: ");
	Serial.println(millis());
}

// callback for hisThread
void boringCallback(){
	Serial.println("BORING...");
}

void oneTimeCallback(){
  Serial.println("Just this time...");
}

void setup(){
	Serial.begin(9600);

	// Configure myThread
	myThread->onRun(niceCallback);
	myThread->setInterval(500);

	// Configure myThread
	hisThread.onRun(boringCallback);
	hisThread.setInterval(250);

  // Create Therad to run just one time
  runOnceThread.onRun(oneTimeCallback);

	// Adds both threads to the controller
	controll.add(myThread);
	controll.add(&hisThread); // & to pass the pointer to it
  controll.add(&runOnceThread);

  // Set Thread to execute once in 5s
  runOnceThread.setRunOnce(5000);
}

void loop(){
	// run ThreadController
	// this will check every thread inside ThreadController,
	// if it should run. If yes, he will run it;
	controll.run();

	// Rest of code
	float h = 3.1415;
	h/=2;
}
