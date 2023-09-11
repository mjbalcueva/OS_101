#include <stdio.h>
#include <stdlib.h>

int getProcessCount()
{
  int processCount;
  printf("\nEnter number of processes: ");
  scanf("%d", &processCount);
  return processCount;
}

void getBurstTime(int processCount, int processID[], int burstTime[])
{
  for (int i = 0; i < processCount; i++)
  {
    printf("Enter burst time for process #%d: ", i + 1);
    scanf("%d", &burstTime[i]);
    processID[i] = i + 1;
  }
}

void sortBurstTime(int processCount, int processID[], int burstTime[])
{
  int position, temp;

  for (int i = 0; i < processCount; i++)
  {
    position = i;
    for (int j = i + 1; j < processCount; j++)
    {
      if (burstTime[j] < burstTime[position])
        position = j;
    }

    temp = burstTime[i];
    burstTime[i] = burstTime[position];
    burstTime[position] = temp;

    temp = processID[i];
    processID[i] = processID[position];
    processID[position] = temp;
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

void printResults(int processCount, int processID[], int burstTime[], int waitingTime[], int turnaroundTime[])
{
  float avgWaitTime, avgTurnaroundTime, totalWaitTime = 0, totalTurnaroundTime = 0;

  puts("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
  for (int i = 0; i < processCount; i++)
  {
    totalWaitTime += waitingTime[i];
    totalTurnaroundTime += turnaroundTime[i];
    printf("\nP%d\t\t%d\t\t%d\t\t%d", processID[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
  }

  avgWaitTime = totalWaitTime / processCount;
  avgTurnaroundTime = totalTurnaroundTime / processCount;
  printf("\n\nAverage Waiting Time = %.2f", avgWaitTime);
  printf("\nAverage Turnaround Time = %.2f\n", avgTurnaroundTime);
}

void fcfs()
{
  int processCount = getProcessCount();
  int processID[processCount], burstTime[processCount], waitingTime[processCount], turnaroundTime[processCount];

  getBurstTime(processCount, processID, burstTime);
  getWaitingTime(processCount, burstTime, waitingTime);
  getTurnaroundTime(processCount, burstTime, waitingTime, turnaroundTime);
  printResults(processCount, processID, burstTime, waitingTime, turnaroundTime);
}

void sjf()
{
  int processCount = getProcessCount();
  int processID[processCount], burstTime[processCount], waitingTime[processCount], turnaroundTime[processCount];

  getBurstTime(processCount, processID, burstTime);
  sortBurstTime(processCount, processID, burstTime);
  getWaitingTime(processCount, burstTime, waitingTime);
  getTurnaroundTime(processCount, burstTime, waitingTime, turnaroundTime);
  printResults(processCount, processID, burstTime, waitingTime, turnaroundTime);
}

void exitProgram()
{
  puts("\nExiting program...");
  exit(0);
}

int main()
{
  int choice;
  puts("\nWhat do you want to do?");
  puts("1. FCFS");
  puts("2. SJF");
  puts("3. Exit");
  printf("Enter option number: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    fcfs();
    break;
  case 2:
    sjf();
    break;
  case 3:
    exitProgram();
    break;
  }
  puts("\n-----------------------------------------------------------------");
  main();
  return 0;
}