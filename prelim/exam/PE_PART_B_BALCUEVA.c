#include <stdio.h>

int main()
{
  // Matrix for storing Process Id, Burst
  // Time, Average Waiting Time & Average
  // Turn Around Time.
  int A[100][4];
  int i, j, n, total = 0, index, temp; //* fix typo tempp
  float avg_wt, avg_tat;
  printf("Enter number of process: ");
  scanf("%d", &n);
  printf("Enter Burst Time:\n");
  // User Input Burst Time and alloting Process Id.
  for (i = 0; i < n; i++)
  {
    printf("P%d: ", i + 1);
    scanf("%d", &A[i][1]);
    A[i][0] = i + 1;
  }
  // Sorting process according to their Burst Time.
  for (i = 0; i < n; i++)
  {
    index = i;
    for (j = i + 1; j < n; j++)
      if (A[j][1] < A[index][1])
        index = j; //* fix assignment from i to j
    temp = A[i][1];
    A[i][1] = A[index][1];
    A[index][1] = temp;

    temp = A[i][0];
    A[i][0] = A[index][0];
    A[index][0] = temp; //* fix typo tempp
  }
  A[0][2] = 0; //* fix assignment from 1 to 0
  // Calculation of Waiting Times
  for (i = 1; i < n; i++) //* add for loop
  {
    A[i][2] = 0;
    for (j = 0; j < i; j++) // j < i; //* applied j < i instead of i < j
      A[i][2] += A[j][1];
    total += A[i][2];
  }
  avg_wt = (float)total / n;
  total = 0;
  printf("P	 BT	 WT	 TAT\n");
  // Calculation of Turn Around Time and printing the
  // data.
  for (i = 0; i < n; i++) //* change i = 0 from i = 1
  {                       // i = 0
    A[i][3] = A[i][1] + A[i][2];
    total += A[i][3];
    printf("P%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3]); //* fix typo A[i][3] instead of A[i][4]
  }
  avg_tat = (float)total / n;
  printf("Average Waiting Time= %.2f", avg_wt);
  printf("\nAverage Turnaround Time= %.2f", avg_tat);
}