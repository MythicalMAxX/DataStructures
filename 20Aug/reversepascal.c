#include<stdio.h>
#include<conio.h>

void reversepascal(int rows) {
    int coef = 1, space, i, j;

    for (i = rows; i >= 0; i--) {
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0) {
                coef = 1;
            } else {
                coef = coef * (i - j + 1) / j;
            }
            printf("%4d", coef);
        }
        printf("\n");
    }
}

int main(){
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    reversepascal(rows);
    getch();
}