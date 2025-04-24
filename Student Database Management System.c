#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    do {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student student;
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter Student GPA: ");
    scanf("%f", &student.gpa);

    students[studentCount++] = student; // Add student to array
    printf("Student added successfully!\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student Found: ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            // Shift remaining students to the left
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--; // Reduce count
            printf("Student with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}
