//
// Created by luis on 20/08/2021.
//

#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void startQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int emptyQueue(Queue queue) {return (queue.front == NULL) && (queue.rear == NULL);}

int enqueue(Queue* queue, char* person) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return 0;
    newNode->firstName = person;
    newNode->next = NULL;
    if (emptyQueue(*queue))
        queue->front = newNode;
    else
        (queue->rear)->next = newNode;
    queue->rear = newNode;
    return 1;
}

int dequeue(Queue* queue) {
    if (emptyQueue(*queue)) return 0;
    if (queue->front == queue->rear) queue->rear = NULL;
    Node *aux = queue->front;
    queue->front = queue->front->next;
    free(aux);
    return 1;
}

char* peek(Queue queue) {
    if (emptyQueue(queue)) return "";
    return (queue.front)->firstName;
}

void displayQueue(Queue queue) {
    while (queue.front != NULL) {
        printf("%s\n", queue.front->firstName);
        queue.front = queue.front->next;
    }
    printf("\n");
}