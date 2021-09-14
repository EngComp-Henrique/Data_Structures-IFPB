//
// Created by luis on 19/08/2021.
//

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void begginList(linked_list *lk) {*lk = NULL;}

int emptyList(linked_list lk) {return lk == NULL;}

int size(linked_list lk) {
    int lenght = 0;
    while (lk != NULL) {
        lk = lk->next;
        lenght++;
    }
    return lenght;
}

int getIdxByElement(linked_list lk, int element) {
    if (emptyList(lk)) return -1;
    int i = 0;
    while (lk != NULL) {
        if (lk->data == element) return i + 1;
        lk = lk->next;
        i++;
    }
    return -1;
}

int getElementByIdx(linked_list lk, int idx) {
    if (emptyList(lk)) return -1;
    if (idx > size(lk) || emptyList(lk) || idx < 0)
        return -1;
    for (int i = 0; i < idx; i++) {
        lk = lk->next;
    }
    return lk->data;
}

void appendElement(linked_list *lk, int data) {
    linked_list newNode = NULL, aux;
    int i = 0;
    if (emptyList(*lk)) {
        newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) return;
        newNode->data = data;
        newNode->next = NULL;
        *lk = newNode;
        return;
    }
    aux = *lk;
    while (aux->next != NULL)
        aux = aux->next;
    newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    aux->next = newNode;
    newNode->next = NULL;
}

void insertElement(linked_list *lk, int idx, int data) {
    linked_list newNode = NULL, aux = NULL;
    int i = 0;
    if (emptyList(*lk)) {
        if (idx != 1) return;
        newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) return;
        newNode->data = data;
        newNode->next = NULL;
        *lk = newNode;
        return;
    }
    if (idx == 1) {
        newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) return;
        newNode->data = data;
        newNode->next = *lk;
        *lk = newNode;
        return;
    }
    aux = *lk;
    while ((i < idx - 1) && (aux != NULL)) {
        aux = aux->next;
        i++;
    }
    if (aux == NULL) return;
    newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = aux->next;
    aux->next = newNode;
}

void deleteElement(linked_list *lk, int element) {
    if (emptyList(*lk)) return;
    linked_list aux = NULL, previous = NULL;
    aux = *lk;
    while (aux != NULL) {
        if (aux->data == element) break;
        previous = aux;
        aux = aux->next;
    }
    if (aux == NULL) return;
    if (getIdxByElement(*lk, element) == 1) *lk = aux->next;
    else previous->next = aux->next;
    free(aux);
}

void displayList(linked_list lk) {
    printf("Linked list: [ ");
    while (lk != NULL) {
        if (lk->next != NULL)
            printf("%d -> ", lk->data);
        else
            printf("%d -> NULL", lk->data);
        lk = lk->next;
    }
    printf("]\n");
}
