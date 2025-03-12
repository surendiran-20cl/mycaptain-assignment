#include <stdio.h>
#include <stdlib.h>

// Structure for customer details
struct Customer {
    int accountNumber;
    char name[50];
    double balance;
};

// Function prototypes
void addCustomer();
void viewCustomers();
void depositMoney();
void withdrawMoney();

// File name for storing data
#define FILENAME "customers.dat"

// Main function
int main() {
    int choice;
    
    while (1) {
        printf("\n===== Banking System =====\n");
        printf("1. Add Customer\n");
        printf("2. View Customers\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: viewCustomers(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: printf("Exiting... Thank you!\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function to add a new customer
void addCustomer() {
    struct Customer c;
    FILE *file = fopen(FILENAME, "ab");

    printf("Enter account number: ");
    scanf("%d", &c.accountNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter initial deposit: ");
    scanf("%lf", &c.balance);

    fwrite(&c, sizeof(struct Customer), 1, file);
    fclose(file);

    printf("Customer added successfully!\n");
}

// Function to view all customers
void viewCustomers() {
    struct Customer c;
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        printf("No customer records found!\n");
        return;
    }

    printf("\nAccount Number\tName\t\tBalance\n");
    printf("----------------------------------------\n");

    while (fread(&c, sizeof(struct Customer), 1, file)) {
        printf("%d\t\t%s\t%.2lf\n", c.accountNumber, c.name, c.balance);
    }

    fclose(file);
}

// Function to deposit money
void depositMoney() {
    struct Customer c;
    FILE *file = fopen(FILENAME, "rb+");
    int accNum, found = 0;
    double amount;

    if (file == NULL) {
        printf("No customer records found!\n");
        return;
    }

    printf("Enter account number to deposit money: ");
    scanf("%d", &accNum);

    while (fread(&c, sizeof(struct Customer), 1, file)) {
        if (c.accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            c.balance += amount;

            fseek(file, -sizeof(struct Customer), SEEK_CUR);
            fwrite(&c, sizeof(struct Customer), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);
    if (found) printf("Amount deposited successfully!\n");
    else printf("Customer not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    struct Customer c;
    FILE *file = fopen(FILENAME, "rb+");
    int accNum, found = 0;
    double amount;

    if (file == NULL) {
        printf("No customer records found!\n");
        return;
    }

    printf("Enter account number to withdraw money: ");
    scanf("%d", &accNum);

    while (fread(&c, sizeof(struct Customer), 1, file)) {
        if (c.accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > c.balance) {
                printf("Insufficient balance!\n");
            } else {
                c.balance -= amount;
                fseek(file, -sizeof(struct Customer), SEEK_CUR);
                fwrite(&c, sizeof(struct Customer), 1, file);
                printf("Amount withdrawn successfully!\n");
            }
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) printf("Customer not found!\n");
}
