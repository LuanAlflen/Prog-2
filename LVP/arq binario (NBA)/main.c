#include "nba_stats.c"

int main(){

    int qtd_jogadores;
    /*
     * 1
    qtd_jogadores = le_cabecario("jogadores.dat");
    printf("quantidade de jogadores: %d\n", qtd_jogadores);
    */

    qtd_jogadores=0;
    // ///////2
    jogador_t *informacoes = le_jogadores("jogadores.dat", &qtd_jogadores);
    //printf("quantidade de jogadores: %d\n", qtd_jogadores);
    /*for (int i = 0; i < qtd_jogadores; ++i) {
        printf("%s \n", informacoes[i].nome);
    }*/
    int indice;
    /*
    // ///////3
    indice= statj_mais_arremessos(informacoes, qtd_jogadores, 'T');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
     */
    //printf("%s com %d arremessos.\n", informacoes[indice].nome, informacoes[indice].aT.arremessos);//tem q mudar aT aqui tbm caso muda o parametro

    /*
    // ///////4
    indice= statj_mais_cestas(informacoes, qtd_jogadores, '2');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
    */

    /*
    // ///////5
    indice= statj_melhor_percentual(informacoes, qtd_jogadores, '3');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
    */

    /*
    // ///////6
    indice= statj_jogos(informacoes, qtd_jogadores, '+');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
    */

    /*
    // ///////7
    indice= statj_idade(informacoes, qtd_jogadores, '+');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
    */

    /*
    // ///////8
    indice= statj_minutos(informacoes, qtd_jogadores, '+');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
    */

    /*
    // ///////9
    indice= statj_pontos(informacoes, qtd_jogadores, '+');
    printf("Indice: %d\n", indice);
    printf("Nome: %s.\n", informacoes[indice].nome);
    */
    float media;int soma;
    /*
    // ///////10

    soma= statt_soma_pontos(informacoes, qtd_jogadores, "GSW");
    printf("Soma: %d\n", soma);
    */


    // ///////11
    media= statt_media_pontos(informacoes, qtd_jogadores, "PHI");
    printf("Media: %f\n", media);



    // ///////12
    media= statt_media_idade(informacoes, qtd_jogadores, "PHI");
    printf("Media: %f\n", media);


    /*
    // ///////13
    soma= statt_posicao(informacoes, qtd_jogadores, "PHI", "SG");
    printf("Soma: %d\n", soma);
    */






    return 0;
}