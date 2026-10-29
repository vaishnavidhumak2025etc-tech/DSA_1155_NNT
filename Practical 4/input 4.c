#include <stdio.h>

typedef struct student
{
    char name[20];
    int roll_no;
    int age;
} stud;


void create(stud *S)
{
    printf("\nEnter the students details:");

    printf("\nEnter name of student: ");
    scanf("%s", S->name);

    printf("Enter roll_no of student: ");
    scanf("%d", &S->roll_no);

    printf("Enter age of student: ");
    scanf("%d", &S->age);
}


void display(stud S)
{
    printf("\nStudent details:");
    printf("\nName of student: %s", S.name);
    printf("\nRoll_no: %d", S.roll_no);
    printf("\nAge: %d\n", S.age);
}


int lsearch(stud *S, int n)
{
    int key;

    printf("\nEnter roll number to search: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++)
    {
        if(S[i].roll_no == key)
        {
            printf("\nFound the key element.");

            printf("\nStudent details:");
            printf("\nName of student: %s", S[i].name);
            printf("\nRoll_no: %d", S[i].roll_no);
            printf("\nAge: %d\n", S[i].age);

            return i;
        }
    }

    printf("\nKey element not found.");
    return -1;
}


void bubble_sort(stud *S, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(S[j].roll_no > S[j + 1].roll_no)
            {
                stud temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }

    printf("\nStudents after sorting:");

    for(int i = 0; i < n; i++)
    {
        printf("\n\nStudent %d", i + 1);
        display(S[i]);
    }
}


void modify(stud *S, int n)
{
    int index;

    index = lsearch(S, n);

    if(index == -1)
    {
        return;
    }

    printf("\nEnter the new details of student:");

    printf("\nEnter name of student: ");
    scanf("%s", S[index].name);

    printf("Enter roll_no of student: ");
    scanf("%d", &S[index].roll_no);

    printf("Enter age of student: ");
    scanf("%d", &S[index].age);

    printf("\nStudent record modified successfully.");
}


int main()
{
    stud S[5];

    int choice, exit = 0, i, n;

    printf("Enter the value of no. of students: ");
    scanf("%d", &n);

    do
    {
        printf("\n\n<---------Menu-------->");

        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Linear Search");
        printf("\n4. Bubble Sort");
        printf("\n5. Modify");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1:
                for(i = 0; i < n; i++)
                {
                    printf("\nStudent %d", i + 1);
                    create(&S[i]);
                }
                break;

            case 2:
                for(i = 0; i < n; i++)
                {
                    printf("\nStudent %d", i + 1);
                    display(S[i]);
                }
                break;

            case 3:
                lsearch(S, n);
                break;

            case 4:
                bubble_sort(S, n);
                break;

            case 5:
                modify(S, n);
                break;

            case 6:
                exit = 1;
                break;

            default:

                printf("\nInvalid choice.");
                break;
        }
    } while(exit == 0);
    return 0;
}
