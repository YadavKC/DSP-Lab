#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to find the minimum value in a node
struct node* find_minimum(struct node *root)  //------------------X
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

//function to create a node
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}

// funnction to delete a node
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left_child);
        int rheight = height(node->right_child);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left_child, level - 1);
        printCurrentLevel(root->right_child, level - 1);
    }
}


void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
    printf("\n\n");
}



int leaf_sum(struct node *roots)
{
  if(roots==NULL)
  {
    return 0;
  }
  if(roots->left_child==NULL&&roots->right_child==NULL)
  {
    return roots->data;
  }
  return (leaf_sum(roots->left_child)+leaf_sum(roots->right_child));
}


int NonLeafSum(struct node* root,int sum)
{
    // Base cases
    if (root == NULL || (root->left_child == NULL
                            && root->right_child == NULL))
        return;

    // if current node is non-leaf,
    // calculate product and sum
    if (root->left_child != NULL || root->right_child != NULL)
    {
        sum += root->data;
    }

    // If root is Not NULL and its one of its
    // child is also not NULL
    NonLeafSum(root->left_child,sum);
    NonLeafSum(root->right_child,sum);
    return sum;
}


int main()
{
    int key,n,i;
    printf("Enter the size\n");
    scanf("%d",&n);
    struct node *root;
    printf("node :0  ");
    scanf("%d",&key);
    root = new_node(key);
    for(i=1;i<n;i++)
    {
        printf("node :%d  ",i);
        scanf("%d",&key);
        insert(root,key);

    }
    printf("\n");
    printf("\nEnter that No you want to delete\t:");
    scanf("%d",&key);
    root = delete(root,key);
    inorder(root);
    printf("\n");
    printf("Hight of tree is %d :",height(root));
    printf("\nLevel Order traversal is : ");
    printLevelOrder(root);
    printf("\nSum of leaf nodes :%d ",leaf_sum(root));
    printf("\nSum of Non leaf nodes :%d ",NonLeafSum(root,0));



    return 0;
}
