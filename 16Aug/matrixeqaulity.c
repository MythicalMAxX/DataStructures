// write a program to determine two matrix are equal or not.

#include <stdio.h>
#include <conio.h>

void main() {
    int a[10][10], b[10][10], i, j, r1, c1, r2, c2, flag = 1;

    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 != r2 || c1 != c2) {
        printf("Matrices are not equal");
        getch();
        return;
    }

    printf("Enter the elements of first matrix: ");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of second matrix: ");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            if (a[i][j] != b[i][j]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag) {
        printf("Matrices are equal");
    } else {
        printf("Matrices are not equal");
    }

    getch();
}
