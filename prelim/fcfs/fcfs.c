#include <stdio.h>

void getBurstTime(int processCount, int burstTime[])
{
  for (int i = 0; i < processCount; i++)
  {
    printf("Enter burst time for process #%d: ", i + 1);
    scanf("%d", &burstTime[i]);
  }
}

void getWaitingTime(int processCount, int burstTime[], int waitingTime[])
{
  waitingTime[0] = 0;

  for (int i = 1; i < processCount; i++)
  {
    waitingTime[i] = 0;
    for (int j = 0; j < i; j++)
    {
      waitingTime[i] += burstTime[j];
    }
  }
}

void getTurnaroundTime(int processCount, int burstTime[], int waitingTime[], int turnaroundTime[])
{
  for (int i = 0; i < processCount; i++)
  {
    turnaroundTime[i] = burstTime[i] + waitingTime[i];
  }
}

void printResults(int processCount, int burstTime[], int waitingTime[], int turnaroundTime[])
{
  float avgWaitTime, avgTurnaroundTime, totalWaitTime = 0, totalTurnaroundTime = 0;

  printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
  for (int i = 0; i < processCount; i++)
  {
    totalWaitTime += waitingTime[i];
    totalTurnaroundTime += turnaroundTime[i];
    printf("\nP%d\t\t%d\t\t%d\t\t%d", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
  }

  avgWaitTime = totalWaitTime / processCount;
  avgTurnaroundTime = totalTurnaroundTime / processCount;
  printf("\n\nAverage Waiting Time = %.2f", avgWaitTime);
  printf("\nAverage Turnaround Time = %.2f\n", avgTurnaroundTime);
}

int main()
{
  int processCount;

  printf("Enter number of processes: ");
  scanf("%d", &processCount);

  int burstTime[processCount], waitingTime[processCount], turnaroundTime[processCount];

  getBurstTime(processCount, burstTime);
  getWaitingTime(processCount, burstTime, waitingTime);
  getTurnaroundTime(processCount, burstTime, waitingTime, turnaroundTime);
  printResults(processCount, burstTime, waitingTime, turnaroundTime);

  return 0;
}