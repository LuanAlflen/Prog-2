#include <stdio.h>
#include <string.h>

//1
int fatorial (int n) {
   if(n == 0) return 1;
   else return n*fatorial(n-1);

//2
}
//2
void intervalo(int x, int y){
    if(x==y) {
        printf("%d", x);
        return;
    }
    else{
        printf("%d ", x);
        return intervalo(x+1, y);
    }
}
//3
int soma_desde_1(int n){
    if(n==1)return 1;
    else{
        return n+soma_desde_1(n-1);
    }
}//perguntar se precisa considerar os negativos
//4
void intervalo_com_incremento(int x, int y, int i){
    if(x>=y) {
        return;
    }
    else{
        printf("%d ", x);
        return intervalo_com_incremento(x+i, y, i);
    }
}
//5
int exponencial(int base, int expoente){
    if(expoente==0) return 1;
    else return base*exponencial(base, expoente-1);
}//perguntar se precisa considerar expoente negativo
//6
int soma_vetor(int *v, int tam){
    if(tam==0) return 0;
    else return v[tam-1]+soma_vetor(v, tam-1);
}
//7
void imprime_vetor_auxiliar(int *v, int tam, int posicao){ //valor de posição é a partir da onde ele imprime
    if(tam==posicao) return;
    else {
        printf("%d ", v[posicao]);
        imprime_vetor_auxiliar(v, tam, posicao +1);
    }
}
void imprime_vetor(int *v, int tam){ //valor de posição é a partir da onde ele imprime
    imprime_vetor_auxiliar(v, tam, 0);
    }
//8
void imprime_vetor_reverso(int *v, int tam){
    if(tam==0) return;
    else {
        printf("%d ", v[tam-1]);
        imprime_vetor_reverso(v, tam - 1);
    }
}
//9
int* reverte_vetor_auxiliar(int *v, int tam, int parcial){
    int aux;
    aux = v[tam];
    v[tam] = v[parcial];
    v[parcial] = aux;
    if(tam==parcial)return v;
    return reverte_vetor_auxiliar(v, tam-1, parcial+1);

}
int* reverte_vetor(int *v, int tam){
    return reverte_vetor_auxiliar(v, tam-1, 0);
}
//10
int multiplicacao(int x, int y){ //precisa considerar os negativos?
    if(x==0 || y ==0) {
        return 0;
    }
    else{
        return y+multiplicacao(x-1, y);
    }
}
//11
int divisor_comum_auxiliar(int x, int y, int parcial){//parcial sempre começa em 1
    if(y==0)return x;
    if(x==0)return divisor_comum_auxiliar(y, x%y, parcial);

    if(parcial > x || parcial > y) return 1;
    int p1 = x%parcial;
    int p2 = y%parcial;
    if(p1 == 0 && p2 == 0) return parcial*divisor_comum_auxiliar(y/parcial, x/parcial, parcial+1);
    else return 1*divisor_comum_auxiliar(y, x, parcial+1);

}
int divisor_comum(int x, int y){
    return divisor_comum_auxiliar(x, y, 1);

}
//12
void palindroma_auxiliar (char *str, unsigned int tam, int parcial) {
    if (tam <= parcial) {
        printf("Palindroma");
        return;
    }else{
        if (str[tam] != str[parcial])
            printf("Nao eh palindroma");
        return palindroma_auxiliar(str, tam-1, parcial+1);
    }
}
void palindroma (char *str) {
    palindroma_auxiliar(str, strlen(str) - 1, 0);
}
//13
int fibonati_auxiliar(int n, int num1, int num2, int i){//i é uma variavel parcial q começa em 0, num1 e num2 são o inicio da sequencia de fibonati (geralmente 0, 1) onde num1<num2
    if(n == i) return num2;
    return fibonati_auxiliar(n, num2, num1+num2, i+1);
}
int fibonati(int n){
    return fibonati_auxiliar(n, 0, 1, 0);
}


int main()
{
    int resposta;
    //teste fatorial
    resposta = fatorial(5);
    printf("fatoria 5: %d\n", resposta);

    //teste intervalo
    printf("intervalo (-3, 8):\n");
    intervalo(-3, 8);

    //teste soma
    resposta = soma_desde_1(3);
    printf("\nsoma desde 1 de 3: %d\n", resposta);

    //teste intervalo com incremento
    printf("intervalo com incremento(-3, 10, 2):\n");
    intervalo_com_incremento(3, 10, 2);

    //teste exponencial
    resposta = exponencial(-3, 3);
    printf("\nexponencial -3^3: %d\n", resposta);

    //teste soma dos valores do vetor
    int vetor[] = {2, 4, 7, 0, -4};
    resposta = soma_vetor(vetor, 5);
    printf("soma elementor vetor: %d\n", resposta);

    //teste imprime vetor
//    int vetor[] = {2, 4, 7, 0, -4};
    printf("imprime vetor:\n");
    imprime_vetor(vetor, 5);

    //teste imprime vetor ao contrario
//    int vetor[] = {2, 4, 7, 0, -4};
    printf("\nimprime vetor reverso:\n");
    imprime_vetor_reverso(vetor, 5);

    //teste vetor reverso
//    int vetor[] = {2, 4, 7, 0, -4};
    int *array;
    array = reverte_vetor(vetor, 5);
    printf("\nreverte vetor: \n");
    imprime_vetor(array, 5);


    //teste multiplicação
    resposta = multiplicacao(7, 7);
    printf("\nmulti. 7x7: %d\n", resposta);

    //teste divisor comum
    resposta = divisor_comum(6, 9);
    printf("divisor comum (6, 9): %d", resposta);

    //teste palindroma
    char str[] = "ana";
    printf("\nteste palindroma: ");
    palindroma(str);

    //teste fibonati
    resposta = fibonati(6);
    printf("\nfibonati(6): %d\n", resposta);


    return 0;
}