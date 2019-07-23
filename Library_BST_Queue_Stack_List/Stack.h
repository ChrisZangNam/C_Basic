#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

struct stackNode{
	ElementType data;
	struct stackNode *next;
};
typedef struct stackNode StackNode;
typedef StackNode  *StackNodePtr;

//ham insert node vao stack top
void push(StackNodePtr *top, ElementType info){
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
ElementType pop(StackNodePtr *top){
   StackNodePtr temp; //con tro trung gian de xoa
   ElementType popValue;

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
