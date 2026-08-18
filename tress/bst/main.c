#include <stdio.h>
#include "bst.h"
#include <stdlib.h>

Node_bst *test_insertion_bst(Node_bst *t){
    t = insert(t, 35);
    printf("Inseriu 35 na raiz OK\n");
    t = insert(t, 30);
    printf("Inseriu 30 a esquerda OK\n");
    t = insert(t, 40);
    printf("Inseriu 40 a direita OK\n");
    t = insert(t, 40);
    printf("Inseriu 40 na direita OK\n");
    t = insert(t, 37);
    t = insert(t, 34);
    t = insert(t, 25);

    return t;
}

void test_search_bst(Node_bst *t){
    struct testes {
        int key;
        char is_in_bst;
    };

    struct testes k1 = {25, 1};
    struct testes k2 = {30, 1};
    struct testes k3 = {37, 1};
    struct testes k4 = {40, 1};
    struct testes k5 = {108, 0};
    struct testes k6 = {35, 1};

    struct testes cases[] = {k1, k2, k3, k4, k5, k6};

    for (int i = 0; i < 6; i++){
        Node_bst *k = search(t, cases[i].key);

        if (cases[i].is_in_bst == 1){
            if (k == NULL){
                printf("Busca %d ERRO: ESTA NO ARRAY MAS NAO ENCONTROU\n", cases[i].key);
            } else if (k->key == cases[i].key){
                printf("Busca %d OK\n", cases[i].key);
            } else {
                printf("Busca %d ERRO: retornou resultado na busca, mas a chave difere\n", cases[i].key);
            }
        } else {
            if (k == NULL){
                printf("Busca %d OK (nao esta na arvore, como esperado)\n", cases[i].key);
            } else {
                printf("Busca %d ERRO: NAO deveria estar na arvore, mas encontrou\n", cases[i].key);
            }
        }
    }
}

void test_remove_bst(Node_bst **t_ptr){
    printf("\n=== TESTES DE REMOCAO ===\n");

    printf("\nArvore antes das remocoes: ");
    print_bst_sort(*t_ptr);
    printf("\n");

    printf("\nRemovendo folha (25)...\n");
    *t_ptr = remove_bst(*t_ptr, 25);
    printf("Arvore apos remover 25: ");
    print_bst_sort(*t_ptr);
    printf("\n");
    if (search(*t_ptr, 25) == NULL){
        printf("OK: 25 foi removido\n");
    } else {
        printf("ERRO: 25 ainda existe\n");
    }

    printf("\nRemovendo no com filho direito (40)...\n");
    *t_ptr = remove_bst(*t_ptr, 40);
    printf("Arvore apos remover 40: ");
    print_bst_sort(*t_ptr);
    printf("\n");
    if (search(*t_ptr, 40) == NULL){
        printf("OK: 40 foi removido\n");
    } else {
        printf("ERRO: 40 ainda existe\n");
    }

    printf("\nRemovendo no com dois filhos (30)...\n");
    *t_ptr = remove_bst(*t_ptr, 30);
    printf("Arvore apos remover 30: ");
    print_bst_sort(*t_ptr);
    printf("\n");
    if (search(*t_ptr, 30) == NULL){
        printf("OK: 30 foi removido\n");
    } else {
        printf("ERRO: 30 ainda existe\n");
    }

    printf("\nRemovendo raiz (35)...\n");
    *t_ptr = remove_bst(*t_ptr, 35);
    printf("Arvore apos remover 35: ");
    print_bst_sort(*t_ptr);
    printf("\n");
    if (search(*t_ptr, 35) == NULL){
        printf("OK: 35 foi removido\n");
    } else {
        printf("ERRO: 35 ainda existe\n");
    }

    printf("\nRemovendo elemento que nao existe (999)...\n");
    Node_bst *before_search = search(*t_ptr, 999);
    *t_ptr = remove_bst(*t_ptr, 999);
    Node_bst *after_search = search(*t_ptr, 999);
    printf("Arvore apos tentar remover 999: ");
    print_bst_sort(*t_ptr);
    printf("\n");
    if (before_search == NULL && after_search == NULL){
        printf("OK: operacao nao afetou arvore\n");
    } else {
        printf("ERRO: operacao teve efeito inesperado\n");
    }

    printf("\nRemovendo ultimo elemento (34)...\n");
    *t_ptr = remove_bst(*t_ptr, 34);
    printf("Arvore apos remover 34: ");
    if (*t_ptr == NULL){
        printf("(vazia)\n");
    } else {
        print_bst_sort(*t_ptr);
        printf("\n");
    }
    if (search(*t_ptr, 34) == NULL){
        printf("OK: 34 foi removido\n");
    } else {
        printf("ERRO: 34 ainda existe\n");
    }
}

int main(){
    Node_bst *t = create_bst();
    printf("Arvore criada com ponteiro NULL OK\n\n");

    t = test_insertion_bst(t);
    printf("\n");
    test_search_bst(t);

    test_remove_bst(&t);

    if (t != NULL){
        free_bst(t);
    }

    return 0;
}



