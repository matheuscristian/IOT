#include <stdio.h>

int main() {
  int s, v;
  printf("Digite o tamanho da string: ");
  scanf("%d", &s);

  char str[s];
  printf("Digite a string: ");
  scanf("%s", str);

  for (int i = 0; i < s; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u') {
      v++;
    }
  }

  printf("A string possui %d vogais.\n", v);

  return 0;
}
