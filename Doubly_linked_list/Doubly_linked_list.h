//
// Created by luis on 23/08/2021.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct reg {
    char* productName;
    struct reg* previous;
    struct reg* next;
} Node;

typedef Node* dl_list;

void begginList(dl_list*);
int emptyList(dl_list);
int size(dl_list list);
int indexElement(dl_list , char* );
char* getElementByIndex(dl_list, int );
int appendElement(dl_list*, char* );
int insertElement(dl_list*, int, char* );
int deleteElement(dl_list*, char* );
void displayList(dl_list list);

#endif
