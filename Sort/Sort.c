#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

#define Max_Size 100000

typedef int DataType;

void genData(DataType arr[])
{
   srand(time(NULL));
   for(int i=1; i<=Max_Size; i++)
   {
      arr[i] = rand() % (Max_Size+1);
   }
}

int main()
{
   int a[Max_Size];

   genData(a);
  /* for(int i=0; i<Max_Size; i++)
      printf("%d ", a[i]);
   printf("\n");*/

   //SelectionSort(a, Max_Size);
   //insertionSort(a, Max_Size);
   Merge_Sort(a, 0, Max_Size-1);
   //Quick_Sort(a, 0, Max_Size-1);
   //Heap_Sort(a,Max_Size);
   //Counting_Sort(a, r, c, Max_Size, Max_Array(a));
   for(int i=1; i<=Max_Size; i++)
      printf("%d ", a[i]);
   printf("\n");

}
