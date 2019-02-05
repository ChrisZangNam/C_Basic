#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ip{
    char digistar[100];//ten mien
    char ip[20];
} IPtype;

typedef IPtype elementType;

struct treeNode
{
    struct treeNode *leftPtr;
    elementType data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

TreeNodePtr creatNode(elementType value)
{
    TreeNodePtr new;
    new = malloc(sizeof(TreeNode));

    if (new != NULL)
    {
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
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        //if memory was located, then assign data
        if (*treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("%d not inserted. No memory is available\n", value);
    }
    else
    { //tree not empty
        //data to insert is less than data in current node
        if (strcmp(value.digistar, (*treePtr)->data.digistar) < 0)
            insertNode((&(*treePtr)->leftPtr), value);
        else if (strcmp(value.digistar, (*treePtr)->data.digistar) > 0)
            insertNode((&(*treePtr)->rightPtr), value);
        else //duplicate data value ignored
            printf("%s", "dup");
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%s\t%s\n", treePtr->data.digistar, treePtr->data.ip);
        inOrder(treePtr->rightPtr);
    }
}

TreeNodePtr SearchIP(TreeNodePtr root, char value[])
{
    if(root == NULL)
        return NULL;

    if(strcmp(value, root->data.digistar) > 0)
        return SearchIP(root->rightPtr, value);
    else if (strcmp(value, root->data.digistar) < 0)
        return SearchIP(root->leftPtr, value);
    else
        return root;
}

TreeNodePtr SearchDigistar(TreeNodePtr root, char value[])
{
    if(root == NULL)
        return NULL;

    if(strcmp(value, root->data.ip) > 0)
        return SearchDigistar(root->rightPtr, value);
    else if (strcmp(value, root->data.ip) < 0)
        return SearchDigistar(root->leftPtr, value);
    else
        return root;
}


//Blocked struct
struct blocked{
    char data[50];
    struct blocked *next;
};

typedef struct blocked BlockedType;
typedef BlockedType *BlockedList;

void insertLast(BlockedList *root, char value[])
{
    BlockedList newPtr;
    BlockedList curPtr;

    newPtr = malloc(sizeof(BlockedList));

    if(newPtr != NULL){
		strcpy(newPtr->data, value);
		newPtr->next = NULL; //node ko lien ket voi node khac

		if(*root == NULL)
         *root = newPtr;
      else{
         curPtr = *root;
         while(curPtr->next != NULL)
         {
            curPtr = curPtr->next;
         }

         curPtr->next = newPtr;
      }
	}
   else{
		printf("%c not inserted. No memory available.\n", value);
	}//end else
}


void printList(BlockedList root)
{
    if(root == NULL)
        puts("NULL");

    while(root != NULL)
    {
        printf("%s\n", root->data);
        root = root->next;
    }
}


int checkBlocked(BlockedList root, char value[])
{
   while(root != NULL)
   {
      if(strcmp(root->data, value) == 0)
      {
         return 1;
      }
      else
         root = root->next;
   }
   return 0;
 }


 //sort

//tach ma function

int* devideIP(char input[])
{
   int i, j, k;
   char tmp[5];
   static int a[4];

   i=0; j=0; k=0;
   while(input[i] != '\0')
   {

      if(isdigit(input[i]))
      {
         tmp[j] = input[i];
         j++;  i++;
      }
      else
      {
         tmp[j] = '\0';
         a[k] = atoi(tmp);
         j=0;    i++;   k++;
      }
   }
   tmp[j] = '\0';
   a[k] = atoi(tmp);
   return a;
}


int compareIP(char s1[], char s2[])
{
   int *atmp, *btmp;
   int a[4], b[4];

   atmp = devideIP(s1);
   for(int i=0; i<4; i++)
   {
      a[i] = *(atmp+i);
   }
   btmp = devideIP(s2);
   for(int i=0; i<4; i++)
   {
      b[i] = *(btmp+i);
   }
   int i=0;
   while(i != 4)
   {
      if(a[i] > b[i])
      {
         return 1;
         break;
      }
      else if(a[i] < b[i])
      {
         return -1;
         break;
      }
      else{
         i++;
      }
   }

   return 0;
}


struct IP{
   char ip[20];
   struct IP *leftPtr;
   struct IP *rightPtr;
};

typedef struct IP IPtree;
typedef IPtree *IPtreePtr;

//insert node into tree
void insertIPNode(IPtreePtr *treePtr, char value[])
{

    //if tree is empty
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        //if memory was located, then assign data
        if (*treePtr != NULL)
        {
            strcpy((*treePtr)->ip, value);
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("Not inserted. No memory is available\n");
    }
    else
    { //tree not empty

        //data to insert is less than data in current node
        if (compareIP((*treePtr)->ip, value) > 0)
            insertIPNode((&(*treePtr)->leftPtr), value);
        else if (compareIP((*treePtr)->ip, value) < 0)
            insertIPNode((&(*treePtr)->rightPtr), value);
        else //duplicate data value ignored
            printf("%s", "dup");
    }
}

void inOrderIP(IPtreePtr treePtr)
{
   if (treePtr != NULL)
    {
        inOrderIP(treePtr->leftPtr);
        printf("%s\n", treePtr->ip);
        inOrderIP(treePtr->rightPtr);
    }
}


void insertIP_tree(IPtreePtr IProot, TreeNodePtr Troot)
{
    if (Troot != NULL)
    {
        insertIPNode(&IProot, Troot->data.ip);
        insertIP_tree(IProot, Troot->leftPtr);
        insertIP_tree(IProot, Troot->rightPtr);
    }
}

/*void writeFile( TreeNodePtr treePtr, FILE *fPtr )
{
    if ( treePtr != NULL ) {
        writeFile( treePtr->leftPtr, fPtr );
        fprintf( fPtr, "%s\t%d\n", treePtr->data.name, treePtr->data.scores );
        writeFile( treePtr->rightPtr, fPtr );
    }
}
*/
