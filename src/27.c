#include <stdio.h>

int main() {
  int m1[10][10], m2[10][10], result[10][10];
  int r1, c1, r2, c2, i, j, k;

  printf("Digite o número de linhas da primeira matriz: ");
  scanf("%d", &r1);
  printf("Digite o número de colunas da primeira matriz: ");
  scanf("%d", &c1);

  printf("Digite o número de linhas da segunda matriz: ");
  scanf("%d", &r2);
  printf("Digite o número de colunas da segunda matriz: ");
  scanf("%d", &c2);

  // Verifique se as colunas da primeira matriz são iguais às linhas da segunda matriz
  if (c1 != r2) {
    printf("As matrizes não podem ser multiplicadas.\n");
    return 1;
  }

  printf("Digite os elementos da primeira matriz:\n");
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c1; ++j) {
      printf("Digite o elemento [%d][%d]: ", i, j);
      scanf("%d", &m1[i][j]);
    }

  printf("Digite os elementos da segunda matriz:\n");
  for (i = 0; i < r2; ++i)
    for (j = 0; j < c2; ++j) {
      printf("Digite o elemento [%d][%d]: ", i, j);
      scanf("%d", &m2[i][j]);
    }

  // Inicialize a matriz resultante com zeros
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c2; ++j) {
      result[i][j] = 0;
    }

  // Multiplique as matrizes
  for (i = 0; i < r1; ++i) {
    for (j = 0; j < c2; ++j) {
      for (k = 0; k < c1; ++k) {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }

  printf("A matriz resultante é:\n");
  for (i = 0; i < r1; ++i) {
    for (j = 0; j < c2; ++j) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}