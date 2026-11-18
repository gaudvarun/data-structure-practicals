#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL) {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    } else {
        struct node *temp = head->prev;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
    }
}

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    printf("CDLL List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("(HEAD)\n");
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    display();
    return 0;
}
