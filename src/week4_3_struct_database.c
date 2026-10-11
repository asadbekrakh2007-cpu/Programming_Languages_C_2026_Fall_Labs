#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Same definition as in Task 2. */
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void)
{
    int n;

    printf("Enter number of students: ");

    /* Reject non-numbers, 0 and negative counts. */
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    /* Guard against n * sizeof overflowing size_t, which would make malloc return a too-small block. */
    if ((size_t)n > SIZE_MAX / sizeof(struct Student)) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    struct Student *students = malloc((size_t)n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);

        /* %49s leaves room for the '\0' in the 50-byte name buffer, preventing overflow. */
        if (scanf("%49s %d %f", students[i].name, &students[i].id, &students[i].grade) != 3) {
            /* Free before leaving so the error path does not leak. */
            free(students);
            printf("Invalid input.\n");
            return 1;
        }
    }

    /* One empty line, then the table header and the rows in input order. */
    printf("\n");
    printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-11s %.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    /* Optional bonus output AFTER the table. */
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    printf("Average grade = %.2f\n", total / n);

    free(students);
    return 0;
}
