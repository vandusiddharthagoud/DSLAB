#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next;
};

// Define the structure for a queue
struct queue {
    struct node *front, *rear;
};

// Function to initialize the queue
void create_queue(struct queue *q) {
    q->front = q->rear = NULL;
}

// Function to insert an element into the queue
void insert(struct queue *q, int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (!ptr) {
        printf("\nMemory allocation failed");
        return;
    }

    ptr->data = val;
    ptr->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }
}

// Function to delete an element from the queue
void delete_element(struct queue *q) {
    if (q->front == NULL) {
        printf("\nUNDERFLOW");
        return;
    }

    struct node *temp = q->front;
    printf("\nDELETED: %d", temp->data);

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Function to peek at the front element
int peek(struct queue *q) {
    return (q->front) ? q->front->data : -1;
}

// Function to display the queue
void display(struct queue *q) {
    if (q->front == NULL) {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    struct node *temp = q->front;
    printf("\nQUEUE: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function to drive the program
int main() {
    struct queue q;
    int val, option;

    create_queue(&q);

    do {
        printf("\n\n1. INSERT\n2. DELETE\n3. PEEK\n4. DISPLAY\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&q, val);
                break;
            case 2:
                delete_element(&q);
                break;
            case 3:
                val = peek(&q);
                if (val != -1)
                    printf("\nFRONT: %d", val);
                else
                    printf("\nQUEUE IS EMPTY");
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid option!");
        }
    } while (option != 5);

    return 0;
}

