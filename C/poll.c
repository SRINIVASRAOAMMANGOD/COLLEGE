#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, expo;
    struct node* next;
};

struct node* phead, * qhead, * rhead, * mhead;

struct node* readpoly() {
    struct node* ptr, * head = NULL;
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = -1; i < n; i++) {
        struct node* new = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &new->coeff, &new->expo);
        new->next = NULL;  // Initialize next to NULL
        if (head == NULL) {
            head = new;
            ptr = new;
        } else {
            ptr->next = new;
            ptr = new;
        }
    }
    return head;
}

void display(struct node* head) {
    struct node* ptr;
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            printf("%dx^%d + ", ptr->coeff, ptr->expo);
            ptr = ptr->next;
        }
        printf("%dx^%d\n", ptr->coeff, ptr->expo);
    }
}

struct node* addpoly() {
    struct node *p = phead, *q = qhead, *r = NULL, *new, *tail = NULL;

    while (p != NULL && q != NULL) {
        if (p->expo == q->expo) {
            new = (struct node*)malloc(sizeof(struct node));
            new->expo = p->expo;
            new->coeff = p->coeff + q->coeff;
            new->next = NULL;
            p = p->next;
            q = q->next;
        } else if (p->expo > q->expo) {
            new = (struct node*)malloc(sizeof(struct node));
            new->expo = p->expo;
            new->coeff = p->coeff;
            new->next = NULL;
            p = p->next;
        } else {
            new = (struct node*)malloc(sizeof(struct node));
            new->expo = q->expo;
            new->coeff = q->coeff;
            new->next = NULL;
            q = q->next;
        }

        if (r == NULL) {
            r = new;//r is resultand head
            tail = r;//instead of head tail given
        } else {
            tail->next = new;
            tail = new;
        }
    }

    while (p != NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->coeff = p->coeff;
        new->expo = p->expo;
        new->next = NULL;
        if (r == NULL) {
            r = new;
            tail = r;
        } else {
            tail->next = new;
            tail = new;
        }
        p = p->next;
    }

    while (q != NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->coeff = q->coeff;
        new->expo = q->expo;
        new->next = NULL;
        if (r == NULL) {
            r = new;
            tail = r;
        } else {
            tail->next = new;
            tail = new;
        }
        q = q->next;
    }

    return r;
}

struct node* mulpoly() {
    struct node *p = phead, *q, *r = NULL, *new, *tail;
    
    while (p != NULL) {
        q = qhead;
        while (q != NULL) {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p->coeff * q->coeff;
            new->expo = p->expo + q->expo;
            new->next = NULL;
            
            // Insert the new node in the result polynomial (sorted by exponent)
            if (r == NULL) {
                r = new;
                tail = r;
            } else {
                tail->next = new;
                tail = new;
            }
            
            q = q->next;
        }
        p = p->next;
    }

    // Combine terms with the same exponent
    struct node *p1 = r, *prev = NULL, *q1;
    while (p1 != NULL) {
        q1 = p1->next;
        prev = p1;
        while (q1 != NULL) {
            if (p1->expo == q1->expo) {
                p1->coeff += q1->coeff;
                prev->next = q1->next;
                free(q1);
                q1 = prev->next;
            } else {
                prev = q1;
                q1 = q1->next;
            }
        }
        p1 = p1->next;
    }
    return r;
}

int main() {
    printf("Enter first polynomial:\n");
    phead = readpoly();
    printf("Enter second polynomial:\n");
    qhead = readpoly();
    
    printf("First Polynomial: ");
    display(phead);
    
    printf("Second Polynomial: ");
    display(qhead);
    
    rhead = addpoly();
    printf("Resultant Polynomial after Addition: ");
    display(rhead);

    mhead = mulpoly();
    printf("Resultant Polynomial after Multiplication: ");
    display(mhead);

    return 0;
}
