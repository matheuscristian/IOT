#include <stdio.h>

int main() {
  int decimal, binary, remainder, i = 1, j;

  printf("Digite um número decimal: ");
  scanf("%d", &decimal);

  binary = 0;
  while (decimal != 0) {
    remainder = decimal % 2;
    decimal /= 2;
    binary += remainder * i;
    i *= 10;
  }

  printf("O número binário é: ");
  for (j = i / 10; j > 1; j /= 10) {
    printf("%d", binary / j % 10);
  }
  printf("%d\n", binary % 10);

  return 0;
}