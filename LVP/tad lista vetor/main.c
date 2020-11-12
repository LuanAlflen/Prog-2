int main(){
    lista_t *lista1 = lista_cria(9);

    lista_insere_cabeca(lista1, 2);
    lista_insere_cauda(lista1, 5);
    lista_insere_cauda(lista1, 5);
    lista_insere_cabeca(lista1, 4);
    lista_insere_posicao(lista1, 6, 1);
    lista_insere_cauda(lista1, 7);
    lista_insere_cabeca(lista1, 1);
    lista_insere_cauda(lista1, 1);

    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");

    printf("inicializada: %d\n", lista_inicializada(lista1));
    printf("tamanho: %d\n", lista_tamanho(lista1));
    printf("capacidade: %d\n", lista_capacidade(lista1));
    printf("cheia: %d\n", lista_cheia(lista1));
    printf("posicao do 6: %d\n", lista_busca_info(lista1, 6));
    printf("vezes q aparece o 1: %d\n", lista_frequencia_info(lista1, 1));
    printf("lista ordenada: %d\n", lista_ordenada(lista1));
    int dado;
    lista_info_cabeca(lista1, &dado);
    printf("info cabeca: %d\n", dado);
    lista_info_cauda(lista1, &dado);
    printf("info cauda: %d\n", dado);
    lista_info_posicao(lista1, &dado, 2);
    printf("info posicao 2: %d\n", dado);

    int dado_removido;
    printf("remove cabeca\n");
    lista_remove_cabeca(lista1, &dado_removido);
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");
    printf("valor removido: %d\n", dado_removido);

    printf("remove cauda\n");
    lista_remove_cauda(lista1, &dado_removido);
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");
    printf("valor removido: %d\n", dado_removido);

    printf("remove posicao 1\n");
    lista_remove_posicao(lista1, &dado_removido, 1);
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");
    printf("valor removido: %d\n", dado_removido);

    printf("remove primeiro 2\n");
    int posicao = lista_remove_primeira(lista1, 2);
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");
    printf("posicao removida: %d\n", posicao);

    printf("lista ordenada: %d\n", lista_ordenada(lista1));

    lista_insere_ordenado(lista1, 6);
    printf("inserindo ordenado 6:\n");
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");


    printf("remove todos os 5's\n");
    int vezes = lista_remove_todas(lista1, 5);
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");
    printf("vezes removidas: %d\n", vezes);

    //--------------- criando outra lista-----------------------//

    lista_t *lista2 = lista_cria(9);

    lista_insere_cabeca(lista2, 4);
    lista_insere_cauda(lista2, 6);
    lista_insere_cauda(lista2, 7);

    printf("-------------------------------\n");
    printf("lista1:\n");
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");

    printf("lista2:\n");
    for (int i = 0; i < lista2->tamanho; ++i) {
        printf("%d ", lista2->dados[i]);
    }
    printf("\n");

    printf("compara lista1 com lista2: %d\n", lista_compara(lista1, lista2));

    printf("reverte lista1:\n");
    lista_reverte(lista1);
    for (int i = 0; i < lista1->tamanho; ++i) {
        printf("%d ", lista1->dados[i]);
    }
    printf("\n");

    printf("lista copia de lista2:\n");
    lista_t *lista3 = lista_cria_copia(lista2);
    for (int i = 0; i < lista3->tamanho; ++i) {
        printf("%d ", lista3->dados[i]);
    }
    printf("\n");

    lista_destroi(&lista1);
    lista_destroi(&lista2);


    return 0;
}