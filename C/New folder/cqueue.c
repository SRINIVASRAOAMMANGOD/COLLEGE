#include<stdio.h>
int A[20],size,front,rear;

// Function for inserting an item to Circular Queue

void ENQUEUE_CQ(int item)
{
  if(((rear+1)%size)==front)
    printf("Queue is Full ,insertion is not possible\n");
  else if(rear==-1)
  {
     front=0;
     rear=0;
     A[rear]=item;
  }
  else
  {
    rear=(rear+1)%size;
    A[rear]=item;
  }
}

// Function for deleting an item from Circular Queue

void DEQUEUE_CQ()
{
 if(front<= -1) 
    printf("Queue is empty\n");
 else if(front==rear)
 {
  printf("Deleted item is %d\n",A[front]);
  front=-1;
  rear=-1;
 }
 else
 {
   printf("Deleted item is %d \n", A[front]);
   front=(front + 1)%size;
 }
}

// Function for displaying the items in the Circular Queue

void DISPLAY()
{
 int i;
 if(front==-1)
   printf("Queue is empty\n");
 else if(front<=rear)
 { 
   printf("f->");
   for(i=front;i<=rear;i++)
   {
     printf("%d\t",A[i]);
   }
   printf("<-r\n");
   printf("front=%d\n",front);
   printf("rear=%d\n",rear);    
 }
 else
 {
   printf("f->");
   for(i=front;i<=size-1;i++)
     printf("%d\t",A[i]);
   for(i=0;i<=rear;i++)
     printf("%d \t",A[i]);
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
 printf("Enter the size of circular queue: \n");
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
             ENQUEUE_CQ(item);
             DISPLAY();    
             break;
    case 2 : DEQUEUE_CQ();
             DISPLAY();
             break;
    case 3 : DISPLAY();
             break;
    case 4 : break;
             
    case 5 : printf(" \nInvaild choice!Please try again");
  }
 }while(opt!=4);
}



   
 OUTPUT       
     
 Enter the size of circular queue: 
3
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Queue is empty
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
5
f->5	<-r
front=0
rear=0
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
5
f->5	5	<-r
front=0
rear=1
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
9
f->5	5	9	<-r
front=0
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:
1
Enter the item to be inserted: 
9
Queue is Full ,insertion is not possible
f->5	5	9	<-r
front=0
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 5 
f->5	9	<-r
front=1
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 5 
f->9	<-r
front=2
rear=2
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:1
Enter the item to be inserted: 
6
f->9	6 	<-r
front=2
rear=0
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:
1 
Enter the item to be inserted: 
9
f->9	6 	9 	<-r
front=2
rear=1
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 9 
f->6	9	<-r
front=0
rear=1
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 6 
f->9	<-r
front=1
rear=1
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:2
Deleted item is 9
Queue is empty
Menu

 1.ENQUEUE	 2.DEQUEUE 	 3.DISPLAY 	 4.EXIT
 Enter the option:4

    

      
                 

