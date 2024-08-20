#include <stdio.h>
#include <math.h>

int main() {
  float raio, area;

  printf("Digite o raio da circunferencia: ");
  scanf("%f", &raio);

  area = M_PI * pow(raio, 2);

  printf("A area da circunferencia e: %.2f\n", area);

  return 0;
}