#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    Node *root = malloc(sizeof(Node));
    Node *left = malloc(sizeof(Node));
    Node *right = malloc(sizeof(Node));
    if (!root || !left || !right) return 1;

    root->data = 1; root->left = left; root->right = right;
    left->data = 2; left->left = left->right = NULL;
    right->data = 3; right->left = right->right = NULL;

    inorder(root);
    printf("\n");
    free(left); free(right); free(root);
    return 0;
}
