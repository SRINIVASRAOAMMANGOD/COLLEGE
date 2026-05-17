// Program to perform LinearSearch

#include<stdio.h>
// function for LinearSearch
int LinearSearch(int a[],int s,int k)
{
  int i;
  for(i=0;i<s;i++)
   {
     if(k==a[i])
     return i;
   }
    return -1;
 }
 
// Main function
int main()
{
   int a[20],size,key,i,b=-1; 
   printf("\nProgram for LinearSearch");
   printf("\nenter array size : ");
   scanf("%d",&size);
   printf("\n enter the key to search : ");
   scanf("%d",&key);
   printf("\n enter %d elements :- \n",size);
   for(i=0;i<size;i++)
   {
      scanf("%d",&a[i]);
   }
   b=LinearSearch(a,size,key);
   if(b==-1)
      printf("key %d not found",key);
   else
      printf("key %d found at index %d",key,b);
} 


/* output-1

  Program for LinearSearch
  enter array size : 5

  enter the key to search : 4

  enter 5 elements :- 
  6
  8
  2
  9
  0
  key 4 not found
  
  output-2
  
  Program for LinearSearch
  enter array size : 5

  enter the key to search : -12

 enter 5 elements :- 
 12
 24
 0
 -13
 -12
 key -12 found at index 4
 
 output-3
 
 Program for LinearSearch
 enter array size : 5

 enter the key to search : 67

 enter 5 elements :- 
 12
 47
 67
 89
 23
 key 67 found at index 2
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

