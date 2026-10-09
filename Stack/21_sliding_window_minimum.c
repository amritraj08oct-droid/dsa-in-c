#include <stdio.h>

#define MAX 100

void printMin(int arr[], int n, int k) {
    int deque[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        /* Remove indices outside the current window. */
        while (front <= rear && deque[front] <= i - k)
            front++;

        /* Keep indices in increasing order of their values. */
        while (front <= rear && arr[deque[rear]] >= arr[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            printf("%d ", arr[deque[front]]);
    }
}

int main(void) {
    int arr[MAX], n, k;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("Enter window size: ");
    if (scanf("%d", &k) != 1 || k < 1 || k > n) {
        printf("Invalid window size.\n");
        return 1;
    }

    printf("Minimum of each window: ");
    printMin(arr, n, k);
    printf("\n");

    return 0;
}
