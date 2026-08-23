#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

int main(void) {
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));
    if (!head || !second || !third) return 1;

    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = NULL;

    Node *toDelete = second;
    head->next = third;
    free(toDelete);

    for (Node *p = head; p; p = p->next) printf("%d ", p->data);
    printf("\n");
    free(third); free(head);
    return 0;
}
