#define MAX 100

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
    char birthday[15];
    char group[20];  // e.g., Family, Friends, Work

} Contact;

Contact phonebook[MAX];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX) {
        printf("Phonebook full.\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", phonebook[contactCount].name);
    printf("Enter phone: ");
    scanf(" %[^\n]", phonebook[contactCount].phone);
    printf("Enter email: ");
    scanf(" %[^\n]", phonebook[contactCount].email);
    printf("Enter birthday (dd/mm/yyyy): ");
    scanf(" %[^\n]", phonebook[contactCount].birthday);
    printf("Enter group (Family/Friends/Work): ");
    scanf(" %[^\n]", phonebook[contactCount].group);

    contactCount++;
    printf("Contact added successfully!\n");
}
void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts found.\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        printf("\nContact #%d:\n", i + 1);
        printf("Name: %s\nPhone: %s\nEmail: %s\nBirthday: %s\nGroup: %s\nInstagram: %s\nTwitter: %s\n",
               phonebook[i].name, phonebook[i].phone, phonebook[i].email, 
               phonebook[i].birthday, phonebook[i].group);
    }
}
void searchContact() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\nBirthday: %s\nGroup: %s\n",
                   phonebook[i].name, phonebook[i].phone, phonebook[i].email, 
                   phonebook[i].birthday, phonebook[i].group);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}


void modifyContact() {
    char modifyName[50];
    printf("Enter name of contact to modify: ");
    scanf(" %[^\n]", modifyName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, modifyName) == 0) {
            printf("Enter new phone: ");
            scanf(" %[^\n]", phonebook[i].phone);
            printf("Enter new email: ");
            scanf(" %[^\n]", phonebook[i].email);
            printf("Enter new birthday: ");
            scanf(" %[^\n]", phonebook[i].birthday);
            printf("Enter new group: ");
            scanf(" %[^\n]", phonebook[i].group);

            printf("Contact updated.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char deleteName[50];
    printf("Enter name of contact to delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            contactCount--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}
void sortContacts() {
    Contact temp;
    for (int i = 0; i < contactCount - 1; i++) {
        for (int j = i + 1; j < contactCount; j++) {
            if (strcmp(phonebook[i].name, phonebook[j].name) > 0) {
                temp = phonebook[i];
                phonebook[i] = phonebook[j];
                phonebook[j] = temp;
            }
        }
    }
    printf("Contacts sorted by name.\n");
}



int main() {
    int choice;
    do {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n2. View Contacts\n3. Search Contact\n");
        printf("4. Modify Contact\n5. Delete Contact\n6. Sort Contacts\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: modifyContact(); break;
            case 5: deleteContact(); break;
            case 6: sortContacts(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);
    
    return 0;
}