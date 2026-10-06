#include <stdio.h>

#define MAX 100

void printMax(int arr[], int n, int k) {
    int deque[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        while (front <= rear && deque[front] <= i - k)
            front++;

        while (front <= rear && arr[deque[rear]] <= arr[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            printf("%d ", arr[deque[front]]);
    }
}

int main() {
    int arr[MAX], n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter window size: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid window size.\n");
        return 0;
    }

    printf("Maximum of each window: ");
    printMax(arr, n, k);

    printf("\n");
    return 0;
}
