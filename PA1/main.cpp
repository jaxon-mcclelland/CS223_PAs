#include "src/MatchingGame.hpp"

// Need ability to get a random command which hasn't been used before and return command description
// Then need to get two descriptions which do not match the command above
// testing:
// test set with duplicate values
// test player and command insert and remove
// make sure files are read and written correctly
// play game with max # of questions


/*
ADVANTAGES/DISADVANTAGES LINKED LIST

Advantages 
    - If inserting at head, O(1) insertion time
    - No limit on number of nodes, thus easy and quick insertions
Disadvantages
    - Random access is common for this implementation (constantly finding random items in the list), and linked lists are very slow in that regard. An array would be better in this regard

ADVANTAGES/DISADVANTAGES OF ARRAY

Advantages
    - Easy to access array at a certain index, good for random access
Disadvantages
    - Fixed size but the number of players is not nessecarily known at runtime, meaning that the array could need to expand constantly. This could be avoided by using a list
*/


// test add and remove command
// make sure players are written and loaded correctly
int main(void) {
    srand(time(NULL));
    MatchingGame game;
    return 0;
}