#include<conio.h>
#include<stdio.h>

int InsertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main() {
    int arr[10];
    printf("Enter the number of elements: ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    getch();
}