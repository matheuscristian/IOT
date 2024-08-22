#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numero_secreto, palpite, tentativas = 0;
  srand(time(NULL));
  numero_secreto = rand() % 100 + 1;
  printf("Bem-vindo ao jogo de adivinhação!\n");
  printf("Eu pensei em um número entre 1 e 100.\n");
  printf("Você tem 10 tentativas para adivinhar.\n");

  do {
    printf("Digite seu palpite: ");
    scanf("%d", &palpite);
    tentativas++;

    if (palpite < numero_secreto) {
      printf("O número secreto é maior.\n");
    } else if (palpite > numero_secreto) {
      printf("O número secreto é menor.\n");
    }
  } while (palpite != numero_secreto && tentativas < 10);

  if (palpite == numero_secreto) {
    printf("Parabéns! Você acertou em %d tentativas!\n", tentativas);
  } else {
    printf("Que pena! O número secreto era %d.\n", numero_secreto);
  }

  return 0;
}