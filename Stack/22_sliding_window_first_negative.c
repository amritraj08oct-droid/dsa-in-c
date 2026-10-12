#include <stdio.h>

#define MAX 100

void printFirstNegative(int arr[], int n, int k) {
    int queue[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        /* Store indices of negative elements. */
        if (arr[i] < 0)
            queue[++rear] = i;

        /* Remove indices that are outside this window. */
        while (front <= rear && queue[front] <= i - k)
            front++;

        if (i >= k - 1) {
            if (front <= rear)
                printf("%d ", arr[queue[front]]);
            else
                printf("0 ");
        }
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

    printf("First negative in each window (0 if none): ");
    printFirstNegative(arr, n, k);
    printf("\n");

    return 0;
}
