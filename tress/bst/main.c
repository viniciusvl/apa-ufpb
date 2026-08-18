#include <stdio.h>
#include <bst.h>

Node_bst *test_insertion_bst(Node_bst *t){

    // Inserção raiz
    t = insert(t, 35);
    printf("Inseriu 35 na raiz OK\n");
    // inserção a esquerda
    t = insert(t, 30);
    printf("Inseriu 30 a esquerda OK\n");
    //inserção a direita
    t = insert(t, 40);
    printf("Inseriu 40 a direita OK\n");
    //inserir mesma chave
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


int main(){
    Node_bst *t = create_bst();
    printf("Arvore criada com ponteiro NULL OK\n");

    t = test_insertion_bst(t);
    test_search_bst(t);

    return 0;
}



