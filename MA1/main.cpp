// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn


#include "testQueue.h"

// main function


/*
BAD DESIGN CHOICES:

    1) including the entire standard namespace is generally a bad idea
    2) the queue destructor should call delete[] instead of delete because it is destroying an array, not just a pointer
    3) There are several places where the program seems to intend for an exception to be raised, such as overflowing the queue - but this doesnt happen
        instead a message is just printed out. An exception should be raised instead which the programming using this data structure can handle
*/

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

