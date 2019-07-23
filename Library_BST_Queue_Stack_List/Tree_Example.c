#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode{
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main()
{
   unsigned int i;
   int item;
   TreeNodePtr rootPtr = NULL;

   srand(time(NULL));
   puts("The number being placed in the tree are: ");

   //insert random values 0->14 in the tree
   for(i=0; i<=10; i++)
   {
      item = rand() % 15;
      printf("%3d", item);
      insertNode(&rootPtr, item);
   }

   //traverse the tree preOrder-Duyet the thu tu truoc
   puts("\n\nThe preOrder traversal is: ");
   preOrder(rootPtr);

   //traverse the tree inOrder-Duyet the thu tu giua
   puts("\n\nThe inOrder traversal is: ");
   inOrder(rootPtr);

   //traverse the tree postOrder-Duyet the thu tu sau
   puts("\n\nThe postOrder traversal is: ");
   postOrder(rootPtr);
}


//insert node into tree
void insertNode(TreeNodePtr *treePtr, int value)
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
      if(value < (*treePtr)->data)
         insertNode((&(*treePtr)->leftPtr), value);
      else if(value > (*treePtr)->data)
         insertNode((&(*treePtr)->rightPtr), value);
      else //duplicate data value ignored
         printf("%s", "dup");
   }
}

//begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr)
{
   //if tree is not empty, then traverse
   if(treePtr != NULL){
      inOrder(treePtr->leftPtr);
      printf("%3d", treePtr->data);
      inOrder(treePtr->rightPtr);
   }
}

//begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      printf("%3d", treePtr->data);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);
   }
}

//begin postorder traversal of tree
void postOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
      printf("%3d", treePtr->data);
   }
}
