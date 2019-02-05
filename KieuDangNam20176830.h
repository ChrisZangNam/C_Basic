#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DISHES 7

typedef struct monan{
   int ID;
   char name[255];
   int ton;
   long gia;
} MonAn;


typedef struct request{
   int ID;
   int order[NUM_DISHES];
   long total;
}Request;

typedef Request elementType;

struct listNode{
	elementType data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;



void insertFirst(ListNodePtr *root, elementType value);
int instruction();
void printMonAn(MonAn data[]);

void insertFirst(ListNodePtr *root, elementType value)
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


void printMonAn(MonAn data[])
{
   printf("%-3s%-30s%-15s%-10s\n", "ID", "Ten mon", "So luong ton", "Gia tien");
   for(int i=0; i<NUM_DISHES; i++)
      if(data[i].ton>0)
         printf("%-3d%-30s%-15d%-10d\n", data[i].ID, data[i].name, data[i].ton, data[i].gia);
}




int instruction()
{
   int choice;
   puts("\n\tQuan Li Nha Hang \n"
        "1. Danh sach mon an hom nay \n"
        "2. Nhan Order(yeu cau dat mon)\n"
        "3. Thong tin tat ca order\n"
        "4. Mon an ua chuong nhat\n"
        "5. Thoat\n");
   printf("Enter your choice: ");
   scanf("%d%*c", &choice);
   puts("==============================");

   return choice;
}


Request Order(int ID, MonAn monan[])
{
   Request data;
   data.ID = ID+1;
   int num;
   data.total = 0;

   printf("Nhap so luong mon an: \n");
   for(int i=0; i<NUM_DISHES; i++)
   {

      do{
      printf("Mon an co ID %d: ", i+1);
      scanf("%d", &data.order[i]);

      if(data.order[i] <0) printf("Nhap lai so luong mon >= 0\n");
      }while(data.order[i] <0 );

      data.total += (data.order[i]*monan[i].gia);
      }

   return data;
}


MonAn* updata(MonAn monan[], Request order)
{
   for(int i=0; i<NUM_DISHES; i++)
   {
      monan[i].ton = monan[i].ton - order.order[i];
   }

   return monan;
}

int checkOrder(MonAn monan[], Request order)
{
   for(int i=0; i<NUM_DISHES; i++)
   {
      if(order.order[i] > monan[i].ton )
      {
         return 0;
         break;
      }
   }

   return 1;
}

void printOrder(ListNodePtr root, MonAn monan[])
{
   if(root == NULL)
      printf("Khong co order.\n");
      int i=0;

   while(root != NULL)
   {
      printf("Don hang so %d\n", i+1);
      printf("%-20s %-10s %-30s\n", "Mon da chon", "So luong", "Thanh tien");
      for(int j=0; j< NUM_DISHES; j++)
      {
         if(root->data.order[j] > 0)
            printf("%-20s %-10d %-30d\n", monan[j].name, root->data.order[j], (monan[j].gia)*(root->data.order[j]) );
      }
      printf("Tong hoa don thanh toan: %ld\n", root->data.total);
      i++;
      root = root->nextPtr;
   }
}

int findMax(int a[], int n)
{
   int numMax= a[0], maxID=0;

   for(int i=0; i<n; i++)
   {
      if(a[i] > numMax)
         maxID = i;
   }

   return maxID;
}
