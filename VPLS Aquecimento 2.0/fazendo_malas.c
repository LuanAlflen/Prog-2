#include <stdio.h>

int main() {

    int n, a, l, c;
    scanf("%i", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%i %i %i", &a, &l, &c);
        if(a <=20 && l <=20 && c <= 20){
            printf("Caso %i: good\n", i+1);
        }else{
            printf("Caso %i: bad\n", i+1);
        }
    }

    return 0;
}
