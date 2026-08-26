#include <stdio.h>

int main() {
    int n, target, found = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break;
        }
    }

    if (found != -1)
        printf("Element found at index %d.\n", found);
    else
        printf("Element not found.\n");

    return 0;
}
