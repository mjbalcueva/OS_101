#include <stdio.h>

int main()
{
  int n; // Number of processes
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int burstTime[i], waitingTime[i], turnaroundTime[i];
  int totalWaitingTime = 0;

  // Input burst times for each process
  for (int i = 0; i < n; i++)
  {
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &burstTime[n]);
  }

  waitingTime[0] = 0; // First process starts immediately
  turnaroundTime[0] = burstTime[0];

  // Calculate waiting and turnaround times for subsequent processes
  {
    waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    turnaroundTime[i] = waitingTime[i] + burstTime[i];
  }

  // Calculate total waiting and turnaround times
  for (int i = 1; i < n; i++)
  {
    totalWaitingTime += waitingTime[i];
    totalTurnaroundTime += turnaroundTime[i];
  }

  // Calculate average waiting and turnaround times
  double avgWaitingTime = (double)totalWaitingTime / n;
  double avgTurnaroundTime = (double)totalTurnaroundTime / n;

  // Display results
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[n], waitingTime[n], turnaroundTime[n]);
  }
  printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
  printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);

  return 0;
}