//
// Created by luis on 19/08/2021.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct reg {
    int data;
    struct reg* next;
} Node;

typedef Node* linked_list;

void begginList(linked_list *lk);
int emptyList(linked_list lk);
int size(linked_list lk);
int getIdxByElement(linked_list lk, int element);
int getElementByIdx(linked_list lk, int idx);
void appendElement(linked_list *lk, int data);
void insertElement(linked_list *lk, int idx, int data);
void displayList(linked_list lk);
void deleteElement(linked_list *lk, int element);

#endif
