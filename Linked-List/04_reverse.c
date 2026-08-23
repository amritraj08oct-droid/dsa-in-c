#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

Node *reverse(Node *head) {
    Node *prev = NULL, *current = head;
    while (current) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(void) {
    Node a = {10, NULL}, b = {20, NULL}, c = {30, NULL};
    a.next = &b; b.next = &c;
    Node *head = reverse(&a);
    for (Node *p = head; p; p = p->next) printf("%d ", p->data);
    printf("\n");
    return 0;
}
