#include <stdio.h>

int main()
{
    int i, j, qnt_ret=0;
    float ret[10][4];
    char c;
    scanf("%c ",&c);
        while(c != '*'){
            if(c == 'r'){
                        if(qnt_ret <= 10){
                            for(j=0;j<4;j++){
                                scanf("%f ",&ret[qnt_ret][j]);
                            }
                            qnt_ret++;
                        }
            }
            scanf("%c",&c);
        }
    
    float x, y;
    int pontos=1, contido=0;
    //printf("quantidade dos retangulos é: %i\n",qnt_ret);
    scanf("%f %f", &x, &y);
    
    while(x != 666 && y != 666){
        for(i=0;i<qnt_ret;i++){
                if(
                    (ret[i][0] >= x && ret[i][2] <= x) || (ret[i][0] <= x && ret[i][2] >= x) && 
                    (ret[i][1] >= y && ret[i][3] <= y) ||  (ret[i][1] <= y && ret[i][3] >= y)    ){
                printf("O ponto %i esta contido na figura %i\n",pontos, i+1);
                contido=1;
            }
        }
        if(contido == 0){
            printf("O ponto %i nao esta contido em nenhuma figura\n",pontos);
        }
        contido = 0;
        pontos++;
        scanf("%f %f", &x, &y);
    }
    //printf("Fim");


    return 0;
}