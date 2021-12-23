#include <stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_front();
void delete_end();

struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;
int main()
{
    int choice;
    while (1)
    {

        printf("\n----MENU----");
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.Insert at the beginning");
        printf("\n 4.Insert at the end");
        printf("\n 5.Insert at specified position");
        printf("\n 6.Delete at the end");
        printf("\n 7.Delete at the front");
        printf("\n 8.Delete at the specified position");      
        printf("\n 9.Exit");
        printf("\n Enter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_front();
            break;
        case 8:
            delete_pos();
            break;
        case 9:
            exit(0);
            break;

        default:
            printf("\nWrong Choice:");
            break;
        }
    }
    return 0;
}
void create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space");
        exit(0);
    }
    printf("\nEnter the data value for the node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty:");
        return;
    }
    else
    {
        ptr = start;
        printf("\nThe List elements are:");
        while (ptr != NULL)
        {
            printf("%d", ptr->info);
            printf("\n");
            ptr = ptr->next;
        }
    }
}
void insert_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}
void insert_end()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void insert_pos()
{
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted:\t");
    scanf("%d", &pos);
    printf("\nEnter the data value of the node:\t");
    scanf("%d", &temp->info);

    temp->next = NULL;
    if (pos == 0)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        for (i = 0, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("\nPosition not found:\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_front()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nList is empty");
    } else {
        ptr = start;
        start = ptr->next;
        free(ptr);
        printf("\nNode deleted from the front...");
    }
}

void delete_end()
{
    struct node *ptr, *ptr1;
    if(start == NULL)
    {
        printf("\nList is empty");
    } else if (start->next!=NULL){
        start = NULL;
        free(start);
        printf("\nOnly node of list deleted");
    } else {
        ptr = start;
        while (ptr->next!=NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\nNode deleted from the end");
    }
}

void delete_pos()
{
    struct node *ptr, *ptr1,*next;
    int pos, i;
    printf("\nEnter location of the node after where you want to delete");
    scanf("%d",&pos);
    ptr=next;
    for (i=0;i<pos;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
       
        if(ptr==NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d",pos+1);
}