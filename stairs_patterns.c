#include <stdio.h>

int main() {
    int n = 6;  // Number of stairs

    for (int i = 1; i <= n; i++) {  // Outer loop: controls rows
        for (int j = 1; j <= i; j++) {  // Inner loop: controls "01" repetition
            printf("01");
        }
        printf("\n");  // Move to the next line after each row
    }

    return 0;
}
