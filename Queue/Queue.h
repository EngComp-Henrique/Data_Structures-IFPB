//
// Created by luis on 20/08/2021.
//

#ifndef QUEUE_H
#define QUEUE_H

typedef struct reg {
    char* firstName;
    struct reg* next;
} Node;

typedef struct head {
    Node* front;
    Node* rear;
} Queue;

void startQueue(Queue* queue);
int emptyQueue(Queue queue);
int enqueue(Queue* queue, char person[]);
int dequeue(Queue* queue);
char* peek(Queue queue);
void displayQueue(Queue queue);

#endif
