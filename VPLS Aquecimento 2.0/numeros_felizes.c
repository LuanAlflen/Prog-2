#include <stdio.h>
#include <math.h>

int main() {
    int i, n, number, soma, number_atual;
    double number_separado[9] ;
    scanf("%i", &n);
    for (i = 0; i < n; ++i) {
        scanf("%i", &number);
        //processa o number
        number_atual = number;
        while (number_atual != 1) {
            //calcula a soma dos quadrados do number armazenando em number atual

            for (int j = 8; j >= 0; j--) {
                number_separado[j] = number_atual / pow(10, j);
                number_separado[j] = floor(number_separado[j]);
                number_atual = number_atual - number_separado[j] * pow(10, j);
            }
            soma=0;
            for (int j = 0; j < 8; ++j) {
                soma = soma + pow(number_separado[j], 2);
            }
            //printf("soma é: %i", soma);
            number_atual = soma;
            if (number_atual == 1) {
                printf("Entrada #%i: e um numero feliz.\n", i+1);
            }
            if(number_atual == number){
                printf("Entrada #%i: e um numero infeliz.\n", i+1);
                number_atual = 1;
            }


        }
    }

    return 0;
}