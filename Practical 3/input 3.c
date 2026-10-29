#include<stdio.h>

int bubble_sort(int m,int arr[]);
int insertion_sort(int m,int arr[]);
int selection_sort(int m,int arr[]);
void quick_sort(int arr[],int low,int high);
void merge_sort(int m,int arr[],int left,int right);

void display_menu()
{
    printf("\n\n<--------Menu-------->");
    printf("\n1. bubble_sort");
    printf("\n2. insertion_sort");
    printf("\n3. selection_sort");
    printf("\n4. quick_sort");
    printf("\n5. merge_sort");
    printf("\n6. exit");
}
/* Bubble Sort */
int bubble_sort(int m,int arr[])
{
    int i,j,temp;
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return 0;
}
/* Insertion Sort */
int insertion_sort(int m,int arr[])
{
    int i,j,temp;
    for(i=1;i<m;i++)
    {
        temp=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    return 0;
}
/* Selection Sort */
int selection_sort(int m,int arr[])
{
    int i,j,min,temp;
    for(i=0;i<m-1;i++)
    {
        min=i;
        for(j=i+1;j<m;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    return 0;
}
/* Quick Sort */
void swap(int *a,int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j;

    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quick_sort(int arr[],int low,int high)
{
    int pi;
    if(low<high)
    {
        pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}
/* Merge Sort */
void merge(int arr[],int left,int mid,int right)
{
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[100],R[100];

    for(i=0;i<n1;i++)
    {
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }

    i=0;
    j=0;
    k=left;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int m,int arr[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        merge_sort(m,arr,left,mid);
        merge_sort(m,arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
/* Main Function */
void main()
{
    int i,m,arr[100];
    int choice;

    printf("\nEnter size of array:");
    scanf("%d",&m);

    printf("Enter array elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nThe array is :");
    for(i=0;i<m;i++)
    {
        printf("\t%d",arr[i]);
    }

    do
    {
        display_menu();
        printf("\n\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                bubble_sort(m,arr);
                printf("\nThe sorted array is:");
                for(i=0;i<m;i++)
                {
                    printf("\t%d",arr[i]);
                }
                break;

            case 2:
                insertion_sort(m,arr);
                printf("\nThe sorted array is:");
                for(i=0;i<m;i++)
                {
                    printf("\t%d",arr[i]);
                }
                break;

            case 3:
                selection_sort(m,arr);
                printf("\nThe sorted array is:");
                for(i=0;i<m;i++)
                {
                    printf("\t%d",arr[i]);
                }
                break;

            case 4:
                quick_sort(arr,0,m-1);
                printf("\nThe sorted array is:");
                for(i=0;i<m;i++)
                {
                    printf("\t%d",arr[i]);
                }
                break;

            case 5:
                merge_sort(m,arr,0,m-1);
                printf("\nThe sorted array is:");
                for(i=0;i<m;i++)
                {
                    printf("\t%d",arr[i]);
                }
                break;

            case 6:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice.");
        }

    }while(choice!=6);
}
