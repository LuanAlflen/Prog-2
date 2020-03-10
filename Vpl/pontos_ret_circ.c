#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, qnt_ret=0, qnt_circ=0, qnt_fig;
    float fig[10][5];
    char c;
    scanf("%c ",&c);

    for(i=0;i<10;i++){
        for(j=0;j<5;j++){
            fig[i][j] = 0;
        }
    }

    while(c != '*'){
        qnt_fig = qnt_circ +qnt_ret;
        if (qnt_fig<=10) {
            if (c == 'r') {
                    fig[qnt_fig][0] = 0;
                    for (j = 1; j < 5; j++) {
                        scanf("%f ", &fig[qnt_fig][j]);
                    }
                    qnt_ret++;
            }
            if (c == 'c') {
                    fig[qnt_fig][0] = 1;
                    for (j = 1; j < 4; j++) {
                        scanf("%f ", &fig[qnt_fig][j]);
                    }
                    qnt_ret++;
            }

        }
        scanf("%c",&c);
    }
    qnt_fig = qnt_circ +qnt_ret;
    /*
    for(i=0;i<qnt_fig;i++){
        for(j=0;j<5;j++){
            printf("%f,",fig[i][j]);
        }
        printf("\n");
    }*/

    float x, y, dist_dos_pontos;
    int pontos=1, contido=0;
    scanf("%f %f", &x, &y);

    while(x != 666 && y != 666){
        for(i=0;i<qnt_fig;i++) {
            if (fig[i][0] == 0.0) {
                // -----------------   RETANGULO --------------------------------------------------------
                if (fig[i][1] <= x && fig[i][3] >= x && fig[i][2] >= y && fig[i][4] <= y) {
                    printf("Ponto %i contido na figura %i\n", pontos, i + 1);
                    contido = 1;
                }
            }
            if (fig[i][0] == 1.0) {
                // ================= CIRCULO ===========================================
                dist_dos_pontos = sqrt((fig[i][1]-x)*(fig[i][1]-x)+(fig[i][2]-y)*(fig[i][2]-y));
                if(dist_dos_pontos<=fig[i][3]){
                    printf("Ponto %i contido na figura %i\n", pontos, i + 1);
                    contido = 1;
                }
                //printf("distancia: %f\nraio: %f\n", dist_dos_pontos, fig[i][3]);
            }
        }
        if(contido == 0){
                printf("Ponto %i nao esta contido em nenhuma figura\n",pontos);
            }
        contido = 0;
        pontos++;
        scanf("%f %f", &x, &y);

    }

    return 0;
}