#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  /* Ask for the number of elements. */
  printf("Enter number of elements: ");

  /* scanf returns 1 only if a valid integer was read; reject non-numbers, 0 and
   * negatives. */
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  /* Allocate room for n ints; sizeof(int) keeps the code portable. */
  int* numbers = malloc((size_t)n * sizeof(int));
  if (numbers == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers: ", n);

  /* Use a wide type for the sum so many large ints cannot overflow it. */
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &numbers[i]) != 1) {
      /* Free before exiting so the error path does not leak memory. */
      free(numbers);
      printf("Invalid input.\n");
      return 1;
    }
    sum += numbers[i];
  }

  /* Cast to double BEFORE dividing, otherwise integer division would truncate
   * (7 8 -> 7.00). */
  double average = (double)sum / n;

  printf("Sum = %lld\n", sum);
  printf("Average = %.2f\n", average);

  /* Every successful malloc needs a matching free. */
  free(numbers);
  return 0;
}
