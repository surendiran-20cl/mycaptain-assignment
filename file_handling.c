#include <stdio.h>
#include <stdlib.h>

void reverseFileContent(char *filename);
void copyFileContent(char *sourceFile, char *destinationFile);

int main() {
    char sourceFile[] = "input.txt";  // Source file name
    char destinationFile[] = "output.txt";  // Destination file name

    // Reverse the file content and display it
    reverseFileContent(sourceFile);

    // Copy contents from source file to destination file
    copyFileContent(sourceFile, destinationFile);

    printf("\nContents copied successfully to %s\n", destinationFile);
    return 0;
}

// Function to reverse and display file content
void reverseFileContent(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    // Move to end of file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file); // Get file size
    printf("Reversed Content:\n");

    // Read characters in reverse
    for (long i = fileSize - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        char ch = fgetc(file);
        putchar(ch);
    }

    printf("\n");
    fclose(file);
}

// Function to copy file contents
void copyFileContent(char *sourceFile, char *destinationFile) {
    FILE *src = fopen(sourceFile, "r");
    FILE *dest = fopen(destinationFile, "w");

    if (src == NULL || dest == NULL) {
        printf("Error: Cannot open files.\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);
}
