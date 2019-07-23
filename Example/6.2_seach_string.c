#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

void search_word(FILE *f, char *find){
   char s[MAX], tmp[MAX];
   int i=0;

   while(!feof(f)){
      fscanf(f, "%[^n]", s);
      printf("%s\n", s);

      /*if(strlen(s) < strlen(find)) return -1;
      else{
         i=0;
         for(i=0; i<strlen(find); i++){
            tmp[i] = s[i];
         }
         tmp[i] = '\0';
         printf("%s\n", tmp);*/
         strncpy(tmp, s, strlen(find));
         printf("%s\n", tmp);

         /*if(strcmp(tmp, find) == 0)
            printf("%s\n", s);
         else return -1;*/
      }

   }




int main(){

   char find[MAX], s[MAX]  ;
   FILE *f;

   f = fopen("word.txt", "r");

   if(f == NULL)
      puts("File could not be opened");
   printf("Nhap tu can tim kiem: ");
   gets(find);


   search_word(f,find);

   return 0;
}
