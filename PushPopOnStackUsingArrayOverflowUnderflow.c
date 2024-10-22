#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

typedef struct Stack {
    int top;
    int items[MAX_SIZE];
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1; // Initialize top to -1 to indicate an empty stack
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->items[++stack->top] = value; // Increment top and add value
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Return -1 to indicate error
    }
    return stack->items[stack->top--]; // Return the top value and decrement top
}

// Function to display the stack elements
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped %d from the stack\n", value);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

