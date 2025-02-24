#include <stdio.h>
#include <stdlib.h>

int i, j; // Declaring i and j outside loops

// Function to create and write to a file
void createFile() {
    char filename[100], text[1000];
    FILE *fp;

    printf("Enter file name to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "w"); // Open in write mode
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    printf("Enter text (Type 'EXIT' to save & exit):\n");
    getchar(); // Consume newline
    while (1) {
        fgets(text, sizeof(text), stdin);
        if (text[0] == 'E' && text[1] == 'X' && text[2] == 'I' && text[3] == 'T') {
            break;
        }
        fputs(text, fp);
    }

    fclose(fp);
    printf("File saved successfully!\n");
}

// Function to open and read a file
void openFile() {
    char filename[100], ch;
    FILE *fp;

    printf("Enter file name to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return;
    }

    printf("\n--- File Opened ---\n");
    while ((ch = fgetc(fp)) != EOF) { 
        putchar(ch);  // Display file content properly
    }
    printf("\n--- End of File ---\n");

    fclose(fp);
}

// Function to display the content of a file
void displayFile() {
    char filename[100], ch;
    FILE *fp;

    printf("Enter file name to display: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return;
    }

    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fp)) != EOF) { 
        putchar(ch);  // Display file content properly
    }
    printf("\n--- End of File ---\n");

    fclose(fp);
}

// Function to append text to a file
void appendFile() {
    char filename[100], text[1000];
    FILE *fp;

    printf("Enter file name to append: ");
    scanf("%s", filename);

    fp = fopen(filename, "a"); // Open in append mode
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return;
    }

    printf("Enter text to append (Type 'EXIT' to save & exit):\n");
    getchar(); // Consume newline
    while (1) {
        fgets(text, sizeof(text), stdin);
        if (text[0] == 'E' && text[1] == 'X' && text[2] == 'I' && text[3] == 'T') {
            break;
        }
        fputs(text, fp);
    }

    fclose(fp);
    printf("File updated successfully!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n===== SIMPLE TEXT EDITOR =====\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Append to File\n");
        printf("4. Display File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                openFile();
                break;
            case 3:
                appendFile();
                break;
            case 4:
                displayFile();
                break;
            case 5:
                printf("Exiting the Text Editor...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

