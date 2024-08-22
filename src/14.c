#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("O primeiro número agora é: %d\n", a);
    printf("O segundo número agora é: %d\n", b);

    return 0;
}