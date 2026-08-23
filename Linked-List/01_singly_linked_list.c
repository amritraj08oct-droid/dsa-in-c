#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void) {
    Node *head = NULL, *second = NULL, *third = NULL;
    head = malloc(sizeof(Node)); second = malloc(sizeof(Node)); third = malloc(sizeof(Node));
    if (!head || !second || !third) return 1;

    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = NULL;

    for (Node *p = head; p != NULL; p = p->next) printf("%d ", p->data);
    printf("\n");

    free(third); free(second); free(head);
    return 0;
}
