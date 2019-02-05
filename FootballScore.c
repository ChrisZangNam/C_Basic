#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct team{
   int id;
   char name[30];
   int score;
   int win;
   int lost;
}TeamInfo;

struct team_info{
   TeamInfo data;
   struct team_info *next;
};

typedef struct team_info TeamList;
typedef TeamList *TeamListPtr;

void instruction(){
   puts("\tFootball Result\n"
        "1. The informaiton of teams\n"
        "2. Match Schedule\n"
        "3. Update Result\n"
        "4. Statistic\n"
        "5. End program\n");
}

void insertFirst(TeamListPtr *root, TeamInfo data)
{
   TeamListPtr newPtr;

   newPtr = malloc(sizeof(TeamList));
   if(newPtr != NULL)
   {
      newPtr->data = data;
      newPtr->next = NULL;

      newPtr->next = (*root);
      (*root) = newPtr;
   }
   else
      puts("No memory available");
}

void printList(TeamListPtr root)
{
   if(root == NULL) return ;

   printf("%-4s%-30s%-10s%-10s%-10s\n","ID", "     Ten", "Diem", "Ban thang", "Ban thua");

   while(root != NULL)
   {
      printf("%-4d%-30s%-10d%-10d%-10d\n", (root->data).id, (root->data).name, (root->data).score, (root->data).win, (root->data).lost);
      root = root->next;
   }
}

TeamListPtr findID(TeamListPtr root, int id)
{
   TeamListPtr cur = root;
   if(root == NULL) return NULL;

   while(cur != NULL && cur->data.id != id)
      cur = cur->next;

   return cur;
}

int minScore(TeamListPtr root)
{
   TeamListPtr cur = root;

   if (root == NULL) return NULL;
   int min = cur->data.score;

   while(cur != NULL)
   {
      if(cur->data.score < min)
         min = cur->data.score;
      cur = cur->next;
   }

   return min;

}

TeamListPtr findScore(TeamListPtr root, int score)
{
   TeamListPtr cur = root;
   if(root == NULL) return NULL;

   while(cur != NULL && cur->data.score != score)
      cur = cur->next;

   return cur;
}

int DeleteTeam(TeamListPtr *root, int scoreValue)
{

   TeamListPtr tmp, cur, pre;
    if((*root)->data.score == scoreValue)
   {
      tmp = (*root);
      *root = (*root)->next;
      free(tmp);
      return scoreValue;
   }
   else{
      pre = *root;
      cur = (*root)->next;

      while(cur != NULL && cur->data.score != scoreValue)
      {
            pre = cur;
            cur = cur->next;
      }

      if(cur != NULL)
      {
         tmp = cur;
         pre->next = cur->next;
         free(tmp);
         return scoreValue;
      }
   }
}

int main()
{
   FILE *fPtr;
   int n, choice; //so doi
   TeamListPtr root = NULL;

   int flag1 = 0, flag3 = 0, flag = 0;
   int id1, id2;
   int score1, score2;
   TeamListPtr team1, team2;
   char s[30], tmp[100];

   TeamInfo data;

   fPtr = fopen("bongda.txt", "r");

   if(fPtr == NULL)
      puts("bongda.txt can not open.");

   instruction();
   printf("Enter your choice: "); scanf("%d", &choice);

   while(choice != 5)
   {
      switch(choice)
      {
      case 1:
         if(flag1 == 0){
            fscanf(fPtr, "%d\n", &n); //printf("%d\n", n);

            for(int i=0; i<n; i++)
            {
               fscanf(fPtr, "%d%*c%30[^\n]", &data.id, data.name);
               data.lost = 0;
               data.score = 0;
               data.win = 0;
              // printf("%-4d%-30s%-10d%-10d%-10d\n", data.id, data.name, data.score, data.win, data.lost);
               insertFirst(&root, data);
            }
            printList(root);
            flag1 = 1;
         }
         else
            printList(root);
         break;

      case 2:
         while(!feof(fPtr))
         {
            fscanf(fPtr, "\n%[^\n]", s);
            printf("%s\n", s);

            for(int j=0; j<2; j++)
            {
               fscanf(fPtr, "%d%*c%d\n", &id1, &id2);
               //printf("%d %d\n", id1, id2);
               team1 = findID(root, id1);
               team2 = findID(root, id2);
               printf("%10s  - %-10s\n", team1->data.name, team2->data.name);
            }
         }

         break;

      case 3:
         if(flag3 == 0 ){
            rewind(fPtr);
         for(int i=0; i<=n; i++)
           {
              fscanf(fPtr, "%[^\n]\n", tmp);
              //printf("%s\n", tmp);
           }
         }
         printf("Cap nhat ket qua thi dau: \n");
         if(flag != 3){
            fscanf(fPtr, "\n%[^\n]", s);
            printf("%s\n", s);

            for(int i=0; i<2; i++){
               fscanf(fPtr, "%d%*c%d\n", &id1, &id2);
               team1 = findID(root, id1);
               team2 = findID(root, id2);

               printf("%10s  - %-10s: ", team1->data.name, team2->data.name);
               scanf("%d%*c%d", &score1, &score2);

               if(score1 > score2){
                  team1->data.win += score1;
                  team2->data.lost += score1;

                  team1->data.score+=3;
               }
               else if(score1 < score2)
               {
                  team1->data.lost += score2;
                  team2->data.win += score2;

                  team2->data.score +=3;
               }
               else
               {
                  team1->data.win += score1;
                  team1->data.lost += score1;
                  team2->data.win += score1;
                  team2->data.lost += score1;

                  team1->data.score +=1;
                  team2->data.score +=1;
               }
            }//end for
            printList(root);
            flag ++;
         }
         else
            printf("Da het cac vong.\n");
         flag3 = 1;
         break;

      case 4:
         puts("Doi co diem thap nhat la: ");
         team1 = findScore(root, minScore(root));
         printf("%-4s%-30s%-10s%-10s%-10s\n","ID", "     Ten", "Diem", "Ban thang", "Ban thua");
         printf("%-4d%-30s%-10d%-10d%-10d\n\n", (team1->data).id, (team1->data).name,
                (team1->data).score, (team1->data).win, (team1->data).lost);

         int scoreValue = DeleteTeam(&root, minScore(root));

         printList(root);

         break;

      default:
         puts("Invalid choice");
         instruction();
         break;
      }

      printf("Enter your choice: "); scanf("%d", &choice);
   }
   puts("End of run.");
}


