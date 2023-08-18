#include <stdio.h>

void get_burst_time(int n, int burst_time[])
{
  for (int i = 0; i < n; i++)
  {
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
  }
}

void get_waiting_time(int n, int burst_time[], int waiting_time[])
{
  waiting_time[0] = 0;

  for (int i = 1; i < n; i++)
  {
    waiting_time[i] = 0;
    for (int j = 0; j < i; j++)
    {
      waiting_time[i] += burst_time[j];
    }
  }
}

void print_table(int n, int burst_time[], int waiting_time[])
{
  printf("\nProcess\t   Burst Time   \tWaiting Time\tTurnaround Time");
  for (int i = 0; i < n; i++)
  {
    printf("\n%d\t\t%d\t\t%d\t\t%d", i + 1, burst_time[i], waiting_time[i], burst_time[i] + waiting_time[i]);
  }
}

void print_avg_time(int n, int burst_time[], int waiting_time[])
{
  int total = 0;
  float avg_wait_time, avg_turnaround_time;

  for (int i = 0; i < n; i++)
  {
    total += waiting_time[i];
  }

  avg_wait_time = (float)total / n;
  total = 0;

  for (int i = 0; i < n; i++)
  {
    total += burst_time[i] + waiting_time[i];
  }

  avg_turnaround_time = (float)total / n;

  printf("\n\nAverage waiting time = %.2f", avg_wait_time);
  printf("\nAverage turn around time = %.2f", avg_turnaround_time);
}

int main()
{
  int n;

  printf("Enter number of process: ");
  scanf("%d", &n);

  int burst_time[n], waiting_time[n];

  get_burst_time(n, burst_time);
  get_waiting_time(n, burst_time, waiting_time);
  print_table(n, burst_time, waiting_time);
  print_avg_time(n, burst_time, waiting_time);

  return 0;
}