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
            Node <T>** temp = &root;
            if (find (data))
                return false;
            else{
                auto newSon = new Node <T> (data);
                if(!root)
                    root = newSon;
                else{
                    while(*temp){
                        if (data < (*temp)->data)
                            temp = &((*temp)->left);
                        else
                            temp = &((*temp)->right);
                    }
                    *temp = newSon;
                }

                nodes++;
                return true;
            }
        }

        bool remove(T data) {
            if (find(data))
                return false;
            else{


            nodes--;
            }
        }

        unsigned int size() {
            return nodes;
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
