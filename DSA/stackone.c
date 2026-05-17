#include <stdio.h>

int main() {
    int a, b, i, x;
    int top = -1;

    printf("1-PUSH, 2-POP, 3-DISPLAY\n");
    scanf("%d", &a);

    printf("ENTER THE LENGTH OF THE ARRAY FOR STACK:\n");
    scanf("%d", &b);

    int stack[b];

    do {
        switch (a) {
            case 1:
                printf("ENTER ELEMENT TO BE PUSHED: ");
                scanf("%d", &x);
                top++;
                stack[top] = x;
                break;

            case 2:
                if (top == -1) {
                    printf("STACK IS EMPTY\n");
                } else {
                    top--;
                }
                break;

            case 3:
                if (top == -1) {
                    printf("EMPTY\n");
                } else {
                    for (i = top; i >= 0; i--) {
                        printf("%d ", stack[i]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("INVALID CHOICE\n");
                break;
        }

        printf("ENTER CHOICE 1-PUSH, 2-POP, 3-DISPLAY ANY OTHER KEY TO EXIT: ");
        scanf("%d", &a);
    } while (a == 1 || a == 2 || a == 3);

    return 0;
}
