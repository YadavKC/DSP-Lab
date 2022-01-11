#include <stdio.h>
#include <stdlib.h>
#define size 10


int adj[size][size];
int visited[size];


int mtrx(int n)
{
   
   int i,j;
   int link;
   printf("\n\n---Enter 1 if nodes are connected---\n---Enter 0 if nodes are'nt connected---\n\n");
   for(i=1;i<=n;i++)
   {
     for(j=i+1;j<=n;j++)
       {
          
          printf("\nFrom node%d to node%d : ",i,j);
          scanf("%d",&link);

          if(1==link || 0==link)
          {
            adj[i][j]=link;
            adj[j][i]=link;
            }
          else
          {
            printf("\nWrong Entry");
            return 0;
           }
       }
      }
    
   return 0;
}




int pf_mtrx(int n)
{    
     int i,j;
     printf("\nAdjecency Matrix is\n");
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=n;j++)
        {
           printf("%d ",adj[i][j]);          
        }
        printf("\n");
     }
    return 0;
}

void DFS(int v,int n)  
{
	int i;

	visited[v]=1;
	for (i=1;i<=n;i++)
	  if(adj[v][i] && !visited[i]) 
	  {
		printf("\n %d->%d\n",v,i);
		DFS(i,n);
	   }
}


int main()
{
    int n,x;
    printf("Enter the no of nodes in Graph :");
    scanf("%d",&n);
    mtrx(n);
    pf_mtrx(n);
    DFS(1,n);
    return 0;
 }
