#include <stdio.h>
#include "seq_list.h"

int main() {
    SEQ_LIST l;
    initialization(&l);
    insertElement(&l, 21, 0);
    insertElement(&l, 9, 1);
    insertElement(&l, 55, 2);

    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    insertElement(&l, 12, 1);

    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    append(&l, 15);
    append(&l, 26);
    append(&l, 700);
    append(&l, 1);

    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    delete(&l, 15);
    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    delete(&l, 700);
    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    delete(&l, 77);
    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    insertElement(&l, 77, 0);
    displayList(&l);
    printf("Tamanho da lista: %d\n", size(&l));

    restartList(&l);

    return 0;
}
