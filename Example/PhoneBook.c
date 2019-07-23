#include <stdio.h>
#include <string.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 100};

// the phone book structure
typedef struct phoneaddress_t {
      char name[20];
      char tel[11];
      char email[25];
}phoneaddress;



int inputAdd(phoneaddress phone[]){
	int i;

	printf("Nhap vao so danh ba: "); scanf("%d%*c", &n);
		for (i=0; i<n; i++){
			printf("Nhap ten: "); gets(phone[i].name);
			printf("Nhap sdt: "); gets(phone[i].tel);
			printf("Nhap email: "); gets(phone[i].email);
	}
	return n;
}

void writeAdd(phoneaddress phone[], int n){
	FILE* fptr;

	if ((fptr = fopen("phonebook.dat", "w+b")) == NULL){
		printf("Error\n");
		exit(0);
	} else{
		fwrite(phone, sizeof(phoneadd), n, fptr);
	}
	fclose(fptr);
}

void swap(phoneaddress *phone1, phoneaddress *phone2){
   phoneaddress tmp;

   tmp = *phone1;
   *phone1 = *phone2;
   *phone2 = tmp;
}

void sortAddress(phoneaddress phonearr[], int n){
   for(int i=0; i<n; i++)
   {
      for(int j=i+1; j<n; j++)
      {
         if(strcmp(phonearr[i].name, phonearr[j].name) > 0)
            swap(&phonearr[i], &phonearr[j]);
      }
   }
}

int binarySearch(phoneaddress phone[], int n, char *name, FILE *fout){
   int low, high, mid;
   low=0;
   high = n-1;

   while(lo<hi)
   {
      mid = (low+high)/2;

      if(strcmp(phone[mid].name, name) == 0)
       {
            fprintf(fpout, "%s have the email address %s and telephone number:%s", phone[mid].name,
                 phone[mid].email, phone[mid].tel);
                 return 1;
         }
      else
         if(strcmp(phone[mid].name, name) > 0)
            low = mid +1;
         else
            high = mid-1;

      return 0;   }

}


void printPhoneBook(phoneaddress phone[], int n)
{
   for(int i=1; i<n; i++)
   {
      printf("%-11s %-20s %-25s\n", phone[i].tel, phone[i].name, phone[i].email);
   }
}
int main(void)
{
   FILE *fp, *fpout;
   phoneaddress  phonearr[MAX_ELEMENT];
	 int i,n, irc; // return code
	 char name[20];
   int reval = SUCCESS;

	printf("How many contacts do you want to enter (<100)?");  scanf("%d", &n);
   if ((fp = fopen("phonebook.dat","rb")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
      reval = FAIL;
	}
   irc = fread(phonearr, sizeof(phoneaddress), n, fp);
   printf(" fread return code = %d\n", irc); fclose(fp);
	if (irc <0) {
		printf (" Can not read from file!");
		return -1;
 }
   printPhoneBook(phonearr, n);







	printf("Let me know the name you want to search:");  gets(name);

	int check = binarySearch(phonearr, n, name, fout);
	if(check == 0) puts("Not result be found");

}
