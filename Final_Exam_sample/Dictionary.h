#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct dict{
   char english[20];
   char vietnamese[20];
}Dictionary;

typedef Dictionary elementType;

struct treeNode{
   struct treeNode *leftPtr;
   elementType data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;


void makeNullTree(TreeNodePtr *treePtr){
   (*treePtr) = NULL;
}

int isLeaf(TreeNodePtr treePtr)
{
   return (treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL);
}

int isEmptyTree(TreeNodePtr treePtr)
{
   return treePtr == NULL;
}

TreeNodePtr creatNode(elementType value){
   TreeNodePtr new;
   new = malloc(sizeof(TreeNode));

   if(new != NULL){
      new->data = value;
      new->leftPtr = NULL;
      new->rightPtr = NULL;
   }

   return new;
}

//insert node into tree
void insertNode(TreeNodePtr *treePtr, elementType value)
{
   //if tree is empty
   if(*treePtr == NULL){
      *treePtr = malloc(sizeof(TreeNode));

      //if memory was located, then assign data
      if(*treePtr != NULL)
      {
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      }
      else
         printf("%d not inserted. No memory is available\n", value);
   }
   else{//tree not empty
      //data to insert is less than data in current node
      if( strcmp(value.english, (*treePtr)->data.english) < 0)
         insertNode((&(*treePtr)->leftPtr), value);
      else if(strcmp(value.english, (*treePtr)->data.english) > 0)
         insertNode((&(*treePtr)->rightPtr), value);
      else //duplicate data value ignored
         printf("%s", "dup");
   }
}

void inOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      inOrder(treePtr->leftPtr);
      printf("%s\t%s\n", treePtr->data.english, treePtr->data.vietnamese);
      inOrder(treePtr->rightPtr);
   }
}

TreeNodePtr findEng(TreeNodePtr root, char word[])
{
   if(root == NULL)
      return NULL;

   if(strcmp(word, root->data.english) < 0)
      return findEng(root->leftPtr, word);
   else if(strcmp(word, root->data.english) > 0)
      return findEng(root->rightPtr, word);
   else
      return root;
}

struct word{
   char word[30];
   struct word *next;
};

void translateVN(TreeNodePtr root, char s[])
{
   TreeNodePtr tmp;
   char word[30], prefix[1000];
   int i=0, j=0;
   elementType data;

   strcpy(prefix, " ");
   for(i=0; i<strlen(s); i++)
   {
      s[i] = tolower(s[i]);
   }

   i=0;
   while(s[i] != '\0')
   {//tach tu
      j=0;
      for(i; i<strlen(s) && s[i] != ' '; i++)
      {
         word[j] = s[i];
         j++;
      }
      word[j] = '\0';
      printf("%s\n", word);

      //translate
      tmp = findEng(root, word);
      if(tmp == NULL)
      {
         printf("=>Thieu tu %s\n", word);
         strcpy(data.english ,word);
         printf("=>Bo sung: \n");
         printf("Nghia cua %s la: ", word);
         gets(data.vietnamese);

         insertNode(&root, data);

         strcat(prefix, data.vietnamese);
         strcat(prefix, " ");
      }
      else{
         strcat(prefix, tmp->data.vietnamese);
         strcat(prefix, " ");
      }
      i++;
   }
   puts("Translate to Vietnamese is: \n");
   printf("%s\n", prefix);

}

