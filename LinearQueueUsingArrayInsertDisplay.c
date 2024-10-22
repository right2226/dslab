#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

typedef struct Queue {
    int front;
    int rear;
    int items[MAX_SIZE];
} Queue;

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to insert an element into the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Set front to 0 if queue was empty
    }
    queue->items[++queue->rear] = value; // Insert the element
    printf("Inserted %d into the queue\n", value);
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                display(&queue);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

