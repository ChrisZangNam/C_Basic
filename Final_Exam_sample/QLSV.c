#include <stdio.h>
#include <stdlib.h>
#include "QLSV.h"



void instruction()
{
   puts("\tQuan li Sinh vien\n"
        "1. Dang Nhap\n"
        "2. Thoat\n");
}

void instructionSV()
{
   puts("=========================\n"
        "1. Xem diem\n"
        "2. Thay doi mat khau\n"
        "3. Ghi lai thong tin len file va Thoat\n");
}

void instructionAd()
{
   puts("=========================\n"
        "1. Them mot sinh vien vao he thong\n"
        "2. In ra danh sach sinh vien\n"
        "3. Xoa sinh vien\n"
        "4. Ghi lai thong tin len file va Thoat\n");
}

int main()
{
   int choice, choiceSv, choiceAd;
   char user[30];
   char pw[30], newpass[30];
   FILE *fPtr;
   TreeNodePtr root = NULL;
   TreeNodePtr sv = NULL;
   SinhVien data;
   int flag, testpass, check;

   fPtr = fopen("danhsach.txt", "r");
   if(fPtr == NULL)
      puts("Khong mo duoc file");

   while(!feof(fPtr)){
       fscanf(fPtr, "%s%*c%s\n", data.username,
                 data.password );
       printf("%s\t%s\n", data.username, data.password);
       //insertNode(&root, data);
   }
   //preOrder(root);

   instruction();
   printf("Lua chon cua ban la: "); scanf("%d", &choice);

   while(choice != 2)
   {
      switch(choice)
      {
      case 1:
        flag = 0;
        check = 0;//khi chua dang nhap thanh cong
         while(flag < 3 && check != 1)
         {
            puts("=========================");
            puts("\tDang Nhap");
            do{
               puts("=========================");
               printf("Unsername: ");
               scanf("%s%*c", user);
               sv = findUsername(root, user);
               if(sv == NULL)
               {
                  puts("Username khong ton tai !");
                  flag++;
               }
               else{
                  testpass = 0;
                  printf("Password : ");
                  scanf("%s%*c", pw);

                  if(strcmp(pw, sv->data.password) != 0)
                  {
                     puts("Password khong dung !");
                     flag++;
                  }//end if
                  else
                  {
                     testpass = 1;
                     puts("Dang nhap thanh cong !");
                     puts("=========================");
                     check = 1;
                  }//end else
               }//end else
            }while(sv != NULL && testpass != 0 && check != 1);
         }//end while

         if(strcmp(sv->data.username, "Admin") != 0)
         {
            instructionSV();
            printf("Nhap lua chon cua ban: ");
            scanf("%d", &choiceSv);
            while(choiceSv != 3)
            {
               switch(choiceSv)
               {
               case 1:
                  printf("Diem cua ban la: %f\n", sv->data.score);
                  break;

               case 2:
                  puts("Nhap mat khau moi: ");
                  scanf("%s%*c", newpass);
                  puts("Nhap lai mat khau moi mot lan nua: ");
                  scanf("%s%*c", pw);
                  while(strcmp(newpass, pw) != 0)
                  {
                     puts("Mat khau nhap lai khong khop ! Vui long nhap lai !");
                     puts("Nhap lai mat khau moi mot lan nua: ");
                     scanf("%s%*c", pw);
                  }
                  puts("Thay doi mat khau thanh cong !");

                  break;

                  default:
                     puts("Khong ton tai lua chon !");
                     break;
                  }//end switchSV
               instructionSV();
               printf("Nhap lua chon cua ban: ");
               scanf("%d", &choiceSv);
            }//end whileSV
            puts("End menu SV.");
            }//end if SV
            else
            {
               instructionAd();
               printf("Nhap lua chon cua ban: ");
               scanf("%d%*c", &choiceAd);
               while(choiceAd != 4)
               {
                  switch(choiceAd)
                  {
                  case 1:
                     puts("Nhap thong tin sinh vien de them vao he thong: ");
                     printf("\tUsername cua sv: ");
                     scanf("%s%*c", data.username);
                     printf("\tPassword cua sv: ");
                     scanf("%s%*c", data.password);
                     printf("\tDiem cua sv    : ");
                     scanf("%f%*c", &data.score);

                     insertNode(&root, data);
                     preOrder(root);

                     break;

                  case 2:
                     inOrder(root->leftPtr);
                     inOrder(root->rightPtr);
                     break;

                  case 3:
                     printf("Nhap username muon xoa: ");
                     scanf("%s%*c", user);
                     sv = findUsername(root, user);
                     if(sv == NULL)
                        printf("Khong ton tai username: %s\n", user);
                     else
                     {
                        if(strcmp(user, "Admin") == 0)
                        {
                           printf("Khong duoc xoa Admin.");
                        }
                        else{
                           root = deleteNode_Name(root, user);
                           printf("Thong tin cua sinh vien vua xoa la:\n");
                           printf("%s\t%s\t%f\n", sv->data.username, sv->data.password, sv->data.score);
                        }
                     }

                     break;

                  default:
                     puts("Khong ton tai lua chon !");
                     break;
                  }//end switchAD
                  instructionAd();
                  printf("Nhap lua chon cua ban: ");
                  scanf("%d%*c", &choiceAd);
               }//end whileAD
               puts("End menu AD.");
            }//end esleAD

         break;

      default:
         puts("Khong ton tai lua chon.\n");
         instruction();
         break;
      }//end switch
      if(flag >= 3)
      {
         puts("Dang nhap that bai.");
         choice = 2;
      }
      else{
         instruction();
         printf("Lua chon cua ban la: ");
         scanf("%d", &choice);
      }
   }//end while
   puts("End of program.");
}
