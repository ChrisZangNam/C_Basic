#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student_Ptr{
   char std;
   struct Student_Ptr *next;
};

typedef struct Student_Ptr StudentList;
typedef StudentList *StudentListPtr;

void insert_last(StudentListPtr *root, char s)
{
   StudentListPtr new, cur;

   new = malloc(sizeof(StudentList));
   if(new == NULL)
      puts("Can not insert to list.");
   else
   {
      cur = *root;
      new->std = s;
      new->next = NULL;

      while(cur != NULL)
            cur = cur->next;

      cur->next = new;
      cur = new;
      }
   }


int isEmpty(StudentListPtr root)
{
   return root == NULL;
}

void printResult(StudentListPtr cur)
{
   if(isEmpty(cur))
      puts("List is Empty");
   else
   {
      printf("List is: \n");
      //printf("%-10s %-20s %-s\n", "ID", "Name", "Grade");

      while(cur != NULL)
      {
        // printf("%-10s %-20s %-d\n", (cur->std).id, (cur->std).name, (cur->std).grade );
        printf("%c\n", cur->std);
        cur = cur->next;
      }
   }
}


int main()
{
   StudentListPtr root = NULL;
   char value = 'a';

   insert_last(&root, value);
   printResult(root);

   return 0;
}
