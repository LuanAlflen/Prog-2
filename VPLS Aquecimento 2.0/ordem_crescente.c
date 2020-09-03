#include <stdio.h>

int main() {
    int i, number1, number2, n, count=0;

    scanf("%i", &n);

    scanf("%i", &number1);
    for (i = 0; i < n-1; ++i) {
        scanf("%i", &number2);
        if(number1<number2){
            count++;
        }
        number1 = number2;
    }
    if (count == n-1){
        printf("SIM");
    }else{
        printf("NAO");
    }

    return 0;
}