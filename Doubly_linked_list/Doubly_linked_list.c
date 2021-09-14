//
// Created by luis on 23/08/2021.
//

#include "Doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void begginList(dl_list* list) {
    *list = NULL;
}

int emptyList(dl_list list) {
    return list == NULL;
}

int size(dl_list list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

int appendElement(dl_list* list, char* data) {
    dl_list newNode = NULL, aux;
    newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return 0;
    newNode->productName = data;
    if (emptyList(*list)) {
        newNode->next = newNode->previous = NULL;
        *list = newNode;
    } else {
        aux = *list;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = newNode;
        newNode->previous = aux;
        newNode->next = NULL;
    }
    return 1;
}

int insertElement(dl_list* list, int idx, char* data) {
    dl_list newNode = NULL, aux = NULL;
    int i = 0;
    newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return 0;
    newNode->productName = data;
    if (emptyList(*list)) {
        if (idx != 1) return 0;
        newNode->next = newNode->previous = NULL;
        *list = newNode;
    } else if (idx == 1) {
        newNode->previous = (*list)->previous;
        newNode->next = *list;
        (*list)->previous = newNode;
        *list = newNode;
    } else {
        aux = *list;
        while ((i < idx - 1) && (aux != NULL)) {
            aux = aux->next;
            i++;
        }
        if (aux == NULL) return 0;
        newNode->next = aux->next;
        newNode->previous = aux;
        if (aux->next != NULL) aux->next->previous = newNode;
        aux->next = newNode;
    }
    return 1;
}

int deleteElement(dl_list* list, char* data) {
    dl_list aux = NULL, previousNode = NULL;
    if (emptyList(*list)) return 0;
    aux = *list;
    while (aux != NULL) {
        if (strcmp(aux->productName, data) == 0) break;
        previousNode = aux;
        aux = aux->next;
    }
    if (aux == NULL) return 0;
    previousNode->next = aux->next;
    aux->next->previous = previousNode;
    free(aux);
    return 1;
}

int indexElement(dl_list list, char* data) {
    int idx = -1;
    while (list != NULL) {
        list = list->next;
        idx++;
    }
    return ++idx;
}

char* getElementByIndex(dl_list list, int idx) {
    if (idx > size(list) || idx < 0 || emptyList(list)) return "";
    for (int i = 0; i < idx; i++)
        list = list->next;
    return list->productName;
}

void displayList(dl_list list) {
    printf("List: ");
    while (list != NULL) {
        if (list->next != NULL)
            printf("%s, ", list->productName);
        else
            printf("%s\n", list->productName);
        list = list->next;
    }
}