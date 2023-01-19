#pragma once 
#include "queue.h"

class queueTestCases {
    public:
        queueTestCases();
        ~queueTestCases();
        static void testSize();
        static void testEmpty();
        static void testFull();
        static void testDeQueue();
        static void testDeQueueEmpty();
        static void testEnqueue();
        static void testEnqueueFull();
        static void testPeek();
        static void testPeekEmpty();
};