#include <stdio.h>
#include<conio.h>

void KthLargestElement(int arr[], int n, int k) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Kth largest element is: %d\n", arr[k - 1]);
}

void main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if (k > 0 && k <= n) {
        KthLargestElement(arr, n, k);
    } else {
        printf("Invalid value of k\n");
    }

    getch();
}