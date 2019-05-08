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

        void makeBegin(){
            while(current->left){
                firstStack->push(current);
                current = current->left;
            }
            begin = end = true;
        }
        void makeEnd(){
            while(current->right){
                secondStack->push(current);
                current = current->right;
            }
            secondStack->push(current);
            end = true;
        }
        explicit Iterator(Node<T> *node) {
            current = node;
            firstStack = new stack<Node<T>*>;
            secondStack = new stack<Node<T>*>;
            begin = false;
        }

        Iterator<T>& operator=(Iterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current != other.current;
        }

        Iterator<T>& operator++() {
            if(current) {
                if((!current->left && !current->right) && !firstStack->empty()) {
                    current = firstStack->top();
                    firstStack->pop();
                }else if (!current->right && !firstStack->empty()){
                    current = firstStack->top();
                    firstStack->pop();
                }else {
                    if (current->right && !firstStack->empty()) {
                        current = current->right;
                        while (current->left) {
                            firstStack->push(current);
                            current = current->left;
                        }
                    } else{
                        current= nullptr;
                    }
                }
                begin = false;
            }
            return *this;
        }

        Iterator<T>& operator--() {
            if(current){
                if(begin)
                    throw out_of_range("Not elements");
                else{
                    if((!current->left && !current->right) && !secondStack->empty()) {
                        current = secondStack->top();
                        secondStack->pop();
                    }else if (!current->left && !secondStack->empty()){
                        current = secondStack->top();
                        secondStack->pop();
                    }else {
                        if (current->left) {
                            current = current->left;
                            while (current->right) {
                                secondStack->push(current);
                                current = current->right;
                            }
                        }
                    }
                    end = false;

                }

            }
            return *this;
        }

        T operator*() {
            return current->data;
        }
};

#endif
