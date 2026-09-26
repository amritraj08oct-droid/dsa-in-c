#include <stdio.h>

#define MAX 100

int main(void) {
    int heights[MAX], stack[MAX];
    int n, top = -1, i;
    int maxArea = 0, area, height, width;

    printf("Enter number of bars: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of bars.\n");
        return 1;
    }

    printf("Enter bar heights: ");
    for (i = 0; i < n; i++)
        scanf("%d", &heights[i]);

    for (i = 0; i <= n; i++) {
        int current = (i == n) ? 0 : heights[i];

        while (top != -1 && heights[stack[top]] > current) {
            height = heights[stack[top--]];
            width = (top == -1) ? i : i - stack[top] - 1;
            area = height * width;

            if (area > maxArea)
                maxArea = area;
        }

        if (i < n)
            stack[++top] = i;
    }

    printf("Largest rectangle area = %d\n", maxArea);

    return 0;
}
