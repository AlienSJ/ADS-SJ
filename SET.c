#include<stdio.h>
#include<conio.h>

int i,j,k,p,ch,n1,n2,set1[10],set2[10], set3[20],flag;
int Input();
int Union();
int Intersection();
int Difference();
void Display();
int d;

int main()
{
    int choice;
    do
    {
        printf("\n\nSET OPERATIONS ");
        printf("\n1. INPUT\n2. UNION\n3. INTERSECTION\n4. DIFFERENCE\n5. DISPLAY\n0. EXIT\n\nENTER CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            Input();
            break;
            case 2:
            Union();
            break;
            case 3:
            Intersection();
            break;
            case 4:
            Difference();
            break;
            case 5:
            Display();
            break;
            case 0:
            exit(0);
            break;
            default:
            printf("Invalid choice!!!");
            break;
            printf("\n Do you want to continue(0/1)? ");
            scanf("%d",&d);
        }
    }
while(d==0);
    }


int Input()
{
    printf("\nEnter the size of set1 : ");
    scanf("%d",&n1);
    printf("\nEnter the element of set1 : \n");
    for(i=0;i<n1;i++)
        scanf("%d",&set1[i]);
    printf("\nEnter the size of set2 : ");
    scanf("%d",&n2);
    printf("\nEnter the elements of set2 : \n");
    for(i=0;i<n2;i++)
        scanf("%d",&set2[i]);

}

int Union()
{
    k=0;
    for(i=0;i<n1;i++)
    {
        set3[k]=set1[i];
        k++;
    }
    for(i=0;i<n2;i++)
    {
        flag=1;
        for(j=0;j<n1;j++)
        {
            if(set2[i]==set1[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            set3[k]=set2[i];
            k++;
        }
    }
    p=k;
    for(k=0;k <p;k++)
    {
        printf(" %d",set3[k]);
    }

}

int Intersection()
{
    k=0;
    for(i=0;i<n2;i++)
    {
        flag=1;
    for(j=0;j<n1;j++)
    {
        if(set2[i]==set1[j])
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    {
        set3[k]=set2[i];
        k++;
    }
    }
    p=k;
    for(k=0;k <p;k++)
    {
        printf(" %d",set3[k]);
    }

}

int Difference()
{
    k=0;
    for(i=0;i<n1;i++)
    {
        flag=1;
        for(j=0;j<n2;j++)
        {
            if(set1[i]==set2[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            set3[k]=set1[i];
            k++;
        }
    }
    p=k;
    for(k=0;k <p;k++)
    {
        printf(" %d",set3[k]);
    }

}

void Display()
{
    int temp=0;
    int arr[]={0,0,0,0,0,0,0,0,0};
    int arr1[]={0,0,0,0,0,0,0,0,0,0};
    printf("\nElements of set1 are: \n");
    for(i=0;i<n1;i++)
    {
        printf(" %d",set1[i]);
    }

    printf("\nSet Representation: \n");
    for(i=0;i<9;i++)
    {
        temp=set1[i];
        arr[temp-1]=1;
        printf(" %d",arr[i]);
    }

    printf("\n\nElements of set2 are: \n");
    for(i=0;i<n2;i++)
    {
        printf(" %d",set2[i]);

    }

    printf("\nSet Representation: \n");
    for(i=0;i<9;i++)
    {
        temp=set2[i];
        arr1[temp-1]=1;
        printf(" %d",arr1[i]);
    }
}



