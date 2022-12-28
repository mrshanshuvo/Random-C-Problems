#include<stdio.h>
#define N 20
struct sort
{
    int data[N];
    int num;
    int n;
};

void main()
{
    struct sort find;
    int i;
    printf("Enter how many elements you wish to add : ");
    scanf("%d", &find.num);

    printf("Enter %d element in the Program : ",find.num);
    for(i=0; i<find.num; i++)
    {
        scanf("%d", &find.data[i]);
    }
}