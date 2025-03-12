#include <stdio.h>

#define MAX_EMPLOYEES 20  // Define maximum number of employees

// Define Structure
struct Employee {
    int empno;
    char empname[50];
    char department[50];
    float salary;
};

// Function to Display Employee Details
void displayEmployees(struct Employee emp[], int n) {
    printf("\n%-10s %-15s %-15s %-10s\n", "Emp No", "Name", "Department", "Salary");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-15s %.2f\n", emp[i].empno, emp[i].empname, emp[i].department, emp[i].salary);
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];  // Array of structures
    int n;

    // Get the number of employees (max 20)
    printf("Enter number of employees (max 20): ");
    scanf("%d", &n);

    if (n > MAX_EMPLOYEES || n <= 0) {
        printf("Invalid number of employees!\n");
        return 1;  // Exit the program
    }

    // Input Employee Details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Employee Number: ");
        scanf("%d", &employees[i].empno);
        printf("Employee Name: ");
        scanf(" %[^\n]", employees[i].empname);  // Accepts multi-word input
        printf("Department: ");
        scanf(" %[^\n]", employees[i].department);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Display Employee Details
    displayEmployees(employees, n);

    return 0;
}
