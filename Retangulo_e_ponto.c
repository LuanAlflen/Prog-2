/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int i, j, qnt_ret=0;
    float ret[10][4];
    char c;
    //printf("Digite a matriz:");
    scanf("%c",&c);
    for(i=0;i<10;i++){
        while(c != '*'){
            while(c == 'r'){
                    for(j=0;j<4;j++){
                        printf("[%i][%i]: ",i,j);
                        scanf("%f",&ret[i][j]);
                    }
                scanf("%c",&c);
            }
            qnt_ret++;
            scanf("%c",&c);
        }
    }
    float x, y;
    printf("quantidade dos retangulos é: %i\n",qnt_ret);
    scanf("%f %f", &x, &y);
    
    while(x != 666 && y != 666){
        for(i=0;i<qnt_ret;i++){
            for(j=0;j<4;j++){
                if(ret[i][j] <= x && ret[i][j+2] >= x && ret[i][j+1] <= y && ret[i][j+3] >= y){
                printf("O ponto(%f,%f) esta contido em retangulo %i\n",x,y,i);
                }
            }
        }
        scanf("%f %f", &x, &y);
    }
    printf("Fim");

    return 0;
}
