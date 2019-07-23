#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Dictionary.h"


void instruction()
{
   puts("\tDICTIONARY\n"
        "1. Read file and save to BST\n"
        "2. Display all data in ascending of English words\n"
        "3. Translate English - Vietnamese\n"
        "4. Exit\n");
}

int main()
{
   int choice;
   TreeNodePtr root = NULL;
   TreeNodePtr tmp;
   Dictionary data;
   char s[1000];
   FILE *fPtr;

   fPtr = fopen("data.txt", "r");
   if(fPtr == NULL)
      puts("Khong mo duoc file.");

   instruction();
   printf("Enter your choice is: ");
   scanf("%d%*c", &choice);

   while(choice != 4)
   {
      switch(choice)
      {
      case 1:
         puts("Read file and save to BST.");
         puts("===============================");

         while(!feof(fPtr))
         {
            fscanf(fPtr, "%s%*c%[^\n]\n", data.english, data.vietnamese );
            insertNode(&root, data);
         }
         puts("===============================");
         break;

      case 2:
         puts("Display all data in ascending of English words.");
         puts("===============================");
         inOrder(root);
         puts("===============================");
         break;

      case 3:
         puts("Translate English - Vietnamese.");
         puts("===============================");

         puts("Enter a sentence: ");
         gets(s);
         translateVN(root, s);

         puts("===============================");
         break;

      default:
         puts("Invalid choice.\n");
         instruction();
         break;
      }//end switch
      instruction();
      printf("Enter your choice is: ");
      scanf("%d%*c", &choice);
   }//end while
}
