// check string is palindrome or not

#include <stdio.h>
#include <conio.h>

void main() {
    char str[100];
    int i, len, flag = 0;

    printf("Enter a string: ");
    gets(str);

    for (len = 0; str[len] != '\0'; len++);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("The string is not a palindrome.");
    } else {
        printf("The string is a palindrome.");
    }

    getch();
}