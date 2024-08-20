// find maximum and minimum occouring character In a string

#include <stdio.h>
#include <conio.h>

void main() {
    char str[100];
    int i, j, len, max, min;
    int freq[256];

    printf("Enter a string: ");
    gets(str);

    for (i = 0; i < 256; i++) {
        freq[i] = 0;
    }

    for (i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    max = 0;
    min = 0;

    for (i = 0; i < 256; i++) {
        if (freq[i] > freq[max]) {
            max = i;
        }
        if (freq[i] < freq[min] && freq[i] != 0) {
            min = i;
        }
    }

    printf("Maximum occouring character is %c\n", max);
    printf("Minimum occouring character is %c\n", min);

    getch();
}

