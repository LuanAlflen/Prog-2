
#include <stdio.h>
#include <math.h>

int main() {
    int i, n, number, soma, number_atual, num_q_ja_passou[25],count=0;
    double number_separado[11] ;
    scanf("%i", &n);

    for (i = 0; i < n; ++i) {
        //zerando os numeros da lista q ja passou antes de pedir um numero e fazer tudo dnv
        for (int i = 0; i < 25; ++i) {
            num_q_ja_passou[i] = 0;
        }
        count=0;
        scanf("%i", &number);
        //processa o number
        number_atual = number;
        num_q_ja_passou[count] = number;
        count++;
        if (number == 1){
            printf("Entrada #%i: %i e um numero feliz.\n", i+1, number);
        }
        //calcula cada numera, se é feliz ou n
        while (number_atual != 1) {
            //calcula a soma dos quadrados do number armazenando em soma
            for (int j = 10; j >= 0; j--) {
                number_separado[j] = number_atual / pow(10, j);
                number_separado[j] = floor(number_separado[j]);
                number_atual = number_atual - number_separado[j] * pow(10, j);
            }
            soma=0;
            for (int j = 0; j <= 10; ++j) {
                soma = soma + pow(number_separado[j], 2);
            }
            number_atual = soma;
            if (number_atual == 1) {
                printf("Entrada #%i: %i e um numero feliz.\n", i+1, number);
                number_atual = 1;
            }
            //verifica se a soma ja apareceu antes (se sim, é pq ta repetindo)
            for (int k = 0; k < 25; ++k) {
                if(number_atual == num_q_ja_passou[k]) {
                    printf("Entrada #%i: %i e um numero infeliz.\n", i + 1, number);
                    number_atual = 1;
                }
            }
            count++;
            num_q_ja_passou[count] = soma;
        }
    }

    return 0;
}
