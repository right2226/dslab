#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int maxSize;
    int *arr;
} Stack;

void initStack(Stack *stack, int size) {
    stack->maxSize = size;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->maxSize * sizeof(int));
}

int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto stack\n", value);
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    int size;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &size);

    // Initialize the stack
    initStack(&stack, size);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                display(&stack);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    free(stack.arr);  // Free allocated memory
    return 0;
}

