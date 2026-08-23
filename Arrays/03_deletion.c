#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int position = 2;

    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
