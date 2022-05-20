#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;

int insert_beg(){
	struct node *temp = start;
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&t->data);
	if(start==NULL){
		start = t;
		t->next = start;
		return 0;
	}
	
	while(temp->next!=start){
		temp = temp->next;
	}
	t->next = start;
	temp->next = t;
	start = t;
	return 0;
}

int insert_middle(){
	int x;
	struct node *temp = start;
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node));
	printf("Enter element after: ");
	scanf("%d",&x);
	while((temp->data!=x)&&(temp->next!=start)){
		temp = temp->next;
	}
	if(temp->data!=x){
		printf("Data not found");
		return 0;
	}
	printf("Enter element: ");
	scanf("%d",&t->data);
	t->next = temp->next;
	temp->next = t;
	
	return 0;
}

int insert_end(){
	struct node *temp = start;
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node));
	printf("Enter element: ");
	scanf("%d",&t->data);
	if(start==NULL){
		start = t;
		t->next = start;
		return 0;
	}
	while(temp->next!=start){
		temp = temp->next;
	}
	t->next = start;
	temp->next = t;
	return 0;
}

int del_beg(){
	struct node *temp=start;
	if(start==NULL){
		printf("Empty list");
		return 0;
	}
	if(start->next==start){
		start = NULL;
		free(temp);
		return 0;
	}
	while(temp->next!=start){
		temp = temp->next;
	}
	temp->next = start->next;
	temp = start;
	start = start->next;
	free(temp);
	return 0;
}

int del_middle(){
	struct node *prev = start;
	struct node *cur = start;
	if(start == NULL){
		printf("Empty list");
		return 0;
	}
	int x;
	
	printf("Enter element: ");
	scanf("%d",&x);
	if(start->data==x){
		del_beg();
		return 0;
	}
	while((cur->data!=x)&&(cur->next!=start)){
		prev = cur;
		cur = cur->next;
	}
	if(cur->data!=x){
		printf("Element not found");
		return 0;
	}
	prev->next = cur->next;
	free(cur);
	return 0;
}

int del_end(){
	struct node *temp = start;
	struct node *prev;
	
	if(start==NULL){
		printf("Empty list");
		return 0;
	}
	if(start->next==start){
		start = NULL;
		free(start);
		return 0;
	}
	while(temp->next!=start){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
	return 0;
}
int display(){
	struct node * temp = start;
	if(start == NULL){
		printf("Empty list");
		return 0;
	}
	while(temp->next!=start){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);
	return 0;
}

int main(){
	int ch;
	do{
		printf("\n1.Insert at beginning\n2.Display\n3.insert at middle\n4.Insert at end\n5.Delete beginning\n6.Delete middle\n7.Delete end\n8.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert_beg();
				break;
			case 2:
				display();
				break;
			case 8:
				exit(0);
				break;
			case 3:
				insert_middle();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				del_beg();
				break;
			case 6:
				del_middle();
				break;
			case 7:
				del_end();
				break;
		}
	}while(ch!=8);
	return 0;
}
