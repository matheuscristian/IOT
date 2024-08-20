#include <stdio.h>

int main() {
    int a, b;

    printf("Digite dois número: ");
    scanf("%d %d", &a, &b);

    printf("O maior deles é o: %d\n", a > b ? a : b);

    return 0;
}
