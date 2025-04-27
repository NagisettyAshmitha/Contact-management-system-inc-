
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[100];
int count = 0;

// Add contact
void addContact() {
    if (count >= 100) {
        printf("Phonebook is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^
]", contacts[count].name);
    printf("Enter phone number: ");
    scanf(" %[^
]", contacts[count].phone);
    count++;
    printf("Contact added!\n");
}

// Display all contacts
void displayContacts() {
    if (count == 0) {
        printf("No contacts.\n");
        return;
    }
    printf("\nContact List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

// Search contact by name
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^
]", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Update contact by name
void updateContact() {
    char name[50];
    printf("Enter name to update: ");
    scanf(" %[^
]", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new name: ");
            scanf(" %[^
]", contacts[i].name);
            printf("Enter new phone number: ");
            scanf(" %[^
]", contacts[i].phone);
            printf("Contact updated!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Delete contact by name
void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf(" %[^
]", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) addContact();
        else if (choice == 2) displayContacts();
        else if (choice == 3) searchContact();
        else if (choice == 4) updateContact();
        else if (choice == 5) deleteContact();
        else if (choice == 6) printf("Exiting...\n");
        else printf("Invalid choice. Try again.\n");

    } while (choice != 6);

    return 0;
}
