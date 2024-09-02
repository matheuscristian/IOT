#include <stdio.h>

void insertion_sort(int *arr, int s) {
    int key, j;
    for (int i = 1; i < s; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int s;
    scanf("%d", &s);

    int arr[s + 10];
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, s);

    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
