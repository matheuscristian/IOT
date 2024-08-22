#include <stdio.h>

int main() {
  int matriz[2][2];
  int determinante;

  printf("Digite os elementos da matriz 2x2:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  determinante = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

  printf("O determinante da matriz é: %d\n", determinante);

  return 0;
}