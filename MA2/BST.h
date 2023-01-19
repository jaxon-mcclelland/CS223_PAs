#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <stack>
//using namespace std;
// ^^ this is bad practice


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		std::cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + std::max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
		
	}
	// deletes the left and right subtrees of a root tree
	void deleteSubTree(Node<T>* root) {
		if(root->left != nullptr) {
			deleteSubTree(root->left);
			delete root->left;
		}
		if(root->right != nullptr) {
			deleteSubTree(root->right);
			delete root->right;
		}
	}

	bool containsHelper(const Node<T>* root, const T val) const {
		if(root == nullptr) {
			return false;
		}
		if(val < root->value) {
			return containsHelper(root->left, val);
		}
		else if(val > root->value) {
			return containsHelper(root->right, val);
		}
		else {
			return true;
		}
	}
	size_t getLengthMaxPath(const Node<T>* root) const {
		if(root == nullptr) {
			return 0;
		}
		return 1 + std::max(getLengthMaxPath(root->left), getLengthMaxPath(root->right));
	}
	/*
		Gets the max path as a vector of pointers
		
		Note: Since this is a private method, it is ok to return a vector of pointers.
		If this were a tree of large structs, it would also be more memory efficient to work
		with pointers rather than the node values themselves. I am also enforcing immutability
		for the pointers returned by this method but that is a choice that would depend on the needs
		for this method.
	*/
	std::vector<const Node<T>*> getMaxPath(const Node<T>* root) const {
		if(root == nullptr) {
			return {};
		}
		
		std::vector<const Node<T>*> leftPath = getMaxPath(root->left);
		std::vector<const Node<T>*> rightPath = getMaxPath(root->right);

		if(leftPath.size() < rightPath.size()) {
			rightPath.push_back(root);
			return rightPath;
		} else {
			leftPath.push_back(root);
			return leftPath;
		}
	}
  
	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 */
	~BST() {
		if(_root != nullptr) {
			deleteSubTree(_root);
			delete _root;
		}
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 */
	void printLevelOrder() const {
		if(this->_root == nullptr) {
			return;
		}
		std::queue<Node<T>*> treeQ;
		treeQ.push(_root);
		while(!treeQ.empty()) {
			int sizeQ = treeQ.size();
			for(int i = 0; i < sizeQ; ++i) {
				Node<T>* front = treeQ.front();
				treeQ.pop();
				std::cout << front->value << " ";
				if(front->left != nullptr) {
					treeQ.push(front->left);
				}
				if(front->right != nullptr) {
					treeQ.push(front->right);
				}
			}
			std::cout << "\n";
		}
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath() const {
		size_t maxPathLength = getLengthMaxPath(_root);
		std::vector<const Node<T>*> result = getMaxPath(_root);
		if(result.size() != maxPathLength) {
			std::cout << "MAX PATH RESULT INVALID! ACTAUL =	" << maxPathLength << " RESULT = " << result.size() << "\n";
			return;
		}
		for(int i = result.size() - 1; i > -1; --i) {
			std::cout << result[i]->value << " ";
		}
		std::cout << "\n";


		

	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 */
	bool contains(T value) const {
	    //std::cout << "TODO: Implement contains" << std::endl;
		//return std::numeric_limits<T>::min();
		return containsHelper(_root, value);
	}
};

#endif

