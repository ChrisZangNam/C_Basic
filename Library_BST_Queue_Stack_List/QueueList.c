#include <stdio.h>
#include <stdlib.h>
#include "QueueList.h"

typedef int ElementType;

struct Node{
   ElementType data;
   struct Node *next;
};
typedef struct Node Node;
typedef Node* Position;
typedef struct{
   Position front, rear;
} Queue;

void MakeNullQueue(Queue *Q){
   Position Header; //con tro vi tri dau
   Header = (Node *) malloc(sizeof(Node));

   Header->next = NULL;
   Q->front = Header;
   Q->rear = Header;
}

int EmptyQueue(Queue *Q){
   return (Q->front == Q->rear);
}

void EnQueue(ElementType X, Queue *Q){
   Q->rear->next = (Node *) malloc(sizeof(Node));//cap phat cho con tro tiep theo rear de chen

   Q->rear = Q->rear->next;
   Q->rear->data = X;
   Q->rear->next = NULL;

}

int DeQueue(Queue *Q){
   int value;

   if(!EmptyQueue(Q))
   {
      Position tmp;
      tmp = Q->front;
      value = tmp->data;
      Q->front = Q->front->next;
      free(tmp);
      return value;
   }
   else
      puts("Queue is empty. ");
}

void printQueue(Queue Q){
   if(EmptyQueue(Q))
      puts("Queue is empty. ");
   else{
         Node *p = Q->front;
      puts("The queue is : ");
      while( p != NULL ){
         printf("%5d", p->data);
         p = p->next;
      }
      printf("\n");
      }
}


void instructions(void)
{
   puts("Enter your choice: \n"
        "1. Add an item to the queue \n"
        "2. Remove an item from the queue\n"
        "3. End program \n"
       );
}

int main()
{
   Queue Q;
   unsigned int choice;
   int item;

   instructions();
   printf("%s", "? ");
   scanf("%u", &choice);

   while( choice != 3){

      switch(choice){

      case 1:
         printf("%s", "Enter an integer: ");
         scanf("\n%d", &item);
         EnQueue(item, &Q); //ham chen
  //       printQueue(Q);
         break;

      case 2:
            item = DeQueue(&Q);
            printf("%d has been dequeued. \n", item);

    //     printQueue(Q);
         break;

      default:
         puts("Invalid choice.\n");
         instructions();
         break;
      }//end switch

      printf("%s", "?");
      scanf("%u", &choice);
   }//end while

   puts("End of run.\n");
}
