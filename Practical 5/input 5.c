#include <stdio.h>
#define MAX 5

void push(int stack[], int *top, int size)
{
    int i;
    if(size > MAX)
    {
        printf("\nStack size cannot be greater than %d", MAX);
        return;
    }
    printf("Enter %d elements for stack:\n", size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &stack[++(*top)]);
    }
} 


void pop(int stack[], int *top)
{
    if(*top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nPopped element = %d", stack[*top]);
        (*top)--;
    }
}


void peek(int stack[], int top)
{
    if(top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nTOP element = %d", stack[top]);
    }
}


void displayStack(int stack[], int top)
{
    int i;
    if(top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack elements are:\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}


void enqueue(int queue[], int *rear, int size)
{
    int i;
    if(size > MAX)
    {
        printf("\nQueue size cannot be greater than %d", MAX);
        return;
    }

    printf("Enter %d elements for queue:\n", size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &queue[++(*rear)]);
    }
}


void addQueue(int queue[], int *rear)
{
    int value;
    if(*rear == MAX - 1)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        printf("\nEnter element to enqueue: ");
        scanf("%d", &value);

        (*rear)++;

        queue[*rear] = value;

        printf("Element enqueued successfully.");
    }
}


void dequeue(int queue[], int *front, int rear)
{
    if(*front > rear)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        printf("\nDequeued element = %d", queue[*front]);
        (*front)++;
    }
}


void displayQueue(int queue[], int front, int rear)
{
    int i;
    if(front > rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements are:\n");
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{

    int stack[MAX], queue[MAX];
    int stackSize, queueSize;
    int top = -1;
    int front = 0, rear = -1;
    int choice;

    printf("Enter size of stack: ");
    scanf("%d", &stackSize);
    push(stack, &top, stackSize);

    printf("\nEnter size of queue: ");
    scanf("%d", &queueSize);
    enqueue(queue, &rear, queueSize);

    do
    {
        printf("\n\n----- STACK AND QUEUE -----");
        printf("\n1. Display Stack");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Enqueue");
        printf("\n5. Dequeue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayStack(stack, top);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                peek(stack, top);
                break;

            case 4:
                addQueue(queue, &rear);
                break;
            case 5:
                dequeue(queue, &front, rear);
                break;

            case 6:
                displayQueue(queue, front, rear);
                break;

            case 7:
                printf("\nProgram ended.");
                break;

            default:
                printf("\nInvalid choice");
        }
    } while(choice != 7);
    return 0;
}
