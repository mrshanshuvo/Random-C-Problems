#include<stdio.h>
#define N 10

void main()
{
    int  col, row, num, k;
    float A[N][N], div, x[10], sum = 0.0;
    printf("\nEnter the order of the MATRIX: ");
    scanf("%d", &num);

    printf("\nEnter the MATRIX elements:\n");
    for(row=1; row<=num; row++)
    {
        for(col=1; col<=(num+1); col++)
        {
            printf("A[%d][%d] : ",row,col);
            scanf("%f", &A[row][col]);
        }
        printf("\n");
    }
    printf("\nMATRIX elements:\n");
    for(row=1; row<=num; row++)
    {
        for(col=1; col<=num+1; col++)
        {
            printf("%.2f\t", A[row][col]);
        }
        printf("\n");
    }
    // main calculation
    for(col=1; col<=num; col++)
    {
        for(row=1; row<=num; row++)
        {
            if(row > col)
            {
                div = A[row][col] / A[col][col];
                for(k=1; k<=num+1; k++)
                {
                    A[row][k] = A[row][k] - div * A[col][k];
                }
            }
        }
    }
    
    x[num] = A[num][num+1] / A[num][num];

    // backward loop for substractions
    for(row=num-1; row>=1; row--)
    {
        sum = 0;
        for(col=row+1; col<=num; col++)
        {
            sum = sum + A[row][col] * x[col];
        }
        x[row] = (A[row][num+1]-sum) / A[row][row];
    }

    printf("\nThe Solution is: \n");
    for(row=1; row<=num; row++)
    {
        printf("X[%d] : %.2f\n",row,x[row]);
    }
}