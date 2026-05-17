//Program to perform BinarySearch(recursive)

#include<stdio.h>
//function for BinarySearch(recursive)
int RBinarySearch(int A[],int l,int h,int key)
 {
           int mid;
           if(l<=h)
           {
             mid=(l+h)/2;
             if(A[mid]==key)
                 return mid;
            else if(A[mid]>key)
                 return RBinarySearch(A,l,mid-1,key);
            else 
                 return RBinarySearch(A,mid+1,h,key);
           }
         else
            return(-1);
  }
  
  //Main function
int main()
{
  int A[20],size,key,i,result;
  printf("this is a program to perform recursive binary search\n");
  printf("\nenter array size:- ");
  scanf("%d",&size);
  printf("enter the %d elements of the array(in ascending order)\n",size);
  for(i=0;i<size;i++)
    {
      scanf("%d",&A[i]);
    }
 printf("enter the element to be searched,key= ");
 scanf("%d",&key);
 result=RBinarySearch(A,0,size-1,key);
 if(result==-1)
     printf("key %d not found",key);
 else
    printf("key %d found at index %d",key,result);
} 
 
 
 /*output-1
 
 this is a program to perform recursive binary search

 enter array size:- 5
 enter the 5 elements of the array(in ascending order)
 12
 34
 56
 78
 90
 enter the element to be searched,key= 90
 key 90 found at index 4
 
 output-2
 
 this is a program to perform recursive binary search

 enter array size:- 5
 enter the 5 elements of the array(in ascending order)
 -13
 -10
 -1
  0
  3
 enter the element to be searched,key= -1
 key -1 found at index 2
 
 output-3
 
 this is a program to perform recursive binary search

 enter the 5 elements of the array(in ascending order)
 2
 7
 8
 9
 10
 enter the element to be searched,key= 12
 key 12 not found
