#include <stdio.h>
#include <string.h>
#define MAXADDR 100

struct employee
{
    char name[20];
    int empid;
    int age;
}ht[MAXADDR];

int hash(int key)
{
    int index;
    index = key%MAXADDR;
    return index;
}

void main()
{
    int choice, i, count = 0, age, key, index;
    char name[20];
    for(int i = 0; i<MAXADDR; i++)
    {
        ht[i].empid = -1;
    }
    for(;;)
    {
        printf("1.INSERT    2.SEARCH    3.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: if(count == MAXADDR)
                    {
                        printf("No Space Available.\n");
                        return;
                    }
                    printf("Enter your name: ");
                    scanf("%s", name);
                    printf("Enter empid: ");
                    scanf("%d", &key);
                    printf("Enter age: ");
                    scanf("%d", &age);
                    index = hash(key);
                    if(ht[index].empid == -1)
                    {
                        strcpy(ht[index].name,name); 
                        ht[index].empid = key;
                        ht[index].age = age;
                        count++;
                        break;
                    }
                    else
                    {
                        for(int i = 1; i<MAXADDR; i++)
                        {
                            index = (hash(key)+i)%MAXADDR;
                            if(ht[index].empid==-1)
                            {
                                strcpy(ht[index].name,name); 
                                ht[index].empid = key;
                                ht[index].age = age;
                                count++;
                                break;
                            }
                        }
                    }
                    break;
            case 2:printf("Enter key to search for: ");
                    scanf("%d", &key);
                    index = hash(key);
                    if(ht[index].empid == -1)
                    {
                        printf("Unsuccessful Search.\n");
                        break;
                    }
                    else if(ht[index].empid == key)
                    {
                        printf("Successfull Search.\n");
                        printf("Name: %s\n", ht[index].name);
                        printf("Empid: %d\n", ht[index].empid);
                        printf("Age: %d\n", ht[index].age);
                        break;
                    }
                    else
                    {
                        for(int i = 1; i<MAXADDR; i++)
                        {
                            index = (hash(key)+i)%MAXADDR;
                            if(ht[index].empid == -1)
                            {
                                printf("Unsuccessful Search.\n");
                                break;
                            }
                            else if(ht[index].empid == key)
                            {
                                printf("Successfull Search.\n");
                                printf("Name: %s\n", ht[index].name);
                                printf("Empid: %d\n", ht[index].empid);
                                printf("Age: %d\n", ht[index].age);
                                break;
                            }
                            else
                                break;
                        }
                        break;
                    }
            default: return;
        }
    }
}