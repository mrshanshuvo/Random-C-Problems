#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}Node;
struct Node *swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp;
    tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;

    return ptr2;
}
int bubbleSort(struct Node** head, int count)
{
    struct Node** h;
    int i, j, swapped;
    for (i = 0; i <= count; i++)
    {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            struct Node* p1 = *h;
            struct Node* p2 = p1->next;

            if (p1->data > p2->data)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }
        if (swapped == 0)
        break;
    }
}
void printList(struct Node* n)
    {
        while (n != NULL)
        {
            printf("%d -> ", n->data);
            n = n->next;
        }
        printf("\n");
    }
void insertBeg(struct Node **start_ref, int data)
    {
        struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));

        ptr1->data = data;
        ptr1->next = *start_ref;
        *start_ref = ptr1;
    }
void main()
 {
    int arr[] = {58, 30, 33, 42, 4, 8};
    int size,i;
    struct Node *start = NULL;
    size = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < size; i++)
    {
        insertBeg(&start, arr[i]);
    }
    printf("Linked list before sorting\n");
    printList(start);

    bubbleSort(&start, size);
    printf("Linked list after sorting\n");
    printList(start);
}
