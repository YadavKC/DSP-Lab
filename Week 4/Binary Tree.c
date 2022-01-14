#include<stdio.h>
#include<stdlib.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define COUNT 20
typedef struct node
{
int data;
struct node *left;
struct node *right;
} node;



node *create()
{
node *p;
int x;
printf("Enter data(-1 for no data):");
scanf("%d",&x);
if(x==-1)
return NULL;
p=(node*)malloc(sizeof(node));
p->data=x;
printf("Enter left child of %d:\n",x);
p->left=create();

printf("Enter right child of %d:\n",x);
p->right=create();
return p;
}

int Hight(node* h)
{
    int a=0,b=7,c=0;

    if(h==NULL)
        return 0;
    if(h->left==NULL&&h->right==NULL)
        return 0;
    else
    {

        a= Hight(h->left);
        b= Hight(h->right);
        c= max(a,b);
        c++;
       // printf("C===%d",c);
        return c;
    }
}









void preorder(node *t)
{
if(t!=NULL)
{
printf("\t%d",t->data);
preorder(t->left);
preorder(t->right);
}
}



void Inorder(node *t)
{
if(t!=NULL)
{
Inorder(t->left);
printf("\t%d",t->data);
Inorder(t->right);
}
}


void postorder(node *t)
{
if(t!=NULL)
{

postorder(t->left);
postorder(t->right);
printf("\t%d",t->data);
}
}



void Display2(node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    Display2(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    Display2(root->left, space);
}

void Display1(node *root)
{
   // Pass initial space count as 0
   Display2(root, 0);
}





int main()
{
int H;
node *root;
root=create();
//Hight of tree------
H=Hight(root);
printf("\nMaximum Hight of Tree is  :%d",H);
//Preorder Traversal of tree--------
printf("\nThe preorder traversal of tree is:\n");
preorder(root);
//Inorder Traversal of tree----------
printf("\nThe Inorder traversal of tree is:\n");
Inorder(root);
//Postorder Traversal of tree---------
printf("\nThe postorder traversal of tree is:\n");
postorder(root);
printf("\n\n\n");
Display1(root);
return 0;
}
