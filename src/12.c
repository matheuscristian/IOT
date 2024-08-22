#include <stdio.h>

int main() {
  int n, i, soma = 0;

  printf("Digite um número inteiro: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    soma += i;
  }

  printf("A soma dos primeiros %d números naturais é: %d\n", n, soma);

  return 0;
}