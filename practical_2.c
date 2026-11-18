#include <stdio.h>

int main() {
    int arr[] = {73, 67, 34, 4, 56, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, temp;
    int comparisons = 0, swaps = 0, passes = 0;
    int swapped;

    printf("Original Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    for(i = 0; i < n - 1; i++) {
        swapped = 0;
        passes++;
        printf("Pass %d: ", passes);
        
        for(j = 0; j < n - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }

        for(int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");

        if(swapped == 0) {
            printf("Early termination occurred at pass %d (Array is already sorted).\n", passes);
            break;
        }
    }

    printf("\nFinal Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n--- Analysis ---\n");
    printf("Passes = %d\n", passes);
    printf("Comparisons = %d\n", comparisons);
    printf("Swaps = %d\n", swaps);

    return 0;
}
