/*
 * Name: Asadbek
 * Surname: Rakhmatillaev
 * Student ID: 251ADB073
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
  char name[50];
  int id;
  float gpa;
} Student;

// Safe line reader helper
int read_line(char* buf, int size) {
  if (fgets(buf, size, stdin) == NULL) {
    return 0;
  }
  buf[strcspn(buf, "\r\n")] = 0;
  return 1;
}

int load_students(Student arr[], int max) {
  FILE* fp = fopen("students.txt", "r");
  if (fp == NULL) {
    return 0;  // First run or file doesn't exist yet
  }
  char line[256];
  int count = 0;
  while (fgets(line, sizeof(line), fp) != NULL && count < max) {
    line[strcspn(line, "\r\n")] = 0;
    if (strlen(line) == 0) continue;

    char name[50];
    int id;
    float gpa;
    if (sscanf(line, "%49[^,],%d,%f", name, &id, &gpa) == 3) {
      strcpy(arr[count].name, name);
      arr[count].id = id;
      arr[count].gpa = gpa;
      count++;
    }
  }
  fclose(fp);
  return count;
}

int save_students(const Student arr[], int count) {
  FILE* fp = fopen("students.txt", "w");
  if (fp == NULL) {
    return -1;
  }
  for (int i = 0; i < count; i++) {
    if (fprintf(fp, "%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa) < 0) {
      fclose(fp);
      return -1;
    }
  }
  fclose(fp);
  return 0;
}

void add_student(Student arr[], int* count) {
  if (*count >= MAX_STUDENTS) {
    printf("Cannot add more students (limit reached).\n");
    return;
  }

  char name_buf[100];
  char id_buf[100];
  char gpa_buf[100];

  printf("Enter name: ");
  if (read_line(name_buf, sizeof(name_buf)) == 0 || strlen(name_buf) == 0) {
    printf("Invalid input. Student not added.\n");
    return;
  }
  if (strchr(name_buf, ',') != NULL) {
    printf("Invalid input. Student not added.\n");
    return;
  }

  printf("Enter ID: ");
  if (read_line(id_buf, sizeof(id_buf)) == 0) {
    printf("Invalid input. Student not added.\n");
    return;
  }
  char* endptr;
  long id = strtol(id_buf, &endptr, 10);
  if (*endptr != '\0' || endptr == id_buf || id <= 0) {
    printf("Invalid input. Student not added.\n");
    return;
  }

  printf("Enter GPA: ");
  if (read_line(gpa_buf, sizeof(gpa_buf)) == 0) {
    printf("Invalid input. Student not added.\n");
    return;
  }
  float gpa = strtof(gpa_buf, &endptr);
  if (*endptr != '\0' || endptr == gpa_buf || gpa < 0.0f || gpa > 4.0f) {
    printf("Invalid input. Student not added.\n");
    return;
  }

  strcpy(arr[*count].name, name_buf);
  arr[*count].id = (int)id;
  arr[*count].gpa = gpa;
  (*count)++;
  printf("Student added successfully!\n");
}

void list_students(const Student arr[], int count) {
  if (count == 0) {
    printf("No students found.\n");
    return;
  }
  printf("ID    Name                 GPA\n");
  for (int i = 0; i < count; i++) {
    printf("%-5d %-20s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
  }
}

int main(void) {
  Student students[MAX_STUDENTS];
  int count = load_students(students, MAX_STUDENTS);
  printf("Loaded %d student(s) from students.txt\n", count);

  char input[100];
  int choice = 0;

  while (1) {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");

    if (read_line(input, sizeof(input)) == 0) {
      break;
    }
    choice = atoi(input);

    if (choice == 1) {
      list_students(students, count);
    } else if (choice == 2) {
      add_student(students, &count);
    } else if (choice == 3) {
      save_students(students, count);
      printf("Data saved. Goodbye!\n");
      break;
    } else {
      printf("Invalid option.\n");
    }
  }

  return 0;
}