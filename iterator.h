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
        bool begin, end;

    public:
        Iterator() {
            current = nullptr;
            firstStack = new stack<Node<T>*>;
            secondStack = new stack<Node<T>*>;
            begin = end = false;
        }

        explicit Iterator(Node<T> *node) {
            current = node;
            firstStack = new stack<Node<T>*>;
            secondStack = new stack<Node<T>*>;
            begin = end = false;
        }

        Iterator<T>& operator=(Iterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current != other.current;
        }

        void makeBegin(){
            while(current->left){
                firstStack->push(current);
                current = current->left;
            }
            begin = true;
        }
        void makeEnd(){
            while(current->right){
                secondStack->push(current);
                current = current->right;
            }
                secondStack->push(current);
                current = nullptr;
                end = true;
        }

        Iterator<T> operator++() {
            if(current) {
                if((!current->left && !current->right) && firstStack->empty() && !end) {
                    secondStack->push(current);
                    current = nullptr;
                    end = true;
                }else if((!current->left && !current->right) && !firstStack->empty()) {
                    secondStack->push(current);
                    current = firstStack->top();
                    firstStack->pop();
                }else if (!current->right && !firstStack->empty()){
                    secondStack->push(current);
                    current = firstStack->top();
                    firstStack->pop();
                }else {
                    if (current->right) {
                        secondStack->push(current);
                        current = current->right;
                        while (current->left) {
                            firstStack->push(current);
                            current = current->left;
                        }
                    }
                }
                begin = false;
            }
            return *this;
        }

        Iterator<T> operator--() {
            // El -- tiene algún problem
                if (end) {
                    current = secondStack->top();
                    secondStack->pop();
                } else if ((!current->left && !current->right) && secondStack->empty()) {
                    firstStack->push(current);
                    current = nullptr;
                    begin = true;
                } else if ((!current->left && !current->right) && !secondStack->empty()) {
                    current = secondStack->top();
                    secondStack->pop();
                } else if (!current->left && !secondStack->empty()) {
                    current = secondStack->top();
                    secondStack->pop();
                } else if (current->left) {
                    firstStack->push(current);
                    current = current->left;
                    secondStack->pop();
                    while (current->right) {
                        secondStack->push(current);
                        current = current->right;
                    }
                }
                end = false;
                return *this;

        }

        T operator*() {
            // Falta controlar el caso vacío
            return current->data;
        }
};

#endif
