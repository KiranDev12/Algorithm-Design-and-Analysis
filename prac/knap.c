#include <stdio.h>

int max(int a, int b)
{
  return (a > b) ? a : b;
}

void main()
{

  int T[20][20], wt[10] = {0}, val[10] = {0}, items, cap, MAX;
  printf("Enter no of items\n");
  scanf("%d", &n);
  printf("Enter Sack capacity\n");
  scanf("%d", &Cap);
  printf("Enter the Weight and Value of items\n");
  for (int i = 1; i < n + 1; i++)
  {
    scanf("%d %d", &Wt[i], &Val[i]);
  }
  printf("Enter no of items\n");
  scanf("%d", &n);
  printf("Enter Sack capacity\n");
  scanf("%d", &Cap);
  printf("Enter the Weight and Value of items\n");
  for (int i = 1; i < n + 1; i++)
  {
    scanf("%d %d", &Wt[i], &Val[i]);
  }
}