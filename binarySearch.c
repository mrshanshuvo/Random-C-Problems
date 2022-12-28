#include<stdio.h>
#define N 20

struct binaryS
{
    int data[N];
    int num;
    int item;
};

void main()
{
    struct binaryS find;
    int i;

    printf("Enter how many elements you wish to add: ");
    scanf("%d", &find.num);

    printf("Enter the %d element in ascending order: ",find.num);
    for(i=0; i<find.num; i++)
    {
        scanf("%d", &find.data[i]);
    }

    printf("Enter the element you wish to find: ");
    scanf("%d", &find.item);

    int beg,end,mid;

    // initializing input
    beg = 0, end = find.num-1;
    mid = ((beg+end)/2);

    // applying binary search
    for(i=0; i<find.num; i++)
    {
        if(find.item < find.data[mid])
        {
            end = mid - 1;
            mid = ((beg+end)/2);
        }
        else
        {
            beg = mid + 1;
            mid=((beg+end)/2);
        }
    }
    if(find.item == find.data[mid])
    {
        printf("\n*** %d is found at Position NO. %d ***\n",find.item,mid+1);
    }
    else
    {
        printf("\n*** Item is not found ***\n");
    }

}