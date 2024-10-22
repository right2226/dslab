#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the stack
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* createNode(char data) {
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
void push(Stack* stack, char value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop function to remove an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character if stack is empty
    }
    Node* temp = stack->top;
    char poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

// Function to reverse the string using the stack
void reverseString(const char* str, char* reversedStr) {
    Stack stack;
    initStack(&stack);

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    // Pop all characters from the stack to get the reversed string
    int index = 0;
    while (!isEmpty(&stack)) {
        reversedStr[index++] = pop(&stack);
    }
    reversedStr[index] = '\0'; // Null-terminate the reversed string
}

int main() {
    char str[100], reversedStr[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character if present

    reverseString(str, reversedStr);
    printf("Reversed string: %s\n", reversedStr);

    return 0;
}

