//SPARSE MATRIX AND ITS TRANSPOSE REPRESENTATION
#include<stdio.h>
void main()
{
 int a[5][5],i,j,k=0,r,c,p=1;
 printf("enter the order of the matrix \n");
 scanf("%d%d",&r,&c);
 printf("the elements are \n");
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   scanf("%d",&a[i][j]);
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
  { 
   if(a[i][j]!=0)
   k++;
  }
 int sparse[k+1][3],trans[k+1][3];
 sparse[0][0]=r;
 sparse[0][1]=c;
 sparse[0][2]=k;
 for(i=0;i<r;i++)
  for(j=0;j<c;j++) 
   if(a[i][j]!=0)
   {
    sparse[p][0]=i;
    sparse[p][1]=j;
    sparse[p][2]=a[i][j];
    p++;
   }
 trans[0][0]=c;
 trans[0][1]=r;
 trans[0][2]=k;
 p=1;
 for(i=0;i<c;i++)
  for(j=1;j<k+1;j++)
   if(sparse[j][1]==i)
   {
    trans[p][0]=sparse[j][1];
    trans[p][1]=sparse[j][0];
    trans[p][2]=sparse[j][2];
    p++;
   }
   printf("sparse representation\n");
   for(i=0;i<k+1;i++)
   {
    for(j=0;j<3;j++)
    {
     printf("%d ",sparse[i][j]);
    }
    printf("\n");
   }
   printf("sparse transpose representation\n");
   for(i=0;i<k+1;i++)
   {
    for(j=0;j<3;j++)
    {
     printf("%d ",trans[i][j]);
    }
    printf("\n");
   }
}
/* OUTPUT :
enter the order of the matrix 
3
2
the elements are
1
0
2
0
0
3
sparse representation
3 2 3 
0 0 1 
1 0 2 
2 1 3 
sparse transpose representation
2 3 3 
0 0 1 
0 1 2 
1 2 3 
*/
    
    
    
    
    
    
