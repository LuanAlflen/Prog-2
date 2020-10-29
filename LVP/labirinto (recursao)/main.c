#include <stdio.h>
#include <stdlib.h>

int labirinto(int lf, int cf, char caracter[lf][cf], int l, int c){
    int resposta=0;
    if(l == (lf-2) && c == (cf-2)){
        caracter[l][c] = '.';
        return 1;
    }
    caracter[l][c] = '.';
    if(caracter[l+1][c] == ' '){
        resposta = labirinto(lf, cf, caracter, l+1, c);
        if(resposta==1){
            return 1;
        }
    }
    if(caracter[l-1][c] == ' '){
        resposta = labirinto(lf, cf, caracter, l-1, c);
        if(resposta==1){
            return 1;
        }
    }
    if(caracter[l][c+1] == ' '){
        resposta = labirinto(lf, cf, caracter, l, c+1);
        if(resposta==1){
            return 1;
        }
    }
    if(caracter[l][c-1] == ' '){
        resposta = labirinto(lf, cf, caracter, l, c-1);
        if(resposta==1){
            return 1;
        }
    }
    caracter[l][c] = ' ';
    return 0;
}

int main(int argc, char *argv[]) {

    FILE *arq = fopen(argv[1], "r");
    if(!arq){
        return 0;
    }
    char caracter;
    int tam_arquivo=0;

    fscanf(arq, "%c", &caracter);
    while (!feof(arq)){
        tam_arquivo++;
        fscanf(arq, "%c", &caracter);
    }

    char valores[tam_arquivo];
    int l=0, c, count=0;
    fseek(arq, 0, SEEK_SET);
    for (int i = 0; i < tam_arquivo; ++i) {
        fscanf(arq, "%c", &caracter);
        valores[i] = caracter;
        if(valores[i] == '\n')
            l++;
    }
    fclose(arq);

    l++; //pois como ta contando pelos \n, a ultima linha n tem \n
    c = (tam_arquivo+1)/l; //+1 pois considerando o ultimo \n q n é digitado

    char matriz[l][c];
    //passando de vetor para matriz (matriz com coluna para os \n)
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if(count == tam_arquivo){
                matriz[i][j] = '\n';
            }else{
                matriz[i][j] = valores[count];
                count++;
            }
        }
    }

    // ///////////////////////////////////////////////////////




    //imprimindo labirinto em matriz
//    for (int i = 0; i < l; ++i) {
//        for (int j = 0; j < c; ++j) {
//            printf("%c", matriz[i][j]);
//        }
//    }

//    printf("\n");
//    printf("qtd caracter: %d\n", tam_arquivo);
//    printf("qtd linhas: %d\n", l);
//    printf("qtd colunas: %d", c);
//    printf("\n-------------------------------\n");

    matriz[1][0] = '.'; //entrada
    labirinto(l, c,  matriz, 1, 1);
    //imprimindo labirinto em matriz
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c-1; ++j) {
            printf("%c", matriz[i][j]);
        }
        if(i!=(l-1)){
            printf("\n");
        }
    }

    return 0;
}