/*
 * week4_2_struct_student.c
 * Author: Samar Joshi
 * Student ID: 241ADB043
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
// Example:
// struct Student {
//     char name[50];
//     int id;
//     float grade;
// };
struct Student {
     char name[50];
     int id;
     float grade;
 };

int main(void) {
    // TODO: Create a couple of Student instances,(Unable to declare and assign value as i am getting error of redeclaration of 'student1' so i did both at once)
    // TODO: Assign values (either manually or via scanf)
    struct  Student student1 = {"Samar", 242, 99.9};
    struct  Student student2 = {"Alex", 241, 100};

    // TODO: Print struct contents using printf
printf("%s\t%d\t%.2f\n", student1.name, student1.id,
    student1.grade);
    printf("%s\t%d\t%.2f\n", student2.name, student2.id,
    student2.grade);
    return 0;
}
