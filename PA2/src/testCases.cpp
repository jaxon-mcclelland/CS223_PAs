#include "testCases.h"

avlTests::avlTests() {}
avlTests::~avlTests() {}

void avlTests::insertCase1() {
    AVL_Tree<int> test_tree;
    test_tree.insert(10);
    test_tree.insert(15);
    test_tree.insert(5);
    test_tree.insert(2);
    test_tree.insert(7);
    test_tree.insert(0);
    test_tree.insert(3);
    test_tree.insert(1);
    test_tree.insert(4);
    test_tree.insert(8);
    test_tree.insert(100);
    test_tree.insert(12);
    test_tree.insert(11);
    
    test_tree.printTree();
    std::cout << "\n\n";
    test_tree.printTree(true);
}