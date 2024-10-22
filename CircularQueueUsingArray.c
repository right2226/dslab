#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

typedef struct CircularQueue {
    int front;
    int rear;
    int items[MAX_SIZE];
} CircularQueue;

// Function to initialize the circular queue
void initQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to insert an element into the circular queue
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Set front to 0 if queue was empty
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    queue->items[queue->rear] = value; // Insert the element
    printf("Inserted %d into the queue\n", value);
}

// Function to remove an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1; // Return -1 or some error value
    }
    int removedValue = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // If the queue becomes empty after this dequeue
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
    }
    return removedValue;
}

// Function to display the elements in the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE; // Circular increment
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

// Main function to demonstrate the circular queue operations
int main() {
    CircularQueue queue;
    initQueue(&queue);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued %d from the queue\n", value);
                }
                break;
            case 3:
                display(&queue);
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

