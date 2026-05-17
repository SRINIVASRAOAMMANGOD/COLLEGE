#include<stdio.h>
int A[20],size,front,rear;

// Function for inserting an item to Queue
void ENQUEUE(int item)
{
  if(rear==size-1)
   printf("Queue overflow\n");
  else if(rear==-1)
  {
    front=0;
    rear=0;
    A[rear]=item;
  }
   else
   {
      rear++;
      A[rear]=item;
   }
}

// Function for deleting an item from Queue

void DEQUEUE()
{
 if(front==-1)
  printf("Queue is empty\n"); 
 else if(front==rear)
  {
    printf("Deleted item is %d\n",A[front]);    
    rear=-1;
    front=-1;
  }
  else
  {
     printf("Deleted item is %d\n",A[front]);    
     front++;
  } 
}

// Function for displaying the items in the Queue

void display()
{
  int i;
  if(front==-1)
  {
     printf("Queue is empty\n"); 
  }
  else
  { 
    printf("The queue elements are \n");
    printf("f->");
    for(i=front;i<=rear;i++)
    {
      printf("%d\t",A[i]);
    }
    printf("<-r\n");
    printf("front=%d\n",front);
    printf("rear=%d\n",rear);
    
  }  
}

// Function for main()

int main()
{
 int opt,item;
 rear=-1;
 front=-1;
 printf("Enter the size of Queue: \n");
 scanf("%d",&size);
 do
 { 
  printf("Menu\n");
  printf("\n 1.ENQUEUE\t 2.DEQUEUE \t 3.DISPLAY \t 4.EXIT");
  printf("\n Enter the option:");
  scanf("%d",&opt);
  switch(opt)
  { 
    case 1 : printf("Enter the item to be inserted: \n");
             scanf("%d",&item);
             ENQUEUE(item);
             display();    
             break;
    case 2 : DEQUEUE();
             display();
             break;
    case 3 : display();
             break;
    case 4 : break;
             
    case 5 : printf(" \nInvaild choice!Please try again");
  }
 }while(opt!=4);
}
   
   



OUTPUT

Enter the size of Queue: 
3
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Queue is empty
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
3
The queue elements are 
f->3	<-r
front=0
rear=0
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
7
The queue elements are 
f->3	7	<-r
front=0
rear=1
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
9
The queue elements are 
f->3	7	9	<-r
front=0
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
8
Queue overflow
The queue elements are 
f->3	7	9	<-r
front=0
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 3
The queue elements are 
f->7	9	<-r
front=1
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 7
The queue elements are 
f->9	<-r
front=2
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
4
Queue overflow
The queue elements are 
f->9	<-r
front=2
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 9
Queue is empty
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:4
  
