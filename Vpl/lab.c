#include "lab.h"
#include <stdlib.h>
#include <math.h>

/*resposta de implementacao aqui*/

FILE *abre_arquivo(const char *arquivo){
    FILE *ptr_arq = fopen(arquivo, "r"); // temos q incluir .txt ou o propria char ja deve conter? (monitor)
    return ptr_arq;
}

int fecha_arquivo(FILE *arq){
    if(!arq){
        return -1;
    }
    int resp = fclose(arq);
    return resp;
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
    if(!qtd_numeros){
        return NULL;
    }
    FILE *arq = abre_arquivo(arquivo);
    if(!arq){
        //printf("erro ao abrir arquivo\n");
        *qtd_numeros=0;
        return NULL;
    }
    unsigned int tam_arquivo=0;
    double d;
    fscanf(arq, "%lf", &d);

    /*
    while (fscanf(arq, "%lf", &d) != -1){
        tam_arquivo++;
    }
    */
    while (!feof(arq)){
        tam_arquivo++;
        fscanf(arq, "%lf", &d);
    }

    *qtd_numeros = tam_arquivo;
    //printf("qtd caracteres: %i\n", tam_arquivo);
    double *valores = (double*) malloc(sizeof(double)* (*qtd_numeros));

    //
    fseek(arq, 0, SEEK_SET);

    for (unsigned int i = 0; i < tam_arquivo; ++i) {
        fscanf(arq, "%lf", &d);
        valores[i] = d;
    }

    fecha_arquivo(arq);

    return valores;
}

double maior(double* valores, unsigned int qtd_numeros){
    if(valores){
        double maior = valores[0];
        for (unsigned int i = 0; i < qtd_numeros; ++i) {
            if(valores[i] > maior){
                maior = valores[i];
            }
        }
        return maior;
    }
    return HUGE_VAL;
}

double menor(double* valores, unsigned int qtd_numeros){
    if(valores){
        double menor = valores[0];
        for (unsigned int i = 0; i < qtd_numeros; ++i) {
            if(valores[i] < menor){
                menor = valores[i];
            }
        }
        return menor;
    }
    return HUGE_VAL;
}

double media(double* valores, unsigned int qtd_numeros){
    if(valores){
        double media = 0;
        for (unsigned int i = 0; i < qtd_numeros; ++i) {
            media += valores[i];
        }
        return media/qtd_numeros;
    }
    return HUGE_VAL;
}

double desvio(double* valores, unsigned int qtd_numeros){
    if(valores){
        double dp=0, media_v;
        media_v = media(valores, qtd_numeros);
        for (unsigned int i = 0; i < qtd_numeros; ++i) {
            dp += pow((valores[i] - media_v), 2);
        }
        dp = sqrt(dp/(qtd_numeros-1)); //confirmar o -1 (monitor)
        return dp;
    }
    return HUGE_VAL;
}

double amplitude(double* valores, unsigned int qtd_numeros){
    if(valores){
        double maiorf, menorf, ampli;
        maiorf = maior(valores, qtd_numeros);
        menorf = menor(valores, qtd_numeros);
        ampli = maiorf - menorf;
        return ampli;
    }
    return HUGE_VAL;
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
    if(valores){
        if(posicao >= 0 && posicao < qtd_numeros){
            return valores[posicao];
        }else{
            return HUGE_VAL;
        }
    }
    return HUGE_VAL;
}

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
    if(!qtd_repeticao){
        return HUGE_VAL;
    }
    
    if(valores){
        double valor_parcial=0;
        unsigned int repeticao_parcial=0;
        *qtd_repeticao = 0;
        for (unsigned int i = 0; i < qtd_numeros; ++i) {
            for (unsigned int j = 0; j < qtd_numeros; ++j) {
                if(valores[i] == valores[j]){
                    repeticao_parcial++;
                }
            }
            if(i==0){
                valor_parcial = valores[i];
                *qtd_repeticao=repeticao_parcial;
            }
            if(repeticao_parcial>*qtd_repeticao){
                *qtd_repeticao=repeticao_parcial;
                valor_parcial = valores[i];
            }
            repeticao_parcial=0;
        }
        return valor_parcial;

    }
    *qtd_repeticao=0;
    return HUGE_VAL;
}

int main(){


    unsigned int qtd_numeros;
    double *b = le_valores("arq-teste.txt", &qtd_numeros);
    /*for (unsigned int i = 0; i < qtd_numeros; ++i) {
        printf("%lf\n", b[i]);
    }*/

    double number;

    number = maior(b, qtd_numeros);
    printf("maior: %lf\n", number);

    number = menor(b, qtd_numeros);
    printf("menor: %lf\n", number);

    number = media(b, qtd_numeros);
    printf("media: %lf\n", number);

    number = desvio(b, qtd_numeros);
    printf("desvio: %lf\n", number);

    number = amplitude(b, qtd_numeros);
    printf("amplitude: %lf\n", number);

    number = valor(b, qtd_numeros, 2);
    printf("posicao: %lf\n", number);

    unsigned int vezes_repetido;
    number = repetido(b, qtd_numeros, &vezes_repetido);
    printf("mais repetido: %lf\n", number);
    printf("vezes repetido: %d\n", vezes_repetido);

    return 0;
}