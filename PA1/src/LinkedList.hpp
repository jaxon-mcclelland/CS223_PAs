#include "Node.hpp"
#include <stdlib.h>

template <class T, class J>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insertAtFront(T command, J description);
        void removeNode(T command);
        int findItem(T command);
        J getRandomDescription();
        int getListSize() const;
        std::ostream& writeListToFile(std::ostream& outfile);
    
    private:
        Node* pHead;
        int size_list;
};

template <class T, class J>
LinkedList<T,J>::LinkedList() {
    this->pHead = nullptr;
    this->size_list = 0;
}
template <class T, class J>
LinkedList<T,J>::~LinkedList() {
    Node* pNode = this->pHead;
    Node* pTemp;
    while(pNode != nullptr) {
        pTemp = pNode->pNext;
        delete pNode;
        pNode = pTemp;
    }
}
template <class T, class J>
void LinkedList<T, J>::insertAtFront(T command, J description) {
    Node* pNode = new Node(command, description);
    pNode->pNext = this->pHead;
    this->pHead = pNode;
}
template <class T, class J>
void LinkedList<T,J>::removeNode(T command) {
    if(this->size_list == 0 || (this->size_list == 1 && this->pHead->command != command)) {
        return;
    }
    Node* pNode = this->pHead;
    Node* pPrev = nullptr;
    while(pNode != nullptr && pNode->command != command) {
        pPrev = pNode;
        pNode = pNode->pNext;
    }
    if(pNode != nullptr) {
        if(pPrev != nullptr ) {
            pPrev->pNext = pNode->pNext;
        }
        delete pNode;
    }

}
template <class T, class J>
int LinkedList<T,J>::findItem(T command) {
    if(this->size_list < 1) {
        return -1;
    }
    Node* pNode = this->pHead;
    int counter = 0;
    while(pNode != nullptr && pNode->command != command) {
        ++counter;
        pNode = pNode->pNext;
    } 
    pNode == nullptr ? counter = -1 : counter;
    return counter;
}

template <class T, class J>
int LinkedList<T,J>::getListSize() const {
    return this->size_list;
}
template <class T, class J>
std::ostream& LinkedList<T,J>::writeListToFile(std::ostream& outfile) {
    Node* pNode = this->pHead;
    for(int i = 0; i < this->size_list; ++i) {
        outfile << pNode->command << "," << pNode->description << "\n";
    }
    return outfile;
}
template <class T, class J>
J LinkedList<T, J>::getRandomDescription() {
    int rand_idx = rand() % this->size_list;
    Node* pNode = this->pHead;
    for(int i = 0; i <= rand_idx; ++i) {
        pNode = pNode->pNext;
    }
    return pNode->description;
}