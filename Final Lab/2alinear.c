#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count, n;

int linear(int arr[], int key, int size)
{
  for (int i = 0; i < size; i++)
  {
    count++;
    if (arr[i] == key)
    {
      break;
    }
  }
  return count;
}

int main()
{
  int size = 10;
  FILE *fp;
  fp = fopen("linear.txt", "w");
  srand(time(NULL));
  while (size < 110)
  {
    int arr[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = rand() % 100;
    }
    for (int i = 0; i < size; i++)
    {
      printf("%d\t", arr[i]);
    }
    printf("\n");
    // Best
    count = 0;
    int result1 = linear(arr, arr[0], size);
    // Avg
    count = 0;
    int result2 = linear(arr, arr[size / 2], size);
    // Worst
    count = 0;
    int result3 = linear(arr, 101, size);
    fprintf(fp, "%d\t%d\t%d\t%d\n", size, result1, result2, result3);
    size += 10;
  }
  fclose(fp);
}
