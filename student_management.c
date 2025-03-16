#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;
    }

    Student new_student;
    new_student.id = student_count + 1;

    printf("Enter student name: ");
    scanf(" %[^\n]", new_student.name);

    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa);

    students[student_count] = new_student;
    student_count++;

    printf("Student added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent List:\n");
    printf("ID\tName\t\tGPA\n");
    printf("--------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void search_student() {
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("GPA: %.2f\n", students[i].gpa);
            return;
        }
    }

    printf("Student with ID %d not found.\n", search_id);
}

void delete_student() {
    int delete_id;
    printf("Enter student ID to delete: ");
    scanf("%d", &delete_id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == delete_id) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student with ID %d deleted successfully.\n", delete_id);
            return;
        }
    }

    printf("Student with ID %d not found.\n", delete_id);
}

void save_to_file() {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&student_count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), student_count, file);
    fclose(file);

    printf("Student data saved to file successfully.\n");
}

void load_from_file() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No existing student data found.\n");
        return;
    }

    fread(&student_count, sizeof(int), 1, file);
    fread(students, sizeof(Student), student_count, file);
    fclose(file);

    printf("Student data loaded from file successfully.\n");
}

int main() {
    int choice;

    load_from_file();

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Save Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                save_to_file();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}