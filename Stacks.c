#include <stdio.h>
#define stacksize 10

void push(int item, int *top, int s[])
{
    if(*top == stacksize-1)
    {
        printf("Stack Overflow...\n");
        return;
    }
    *top += 1;
    s[*top] = item;
}

int pop(int *top, int s[])
{
    if(*top == -1)
    {
        return -1;
    }
    int item = s[*top];
    *top -= 1;
    return item;
}

void display(int top, int s[])
{
    if(top == -1)
    {
        printf("Stack is empty...\n");
        return;
    }
    printf("The contents of the stack are: \n");
    for(int i = 0; i<=top; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
}

void main()
{
    int s[stacksize];
    int item, choice, top, y;
    top = -1;
    for(;;)
    {
        printf("Enter 1.Push 2.Pop 3.Display and 4.Exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter item to push: ");
                    scanf("%d", &item);
                    push(item, &top, s);
                    break;
            case 2: y = pop(&top, s);
                    if(y==-1)
                        printf("Stack underflow...\n");
                    else    
                        printf("Item deleted: %d\n",y);
                    break;
            case 3: display(top, s);
                    break;
            default: return;
        }
    }
}