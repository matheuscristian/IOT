#include <stdio.h>

int main() {
    int num1, num2, i, mmc;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    for (i = 1; i <= num1 * num2; i++) {
        if (i % num1 == 0 && i % num2 == 0) {
            mmc = i;
            break;
        }
    }

    printf("O MMC de %d e %d é: %d\n", num1, num2, mmc);

    return 0;
}