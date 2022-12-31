#include<stdio.h>

int queue[100];
int front=0,back=0;

void enqueue(int var)
{
    queue[back] = var;
    back++;
}

void dequeue()
{
    queue[front] = 0;
    front++;
}

int visited[7] = {0};

int main()
{
    int i,j,n;
    int N  = 6;
    int graph[10][10];
    
    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("\nEnter adjecency matrix of the graph:");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
            scanf("%d",&graph[i][j]);
       }
    }

    enqueue(1);
    visited[0] = 1;
    printf("\nOutput: ");
    while(front != back)
    {
        int current = queue[front];

        printf("%d ", current);

        dequeue();
        for(int i=0;i<6;i++)
        {
            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1;
                enqueue(i+1);
            }
        }
    }
    return 0;
}
