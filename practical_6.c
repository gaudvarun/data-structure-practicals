#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *START = NULL;

void insertBeginning(int value) {
    struct node *NEW = malloc(sizeof(struct node));
    if (NEW == NULL) {
        printf("Memory is full\n");
        return;
    }
    NEW->data = value;
    NEW->next = START;
    START = NEW;
}

void insertEnd(int value) {
    struct node *NEW = malloc(sizeof(struct node));
    struct node *PTR;
    if (NEW == NULL) {
        printf("Memory is full\n");
        return;
    }
    NEW->data = value;
    NEW->next = NULL;
    if (START == NULL) {
        START = NEW;
        return;
    }
    PTR = START;
    while (PTR->next != NULL) {
        PTR = PTR->next;
    }
    PTR->next = NEW;
}

void insertPosition(int value, int pos) {
    struct node *NEW;
    struct node *PTR;
    int i;
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    PTR = START;
    for (i = 1; i < pos - 1 && PTR != NULL; i++) {
        PTR = PTR->next;
    }
    if (PTR == NULL) {
        printf("Invalid position.\n");
        return;
    }
    NEW = malloc(sizeof(struct node));
    if (NEW == NULL) {
        printf("Memory is full\n");
        return;
    }
    NEW->data = value;
    NEW->next = PTR->next;
    PTR->next = NEW;
}

void deleteBeginning(void) {
    struct node *PTR;
    if (START == NULL) {
        printf("List is empty.\n");
        return;
    }
    PTR = START;
    START = START->next;
    printf("Deleted number: %d\n", PTR->data);
    free(PTR);
}

void deleteEnd(void) {
    struct node *PTR, *SAVE;
    if (START == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (START->next == NULL) {
        printf("Deleted number: %d\n", START->data);
        free(START);
        START = NULL;
        return;
    }
    PTR = START;
    while (PTR->next->next != NULL) {
        PTR = PTR->next;
    }
    SAVE = PTR->next;
    PTR->next = NULL;
    printf("Deleted number: %d\n", SAVE->data);
    free(SAVE);
}

void deletePosition(int pos) {
    struct node *PTR, *SAVE;
    int i;
    if (START == NULL || pos < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    PTR = START;
    for (i = 1; i < pos - 1 && PTR != NULL; i++) {
        PTR = PTR->next;
    }
    if (PTR == NULL || PTR->next == NULL) {
        printf("Invalid position.\n");
        return;
    }
    SAVE = PTR->next;
    PTR->next = SAVE->next;
    printf("Deleted number: %d\n", SAVE->data);
    free(SAVE);
}

void display(void) {
    struct node *PTR = START;
    if (START == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (PTR != NULL) {
        printf("%d -> ", PTR->data);
        PTR = PTR->next;
    }
    printf("NULL\n");
}

int main(void) {
    insertBeginning(1);
    insertEnd(2);
    display();
    deleteEnd();
    display();
    return 0;
}
