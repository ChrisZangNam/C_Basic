/*Make a queue that holds integers. The size of the queue is fixed to 10.
Read integers separated by spaces from the standard input, and add them to the queue. When the program reads the 11th integer, the queue is already full. So the program removes the first integer and adds the 11th integer. Print the removed integer to the standard output.
Process all the integers in this way.*/

#include <stdio.h>
#include <stdlib.h>

#define MaxLength 3

struct node{
   int data;
   struct node *next;
};

typedef struct node QueueNode;
typedef QueueNode *QueueNodePtr;

typedef struct node StackNode;
typedef StackNode *StackNodePtr;

void enQueue(QueueNodePtr *head, QueueNodePtr *tail, int value);
int deQueue(QueueNodePtr *head, QueueNodePtr *tail);
void printQueue(QueueNodePtr cur);
int countQueue(QueueNodePtr head);
int isFull(QueueNodePtr head);
//int isEmpty(QueueNodePtr head);

void push(StackNodePtr *top, int value);
void printStack(StackNodePtr top);

int main(){
   int choice, value, popValue;
   QueueNodePtr head = NULL, tail = NULL;
   StackNodePtr stack = NULL;


   do{
      printf("Enter the integer: ");
      scanf("%d", &value);

      enQueue(&head, &tail, value);
      printf("The queue is: ");
      printQueue(head);
      printStack(stack);
      printf("\n");

      if(countQueue(head) == MaxLength){
            popValue = deQueue(&head, &tail);
            push(&stack, popValue);
      }

      printf("Enter 1 to continue, 0 to end program: ");
      scanf("%d", &choice);

   }while(choice != 0);

   return 0;
}

void push( StackNodePtr *top, int data )
{
	StackNodePtr newPtr;

	newPtr = malloc( sizeof( StackNode ) );
	newPtr->data = data;
	newPtr->next = *top;
	*top = newPtr;
}

void printStack( StackNodePtr current )
{
   if(current != NULL){
   printf("-->");
	while ( current != NULL ) {
		printf( "%5d", current->data );
		current = current->next;
	}
	puts("\n");
   }
}

void enQueue(QueueNodePtr *head, QueueNodePtr *tail, int value)
{
   QueueNodePtr new;
   new = malloc(sizeof(QueueNode));

   if(new == NULL)
      puts("No memory available.");
   else{
      new->data = value;
      new->next = NULL;

      if(isEmpty(*head))
         *head = new;
      else
         (*tail)->next = new;

      *tail = new;
   }
}

int deQueue(QueueNodePtr *head, QueueNodePtr *tail)
{
   int value;
   QueueNodePtr tmp;

   tmp = *head;
   value = (*head)->data;
   *head = (*head)->next;

   if(*head == NULL)
      *tail = NULL;

   free(tmp);

   return value;
}

void printQueue(QueueNodePtr cur)
{
   if(cur == NULL)
      puts("NULL\n");
   else{
      while(cur != NULL){
         printf("%5d ", cur->data);\
         cur = cur->next;
      }
      printf("\n");
   }
}

int isEmpty(QueueNodePtr head)
{
   return head == NULL;
}

int countQueue(QueueNodePtr head)
{
      int count=0;
      QueueNodePtr cur = head;

      while(cur != NULL){
         count++;
         cur = cur->next;
      }
      return count;
}


