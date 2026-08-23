#include <stdio.h>

int main(void) {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int position = 2;
    int value = 25;

    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    n++;

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
