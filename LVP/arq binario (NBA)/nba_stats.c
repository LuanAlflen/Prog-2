#include "nba_stats.h"
#include <stdio.h>
//1
int 		le_cabecario				(char *nome){
    if(nome){
        FILE *arq=fopen(nome, "r");
        if(!arq){
            return 0;
        }
        int qtd_jogadores;
        fread(&qtd_jogadores, sizeof(int), 1, arq);
        fclose(arq);
        return qtd_jogadores;
    }
    return -1;
}
//2
jogador_t* 	le_jogadores				(char *nome, int *njogadores){
    if(nome == NULL|| njogadores == NULL){
        return NULL;
    }
    FILE *arq=fopen(nome, "r");
    if(!arq){
        return NULL;
    }
    *njogadores = le_cabecario(nome);
    jogador_t *info = (jogador_t*) malloc(sizeof(jogador_t)* (*njogadores));
    fseek(arq, sizeof(int), SEEK_SET);
    fread(info, sizeof(jogador_t), (*njogadores), arq);
    fclose(arq);
    return info;
}
//3
int 		statj_mais_arremessos		(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    int parcial=0, id=0;
    if(tipo != 'L' && tipo != 'T' && tipo != '2' && tipo != '3')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='L'){
            if(jogadores[i].aL.arremessos > parcial){
                parcial=jogadores[i].aL.arremessos;
                id=i;
            }
        }
        if(tipo=='T'){
            if(jogadores[i].aT.arremessos > parcial){
                parcial=jogadores[i].aT.arremessos;
                id=i;
            }
        }
        if(tipo=='2'){
            if(jogadores[i].a2.arremessos > parcial){
                parcial=jogadores[i].a2.arremessos;
                id=i;
            }
        }
        if(tipo=='3'){
            if(jogadores[i].a3.arremessos > parcial){
                parcial=jogadores[i].a3.arremessos;
                id=i;
            }
        }

    }
    return id;

}
//4
int 		statj_mais_cestas			(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    int parcial=0, id=0;
    if(tipo != 'L' && tipo != 'T' && tipo != '2' && tipo != '3')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='L'){
            if(jogadores[i].aL.cestas > parcial){
                parcial=jogadores[i].aL.cestas;
                id=i;
            }
        }
        if(tipo=='T'){
            if(jogadores[i].aT.cestas > parcial){
                parcial=jogadores[i].aT.cestas;
                id=i;
            }
        }
        if(tipo=='2'){
            if(jogadores[i].a2.cestas > parcial){
                parcial=jogadores[i].a2.cestas;
                id=i;
            }
        }
        if(tipo=='3'){
            if(jogadores[i].a3.cestas > parcial){
                parcial=jogadores[i].a3.cestas;
                id=i;
            }
        }

    }
    return id;
}
//5
int 		statj_melhor_percentual		(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    float parcial=0; int id=0;
    if(tipo != 'L' && tipo != 'T' && tipo != '2' && tipo != '3')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='L'){
            if(jogadores[i].aL.percentual > parcial){
                parcial=jogadores[i].aL.percentual;
                id=i;
            }
        }
        if(tipo=='T'){
            if(jogadores[i].aT.percentual > parcial){
                parcial=jogadores[i].aT.percentual;
                id=i;
            }
        }
        if(tipo=='2'){
            if(jogadores[i].a2.percentual > parcial){
                parcial=jogadores[i].a2.percentual;
                id=i;
            }
        }
        if(tipo=='3'){
            if(jogadores[i].a3.percentual > parcial){
                parcial=jogadores[i].a3.percentual;
                id=i;
            }
        }

    }
    return id;
}
//6
int 		statj_jogos					(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    int parcial=0, id=0;
    if(tipo != '+' && tipo != '-')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='+'){
            if(jogadores[i].jogos > parcial){
                parcial=jogadores[i].jogos;
                id=i;
            }
        }
        if(tipo=='+'){
            if(i == 0) {
                parcial = jogadores[0].jogos;
                id=0;
            }
            if(jogadores[i].jogos < parcial){
                parcial=jogadores[i].jogos;
                id=i;
            }
        }

    }
    return id;
}
//7
int 		statj_idade					(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    int parcial=0, id=0;
    if(tipo != '+' && tipo != '-')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='+'){
            if(jogadores[i].idade > parcial){
                parcial=jogadores[i].idade;
                id=i;
            }
        }
        if(tipo=='-'){
            if(i == 0) {
                parcial = jogadores[0].idade;
                id=0;
            }
            if(jogadores[i].idade < parcial){
                parcial=jogadores[i].idade;
                id=i;
            }
        }

    }
    return id;
}
//8
int 		statj_minutos				(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    int parcial=0, id=0;
    if(tipo != '+' && tipo != '-')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='+'){
            if(jogadores[i].minutos > parcial){
                parcial=jogadores[i].minutos;
                id=i;
            }
        }
        if(tipo=='-'){
            if(i == 0) {
                parcial = jogadores[0].minutos;
                id=0;
            }
            if(jogadores[i].minutos < parcial){
                parcial=jogadores[i].minutos;
                id=i;
            }
        }

    }
    return id;
}
//9
int 		statj_pontos				(jogador_t *jogadores, int njogadores, char tipo){
    if(!jogadores)return -1;
    int parcial=0, id=0;
    if(tipo != '+' && tipo != '-')return -2;

    for (int i = 0; i < njogadores; ++i) {
        if(tipo=='+'){
            if(jogadores[i].pontos > parcial){
                parcial=jogadores[i].pontos;
                id=i;
            }
        }
        if(tipo=='-'){
            if(i == 0) {
                parcial = jogadores[0].pontos;
                id=0;
            }
            if(jogadores[i].pontos < parcial){
                parcial=jogadores[i].pontos;
                id=i;
            }
        }

    }
    return id;
}
//10
int 		statt_soma_pontos			(jogador_t *jogadores, int njogadores, char* time){
    if(jogadores == NULL|| time == NULL)return -1;
    int  soma=0;
    for (int i = 0; i < njogadores; ++i) {
        if(!strcmp(jogadores[i].time, time)){
            soma += jogadores[i].pontos;
        }
    }
    return soma;
}
//11
float 		statt_media_pontos			(jogador_t *jogadores, int njogadores, char* time){
    if(jogadores == NULL|| time == NULL)return -1;
    int  soma=0, jogadores_no_time=0; float media=0;
    for (int i = 0; i < njogadores; ++i) {
        if(!strcmp(jogadores[i].time, time)){
            soma += jogadores[i].pontos;
            jogadores_no_time++;
        }
    }
    if(jogadores_no_time !=0){
        media = (float)soma/ (float) jogadores_no_time;
    }
    return media;
}
//12
float 		statt_media_idade			(jogador_t *jogadores, int njogadores, char* time){
    if(jogadores == NULL|| time == NULL)return -1;
    int  soma=0, jogadores_no_time=0; float media=0;
    for (int i = 0; i < njogadores; ++i) {
        if(!strcmp(jogadores[i].time, time)){
            soma += jogadores[i].idade;
            jogadores_no_time++;
        }
    }
    if(jogadores_no_time !=0){
        media = (float) soma/ (float)jogadores_no_time;
    }
    return media;
}
//13
int 		statt_posicao				(jogador_t *jogadores, int njogadores, char *time, char* posicao){
    if(jogadores == NULL|| time == NULL)return -1;
    int  soma=0;
    for (int i = 0; i < njogadores; ++i) {
        if(!strcmp(jogadores[i].time, time)){
            if(!strcmp(jogadores[i].posicao, posicao)){
                soma++;
            }
        }
    }

    return soma;
}



//Coloque aqui a implementação das funções.