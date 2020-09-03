#include <stdio.h>
#include <string.h>

int main() {
    int i, n, tam, count=0;
    char txt[20], numbers[3][20] = {"one", "two", "three"};
    scanf("%i", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s",txt);
        tam = strlen(txt);
        for (int j = 0; j < 3; ++j) {
            count = 0;
            for (int k = 0; k < tam; ++k) {
                    if(txt[k] != numbers [j][k]){
                        count++;
                    }
            }
            if(count<2){
                printf("%i\n", j+1);
            }
        }


    }

    return 0;
}