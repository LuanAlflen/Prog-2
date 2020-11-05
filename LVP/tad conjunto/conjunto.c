#include "conjunto_privado.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//1
conjunto_t *conjunto_cria(void){
    conjunto_t *c = (conjunto_t*) malloc(sizeof(conjunto_t));
    if(c){
        c->capacidade = 10;
        c->numero = 0;
        c->vetor = (int*) malloc(sizeof(int)*10);
        if(c->vetor == NULL){
            free(c);
            return NULL;
        }
    }
    return c;
}
//2
void conjunto_destroi(conjunto_t **a){
    if(a == NULL) {
        return;
    }
    if(*a == NULL) {
        return;
    }
    if((*a)->vetor == NULL) {
        free((*a));
        *a = NULL;
        return;
    }
    else {
        free((*a)->vetor);
    }
    free((*a));
    *a = NULL;
}
//3
int conjunto_numero_elementos(conjunto_t *a){
    if(a)
        return a->numero;
    return 0;
}
//4
void conjunto_inicializa_vazio(conjunto_t *a){
    if(a)
        a->numero = 0;
}
//5
void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a && b && c){
        c->numero=0;
//        c->capacidade= (a->numero + b->numero);
//        c->vetor = realloc(c->vetor, sizeof(int)*(a->numero + b->numero));
        for (int i = 0; i < a->numero; ++i) {
            conjunto_insere_elemento(a->vetor[i], c);
        }
        for (int i = 0; i < b->numero; ++i) {
            conjunto_insere_elemento(b->vetor[i], c);
        }
    }
}
//6
void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a && b && c){
        c->numero=0;
//        c->capacidade= (a->numero + b->numero);
//        c->vetor = realloc(c->vetor, sizeof(int)*(a->numero + b->numero));
        for (int i = 0; i < a->numero; ++i) {
            for (int j = 0; j < b->numero; ++j) {
                if(a->vetor[i] == b->vetor[j]){
                    conjunto_insere_elemento(a->vetor[i], c);
                }
            }
        }
    }
}
//7
void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a && b && c){
        c->numero=0;
//        c->capacidade= (a->numero + b->numero);
//        c->vetor = realloc(c->vetor, sizeof(int)*(a->numero + b->numero));
        for (int i = 0; i < a->numero; ++i) {
            if(conjunto_membro(a->vetor[i], b) == 0){
                conjunto_insere_elemento(a->vetor[i], c);
            }
        }
    }
}
//8
int conjunto_membro(elem_t x, conjunto_t *a){
    if(a){
        for (int i = 0; i < a->numero; ++i) {
            if(a->vetor[i] == x)
                return 1;
        }
        return 0;
    }
    return 0;
}
//9
int conjunto_insere_elemento(elem_t x, conjunto_t *a){
    if(a){
        if(conjunto_membro(x, a) == 1)
            return 1;
        if(a->numero == a->capacidade){
            a->capacidade++;
            a->vetor = realloc(a->vetor, sizeof(int)*(a->capacidade));
        }
        a->vetor[(a->numero)] = x;
        a->numero++;
        return 1;
    }
    return 0;
}

//10
void conjunto_remove_elemento(elem_t x, conjunto_t *a){
    if(a){
        if(conjunto_membro(x, a) == 0)
            return;
        for (int i = 0; i < a->numero; ++i) {
            if(a->vetor[i] == x){
                for (int j = i; j < (a->numero-1); ++j) {
                    a->vetor[j] = a->vetor[j+1];
                }
            }
        }
        a->numero--;
    }
}

//11
void conjunto_atribui(conjunto_t *a, conjunto_t *b){
    if(a != NULL && b != NULL){
        conjunto_inicializa_vazio(b);
        for (int i = 0; i < a->numero; ++i) {
            conjunto_insere_elemento(a->vetor[i], b);
        }
    }
}

//12
int conjunto_igual(conjunto_t *a, conjunto_t *b){
    if(a != NULL && b != NULL){
        if(a->numero != b->numero)
            return 0;
        for (int i = 0; i < b->numero; ++i) {
            if(conjunto_membro(b->vetor[i], a) == 0)
                return 0;
        }
        for (int i = 0; i < a->numero; ++i) {
            if(conjunto_membro(a->vetor[i], b) == 0)
                return 0;
        }
        return 1;
    }
    return 0;
}

//13
elem_t conjunto_minimo(conjunto_t *a){
    if(a){
        if(a->numero == 0)
            return ELEM_MAX;
        int minimo=a->vetor[0];
        for (int i = 0; i < a->numero; ++i) {
            if(a->vetor[i] < minimo)
                minimo = a->vetor[i];
        }
        return minimo;
    }
    return ELEM_MAX;
}
//14
elem_t conjunto_maximo(conjunto_t *a){
    if(a){
        if(a->numero == 0)
            return ELEM_MAX;
        int maximo=a->vetor[0];
        for (int i = 0; i < a->numero; ++i) {
            if(a->vetor[i] > maximo)
                maximo = a->vetor[i];
        }
        return maximo;
    }
    return ELEM_MIN;
}


void conjunto_imprime(conjunto_t *a){
    if(a){
        for (int i = 0; i < a->numero; ++i) {
            if(i==(a->numero-1)){
                printf("%d\n", a->vetor[i]);
            }else{
                printf("%d ", a->vetor[i]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    conjunto_t *c1 = conjunto_cria();
    conjunto_t *c2 = conjunto_cria();
    conjunto_t *c3 = conjunto_cria();
    conjunto_t *c4 = conjunto_cria();
    conjunto_t *c5 = conjunto_cria();


    //gerando c1 e c2 aleatoriamente
    int tmp = rand() % 16, x;
    while (tmp < 5)
        tmp = rand() % 16;
    for (int i = 0; i < tmp; i++) {
        x = rand() % 11;
        conjunto_insere_elemento(x, c1);
    }

    tmp = rand() % 16;
    while (tmp < 5)
        tmp = rand() % 16;
    for (int i = 0; i < tmp; i++) {
        x = rand() % 11;
        conjunto_insere_elemento(x, c2);
    }

    //conjunto_inicializa_vazio(c1);

    /*
    for (int i = 1; i < 6; ++i) {
        conjunto_insere_elemento(i, c1);
    }

    for (int i = 5; i > 0; --i) {
        conjunto_insere_elemento(i, c2);
    }
     */

    conjunto_uniao(c1, c2, c3);
    conjunto_interseccao(c1, c2, c4);
    conjunto_diferenca(c1, c2, c5);


    printf("1. c1: ");
    conjunto_imprime(c1);
    //printf("c1 tem %d elementos\n", conjunto_numero_elementos(c1));

    printf("2. c2: ");
    conjunto_imprime(c2);
    //printf("c2 tem %d elementos\n", conjunto_numero_elementos(c2));

    if(conjunto_igual(c1, c2) == 1){
        printf("3. c1 e c2 sao iguais\n");
    }else{
        printf("3. c1 e c2 sao diferentes\n");
    }

    printf("4. minimo de c1: %d\n", conjunto_minimo(c1));
    printf("5. maximo de c1: %d\n", conjunto_maximo(c1));

    printf("6. uniao: ");
    conjunto_imprime(c3);

    printf("7. interseccao: ");
    conjunto_imprime(c4);

    printf("8. diferenca: ");
    conjunto_imprime(c5);

    conjunto_remove_elemento(5, c1);
    printf("9. c1 com valor 5 removido: ");
    conjunto_imprime(c1);

    conjunto_atribui(c1, c2);
    printf("10. c2 = c1 removido: ");
    conjunto_imprime(c2);
    conjunto_destroi(&c1);
    conjunto_destroi(&c2);
    conjunto_destroi(&c3);
    conjunto_destroi(&c4);
    conjunto_destroi(&c5);


    return 0;
}