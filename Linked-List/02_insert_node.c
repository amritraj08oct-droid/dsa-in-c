#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

int main(void) {
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *newNode = malloc(sizeof(Node));
    if (!head || !second || !newNode) return 1;

    head->data = 10; head->next = second;
    second->data = 30; second->next = NULL;
    newNode->data = 20; newNode->next = second;
    head->next = newNode;

    for (Node *p = head; p; p = p->next) printf("%d ", p->data);
    printf("\n");
    free(second); free(newNode); free(head);
    return 0;
}
