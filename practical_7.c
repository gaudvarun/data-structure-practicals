#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *next;
};

struct node *insert(struct node *head, int c, int e) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->expo = e;
    newnode->next = NULL;
    if (head == NULL) return newnode;
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
    return head;
}

struct node *Add(struct node *p1, struct node *p2) {
    struct node *result = NULL, *temp;
    while (p1 != NULL) {
        temp = p2;
        while (temp != NULL && temp->expo != p1->expo)
            temp = temp->next;
        if (temp != NULL) {
            result = insert(result, p1->coeff + temp->coeff, p1->expo);
            temp->coeff = 0;
        } else {
            result = insert(result, p1->coeff, p1->expo);
        }
        p1 = p1->next;
    }
    while (p2 != NULL) {
        if (p2->coeff != 0)
            result = insert(result, p2->coeff, p2->expo);
        p2 = p2->next;
    }
    return result;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->coeff != 0)
            printf("%dx^%d ", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL) printf("+ ");
    }
    printf("\n");
}

int main() {
    struct node *p1 = NULL, *p2 = NULL, *result = NULL;
    p1 = insert(p1, 5, 3);
    p1 = insert(p1, 4, 2);
    p1 = insert(p1, 2, 1);
    p1 = insert(p1, 7, 0);

    p2 = insert(p2, 3, 3);
    p2 = insert(p2, 2, 2);
    p2 = insert(p2, 6, 0);

    printf("First polynomial: ");
    display(p1);
    printf("Second polynomial: ");
    display(p2);

    result = Add(p1, p2);
    printf("Addition: ");
    display(result);

    return 0;
}
