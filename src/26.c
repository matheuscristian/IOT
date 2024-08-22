#include <stdio.h>

int main() {
  int m, n, i, j;
  printf("Digite o número de linhas das matrizes: ");
  scanf("%d", &m);
  printf("Digite o número de colunas das matrizes: ");
  scanf("%d", &n);

  int matriz1[m][n], matriz2[m][n], soma[m][n];

  printf("Digite os elementos da primeira matriz:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matriz1[i][j]);
    }
  }

  printf("Digite os elementos da segunda matriz:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matriz2[i][j]);
    }
  }

  // Somar as matrizes
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      soma[i][j] = matriz1[i][j] + matriz2[i][j];
    }
  }

  printf("A matriz resultante da soma é:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", soma[i][j]);
    }
    printf("\n");
  }

  return 0;
}