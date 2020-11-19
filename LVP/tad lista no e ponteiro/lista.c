#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de nó duplamente encadeado
struct no {
    tipo 		 info;		//Informação (dado) armazenada no nó
    struct no	*ant;		//Ponteiro para o nó anterior
    struct no	*prx;		//Ponteiro para o próximo nó
};

//Estrutura de lista duplamente encadeada com nós
struct lista {
    no_t 		*cabeca;	//Ponteiro para a cabeça da lista (primeiro)
    no_t 		*cauda;		//Ponteiro para a cauda da lista (último)
    int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções

//1
lista_t*	lista_cria				(){
    lista_t *l = (lista_t*) malloc(sizeof(lista_t));
    if(l){
        l->tamanho=0;
        l->cabeca=NULL;
        l->cauda=NULL;
        return l;
    }
    return NULL;
}

//2
void		lista_destroi			(lista_t **l){
    if(!l) return;
    if(!(*l)) return;

    no_t *aux;

    while ((*l)->cabeca != NULL){
        aux = (*l)->cabeca;
        (*l)->cabeca = (*l)->cabeca->prx;
        free(aux);
    }
    free(*l);
    *l = NULL;
}

//3
int 		lista_inicializada		(lista_t *l){
    if(l)
        return 1;
    else
        return 0;
}

//4
int 		lista_tamanho			(lista_t *l){
    if(lista_inicializada(l) == 0)return -1;
    return l->tamanho;
}

//5
int 		lista_info_cabeca  		(lista_t *l, int *dado){
    if(lista_inicializada(l) == 0)return -1;
    if(!dado)return -1;
    if(lista_tamanho(l) == 0)return 0;
    *dado = l->cabeca->info;
    return 1;
}

//6
int 		lista_info_cauda 		(lista_t *l, int *dado){
    if(lista_inicializada(l) == 0)return -1;
    if(!dado)return -1;
    if(lista_tamanho(l) == 0)return 0;
    *dado = l->cauda->info;
    return 1;
}

//7
int 		lista_info_posicao 		(lista_t *l, int *dado, int pos){
    if(lista_inicializada(l) == 0)return -1;
    if(!dado)return -1;
    if(lista_tamanho(l) == 0)return 0;
    if(pos >= lista_tamanho(l) || pos < 0)return 0;
    //verificando casos de cabeça e cauda
    if(pos == 0){
        lista_info_cabeca(l, dado);
        return 1;
    }
    if(pos == (lista_tamanho(l)-1)){
        lista_info_cauda(l, dado);
        return 1;
    }
    //percorrendo nós
    int i=0;
    no_t *aux = l->cabeca;
    while (i!=pos){
        aux = aux->prx;
        i++;
    }
    *dado = aux->info;
    return 1;
}

//8
int			lista_insere_cabeca		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    no_t *novo_no = (no_t*) malloc(sizeof(no_t));
    if(!novo_no)return -1;
    novo_no->info = dado;
    novo_no->prx = l->cabeca;
    novo_no->ant=NULL;
    if(l->cabeca != NULL){
        l->cabeca->ant = novo_no;
    }
    l->cabeca = novo_no;
    //se a lista esta vazia, o novo vais er cabeça e cauda
    if(l->tamanho == 0)
        l->cauda = novo_no;
    l->tamanho++;
    return 1;
}

//9
int			lista_insere_cauda		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    no_t *novo_no = (no_t*) malloc(sizeof(no_t));
    if(!novo_no)return -1;
    novo_no->info = dado;
    novo_no->prx = NULL;
    novo_no->ant = l->cauda;
    if(l->cauda != NULL){
        l->cauda->prx = novo_no;
        l->cauda = novo_no;
    }else{
        //se a lista esta vazia, o novo vai ser cabeça e cauda
        l->cabeca = novo_no;
        l->cauda = novo_no;
    }
    l->tamanho++;
    return 1;
}

//10
int			lista_insere_posicao	(lista_t *l, tipo dado, int pos){
    if(lista_inicializada(l) == 0)return -1;
    if(pos < 0 || pos > l->tamanho)return 0;

    //caso insere cabeça
    if(pos == 0){
        lista_insere_cabeca(l, dado);
        return 1;
    }
    //caso insere cauda
    if(pos == l->tamanho){
        lista_insere_cauda(l, dado);
        return 1;
    }

    no_t *novo_no = (no_t*) malloc(sizeof(no_t));
    if(!novo_no)return -1;

    novo_no->info = dado;
    no_t *aux = l->cabeca;
    int i=0;
    while (i!=pos){
        aux = aux->prx;
        i++;
    }
    novo_no->ant = aux->ant;
    aux->ant->prx = novo_no;
    aux->ant = novo_no;
    novo_no->prx = aux;

    l->tamanho++;
    return 1;
}

//11
int			lista_remove_cabeca		(lista_t *l, tipo *dado){
    if(lista_inicializada(l) == 0)return -1;
    if(!dado) return -1;
    if(l->tamanho==0)return 0;

    no_t *aux = l->cabeca;
    if(l->cabeca->prx == NULL){
        //só tem um elemento na lista
        *dado = l->cabeca->info;
        l->cabeca=NULL;
        l->cauda=NULL;
        l->tamanho--;
        free(aux);
        return 1;
    }else{
        //tem mais de um elemento no lista
        *dado = l->cabeca->info;
        l->cabeca = l->cabeca->prx;
        l->cabeca->ant = NULL;
        l->tamanho--;
        free(aux);
        return 1;
    }
}

//12
int			lista_remove_cauda		(lista_t *l, tipo *dado){
    if(lista_inicializada(l) == 0)return -1;
    if(!dado) return -1;
    if(l->tamanho==0)return 0;

    no_t *aux = l->cauda;
    *dado = l->cauda->info;
    if(l->cauda->ant ==NULL){
        //só tem um elemento na lista
        l->cauda=NULL;
        l->cabeca=NULL;
        l->tamanho--;
        free(aux);
        return 1;
    }else{
        l->cauda = l->cauda->ant;
        l->cauda->prx = NULL;
        l->tamanho--;
        free(aux);
        return 1;
    }
}

//13
int			lista_remove_posicao	(lista_t *l, tipo *dado, int pos){
    if(lista_inicializada(l) == 0)return -1;
    if(!dado) return -1;
    if(l->tamanho==0)return 0;
    if(pos < 0 || pos >= l->tamanho)return 0;

    //------------------------
    //caso remove cabeça
    if(pos == 0){
        lista_remove_cabeca(l, dado);
        return 1;
    }
    //caso remove cauda
    if(pos == (l->tamanho)-1){
        lista_remove_cauda(l, dado);
        return 1;
    }

    no_t *aux = l->cabeca;
    int i=0;
    while (i!=pos){
        aux = aux->prx;
        i++;
    }
    aux->ant->prx = aux->prx;
    aux->prx = aux->ant;
    *dado = aux->info;
    free(aux);
    l->tamanho--;
    return 1;

}

//14
int 		lista_remove_primeira	(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    if(l->tamanho==0)return -2;

    no_t *aux = l->cabeca;
    int i=0, aux2;
    while (aux !=NULL){
        if(aux->info == dado){
            lista_remove_posicao(l, &aux2, i);
            return i;
        }
        aux = aux->prx;
        i++;
    }
    return -2;
}

//15
int 		lista_remove_todas		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    if(l->tamanho==0)return 0;

    no_t *aux = l->cabeca;
    int i=0, aux2, count=0;
    while (aux !=NULL){
        if(aux->info == dado){
            aux = aux->prx;
            lista_remove_posicao(l, &aux2, i);
            count++;
        }else{
            aux = aux->prx;
            i++;
        }
    }
    return count;
}

//16
int 		lista_busca_info		(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    if(l->tamanho==0)return -1;

    no_t *aux = l->cabeca;
    int i=0;
    while (aux->prx !=NULL){
        if(aux->info == dado){
            return i;
        }
        aux = aux->prx;
        i++;
    }
    return -1;
}

//17
int 		lista_frequencia_info	(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    if(l->tamanho==0)return -1;

    no_t *aux = l->cabeca;
    int i=0, count=0;
    while (aux->prx !=NULL){
        if(aux->info == dado){
            count++;
        }
        aux = aux->prx;
        i++;
    }
    if(aux->info == dado){
        count++;
    }
    return count;
}

//18
int			lista_ordenada 			(lista_t *l){
    if(lista_inicializada(l) == 0)return -1;
    if(l->tamanho==0 || l->tamanho == 1)return 1;
    no_t *aux = l->cabeca;
    no_t *aux2 = l->cabeca->prx;
    if(l->tamanho == 2){
        if(aux->info > aux2->info){
            return 0;
        }
    }
    while (aux2->prx !=NULL){
        if(aux->info > aux2->info){
            return 0;
        }
        aux = aux->prx;
        aux2 = aux2->prx;
    }
    //verificando os dois ultimos numeros
    if(aux->info > aux2->info){
        return 0;
    }
    return 1;
}

//19
int 		lista_insere_ordenado	(lista_t *l, tipo dado){
    if(lista_inicializada(l) == 0)return -1;
    if(l->tamanho == 0){
        if(lista_insere_cabeca(l, dado) == 1)
            return 1;
        else
            return -1;
    }
    no_t *aux = l->cabeca;
    int i=0;
    while (aux->prx !=NULL){
        if(dado <= aux->info){
            if(lista_insere_posicao(l, dado, i) ==1)
                return 1;
            else
                return -1;
        }
        i++;
        aux = aux->prx;
    }
    if(dado <= aux->info){
        if(lista_insere_posicao(l, dado, i) ==1)
            return 1;
        else
            return -1;
    } else{
        if(lista_insere_cauda(l, dado) == 1)
            return 1;
        else
            return -1;
    }
}

//20
int 		lista_compara(lista_t *l1, lista_t *l2){
    if(lista_inicializada(l1) != lista_inicializada(l2))return 0;
    if(lista_inicializada(l1) == 0 && lista_inicializada(l2) == 0)return 1;
    if(l1->tamanho != l2->tamanho)return 0;
    if(l1->tamanho == 0)return 1;

    no_t *aux = l1->cabeca;
    no_t *aux2 = l2->cabeca;
    while (aux->prx !=NULL){
        if(aux->info != aux2->info){
            return 0;
        }
        aux = aux->prx;
        aux2 = aux2->prx;
    }
    if(aux->info != aux2->info){
        return 0;
    }

    return 1;

}

//21
int 		lista_reverte(lista_t *l){
    if(lista_inicializada(l) == 0)return -1;
    if(lista_tamanho(l) == 0 || lista_tamanho(l) == 1)return 1;
    no_t *aux = l->cabeca;
    no_t *aux2 = l->cauda;
    int num_trocas=0, parcial;
    while (num_trocas <= (l->tamanho)-1){
        parcial = aux->info;
        aux->info = aux2->info;
        aux2->info = parcial;
        num_trocas++;
        num_trocas++;
        aux = aux->prx;
        aux2 = aux2->ant;
    }
    return 1;
}

//22
lista_t*	lista_cria_copia(lista_t *l){
    if(l == NULL)return NULL;
    lista_t *copia = lista_cria();
    if(!copia) return NULL;

    if(l->tamanho == 0){
        return copia;
    }

    no_t *aux = l->cabeca;
    int i=0, dado;
    while (aux->prx !=NULL){
        dado = aux->info;
        lista_insere_cauda(copia, dado);
        aux = aux->prx;
        i++;
    }
    dado = aux->info;
    lista_insere_cauda(copia, dado);

    return copia;
}

//23
void        imprime_lista(no_t *no){
    if(no == NULL)return;
    printf("%d ", no->info);
    if(no->prx == NULL){
        printf("\n");
        return;
    }
    imprime_lista(no->prx);
}