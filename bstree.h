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
            if (!find(data))
                return false;
            else{
                Node <T> ** temp = &root;
                while(*temp){
                    if (data == (*temp)->data)
                        break;
                    else if (data < (*temp)->data)
                        temp = &((*temp)->left);
                    else
                        temp = &((*temp)->right);
                }
                if(((*temp)->left == nullptr) && ((*temp)->right== nullptr)) {
                    *temp = nullptr;
                    nodes--;
                    return true;
                }else if (((*temp)->left == nullptr) != ((*temp)->right == nullptr)){
                    if((*temp)->right)
                        *temp = (*temp)->right;
                    else
                        *temp = (*temp)->left;
                    nodes--;
                    return true;
                }else{
                    auto temp2 = *temp;
                    temp = &((*temp)->right);
                    while ((*temp)->left)
                        temp = &((*temp)->left);
                    swap((*temp)->data, (temp2)->data);
                    if((*temp)->right){
                        *temp = (*temp)->right;
                        nodes--;
                        return true;
                    }
                    delete *temp;
                    *temp = nullptr;
                    nodes--;
                    return true;
                }
            }
        }

        unsigned int size() {
            return nodes;
        }

        void traversePreOrder() {
            if (root)
                PreOrder(root);
            else
                throw out_of_range("Empty Tree!");

        }
        void PreOrder(Node<T> * temp){
            if(temp) {
                cout << temp->data << " - ";
                PreOrder(temp->left);
                PreOrder(temp->right);
            }else
                return;
        }

        void traverseInOrder() {
            if (root)
                InOrder(root);
            else
                throw out_of_range("Empty Tree!");
        }
        void InOrder(Node<T> * temp) {
            if (temp){
                InOrder(temp->left);
                cout << temp->data << " - ";
                InOrder(temp->right);
            }else
                return;

        }

        void traversePostOrder() {
            if(root)
                PostOrder(root);
            else
                throw out_of_range("Empty Tree!");
        }
        void PostOrder(Node<T> * temp) {
            if(temp) {
                PostOrder(temp->left);
                PostOrder(temp->right);
                cout << temp->data << " - ";
            }else
                return;
        }

        Iterator<T> begin() {
            if(root) {
                auto it = new Iterator<T>(root);
                return *it;
            }else {
                auto it = new Iterator<T>();
                return *it;
            }
        }

        Iterator<T> end() { 
            auto it = new Iterator<T>();
            return *it;
        }

        ~BSTree() {
            if(root)
                root->killSelf();
            root = nullptr;
            nodes = 0;
        }
};

#endif
