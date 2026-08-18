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

        if (new == NULL){
            printf("Erro ao alocar espaço de memória para BST");
            exit(1);
        }

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

Node_bst *remove_bst(Node_bst *t, int key){
    if (t == NULL){
        return t;
    }
    
    if (key == t->key){
        if (t->right == NULL && t->left == NULL){
            free(t);
            return NULL;
        }

        if (t->right != NULL && t->left == NULL){
            t->key = t->right->key;
            
            free(t->right);
            return NULL;
        }

        if (t->right == NULL && t->left != NULL){
            t->key = t->left->key;
            
            free(t->left);
            return NULL;        
        }

        if (t->right != NULL && t->left != NULL){
            Node_bst *current = t->right, *parent = t;

            while (current->left != NULL){
                parent = current;
                current = current->left;
            }

            t->key = current->key;
            t->right = remove_bst(t->right, current->key);

            return t;
        }
    }


    if (key > t->key){
        t->right = remove_bst(t->right, key);
    } else {
        t->left = remove_bst(t->left, key);
    }

    return t;
}

Node_bst *search(Node_bst *t, int key){
    // Se não encontrar, então retorna NULL
    if (t == NULL){
        return NULL;
    }
    Node_bst *aux = t;
    if (t->key == key){
        return t;
    }

    if (key > t->key){
        aux = search(t->right, key);
    } else {
        aux = search(t->left, key);
    }

    return aux;
}

void free_bst(Node_bst *t){
    if (t == NULL){
        return;
    }

    free_bst(t->left);
    free_bst(t->right);

    free(t);
}

void print_bst_sort(Node_bst *t){
    if (t == NULL){
        return;
    }

    print_bst_sort(t->left);
    printf("%d ", t->key);
    print_bst_sort(t->right);
}