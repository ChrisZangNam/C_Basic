#include <stdio.h>

int binSearch (int List[], int Target, int size)
{
   int mid;
   int hi = size -1;
   int lo = 0;

   while(lo <= hi)
   {
      mid = (lo + hi)/2;
      if(List[mid] == Target)
         return mid;
      else if(Target < List[mid])
         hi = mid - 1;
      else
         lo = mid + 1;
   }
   return -1;
}

int main()
{
   int arr[10]={1,2,3,4,5,6,7,8,9,10};
   int key = 8;

   int find;
   find= binSearch(arr, key, 10);

   printf("%d\n", find);

   return 0;
}
