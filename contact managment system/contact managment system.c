#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j; // Declaring i and j outside loops

// Define the structure for a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Function to add a new contact
void addContact() {
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Phone: ");
    scanf("%s", c.phone);
    printf("Enter Email: ");
    scanf("%s", c.email);

    fwrite(&c, sizeof(struct Contact), 1, fp);
    fclose(fp);

    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts() {
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\n===== Contact List =====\n");
    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
        printf("----------------------\n");
    }

    fclose(fp);
}

// Function to search for a contact
void searchContact() {
    struct Contact c;
    char searchName[50];
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");

    if (fp == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcmp(c.name, searchName) == 0) {
            printf("\nContact Found!\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }

    fclose(fp);
}

// Function to edit a contact
void editContact() {
    struct Contact c;
    char searchName[50];
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb+");

    if (fp == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\nEnter name to edit: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcmp(c.name, searchName) == 0) {
            printf("\nEditing Contact...\n");
            printf("Enter New Name: ");
            scanf(" %[^\n]", c.name);
            printf("Enter New Phone: ");
            scanf("%s", c.phone);
            printf("Enter New Email: ");
            scanf("%s", c.email);

            fseek(fp, -sizeof(struct Contact), SEEK_CUR);
            fwrite(&c, sizeof(struct Contact), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Contact updated successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

// Function to delete a contact
void deleteContact() {
    struct Contact c;
    char searchName[50];
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcmp(c.name, searchName) != 0) {
            fwrite(&c, sizeof(struct Contact), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

// Main function with menu
int main() {
    int choice;

    while (1) {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                editContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Exiting Contact Management System...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

