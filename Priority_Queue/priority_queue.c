#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"

struct patient {
    char name[30];
    int prio;
};

struct priority_queue {
    int len;
    struct patient data[MAX];
};

PriorityQueue* createQueue() {
    PriorityQueue *pq;
    pq = (PriorityQueue*) malloc(sizeof(struct priority_queue));
    if (pq != NULL)
        pq->len = 0;
    return pq;
}

int isFull(PriorityQueue *pq) {
    if (pq == NULL) return -1;
    return (pq->len == MAX);
}

int isEmpty(PriorityQueue *pq) {
    if (pq == NULL) return -1;
    return (pq->len == 0);
}

void freeQueue(PriorityQueue *pq) {
    free(pq);
}

int queueSize(PriorityQueue *pq) {
    if (pq == NULL) return -1;
    else return pq->len;
}

int insert(PriorityQueue *pq, char *name, int priority) {
    if (pq == NULL) return 0;
    if (pq->len == MAX) return 0;
    int i = pq->len - 1;
    while (i >= 0 && pq->data[i].prio >= priority) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }
    strcpy(pq->data[i + 1].name, name);
    pq->data[i + 1].prio = priority;
    pq->len++;
    return 1;
}

int removeElem(PriorityQueue *pq) {
    if ((pq == NULL) || (pq->len == 0)) return 0;
    pq->len--;
    return 1;
}

char* query(PriorityQueue *pq) {
    if ((pq == NULL) || (pq->len == 0)) return "Is empty";
    char* new_data = pq->data[pq->len - 1].name;
    return new_data;
}

void showQueue(PriorityQueue *pq) {
    int i = pq->len;
    for (int j = 0; j < i; j++) {
        printf("%s ", pq->data[j].name);
    }
    printf("\n");
}