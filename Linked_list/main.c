#include <stdio.h>
#include "linked_list.h"

int main() {
    linked_list list;
    begginList(&list);
    printf("Is the list empty? %s\n", emptyList(list)? "Yes" : "No");
    appendElement(&list, 6);
    appendElement(&list, 3);
    appendElement(&list, 2002);

    printf("Is the list empty? %s\n", emptyList(list)? "Yes" : "No");
    printf("Linked List size: %d\n", size(list));
    displayList(list);

    printf("Number 6 position: %d\n", getIdxByElement(list, 6));
    printf("Number 2002 position: %d\n", getIdxByElement(list, 2002));

    printf("Element at 1-position: %d\n", getElementByIdx(list, 1));

    insertElement(&list, 1, 19);
    insertElement(&list, 3, 42);
    insertElement(&list, 5, 33);
    displayList(list);
    printf("Linked List size: %d\n", size(list));

    deleteElement(&list, 19);
    displayList(list);
    printf("Linked List size: %d\n", size(list));

    deleteElement(&list, 33);
    displayList(list);
    printf("Linked List size: %d\n", size(list));

    deleteElement(&list, 3);
    displayList(list);
    printf("Linked List size: %d\n", size(list));
    return 0;
}
