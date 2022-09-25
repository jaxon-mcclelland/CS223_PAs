// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn


#include "testQueue.h"

// main function
int main()
{
    // call your test functions here!
    
    queueTestCases cases;
    cases.testEmpty();
    cases.testFull();
    cases.testSize();
    cases.testEnqueue();
    cases.testEnqueueFull();
    cases.testDeQueue();
    cases.testDeQueueEmpty();
    cases.testPeek();
    cases.testPeekEmpty();

    return 0;
}

