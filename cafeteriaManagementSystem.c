#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Item
{
    char name[50];
    float rating;
    float price;
    int food_Id_No;
    struct Item *next;
    struct Item *prev;
};
int cust_id=1;
struct Item *head;
struct Item *last;
int Today_custmer = 0;
float total_income = 0;

struct order_hist
{
    int Customer_ID;
    int items [10][2];
    float amount;
    char date [11];

    struct order_hist *next;
    struct order_hist *prev;
};
struct order_hist *head1;
struct order_hist *last1;
struct Item* getnewNode(char a[],float p,int fin)
{
    struct Item *temp = (struct Item *)malloc(sizeof (struct Item));
    temp->food_Id_No = fin;
    strcpy(temp->name,a);
    temp->rating = 4.0;
    temp->price = p;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
};

void insert(char n[],float p, int fin)
{
    struct Item*temp1=getnewNode (n,p,fin);
    if(head == NULL)
    {
        head = temp1;
        last = temp1;
    }
    else
    {
        temp1->prev = last;
        last->next = temp1;
        last = temp1;
    }
}
struct order_hist *getnewNode_hist()
{
    struct order_hist *temp=(struct order_hist *)malloc(sizeof(struct order_hist));
    temp->next = temp->prev = NULL;
    return (temp);

};


void Display()
{
    printf("################ MENU ###############\n\n");
    printf("------------------------------------\n");
    printf("INDEX       ITEM      PRICE     RATING \n");
    struct Item *temp = head;
    if(head == NULL)
    {
        printf("!! EMPTY !!\n");
    }
    while(temp != NULL)
    {
        printf("%d \t %s \t %f\n", temp->food_Id_No, temp->name, temp->price, temp->rating);
        temp = temp->next;
    }
    printf("-------------------------------------\n");
}

int login()
{
    char username [20];
    char userpwd [11];
    int i;
    printf("ENTER YOUR USERNAME: ");
    scanf("%s", username);

    printf("ENTER YOUR PASSWORD: ");
    for(i=0; i<8; i++)
    {
        userpwd[i]=getch();
        printf("*");
    }

    userpwd [i]= '\0';

    if(!strcmp(username,"mrshan") && !strcmp(userpwd,"shan1234"))
    {
        printf("\n\n LOGGED IN SUCCESSFULL \n");
        return 1;
    }
    else
    {
        printf("\n!! INCORRECT USERNAME OR PASSWORD !!\n");
        return 0;
    }
}
void order()
{
    int a[10][2];
    int n,j=0,i=0;
    do
    {
        printf("\n PLEASE enter the |FOOD ID NUMBER of ITEM|  and  |Its QUANTITY| : ");
        for(i=0; i<2; i++)
        {
            scanf("%d",& a[j][i]);
        }
        j++;
        printf("\nDo You Want to ORDER more?\n 1. YES\n 2. NO\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&n);

    }
    while (n == 1);
    float total_amount =0.0;
    char name[25];
    char Date [10];
    printf("\nENTER YOUR NAME: ");
    scanf("%s",name);
    printf("\nENTER TODAYS DATE: ");
    scanf("%s",Date);
    int k=0;
    printf("\n--------------------------------------\n");
    printf("                     BILL               \n");
    printf("\nNAME:- %s\n", name);
    printf("\nDATE:- %s\n", Date);

    for(k=0; k<j; k++)
    {
        struct Item *temp=head;
        while(temp->food_Id_No != a[k][0])
        {
            temp = temp->next;
        }
        printf("\n---------------------------------------\n");
        printf("\n%d\t %s \t %d \t %f\n",temp->food_Id_No,temp->name,a[k][1],(a[k][1]*(temp->price)));
        total_amount+=(a[k][1]*(temp->price));
    }
    printf("\n---------------------------------------------\n");
    printf("\n TOTAL PAYMENT : \t %f \n",total_amount);
    printf("\n-----------------------------------------------\n");
    struct order_hist*temp2 = getnewNode_hist();
    temp2->amount = total_amount;
    temp2->Customer_ID = cust_id++;

    int p,s;
    for(p=0; p<j; p++)
    {
        for(s=0; s<2; s++)
        {

            temp2->items[p][s] = a[p][s];
        }
    }
    if(head1 == NULL)
    {
        head1 = last1 = temp2;
    }
    else
    {
        last1->next = temp2;
        temp2->prev = last1;
        last1 = temp2;
    }
    strcpy(temp2->date, Date);
    Today_custmer++;
    total_income += total_amount;
}
void display_rd_hist()
{
    printf("ORDER HISTORY: \n");
    printf("NO    DATE    TOTAL AMOUNT\n");

    struct order_hist *temp=head1;
    if(head1 == NULL)
    {
        printf("EMPTY\n");
    }
    while(temp != NULL)
    {
        printf("%d \t %s\t%f\t \n", temp->Customer_ID, temp->date, temp->amount);
        temp = temp->next;
    }
}

int main()
{
    last=NULL;
    head=NULL;
    insert("Coffee        ",70.23,1);
    insert("Tea           ",25.67,2);
    insert("Hot Cake      ",75.63,3);
    insert("Snacks        ",70.23,4);
    insert("Ice-Cream     ",79.23,5);
    insert("Chicken Roast ",150.50,6);
    insert("Beef Bhuna    ",200.32,7);
    int choice;
    do
    {
        printf("--------------------\n");
        printf("1. FOOD PART\n");
        printf("2. ADMIN PANEL\n");
        printf("3. Exit\n");
        printf(" Enter Your CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("");
            int ex;
            do
            {
                int n;
                printf("1. FOOD LIST   \n2. ORDER  \n");
                printf("Enter Your Choice: ");
                scanf("%d",&n);

                switch(n)
                {
                case 1:
                    Display();
                    break;
                case 2:
                    order();
                    break;
                }
                printf("1. FOOD PART\n2. MAIN MENU\n");
                scanf("%d",&ex);

            }
            while(ex==1);
            break;
        case 2:
            printf("\n");
            int k=login();
            int e;
            if(k == 1)
            {
            do
            {
                printf("------------------------\n");
                printf("1. ADD NEW DISH\n");
                printf("2. TODAYS TOTAL INCOME\n");
                printf("3. TODAYS TOTAL CUSTOMER\n");
                printf("4. ORDER HISTORY\n");
                printf("------------------------\n");
                printf("Enter your Choice: ");
                int ch;
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    printf("\n");
                    float p;
                    int fin;
                    char n[50];

                    printf("ENTER THE NAME OF ITEM: ");
                    scanf("%s",n);

                    printf("ENTER THE PRICE OF THE ITEM: ");
                    scanf("%f",&p);
                    printf("ENTER THE FOOD ID OF THE ITEM: ");
                    scanf("%d",&fin);

                    insert(n,p,fin);
                    printf(" -------------------------- \n");
                    printf(" NEW DISH ADDED SUCCESSFULLY \n");
                    printf(" --------------------------- \n");
                    printf("\n");
                    break;

                case 2:
                    printf("TODAYS TOTAL INCOME: %f\n",total_income); break;
                case 3:
                    printf("TODAYS TOTAL CUSTOMER: %d\n", Today_custmer); break;
                case 4:
                    printf(" ORDER SUMMARY \n");
                    display_rd_hist();
                    printf("\n");
                    break;
                case 5:
                    printf("\n");
                    Display();
                    break;
                }
            }
            while(ex==2);
            }
        }
    }
    while(choice!=3);
}