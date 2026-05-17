#include <stdio.h>
#include <stdlib.h>
/*int countLeafNodes(struct Node* root) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }
    
    // If it's a leaf node (both left and right are NULL)
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}*/
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *root, int key) {
    if (root == NULL) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->left = newnode->right = NULL; // Corrected initialization
        return newnode;
    } else {
        if (key < root->data) {
            root->left = insert(root->left, key); // Corrected recursive call
        } else if (key > root->data) {
            root->right = insert(root->right, key); // Corrected recursive call
        }
    }
    return root;
}

void display(struct node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

struct node* search(struct node *root, int key) {
    if (root == NULL || key == root->data) {
        return root;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

struct node* findmin(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deletenode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deletenode(root->left, key);
    } else if (key > root->data) {
        root->right = deletenode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data); // Corrected deletion
    }
    return root;
}
int main(){ 
    struct node *root = NULL; 
    int ch, key; 
    struct node *result; 
 
    do { 
        printf("\n---MENU---\n"); 
        printf("1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n\nEnter your choice:"); 
        scanf("%d", &ch); 
 
        switch (ch) { 
            case 1: 
                printf("Enter the key to insert:"); 
                scanf("%d", &key); 
                root = insert(root, key); 
                display(root); 
                break; 
 
            case 2: 
                printf("\nEnter the key to search:"); 
                scanf("%d", &key); 
                result = search(root, key); 
 
                if (result != NULL) { 
                    printf("\nKey %d found in the BST\n", key); 
                } else { 
                    printf("\nKey %d not found in the BST\n", key); 
                } 
                break; 
 
            case 3: 
                printf("\nEnter the key to delete:"); 
                scanf("%d", &key); 
                root = deletenode(root, key); 
                break;   
 
            case 4: 
                display(root); 
                break; 
 
            case 5: 
                printf("\nExiting...\n"); 
                break; 
 
            default: 
                printf("\nInvalid choice [TRY AGAIN]\n"); 
                break; 
        } 
 
    }while(ch != 5); 
    return 0; 
} 