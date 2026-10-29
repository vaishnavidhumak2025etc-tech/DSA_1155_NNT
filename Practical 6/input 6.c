#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void insert(int item)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->next = top;
    top = newnode;
}
int delete()
{
    int item;
    struct Node *temp;
    if(top == NULL)
    {
        printf("\nStack is Empty");
        return -1;
    }
    else
    {
        temp = top;
        item = top->data;
        top = top->next;
        free(temp);
        return item;
    }
}
void display()
{
    struct Node *temp;
    if(top == NULL)
    {
        printf("\nStack is Empty");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice, item;
    while(1)
    {
        printf("\n\nImplementation of Stack using Linked List");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                if(top == NULL)
                {
                    printf("\nStack is Empty");
                }
                else
                {
                    item = delete();
                    printf("\nDeleted item = %d", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid Choice !!");
        }
    }
    return 0;
}
