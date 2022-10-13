// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn


#include "testQueue.h"

// main functions


/*
BAD DESIGN CHOICES:

    1) including the entire standard namespace is generally a bad idea
    2) the queue destructor should call delete[] instead of delete because it is destroying an array, not just a pointer
    3) There are several places where the program seems to intend for an exception to be raised, such as overflowing the queue - but this doesnt happen
        instead a message is just printed out. An exception should be raised instead which the programming using this data structure can handle
    4) The queue class has no private members - this is a poor design choice since there isn't really any point of abstracting the implementation of the queue anymore
    5) Program is calling getters internally to access member variables such as the size of the queue - this is uneeded since non-static memebr functions can access member variables
        directly without the need for getters - even if they were private.
    6) Not entirely a "bad" design since there are tradeoffs involved - but it could be argued that a linked list would be a better choice since with a linked list
        insertions at the back (if you keep track of the back pointer) are O(1). The disadvantage of a linked list - that being slow random access - does not apply since with a queue you only have access to the first and last elements 
        (the front and back).
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

