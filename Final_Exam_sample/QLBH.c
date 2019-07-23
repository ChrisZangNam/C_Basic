#include <stdio.h>
#include <stdlib.h>
#include "QLBH.h"

void instruction()
{
   puts("\tQUAN LI BAN HANG \n"
        "1. Doc file danhsach.txt\n"
        "2. Them nguoi mua vao hang doi\n"
        "3. Ban hang\n"
        "4. Ghi thong tin sau mot ngay\n"
        "5. Thong ke thong tin ban hang\n"
        "6. Yeu cau dac biet\n"
        "7. Thoat\n");
}


int main(){
   int choice;
   QueueNodePtr headPtr = NULL;
   QueueNodePtr tailPtr = NULL;
   QueueNodePtr cur;
   Guest data;
   FILE *fPtr1;
   FILE *fPtr2;
   int a, b, c,sumA=0, sumB=0, sumC=0, i, sum = 0;

   fPtr1 = fopen("danhsach.txt", "r+");
   if(fPtr1 == NULL)
      puts("khong mo duoc file");

   fPtr2 = fopen("banhang.txt", "a");
   if(fPtr2 == NULL)
      puts("Khong mo duoc file.");

   instruction();
   printf("Lua chon cua ban la: "); scanf("%d%*c", &choice);
   puts("=========================");
   while(choice != 7)
   {
      switch(choice)
      {
      case 1:
         puts("Doc file danhsach.txt");
         puts("=========================");

         while(!feof(fPtr1))
         {
            fscanf(fPtr1, "%s%*c%s\n", data.name, data.phone);
            printf("%s\t%s\n", data.name, data.phone);
            EnQueue(&headPtr, &tailPtr, data);
         }
         //printQueue(headPtr);
         fclose(fPtr1);
         puts("\n=========================\n");
         break;

      case 2:
         puts("Them nguoi mua vao hang doi.\n");
         puts("=========================");

         printf("Nhap ten khach hang: ");
         gets(data.name);
         while(strchr(data.name, ' ') != NULL)
         {
            printf("Nhap ten khach hang khong co dau cach: ");
            gets(data.name);
         }

         printf("Nhap so dien thoai : ");
         scanf("%s%*c", data.phone);

         EnQueue(&headPtr, &tailPtr, data);
         puts("\n=========================\n");
         break;

      case 3:
         puts("Ban hang.\n");
         puts("=========================");
         if(headPtr != NULL)
         {
            printf("Thong tin cua khach hang :\n");
            data = DeQueue(&headPtr, &tailPtr);
            printf("%s\t%s\n", data.name, data.phone);
            printf("So luong san pham moi loai (>=0): \n");
            printf("\tSan pham A: "); scanf("%d", &a);
            printf("\tSan pham B: "); scanf("%d", &b);
            printf("\tSan pham C: "); scanf("%d", &c);

            fprintf(fPtr2, "%d\t%d\t%d\n", a, b, c);
         }
         else
            puts("Da het khach hang.");

         puts("\n=========================\n");
         break;

      case 4:
         puts("Ghi thong tin sau mot ngay.\n");
         puts("=========================");

         fPtr1 = fopen("danhsach.txt", "w");
         if(fPtr1 == NULL)
            puts("khong mo duoc file");

         fprintf(fPtr2, "%d\n", -1);

         if(headPtr == NULL)
            puts("Khong con khach hang trong hang doi.");
         else{
            printf("Danh sach khach hang trong hang doi la: \n");
            cur = headPtr;
            while(cur != NULL)
            {
               printf("\t%s\t%s\n", cur->data.name, cur->data.phone);
               fprintf(fPtr1, "%s\t%s\n", cur->data.name, cur->data.phone );
               cur = cur->nextPtr;
            }
         }
         fclose(fPtr1);
         fclose(fPtr2);
         puts("\n=========================\n");
         break;

      case 5:
         puts("Thong ke thong tin ban hang.\n");
         puts("=========================");

         fPtr2 = fopen("banhang.txt", "r");

         fscanf(fPtr2, "%d%*c", &a);
         i = 1;
         while(!feof(fPtr2)){
            printf("Ngay thu %d: \n", i);
            while(a != -1)
            {
               sumA+=a;
               fscanf(fPtr2, "%d%*c", &b);
               sumB+=b;
               fscanf(fPtr2, "%d%*c", &c);
               sumC+=c;
               fscanf(fPtr2, "%d%*c", &a);
            }
            sum = sumA*10 + sumB*50 + sumC*80;
            printf("\nSo luong ban duoc cua cac san pham la: \n");
            printf("\tSan pham A: %d\n", sumA);
            printf("\tSan pham B: %d\n", sumB);
            printf("\tSan pham C: %d\n", sumC);
            printf("Tong so tien ban duoc trong ngay: %d trieu dong\n\n", sum);

            fscanf(fPtr2, "%d%*c", &a);
            i++;
         }

         fclose(fPtr2);

         puts("\n=========================\n");
         break;

      case 6:
         puts("Yeu cau dac biet.\n");
         puts("=========================");

         puts("Them nguoi mua vao dau hang doi.\n");
         puts("=========================");
         printf("Nhap ten khach hang: ");
         scanf("%s%*c", data.name);
         printf("Nhap so dien thoai : ");
         scanf("%s%*c", data.phone);

         EnQueueFirst(&headPtr, &tailPtr, data);
         printQueue(headPtr);
         puts("\n=========================\n");

         puts("\n=========================\n");
         break;

      default:
         puts("Lua chon khong ton tai.");
         break;
      }//end switch
      instruction();
      printf("\nLua chon cua ban la: "); scanf("%d%*c", &choice);
   }//end while

   return 0;

}
