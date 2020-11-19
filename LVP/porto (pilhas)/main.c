#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.c"

int main() {

    int capacidade, i, j, k, l;
    char input[256];

    //printf("digite a altura dos containers:\n");
    scanf("%d", &capacidade);
    while (capacidade!= 0) {


        //printf("digite os containers:\n");
        scanf("%s", input);

        int tam = (int) strlen(input);

        char **pilhas = (char **) malloc(sizeof(char *));
        pilhas[0] = (char *) malloc(sizeof(char) * capacidade);
        //inicializa a pilha com 'a'
        for (l = 0; l < capacidade; ++l) {
            pilhas[0][l] = 'a';
        }

        int qtd_pilhas = 1, inseriu = 0;

        pilhas[0][0] = input[0];
        inseriu++;

        for (i = 1; i < tam; ++i) {

            for (j = 0; j < qtd_pilhas; ++j) {
                for (k = 0; k < capacidade - 1; ++k) {
                    if (pilhas[j][k] >= 65 && pilhas[j][k] <= 90) {
                        if (pilhas[j][k] >= input[i] && pilhas[j][k + 1] == 'a') {
                            //printf("teste\n");
                            pilhas[j][k + 1] = input[i];
                            inseriu++;
                            k = capacidade;
                            j = qtd_pilhas;
                        }
                    }
                }

            }
            //tem q verificar se ele inseriu, se não, cria mais uma linha
            if (inseriu == i) {
                //printf("inseriu uma pilha\n");
                qtd_pilhas++;
                pilhas = (char **) realloc(pilhas, sizeof(char *) * qtd_pilhas);
                pilhas[qtd_pilhas - 1] = (char *) malloc(sizeof(char) * capacidade);
                //inicializa a pilha com 'a'
                for (l = 0; l < capacidade; ++l) {
                    pilhas[qtd_pilhas - 1][l] = 'a';
                }
                pilhas[qtd_pilhas - 1][0] = input[i];
                inseriu++;
            }

            /*
            printf("\n");
            //AKKEFA
            for (int y = 0; y < qtd_pilhas; ++y) {
                for (int j = 0; j < capacidade; ++j) {
                    printf("%c", pilhas[y][j]);
                }
                printf("\n");
            }
            */
        }

        printf("%d\n", qtd_pilhas);

        for (i = 0; i < qtd_pilhas; ++i) {
            free(pilhas[i]);
        }
        free(pilhas);

        scanf("%d", &capacidade);
    }

    return 0;
}