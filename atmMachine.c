#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Functions
void login();
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();

int main()
{
    int option,pin;
    float balance = 70000.00;
    int choose;
    bool again = true;

    // insert pass-code here
    while (pin != 1234)
    {
        printf("########                           ########\n\n");
        printf("**************** <HELLO > *****************\n\n");
        printf("**********WELCOME to ATM BANKING***********\n\n");
        printf("########                           ########\n\n");

        printf("ENTER YOUR SECRET PIN NUMBER:");
        scanf("%d",&pin);

        system("CLS");

        printf("\n########                           ########\n\n");
        printf("******* ATM SYSTEM CUSTOMER SERVICES *******");
        if (pin != 1234)
            printf("PLEASE ENTER VALID PASSWORD! \a\n");
    }

    do
    {
        while (again)
        {
            mainMenu();
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("YOUR SELECTION:\t");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                system("CLS");
                checkBalance(balance);
                break;
            case 2:
                system("CLS");
                balance = moneyDeposit(balance);
                break;
            case 3:
                system("CLS");
                balance = moneyWithdraw(balance);
                break;
            case 4:
                system("CLS");
                menuExit();
                return 0;
            default:
                errorMessage();
                break;
            }
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
            printf(" WOULD YOU LIKE TO DO ANOTHER TRANSACTION : \n\n");
            printf("<=> 1.      Yes\n\n");
            printf("<=> 2.      No\n\n");
            printf("PLEASE ENTER 1 OR 2 TO START AGAIN : ");
            scanf("%d", &choose);

            system("CLS");

            if (choose == 2)
            {
                menuExit();
            }
        }
    }
    while (pin = 1234);
    return 0;
}

//Functions
void mainMenu()
{
    printf("\n\n");
    printf("=>  1.   CHECK BALANCE\n");
    printf("=>  2.   DEPOSIT MONEY\n");
    printf("=>  3.   WITHDRAW MONEY\n");
    printf("=>  4.   EXIT\n\n");
}

void checkBalance(float balance)
{
    printf("YOU CHOOSE TO SEE YOUR BALANCE\n");
    printf("\n\n****YOUR AVAILABLE BALANCE IS:   $%.2f\n\n", balance);
}

float moneyDeposit(float balance)
{
    float deposit;
    printf("YOU CHOOSE TO DEPOSIT YOUR CASH MONEY\n");
    printf("$$$$ YOUR BALANCE IS: $%.2f \n\n", balance);
    printf("**** ENTER YOUR AMOUNT TO DEPOSIT IN YOUR ACCOUNT : ");
    scanf("%f", &deposit);

    balance += deposit;

    printf("\n****YOUR NEW BALANCE IS:   $%.2f\n\n", balance);

    return balance;
}

float moneyWithdraw(float balance)
{
    float withdraw;

    printf("YOU CHOOSE TO WITHDRAW MONEY\n");
    printf("$$$$ YOUR BALANCE IS: $%.2f\n\n", balance);

    printf("ENTER YOUR AMOUNT TO WITHDRAW : ");
    scanf("%f", &withdraw);

    if (withdraw < balance)
    {
        balance -= withdraw;

        printf("\n$$$$ YOUR WITHDRAWING MONEY IS:  $%.2f \n", withdraw);
        printf("**** YOUR NEW BALANCE IS:   $%.2f\n\n", balance);
    }
    else
    {
        printf("+++ YOU DON'T HAVE ENOUGH MONEY +++\n");
        printf("PLEASE CONTACT TO YOUR BANK CUSTOMER SERVICES\n");
        printf("**** YOUR BALANCE IS:   $%.2f\n\n", balance);
    }
    return balance;
}

void menuExit()
{
    printf("----------------TAKE YOUR RECEIPT------------------\n");
    printf("------Thank you for using ATM Banking System-------\n");
}

void errorMessage()
{
    printf("\n\n");
    printf("!!!!!! YOU SELECTED INVALID NUMBER !!!!!!\n");
}