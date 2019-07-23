#include<stdio.h>
#include<stdlib.h>

typedef char elementType;

struct listNode{
	elementType data; // moi listNode  deu gom mot ki tu
	struct listNode *nextPtr; //con tro next node
};

typedef struct listNote ListNode; //dong nghia cho struct listNode
typedef ListNode *ListNodePtr; //dong nghia vowi ListNode*

void insert(ListNodePtr *sPtr, elementType value);
elementType delete(ListNodePtr *sPtr, elementType value);
int isEmpty( ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);

void insertFirst(ListNodePtr *sPtr, elementType value)
{
   ListNodePtr newPtr; //node moi
	ListNodePtr prevPtr;	//node truoc do
	ListNodePtr curPtr; //con tro toi node hien tai

	newPtr = malloc(sizeof(ListNode)); //tao node

	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL; //node ko lien ket voi node khac

		newPtr->nextPtr = *root;
		*root = newPtr ;
	}
   else{
		printf("%c not inserted. No memory available.\n", value);
	}//end else
}


void insertLast(ListNodePtr *sPtr, elementType value)
{
   ListNodePtr newPtr; //node moi
	ListNodePtr prevPtr;	//node truoc do
	ListNodePtr curPtr; //con tro toi node hien tai

	newPtr = malloc(sizeof(ListNode)); //tao node

	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL; //node ko lien ket voi node khac

		if(*root == NULL)
         *root = newPtr;
      else{
         curPtr = *root;
         while(curPtr->next != NULL)
         {
            curPtr = curPtr->nextPtr;
         }

         curPt->nextPtr = newPtr;
      }
	}
   else{
		printf("%c not inserted. No memory available.\n", value);
	}//end else
}



//insert theo thu tu bang chu cai
void insert(ListNodePtr *sPtr, elementType value)
{
	ListNodePtr newPtr; //node moi
	ListNodePtr prevPtr;	//node truoc do
	ListNodePtr curPtr; //con tro toi node hien tai

	newPtr = malloc(sizeof(ListNode)); //tao node

	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL; //node ko lien ket voi node khac

		prevPtr = NULL;
		curPtr = *sPtr; //root=sPtr

		//vong lap de tim kiem vi tri chinh xac trong list(theo thu tu trong abc)
		while(curPtr != NULL && value>curPtr->data){
			prevPtr = curPtr;
			curPtr = curPtr->nextPtr;
		}//end while

		//chen them not vao vi tri bat dau cua list
		if(prevPtr == NULL){ //neu day chua co du lieu
			newPtr->nextPtr = *sPtr; //root;
			*sPtr = newPtr;
		}//end if
		else{	//file da co du lieu, chen vao giua pre va cur
			prevPtr->nextPtr = newPtr;
			newPtr->nextPtr = curPtr;
		} //end else

	}//end if
	else{
		printf("%c not inserted. No memory available.\n", value);
	}//end else

} //end insert


elementType delete(ListNodePtr *sPtr, elementType value)
{
	ListNodePtr prevPtr;
	ListNodePtr curPtr;
	ListNodePtr tempPtr;//temporary node pointer: node tam thoi

 	if(value == (*sPtr)->data){//root->data
		tempPtr= (*sPtr);//=root
		*sPtr = (*sPtr)->nextPtr;
		free(tempPtr);
		return value;
	}//end if
	else{
		prevPtr =*sPtr;
		curPtr=(*sPtr)->nextPtr;

		//vong lap tim kiem vi tri value trong list
		while( curPtr!= NULL && curPtr->data != value){
			prevPtr=curPtr;
			curPtr = curPtr->nextPtr;
		}//end while

		//xoa node tu vi tri curPtr
		if(curPtr != NULL){
			tempPtr = curPtr;
			prevPtr->next=curPtr->nextPtr;
			free(tempPtr);
			return value;
		}//end if
	}//end else
	return '\0';
} //end function delete

//return 1 neu list trong, 0 nguoc lai
int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr curPtr){
	if(isEmpty(curPtr)){
		puts("List is empty");
	 	}
	else{
		puts("The list is: ");

		while(curPtr != NULL) {
			printf("%c --> ", curPtr->data);
			curPtr = curPtr->nextPtr;
		}
		puts("NULL\n");
	}
}
