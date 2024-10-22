#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push function to add an element to the stack
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto stack\n", value);
}

// Pop function to remove an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from stack\n");
        return -1; // Return -1 or some error value
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

// Show function to display the elements of the stack
void show(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
        printf("3. Show\n");
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
                    printf("Popped %d from stack\n", value);
                }
                break;
            case 3:
                show(&stack);
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

