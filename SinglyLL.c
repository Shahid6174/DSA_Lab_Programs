#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char usn[20];
    char name[30];
    char branch[20];
    int sem;
    char phno[20];

    struct node* link;
};

typedef struct node* NODE;

NODE insert_front(char usn[20], char name[30], char branch[20], int sem, char phno[20], NODE first)
{ 
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem = sem;
    strcpy(temp->phno, phno);
    temp -> link = NULL;
    if(first == NULL)
        return temp;
    temp->link = first;
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
    temp = first;
    first = first->link;
    printf("Item deleted with following contents: \n");
    printf("USN: %s\n", temp->usn);
    printf("Name: %s\n", temp->name);
    printf("Branch: %s\n", temp->branch);
    printf("SEM: %d\n",temp->sem);
    printf("Phno: %s\n", temp->phno);
    free(temp);
    return first;
}

NODE insert_rear(char usn[20], char name[30], char branch[20], int sem, char phno[20], NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem = sem;
    strcpy(temp->phno, phno);
    temp -> link = NULL;
    if(first == NULL)
        return temp;
    NODE cur = first;
    while(cur->link != NULL)
    {
        cur= cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if(first == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    } 
    if(first -> link == NULL)
    {
        NODE temp = first;
        printf("Item deleted with following contents: \n");
        printf("USN: %s\n", first->usn);
        printf("Name: %s\n", first->name);
        printf("Branch: %s\n", first->branch);
        printf("SEM: %d\n",first->sem);
        printf("Phno: %s\n", first->phno);
        free(first);
        return NULL;
    }
    cur = first;
    prev = NULL;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Item deleted with following contents: \n");
    printf("USN: %s\n", cur->usn);
    printf("Name: %s\n", cur->name);
    printf("Branch: %s\n", cur->branch);
    printf("SEM: %d\n",cur->sem);
    printf("Phno: %s\n", cur->phno);
    prev->link = NULL;
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
    NODE cur = first;
    printf("The contents of the list are: \n");
    while(cur != NULL)
    {
        printf("USN: %s\n", cur->usn);
        printf("Name: %s\n", cur->name);
        printf("Branch: %s\n", cur->branch);
        printf("SEM: %d\n",cur->sem);
        printf("Phno: %s\n", cur->phno);
        printf("\n");
        cur  = cur->link;
    }
}

void main()
{
    char usn[20];
    char name[30];
    char branch[20];
    int sem;
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
            case 1: printf("Enter USN: ");
                    scanf("%s", usn);
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter branch: ");
                    scanf("%s", branch);
                    printf("Enter sem: ");
                    scanf("%d", &sem);
                    printf("Enter phno: ");
                    scanf("%s", phno);
                    first = insert_front(usn, name, branch, sem, phno, first);
                    break;
            case 2: first = delete_front(first);
                    break;
            case 3: printf("Enter USN: ");
                    scanf("%s", usn);
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter branch: ");
                    scanf("%s", branch);
                    printf("Enter sem: ");
                    scanf("%d", &sem);
                    printf("Enter phno: ");
                    scanf("%s", phno);
                    first = insert_rear(usn, name, branch, sem, phno, first);
                    break;
            case 4:first = delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            default: return;
        }
    }

}