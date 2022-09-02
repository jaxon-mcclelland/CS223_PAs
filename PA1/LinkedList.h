#include "Node.h"
template <class T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insert_item(T item);
        void delete_item(T item);
        T find_item(int idx);

    private:
        Node<T>* pHead;
        int size_list;
        T data;
        

};

template <class T>
LinkedList<T>::LinkedList() {
    this->pHead = nullptr;
    this->size_list = 0;
}
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* pNode = this->pHead;
    Node<T>* pTemp;
    while(pNode != nullptr) {
        pTemp = pNode->pNext;
        delete pNode;
        pNode = pTemp;
    }
}
template <class T>
void LinkedList<T>::insert_item(T item) {
    Node<T>* pNode = new Node<T>(item);
    pNode->pNext = this->pHead;
    this->pHead = pNode;
}
template <class T>
void LinkedList<T>::delete_item(T item) {
    if(this->size_list == 0 || (this->size_list == 1 && this->pHead->data != item)) {
        return;
    }
    Node<T>* pNode = this->pHead;
    Node<T>* pPrev = nullptr;
    while(pNode != nullptr && pNode->data != item) {
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
template <class T>
T LinkedList<T>::find_item(int idx) {
    if(idx >= this->size_list) {
        throw;
    }
    Node<T>* pNode = this->pHead;
    for(int i = 0; i <= idx; ++i) {
        pNode = pNode->pNext;
    }
    return pNode->data;
}