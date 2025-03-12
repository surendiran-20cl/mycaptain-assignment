#include <stdio.h>

int main() {
    int matrix[3][3];  // Declare a 3x3 matrix
    int *ptr = &matrix[0][0];  // Pointer to the first element
    int i, j, sum = 0;

    // Input values into the matrix using a pointer
    printf("Input elements in the matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", (ptr + i * 3 + j));  // Accessing elements using pointer
        }
    }

    // Print the matrix using pointer
    printf("The matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", *(ptr + i * 3 + j));
        }
        printf("\n");
    }

    // Calculate the sum of diagonal elements
    for (i = 0; i < 3; i++) {
        sum += *(ptr + i * 3 + i);  // Primary diagonal (matrix[i][i])
        if (i != (2 - i)) //avoids adding matrix[1][1] twice
        {
            sum += *(ptr + i * 3 + (2 - i));  // Secondary diagonal (matrix[i][2-i])
        }
    }

    // Print sum of diagonal elements
    printf("Sum of diagonal elements = %d\n", sum);

    return 0;
}


