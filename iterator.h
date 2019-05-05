#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        stack<Node<T>> firstStack;

    public:
        Iterator() {
            current = nullptr;
        }

        explicit Iterator(Node<T> *node) {
            current = node;
            firstStack = new stack<Node<T>>();
            while(node){
                firstStack.push(node);
                node = node->left;
            }
        }

        Iterator<T>& operator=(Iterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current != other.current;
        }
        void inOrderIterator(Node<T> *temp){
            if(temp){
                inOrderIterator(temp->left);

            }else
                return;
        }

        Iterator<T>& operator++() {

            return *this;
        }

        Iterator<T> operator--() {
            // TODO
        }

        T operator*() {
            // TODO
        }
};

#endif
