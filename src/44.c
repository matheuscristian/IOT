#include <stdio.h>

int main() {
    
    int x, y, i, j;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            printf("(%d, %d): ", x, y);
            for (i = -2; i <= 2; i += 4) {
                for (j = -1; j <= 1; j += 2) {
                    if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8) {
                        printf("(%d, %d) ", x + i, y + j);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
