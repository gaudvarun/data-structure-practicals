#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1;
int rear = -1;

void addPassenger(int token) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = token;
    printf("Passenger %d added successfully.\n", token);
}

void servePassenger() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int token = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Passenger %d has been served.\n", token);
}

void showQueue() {
    if (front == -1) {
        printf("No passengers in the queue.\n");
        return;
    }
    printf("Passengers waiting: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        if (i == MAX - 1) i = 0;
        else i++;
    }
    printf("\n");
}

int main() {
    addPassenger(1);
    addPassenger(2);
    showQueue();
    servePassenger();
    showQueue();
    return 0;
}
