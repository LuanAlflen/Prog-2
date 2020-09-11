#include <stdio.h>
#include <string.h>

int main() {
    char text[128];
    int tam, primeiro_aspas=0;

    while (fgets(text, 128, stdin)){
        //text[strlen(text)-1] = '\0';
        tam = strlen(text);
        for (int i = 0; i < tam; ++i) {
            if (text[i] == '"'){
                if(primeiro_aspas == 0){
                    printf("``");
                    primeiro_aspas++;
                }else{
                    printf("''");
                    primeiro_aspas--;
                }
            }else{
                printf("%c", text[i]);
            }
        }
    }


    return 0;
}
