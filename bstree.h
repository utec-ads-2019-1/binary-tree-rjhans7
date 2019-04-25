#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;

    public:
        BSTree() : root(nullptr) {};

        bool find(T data) {
            auto temp = root;
            while (temp) {
                if (data == temp->data)
                    return true;
                else if (data > temp->data)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            return false;
        }

        bool insert(T data) {
            auto temp = root;
            if (find (data)){

            }else{

            }
        }

        bool remove(T data) {
            // TODO
        }

        unsigned int size() {
            // TODO
        }

//Solo cout

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};

#endif
