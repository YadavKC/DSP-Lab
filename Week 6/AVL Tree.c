#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int ht;
    struct node *right;
    struct node *left;
}node;

    node *insert(node *,int);
    node *Delete(node *,int);
    void preorder(node *);
    void inorder(node *);
    int height( node *);
    node *rotateleft(node *);
    node *RR(node *);
    node *LL(node *);
    node *LR(node *);
    node *RL(node *);
    int BF(node *);

int main()
{
    node *root=NULL;
    int x,n,i,choice;
    do
    {
        printf("\n1.Create Tree :");
        printf("\n2.Insert :");
        printf("\n3.Delete :");
        printf("\n4.Display Pre-order,In-order,Post-order,level-order :");
        printf("\n5.Exit :");
        printf("\n\nEnter Your Choice :");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\nEnter no. of elements :");
            scanf("%d",&n);
            root=NULL;
            printf("\nEnter Value in Tree:");
            for(i=0;i<n;i++)
            {
                scanf("%d",&x);
                root=insert(root,x);
            }
        }
        else if(choice==2)
        {
              printf("\nEnter a data:");
              scanf("%d",&x);
              root=insert(root,x);

          }
          else if(choice==3)
          {
              printf("\nEnter a data:");
              scanf("%d",&x);
              root=Delete(root,x);
          }
          else if(choice==4)
          {
              printf("\nPreorder Traversal:\n");
              preorder(root);
              printf("\n\nInorder Traversal:\n");
              inorder(root);
              printf("\n\nPostorder Traversal:\n");
              postorder(root);
              printf("\n\nLeve-lorder Traversal:\n");
              printLevelOrder(root);
              printf("\n\n\n");

          }



       }while(choice!=5);
return 0;
}

node * insert(node *Tree,int x)
{
    if(Tree==NULL)
    {
        Tree=(node*)malloc(sizeof(node));
        Tree->data=x;
        Tree->left=NULL;
        Tree->right=NULL;
    }
    else if(x > Tree->data) // insert in right subtree
    {
        Tree->right=insert(Tree->right,x);
        if(BF(Tree)==-2)
        if(x>Tree->right->data)
           Tree=RR(Tree);
        else
           Tree=RL(Tree);
     }
     else if(x<Tree->data)
     {
         Tree->left=insert(Tree->left,x);
         if(BF(Tree)==2)
            if(x < Tree->left->data)
                Tree=LL(Tree);
            else
                Tree=LR(Tree);
      }
      Tree->ht=height(Tree);
      return(Tree);
}

node * Delete(node *Tree,int x)
{
    node *p;
    if(Tree==NULL)
    {
       return NULL;
     }
    else if(x > Tree->data) // insert in right subtree
    {
        Tree->right=Delete(Tree->right,x);
        if(BF(Tree)==2)
           if(BF(Tree->left)>=0)
              Tree=LL(Tree);
        else
            Tree=LR(Tree);
     }
    else if(x<Tree->data)
    {
        Tree->left=Delete(Tree->left,x);
        if(BF(Tree)==-2) //Rebalance during windup
            if(BF(Tree->right)<=0)
                Tree=RR(Tree);
            else
                Tree=RL(Tree);
     }
     else
     {
        if(Tree->right!=NULL)
        {
            p=Tree->right;
            while(p->left!= NULL)
                 p=p->left;
            Tree->data=p->data;
            Tree->right=Delete(Tree->right,p->data);
            if(BF(Tree)==2)//Rebalance during windup
               if(BF(Tree->left)>=0)
                   Tree=LL(Tree);
               else
                   Tree=LR(Tree);\
          }
          else
               return(Tree->left);
       }
       Tree->ht=height(Tree);
       return(Tree);
}

int height(node *Tree)
{
    int lh,rh;
    if(Tree==NULL)
       return(0);
    if(Tree->left==NULL)
       lh=0;
    else
       lh=1+Tree->left->ht;
    if(Tree->right==NULL)
       rh=0;
    else
       rh=1+Tree->right->ht;
       if(lh>rh)
          return(lh);
       return(rh);
}

node * rotateright(node *A)
{
    node *B;
    B=A->left;
    A->left=B->right;
    B->right=A;
    A->ht=height(A);
    B->ht=height(B);
    return(B);
}

node * rotateleft(node *A)
{
    node *B;
    B=A->right;
    A->right=B->left;
    B->left=A;
    A->ht=height(A);
    B->ht=height(B);
    return(B);
}

node * RR(node *Tree)
{
     Tree=rotateleft(Tree);
     return(Tree);
}

node * LL(node *Tree)
{
     Tree=rotateright(Tree);
     return(Tree);
}

node * LR(node *Tree)
{
    Tree->left=rotateleft(Tree->left);
    Tree=rotateright(Tree);
    return(Tree);
}

node * RL(node *Tree)
{
     Tree->right=rotateright(Tree->right);
     Tree=rotateleft(Tree);
     return(Tree);
}

int BF(node *Tree)
{
    int lh,rh;
    if(Tree==NULL)
       return(0);

    if(Tree->left==NULL)
        lh=0;
    else
        lh=1+Tree->left->ht;
    if(Tree->right==NULL)
        rh=0;
    else
        rh=1+Tree->right->ht;

     return(lh-rh);
}

void preorder(node *Tree)
{
   if(Tree!=NULL)
   {
      printf("(%d)",Tree->data);
      preorder(Tree->left);
      preorder(Tree->right);
    }
}

void inorder(node *Tree)
{
    if(Tree!=NULL)
{
inorder(Tree->left);
printf("(%d)",Tree->data);
inorder(Tree->right);
}
}

void postorder(node *Tree)
{
if(Tree!=NULL)
{
    postorder(Tree->left);
    postorder(Tree->right);
    printf("(%d)",Tree->data);
}
}

void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("(%d) ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
    printf("\n\n");
}
