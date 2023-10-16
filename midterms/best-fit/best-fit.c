#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int count, *sizes;
} Object;

typedef struct
{
  int fileID, fileSize, blockID, blockSize, transferredFileSize, remainingBlockSize;
} Process;

int getArraySize(const char *text)
{
  int count;
  printf("Enter the number of %s: ", text), scanf("%d", &count);
  return count;
}

int *getArrayElements(const char *sizeOfText, const char *text, int count)
{
  int *array = (int *)malloc(count * sizeof(int));
  printf("\nEnter the sizes of the %s:\n", sizeOfText);
  for (int i = 0; i < count; i++)
    printf("%s #%d: ", text, i + 1), scanf("%d", &array[i]);
  return array;
}

void bestFit(Object block, Object file, Process *processes)
{
  for (int i = 0; i < file.count; i++)
  {
    processes[i].fileID = i + 1;
    processes[i].fileSize = file.sizes[i];

    int min = __INT_MAX__;
    for (int j = 0; j < block.count; j++)
      if (block.sizes[j] >= file.sizes[i] && block.sizes[j] < min)
        min = block.sizes[j];

    for (int j = 0; j < block.count; j++)
    {
      if (block.sizes[j] == min)
      {
        processes[i].blockID = j + 1;
        processes[i].blockSize = block.sizes[j];
        processes[i].transferredFileSize = file.sizes[i];
        processes[i].remainingBlockSize = block.sizes[j] - file.sizes[i];
        block.sizes[j] -= file.sizes[i];
        break;
      }
    }
  }
}

void printOutput(int processCount, Process *processes)
{
  printf("\n%-18s%-18s%-18s%-18s%-18s%-18s\n", "File IDs", "File Size", "Block IDs", "Block Size", "Transferred FS", "Remaining BS");
  for (int i = 0; i < processCount; i++)
  {
    printf("%-18d%-18d", processes[i].fileID, processes[i].fileSize);
    if (processes[i].blockID == 0)
      printf("%-18s%-18s%-18s%-18s\n", "Not Allocated", "Not Allocated", "Not Allocated", "Not Allocated");
    else
      printf("%-18d%-18d%-18d%-18d\n", processes[i].blockID, processes[i].blockSize, processes[i].transferredFileSize, processes[i].remainingBlockSize);
  }
}

int main()
{
  Object block = {0, NULL}, file = {0, NULL};
  block.count = getArraySize("memory blocks");
  file.count = getArraySize("files");
  block.sizes = getArrayElements("memory blocks", "block", block.count);
  file.sizes = getArrayElements("files", "file", file.count);
  Process *processes = (Process *)malloc(file.count * sizeof(Process));

  bestFit(block, file, processes);
  printOutput(file.count, processes);
  free(block.sizes);
  free(file.sizes);
  free(processes);

  return 0;
}