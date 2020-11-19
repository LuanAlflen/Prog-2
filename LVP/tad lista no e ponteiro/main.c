#include <stdio.h>
#include "lista.c"

int main() {
    lista_t *lista1 = lista_cria();

    printf("Lista 1:\n");
    //lista ordenada
    lista_insere_cabeca(lista1, 1);
    lista_insere_cauda(lista1, 4);
    lista_insere_cauda(lista1, 6);
    lista_insere_ordenado(lista1,5);
    imprime_lista(lista1->cabeca);


    printf("Lista 2:\n");
    lista_t *lista2 = lista_cria();
    //lista 2 ordenada
    lista_insere_cabeca(lista2, 1);
    lista_insere_cauda(lista2, 4);
    lista_insere_cauda(lista2, 6);
    lista_insere_ordenado(lista2,5);
    imprime_lista(lista2->cabeca);



    //lista qq
    /*
    lista_insere_cabeca(lista1, 3);
    lista_insere_cauda(lista1, 5);
    lista_insere_cauda(lista1, 4);
    lista_insere_posicao(lista1, 6, 1);
    lista_insere_cabeca(lista1, 1);
    lista_insere_cabeca(lista1, 6);
    imprime_lista(lista1->cabeca);
     */

    printf("compara l1 com l2: %d\n", lista_compara(lista1, lista2));

    printf("inicializada: %d\n", lista_inicializada(lista1));
    printf("tamanho: %d\n", lista_tamanho(lista1));
    printf("lista ordenada: %d\n", lista_ordenada(lista1));

    int dado;
    lista_info_cabeca(lista1, &dado);
    printf("info cabeca: %d\n", dado);
    lista_info_cauda(lista1, &dado);
    printf("info cauda: %d\n", dado);
    lista_info_posicao(lista1, &dado, 2);
    printf("info posicao 2: %d\n", dado);

    printf("posicao do 5: %d\n", lista_busca_info(lista1, 5));
    printf("vezes q aparece o 6: %d\n", lista_frequencia_info(lista1, 6));



//    lista_remove_primeira(lista1, 6);
    dado = lista_remove_todas(lista1, 6);
    imprime_lista(lista1->cabeca);
    printf("vezes removidas: %d\n", dado);
    /*
    int dado_removido;
    lista_remove_cabeca(lista1, &dado_removido);
    imprime_lista(lista1->cabeca);
    printf("dado removido: %d\n", dado_removido);

    lista_remove_cauda(lista1, &dado_removido);
    imprime_lista(lista1->cabeca);
    printf("dado removido: %d\n", dado_removido);

    lista_remove_posicao(lista1, &dado_removido, 1);
    imprime_lista(lista1->cabeca);
    printf("dado removido: %d\n", dado_removido);
    */
    lista_reverte(lista1);
    printf("lista invertida:\n");
    imprime_lista(lista1->cabeca);


    printf("lista 3:\n");
    lista_t *lista3 = lista_cria_copia(lista1);
    imprime_lista(lista3->cabeca);

    lista_destroi(&lista1);
    return 0;
}