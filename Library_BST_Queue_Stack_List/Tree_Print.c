#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "BSTree.h"

/*struct treeNode{
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

/*void makeNullTree(TreeNodePtr *treePtr){
   (*treePtr) = NULL;
}

int isEmptyTree(TreeNodePtr treePtr)
{
   return treePtr == NULL;
}

int isLeaf(TreeNodePtr treePtr)
{
   if(treePtr->leftPtr == NULL && treePtr->rightPtr==NULL)
      return 1;
   return 0;
}

TreeNodePtr creatNode(int value){
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

TreeNodePtr Search_Node(TreeNodePtr treePtr, int key)
{
   if(treePtr == NULL) return NULL;

   if(key > treePtr->data)
      return Search_Node(treePtr->rightPtr, key);
   else if(key < treePtr->data)
      return Search_Node(treePtr->leftPtr, key);
   else
      return treePtr;
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

void convertMirror(TreeNodePtr root)
{
   TreeNodePtr tmp;
   if(root == NULL) return ;

   convertMirror(root->leftPtr);
   convertMirror(root->rightPtr);

   tmp = root->leftPtr;
   root->leftPtr = root->rightPtr;
   root->rightPtr = tmp;

}

void print2DUntil(TreeNodePtr root, int space)
{
   if(root == NULL)
      return ;

   space+=COUNT;

   print2DUntil(root->rightPtr, space);

   printf("\n");

   for(int i = COUNT; i<space; i++){
      printf(" ");
   }
   printf("%d\n", root->data);

   print2DUntil(root->leftPtr, space);
}

TreeNodePtr deleteLeaf(TreeNodePtr root, int x){
   if((root) == NULL)
      return NULL;

   if(x > root->data)
      root->rightPtr = deleteLeaf(root->rightPtr, x);
   else if(x < root->data)
      root->leftPtr = deleteLeaf(root->leftPtr, x);
   else if(root->leftPtr == NULL && root->rightPtr == NULL){
      free(root);
      return NULL;
   }

   return root;
}
*/
void instruction()
{
   puts("Enter choice: \n"
        "1 to make tree\n"
        "2 to print preOrder\n"
        "3 to print inOrder\n"
        "4 to print postOrder\n"
        "5 to print in 2-Dimensions\n" //in theo 2 chieu doc
        "6 to convert a tree into its mirror tree\n"
        "7 to delete a leaf node\n"
        "8 to end program\n");
}

int main()
{
   unsigned int i, choice;
   int item;
   int a, b;
   TreeNodePtr tree1, tree2, treeLCA;
   TreeNodePtr rootPtr = NULL;
   char* prefix;

   instruction();
   printf("%s", "?");
   scanf("%u", &choice);

   while(choice != 8)
   {
      switch(choice)
      {
      case 1:
         rootPtr = NULL;
         //srand(time(NULL));
         puts("The number being placed in the tree are: ");

         //insert random values 0->14 in the tree
         for(i=0; i<=10; i++)
         {
            item = rand() % 15;
            printf("%3d", item);
            insertNode(&rootPtr, item);
         }
         printf("\n");
         break;

      case 2:
         preOrder(rootPtr);
         printf("\n");
         break;

      case 3:
         inOrder(rootPtr);
         printf("\n");
         break;

      case 4:
         postOrder(rootPtr);
         printf("\n");
         break;

      case 5:
         print2DUntil(rootPtr, 0);
         break;

      case 6:
         convertMirror(rootPtr);
         inOrder(rootPtr);
         printf("\n");
         break;

      case 7:
         inOrder(rootPtr);
         printf("\n");
         printf("Enter the value of leaf node to delete: "); scanf("%d", &a);

         rootPtr = deleteLeaf(rootPtr, a);
         inOrder(rootPtr);
         printf("\n");
         break;

      default:
         puts("Invalid choice.\n");
         instruction();
         break;

      }//end switch

      printf("%s", "?");
      scanf("%u", &choice);
   }//end while

   puts("End of run.");

}
