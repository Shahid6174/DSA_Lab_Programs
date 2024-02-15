#include <stdio.h>
#include <stdlib.h>
#define qsize 5
void insert_rear(int item, int *f, int *r, int q[qsize], int *count)
{
    if(*count==qsize)
    {
        printf("Queue overflow.\n");
        return;
    }
    *r = (*r+1)%qsize;
    q[*r] = item;
    *count+=1;
}

void delete_front(int *f, int *r, int q[qsize], int *count)
{
    if(*count == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    int item = q[*f];
    printf("Item deleted is %d\n", item);
    *f = (*f+1)%qsize;
    *count -= 1;
}

void display(int f, int r, int q[qsize], int count)
{
    if(count == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The contents of the queue are: \n");
    for(int i = 0; i<count; i++)
    {
        printf("%d ", q[f]);
        f = (f+1)%qsize;
    }
}

void main()
{
    int f = 0, r = -1;
    int choice;
    int count = 0;
    int item;   
    int q[qsize];
    for(;;)
    {
        printf("1.IR    2.DF    3.Display   4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the item: ");
                    scanf("%d", &item);
                    insert_rear(item, &f, &r, q, &count);
                    break;
            case 2:delete_front(&f, &r, q, &count);
                    break;
            case 3: display(f,r,q,count);
                    break;
            default: return;
        }
    }   
}