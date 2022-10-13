#include<stdio.h>
#include<stdlib.h>


struct node
{
    int val;
    struct node *next;
}
 *curr;

struct node *head, *tail, *temp, *temp1;
int Choose,n,i,val,check,pos;

int main()
{
    while(1)
    {
    int Choose;
    printf("\nChoose Option:\n");

    printf("1. Create Linked List\n");
    printf("2. Insert the node at the end of the previously inserted node.\n");
    printf("3. Insert New Node at beginning\n");
    printf("4. Insert New Node at any position\n");
    printf("5. Delete Node from last position\n");
    printf("6. Delete Node from beginning\n");
    printf("7. Delete Node from any position\n");
    printf("8. Reverse Linked list\n");
    printf("9. Remove Duplicate data from Linked list\n");

    printf("\n\nPlease choose your option:\n");
    scanf("%d",&Choose);
    if(Choose==1)
    {
        create_linked_list();
    }
    else if(Choose==2)
    {
        insert_end();
    }
    else if(Choose==3)
    {
        insert_at_beginning();
    }
    else if(Choose==4)
    {
        insert_at_any_position();
    }
    else if(Choose==5)
    {
        delete_from_last();
    }
    else if(Choose==6)
    {
        delete_from_beginning();
    }
    else if(Choose==7)
    {
        delete_from_any_position();
    }
    else if(Choose==8)
    {
        reverse_list();
    }
    else if(Choose==9)
    {
        remove_duplicate();
    }

    else{
        exit(0);
    }
    }

    return 0;
}

void create_linked_list()
{
    head = NULL;
    printf("Enter Number of nodes you want to create : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("\nEnter Value : ");
        scanf("%d",&val);
        curr = (struct node*)malloc(n*sizeof(struct node));
        curr->val = val;
        curr->next = NULL;

        if(head==NULL)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            tail->next = curr;
            tail = curr;
        }
    }
    display();
}
void insert_end()
{
    struct node *newnode,*temp=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nInsert Data for Node  : ");
    scanf("%d",&val);
    newnode->val = val;
    newnode->next = NULL;
        if(head==NULL)
            {
            head=newnode;
            tail=newnode;
            }
        else
            {
            tail->next= newnode;
		    tail=newnode;
		    }
        display();
}

void insert_at_beginning()
{
    struct node *newnode,*temp=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nInsert Data for Node  : ");
    scanf("%d",&val);
    newnode->val = val;
    newnode->next = NULL;
        if(head==NULL)
            {
            head=newnode;
            tail=newnode;
            }
        else
            {
 		    newnode->next= head;
		    head=newnode;
		    }
        display();
}

void insert_at_any_position()
{
	struct node *newnode,*temp=NULL, *temp1=NULL;
    printf("\nInsert Data for Node  : ");
    scanf("%d",&val);
    printf("\nEnter Position : ");
    scanf("%d",&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;

    if(head==NULL)
            {
            head=newnode;
            tail=newnode;
            }
        else
            {
            temp = head;
            for(i=1;i<pos;i++)
              {
                temp1 = temp;
                temp=temp->next;
              }
                if(i == pos)
                    {temp1->next = newnode;
                     newnode->next=temp; }
            }

        display();
}

void delete_from_last()
{
	struct node *temp=NULL, *temp1=NULL;
    if(head == NULL)
    {
        printf("\nList is Empty! No Node Found.\n");
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
    }
    display();
}

void delete_from_beginning()
{
	struct node *temp=NULL;
    if(head == NULL)
    {
        printf("\nList is Empty! No Node Found.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    display();
}

void delete_from_any_position()
{
	struct node *temp=NULL;
    if(head == NULL)
    {
        printf("\nList is Empty! No Node Found.\n");
    }
    else
    {
        printf("\nEnter the Position You Want to Delete a Node From: ");
        scanf("%d",&pos);
        temp = head;
        for(i=1;i<pos;i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        if (i==pos)
        {
            temp1->next = temp->next;
            free(temp);
        }
    }
    display();
}

void reverse_list()
{
    struct node *prev_node, *curr_node;
    prev_node = head;
    head = head->next;
    curr_node = head;
    prev_node->next = NULL;
    while(head!=NULL)
    {
       head = head->next;
       curr_node->next = prev_node;
       prev_node = curr_node;
       curr_node = head;
    }
    head = prev_node;
    display();
}

void remove_duplicate()
{
    struct node *temp, *temp1, *dupe;
    temp = head;

    while (temp!=NULL&&temp->next != NULL)
    {
        temp1 = temp;

        while (temp1->next != NULL)
        {
            if (temp->val == temp1->next->val)
            {
                dupe = temp1->next;
                temp1->next = temp1->next->next;
                free(dupe);
            }
            else
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
    display();

}
void display()
{
    curr = head;
    printf( "\n\nYour Link List values : ");
    while (curr!= NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n\n");
}


