#include "BST.h"

int main()
{
    BST<int> *bst = new BST<int>();
    bst->add(11);
    bst->add(1);
    bst->add(6);
    bst->add(-1);
    bst->add(-10);
    bst->add(100);
    bst->print();
    std::cout<<std::endl;
    bst->printLevelOrder();
    std::cout << "100 in BST? true (1) or false (0): " << bst->contains(100) << std::endl;
    std::cout << "9 in BST? true (1) or false (0): " << bst->contains(9) << std::endl;
    std::cout<<"Nodes count: "<<bst->nodesCount();
    std::cout<<std::endl;
    std::cout<<"Height: "<<bst->height();
    std::cout<<std::endl;
    std::cout<<"Max path: ";
    bst->printMaxPath();
    std::cout<<std::endl;
    bst->deleteValue(11);
    std::cout<<"After 11 removed: ";
    bst->print();
    std::cout<<std::endl;
    bst->printLevelOrder();
    std::cout<<"Nodes count: "<<bst->nodesCount();
    std::cout<<std::endl;
    delete bst;
    return 0;
}