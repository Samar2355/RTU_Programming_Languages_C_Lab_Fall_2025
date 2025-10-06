#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Student with fields name, id, grade
struct student {
    char name[50];
    int id;
    float grade;
};
typedef struct student Student;

int main(void) {
    int n;
    Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Allocate memory for n Student structs using malloc
    students = (Student*)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("Enter name, id, and grade for student %d: ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade);
    }

    // Display all student records in formatted output
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", students[i].name, students[i].id, students[i].grade);
    }

    // Free allocated memory
    free(students);

    return 0;
}
