#include <stdio.h>
#include <stdlib.h>
#include "mod_linked_list.h"

struct element {
    struct student data;
    struct element  *next;
};

typedef struct element Elem;

struct descriptor {
    struct element *head;
    struct element *tail;
    int len;
};

List* createList() {
    List* li = (List*) malloc(sizeof(List));
    if (li != NULL) {
        li->head = NULL;
        li->tail = NULL;
        li->len = 0;
    }
    return li;
}

void freeList(List* li) {
    if (li != NULL) {
        Elem* node;
        while ((li->head) != NULL) {
            node = li->head;
            li->head = li->head->next;
            free(node);
        }
        free(li);
    }
}

int lenList(List *li) {
    if (li == NULL) return 0;
    return li->len;
}

int insertHead(List *li, struct student st) {
    if (li == NULL) return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = st;
    node->next = li->head;
    if (li->head == NULL) li->tail = node;
    li->head = node;
    li->len++;
    return 1;
}

int insertTail(List *li, struct student st) {
    if (li == NULL) return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = st;
    node->next = NULL;
    if (li->head == NULL) 
        li->head = node;
    else 
        li->tail->next = node;
    li->tail = node;
    li->len++;
    return 1;
}

int removeHead(List *li) {
    if (li == NULL) return 0;
    if (li->head == NULL) return 0;
    Elem *node = li->head;
    li->head = node->next;
    free(node);
    if (li->head == NULL)
        li->tail = NULL;
    li->len--;
    return 1;
}

int removeTail(List *li) {
    if (li == NULL) return 0;
    if (li->head == NULL) return 0;
    Elem *node = li->head, *previous;
    while (node->next != NULL) {
        previous = node;
        node = node->next;
    }
    if (node == li->head) {
        li->head = li->tail = NULL;
    } else {
        previous->next = node->next;
        li->tail = previous;
    }
    free(node);
    li->len--;
    return 1;
}

void getStudentsInfo(List *li) {
    float mean;
    Elem *node = li->head;
    while (node != NULL) {
        printf("--------------------------------------\n");
        printf("Name: %s\n", node->data.name);
        printf("Registration number: %d\n", node->data.registration_number);
        printf("First exam %.2f\n", node->data.first_exam);
        printf("First exam %.2f\n", node->data.sec_exam);
        printf("First exam %.2f\n", node->data.third_exam);
        mean = (node->data.first_exam + node->data.sec_exam + node->data.third_exam) / 3;
        printf("Mean: %.2f\n", mean);
        node = node->next;
    }
    free(node);
}