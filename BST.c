#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE insert(int item, NODE root)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if(root==NULL)
    {
        return temp;
    }
    NODE cur = root;
    NODE prev = NULL;
    while(cur != NULL)
    {
        prev = cur;
        if(item>cur->info)
        {
            cur=cur->rlink;
        }
        else
        {
            cur=cur->llink;
        }
    }
    if(item>prev->info)
        prev->rlink = temp;
    else
        prev->llink = temp;
    return root; 
}

NODE search(int key, NODE root)
{
    if(root==NULL || root->info==key)
    {
        return root;
    }
    if(key < root->info)
        return search(key, root->llink);
    return search(key, root->rlink);
}

void preorder(NODE root) //NLR
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(NODE root) //LNR
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);

}

void postorder(NODE root) //LRN
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

void main()
{
    int choice, item, key;
    NODE root = NULL;
    NODE temp = NULL;
    for(;;)
    {
        printf("1.Insert    2.Search    3.Display   4.Exit: \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:printf("Enter the item: ");
                    scanf("%d", &item);
                    root = insert(item, root);
                    break;
            case 2: printf("Enter the item to search for: ");
                    scanf("%d", &key);
                    temp = search(key, root);
                    if(temp==NULL)
                    {
                        printf("Unsuccesfull Search.\n");
                        printf("Key element not found.\n");
                    }
                    else
                    {
                        printf("Successfull Search.\n");
                        printf("Element found: %d\n", temp->info);
                    }
                    break;
            case 3: printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                    break;
            default: return;
        }
    }
}