#include<stdio.h>
#include<conio.h>

void BubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void main(){
    int arr[10];
    printf("Enter the number of elements: ");
    for(int i=0; i<10; i++)
        scanf("%d", &arr[i]);
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, n);
    printf("Sorted array: \n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    getch();
}