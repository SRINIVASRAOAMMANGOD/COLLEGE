#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
struct Node* insert_at_beginning(struct Node* head, int new_data) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data to the new node
    new_node->data = new_data;
    
    // Point the new node's next to the current head
    new_node->next = head;
    
    // Return the new head (the new node)
    return new_node;
}

// Function to insert a node at the end of the list
struct Node* insert_at_end(struct Node* head, int new_data) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data to the new node
    new_node->data = new_data;
    new_node->next = NULL;  // This will be the last node, so its next is NULL
    
    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        return new_node;
    }

    // Otherwise, traverse the list to find the last node
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Link the last node to the new node
    last->next = new_node;
    
    // Return the head, which hasn't changed
    return head;
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 30);
    
    printf("List after inserting at beginning: ");
    print_list(head);
    
    // Insert nodes at the end
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);
    
    printf("List after inserting at end: ");
    print_list(head);
    
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the node at the beginning of the list
struct Node* delete_at_beginning(struct Node* head) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    
    // Save the current head for later deletion
    struct Node* temp = head;
    
    // Move the head to the next node
    head = head->next;
    
    // Free the memory of the old head
    free(temp);
    
    return head;
}

// Function to delete the node at the end of the list
struct Node* delete_at_end(struct Node* head) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    
    // If the list has only one node
    if (head->next == NULL) {
        free(head);
        return NULL;  // List is now empty
    }
    
    // Traverse to find the second-to-last node
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Now temp points to the second-to-last node, delete the last node
    free(temp->next);
    temp->next = NULL;  // Set the second-to-last node's next to NULL
    
    return head;
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    struct Node* head = NULL;
    
    // Manually creating a linked list for testing
    // Insert nodes at the beginning
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 30);
    
    printf("List after inserting at beginning: ");
    print_list(head);
    
    // Insert nodes at the end
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);
    
    printf("List after inserting at end: ");
    print_list(head);
    
    // Delete the node at the beginning
    head = delete_at_beginning(head);
    printf("List after deleting at beginning: ");
    print_list(head);
    
    // Delete the node at the end
    head = delete_at_end(head);
    printf("List after deleting at end: ");
    print_list(head);
    
    return 0;
}
