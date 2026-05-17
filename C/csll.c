#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insert(struct node* head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head; // Point to itself
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; // Make it circular
    }
    return head;
}

struct node* delete(struct node* head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct node *temp = head, *prev = NULL;

    // If the node to be deleted is the head
    if (head->data == data) {
        if (head->next == head) { // Only one node
            free(head);
            return NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            struct node* toDelete = head;
            head = head->next;
            temp->next = head; // Update the last node's next
            free(toDelete);
            return head;
        }
    }

    // Search for the node to delete
    prev = head;
    temp = head->next;
    while (temp != head) {
        if (temp->data == data) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Node with data %d not found.\n", data);
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node* temp = head;
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int data, n;
    while (1) {
        printf("1-in\n2-de\n3-dis\n4-exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = delete(head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}