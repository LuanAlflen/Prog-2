#include <stdio.h>
#include <string.h>

int main() {
    int i, count=0;
    char text[50], words[6][20] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"}, linguage[6][20] = {"INGLES", "ESPANHOL", "ALEMAO", "FRANCES", "ITALIANO", "RUSSO"};;

    //printf("Digite a frase:\n");
    gets(text);
    while (text[0] != '#'){
        for(i=0;i<6;i++){
            if(strcmp(text, words[i]) == 0){
                printf("Caso %i: %s\n", i+1, linguage[i]);
                count++;
            }
        }
        if(count == 0){
            printf("Caso 7: DESCONHECIDO\n");
        }
        count=0;
        gets(text);
    }

    return 0;
}
