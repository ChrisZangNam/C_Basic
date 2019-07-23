#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_t{
   char name[20];
   char id[10];
   int grade;

   struct student_t *next;
} Student;

Student* root;

Student* insert(Student* new)
{
   if(root == NULL)
      return new;
   else
   {
      Student* cur;

      cur = root;
      while(cur != NULL) cur= cur->next;

      cur->next=new;
   }

   return root;
}

Student* creatList(FILE *f)
{
   Student* new;

   new = malloc(sizeof(Student));

   if(new != NULL)
   {
      while(!feof(f))
      {
         fscanf(f, "%s %s %d\n", new->id, new->name, &new->grade);
   //      printf("%s %s %d\n", new->id, new->name, new->grade);
         new->next = NULL;

         //insert
         root = insert(new);
      }
   }

   return root;
}

void printList(Student* root)
{
   if(root == NULL)
      puts("NULL");
   else
   {
      Student* cur;
      cur = root;
      while(cur != NULL)
      {
         printf("%-10s%-20s%-d\n", cur->id, cur->name, cur->grade);
      }
   }
}

int main()
{
   root = NULL;
   FILE *f;

   f = fopen("Student.txt", "r");

   creatList(f);
   fclose(f);
   printList(root);

   return 0;
}
