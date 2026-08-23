#include <stdio.h>

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int found = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("%d found at index %d\n", target, found);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
