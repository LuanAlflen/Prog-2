#include "lista.h"
//perguntas
//nas "info" qual valor de dado casa a lista seja vazia ou nula, ele continua inalterado?
//na lista remove todas, caso n tenha o numero na lista, considero lista invalida e retorno -1 ou continuo retornando -2 igual remove_primeira, ou returno 0?
/**
 * arquivo lista.c
 *
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas fornecidas. Você pode
 * implementar funções auxiliares além das fornecidas, para isso,
 * coloque o cabeçário da função no arquivo .h e sua implementação
 * aqui, no arquivo .c. Não altere assinaturas de funções, caso
 * contrário seu código receberá nota 0,0 (zero).
 */

//Estrutura de lista
struct lista {
    tipo 		*dados;		//Vetor que armazena os dados
    int 		capacidade; //Capacidade de armazenamento da lista
    int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções

//1
lista_t*	lista_cria				(int capacidade){
    lista_t *l = (lista_t*) malloc(sizeof(lista_t));
    if(l){
        l->capacidade = capacidade;
        l->tamanho = 0;
        l->dados = (int*) malloc(sizeof(int)*capacidade);
        if(l->dados == NULL){
            free(l);
            return NULL;
        }
        return l;
    }
    return NULL;
}

//2
void		lista_destroi			(lista_t **l){
    if(l == NULL) {
        return;
    }
    if(*l == NULL) {
        return;
    }
    if((*l)->dados == NULL) {
        free((*l));
        *l = NULL;
        return;
    }
    else {
        free((*l)->dados);
    }
    free((*l));
    *l = NULL;
}

//3
int 		lista_inicializada		(lista_t *l){
    if(l){
        if(l->dados){
            return 1;
        }
    }
    return 0;
}

//4
int 		lista_tamanho			(lista_t *l){
    if(lista_inicializada(l) == 1){
        return l->tamanho;
    }
    return -1;
}

//5
int 		lista_capacidade			(lista_t *l){
    if(lista_inicializada(l) == 1){
        return l->capacidade;
    }
    return -1;
}

//6
int 		lista_cheia 			(lista_t *l){
    if(lista_inicializada(l) == 1){
        if(lista_capacidade(l) == lista_tamanho(l)){
            return 1;
        }
        return 0;
    }
    return -1;
}

//7
int 		lista_info_cabeca  		(lista_t *l, int *dado){
    if(dado == NULL){
        return -1;
    }
    if(lista_inicializada(l) == 1){
        if(lista_tamanho(l) == 0){
            return 0;
        }
        *dado = l->dados[0];
        return 1;
    }
    return -1;
}

//8
int 		lista_info_cauda 		(lista_t *l, int *dado){
    if(dado == NULL){
        return -1;
    }
    if(lista_inicializada(l) == 1){
        if(lista_tamanho(l) == 0){
            return 0;
        }
        *dado = l->dados[(l->tamanho)-1];
        return 1;
    }
    return -1;
}

//9
int 		lista_info_posicao 		(lista_t *l, int *dado, int pos){
    if(dado == NULL){
        return -1;
    }
    if(lista_inicializada(l) == 1){
        if(lista_tamanho(l) == 0){
            return 0;
        }
        if(pos > l->tamanho || pos < 0)
            return 0;
        *dado = l->dados[pos];
        return 1;
    }
    return -1;
}

//10
int			lista_insere_cabeca		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(lista_cheia(l) == 1){
            return -1;
        }
        int aux=0, aux2=0;
        for (int i = 0; i < (l->tamanho)+1; ++i) {
            if(i==0) {
                aux = l->dados[i];
                l->dados[i] = dado;
            }
            else {
                aux2 = l->dados[i];
                l->dados[i] = aux;
                aux = aux2;
            }
        }
        l->tamanho++;
        return 1;
    }
    return -1;
}

//11
int			lista_insere_cauda		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(lista_cheia(l) == 1){
            return -1;
        }
        l->dados[l->tamanho] = dado;
        l->tamanho++;
        return 1;
    }
    return -1;
}

//12
int			lista_insere_posicao	(lista_t *l, tipo dado, int pos){
    if(lista_inicializada(l) == 1){
        if(lista_cheia(l) == 1){
            return -1;
        }
        if(pos < 0 || pos > l->tamanho)
            return 0;
        if(pos == 0){
            lista_insere_cabeca(l, dado);
            return 1;
        }
        if(pos == l->tamanho){
            lista_insere_cauda(l, dado);
            return 1;
        }
        int aux=0, aux2=0;
        for (int i = 0; i < l->tamanho; ++i) {
            if(i == pos){
                for (int j = i; j <= l->tamanho; ++j) {
                    if(i==j) {
                        aux = l->dados[i];
                        l->dados[i] = dado;
                    }
                    else {
                        aux2 = l->dados[j];
                        l->dados[j] = aux;
                        aux = aux2;
                    }
                }

            }
        }
        l->tamanho++;
        return 1;
    }
    return -1;
}

//13
int			lista_remove_cabeca		(lista_t *l, tipo *dado){
    if(lista_inicializada(l) == 1){
        if(dado == NULL)
            return -1;
        if(lista_tamanho(l) == 0){
            return 0;
        }
        *dado = l->dados[0];
        for (int i = 0; i < (l->tamanho)-1; ++i) {
            l->dados[i] = l->dados[i+1];
        }
        l->tamanho--;
        return 1;
    }
    return -1;
}

//14
int			lista_remove_cauda		(lista_t *l, tipo *dado){
    if(lista_inicializada(l) == 1){
        if(dado == NULL)
            return -1;
        if(lista_tamanho(l) == 0){
            return 0;
        }
        *dado = l->dados[(l->tamanho)-1];
        l->tamanho--;
        return 1;
    }
    return -1;
}

//15
int			lista_remove_posicao	(lista_t *l, tipo *dado, int pos){
    if(lista_inicializada(l) == 1){
        if(dado == NULL)
            return -1;
        if(lista_tamanho(l) == 0){
            return 0;
        }
        if(pos < 0 || pos >= l->tamanho)
            return 0;

        if(pos == 0){
            *dado = l->dados[pos];
            lista_remove_cabeca(l, dado);
            return 1;
        }
        if(pos == (l->tamanho)-1){
            *dado = l->dados[pos];
            lista_remove_cauda(l, dado);
            return 1;
        }

        *dado = l->dados[pos];
        for (int i = 0; i < l->tamanho; ++i) {
            if(i >= pos){
                l->dados[i] = l->dados[i+1];
            }
        }
        l->tamanho--;
        return 1;

    }
    return -1;
}

//16
int 		lista_remove_primeira	(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(lista_existe_tipo_dado(l, dado) == 0)
            return -2;
        for (int i = 0; i < l->tamanho; ++i) {
            if(l->dados[i] == dado){
                int aux;
                lista_remove_posicao(l, &aux, i);
                return i;
            }
        }
    }
    return -1;
}

//17
int 		lista_remove_todas		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
//        if(lista_existe_tipo_dado(l, dado) == 0)
//            return -2;
        int vezes_removida=0, aux;
        for (int i = 0; i < l->tamanho; ++i) {
            if(l->dados[i] == dado){
                lista_remove_posicao(l, &aux, i);
                vezes_removida++;
                i--;
            }
        }
        return vezes_removida;
    }
    return -1;
}

//18
int 		lista_busca_info		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(lista_existe_tipo_dado(l, dado) == 0)
            return -1;
        for (int i = 0; i < l->tamanho; ++i) {
            if(l->dados[i] == dado){
                return i;
            }
        }
    }
    return -1;
}

//19
int 		lista_frequencia_info	(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
//        if(lista_existe_tipo_dado(l, dado) == 0)
//            return -2;
        int vezes_achado=0;
        for (int i = 0; i < l->tamanho; ++i) {
            if(l->dados[i] == dado){
                vezes_achado++;
            }
        }
        return vezes_achado;
    }
    return -1;
}

//20
int			lista_ordenada 			(lista_t *l){
    if(lista_inicializada(l) == 1){
        if(l->tamanho == 0)
            return 1;
        int parcial = l->dados[0];
        for (int i = 0; i < (l->tamanho)-1; ++i) {
            if(l->dados[i+1] <= parcial)
                return 0;
        }
        return 1;
    }
    return -1;
}

//21
int 		lista_insere_ordenado	(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        if(l->tamanho == 0){
            lista_insere_cabeca(l, dado);
            return 1;
        }

        for (int i = 0; i < l->tamanho; ++i) {
            if(dado <= l->dados[i]){
                lista_insere_posicao(l, dado, i);
                return 1;
            }
        }
        lista_insere_cauda(l, dado);
        return 1;
        

    }
    return -1;
}

//22
int 		lista_compara(lista_t *l1, lista_t *l2){
    if(lista_inicializada(l1) == 0 && lista_inicializada(l2) == 0){
        return 1;
    }
    if(lista_inicializada(l1) == 1 && lista_inicializada(l2) == 1){
        if(l1->tamanho == l2->tamanho){
            for (int i = 0; i < l1->tamanho; ++i) {
                if(l1->dados[i] != l2->dados[i])
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

//23
int 		lista_reverte(lista_t *l){
    if(lista_inicializada(l) == 1){
        if(l->tamanho == 0 || l->tamanho == 1)
            return 1;
        int aux[l->tamanho], j=0;
        for (int i = (l->tamanho)-1; i >= 0; --i) {
            aux[i] = l->dados[j];
            j++;
        }
        for (int i = 0; i < l->tamanho; ++i) {
            l->dados[i] = aux[i];
        }
        return 1;
    }
    return -1;
}

//24
lista_t*	lista_cria_copia(lista_t *l){
    if(l){
        lista_t *lista_copia = lista_cria(l->capacidade);
        if(lista_inicializada(lista_copia) == 1){
            for (int i = 0; i < l->tamanho; ++i) {
                lista_insere_cauda(lista_copia, l->dados[i]);
            }
            return lista_copia;
        }
        return NULL;
    }
    return NULL;
}

//extra
int         lista_existe_tipo_dado (lista_t *l, tipo dado){
    if(lista_inicializada(l) == 1){
        for (int i = 0; i < l->tamanho; ++i) {
            if(l->dados[i] == dado)
                return 1;
        }
        return 0;
    }
    return -1;
}