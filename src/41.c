#include <stdio.h>

int main() {
  char message[1000];

  printf("Digite uma mensagem: ");
  fgets(message, 1000, stdin);

  int shift;
  printf("Digite o valor do deslocamento: ");
  scanf("%d", &shift);

  int i = 0;
  while (message[i] != '\n') {
    message[i] += shift;
    i++;
  }

  printf("%s\n", message);

  return 0;
}
