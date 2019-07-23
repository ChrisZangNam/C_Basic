#include <stdio.h>

#define MAxLength 10

typedef int ElementType;

typedef struct{
   ElementType Element[MaxLength];
   int front;
   int rear;
}Queue;

void MakeNull_Queue(Queue *Q){
   Q->front = -1;
   Q->rear = -1;
}

int Empty_Queue(Queue Q){
   return Q.front == -1;
}

int Full_Queue( Queue Q){
   return (Q.rear - Q.front +1) == MaxLength;
}

void EnQueue(ElementType X, Queue *Q){
   if(!Full_Queue(*Q)){
      if(Empty_Queue(*Q))
         Q->front = 0;
      Q->rear = Q->rear+1;
      Q->Element[Q->rear] = X;
   }
   else
      printf("Queue is full ! \n");
}

ElementType DeQueue(Queue *Q){
   ElementType value;
   if(!Empty_Queue(*Q)){
      value = Q->Element[Q->front];
      Q->front = Q->front + 1;
      if(Q->front > Q->rear)
         MakeNull_Queue(Q);
   }
   else
      printf("Queue is empty !\n");

   return value;
}
