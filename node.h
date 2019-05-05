#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    private:
        T data;
        Node<T> *left;
        Node<T> *right;
    public:
        explicit Node(T value){
            left = right = nullptr;
            data = value;
        };

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif