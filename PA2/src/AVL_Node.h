
#pragma once
#include <iostream>

template <class T>
class AVL_Node {
    template <class J>
    friend class AVL_Tree;
    public:
        AVL_Node(T data, int height = 0);
        ~AVL_Node();
        T getData() const;
    private:
        AVL_Node<T>* pLeft;
        AVL_Node<T>* pRight;
        T data;
        int height;
};

template <class T>
std::ostream& operator<<(std::ostream& lhs, AVL_Node<T>& rhs);

template <class T>
std::istream& operator>>(std::istream& lhs, AVL_Node<T>& rhs);


template <class T>
AVL_Node<T>::AVL_Node(T data, int height) {
    this->data = data;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->height = height;
}
template <class T>
AVL_Node<T>::~AVL_Node() {
    delete this->data;
}

template <class T>
T AVL_Node<T>::getData() const {
    return this->data;
}

template <class T>
std::ostream& operator<<(std::ostream& lhs, AVL_Node<T>& rhs) {
    lhs << rhs.getData() << " ";
    return lhs;
}
template <class T>
std::istream& operator>>(std::istream& lhs, AVL_Node<T>& rhs) {
    lhs >> rhs.getData();
    return lhs;
}