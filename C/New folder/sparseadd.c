//ADDITION OF 2 SPARSE MATRICES

#include<stdio.h>
#define MAX 100

void createsparse(int spmat[MAX][3],int normat[][5],int r,int c)
{
 int k=1;
 spmat[0][0]=r;
 spmat[0][1]=c;
 for(int i=0;i<r;i++)
 { 
  for(int j=0;j<c;j++)
  {
   if(normat[i][j]!=0)
   {
    spmat[k][0]=i;
    spmat[k][1]=j;
    spmat[k][2]=normat[i][j];
    k++;
   }
  }
 }
 spmat[0][2]=k-1;
}

void addsparse(int result[MAX][3],int mat1[MAX][3],int mat2[MAX][3])
{
 int i=1,j=1,k=1;
 while(i<=mat1[0][2] && j<=mat2[0][2])
 {
  if(mat1[i][0]<mat2[j][0] || (mat1[i][0]==mat2[j][0] && mat1[i][1]<mat2[j][1]))
  {
   result[k][0]=mat1[i][0];
   result[k][1]=mat1[i][1];
   result[k][2]=mat1[i][2];
   i++;
  }
  else if(mat1[i][0]>mat2[j][0] || (mat1[i][0]==mat2[j][0] && mat1[i][1]>mat2[j][1]))
  {
   result[k][0]=mat2[j][0];
   result[k][1]=mat2[j][1];
   result[k][2]=mat2[j][2];
   j++;
  }
  else
  {
   result[k][0]=mat1[i][0];
   result[k][1]=mat1[i][1];
   result[k][2]=mat1[i][2]+mat2[j][2];
   i++;
   j++;
  }
  k++;
 }
 while(i<=mat1[0][2])
 {
  result[k][0]=mat1[i][0];
  result[k][1]=mat1[i][1];
  result[k][2]=mat1[i][2];
  i++; 
  k++;
 }
 while(j<=mat2[0][2])
 { 
  result[k][0]=mat2[j][0];
  result[k][1]=mat2[j][1];
  result[k][2]=mat2[j][2];
  j++;
  k++;
 }
 result[0][0]=mat1[0][0];
 result[0][1]=mat1[0][1];
 result[0][2]=k-1;
}

void display(int spmat[MAX][3])
{
 for(int i=0;i<=spmat[0][2];++i)
 {
  printf("%d %d %d\n",spmat[i][0],spmat[i][1],spmat[i][2]);
 }
}

int main()
{
 int r,c,normat1[5][5],normat2[5][5];
 printf("enter no:of rows and columns of matrix:");
 scanf("%d %d",&r,&c);
 printf("enter elements of 1st matrix:\n");
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   printf("element(%d)(%d) - ",i,j); 
   scanf("%d",&normat1[i][j]);
  }
 }
 printf("enter elements of 2nd matrix:\n");
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   printf("element(%d)(%d) - ",i,j); 
   scanf("%d",&normat2[i][j]);
  }
 }
 int spmat1[MAX][3];
 int spmat2[MAX][3];
 int result[MAX][3];
 createsparse(spmat1,normat1,r,c);
 createsparse(spmat2,normat2,r,c);
 printf("sparse matrix 1: \n");
 display(spmat1);
 printf("sparse matrix 2: \n");
 display(spmat2); 
 addsparse(result,spmat1,spmat2);
 printf("\nresultant sparse matrix :\n");
 display(result);
 return 0;
}
 
/* OUTPUT :

enter no:of rows and columns of matrix:2
3
enter elements of 1st matrix:
element(0)(0) - 2
element(0)(1) - 0
element(0)(2) - 0
element(1)(0) - 5
element(1)(1) - 0
element(1)(2) - 3
enter elements of 2nd matrix:
element(0)(0) - 5
element(0)(1) - 0
element(0)(2) - 1
element(1)(0) - 0
element(1)(1) - 0
element(1)(2) - 2
sparse matrix 1: 
2 3 3
0 0 2
1 0 5
1 2 3
sparse matrix 2: 
2 3 3
0 0 5
0 2 1
1 2 2

resultant sparse matrix :
2 3 4
0 0 7
0 2 1
1 0 5
1 2 5

*/
 
  
  
  
