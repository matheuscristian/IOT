#include <math.h>
#include <stdio.h>

int main() {
  int base, exponent, result = 1;
  printf("Enter base number: ");
  scanf("%d", &base);
  printf("Enter exponent: ");
  scanf("%d", &exponent);

  printf("%d", (int)pow(base, exponent));

  return 0;
}