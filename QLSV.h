#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10

typedef struct Sinhvien{
   char username[30];
   char password[30];
   float score;
}SinhVien;

typedef SinhVien elementType;

struct treeNode{
   struct treeNode *leftPtr;
   elementType data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;


void instruction()
{
   puts("\tQuan li Sinh vien\n"
        "1. Dang Nhap\n"
        "2. Thoat\n");
}

void instructionSV()
{
   puts("=========================\n"
        "1. Xem diem\n"
        "2. Thay doi mat khau\n"
        "3. Ghi lai thong tin len file va Thoat\n");
}

void instructionAd()
{
   puts("=========================\n"
        "1. Them mot sinh vien vao he thong\n"
        "2. In ra danh sach sinh vien\n"
        "3. Xoa sinh vien\n"
        "4. Ghi lai thong tin len file va Thoat\n");
}

int isLeaf(TreeNodePtr treePtr)
{
   return (treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL);
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
      if( strcmp(value.username, (*treePtr)->data.username) < 0)
         insertNode((&(*treePtr)->leftPtr), value);
      else if(strcmp(value.username, (*treePtr)->data.username) > 0)
         insertNode((&(*treePtr)->rightPtr), value);
      else //duplicate data value ignored
         printf("%s", "dup");
   }
}

//begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      printf("%s\t%s\t%f\n", treePtr->data.username, treePtr->data.password, treePtr->data.score);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);
   }
}

void inOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      inOrder(treePtr->leftPtr);
      printf("%s\t%s\t%f\n", treePtr->data.username, treePtr->data.password, treePtr->data.score);
      inOrder(treePtr->rightPtr);
   }
}

void postOrder(TreeNodePtr treePtr)
{
   if(treePtr != NULL){
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
      printf("%s\t%s\t%f\n", treePtr->data.username, treePtr->data.password, treePtr->data.score);
   }
}

TreeNodePtr findUsername(TreeNodePtr root, char name[])
{
   if(root == NULL) return NULL;
   if(strcmp(name, root->data.username) > 0)
      return findUsername(root->rightPtr, name);
   else if(strcmp(name, root->data.username) < 0)
      return findUsername(root->leftPtr, name);
   else
      return root;

}
TreeNodePtr findMin(TreeNodePtr root)
{
      if(root == NULL) return NULL;
      if(root->leftPtr == NULL) return root;
      else
         return findMin(root->leftPtr);
}

TreeNodePtr deleteNode_Name(TreeNodePtr root, char key[])
{
   if(root == NULL) return NULL;

   if(strcmp(key, root->data.username) > 0)
      root->rightPtr = deleteNode_Name(root->rightPtr, key);
   else if(strcmp(key, root->data.username) < 0)
      root->leftPtr = deleteNode_Name(root->leftPtr, key);
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
         TreeNodePtr tmp = findMin(root->rightPtr);
         root->data = tmp->data;
         root->rightPtr = deleteNode_Name(root->rightPtr, tmp->data.username); //xoa bo node lap lai
      }
   }
   return root;
}
