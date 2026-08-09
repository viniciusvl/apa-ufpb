#ifndef BST_H
#define BST_H

typedef enum Bool {
    TRUE,
    FALSE
} Bool;

typedef struct Node{
    struct Node *left;
    struct Node *right;
    int key;
} Node_bst;

Node_bst *create_bst();
Node_bst *insert(Node_bst *t, int key);
Node_bst *insert_it(Node_bst *t, int key);
Node_bst *search(Node_bst *t, int key);

void free_bst(Node_bst *t);
void print_bst(Node_bst *t);

#endif