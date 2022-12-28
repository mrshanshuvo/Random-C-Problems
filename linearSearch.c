#include<stdio.h>
#define N 10

struct linearS
{
    int data[N];
    int num;
    int n;
};

void main()
{
    int i;
    struct linearS find;
    printf("How many elements you wish to enter: ");
    scanf("%d", &find.num);

    printf("Enter %d element in the Program: ",find.num);
    for(i=0; i<find.num; i++)
    {
        scanf("%d", &find.data[i]);
    }

    printf("Enter the element you wish to find: ");
    scanf("%d", &find.n);

    for(i=0; i<find.num; i++)
    {
        if(find.data[i] == find.n)
        {
            printf("%d is Found at %dth index\n",find.data[i],i);
            break;
        }
    }
    if(i == find.num)
    {
        printf("Element is not found in the Program\n");
    }
}