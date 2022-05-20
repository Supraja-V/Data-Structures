#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *start;  
 
int insertion_beginning()  
{  
   struct node *ptr,*temp;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value: ");  
    scanf("%d",&item);  
    ptr->data=item;  
   if(start==NULL)  
   {  
      start = ptr;  
      ptr -> next = start;   
      ptr -> prev = start;   
   }  
   else   
   {  
       temp = start;   
    while(temp -> next != start)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  
    ptr -> prev = temp;  
    start -> prev = ptr;  
    ptr -> next = start;  
    start = ptr;  
   }  
   printf("\nNode inserted\n");  
}  
    return 0; 
}  
int insertion_last()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value: ");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(start == NULL)  
       {  
           start = ptr;  
           ptr -> next = start;   
           ptr -> prev = start;   
       }  
       else  
       {  
          temp = start;  
          while(temp->next !=start)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          start -> prev = ptr;  
      ptr -> next = start;  
        }  
   }  
     printf("\nnode inserted\n");  
     return 0;
}  
  
int deletion_beginning()  
{  
    struct node *temp;  
    if(start == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(start->next == start)  
    {  
        start = NULL;   
        free(start);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        temp = start;   
        while(temp -> next != start)  
        {  
            temp = temp -> next;  
        }  
        temp -> next = start -> next;  
        start -> next -> prev = temp;  
        free(start);  
        start = temp -> next;  
    }  
  return 0;
}  
int deletion_last()  
{  
    struct node *ptr;  
    if(start == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(start->next == start)  
    {  
        start = NULL;   
        free(start);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = start;   
        if(ptr->next != start)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = start;  
        start -> prev = ptr -> prev;    
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
    return 0;
}  
  
int display()  
{  
    struct node *ptr;  
    ptr=start;  
    if(start == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != start)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
              return 0;
}  
  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag=1;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        if(start ->data == item)  
        {  
        printf("item found at location %d",i+1);  
        flag=0;  
        }  
        else   
        {  
        while (ptr->next != start)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
} 

int main ()  
{  
int choice =0;  
    while(choice != 9)  
    { 
        printf("\nEnter choice: \n");  
        printf("\n1.Insert in Beginning, 2.Insert at last, 3.Delete from Beginning, 4.Delete from last, 5.Search, 6.Show, 7.Exit\n");  
        printf("\nEnter your choice: ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
                    insertion_last();  
            break;  
            case 3:  
            deletion_beginning();  
            break;  
            case 4:  
            deletion_last();  
            break;  
            case 5:  
            search();  
            break;  
            case 6:  
            display();  
            break;  
            case 7:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
return 0;
}
  

