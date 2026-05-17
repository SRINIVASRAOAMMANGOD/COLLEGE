#include<stdio.h>
#define max 100
int main(){
int p1[max+1],p2[max+1],p3[max+1],d1,d2,d3,i,j;
 printf("Enter the degree of the polynomial:");
  scanf("%d %d",&d1,&d2);
printf("Enter the first polynomial:\n");
  for(int i=0;i<=d1;i++)
  {
   printf("Enter the coefficient for x^%d: ",i);
   scanf("%d",&p1[i]);
  }
printf("Enter the second polynomial:\n");
  for(int i=0;i<=d2;i++)
  {
   printf("Enter the coefficient for x^%d: ",i);
   scanf("%d",&p2[i]);
  }
d3=d1>d2?d1:d2;
for(i=0;i<=d3;i++){
p3[i]=0;
p3[i]=p1[i]+p2[1];
}
printf("The sum of the polynomials is:\n");
for(i=0;i<=d3;i++)
{
    printf("%dx^%d + ",p3[i],i);
    printf("\n");
    \
    }
    return 0;
}