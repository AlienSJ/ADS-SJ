#include <stdio.h>
#include <stdlib.h>

int count=0,po;

int InsertFront();
int InsertPosition();
int InsertEnd();
int DeleteFront();
int DeletePosition();
int DeleteEnd();
void Display();
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;

int main()
{
    int choice,choice2;
    do
    {
        printf("\n\nCIRCULAR LINKED LIST OPERATIONS ");
        printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n0. EXIT\n\nENTER CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\n1. INSERT FRONT\n2. INSERT POSITION\n3. INSERT END\n4. BACK TO MAIN MENU\n\nENTER CHOICE : ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                InsertFront();
                break;
                case 2:
                InsertPosition();
                break;
                case 3:
                InsertEnd();
                break;
                case 4:
                break;
                default:
                printf("\nInvalid Entry!");
            }
            // Display();
            break;
            case 2:
            printf("\n1. DELETE FRONT\n2. DELETE POSITION\n3. DELETE END\n4. BACK TO MAIN MENU\n\nENTER CHOICE : ");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                DeleteFront();
                break;
                case 2:
                DeletePosition();
                break;
                case 3:
                DeleteEnd();
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
    while(1);

}

int InsertFront()       //Insert Element at Front Position
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    count++;
    printf("\nEnter data: ");
    scanf("%d",&p->data);
    if(start==NULL){
        start=p;
        p->next=start;
    }
    else{
        temp=start;
        while(temp->next!=start){
            temp=temp->next;
        }
        temp->next=p;
        p->next=start;
        start=p;
    }
    Display();
}

int InsertPosition()       //Insert Element at a Specific Position
{
    printf("\nEnter the position: ");
    scanf("%d",&po);
    if(po==1){
        InsertFront();
    }
    else if(po>count||po<=0){
        printf("Invalid position");
    }
    else if(po==count){
        InsertEnd();
        return 0;
    }
    else{
        struct node *p,*temp;
        p=(struct node *)malloc(sizeof(struct node));
        count++;
        printf("Enter the data: ");
        scanf("%d",&p->data);
        temp=start;
        for(int i=2; i!=po; i++){
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
        Display();
    }
    return 0;
}

int InsertEnd()       //Insert Element at End Position
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    count++;
    temp=start;
    printf("\nEnter the data: ");
    scanf("%d",&p->data);
    if(start==NULL){
        start=p;
        p->next=start;
    }
    else{
        while(temp->next!=start){
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
    Display();
}

int DeleteFront()       //Delete Element at Front Position
{
    struct node *temp,*x;
    if(start==NULL){
        printf("\nList Empty");
    }
    else{
        temp=start;
        x=start;
        while(temp->next!=start){
            temp=temp->next;
        }
        start=x->next;
        temp->next=start;
        printf("\nNode %d deleted",x->data);
        free(x);
        count--;
        Display();
    }
}

int DeletePosition()       //Delete Element at a Specific Position
{
    struct node *temp,*x;
    if(start==NULL){
        printf("\nList Empty");
    }
    else{
        temp=start;
        printf("\nEnter the position : ");
        scanf("%d",&po);
        if(po==1){
            DeleteFront();
            return 0;
        }
        else if(po>count||po<=0){
            printf("Invalid position");
        }
        else{
        for(int i=2; i!=po; i++){
            temp=temp->next;
        }
        x=temp->next;
        temp->next=x->next;
        printf("\nNode %d deleted",x->data);
        free(x);
        count--;
        Display();
        }
    }
}

int DeleteEnd()       //Delete Element at End Position
{
    struct node *temp,*x;
    if(start==NULL){
        printf("\nList Empty");
    }
    else{
        temp=start;
        while(temp->next!=start){
            x=temp;
            temp=temp->next;
        }
        x->next=temp->next;
        printf("\nNode %d deleted",temp->data);
        free(temp);
        count--;
        Display();
    }
}

void Display()       //Display Circular Linked List
{
    struct node *temp;
    if(start==NULL){
        printf("\nEmpty List!!!");
    }
    else{
        temp=start;
        printf("\nNo. of nodes : %d\n",count);
        while(temp->next!=start){
            printf("\t %d",temp->data);
            temp=temp->next;
        }
        printf("\t %d",temp->data);
    }
}



