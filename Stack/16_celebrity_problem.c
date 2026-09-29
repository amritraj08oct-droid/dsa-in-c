#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop(void) {
    return stack[top--];
}

int main(void) {
    int knows[MAX][MAX];
    int n, i, j, a, b, candidate;
    int isCelebrity = 1;

    printf("Enter number of people: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of people.\n");
        return 1;
    }

    printf("Enter the relationship matrix (1 = knows, 0 = does not know):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &knows[i][j]);
    }

    for (i = 0; i < n; i++)
        push(i);

    while (top > 0) {
        a = pop();
        b = pop();

        if (knows[a][b])
            push(b);
        else
            push(a);
    }

    candidate = pop();

    for (i = 0; i < n; i++) {
        if (i == candidate)
            continue;

        if (knows[candidate][i] || !knows[i][candidate]) {
            isCelebrity = 0;
            break;
        }
    }

    if (isCelebrity)
        printf("Celebrity is person %d.\n", candidate);
    else
        printf("No celebrity found.\n");

    return 0;
}
