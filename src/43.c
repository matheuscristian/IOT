#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);

    int v[s + 10];
    for (int i = 0; i < s; i++) {
        scanf("%d", &v[i]);
    }

    int l = 0, r = 0, l_m, r_m, c = 1, c_m = 0;
    for (int i = 1; i < s; i++) {
        if (v[i] - 1 == v[i - 1]) {
            r = i;
            c++;

            if (c > c_m) {
                c_m = c;
                l_m = l;
                r_m = r;
            }
        } else {
            l = i;
            c = 1;
        }
    }

    printf("%d %d %d\n", l_m, r_m, c_m);

    for (int i = l_m; i <= r_m; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
