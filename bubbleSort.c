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
    int i,j,temp;
    printf("Enter how many elements you wish to add : ");
    scanf("%d", &find.num);

    printf("Enter %d element in the Program : ",find.num);
    for(i=0; i<find.num; i++)
    {
        scanf("%d", &find.data[i]);
    }

    printf("\nThe given data are : \n");
    for(i=0; i<find.num; i++)
    {
        printf("%d\t",find.data[i]);
    }
    //bubble sorting
    for(i=0; i<find.num-1; i++)
    {
        for(j=0; j<find.num-i-1; j++)
        {
            if(find.data[j]>find.data[j+1])
            {
                temp = find.data[j];
                find.data[j] = find.data[j+1];
                find.data[j+1] = temp;
            }

        }
    }
    //showing the sorted data
    printf("\n\nThe Sorted Data are : \n\n");
    for(i=0; i<find.num; i++)
    {
        printf("%d\t",find.data[i]);
    }
}