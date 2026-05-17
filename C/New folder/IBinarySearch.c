//Program to perform BinarySearch(iterative)

#include<stdio.h>
// function for BinarySearch(iterative)
int IBinarySearch(int A[],int size,int key)
{
   int mid;
   int l=0,h=size-1;
   while(l<=h)
       {
        mid=(l+h)/2;
       if(A[mid]==key)
         return mid;
       if(A[mid]>key)
         h=mid-1;
       else
          l=mid+1;
}
  return(-1);
} 

 //Main function
int main()
{
  int A[20],size,key,i,result;
  printf("this is a program to perform iterative binary search\n");
  printf("\nenter array size:- ");
  scanf("%d",&size);
  printf("enter the %d elements of the array (in ascending order)\n",size);
  for(i=0;i<size;i++)
    {
      scanf("%d",&A[i]);
    }
  printf("enter the element to be searched,key= ");
  scanf("%d",&key);
  result=IBinarySearch(A,size,key);
  if(result==-1)
       printf("key %d not found",key);
  else
       printf("key %d found at index %d",key,result);
}


/* output-1
  
  this is a program to perform iterative binary search

  enter array size:- 5    
  enter the 5 elements of the array (in ascending order)
  23
  34
  45
  56
  67
  enter the element to be searched,key= 67
  key 67 found at index 4
  
  output-2
  
  this is a program to perform iterative binary search

  enter array size:- 5
  enter the 5 elements of the array (in ascending order)
  -1
   0
   2
   4
   5
   enter the element to be searched,key= 2
   key 2 found at index 2
   
   output-3
    
    this is a program to perform iterative binary search

  enter array size:- 4
  enter the 4 elements of the array (in ascending order)
  -12
  -1
   0
   34
  enter the element to be searched,key= 20
  key 20 not found
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
