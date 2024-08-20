#include <stdio.h>

int main() {
  float num1, num2, num3, average;

  printf("Digite o primeiro número: ");
  scanf("%f", &num1);

  printf("Digite o segundo número: ");
  scanf("%f", &num2);

  printf("Digite o terceiro número: ");
  scanf("%f", &num3);

  average = (num1 + num2 + num3) / 3;

  printf("A média dos três números é: %.2f\n", average);

  return 0;
}