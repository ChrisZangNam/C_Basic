#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BSTree.h"

int main()
{
   TreeNodePtr root = NULL;
   //srand(time(NULL));
   for(int i=0; i<=10; i++)
   {
      int item = rand() % 15;
      printf("%3d", item);
      insertNode(&root, item);
   }
   print2DUntil(root, 0);
   deleteNode(root, 10);
   print2DUntil(root, 0);


}
