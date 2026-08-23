#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int value) { if (rear < MAX - 1) queue[++rear] = value; }
int dequeue(void) { return front <= rear ? queue[front++] : -1; }

int main(void) {
    enqueue(10); enqueue(20); enqueue(30);
    printf("Dequeued: %d\n", dequeue());
    printf("Front: %d\n", queue[front]);
    return 0;
}
