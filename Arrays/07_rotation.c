#include <stdio.h>

void reverse(int arr[], int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp;
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;
    k %= n;

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
