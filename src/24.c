#include <stdio.h>
#include <math.h>

int main() {
    long long binary, decimal = 0, i = 0, remainder;
    printf("Digite um número binário: ");
    scanf("%lld", &binary);
    while (binary != 0) {
        remainder = binary % 10;
        decimal += remainder * pow(2, i);
        i++;
        binary /= 10;
    }
    printf("O número decimal equivalente é: %lld\n", decimal);
    return 0;
}