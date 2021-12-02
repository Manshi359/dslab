#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
 
 
  struct node
  {
      int info;
      struct node *next;
  };
 
  struct node *start=NULL;
 
  int main()
  {
      int choice;
      while(1)
      {
          printf("\n menu");
          printf("\n1.create \n");
          printf("\n2.display \n");
          printf("\n3.insert at the the beginning \n");
          printf("\n4.exit \n");
          printf("\n enter your choice");
          scanf("%d",&choice);
          switch(choice)
          {
              case 1:
             // create();
              break;
              case 2:
              display();
              break;
              case 3:
              insert_begin();
              break;
              case 4:
              exit(0);
              break;
              default:printf("\n wrong choice");
              break;
          }
          }
          return 0;
  }
 
          void display()
          {
              struct node*ptr;
              if(start==NULL)
              {
                  printf("\n list is empty");
                  return;
              }
              else
              {
                  ptr=start;
                  printf("\n the list of elements are:");
                  while(ptr!=NULL)
                  {
                      printf("%d",ptr->info);
                      ptr=ptr->next;
                  }
              }
          }
                   
                     void insert_begin()
                     {
                         struct node*temp;
                         temp=(struct node*)malloc(sizeof(struct node));
                          printf("\n enter the value into the node");
                         scanf("%d",&temp->info);
                         temp->next=NULL;
                         if(temp==NULL)
                         {
                             start=temp;
                         }
                     else
                     {
                         temp->next=start;
                         start=temp;
                     }
                     }