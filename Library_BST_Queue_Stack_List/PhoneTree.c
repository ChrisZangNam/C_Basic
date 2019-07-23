#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneaddress_t {
      char name[20];
      char tel[11];
      char email[25];
}phoneaddress;

struct Node{
	phoneaddress key;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;
typedef Node* treeType;

typedef struct node_q{
	treeType data;
	struct node_q* next;
}nodeQ;

typedef nodeQ* position;
typedef struct Queue{
	position Front;
	position Rear;
}queue;
typedef queue* QueueType;

void MakeNull_Queue(queue *Q){
	position header;
	header = (nodeQ*)malloc(sizeof(nodeQ));
	header->next=NULL;
	Q->Front = NULL;
	Q->Rear = NULL;
}

int isEmpty(queue *Q){
	return (Q->Front==Q->Rear);
}

void Enqueue(queue *Q, treeType node){
	position tmp;
	tmp = (nodeQ*)malloc(sizeof(nodeQ));
	tmp->data = node;
	tmp->next = NULL;
	if(Q->Front==NULL){
		Q->Front = tmp;
		Q->Rear  = tmp;
	}
	else{
		Q->Rear->next = tmp;
		Q->Rear = tmp;
	}
}

void Dequeue(queue *Q, treeType *node){
	position tmp;
	if(Q->Front==NULL){
		printf("Danh sach rong");
		exit(1);
	}
	else{
		tmp = Q->Front;
		Q->Front = tmp->next;
		*node = Q->Front->data;
		free(tmp);
	}
}

void BFS(treeType node){
	QueueType Q;
	Q = (queue *)malloc(sizeof(queue));
	MakeNull_Queue(Q);
	if (node != NULL){
		Enqueue(Q, node);
		while (isEmpty(queue)){
			Dequeue(Q, node);
			printf(node->data->key->name);
			if (node->left!=NULL){
				Enqueue(Q, node->left);
			}
			if (node->right!=NULL){
				Enqueue(Q, node->right);
			}
		}
	}
}

treeType makeNode(char *name, char *tel, char *email){
	treeType newNode;
	newNode = (treeType)malloc(sizeof(NodeType));
	if (newNode != NULL){
		strcpy((newNode->key).name, name);
		strcpy((newNode->key).tel, tel);
		strcpy((newNode->key).email, email);
		newNode->left=NULL;
		newNode->right=NULL;
	}
	return newNode;
}


void insertNode(treeType *root, char *name, char *tel, char *email){
	if(*root == NULL){
		treeType node = makeNode(name, tel, email);
		*root = node;
	}
	else if(strcmp((*root->key).name, name)<0)
		 insertNode(&(*root)->right, name, tel, email);
	else if(strcmp((*root -> key).name, name)>0)
		insertNode(&(*root) -> left, name, tel, email);
	}
}

int main(void){
	treeType root;
	int choice;
	do
	{
		printf("PHONEBOOK MENU\n");
		printf("1. Them dia chi moi\n");
		printf("2. Doc danh sach tu tep\n");
		printf("3. Ghi danh sach vao tep\n");
		printf("4. Thoat khoi chuong trinh\n");
		do
		{
			printf("Nhap vao lua chon cua ban: ");
			scanf("%d", &choice);
		} while(choice < 1 || choice > 4);

	switch(choice)
	{
		case 1:
			char name[64], tel[64], email[64];
			printf("Name: %s\n", &name);
			printf("Tel: %s\n", &tel);
			printf("Email: %s\n", &email);
			insertNode(root, name, tel, email);
			break;
		case 2:
			readAddress();
			break;
		case 3:
			writeAddress();
			break;
		case 4:
			printf("Thoat khoi chuong trinh¥n");
			break;
		default:
			printf("Lua chon khong hop le¥n");
	}
	} while(choice != 4);
}
