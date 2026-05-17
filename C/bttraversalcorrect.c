#include<stdio.h>
#include<stdlib.h>
struct tree{
    struct tree* left;
    int data;
    
    struct tree* right;
};
struct tree  *root,*ptr,*newnode;
struct tree *stack[100];
int top=-1;
int push(struct tree* item){
    top++;
    stack[top]=item;
    return top;
}
struct tree *pop()
{
    struct tree* p2;
    p2=stack[top];
    top--;
    return p2;
}
void preorder(struct tree* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct tree* root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct tree* root){
    if(root!=NULL){
        
        postorder(root->left);
        
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    int a,info;
    printf("DOES TREE HAVE NODE 1or 0:\n");
    scanf("%d",&a);
    if(a==1){
        newnode=(struct tree*)malloc(sizeof(struct tree));
        root=newnode;
        ptr=newnode;

    }else{
        root=NULL;
        ptr=NULL;
        printf("EXIT");
    }
    printf("%d",a);
    top=push(NULL);
    while(ptr!=NULL){
        printf("ENTER THE DATA OF THE NODE:\n");
        scanf("%d",&info);
        ptr->data=info;
        top=push(ptr);
        printf("DOES %d HAS LEFT CHILD:",info);
        scanf("%d",&a);
        if(a==1){
            newnode=(struct tree*)malloc(sizeof(struct tree));
            ptr->left=newnode;
        }else{
            ptr->left=NULL;
        }
       ptr=ptr->left;

        while(ptr==NULL){
            ptr=pop();
            if(ptr==NULL){
                break;
            }
            printf("DOES %d HAS RIFHT CHILD:",ptr->data);
            scanf("%d",&a);
            if(a==1){
                 newnode=(struct tree*)malloc(sizeof(struct tree));
                ptr->right=newnode;
            }else{
                ptr->right=NULL;
            }
            ptr=ptr->right;
        }
    }
    printf("SUCCESS");
    printf("PRE: ");
    preorder(root);
    printf("\n");
    printf("IN: ");
    inorder(root);
    printf("\n");
    printf("POST");
    postorder(root);
    return 0;
}