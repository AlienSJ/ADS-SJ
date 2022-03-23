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

