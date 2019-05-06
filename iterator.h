#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        stack<Node<T>*> *firstStack;
        stack<Node<T>*> *secondStack;

    public:
        Iterator() {
            current = nullptr;
            firstStack = new stack<Node<T>*>;
            secondStack = new stack<Node<T>*>;
        }

        explicit Iterator(Node<T> *node) {
            current = node;
            firstStack = new stack<Node<T>*>;
            secondStack = new stack<Node<T>*>;
            while(current->left){
                firstStack->push(current);
                current = current->left;
            }
        }

        Iterator<T>& operator=(Iterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current != other.current;
        }

        Iterator<T> operator++() {
            if(current) {
                if((!current->left && !current->right) && !firstStack->empty()) {
                    current = firstStack->top();
                    firstStack->pop();
                }else if (!current->right && !firstStack->empty()){
                    current = firstStack->top();
                    firstStack->pop();
                }else {
                    if (current->right) {
                        current = current->right;
                        while (current->left) {
                            firstStack->push(current);
                            current = current->left;
                        }

                    }
                }
            }
            return *this;
        }

        Iterator<T> operator--() {
            // TODO
        }

        T operator*() {
            return current->data;
        }
};

#endif
