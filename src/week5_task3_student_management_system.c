// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // TODO: Load existing data from file using load_students()

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                    list_students(students, count);
                break;
            case 2:
                    add_student(students, &count);
                break;
            case 3:
                    save_students(students, count);
                    printf("Data saved. Exiting\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    FILE *file = fopen(DATA_FILE, "r");
    if (!file) {
        // If file doesn't exist, start with zero students
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%49s %d %f", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
        if (count >= MAX_STUDENTS) {
            printf("Maximum student limit reached.\n");
            break;
        }
    }
    fclose(file);
    return count;
}

// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *file = fopen(DATA_FILE, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    fclose(file);
}

// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    Student new_student;
    printf("Enter name: ");
    fgets(new_student.name, NAME_LEN, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; // Remove newline
    printf("Enter ID: ");
    scanf("%d", &new_student.id);
    printf("Enter GPA: ");
    scanf("%f", &new_student.gpa);
    getchar(); // clear newline
    arr[*count] = new_student;
    (*count)++;
    printf("Student added successfully.\n");
}

// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %d, GPA: %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
}
