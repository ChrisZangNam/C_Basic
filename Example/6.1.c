
#include <stdio.h>

#define MAX 100

int sentinel_linear_search(int key, int *arr, int n)
{
   int last_value, i;

   if(n == 1) return (arr[0]) == key ? 0 : -1;

   if(--n < 1)
      return -1;

   last_value = arr[n];

   arr[n] = key;

   i = 0;
   while(arr[i] != key)
      i++;

   printf("arr[%d] ")
   arr[n] = last_value;

   sentinel_linear_search(key, arr, n-i);

}

int main(){
   int arr[MAX];
   int n, key;

   printf("Input the number of array: ");
   scanf("%d", &n);
   for(int i=0; i<n; i++){
      printf("\tInput arr[%d] = ", i);
      scanf("%d", &arr[i]);
   }

   printf("Input the value: ");
   scanf("%d", &key);

   if(sentinel_linear_search(key, arr, n) != -1)
      printf("Searching ! Post is : %d\n", sentinel_linear_search(key, arr, n)+1 );
   else
      puts("Not seach !");

   return 0;
}
