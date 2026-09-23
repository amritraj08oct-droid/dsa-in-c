#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX], result[MAX], stack[MAX];
    int n, top = -1, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i])
            top--;

        result[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];
    }

    printf("Next greater elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
    return 0;
}
