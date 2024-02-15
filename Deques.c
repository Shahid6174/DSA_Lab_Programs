#include <stdio.h>
#include <stdlib.h>
#define qsize 10
void insert_rear(int item, int *f, int *r, int q[qsize])
{
    if(*r == qsize-1)
    {
        printf("Queue overflow.\n");
        return;
    }
    *r += 1;
    q[*r] = item;
}

void delete_front(int *f, int *r, int q[qsize])
{
    if(*f>*r)
    {
        printf("Queue is empty.\n");
        return;
    }
    int item = q[*f];
    *f += 1;
    printf("Item deleted is %d.\n", item);
    if(*f>*r)
    {
        *f = 0;
        *r = -1;
    }
}
void insert_front(int item, int *f, int *r, int q[qsize])
{
    if(*f==0 && *r != -1)
    {
        printf("You cannot insert from the front.\n");
        return;
    }
    if(*f==0)
    {
        *r += 1;
        q[*r] = item;
        return;
    }
    *f -= 1;
    q[*f] = item;

}
void delete_rear(int *f, int *r, int q[qsize])
{
    if(*f>*r)
    {
        printf("Queue is empty.\n");
        return;
    }
    int item = q[*r];
    printf("Item deleted is %d.\n", item);
    *r -= 1;
    if(*f>*r)
    {
        *f = 0;
        *r = -1;
    }
}
void display(int f, int r, int q[qsize])
{
    if(f>r)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The contents of the queue are: \n");
    for(int i=f; i<=r; i++)
    {
        printf("%d ", q[i]);
    }
}
void main()
{   
    int f = 0, r = -1;
    int choice;
    int item;   
    int q[qsize];
    for(;;)
    {
        printf("1.IR    2.DF    3.IF    4.DR    5.Display   6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the item: ");
                    scanf("%d", &item);
                    insert_rear(item, &f, &r, q);
                    break;
            case 2:delete_front(&f, &r, q);
                    break;
            case 3:printf("Enter the item: ");
                    scanf("%d", &item);
                    insert_front(item, &f, &r, q);
                    break;
            case 4: delete_rear(&f, &r, q);
                    break;
            case 5: display(f,r,q);
                    break;
            default: return;
        }
    }   
}