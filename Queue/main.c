#include <stdio.h>
#include "Queue.h"

int main() {
    Queue queue;
    startQueue(&queue);

    printf("Is queue empty? %s\n", emptyQueue(queue)? "Yes": "No");

    enqueue(&queue, "Luis");
    enqueue(&queue, "Henrique");
    enqueue(&queue, "Lima");
    enqueue(&queue, "Santos");

    printf("Is queue empty? %s\n", emptyQueue(queue)? "Yes": "No");

    char *firstPerson = peek(queue);
    printf("First person: %s\n", firstPerson);

    displayQueue(queue);

    dequeue(&queue);
    displayQueue(queue);

    return 0;
}
