#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int elementType;

struct treeNode{
   struct treeNode *leftPtr;
   elementType data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

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

void inOrder(TreeNodePtr treePtr)
{
   //if tree is not empty, then traverse
   if(treePtr != NULL){
      inOrder(treePtr->leftPtr);
      printf("%3d", treePtr->data);
      inOrder(treePtr->rightPtr);
   }
}

/* Recursive function which checks whether all leaves are at same level */
int checkUtil(TreeNode *root, int level, int *leafLevel)
{
    // Base case
    if (root == NULL)  return 1;

    // If a leaf node is encountered
    if (root->leftPtr == NULL && root->rightPtr == NULL)
    {
        // When a leaf node is found first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return 1;
        }

        // If this is not first leaf node, compare its level with
        // first leaf's level
        return (level == *leafLevel);
    }

    // If this node is not leaf, recursively check left and right subtrees
    return checkUtil(root->leftPtr, level+1, leafLevel) &&
           checkUtil(root->rightPtr, level+1, leafLevel);
}

/* The main function to check if all leafs are at same level.
   It mainly uses checkUtil() */
int check(TreeNode *root)
{
   int level = 0, leafLevel = 0;
   if(checkUtil(root, level, &leafLevel))
      return level;
   else
      return -1;
}

int countNodeS(TreeNode* root, int key)
{
   int count = 0;
   if(root == NULL) return 0;
   if(root->data < key) count++;
   count = count + countNodeS(root->leftPtr, key)+ countNodeS(root->rightPtr, key);


   return count;
}

/*int countNodeSmall(TreeNode* root, int key){
   return countNodeS(root, key, 0);
}
*/
int main()
{
   int item, level, key=5;
   TreeNode* root = NULL;

   srand(time(NULL));
   for(int i=0; i<=5; i++)
   {
      item = rand() % 20;
      printf("%3d", item);
      insertNode(&root, item);
   }

   //inOrder(root);
   printf("\n the number of node smaller than %d is %d\n", key, countNodeS(root, key));
   //level = check(root);
   //printf("\nlevel = %d\n", level);
}
