#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX], n, k;
    long long sum = 0;

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

    for (int i = 0; i < k; i++)
        sum += arr[i];

    printf("Average of each window: ");
    printf("%.2f ", (double)sum / k);

    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        printf("%.2f ", (double)sum / k);
    }

    printf("\n");
    return 0;
}
