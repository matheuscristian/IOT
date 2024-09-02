#include <stdio.h>

void selection_sort(int *arr, int s) {
    int min;
    for (int i = 0; i < s - 1; i++) {
        min = i;
        for (int j = i + 1; j < s; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int s;
    scanf("%d", &s);

    int arr[s + 10];
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, s);

    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
