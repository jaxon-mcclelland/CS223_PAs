#pragma once
#include "Node.h"
#include <queue>

template <class T>
class AVL_Tree {
    
    public:
        AVL_Tree();
        ~AVL_Tree();
        void insert(T data);
        void remove(T data);
        void printTree(bool printHeight = false) const;
        bool validate() const;
        int height() const;
    private:
        AVL_Node<T>* root;
        // allowed imbalance of the tree
        static const int ALLOWED_IMBALANCE = 1;

        static void insertNode(T data, AVL_Node<T>* &pRoot);
        static void deleteNode(T data, AVL_Node<T>* &pRoot);
        static void deleteSubTree(AVL_Tree<T>* pRoot);
        static void rebalanceTree(AVL_Node<T>* &pRoot);
        static int getHeight(AVL_Node<T>* pNode);
        
        // rotations
        static void rotateLeft(AVL_Node<T>* &pRoot);
        static void rotateRight(AVL_Node<T>* &pRoot);
        
        bool validateSubTree(const AVL_Node<T>* pRoot) const;
        

};


template <class T>
AVL_Tree<T>::AVL_Tree() {
    this->root == nullptr;
}

template <class T>
AVL_Tree<T>::~AVL_Tree() {
    deleteSubTree(root);
}

template <class T>
void AVL_Tree<T>::insert(T data) {
    if(this->root == nullptr) {
        this->root = new AVL_Node<T>(data);
        return;
    }
    insertNode(data, root);
}
template <class T>
void AVL_Tree<T>::remove(T data) {
    deleteNode(data, root);
}


template <class T>
void AVL_Tree<T>::insertNode(T data, AVL_Node<T>* &pRoot) {    
    // no duplicate data allowed in the tree
    if(pRoot->data == data) {
        return;
    }

    if(data < pRoot->data) {
        if(pRoot->pLeft == nullptr) {
            pRoot->pLeft = new AVL_Node<T>(data, pRoot->height + 1);
            return;
        }
        insertNode(data, pRoot->pLeft);
    } else {
        if(pRoot->pRight == nullptr) {
            pRoot->pRight = new AVL_Node<T>(data, pRoot->height + 1);
            return;
        }
        insertNode(data, pRoot->pRight);
    }
    rebalanceTree(pRoot);
}

template <class T>
void deleteNode(T data, AVL_Node<T>* &pRoot) {
    if(pRoot == nullptr) {
        // data does not exist in the tree
        return;
    }
    if(pRoot->data == data) {
        AVL_Node<T>* node_to_delete = pRoot;
        pRoot = pRoot->pLeft == nullptr ? pRoot->pRight : pRoot->pLeft;
        delete pRoot;
    } 
    else if(data < pRoot->data) {
        deleteNode(data, pRoot->pLeft);
    } 
    else if (data > pRoot->datas) {
        deleteNode(data, pRoot->pRight);
    }
}

// deletes an entire subtree, does not rebalance since this is only used to delete the whole tree
template <class T>
void deleteSubTree(AVL_Node<T>* pRoot) {
    if(pRoot == nullptr) {
        return;
    }
    deleteSubTree(pRoot->pLeft);
    deleteSubTree(pRoot->pRight);
    delete pRoot;

}

// validates an AVL subtree from pRoot
template <class T>
void AVL_Tree<T>::rebalanceTree(AVL_Node<T>* &pRoot) {
    if(pRoot == nullptr) {
        return;
    }
    if(getHeight(pRoot->pLeft) - getHeight(pRoot->pRight) > ALLOWED_IMBALANCE) {
        if(getHeight(pRoot->pLeft->pLeft) >= getHeight(pRoot->pLeft->pRight)) {
            // case 1
            rotateLeft(pRoot);
        }
        else {
            // case 2
            rotateRight(pRoot->pLeft);
            rotateLeft(pRoot);
        }
    }
    // I'm not sure these cases are setup correcy
    else if(getHeight(pRoot->pRight) - getHeight(pRoot->pLeft) > ALLOWED_IMBALANCE) {
        if(getHeight(pRoot->pRight->pRight) >= getHeight(pRoot->pRight->pLeft)) {
            // case 4
            rotateLeft(pRoot->pRight);
            rotateRight(pRoot);
        }
        else {
            // case 3
            rotateRight(pRoot);
        }
    }
    pRoot->height = std::max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight)) + 1;
    
}

template <class T>
void AVL_Tree<T>::rotateLeft(AVL_Node<T>* &pRoot) {
    if(pRoot->pLeft == nullptr) {
        return;
    }
    AVL_Node<T>* leftChild = pRoot->pLeft;
    pRoot->pLeft = leftChild->pRight;
    leftChild->pRight = pRoot;
    pRoot->height = std::max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight)) + 1;
    leftChild->height = std::max(getHeight(leftChild->pLeft), pRoot->height) + 1;
    pRoot = leftChild;
}

template <class T>
void AVL_Tree<T>::rotateRight(AVL_Node<T>* &pRoot) {
    if(pRoot->pRight == nullptr) {
        return;
    }
    AVL_Node<T>* rightChild = pRoot->pRight;
    pRoot->pRight = rightChild->pLeft;
    rightChild->pLeft = pRoot;
    pRoot->height = std::max(getHeight(pRoot->pRight), getHeight(pRoot->pLeft)) + 1;
    rightChild->height = std::max(getHeight(rightChild->pRight), pRoot->height) + 1;
    pRoot = rightChild;
}

template <class T>
int AVL_Tree<T>::getHeight(AVL_Node<T>* pNode) {
    return pNode == nullptr ? -1 : pNode->height;
}

// prints the tree as a level order traversal
template <class T>
void AVL_Tree<T>::printTree(bool printHeight) const {
    if(this->root == nullptr) {
        return;
    }
    std::queue<AVL_Node<T>*> treeQ;
    treeQ.push(this->root);
    while(!treeQ.empty()) {
        int sizeQ = treeQ.size();
        for(int i = 0; i < sizeQ; ++i) {
            AVL_Node<T>* pNode = treeQ.front();
            treeQ.pop();
            printHeight == false ? std::cout << *pNode : std::cout << pNode->height << " ";
            if(pNode->pLeft != nullptr) {
                treeQ.push(pNode->pLeft);
            }
            if(pNode->pRight != nullptr) {
                treeQ.push(pNode->pRight);
            }
        }
        std::cout << "\n";
    }
}

template <class T>
bool AVL_Tree<T>::validate() const {
    return validateSubTree(root);
}

template <class T>
bool AVL_Tree<T>::validateSubTree(const AVL_Node<T>* pRoot) const {
    if(pRoot == nullptr)
        return true;
    if(getHeight(pRoot->pLeft) - getHeight(pRoot->pRight) > ALLOWED_IMBALANCE || !validateSubTree(pRoot->pLeft) || !validateSubTree(pRoot->pRight))
        return false;
    
    return true;
}

template <class T>
int AVL_Tree<T>::height() const {
    return root != nullptr ? std::max(getHeight(root->pLeft), getHeight(root->pRight)) : 0;
}