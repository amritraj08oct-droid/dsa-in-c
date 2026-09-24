#include <stdio.h>

#define MAX 100

int main(void) {
    int price[MAX], span[MAX], stack[MAX];
    int n, top = -1, i;

    printf("Enter number of days: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of days.\n");
        return 1;
    }

    printf("Enter stock prices: ");
    for (i = 0; i < n; i++)
        scanf("%d", &price[i]);

    for (i = 0; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }

    printf("Stock spans: ");
    for (i = 0; i < n; i++)
        printf("%d ", span[i]);

    printf("\n");
    return 0;
}
