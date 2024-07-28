#include <stdio.h>

int top = -1; // Global top is fine if you want to keep it global, but it's better to use local variables.

int isempty() {
    return top == -1;
}

int isfull(int n) {
    return top == n - 1;
}

void push(int stack[], int n) {
    int data;
    printf("ENTER NUMBER TO BE ADDED: ");
    scanf("%d", &data);
    if (!isfull(n)) {
        top++;
        stack[top] = data;
    } else {
        printf("STACK IS FULL. POP ELEMENT FIRST.\n");
    }
}

void pop(int stack[]) {
    if (!isempty()) {
        printf("Popped Element: %d\n", stack[top]);
        top--;
    } else {
        printf("EMPTY STACK. PUSH ELEMENT FIRST.\n");
    }
}

void display(int stack[]) {
    if (isempty()) {
        printf("STACK IS EMPTY.\n");
        return;
    }
    printf("STACK ELEMENTS:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int n, ch;
    printf("ENTER LENGTH OF STACK: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid stack size.\n");
        return 1;
    }
    
    int stack[n];
    printf("STACK INITIALIZED. YOU CAN NOW PUSH ELEMENTS.\n");

    do {
        printf("ENTER CHOICE\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push(stack, n);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 4);

    return 0;
}
