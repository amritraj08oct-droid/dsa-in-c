#include <stdio.h>

int main(void) {
    int graph[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) printf("%d ", graph[i][j]);
        printf("\n");
    }
    return 0;
}
