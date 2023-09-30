#include <stdio.h>
#include <stdlib.h>

int getArraySize(const char *text)
{
  int arraySize;
  printf("Enter the number of %s: ", text), scanf("%d", &arraySize);
  return arraySize;
}

int *getArrayElements(const char *sizeOfText, const char *text, int arraySize)
{
  int *array = (int *)malloc(arraySize * sizeof(int));

  printf("\nEnter the sizes of the %s:\n", sizeOfText);
  for (int i = 0; i < arraySize; i++)
    printf("%s #%d: ", text, i + 1), scanf("%d", &array[i]);
  return array;
}

void firstFit(int blocks[], int blocksSize, int files[], int filesSize)
{
  int allocation[filesSize], transferred[filesSize];
  for (int i = 0; i < filesSize; i++)
  {
    allocation[i] = transferred[i] = -1;
    for (int j = 0; j < blocksSize; j++)
      if (blocks[j] >= files[i])
      {
        allocation[i] = j;
        transferred[i] = files[i];
        blocks[j] -= files[i];
        break;
      }
  }

  puts("\nFile Allocation using First-Fit:");
  puts("File Number\tFile Size\tBlock Number\tTransferred File Size");
  for (int i = 0; i < filesSize; i++)
  {
    printf("%d\t\t%d\t\t", i + 1, files[i]);
    if (allocation[i] != -1)
      printf("%d\t\t%d\n", allocation[i] + 1, transferred[i]);
    else
      puts("Not Allocated\t-");
  }
}

int main()
{
  int blocksCount = getArraySize("memory blocks");
  int filesCount = getArraySize("files");
  int *memoryBlocks = getArrayElements("memory blocks", "Block", blocksCount);
  int *files = getArrayElements("files", "File", filesCount);

  firstFit(memoryBlocks, blocksCount, files, filesCount);
  free(memoryBlocks);
  free(files);

  return 0;
}