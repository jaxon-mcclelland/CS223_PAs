#include "Node.hpp"
#include <stdlib.h>
#pragma once

template <class T, class J>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insertAtFront(T command, J description);
        void getNode(int idx, T& command, J& description) const;
        void removeNode(T command);
        int findItem(T command);
        J getRandomDescription(int idx);
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
    this->size_list++;
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
    this->size_list--;
}
template <class T, class J>
void LinkedList<T,J>::getNode(int idx, T& command, J& description) const {
    if(idx > this->size_list) {
        return;
    }
    Node* pNode = this->pHead;
    for(int i = 0; i < idx; ++i) {
        pNode = pNode->pNext;
    }
    command = pNode->command;
    description = pNode->description;
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
        pNode = pNode->pNext;
    }
    return outfile;
}
template <class T, class J>
J LinkedList<T, J>::getRandomDescription(int idx) {
    int rand_idx;
    do {
        rand_idx = rand() % this->size_list;
    } while(idx == rand_idx);
    Node* pNode = this->pHead;
    for(int i = 0; i <= rand_idx; ++i) {
        pNode = pNode->pNext;
    }
    return pNode->description;
}