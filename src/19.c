#include <stdio.h>

int main() {
    int num, i, sum = 0;

    printf("Digite um número: ");
    scanf("%d", &num);

    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (sum == num) {
        printf("%d é um número perfeito.\n", num);
    } else {
        printf("%d não é um número perfeito.\n", num);
    }

    return 0;
}