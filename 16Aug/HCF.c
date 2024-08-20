// write a program to find HCF.

#include <stdio.h>
#include <conio.h>

int hcf(int a, int b) {
    if (b == 0) {
        return a;
    }
    return hcf(b, a % b);
}

void main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("HCF of %d and %d is %d", a, b, hcf(a, b));
    getch();
}