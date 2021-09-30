#include <stdio.h>
#include "priority_queue.h"

int main(void) {
    PriorityQueue *queue;

    queue = createQueue();
    printf("Is the queue empty? %s\n", (isEmpty(queue) ? "Yes" : "No"));
    printf("%s\n", query(queue));

    insert(queue, "Luis", 10);
    insert(queue, "Henrique", 2);
    insert(queue, "Duarte", 500);
    insert(queue, "João", 1);

    printf("%s\n", query(queue));

    printf("Queue size %d\n", queueSize(queue));
    showQueue(queue);

    removeElem(queue);
    removeElem(queue);

    printf("%s\n", query(queue));

    printf("Queue size %d\n", queueSize(queue));
    showQueue(queue);

    freeQueue(queue);
    return 0;
}