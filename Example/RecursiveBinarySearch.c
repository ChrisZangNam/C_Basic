#include <stdio.h>

int RecursiveBinarySearch (int List[],int Target, int lo, int hi)
{
   int mid;

   if(lo>hi) return -1;
   mid = (lo+hi)/2;
   if(List[mid] == Target)
      return mid;

   else if(Target < List[mid])
      RecursiveBinarySearch(List, Target, lo, mid-1);

   else
      RecursiveBinarySearch(List, Target, mid+1, hi);
}

int main()
{
   int arr[10]={1,2,3,4,5,6,7,8,9,10};
   int key = 8;

   int find;
   find= RecursiveBinarySearch(arr, key, 0, 9);

   printf("%d\n", find);

   return 0;
}
