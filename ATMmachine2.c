#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20

int login();
void mainMenu(float);
void checkBalance(float);
void withdrawMoney(float);
void moneyDeposit(float);
void menuExit();
void errorMeassage();

void main()
{
    int i;
    float balance;
    balance = 70000.00;
    i = login();
    system("CLS");
    if(i == 1)
    {
        mainMenu(balance);
    }
}

int login()
{
    int a,b;
    char user[N], pass[N];
    printf("Enter Your Username: ");
    gets(user);
    printf("Enter Your Password: ");
    gets(pass);

    if(!strcmp(user,"mrshan") && !strcmp(pass,"221002038"))
    {
        printf("\nLogged in Successfully\n");
        return 1;
    }
    else
    {
        printf("\nUnsuccessfull to login\n");
        return 0;
    }
}

void mainMenu(float balance)
{
    int choice;
    printf("########### MENU ###########\n");
    printf("\n1. Check Balance \n2. Withdraw Money \n3. Deposit Money \n4. Exit \n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1 :
            system("CLS");
            checkBalance(balance);
            break;
        case 2 :
            system("CLS");
            withdrawMoney(balance);
            break;
        case 3 :
            system("CLS");
            moneyDeposit(balance);
            break;
        case 4 :
            system("CLS");
            menuExit();
            break;
        default :
            errorMeassage();
            break;
    }
}

void checkBalance(float money)
{
    int ch;
    printf("Your Balance is : %.2f\n",money);
    printf("Do you wish to see the MainMenu: \n1. Yes \n2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    if(ch == 1)
    {
        mainMenu(money);
    }
    else
    {
        menuExit();
    }
}

void withdrawMoney(float money)
{
    int ch;
    float num, total = 0.0;
    printf("How much money do you wish to Withdraw: ");
    scanf("%f", &num);
    if(money < num)
    {
        printf("You can not withdraw money\n");
        printf("You have less money (%.2f) than the withdrawn amount (%.2f) you have entered\n", money,num);
    }
    else
    {
        total = money - num;
        printf("Withdrawn Money is: %.2f\n", num);
        printf("After the Withdraw, you have: %.2f\n", total);
    }

    printf("Do you want to do more transaction:  \n1. Yes \n2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    if(ch == 1)
    {
        mainMenu(total);
    }
    else
    {
        menuExit();
    }
}

void moneyDeposit(float money)
{
    int ch;
    float num, total;

    printf("Enter Your Deposition Money: ");
    scanf("%f", &num);
    total = money + num;
    printf("Your Deposited Money is : %.2f\n", num);
    printf("Your Present Balance is : %.2f\n",total);

    printf("Do you want to do more transaction:  \n1. Yes \n2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    if(ch == 1)
    {
        mainMenu(total);
    }
    else
    {
        menuExit();
    }
}

void menuExit()
{
    printf("Thank You\n");
    printf("Please use our system more often\n");
}

void errorMeassage()
{
    printf("INVALID CHOICE\n");
    printf("Don't be oversmart\n Select Your choice more accurately (1-4)\n");
}