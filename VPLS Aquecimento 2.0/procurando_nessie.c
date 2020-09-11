#include <stdio.h>

int main() {

    int n, a, b, sonarh, sonarv, sonar;

    scanf("%i\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%i %i", &a, &b);
        sonarh = a/3;
        sonarv = b/3;
        sonar = sonarh*sonarv;
        printf("%i\n", sonar);
    }

    return 0;
}
