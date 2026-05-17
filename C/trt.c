#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree *root, *ptr;
struct tree *stack[100];
int top = -1;

int push(struct tree* item) {
    top++;
    stack[top] = item;
    return top;
}

struct tree* pop() {
    struct tree* p2;
    p2 = stack[top];
    top--;
    return p2;
}

void preorder(struct tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct tree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int a, info;
    printf("DOES TREE HAVE NODE (1 or 0):\n");
    scanf("%d", &a);
    
    if (a == 1) {
        struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
        root = newnode;
        ptr = newnode;
    } else {
        root = NULL;
        ptr = NULL;
        printf("EXIT\n");
        return 0;
    }

    top = push(NULL);
    
    while (ptr != NULL) {
        printf("ENTER THE DATA OF THE NODE:\n");
        scanf("%d", &info);
        ptr->data = info;
        
        printf("DOES %d HAVE LEFT CHILD (1 or 0):\n", ptr->data);
        scanf("%d", &a);
        if (a == 1) {
            struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
            ptr->left = newnode;
        } else {
            ptr->left = NULL;
        }
        
        if (ptr->left != NULL) {
            top = push(ptr->left);
            ptr = ptr->left;
        } else {
            // Check for right child if no left child
            printf("DOES %d HAVE RIGHT CHILD (1 or 0):\n", ptr->data);
            scanf("%d", &a);
            if (a == 1) {
                struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
                ptr->right = newnode;
            } else {
                ptr->right = NULL;
            }
            ptr = ptr->right;
        }

        while (ptr == NULL && top >= 0) {
            ptr = pop();
            if (ptr != NULL) {
                break;
            }
        }
    }

    printf("SUCCESS\n");
    printf("PRE: ");
    preorder(root);
    printf("\n");
    printf("IN: ");
    inorder(root);
    printf("\n");
    printf("POST: ");
    postorder(root);
    printf("\n");

    return 0;
}
