#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct treeNode{
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void makeNullTree(TreeNodePtr *treePtr){
   (*treePtr) = NULL;
}

int isEmptyTree(TreeNodePtr treePtr)
{
   return treePtr == NULL;
}

TreeNodePtr getLeft(TreeNodePtr treePtr){
   if(treePtr != NULL)
      return treePtr->leftPtr;
   else
      return NULL;
}

TreeNodePtr getRight(TreeNodePtr treePtr){
   if(treePtr != NULL)
      return treePtr->rightPtr;
   else
      return NULL;
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

int countTree(TreeNodePtr treePtr)
{
   if(isEmptyTree(treePtr)) return 0;
   else
      return 1 + countTree(getLeft(treePtr)) + countTree(getRight(treePtr));
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

int count_Leaf(TreeNodePtr treePtr)
{
   if(treePtr == NULL)
    return 0;
  if(treePtr->leftPtr == NULL && treePtr->rightPtr==NULL)
    return 1;
  else
    return count_Leaf(treePtr->leftPtr)+
           count_Leaf(treePtr->rightPtr);
}

int height_Tree(TreeNodePtr treePtr)
{
   int hL, hR;
   if(treePtr == NULL) return 0;
   else{
       hL = height_Tree(treePtr->leftPtr);
       hR = height_Tree(treePtr->rightPtr);
  }
   return 1 + (hL > hR ? hL : hR);
}

int sum_Node(TreeNodePtr treePtr)
{
   if(treePtr == NULL)return 0;
   else
      return treePtr->data + sum_Node(treePtr->leftPtr) + sum_Node(treePtr->rightPtr);
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

//kiem tra xem 2 node co la anh em ruot khong
int isSiblings(TreeNodePtr root, TreeNodePtr tree1, TreeNodePtr tree2)
{
   if(root == NULL) return 0;

   return ((root->leftPtr == tree1 && root->rightPtr == tree2) ||
          (root->leftPtr == tree2 && root->rightPtr == tree1) ||
          isSiblings(root->leftPtr, tree1, tree2) ||
          isSiblings(root->rightPtr, tree1, tree2));
}


int findLevel(TreeNodePtr root, TreeNodePtr treePtr, int lev)
{
   if(root == NULL) return 0;
   if(treePtr == root) return lev;

   int l = findLevel(root->leftPtr, treePtr, lev+1);

   if(l != 0) return l;

   return findLevel(root->rightPtr, treePtr, lev+1);
}

//kiem tra 2 node co la anh em ho ko
int isCousin(TreeNodePtr root, TreeNodePtr tree1, TreeNodePtr tree2)
{
   if((findLevel(root, tree1, 1) == findLevel(root, tree2, 1))
      && !(isSiblings(root, tree1, tree2)))
      return 1;
   else
      return 0;
}

//tinh khoang cach giua 2 node: so canh toi thieu de di tu tree1 den tree2
// Dist (n1, n2) = Dist (root, n1) + Dist (root, n2) - 2 * Dist (root, lca)
// root-lca : khoang cach tu root den to tien chung thap nhat lca

TreeNodePtr findLCA(TreeNodePtr root, int a, int b)// lowest common ancestor
{
   if(root == NULL) return NULL;

   if(root->data == a || root->data == b) return root;

   TreeNodePtr left = findLCA(root->leftPtr, a, b);
   TreeNodePtr right = findLCA(root->rightPtr, a, b);

   if(left != NULL && right != NULL)
      return root;
   if(left != NULL)
      return findLCA(root->leftPtr, a, b);

   return findLCA(root->rightPtr, a, b);
}

int Dist2Node(TreeNodePtr root, int a, int b)
{
   TreeNodePtr tree1 = Search_Node(root, a);
   TreeNodePtr tree2 = Search_Node(root, b);

   TreeNodePtr treeLCA = findLCA(root, a, b);

   int d1 = findLevel(treeLCA, tree1, 1);
   int d2 = findLevel(treeLCA, tree2, 1);

   return d1 + d2 - 2;
}

void prettyprint(TreeNodePtr tree, char *prefix){
	char *prefixend=prefix+strlen(prefix);
	if (tree!=NULL){
		printf("%04d",tree->data);
		if (tree->leftPtr!=NULL) if (tree->rightPtr==NULL){
			printf("\304");strcat(prefix,"     ");
		}
		else {
			printf("\302");strcat(prefix,"\263    ");
		}
		prettyprint(tree->leftPtr,prefix);
		*prefixend='\0';
		if (tree->rightPtr!=NULL) if (tree->leftPtr!=NULL){
			printf("\n%s",prefix);printf("\300");
		} else printf("\304");
		strcat(prefix,"     ");
		prettyprint(tree->rightPtr,prefix);
		printf("\n");
	}
}

int findMin(TreeNodePtr root)
{
      if(root == NULL) return NULL;
      if(root->leftPtr == NULL) return root->data;
      else
         return findMin(root->leftPtr);
}

TreeNodePtr findParent(TreeNodePtr root, int value)
{
   if(root == NULL) return NULL;
   if((root->leftPtr)->data == value || (root->rightPtr)->data == value)
      return root;
   if(value >  root->data)
      return findParent(root->rightPtr, value);
   else if (value < root->data)
      return findParent(root->leftPtr, value);
   else
      return root;
}

void freeTree(TreeNodePtr root)
{
   if(root != NULL)
   {
      freeTree((root)->leftPtr);
      freeTree((root)->rightPtr);
      free(root);
   }
}

void deleteNode(TreeNodePtr *root, int value)
{
   TreeNodePtr tmp = Search_Node(*root, value);

   if(tmp->rightPtr == NULL)
      tmp = tmp->leftPtr;
   else{
      int a = findMin(tmp->rightPtr);
      TreeNodePtr parent = findParent(*root, a);
     // TreeNodePtr nodeRemove = Search_Node(*root, a);
      tmp->data = a;
      parent->leftPtr = NULL;
      //free(nodeRemove);
   }
}

void preOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      printf("%3d", treePtr->data);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);
   }
   else
      printf("NULL\n");
}

void instruction()
{
   puts("Enter choice: \n"
        "1 to make tree\n"
        "2 to show the number of node\n"
        "3 to show the number of leaf\n"
        "4 to show sum of tree node\n"
        "5 to show the height of tree\n"
        "6 to find the level of node\n"
        "7 to check two node are cousins\n"
        "8 to check two node are siblings\n"
        "9 to find lowest comon ancestor of 2 node\n"
        "10 to find distance of 2 node\n"
        "11 to prettrprint\n"
        "12 to remove a node\n"
        "13 to free Tree\n"
        "14 to end program\n");
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

   while(choice != 14)
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
         printf("The number of node in tree is %d\n", countTree(rootPtr));
         break;

      case 3:
         printf("The number of leaf node in tree is %d\n", count_Leaf(rootPtr));
         break;

      case 4:
         printf("The sum of all node in tree is %d\n", sum_Node(rootPtr));
         break;

      case 5:
         printf("The height of node in tree is %d\n", height_Tree(rootPtr));
         break;

      case 6:
         printf("Enter the value of node in tree: "); scanf("%d", &a);
         tree1 = Search_Node(rootPtr, a);

         printf("The level of %d is %d\n", a, findLevel(rootPtr, tree1, 1));
         break;

      case 7:
         printf("Enter 2 value of tree you want check cousin: ");
         scanf("%d %d", &a, &b);

         tree1 = Search_Node(rootPtr, a);
         tree2 = Search_Node(rootPtr, b);

         if(isCousin(rootPtr, tree1, tree2))
            printf("%d  and %d are cousins.\n", a, b);
         else
            printf("%d  and %d are not cousins.\n", a, b);

         break;

      case 8:
         printf("Enter 2 value of tree you want check sibling: ");
         scanf("%d %d", &a, &b);

         tree1 = Search_Node(rootPtr, a);
         tree2 = Search_Node(rootPtr, b);

         if(isSiblings(rootPtr, tree1, tree2))
            printf("%d  and %d are siblings.\n", a, b);
         else
            printf("%d  and %d are not siblings.\n", a, b);

         break;

      case 9:
         printf("Enter 2 value of node in tree to find LCA: ");
         scanf("%d %d", &a, &b);

         treeLCA = findLCA(rootPtr, a, b);
         printf("The Lowest comon ancestor of %d and %d is %d\n", a, b, treeLCA->data);
         break;

      case 10:
         printf("Enter 2 value of node in tree to find distance: ");
         scanf("%d %d", &a, &b);

         printf("The distance of %d and %d is %d\n", a, b, Dist2Node(rootPtr, a, b));
         break;

      case 11:
         strcpy(prefix, "     ");
         prettyprint(rootPtr, prefix);
         break;

      case 12:
         preOrder(rootPtr); printf("\n");
         printf("Enter value of node in tree to delete: "); scanf("%d", &a);
         //tree1 = Search_Node(rootPtr, a);
         //printf("The min of tree root = %d is %d\n", a, findMin(tree1));
         deleteNode(&rootPtr, a);
         preOrder(rootPtr); printf("\n");
         break;

      case 13:
         preOrder(rootPtr); printf("\n");
         freeTree(rootPtr);
         preOrder(rootPtr); printf("\n");
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
