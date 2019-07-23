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

StudentListPtr creatListResult(FILE *fPtr)
{
   StudentListPtr root = NULL;
   Student s;

   while( !feof(fPtr))
   {
      fscanf(fPtr, "%s %s %d\n", s.id, s.name, &s.grade);
      insertLast(&root, s);
   }
   printList(root);

   return root;
}

void search_name(StudentListPtr cur)
{

   FILE *fout;
   char find_name[30];

   fout = fopen("Result.txt", "w");
   if(fout == NULL)
      puts("Can not open file.");

   printf("Enter name you want search: "); gets(find_name);


   while(cur != NULL)
   {
      if(strcmp((cur->data).name, find_name) == 0)
          fprintf(fout,"%s has id %s and grade is %d\n", (cur->data).name,
                (cur->data).id, (cur->data).grade);
      cur = cur->next;
   }
   fclose(fout);
}

void search_grade(StudentListPtr cur)
{

   FILE *fout;
   int find_grade;

   fout = fopen("Result.txt", "w");
   if(fout == NULL)
      puts("Can not open file.");

   printf("Enter grade you want search: ");scanf("%d", &find_grade);


   while(cur != NULL)
   {
      if((cur->data).grade == find_grade)
          fprintf(fout,"%s has id %s and grade is %d\n", (cur->data).name,
                (cur->data).id, (cur->data).grade);
      cur = cur->next;
   }
   fclose(fout);
}



int main(){
   FILE *f, *fout;
   StudentListPtr root = NULL;
   Student s;
   char name[20];

   f = fopen("Student.txt", "r");

   if(f == NULL)
      puts("Can not open file.");

   root = creatListResult(f);
   fclose(f);

   //search_name(root);
   search_grade(root);

   return 0;
}
