#include <stdio.h>
#include <math.h>
#include <string.h>
#define stacksize 100

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

int evaluate(char postfix[])
{
    int top = -1;
    char symbol;
    int i;
    int op1, op2, res;
    int n = strlen(postfix);
    int s[stacksize];
    for(i=0; i<n; i++)
    {
        symbol = postfix[i];
        switch(symbol)
        {
            case '+':op2 = pop(&top,s);
                     op1 = pop(&top,s);
                     res = op1+op2;
                     push(res,&top,s);
                     break;   
            case '-':op2 = pop(&top,s);
                     op1 = pop(&top,s);
                     res = op1-op2;
                     push(res,&top,s);
                     break;   
            case '*':op2 = pop(&top,s);
                     op1 = pop(&top,s);
                     res = op1*op2;
                     push(res,&top,s);
                     break;   
            case '/':op2 = pop(&top,s);
                     op1 = pop(&top,s);
                     res = op1/op2;
                     push(res,&top,s);
                     break;   
            case '%':op2 = pop(&top,s);
                     op1 = pop(&top,s);
                     res = op1%op2;
                     push(res,&top,s);
                     break;   
            case '$':
            case '^':op2 = pop(&top,s);
                     op1 = pop(&top,s);
                     res = (int)pow((double)op1,(double)op2);
                     push(res,&top,s);
                     break;   
            default: push(symbol-'0', &top, s);

        }
    }
    return(pop(&top,s));
}

void main()
{
    char postfix[20];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int res = evaluate(postfix);
    printf("The result is %d.\n", res);
}

