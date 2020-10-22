#include <stdio.h>

int verifica_lados(char caracter[10][11], int l, int c){
    if(caracter[l][c] == '\n' || caracter[l][c] == '#' ||  caracter[l][c] == 'p' ){
        return 0;
    }
    if(caracter[l][c] == ' '){
        caracter[l][c] = 'p';
        if(l == 0 && c == 0) return 1 + verifica_lados(caracter, l+1,c ) + verifica_lados(caracter, l, c+1); //canto superior esq
        if(l == 0 && c == 9) return 1 + verifica_lados(caracter, l+1,c ) + verifica_lados(caracter, l, c-1); //canto superior dir
        if(l == 9 && c == 0) return 1 + verifica_lados(caracter, l-1,c ) + verifica_lados(caracter, l, c+1); //canto inferior esq
        if(l == 9 && c == 9) return 1 + verifica_lados(caracter, l-1,c ) + verifica_lados(caracter, l, c-1); //canto inferior dir
        if(l==0) return 1 + verifica_lados(caracter, l,c+1 ) + verifica_lados(caracter, l, c-1) + verifica_lados(caracter, l+1, c);
        if(l==9) return 1 + verifica_lados(caracter, l,c+1 ) + verifica_lados(caracter, l, c-1) + verifica_lados(caracter, l-1, c);
        if(c==0) return 1 + verifica_lados(caracter, l+1,c ) + verifica_lados(caracter, l-1, c) + verifica_lados(caracter, l, c+1);
        if(c==9) return 1 + verifica_lados(caracter, l+1,c ) + verifica_lados(caracter, l-1, c) + verifica_lados(caracter, l, c-1);
        //caso n ta em nenhuma borda
        return 1 + verifica_lados(caracter, l+1,c ) + verifica_lados(caracter, l-1, c) + verifica_lados(caracter, l, c-1) +  verifica_lados(caracter, l, c+1);
    }
    return 0;
}


int main() {
    char v[10][11];
    int regioes[50], count=0, parcial;

    //zerando regioes
    for (int i = 0; i < 50; ++i) {
        regioes[i] = 0;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 11; ++j) {
            scanf("%c", &v[i][j]);
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
           parcial = verifica_lados(v, i, j);
           if(parcial != 0){
               regioes[count]  = parcial;
               count++;
           }
        }
    }

    printf("O tabuleiro possui %d regioes, de tamanhos:\n", count);
    int aux;
    for(int  i=0; i<50; i++ ){
        for(int j=i; j<50; j++ ){
            if( regioes[i] > regioes[j] ){
                aux = regioes[i];
                regioes[i] = regioes[j];
                regioes[j] = aux;
            }
        }
    }
    for(int i=0;i<50;i++){
        if(regioes[i] != 0) {
            if (i == 49){
                printf("%d.", regioes[i]);
            }else{
                printf("%d,", regioes[i]);
            }
        }
    }

    return 0;
}