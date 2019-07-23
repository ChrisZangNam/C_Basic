#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

/*struct stackNode{
	int data;
	struct stackNode *next;
};

typedef struct stackNode StackNode;
typedef struct stackNode  *StackNodePtr;

void push(StackNodePtr *top, int info);
int pop(StackNodePtr *top);
int isEmpty(StackNodePtr top);
void printStack(StackNodePtr cur);*/
void instructions();

int main()
{
	StackNodePtr stackPtr = NULL;//con tro toi stack top
	unsigned int choice;
	int value;

	instructions();
	printf("%s", "?");
	scanf("%u", &choice);

	while(choice != 3){

        switch(choice){
            case 1:
                printf("%s", "Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);

                printStack(stackPtr);
                break;

            case 2:
                if(isEmpty(stackPtr)){
                    printf("The popped value is %d.\n", pop(&stackPtr));
                }
                printStack(stackPtr);
                break;

            default:
               puts("Invalid choice.\n");
               instructions();
               break;
         }

       printf("%s", "?");
       scanf("%u", &choice);
	}

   puts("End of run.");
}


//menu
void instructions(){
   puts("Enter choice: \n"
        "1 to push a value on the stack\n"
        "2 to pop a value off the stack\n"
        "3 to end program");
}


/*//ham insert node vao stack top
void push(StackNodePtr *top, int info){
   StackNodePtr new;

   new = malloc(sizeof(StackNode));

   if(new != NULL)
   {
      new->data = info;
      new->next = *top;
      *top = new;
   }
   else{
      printf("%d not inserted. No memory available. \n");
   }
}

//remove node tu vi tri stack top
int pop(StackNodePtr *top){
   StackNodePtr temp; //con tro trung gian de xoa
   int popValue;

   temp = *top;
   popValue = (*top)->data;
   *top = (*top)->next;
   free(temp);
   return popValue;
}

//print Stack
void printStack(StackNodePtr cur){
   if(cur == NULL)
      puts("The stack is empty.");
   else{
      puts("The stack is: ");

      while(cur != NULL){
         printf("%d --> ", cur->data);
         cur = cur->next;
      }
      puts("NULL.\n");
   }
}

int isEmpty(StackNodePtr top){
   return top == NULL;
}
*/
