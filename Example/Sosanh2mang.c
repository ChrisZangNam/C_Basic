#include <stdio.h>

#define MAX 100

void swap(int *a, int *b){
   int tmp = *a;
   *a=*b;
   *b = tmp;
}

void sort(int arr[], int n)
{
   for(int i=0; i<n-1; i++)
      for(int j=i+1; i<n; j++)
      {
         if(arr[j] < arr[i])
            swap(&arr[i], &arr[j]);
      }
}

int binarySearch(int a[], int key, int size)
{
   int lo = 0, high = size -1;
   int mid;

   while(lo <= high)
      {
         mid = (lo+high)/2;
         if(a[mid] == key)
            return mid;
         else if(a[mid] > key)
            high = mid-1;
         else
            lo = mid+1;
      }

      return -1;
}

int main()
{
   int a[5] = {1,2,3,4,5};
   int b[3] = {1,2,3};
   int k;

   printf("Cac phan tu co o ca hai day la: ");
   for(int i =0; i<5; i++){
      k = binarySearch(b,a[i],3);
      if(k!= -1)
         printf("%5d", a[i]);
   }
   printf("\n");

   printf("Cac phan tu co o day 1 va ko co day 2 la: ");
   for(int i =0; i<5; i++){
      k = binarySearch(b,a[i],3);
      if(k == -1)
         printf("%5d", a[i]);
   }
   return 0;
}
