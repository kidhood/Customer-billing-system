#include "stdio.h"
#include "string.h"
#include "time.h"
#include "conio.h"

struct date{
    int month;
    int day;
    int year;
    };
struct account {
    int number;
    char name[100];
    int accNum;
    float mobileNum;
    char streetAddr[100];
    char cityAddr[100];
    char accType;
    float oldBalance;
    float newBalance;
    float payment;
    date lastPayment;
};

typedef account AC;

void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}

void inputOneAccount(AC &customerAcc){
        printf("Enter name: ");
        fflush(stdin); fgets(customerAcc.name, sizeof(customerAcc.name), stdin); xoaXuongDong(customerAcc.name);
        printf("Enter account number: ");
        scanf("%d", &customerAcc.accNum);
        printf("Enter mobile number: ");
        scanf("%f", &customerAcc.mobileNum);
        printf("Enter street address: ");
        fflush(stdin); fgets(customerAcc.streetAddr, sizeof(customerAcc.streetAddr), stdin); xoaXuongDong(customerAcc.streetAddr);
        printf("Enter city address: ");
        fflush(stdin); fgets(customerAcc.cityAddr, sizeof(customerAcc.cityAddr), stdin); xoaXuongDong(customerAcc.cityAddr);
        printf("Enter previous balance: ");
        scanf("%f", &customerAcc.oldBalance);
        do {
        printf("Enter current balance: ");
        scanf("%f", &customerAcc.payment);
    	} while (customerAcc.payment>customerAcc.oldBalance);
        printf("Enter payment date: ");
        scanf("%d/%d/%d", &customerAcc.lastPayment.day,
         &customerAcc.lastPayment.month, &customerAcc.lastPayment.year);
        fflush(stdin);

}

void inputAListOfAccount(AC listCustomerAcc[], int &numOfAcc){
	printf("Enter number of accounts you want to add: ");
    scanf("%d", &numOfAcc);
    int i=0;
    for( i; i < numOfAcc; i++){
    	printf("Input infor of customer number %d \n", i);
    	inputOneAccount(listCustomerAcc[i]);
	}
}

void outputOneCustomer (AC customerAcc) {
	printf("\n\nCustomer no    :%d\n", customerAcc.number);
	printf("    Name:	%s\n", customerAcc.name);
	printf("    Mobile no      :%.f\n", customerAcc.mobileNum);
	printf("    Account number :%d\n", customerAcc.accNum);
	printf("    Street         :%s\n", customerAcc.streetAddr);
	printf("    City           :%s\n", customerAcc.cityAddr);
	printf("    Old balance    :%.2f\n", customerAcc.oldBalance);
	printf("    Current payment:%.2f\n", customerAcc.payment);
	customerAcc.newBalance = customerAcc.oldBalance - customerAcc.payment;
	printf("    New balance    :%.2f\n", customerAcc.newBalance);
	printf("    Payment date   :%d/%d/%d\n\n", customerAcc.lastPayment.day,
         customerAcc.lastPayment.month, customerAcc.lastPayment.year);
	printf("    Account status \n:");
	}

void outputListOfCustomer(AC listCustomerAcc[], int numOfAcc){
	for(int i=0; i < numOfAcc; i++){
		outputOneCustomer(listCustomerAcc[i]);
		printf("\n");
	}
}

void search (AC listCustomerAcc[], int numOfAcc) {
	char ch;
	char name[100];
	int i; 
	printf("Enter the name: ");
	fflush(stdin); fgets(name, sizeof(name), stdin); xoaXuongDong(name);
	for(i = 0; i < numOfAcc; i++) {
		if(strcmp(listCustomerAcc[i].name, name)==0){
			outputOneCustomer(listCustomerAcc[i]);
		}
	}
}

int main(){
	AC listCustomerAcc[100];
	int numOfAcc;
    int i,n;
	int choice;
	do{		
		printf("===============================\n");
		printf("   CUSTOMER BILLING SYSTEM:\n\n");
		printf("\n1:    to add account on list\n");
		printf("2:    to search customer account\n");
		printf("3:    exit\n");
		printf("\n================================\n");
	    printf("\nselect what do you want to do: ");
	    scanf("%d", &choice);
	    switch(choice){
        	case 1: 
            	inputAListOfAccount(listCustomerAcc, numOfAcc);
            	break;
       		case 2: 
       			search(listCustomerAcc, numOfAcc);
            	break;
        	case 3:
        		break;
        	default:
        		printf("Please enter 1-3 option\n");
        		break;
    	}
	}while(choice != 3);
    
}

