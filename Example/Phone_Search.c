#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_t {
      char id[11];
      char name[20];
      int grade;
}Student;

struct studentList{
   Student data;
   struct studentList *next;
} ;

typedef struct studentList StudentList;
typedef StudentList *StudentListPtr;

void insertLast(StudentListPtr *root, Student value)
{
   StudentListPtr new ;
   StudentListPtr cur, pre;

   new = malloc(sizeof(StudentList));

   if(new != NULL)
   {
      new->data = value;
      new->next = NULL;

      if((*root) == NULL)
         *root = new;
      else
      {
         cur = *root; pre = NULL;
         while(cur != NULL)
         {  pre = cur;
            cur = cur->next;
         }
         pre->next = new;
         cur = new;
      }
   }
   else
      puts("NULL");
}

void printList(StudentListPtr cur)
{
   if(cur == NULL)
      puts("List is empty");
   else
   {
      printf("%-10s %-20s %-s\n", "ID", "Name", "Grade");
      while(cur != NULL){
         printf("%-10s %-20s %-d\n", (cur->data).id, (cur->data).name, (cur->data).grade );
         cur = cur->next;
      }
   }
}

void creatListResult(FILE *fPtr)
{
   StudentListPtr root = NULL;
   Student s;

   while( !feof(fPtr))
   {
      fscanf(fPtr, "%s %s %d\n", s.id, s.name, &s.grade);
      insertLast(&root, s);
   }
   printList(root);
}

void search_name(StudentListPtr root)
{
   StudentListPtr cur;
   FILE *fout;
   char find_name[30];

   fout = fopen("Result.txt", "w");
   if(fout == NULL)
      puts("Can not open file.");

   printf("Insert name you want search: "); gets(find_name);

   cur = root;
   while(cur != NULL)
   {
      printf("%s\n", (cur->data).name);
      /*if(strcmp((cur->data).name, find_name) == 0)
        {
           printf("Student %s has id %s and grade is %d\n", (cur->data).name,
                (cur->data).id, (cur->data).grade);
           //fprintf(fout,"%s has id %s and grade is %d\n", (cur->data).name,
                //(cur->data).id, (cur->data).grade);

        }*/
      cur = cur->next;
   }

}


int main(){
   FILE *f, *fout;
   StudentListPtr root = NULL;
   Student s;
   char name[20];

   f = fopen("Student.txt", "r");

   if(f == NULL)
      puts("Can not open file.");

   creatListResult(f);
   fclose(f);


   search_name(root);
   fclose(fout);

   return 0;
}
