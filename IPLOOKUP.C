#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "IPlookup.h"

void instruction()
{
    puts("\tIP Look Up Program \n"
         "1. Read data from file ip.txt\n"
         "2. Search IP\n"
         "3. Block web\n"
         "4. Sort IP\n"
         "5. Exit program\n");
}


int main()
{
    TreeNodePtr root = NULL;
    TreeNodePtr cur;
    IPtype data;
    BlockedList blockroot = NULL;
    int choice;
    FILE *fPtr, *fPtr1;
    char ipSearch[20], blocked[50], input[50];
    TreeNodePtr result;
    IPtreePtr IProot = NULL;

    fPtr = fopen("ip.txt", "r");
    if(fPtr == NULL)
        puts("Can not ope file.");

    fPtr1 = fopen("blockedip.txt", "r");
    if (fPtr1 == NULL)
        puts("Can not ope file.");

    instruction();
    printf("Your choice is: ");
    scanf("%d%*c", &choice);

    while(choice != 5)
    {
        switch(choice){
            case 1:
                puts("\tRead data from file ip.txt\n");

                while(!feof(fPtr))
                {
                    fscanf(fPtr, "%[^ ] %[^\n]\n", data.digistar, data.ip);
                    printf("%s  %s\n", data.digistar, data.ip);
                    insertNode(&root, data);
                }
                rewind(fPtr);
                break;

            case 2:
                puts("\tSearch IP\n");
                printf("Enter the digistar: ");
                gets(ipSearch);

                result = SearchIP(root, ipSearch);
                if(result == NULL)
                    puts("The site can't be reached.");
                else
                    printf("Redirecting to %s\n", result->data.ip);
                break;

            case 3:
                puts("\tBlocked IP\n");
                while(!feof(fPtr1))
                {
                    fscanf(fPtr1, "%[^\n]\n", blocked );
                    //printf("%s\n", blocked);
                    insertLast(&blockroot, blocked);
                }
                printList(blockroot);

                printf("Enter the IP to search: ");
                gets(input);
                result = SearchDigistar(root, input);

                if(result == NULL)
                    puts("The site can't be reached.");
                else
                {
                   if(checkBlocked(blockroot, input) || checkBlocked(blockroot, result->data.digistar))
                   {
                     puts("This site is has been blocked.");
                   }
                  else
                     printf("Redirecting to %s\n", result->data.digistar);
                }
                fclose(fPtr1);
                break;

            case 4:
                puts("\tSort IP\n");

                /*while(!feof(fPtr))
                {
                    fscanf(fPtr, "%[^ ] %[^\n]\n", data.digistar, data.ip);
                    //printf("%s  %s\n", data.digistar, data.ip);
                    insertIPNode(&IProot, data.ip);
                }*/


                  insertIPNode(&IProot, "172.217.9.238");
                  insertIPNode(&IProot, "172.217.7.5");
                  insertIPNode(&IProot, "157.240.14.35");
                printf("%d\n",  compareIP("172.217.9.238","157.240.14.35"));
                printf("%d\n",  compareIP("172.217.7.5","157.240.14.35"));
                inOrderIP(IProot);
                fclose(fPtr);
                break;

            default:
                puts("Invalid choice. Please enter again !");
                break;
        }
        instruction();
        printf("Your choice is: ");
        scanf("%d%*c", &choice);
    }
    puts("End of program.");
}
