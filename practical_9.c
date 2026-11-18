#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *START = NULL;

struct Node* createNode(int item) {
    struct Node *NEW = (struct Node*)malloc(sizeof(struct Node));
    if (NEW == NULL) {
        printf("OVERFLOW\n");
        return NULL;
    }
    NEW->data = item;
    NEW->next = NEW;
    NEW->prev = NEW;
    return NEW;
}

void insertEnd(int item) {
    struct Node *NEW = createNode(item);
    if (NEW == NULL) return;
    if (START == NULL) {
        START = NEW;
        return;
    }
    struct Node *LAST = START->prev;
    NEW->next = START;
    NEW->prev = LAST;
    LAST->next = NEW;
    START->prev = NEW;
}

void display() {
    if (START == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *TEMP = START;
    printf("List: ");
    do {
        printf("%d <-> ", TEMP->data);
        TEMP = TEMP->next;
    } while (TEMP != START);
    printf("(START)\n");
}

int main() {
    insertEnd(12);
    insertEnd(56);
    insertEnd(45);
    display();
    return 0;
}
