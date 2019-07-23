#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef int elementType;

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

TreeNodePtr Search_Node(TreeNodePtr treePtr, elementType key)
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

TreeNodePtr findParent(TreeNodePtr root, elementType value)
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

TreeNodePtr deleteLeaf(TreeNodePtr root, elementType x){
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

elementType findMin(TreeNodePtr root)
{
      if(root == NULL) return NULL;
      if(root->leftPtr == NULL) return root->data;
      else
         return findMin(root->leftPtr);
}

TreeNodePtr deleteNode(TreeNodePtr root, elementType key)
{
   if(root == NULL) return NULL;

   if(key > root->data)
      root->rightPtr = deleteNode(root->rightPtr, key);
   else if(key < root->data)
      root->leftPtr = deleteNode(root->leftPtr, key);
   else{
      //case 1: no child
      if(isLeaf(root))
      {
         free(root);
         root = NULL;
      }
      //case 2: 1 chile (right)
      else if(root->leftPtr == NULL)
      {
         TreeNodePtr tmp = root;
         root = root->rightPtr;
         free(tmp);
      }
      //case 3: 1 child (left)
      else if(root->rightPtr == NULL)
      {
         TreeNodePtr tmp = root;
         root= root->leftPtr;
         free(tmp);
      }
      //case 4:2 child
      else
      {
         elementType minNext = findMin(root->rightPtr);//tim gia tri nho nhat ben phai
         root->data = minNext;
         root->rightPtr = deleteNode(root->rightPtr, minNext); //xoa bo node lap lai
      }
   }
   return root;
}
