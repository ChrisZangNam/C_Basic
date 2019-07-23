#include <stdio.h>
#include <stdlib.h>

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
