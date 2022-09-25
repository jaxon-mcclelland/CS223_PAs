#include "testQueue.h"

queueTestCases::queueTestCases() {}
queueTestCases::~queueTestCases() {}
/*
***** Test ID: queue size check****
Unit: queue::size()
Description: Test to determine if queue size is returned correctly
Test Steps:
    1) Init Queue with size 10
    2) Check if queue size is 0\n";
Expected Result: queue returns 0
Actual Result: queue returns 1
Status: failed
*/
void queueTestCases::testSize() {
    std::cout << "***** Test ID: queue size check**** \n";
    std::cout << "Expected Result: queue returns 0\n";
    queue testQ(10);

    std::cout << "Actual Result: queue returns " << testQ.size() << "\n";
    if(testQ.size() != 0) {
        std::cout << "Status: failed\n\n";
    } else {
        std::cout << "Status: Passed\n\n";
    }
}
/*
**** Test ID: queue empty check ****
Unit: queue::isEmpty()
Description: Test to determine if queue returns true when it is empty
Test Steps:
    1) Init Queue with size 5
    2) Check that isEmpty retuns true
Expected Result: queue returns 1
Actual Result: queue returns 0
Status: failed
*/
void queueTestCases::testEmpty() {
    std::cout << "**** Test ID: queue empty check ****\n";

    queue testQ(5);
    std::cout << "Actual Result: queue returns " << testQ.isEmpty() << "\n";
    if(!testQ.isEmpty()) {
        std::cout << "Status: failed\n\n";
    } else {
        std::cout << "Status: Passed\n\n";
    }
}
/*
**** Test ID: queue full check *****
Unit: queue::isFull()
Description: Test to determine if queue returns true when it is full
Test Steps:
    1) Init Queue with size 0
    2) Check that isFull retuns true
Expected Result: queue returns 1
Actual Result: queue returns 0
Status: failed
*/
void queueTestCases::testFull() {
    std::cout << "**** Test ID: queue full check *****\n";
    queue testQ(0);
    std::cout << "Actual Result: queue returns " << testQ.isFull() << "\n";
    if(!testQ.isFull()) {
        std::cout << "Status: failed\n\n";
    } else {
        std::cout << "Status: Passed\n\n";
    }
}
/*
**** Test ID: basic dequeue check *****
Unit: queue::dequeue()
Description: Test to determine if queue dequeues an item correctly
Test Steps:
    1) Init Queue with size 3
    2) Enqueue 3 items into the queue
    3) Dequeue once
    4) Check that front of queue equals the second item
Test Data: size = 3, 1,2,3 is inserted into the queue
Expected Result: front of queue is 2
*/
void queueTestCases::testDeQueue() {
    std::cout << "**** Test ID: basic dequeue check *****\n";
    queue testQ(3);
    testQ.enqueue(1);
    testQ.enqueue(2);
    testQ.enqueue(3);
    testQ.dequeue();
    std::cout << "Actual result: queue returns " << testQ.peek() << "\n";
    if(testQ.peek() != 2) {
        std::cout << "Status: failed\n\n";
    } else {
        std::cout << "Status: passed\n\n";
    }
}
/*
**** Test ID: empty dequeue check *****
Unit: queue::dequeue()
Description: Test to determine if queue dequeues an empty queue correctly
Test Steps:
    1) Init Queue with size 0
    2) Dequeue once
    3) Ensure that no exceptions were generated
Expected Result: no exception is raised
*/
void queueTestCases::testDeQueueEmpty() {
    std::cout << "**** Test ID: empty dequeue check *****\n";
    queue testQ(1);
    try {
        testQ.dequeue();
        std::cout << "Status: passed\n\n";
    } catch(...) {
        std::cout << "Status: failed\n\n";
    }
}
/*
**** Test ID: basic enqueue check *****
Unit: queue::enqueue()
Description: Test to determine if queue enqueues an item correctly
Test Steps:
    1) Init Queue with size 2
    2) enqueue 2 items
    3) check that the front of the queue equals the first item
Test Data: 1,2 is enqueued
Expected Result: queue returns 1

*/
void queueTestCases::testEnqueue() {
    std::cout << "**** Test ID: basic enqueue check *****\n";
    queue testQ(5);
    std::cout << "None";
    testQ.enqueue(1);
    testQ.enqueue(2);
    std::cout << "Actual Result: queue returns " << testQ.peek() << "\n";
    if(testQ.peek() != 1) {
        std::cout << "Status: failed\n\n";
    } else {
        std::cout << "Status: passed\n\n";
    }
}
/*
**** Test ID: full enqueue check *****
Unit: queue::enqueue()
Description: Test to determine if queue enqueues a full queue correctly
Test Steps:
    1) Init Queue with size 1
    2) enqueue one item
    3) enqueue another item
    4) Ensure that no exceptions were generated after enqueueing the second item
Expected Result: no exception is raised

*/
void queueTestCases::testEnqueueFull() {
    std::cout << "**** Test ID: full enqueue check *****\n";
    queue testQ(1);
    testQ.enqueue(1);
    try {
        testQ.enqueue(2);
        std::cout << "Status: passed\n\n";
    } catch(...) {
        std::cout << "Status: failed\n\n";
    }
}
/*
**** Test ID: queue peek check *****
Unit: queue::peek()
Description: Test to determine if queue peeks a non-empty queue correctly
Test Steps:
    1) Init Queue with size 1
    2) enqueue one item
    3) Check that the front of the queue equals the first item
Test Data: 1 is enqueued
Expected Result: front of queue 

*/
void queueTestCases::testPeek() {
    std::cout << "**** Test ID: queue peek check *****\n";
    queue testQ(1);
    testQ.enqueue(1);
    std::cout << "Actual Result: queue returns " << testQ.peek() << "\n";
    if(testQ.peek() == 1) {
        std::cout << "Status: Test Passed\n\n";
    } else {
        std::cout << "Status: Test Failed\n\n";
    }
    
}
/*
**** Test ID: empty queue peek *****
Unit: queue::peek()
Description: Test to determine if queue peeks an empty queue correctly
Test Steps:
    1) Init Queue with size 0
    2) peek once
    3) check that the peek result is equal to INT_MIN
*/

void queueTestCases::testPeekEmpty() {
    std::cout << "**** Test ID: empty queue peek *****\n";
    std::cout << "Expected Result: peek is equal to " << std::numeric_limits<int>::min() << "\n";
    queue testQ(1);
    std::cout << "Actual Result: " << testQ.peek() << "\n";
    if(testQ.peek() == std::numeric_limits<int>::min()) {
        std::cout << "Status: Passed\n\n";
    } else {
        std::cout << "Status: Failed\n\n";
    }
}