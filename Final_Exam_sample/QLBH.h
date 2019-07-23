#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guest{
   char name[30];
   char phone[15];
}Guest;

typedef Guest elementType;

struct queueNode{
   Guest data;
   struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

int isEmpty(QueueNodePtr headPtr)
{
   return headPtr == NULL;
}

void EnQueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, elementType value)
{
   QueueNodePtr newPtr;

   newPtr = malloc(sizeof(QueueNode));

   if(newPtr != NULL)
   {
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      if(isEmpty(*headPtr))
         *headPtr = newPtr;
      else
         (*tailPtr)->nextPtr = newPtr;

      *tailPtr = newPtr;
   }
   else
   {
      printf("Not inserted. No memory available.\n");
   }
}

elementType DeQueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
   elementType value;
   QueueNodePtr tempPtr;

   value = (*headPtr)->data;
   tempPtr = *headPtr;
   *headPtr = (*headPtr)->nextPtr;

   if(*headPtr == NULL)
      *tailPtr = NULL;

   free(tempPtr);
   return value;
}

void EnQueueFirst(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, elementType value)
{
   QueueNodePtr newPtr;

   newPtr = malloc(sizeof(QueueNode));

   if(newPtr != NULL)
   {
      newPtr->data = value;
      newPtr->nextPtr = *headPtr;
      *headPtr = newPtr;
   }
   else
   {
      printf("Not inserted. No memory available.\n");
   }
}

void printQueue(QueueNodePtr cur)
{
   if(cur == NULL){
      puts("Empty.");
   }
   else{
      puts("The Guest List is: ");

      while(cur != NULL)
      {
         printf("%s\t%s\n", cur->data.name, cur->data.phone);
         cur = cur->nextPtr;
      }
   }
}

