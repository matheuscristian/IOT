#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = 1, b = 1, c, i;
    printf("1\n");
    printf("1\n");
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d\n", c);
    }

    printf("%d\n", a);

    return 0;
}
