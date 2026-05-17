#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
}

// Insert at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

// Insert in sorted order
struct Node* insertInSortedOrder(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
    return head;
}

// Count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Delete from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Delete from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;  // If only one node exists
    }
    free(temp);
    return head;
}

// Reverse the list
struct Node* reverseList(struct Node* head) {
    if (head == NULL) {
        return head;
    }
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert in sorted order\n");
        printf("4. Count the number of nodes\n");
        printf("5. Reverse the list\n");
        printf("6. Delete from the beginning\n");
        printf("7. Delete from the end\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the data to insert in sorted order: ");
                scanf("%d", &data);
                head = insertInSortedOrder(head, data);
                break;
            case 4:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 5:
                head = reverseList(head);
                printf("The list has been reversed.\n");
                break;
            case 6:
                head = deleteFromBeginning(head);
                printf("Node deleted from the beginning.\n");
                break;
            case 7:
                head = deleteFromEnd(head);
                printf("Node deleted from the end.\n");
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
