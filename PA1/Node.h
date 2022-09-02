template <class T>
class Node {
    friend class LinkedList<T>;
    public:
        Node();
        Node(T data);
        ~Node();
    private:
        T data;
        Node<T>* pNext;
};
template <class T>
Node<T>::Node() {}
template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->pNext = nullptr;
}
template <class T>
Node<T>::~Node() {} 
