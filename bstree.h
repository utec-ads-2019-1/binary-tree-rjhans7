#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;
        int nodes;

    public:
        BSTree() : root(nullptr), nodes(0) {};

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
            //Equilibra los niveles del arbol, luego el heapify ordena los valores
            auto temp = root;
            if (find (data))
                return false;
            else{
                auto newSon = new Node <T> (data);
                while (temp){
                    if (temp->left == nullptr){
                        temp->left = newSon;
                        nodes++;
                        heapify();
                        return true;
                    }else if (temp->right == nullptr){
                        temp->right = newSon;
                        nodes++;
                        heapify();
                        return true;
                    }else{
                        if(temp->left->left== nullptr || temp->left->right== nullptr)
                            temp = temp->left;
                        temp = temp->right;
                    }

                }
                root = newSon;
                nodes++;
                return true;
            }
        }
        void heapify(){

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
