#include <stdio.h>

int binarySearch(int a[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void) {
    int a[] = {10, 20, 30, 40, 50};
    int index = binarySearch(a, 5, 40);
    printf("Index = %d\n", index);
    return 0;
}
