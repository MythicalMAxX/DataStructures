// there is a stare case with n steps we need to reach the  top and we can either climb one step or two step at a time. how many distinct we can rearch at the top of the stair cases

#include <stdio.h>
#include <conio.h>

int countWays(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return countWays(n - 1) + countWays(n - 2);
}

void main() {
    int n;
    printf("Enter the number of stairs: ");
    scanf("%d", &n);
    printf("Number of ways to reach the top: %d", countWays(n));
    getch();
}