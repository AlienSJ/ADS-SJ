# ADS

## Doubly Linked List Operations

#include <stdio.h>
#include <stdlib.h>

int count=0;
struct node {
    int data;
    struct node *prev, *next;
};
struct node* start = NULL;

int main()
{
    int choice,choice2;
    while (1) {
        printf("\n\nDOUBLY LINKED LIST OPERATIONS ");
        printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n0. EXIT\n\nENTER CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\n1. INSERT FRONT\n2. INSERT END\n3. INSERT POSITION\n4. BACK TO MAIN MENU\n\nENTER CHOICE : ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                insertAtFront();
                break;
                case 2:
                insertAtEnd();
                break;
                case 3:
                insertAtPosition();
                break;
                case 4:
                break;
                default:
                printf("\nInvalid Entry!");
            }
            Display();
            break;
            case 2:
            printf("\n1. DELETE FRONT\n2. DELETE END\n3. DELETE POSITION\n4. BACK TO MAIN MENU\n\nENTER CHOICE : ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                deleteFirst();
                break;
                case 2:
                deleteEnd();
                break;
                case 3:
                deletePosition();
                break;
                case 4:
                break;
                default:
                printf("\nInvalid Entry!");
            }
            break;
            case 3:
            Display();
            break;
            case 0:
            exit(0);
            break;
            default:
            printf("\nInvalid Entry!");
        }
    }
    return 0;
}


void Display()
{
    if (start == NULL) {
        printf("\n\tList is empty\n");
        return;
    }
    struct node* temp;
    temp = start;
    printf("\n\nElements are: ");
    while (temp != NULL) {
        printf("\t %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtFront()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    count++;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        count++;
    }
    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
        count++;
    }
}

void insertAtEnd()
{
    struct node *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    count++;
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    p = start;

    if (start == NULL) {
        start = temp;
    }
    else {
        while (p->next != NULL)
            p = p->next;
        temp->prev = p;
        p->next = temp;
    }
}


void insertAtPosition()
{
    int pos, i = 1;
    struct node *temp, *p;
    p = (struct node*)malloc(sizeof(struct node));
    count++;
    p->next = NULL;
    p->prev = NULL;

    printf("\nEnter position: ");
    scanf("%d", &pos);
    printf("\nEnter data to be inserted: ");
    scanf("%d", &p->data);
    temp = start;


    if (start == NULL) {
        start = p;
        p->prev = NULL;
        p->next = NULL;
    }


    else if (pos == 1) {
        p->next = start;
        p->next->prev = p;
        p->prev = NULL;
        start = p;
    }

    else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        p->next = temp->next;
        p->prev = temp;
        temp->next = p;
        temp->next->prev = p;
    }
}

void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\n\tList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
            printf("\nDeleted : %d",temp->data);
        free(temp);
        count--;
    }
}

void deleteEnd()
{
    struct node* temp;
    if (start == NULL){
        printf("\n\tList is empty\n");
        return;
    }
    else{
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        printf("\nDeleted : %d",temp->data);
        free(temp);
    }
    }
}

void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *x;
    temp = start;

    if (start == NULL)
        printf("\n\tList is empty\n");


    else {
        printf("\nEnter position : ");
        scanf("%d", &pos);
        if (pos>count)
        {
            printf("\n\tInvalid position!!!");
            return;
        }
        else if (pos == 1) {
            x = start;
            start = start->next;
            if (start != NULL) {
                start->prev = NULL;
            }
            printf("\nDeleted : %d",x->data);
            free(x);
            count--;
            return;
        }

        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        x = temp->next;
        if (x->next != NULL)
            x->next->prev = temp;
        temp->next = x->next;
        printf("\nDeleted : %d",x->data);
        free(x);
        count--;
    }
}


## ---------------------------------------------------------------


## Set Operations

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



## ------------------------------------------------------------





## DFS

#include<stdio.h>
#include<conio.h>
void dfs(int v);
typedef enum boolean{false,true} bool;
int n,a[10][10];
bool visited[10];

void main()
{
int i,j,v;
printf("Enter the no. of nodes in the graph\n");
scanf("%d",&n);

printf("Enter the adjacency matrix \n");
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]);
    }
}

printf("The adjacency matrix shown as\n");
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        printf("%d ",a[i][j]);
    }
    printf("\n");
}


printf("Enter the starting node for Depth First search\n");
scanf("%d",&v);


for(i=1;i<=n;i++)
    visited[i]=false;

dfs(v);

getch();
}
void dfs(int v)
{
    int i,stack[10],top=-1,pop;
    top++;
    stack[top]=v;
    while(top>=0)
    {
        pop=stack[top];
        top--;
        if(visited[pop]==false)
        {
            printf("%d",pop);
            visited[pop]=true;
        }
        else
            continue;
        for(i=n;i>=1;i--)
        {
            if(a[pop][i]==1 && visited[i]==false)
            {
                top++;// push all the unvisited neighbours in the stack
                stack[top]=i;
            }
        }
    }
}
