#ifndef BST_H
#define BST_H

typedef enum Bool {
    TRUE,
    FALSE
};

struct Node{
    struct Node *left;
    struct Node *right;
    int key;
};

struct Node *insert(struct Node *t, int key);

struct Node *search(int key);

Bool remove(int key);

void free_bst(struct Node *t);

#endif