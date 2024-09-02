#include <stdio.h>

void bubble_sort(int *arr, int s) {
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int s;
    scanf("%d", &s);

    int arr[s + 10];
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, s);

    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
