#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char ssn[20];
    char name[30];
    char dept[20];
    char desg[20];
    int salary;
    char phno[20];

    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE insert_front(char ssn[20],char name[30],char dept[20],char desg[20],int salary,char phno[20],NODE first)
{   
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->ssn, ssn);
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->salary = salary;
    strcpy(temp->phno, phno);
    temp -> llink = NULL;
    temp -> rlink = NULL;

    if(first == NULL)
    {
        return temp;
    }

    temp->rlink = first;
    first->llink = temp;
    return temp;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if(first->rlink == NULL)
    {
        printf("Item deleted with following contents: \n");
        printf("USN: %s\n", first->ssn);
        printf("Name: %s\n", first->name);
        printf("Dept: %s\n", first->dept);
        printf("Desg: %s\n", first->desg);
        printf("Salary: %d\n",first->salary);
        printf("Phno: %s\n", first->phno);
        free(first);
        return NULL;
    }
    temp = first;
    first = first->rlink;
    printf("Item deleted with following contents: \n");
    printf("USN: %s\n", temp->ssn);
    printf("Name: %s\n", temp->name);
    printf("Dept: %s\n", temp->dept);
    printf("Desg: %s\n", temp->desg);
    printf("Salary: %d\n",temp->salary);
    printf("Phno: %s\n", temp->phno);
    first->llink =NULL;
    free(temp);
    return first;
}

NODE insert_rear(char ssn[20],char name[30],char dept[20],char desg[20],int salary,char phno[20],NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->ssn, ssn);
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->salary = salary;
    strcpy(temp->phno, phno);
    temp -> llink = NULL;
    temp -> rlink = NULL;

    if(first == NULL)
    {
        return temp;
    }
    NODE cur = first;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink=temp;
    temp->llink = cur;
    return first;

}

NODE delete_rear(NODE first)
{
    if(first == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if(first -> rlink == NULL)
    {
        printf("Item deleted with following contents: \n");
        printf("USN: %s\n", first->ssn);
        printf("Name: %s\n", first->name);
        printf("Dept: %s\n", first->dept);
        printf("Desg: %s\n", first->desg);
        printf("Salary: %d\n",first->salary);
        printf("Phno: %s\n", first->phno);
        free(first);
        return NULL;
    }
    NODE cur = first;
    NODE prev = NULL;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    prev = cur->llink;
    printf("Item deleted with following contents: \n");
    printf("USN: %s\n", cur->ssn);
    printf("Name: %s\n", cur->name);
    printf("Dept: %s\n", cur->dept);
    printf("Desg: %s\n", cur->desg);
    printf("Salary: %d\n",cur->salary);
    printf("Phno: %s\n", cur->phno);
    prev -> rlink = NULL;
    free(cur);
    return first;
}

void display(NODE first)
{
    if(first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("The contents of the list are: \n");
    NODE cur = first;
    while(cur != NULL)
    {
        printf("USN: %s\n", cur->ssn);
        printf("Name: %s\n", cur->name);
        printf("Dept: %s\n", cur->dept);
        printf("Desg: %s\n", cur->desg);
        printf("Salary: %d\n",cur->salary);
        printf("Phno: %s\n", cur->phno);
        printf("\n");
        cur = cur->rlink;
    }

}

void main()
{
    char ssn[20];
    char name[30];
    char dept[20];
    char desg[20];
    int salary;
    char phno[20];

    int choice;
    NODE first = NULL;
    for(;;)
    {
        printf("1.IF    2.DF    3.IR    4.DR    5.Display   6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter SSN: ");
                    scanf("%s", ssn);
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter dept: ");
                    scanf("%s", dept);
                    printf("Enter desg: ");
                    scanf("%s", desg);
                    printf("Enter Salary: ");
                    scanf("%d", &salary);
                    printf("Enter phno: ");
                    scanf("%s", phno);
                    first = insert_front(ssn, name, dept,dept, salary, phno, first);
                    break;
            case 2: first = delete_front(first);
                    break;
            case 3: printf("Enter SSN: ");
                    scanf("%s", ssn);
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter dept: ");
                    scanf("%s", dept);
                    printf("Enter desg: ");
                    scanf("%s", desg);
                    printf("Enter Salary: ");
                    scanf("%d", &salary);
                    printf("Enter phno: ");
                    scanf("%s", phno);
                    first = insert_rear(ssn, name, dept,dept, salary, phno, first);
                    break;
            case 4:first = delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            default: return;
        }
    }
}