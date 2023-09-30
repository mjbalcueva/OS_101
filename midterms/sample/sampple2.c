#include <stdio.h>

// Function to allocate memory using First-Fit
void firstFit(int blocks[], int m, int files[], int n)
{
  int allocation[n];
  int transferred[n]; // To store the file size that was transferred

  for (int i = 0; i < n; i++)
  {
    allocation[i] = -1; // Initialize allocation array as -1 (unallocated)
  }

  for (int i = 0; i < n; i++)
  {
    transferred[i] = -1; // Initialize transferred array as -1 (no transfer)
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (blocks[j] >= files[i])
      {
        // Allocate file i to block j
        allocation[i] = j;
        transferred[i] = files[i]; // Store the file size that was transferred
        blocks[j] -= files[i];
        break;
      }
    }
  }

  // Display allocation results and transferred file sizes
  printf("\nFile Allocation using First-Fit:\n");
  printf("File Number\tFile Size\tBlock Number\tTransferred File Size\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t", i + 1, files[i]);
    if (allocation[i] != -1)
    {
      printf("%d\t\t%d\n", allocation[i] + 1, transferred[i]); // Block number starts from 1
    }
    else
    {
      printf("Not Allocated\t-\n");
    }
  }
}

int main()
{
  int m = 5; // Number of memory blocks
  int n = 4; // Number of files

  int blocks[] = {50, 20, 30, 10, 25}; // Predefined block sizes
  int files[] = {15, 20, 10, 30};      // Predefined file sizes

  // Perform First-Fit memory allocation
  firstFit(blocks, m, files, n);

  return 0;
}