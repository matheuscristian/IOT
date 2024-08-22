#include <stdio.h>

int busca_binaria(int vetor[], int n, int x) {
  int inicio = 0;
  int fim = n - 1;
  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;
    if (vetor[meio] == x) {
      return meio;
    } else if (vetor[meio] < x) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

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
  found = busca_binaria(vetor, n, x);
  if (found == -1) {
    printf("Não foi encontrado o elemento %d no vetor.\n", x);
  } else {
    printf("O elemento %d foi encontrado na posição %d do vetor.\n", x, found);
  }
  return 0;
}