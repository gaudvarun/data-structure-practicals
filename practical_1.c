#include <stdio.h>

// Linear Search
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary Search (Iterative)
int binarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int a[] = {56, 3, 249, 518, 7, 26, 94, 651, 23, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 9;

    printf("--- Linear Search ---\n");
    int linResult = linearSearch(a, n, x);
    if (linResult != -1)
        printf("Element %d found at index %d\n", x, linResult);
    else
        printf("Element %d not found\n", x);

    int sortedArr[] = {3, 7, 9, 11, 23, 31, 33, 65, 68};
    int n2 = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int key = 31;

    printf("\n--- Binary Search ---\n");
    int binResult = binarySearch(sortedArr, n2, key);
    if (binResult != -1)
        printf("Element %d found at index %d\n", key, binResult);
    else
        printf("Element %d not found\n", key);

    return 0;
}
