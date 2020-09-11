#include <stdio.h>

int main() {

    int tab[12][12], a, b;


    //só lê
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            tab[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; ++i) {
        scanf("%i", &a);
        scanf("%i", &b);
        //bomba tem valor 100
        tab[a+1][b+1] = 100;
    }

    //manipula os dados
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 11; ++j) {

            if(tab[i][j] != 100){
                //verif. se tem bomba acima
                if(tab[i-1][j] == 100){
                    tab[i][j]++;
                }
                //verif. se tem bomba abaixo
                if(tab[i+1][j] == 100){
                    tab[i][j]++;
                }
                //verif. se tem bomba na esquerda
                if(tab[i][j-1] == 100){
                    tab[i][j]++;
                }
                //verif. se tem bomba direita
                if(tab[i][j+1] == 100){
                    tab[i][j]++;
                }
                // ================================
                //verif. se tem bomba diagonal sup esq.
                if(tab[i-1][j+1] == 100){
                    tab[i][j]++;
                }
                //verif. se tem bomba diagonal sup dir.
                if(tab[i+1][j+1] == 100){
                    tab[i][j]++;
                }
                //verif. se tem bomba na inf. esq.
                if(tab[i-1][j-1] == 100){
                    tab[i][j]++;
                }
                //verif. se tem bomba inf. dir.
                if(tab[i+1][j-1] == 100){
                    tab[i][j]++;
                }
            }
        }
    }

    //só imprimi
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 11; ++j) {
            if (!(i==10 && j==10)){
                if(tab[i][j] == 100){
                    printf("* ");
                }else{
                    printf("%i ", tab[i][j]);
                }
            }else{
                if(tab[i][j] == 100){
                    printf("*");
                } else{
                    printf("%i", tab[i][j]);
                }
            }

        }
        printf("\n");
    }
}