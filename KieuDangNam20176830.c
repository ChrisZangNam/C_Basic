#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KieuDangNam20176830.h"


int main()
{
   int choice; int i=0; int k=0; int maxID;
   int soluongmon[NUM_DISHES];
   MonAn data[NUM_DISHES];
   FILE *fPtr;
   int n;//soluongmon
   Request order;
   ListNodePtr root= NULL, cur;

   fPtr = fopen("thucdontheongay.txt", "r");
   if(fPtr == NULL)
      puts("Khong mo duoc file.");


    choice = instruction();

    while(choice != 5)
    {
       switch(choice)
       {
       case 1:
          puts("\t1.Danh sach mon an hom nay \n");
          fscanf(fPtr, "%d\n", &n);
          //NUM_DISHES = n;

          while(!feof(fPtr))
          {
             fscanf(fPtr, "%d%*c%[^ ]%d%ld\n", &data[i].ID, data[i].name, &data[i].ton, &data[i].gia);
             i++;
          }
          printMonAn(data);

          puts("==============================\n");
          break;

       case 2:
          puts("\t2.Nhan Order(yeu cau dat mon) \n");
          printf("Don hang thu %d: \n", k+1);
          order = Order(k+1,data);
          if(checkOrder(data, order) == 1)
          {
             insertFirst(&root, order);
             printf("==> Tong tien phai tra cua order: %ld\n", order.total);
             k++;
             //cap nhat so luong mon an

             for(int i=0; i<NUM_DISHES; i++)
               {
                  data[i].ton = data[i].ton - order.order[i];
               }

             printMonAn(data);
          }
          else
            puts("Xin loi nha hang khong du suat an dap ung yeu cau cua quy khach");

          puts("==============================\n");
          break;

       case 3:
          puts("\t3.Thong tin tat ca order \n");

          printOrder(root, data);

          puts("==============================\n");
          break;

       case 4:
          puts("\t4.Mon an ua chuong nhat ");
            cur = root;
          //cap nhat so luong cac mon

         for(int j=0; j<NUM_DISHES; j++)
            soluongmon[j] = 0;

          if(cur == NULL)
            printf("Khong thong ke duoc do khong co order.");
          while(cur != NULL)
          {
               for(int j=0; j<NUM_DISHES; j++)
               {
                  soluongmon[j] = soluongmon[j] + cur->data.order[j];
               }

               cur = cur->nextPtr;
          }

          maxID = findMax(soluongmon, NUM_DISHES);
          printf("Mon an ua chuong nhat la: %s\nSo luong duoc goi la: %d\n", data[maxID].name, soluongmon[maxID]);

          puts("==============================\n");
          break;

       default:
          puts("Lua chon khong ton tai ! Vui long nhat lai !");
          puts("==============================\n");
          break;
       }//end switch

       choice = instruction();
    }//end while

    puts("Thoat !");
}
