#include<stdio.h>
struct date{
    int month;
    int day;
    int year;
};
typedef struct account {
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
    struct date lastPayment;
}account;
typedef struct VoMinhHoang{
    int number;
    
}VoMinhHoang;
typedef struct HuynhVanThong{
    
}HuynhVanThong;
void Input();
void Output();

int main(){
    int i,n;
	int choice;
	printf("   CUSTOMER BILLING SYSTEM:\n\n");
	printf("===============================\n");
	printf("\n1:    to add account on list\n");
	printf("2:    to search customer account\n");
	printf("3:    exit\n");
	printf("\n================================\n");
	do{
	    printf("\nselect what do you want to do: ");
	    scanf("%d", &choice);
	}while(choice<= 0|| choice> 3);
    switch(choice){
        case 1: 
            Input();
            break;
        case 2: 
            break;
        case 3:
        return 0;
    }
}//Main
void Input(){
    int numOfAcc, i;
    printf("Enter number of accounts you want to add: ");
    scanf("%d", &numOfAcc);
    account customerAcc[numOfAcc];
    for(i = 0; i < numOfAcc; i++){
        customerAcc[i].number = i;
        printf("Enter name: ");
        scanf(" %[^\n]s", &customerAcc[i].name); fflush(stdin);
        printf("Enter account number: ");
        scanf("%d", &customerAcc[i].accNum);
        printf("Enter mobile number: ");
        scanf("%f", &customerAcc[i].mobileNum);
        printf("Enter street address: ");
        scanf("%s", &customerAcc[i].streetAddr);fflush(stdin);
        printf("Enter city address: ");
        scanf("%s", &customerAcc[i].cityAddr);fflush(stdin);
        printf("Enter previous balance: ");
        scanf("%f", &customerAcc[i].oldBalance);
        printf("Enter current balance: ");
        scanf("%f", &customerAcc[i].newBalance);
        printf("Enter payment date: ");
        scanf("%d/%d/%d",&customerAcc[i].lastPayment.day,
        &customerAcc[i].lastPayment.month, &customerAcc[i].lastPayment.year);
        fflush(stdin);
    }
    for(i = 0; i < 2; i++){
        printf("%s\n", customerAcc[i].name);
        printf("%.1f\n", customerAcc[i].mobileNum);
    }
    return;
}
