/*
 * Name: Asadbek
 * Surname: Rakhmatillaev
 * Student ID: 251ADB073
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  const char* filename = "data.txt";
  if (argc > 1) {
    filename = argv[1];
  }

  printf("Writing lines to %s...\n", filename);
  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file for writing");
    return 1;
  }

  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");
  fclose(fp);

  printf("Reading contents:\n");
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return 1;
  }

  char buffer[256];
  int lines_read = 0;
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
    lines_read++;
  }
  fclose(fp);

  printf("Lines read: %d\n", lines_read);
  return 0;
}