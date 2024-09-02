#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen_randint(int min, int max) {
  srand(time(NULL));
  return min + rand() % (max - min + 1);
};

int main() {
  printf("%d\n", gen_randint(1, 100));

  return 0;
}
