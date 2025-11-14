#include <stdio.h>
#include <stdlib.h>

void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    char name[50];
    int roll;

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Name: ");
    scanf("%s", name);

    fprintf(fp, "%d %s\n", roll, name);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.txt", "r");
    int roll;
    char name[50];

    printf("\n--- Student List ---\n");
    while (fscanf(fp, "%d %s", &roll, name) != EOF) {
        printf("Roll: %d  Name: %s\n", roll, name);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

}
