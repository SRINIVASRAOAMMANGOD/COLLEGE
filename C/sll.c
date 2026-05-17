#include<stdlib.h>
#include<stdio.h>
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node{
    int info;
    struct node *next;

};

struct node *start = NULL;

int main(){
    int choice;
	printf("\n Menu \n");
	printf("\n1.Display");
	printf("\n2.Insert at the beginning");
	printf("\n3.Insert at the end");
	printf("\n4.Insert at specified position");
	printf("\n5.Delete from beginning");
	printf("\n6.Delete from the end");
	printf("\n7.Delete from specific position");
	printf("\n8.Exit");
    while(1){
   	 printf("\n Enter your choice");
   	 scanf("%d",&choice);
   	 switch(choice){
   		 case 1: display();
   			 break;
   		 case 2: insert_begin();
   			 break;
   		 case 3: insert_end();
   			 break;
   		 case 4: insert_pos();
   			 break;
   		 case 5: delete_begin();
   			 break;
   		 case 6: delete_end();
   			 break;
   		 case 7: delete_pos();
   			 break;
   		 case 8: exit(0);
   			 break;
   		 default: printf("\n Wrong choice");
   	 }
   		 
    
    }
    return 0;

}

void display(){
    struct node *ptr;
    if(start==NULL){
   	 printf("\n List is empty");
   	 return;
    }
    else{
   	 ptr=start;
   	 printf("In the list elements are\n");
   	 while(ptr!=NULL){
   		 printf("%d\t",ptr->info);
   		 ptr=ptr->next;
   	 }
    }
}

void insert_begin(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
   	 printf("\n Overflow");
   	 return;
    }
    
    printf("\n Enter the data value of the node \t");
    scanf("%d",&temp->info);
    temp->next = NULL;
    if(start==NULL)
   	 start = temp;
    else{
   	 temp->next=start;
   	 start = temp;
    }
}

void insert_end(){
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp==NULL){
   	 printf("\n Overflow");
   	 return;
    }
    
    printf("\n Enter the data value of the node \t");
    scanf("%d",&temp->info);
    temp->next = NULL;
    if(start==NULL)
   	 start = temp;
    else{
   	 ptr=start;
   	 while(ptr->next!=NULL){
   		 ptr=ptr->next;   	 
   	 }
   	 ptr->next = temp;
    }
}

void insert_pos(){
    struct node *ptr,*temp;
    int i,pos;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp==NULL){
   	 printf("\n Overflow");
   	 return;
    }
    
    printf("\n Enter the position for the new node to be inserted \t");
    scanf("%d",&pos);
    printf("\n Enter the data value of the node \t");
    scanf("%d",&temp->info);
    temp->next = NULL;
    
    if(pos==0){
   	 temp->next=start;
   	 start = temp;
    }
    else{
   	 for(i=0,ptr=start;i<pos-1;i++){
   		 ptr = ptr->next;
   		 if(ptr==NULL){
   			 printf("\n Position not found");
   			 return;
   		 }
   	 }
   	 temp->next = ptr->next;
   	 ptr->next = temp;
    }
}


void delete_begin(){
    struct node *ptr;
    if(start==NULL){
   	 printf("\n Underflow");
   	 return;
    }
    else{
   	 printf("1");
   	 ptr=start;
   	 printf("2");
   	 start = start->next;
   	 printf("\n The deleted element is %d \t",ptr->info);
   	 free(ptr);
    }

}

void delete_end(){
    struct node *temp, *ptr;
    if(start==NULL){
   	 printf("\n Underflow");
   	 return;
    }
    else if(start->next==NULL){
   	 ptr=start;
   	 start=NULL;
   	 printf("\n The deleted element is %d",ptr->info);
   	 free(ptr);
    }
    else{
   	 ptr=start;
   	 while(ptr->next!=NULL){
   		 temp = ptr;
   		 ptr=ptr->next;
   	 }
   	 temp->next = NULL;
   	 printf("\n The deleted element is %d \t",ptr->info);
   	 free(ptr);
    }
}

void delete_pos(){
    int i,pos;
    struct node *ptr, *temp;
    if(start==NULL){
   	 printf("\n Underflow");
   	 exit(0);
    }
    else{
   	 printf("\n Enter the position to be deleted");
   	 scanf("%d",&pos);
   	 if(pos == 0){
   		 ptr = start;
   		 start = start->next;
   		 printf("\n The deleted element is %d \t",ptr->info);
   		 free(ptr);
   	 }
   	 else{
   		 ptr = start;
   		 for(i=0;i<pos;i++){
   			 temp = ptr;
   			 ptr = ptr->next;
   			 if(ptr == NULL){
   				 printf("\n Position not found");
   				 return;
   			 }
   		 
   		 }
   		 temp->next = ptr->next;
   		 printf("\n The deleted element is %d \t",ptr->info);
   		 free(ptr);
   	 }
    
    }
}