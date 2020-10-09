#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int U, V, I, tam=0, questoes=0, i, pot=0;
    char frase[50];

    printf("numero de questoes:\n");
    scanf("%i",&questoes);
    for(i=0;i<=questoes;i++){
        if(i != 0){
            printf("Questao #%i\n", i);
        }
        fgets(frase, 50, stdin);
        tam = strlen(frase)-1;
        /*if(i != 0) {
            printf("tamanho da frase: %i\n", tam);
        }*/
        //neste for aqui, é onde percorro cada frase e encontro o = delas, onde no caso, terei duas por frase
        for(int j=0;j<tam;j++){
            if(frase[j] == '='){
                if(frase[j-1] == 'U'){
                    printf("tem U\n");
                }
                if(frase[j-1] == 'P'){
                    printf("tem P\n");
                }
                if(frase[j-1] == 'I'){
                    printf("tem I\n");
                }
            }
        // termina o for de cada frase, até aqui tem que dar a resposta de cada uma antes de sair do for
        }


    }

    return 0;
}