/*
 * Name: Asadbek
 * Surname: Rakhmatillaev
 * Student ID: 251ADB073
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

int save_student_binary(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) return -1;
  if (fwrite(s, sizeof(Student), 1, fp) != 1) {
    fclose(fp);
    return -1;
  }
  fclose(fp);
  return 0;
}

int load_student_binary(const char* filename, Student* out) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) return -1;
  if (fread(out, sizeof(Student), 1, fp) != 1) {
    fclose(fp);
    return -1;
  }
  fclose(fp);
  return 0;
}

long file_size(const char* filename) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) return -1;
  if (fseek(fp, 0, SEEK_END) != 0) {
    fclose(fp);
    return -1;
  }
  long size = ftell(fp);
  fclose(fp);
  return size;
}

int main(void) {
  Student s = {0};
  snprintf(s.name, sizeof(s.name), "Alice");
  s.age = 21;
  s.gpa = 3.75;

  printf("Saving student in binary format...\n");
  if (save_student_binary(&s, "student.bin") != 0) {
    perror("Error saving binary");
    return 1;
  }

  FILE* tfp = fopen("student.txt", "w");
  if (tfp) {
    fprintf(tfp, "%s %d %.2f\n", s.name, s.age, s.gpa);
    fclose(tfp);
  }

  printf("Loading student from binary file...\n");
  Student loaded = {0};
  if (load_student_binary("student.bin", &loaded) != 0) {
    perror("Error loading binary");
    return 1;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);

  long txt_size = file_size("student.txt");
  long bin_size = file_size("student.bin");

  printf("Text file size: %ld bytes\n", txt_size);
  printf("Binary file size: %ld bytes\n", bin_size);

  return 0;
}