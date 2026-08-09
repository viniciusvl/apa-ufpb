#include <stdio.h>
#include "bst.h"
#include <stdlib.h>

Node_bst *create_bst(){
    return NULL;
}

//inserção de forma recursiva
Node_bst *insert(Node_bst *t, int key){
    if (t == NULL){
        Node_bst *new = (Node_bst *)malloc(sizeof(Node_bst));
        new->key = key;
        new->left = new->right = NULL;

        return new;
    }

    if (key >= t->key){
        t->right = insert(t->right, key);
    } else {
        t->left = insert(t->left, key);
    }

    return t;
}

//inserção de forma iterativa
Node_bst *insert_it(Node_bst *t, int key){
    Node_bst *new = (Node_bst *)malloc(sizeof(Node_bst));
    new->key = key;
    new->left = new->right = NULL;

    if (t == NULL){
        return new;
    }

    Node_bst *current = t,
             *parent = t;
    while (current != NULL){
        parent = current;
        if (key >= current->key){
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (key >= parent->key){
        parent->right = new;
    } else {
        parent->left = new;
    }

    return t;
}