#include<stdio.h>
int main()
{
    int data[10],i,n,j,temp;

    //taking the size of array
    printf("How many elements you want to add : \n\n");
    scanf("%d", &n);

    //taking input in array
    printf("\nEnter the elements : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }

    //showing the inputed data
    printf("\nThe given data are : \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",data[i]);
    }

    //bubble sorting
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(data[j]>data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }

        }
    }

    //showing the sorted data
    printf("\n\nThe Sorted Data are : \n\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",data[i]);
    }

    int beg,end,mid,item;
    int choice;

    while(choice)
    {
    printf("\n\nEnter the elements you want to find : \n\n");
    scanf("%d", &item);

    //initializing input for beg and end
    beg=0,end=n-1;
    mid=((beg+end)/2);
    for(i=0; i<n; i++)
    {
        if(item < data[mid])
        {
            end = mid - 1;
            mid=((beg+end)/2);
        }
        else
        {
            beg = mid + 1;
            mid=((beg+end)/2);
        }
    }
    if(item == data[mid])
    {
        printf("\n*** %d is found at index %d ***\n",item,mid);
    }
    else
    {
        printf("\n*** Item is not found ***\n");
    }

    // repeatation
    printf("Do you want to continue(0/1): ");
    scanf("%d",&choice);

    }
    return 0;
}