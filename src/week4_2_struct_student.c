/*
 * week4_2_struct_student.c
 * Author: Asadbek Rakhmatillaev
 * Student ID: 251ADB073
 * Description:
 *   Demonstrates defining and using a struct in C.
 */

#include <stdio.h>
#include <string.h>

// Define struct Student
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    // Declare two Student variables
    struct Student s1;
    struct Student s2;

    // Assign values for Student 1
    strcpy(s1.name, "Alice Johnson");
    s1.id = 1001;
    s1.grade = 9.1f;

    // Assign values for Student 2
    strcpy(s2.name, "Bob Smith");
    s2.id = 1002;
    s2.grade = 8.7f;

    // Print each student in the required format
    printf("Student 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

    return 0;
}
