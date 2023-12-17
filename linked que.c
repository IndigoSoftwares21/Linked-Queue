#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    char data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* new_node(char data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* create_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, char data) {
    struct Node* new_node_ptr = new_node(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node_ptr;
        return;
    }

    queue->rear->next = new_node_ptr;
    queue->rear = new_node_ptr;
}

// Function to dequeue an element from the queue
char dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return '\0'; // Return null character if queue is empty
    }

    // Remove the front node from the queue and update the front pointer
    char data = queue->front->data;
    struct Node* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to check if the queue is empty
int is_empty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to display the queue
void display_queue(struct Queue* queue) {
    struct Node* temp = queue->front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    // Traverse the queue and print its elements
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function for example usage
int main() {
    struct Queue* queue = create_queue();

    enqueue(queue, 'A');
    enqueue(queue, 'B');
    enqueue(queue, 'C');

    display_queue(queue);

    printf("Dequeued element: %c\n", dequeue(queue));
    printf("Dequeued element: %c\n", dequeue(queue));

    display_queue(queue);

    enqueue(queue, 'D');
    enqueue(queue, 'E');

    display_queue(queue);

    return 0;
}
