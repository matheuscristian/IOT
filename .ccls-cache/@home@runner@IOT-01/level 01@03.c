#include <stdio.h>

int main() {
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("O número é par\n");
    } else {
        printf("O número é ímpar\n");
    }

    return 0;
}
