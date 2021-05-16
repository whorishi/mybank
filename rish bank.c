#include <stdio.h>
#include <string.h>

void deposit();
void withdraw();
void transactiondetails();
int list();
void transfer();

FILE *fp;
int amt=1000,beneficiary=0;
int bal,trn=0,totdep=0,totwith=0,tottrn=0;

int main()
{
	while(1)
	{
	system("cls");
	printf("\n\t\t**RISHI BANK**");
	switch(list())
	{
		case 1:
			printf("\n\n\tD E P O S I T");
	        deposit();
			break;
			
		case 2:
			printf("\n\n\tW I T H D R A W");
			withdraw();
			break;
			
		case 3:
			printf("\n\n\tT R A N S F E R");
			transfer();
			break;
			
		case 4:
			printf("\n\n\tT R A N S A C T I O N   D E T A I L S ");
			transactiondetails();
			break;
			
		case 5:
			printf("\n\n\tE X I T");
			fclose(fp);
			return 0;
			break;
			
	}
	fclose(fp);
	printf("\npress ENTER KEY to continue.........");
	getch();
    }
	return 0;
}

int list()
{
	int opr;
	printf("\n\t1.DEPOSIT\n\t2.WITHDRAW\n\t3.TRANSFER\n\t4.TRANSACTION DETAILS\n\t5.EXIT\n");
	printf("\tBASE BALANCE: 1000");
	printf("\nEnter Operation:=> ");
	scanf("%d",&opr);
	return opr;
}

void deposit()
{ 
    fp=fopen("passbook.txt","a+");
	int sum=0;
	printf("\n\n\tamount for deposit:  ");
	scanf("%d",&sum);
	amt=amt+sum;
	bal=amt;
	printf("\n\n\tTRANSACTION SUCESSFUL");
	trn++;
	totdep=+sum;
	fprintf(fp,"CREDIT: %d\t\t Curr. BALANCE: %d\n",sum,bal);
}

void withdraw()
{
	fp=fopen("passbook.txt","a+");
	int sum;
	printf("\n\n\tamount to withdraw:  ");
	scanf("%d",&sum);
	if(sum<=amt)
	    amt=amt-sum;
	bal=amt;
	printf("\n\n\tTRANSACTION SUCESSFUL");
	trn++;
	totwith=+sum;
	fprintf(fp,"DEBIT: %d\t\t Curr. BALANCE: %d\n",sum,bal);
}

void transfer()
{
	fp=fopen("passbook.txt","a+");
	int sum;
	char s[20];
	
	label:
	printf("\n\n\tenter benificiary account number(must be of 8 digit): ");
	fflush(stdin);
	scanf("%s",&s);
	if(strlen(s)==8)
	{
	printf("\n\tamount to transfer:  ");
	scanf("%d",&sum);
	if(sum<=amt)
	{
	    amt=amt-sum;
	    bal=amt;
	    beneficiary++;
	    trn++;
	    printf("\n\n\tTRANSACTION SUCESSFUL");
	    tottrn=+sum;
	    fprintf(fp,"DEBIT(acc no.:%s): %d\t\t Curr BALANCE: %d\n",s,sum,bal);
	}
	else
	    printf("\n\tINSUFFICIENT BALANCE!!!");
    }
    else
    {
    printf("\n\tinvalid acc. no.!!!\n\tenter again");
    goto label;
	}
}

void transactiondetails()
{
	printf("\n\n\tBalance= %d",bal);
	printf("\n\tTotal Transactions= %d",trn);
	printf("\n\tBeneficiarys= %d",beneficiary);
	printf("\n\tTOTAL AMOUNT DEPOSIT= %d",totdep);
	printf("\n\tTOTAL AMOUNT WITHDRAWL= %d",totwith);
	printf("\n\tTOTAL AMOUNT TRANSFER= %d",tottrn);
}
