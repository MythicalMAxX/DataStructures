#include <stdio.h>
#include<conio.h>

int trapwater(int arr[], int n) {
    int l = 0, r = n - 1;
    int l_max = 0, r_max = 0;
    int result = 0;
    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] >= l_max) {
                l_max = arr[l];
            } else {
                result += l_max - arr[l];
            }
            l++;
        } else {
            if (arr[r] >= r_max) {
                r_max = arr[r];
            } else {
                result += r_max - arr[r];
            }
            r--;
        }
    }
    return result;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Trapped water: %d\n", trapwater(arr, n));
    getch();
}
