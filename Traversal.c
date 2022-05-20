#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};

int inorderTraversal(struct node* root) {
  if (root==NULL) return;
  inorderTraversal(root->left);
  printf("%d \t", root->data);
  inorderTraversal(root->right);
}

int preorderTraversal(struct node* root) {
  if (root==NULL) return;
  printf("%d \t", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
int postorderTraversal(struct node* root) {
  if (root==NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d \t", root->data);
}

struct node *Insert( int x, struct node *t)
{
if(t==NULL)
{
t= (struct node *)malloc(sizeof(struct node));
if(t==NULL)
printf("Out of space");
else {
t->data = x;
t->left=t->right=NULL;
}
}
else if(x < t -> data)
t -> left=Insert(x, t-> left);
else if (x > t -> data)
t -> right=Insert(x, t-> right);
return t;
}


struct node *FindMin( struct node *T )
{if(T == NULL)
return NULL;
else
if( T->left == NULL )
return T;
else
return FindMin(T->left);
}

struct node *Delete ( int X , struct node *t )
{ struct node *temp;
if(t == NULL)
printf(" data not found");
else if(X < t -> data)
t -> left=Delete(X, t-> left);
else if (X > t -> data)
t -> right = Delete(X, t-> right);
else if (t->left && t->right)
{
temp = FindMin (t->right);
t->data = temp->data;
t->right = Delete (t->data, t->right);
}
else
{
temp = t;
if( t-> left == NULL)
t = t->right;
else if (t -> right == NULL)
t = t-> left;
free (temp);
}
return t;
}

struct node *Find( int X, struct node *t)
{
if(t == NULL)
return NULL;
if(X < t->data)
return Find(X, t->left);
else
if(X > t->data)
return Find(X, t->right);
else
return t;
}


int main(){
	int ch,x;
	struct node *t = NULL;
do
{
printf("\n1.Insert, 2.Pre Order, 3.In order, 4.Post Order, 5. Delete, 6.Find, 7.Exit\n");
printf("\nEnter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf("Enter: ");
	scanf("%d",&x);
t = Insert(x,t);
break;
case 2:
	printf("\n");
preorderTraversal(t);
break;
case 3:
	printf("\n");
inorderTraversal(t);
break;
case 4:
	printf("\n");
postorderTraversal(t);
break;
case 5:
	printf("Enter: ");
	scanf("%d",&x);
	t = Delete(x,t);
	break;
case 6:
	printf("Enter: ");
	scanf("%d",&x);
	if(Find(x,t)){
		printf("Element found");
	}
	else{
		printf("ENF");
	}
	break;
}
}while(ch!=7);
	return 0;
}

