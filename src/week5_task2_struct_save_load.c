/*
 * Name: Asadbek
 * Surname: Rakhmatillaev
 * Student ID: 251ADB073
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

int save_student(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    return -1;
  }
  if (fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa) < 0) {
    fclose(fp);
    return -1;
  }
  fclose(fp);
  return 0;
}

int load_student(const char* filename, Student* out) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }
  if (fscanf(fp, "%49s %d %f", out->name, &(out->age), &(out->gpa)) != 3) {
    fclose(fp);
    return -1;
  }
  fclose(fp);
  return 0;
}

int main(void) {
  Student s = {"Alice", 21, 3.75};
  const char* filename = "student.txt";

  printf("Saving student to file...\n");
  if (save_student(&s, filename) != 0) {
    perror("Error saving student");
    return 1;
  }

  printf("Loading student from file...\n");
  Student loaded;
  if (load_student(filename, &loaded) != 0) {
    perror("Error loading student");
    return 1;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);
  return 0;
}