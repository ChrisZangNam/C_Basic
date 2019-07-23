#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_t {
      char id[11];
      char name[20];
      int grade;
 }Student;

typedef struct Student_Ptr{
   Student std;
   struct Student_Ptr *next;
} StudentList;

typedef StudentList *StudentListPtr;

void insert_last(StudentListPtr *root, Student s)
{
   StudentListPtr new, cur = *root;

   new = malloc(sizeof(StudentList));
   if(new == NULL)
      puts("Can not insert to list.");
   else
   {
      new->std = s;
      new->next = NULL;

      if(*root == NULL){
         (*root)->next = new;
         *root = new;
      }
      else
      {
         while(cur != NULL)
            cur = cur->next;

         cur->next = new;
         cur = new;
      }
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
      printf("%-10s %-20s %-s\n", "ID", "Name", "Grade");

      while(cur != NULL)
      {
         printf("%-10s %-20s %-d\n", (cur->std).id, (cur->std).name, (cur->std).grade );
      }
   }
}

void creatListResult(FILE *fPtr)
{
   StudentListPtr root = NULL;
   Student s;

   while((fscanf(fPtr, "%s %s %d\n", s.id, s.name, &s.grade)) != EOF)
   {
      insert_last(&root, s);
      //printResult(root);
   }
}

int main(){
   FILE *f;

   f = fopen("Student.txt", "r");

   if(f == NULL)
      puts("Can not open file.");
   else
      creatListResult(f);

   return 0;
}




