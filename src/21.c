#include <stdio.h>

int main() {
  int n, i, x, found = 0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int vetor[n];
  printf("Digite os elementos do vetor:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &vetor[i]);
  }
  printf("Digite o elemento a ser buscado: ");
  scanf("%d", &x);
  for (i = 0; i < n; i++) {
    if (vetor[i] == x) {
      found = 1;
      printf("Elemento encontrado na posição %d\n", i);
      break;
    }
  }
  if (!found) {
    printf("Elemento não encontrado no vetor\n");
  }
  return 0;
}