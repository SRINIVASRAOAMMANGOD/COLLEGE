#include<stdio.h>

// Function to handle polynomial

void polynomial()
{
  int degree;
  printf("Enter the degree of the polynomial:");
  scanf("%d",&degree);
  int poly1[degree+1],poly2[degree+1],result[degree+1];
  printf("Enter the first polynomial:\n");
  for(int i=0;i<=degree;i++)
  {
   printf("Enter the coefficient for x^%d: ",i);
   scanf("%d",&poly1[i]);
  }
   printf("Enter the second polynomial:\n");
  for(int i=0;i<=degree;i++)
  {
   printf("Enter the coefficient for x^%d: ",i);
   scanf("%d",&poly2[i]);
  }
  
  // adding the polynomials
  
  for(int i=0;i<=degree;i++)
  {

    result[i]=0;
    result[i]=result[i]+(poly1[i]+poly2[i]);
  }
  printf("First polynomial:");
  for(int i=degree;i>=0;i--)
  {
    if(poly1[i] !=0)
    {
      printf("%d",poly1[i]);
      if(i>0)
      {
       printf("x^%d",i);
      }
     if(i>0&&poly1[i-1]>=0)
      {
       printf("+"); 
      }
   }
  }
  printf("\n");
  printf("second polynomial:");
  for( int i=degree;i>=0;i--)
  {
    if(poly2[i]!=0)
    { 
      printf("%d",poly2[i]);
      if(i>0)
      {
       printf("x^%d",i);
      }
      if(i>0&&poly2[i-1]>0)
      { 
       printf("+");
      }
    }
  }
  printf("\n");
  printf("Resultant polynomial:");
  for(int i=degree;i>=0;i--)
  {
   if(result[i]!=0)
    {
     printf("%d",result[i]);
     if(i>0)
      {
       printf("x^%d",i);
      }
     if(i>0&&result[i-1]>=0)
      {
       printf("+");
      }
    }
  }
  printf("\n");
}
 
//Function for main

int main()
{
 polynomial();
 return 0;
}





// OUTPUT

// Enter the degree of the polynomial:4
// Enter the first polynomial:
// Enter the coefficient for x^0: 4
// Enter the coefficient for x^1: 2
// Enter the coefficient for x^2: 3
// Enter the coefficient for x^3: 0
// Enter the coefficient for x^4: 7
// Enter the second polynomial:
// Enter the coefficient for x^0: 0
// Enter the coefficient for x^1: 0
// Enter the coefficient for x^2: 4
// Enter the coefficient for x^3: 5
// Enter the coefficient for x^4: 2
// First polynomial:7x^4+3x^2+2x^1+4
// second polynomial:2x^4+5x^3+4x^2+
// Resultant polynomial:9x^4+5x^3+7x^2+2x^1+4

