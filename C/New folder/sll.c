#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* next;
};
void ib(struct node** head,int data){
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=*head;
    *head=nn;
}
void ie(struct node** head,int data){
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    if(*head==NULL){
        *head=nn;
        return;
    }
    struct node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nn;
}
void is(struct node** head,int data){
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    if(*head==NULL||(*head)->data>=nn->data){
        nn->next = *head; // Link to the old head
        *head = nn; // Update head to new node
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL && temp->next->data < nn->data) {
        temp = temp->next;
    }
    nn->next = temp->next; // Link new node to the next node
    temp->next = nn; 
}
