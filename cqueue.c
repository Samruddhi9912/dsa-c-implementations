#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {   // first element
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;        // circular condition
    }
    else {
        rear++;
    }

    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);

    if (front == rear) { // only one element
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;       // circular condition
    }
    else {
        front++;
    }
}

// Display
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } 
    else {
        for (i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}