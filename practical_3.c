#include <stdio.h>
#include <string.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[50];

    while(i <= mid && j <= high) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while(i <= mid) {
        temp[k++] = a[i++];
    }
    while(j <= high) {
        temp[k++] = a[j++];
    }
    for(i = low, k = 0; i <= high; i++, k++) {
        a[i] = temp[k];
    }
}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    char city[6][20] = {"Delhi", "Kolkata", "Agra", "Mumbai", "Jaipur", "Chennai"};
    int i, j, min;
    char temp[20];

    printf("--- Selection Sort (Cities) ---\nOriginal array: ");
    for(i = 0; i < 6; i++) printf("%s ", city[i]);
    printf("\n");

    for(i = 0; i < 5; i++) {
        min = i;
        for(j = i + 1; j < 6; j++) {
            if(strcmp(city[j], city[min]) < 0) {
                min = j;
            }
        }
        strcpy(temp, city[i]);
        strcpy(city[i], city[min]);
        strcpy(city[min], temp);
    }

    printf("Final sorted cities: ");
    for(i = 0; i < 6; i++) printf("%s ", city[i]);
    printf("\n\n");

    int a[] = {4, 2, 7, 5, 3, 8, 1, 6, 33, 67, 23, 26, 12};
    int n = 13;

    printf("--- Merge Sort (Delivery Days) ---\nOriginal array: ");
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    mergeSort(a, 0, n - 1);

    printf("Final sorted delivery days: ");
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
