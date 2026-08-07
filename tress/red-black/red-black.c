#ifndef RED_BLACK_H
#define RED_BLACK_H

typedef char Color_rb;

struct Node_rb{
    struct Node_rb *parent;
    struct Node_rb *left;
    struct Node_rb *right;

    Color_rb color;
    int key;  
};

#endif