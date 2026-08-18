#include <stdio.h>
#include <stdlib.h>

int main(){
    int ret = system("cd c:\\Users\\vinic\\Desktop\\FACULDADE\\APA\\apa-ufpb\\tress\\bst && gcc -Wall main.c bst.c -o bst_exec && bst_exec");
    return ret >> 8;
}
