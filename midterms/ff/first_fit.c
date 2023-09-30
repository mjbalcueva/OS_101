#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getArraySize(const char *text)
{
  int arraySize;
  printf("Enter the number of %s: ", text);
  scanf("%d", &arraySize);
  return arraySize;
}

int getArrayElements(int arraySize, const char *text)
{
  int array[arraySize];
  for (int i = 0; i < arraySize; i++)
  {
    printf("%s #%d: ", text, i + 1);
    scanf("%d", &array[i]);
  }
  return *array;
}

void firstFit(int blocks[], int blocksSize, int files[], int filesSize)
{
  int allocation[filesSize];
  int transferred[filesSize];

  for (int i = 0; i < filesSize; i++)
  {
    allocation[i] = -1;
    transferred[i] = -1;
  }

  for (int i = 0; i < filesSize; i++)
  {
    for (int j = 0; j < blocksSize; j++)
    {
      if (blocks[j] >= files[i])
      {
        allocation[i] = j;
        transferred[i] = files[i];
        blocks[j] -= files[i];
        break;
      }
    }
  }

  printf("\nFile Allocation using First-Fit:\n");
  printf("File Number\tFile Size\tBlock Number\tTransferred File Size\n");
  for (int i = 0; i < filesSize; i++)
  {
    printf("%d\t\t%d\t\t", i + 1, files[i]);
    if (allocation[i] != -1)
    {
      printf("%d\t\t%d\n", allocation[i] + 1, transferred[i]);
    }
    else
    {
      printf("Not Allocated\t-\n");
    }
  }
}

int main()
{
  // int m, n;
  // int blockSize[] = {100, 500, 200, 300, 600};
  // int processSize[] = {212, 417, 112, 426};
  // m = sizeof(blockSize) / sizeof(blockSize[0]);
  // n = sizeof(processSize) / sizeof(processSize[0]);
  // firstFit(blockSize, m, processSize, n);

  int blocksCount = getArraySize("memory blocks");
  int filesCount = getArraySize("files");
  puts("\nEnter the sizes of the memory blocks: ");
  int memoryBlocks = getArrayElements(blocksCount, "Block");
  puts("\nEnter the sizes of the files: ");
  int files = getArrayElements(filesCount, "File");

  firstFit(&memoryBlocks, blocksCount, &files, filesCount);

  return 0;
}