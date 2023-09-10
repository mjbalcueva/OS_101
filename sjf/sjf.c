#include <stdio.h>

void get_burst_time(int process_count, int process_id[], int burst_time[])
{
  for (int i = 0; i < process_count; i++)
  {
    printf("Enter burst time for processes #%d: ", i + 1);
    scanf("%d", &burst_time[i]);
    process_id[i] = i + 1;
  }
}

void sort_burst_time(int process_count, int process_id[], int burst_time[])
{
  int position, temp;

  for (int i = 0; i < process_count; i++)
  {
    position = i;
    for (int j = i + 1; j < process_count; j++)
    {
      if (burst_time[j] < burst_time[position])
        position = j;
    }

    temp = burst_time[i];
    burst_time[i] = burst_time[position];
    burst_time[position] = temp;

    temp = process_id[i];
    process_id[i] = process_id[position];
    process_id[position] = temp;
  }
}

void get_waiting_time(int process_count, int burst_time[], int waiting_time[])
{
  waiting_time[0] = 0;

  for (int i = 1; i < process_count; i++)
  {
    waiting_time[i] = 0;
    for (int j = 0; j < i; j++)
    {
      waiting_time[i] += burst_time[j];
    }
  }
}

void print_results(int process_count, int process_id[], int burst_time[], int waiting_time[], int turnaround_time[])
{
  float avg_wait_time, avg_turnaround_time, total_wait_time = 0, total_turnaround_time = 0;

  printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
  for (int i = 0; i < process_count; i++)
  {
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    total_wait_time += waiting_time[i];
    total_turnaround_time += turnaround_time[i];
    printf("\nP%d\t\t%d\t\t%d\t\t%d", process_id[i], burst_time[i], waiting_time[i], turnaround_time[i]);
  }

  avg_wait_time = total_wait_time / process_count;
  avg_turnaround_time = total_turnaround_time / process_count;
  printf("\n\nAverage Waiting Time = %.2f", avg_wait_time);
  printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
}

int main()
{
  int process_count;

  printf("Enter number of process: ");
  scanf("%d", &process_count);

  int process_id[process_count], burst_time[process_count], waiting_time[process_count], turnaround_time[process_count];

  get_burst_time(process_count, process_id, burst_time);
  sort_burst_time(process_count, process_id, burst_time);
  get_waiting_time(process_count, burst_time, waiting_time);
  print_results(process_count, process_id, burst_time, waiting_time, turnaround_time);

  return 0;
}