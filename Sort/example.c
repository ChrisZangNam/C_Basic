#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

void genData(int arr[])
{
   srand(time(NULL));
   for(int i=0; i<Max_Size; i++)
   {
      arr[i] = rand() % (Max_Size+1);
   }
}
//COUNTING SORT

void Counting_Sort(DataType a[], int r[], int c[],int n, int k)
{
   // a [ 0 . . n ] is the array to be sorted
   // n i s the number of elements of the arraya
   // k i s the maximum o f a , and 0 i s minimum of a

   for(int i=0; i<= k; i++)
      r[i] = 0;

   for(int i=0; i<n; i++)
      r[a[i]]++;

   //compute rank r[i] of i, r[i] is rank of i
   for(int i=1; i<k; i++)
      r[i] = r[i] + r[i-1];
   //sort
   for(int i=n-1; i>=0; i--)
   {
      c[r[a[i]]-1] = a[i];
      r[a[i]] = r[a[i]] - 1;//reduce rank of a[i]
   }
}
int main()
{
   int a[Max_Size];
   int c[Max_Size];


   genData(a);
   for(int i=0; i<Max_Size; i++)
      printf("%d ", a[i]);
   printf("\n");

   int amax = 0;
   for(int i=0; i<Max_Size; i++)
      if(a[i] > amax) amax = a[i];

   int r[amax];
   //Quick_Sort(a, 0, Max_Size-1);
   Counting_Sort(a,r,c,Max_Size, amax);

   for(int i=0; i<Max_Size; i++)
      printf("%d ", c[i]);
   printf("\n");
}
