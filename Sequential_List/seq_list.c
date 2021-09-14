//
// Created by luis on 16/08/2021.
//

#include "seq_list.h"
#include <stdio.h>

void initialization(SEQ_LIST* l) {
    l->numElements = 0;
}

int size(SEQ_LIST* l) {
    return l->numElements;
}

int searchElement(SEQ_LIST* l, int k) {
    int i;
    for (i = 0; i < l->numElements; i++) {
        if (l->A[i] == k) return i;
    }
    return -1;
}

int insertElement(SEQ_LIST* l, int element, int i) {
    if (i < 0 || i > l->numElements || l->numElements == MAX) return 0;
    int j;
    for (j = l->numElements; j > i; j--) { l->A[j] = l->A[j - 1]; }
    l->A[i] = element;
    l->numElements++;
    return 1;
}

int append(SEQ_LIST* l, int element) {
    if (l->numElements == MAX) return 0;
    l->A[l->numElements] = element;
    l->numElements++;
    return 1;
}

int delete(SEQ_LIST* l, int element) {
    int i, pos = searchElement(l, element);
    if (pos == -1) return 0;
    for (i = pos; i < l->numElements; i++)
        l->A[i] = l->A[i + 1];
    l->numElements--;
    return 1;
}

void displayList(SEQ_LIST* l) {
    int i;
    printf("Lista: [ ");
    for (i = 0; i < l->numElements; i++) {
        printf("%d ", l->A[i]);
    }
    printf("]\n");
}

void restartList(SEQ_LIST* l) {
    l->numElements = 0;
}