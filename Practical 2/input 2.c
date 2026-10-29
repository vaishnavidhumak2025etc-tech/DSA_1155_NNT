#include <stdio.h>
void insert(int a[], int n)
{
    int i;

    printf("Enter the array elements: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
    int i;

    printf("Array elements are: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void search(int a[], int n)
{
    int i, key, found = 0;

    printf("Enter the number to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("Number is found\n");
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Number not found\n");
    }
}

void binarySearch(int a[], int low, int high, int key)
{
    int mid;

    if(low > high)
    {
        printf("Number not found\n");
        return;
    }

    mid = (low + high) / 2;

    if(a[mid] == key)
    {
        printf("Number is found\n");
    }
    else if(key < a[mid])
    {
        binarySearch(a, low, mid - 1, key);
    }
    else
    {
        binarySearch(a, mid + 1, high, key);
    }
}

int main()
{
    int a[10], n, choice;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    insert(a, n);

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Display\n");
        printf("2. Search\n");
        printf("3. BinarySearch\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(a, n);
                break;

            case 2:
                search(a, n);
                break;

            case 3:
            {
                int key;

                printf("Enter number for search: ");
                scanf("%d", &key);

                binarySearch(a, 0, n - 1, key);
                break;
            }

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
