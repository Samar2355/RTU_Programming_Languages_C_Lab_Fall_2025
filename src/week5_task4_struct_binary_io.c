
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    save_student(s1, filename);
    printf("Saving Student in binary format \n");
    printf("Loading Student in binary format\n");
    Student s2 = load_student(filename);

    printf("Loaded Student: Name= %s, Age= %d, GPA= %.2f\n", s2.name, s2.age, s2.gpa);

    return 0;
}

void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }
    fprintf(fp, "%s\n%d\n%.2f\n", s.name, s.age, s.gpa);
    fclose(fp);
}


Student load_student (const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s for reading.\n", filename);

        s.name[0] = '\0';
        s.age = 0;
        s.gpa = 0.0f;
        return s;
    }
    fscanf(fp, "%49[^\n]\n%d\n%f\n", s.name, &s.age, &s.gpa);
    fclose(fp);
    return s;
}