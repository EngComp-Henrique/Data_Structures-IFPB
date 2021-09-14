#include <stdio.h>
#include "Doubly_linked_list.h"

int main() {
    dl_list products = NULL;
    begginList(&products);

    printf("Is the list empty? %s\n", emptyList(products)? "Yes": "No");
    appendElement(&products, "Apple");
    appendElement(&products, "Banana");
    appendElement(&products, "Orange");
    appendElement(&products, "Rice");
    printf("Is the list empty? %s\n", emptyList(products)? "Yes": "No");
    printf("List size: %d\n", size(products));
    printf("The first three products are: ");
    for (int i = 0; i < 3; i++) {
        printf("%s ", getElementByIndex(products, i));
    }
    printf("\n");
    printf("Banana index: %d\n", indexElement(products, "Banana"));

    insertElement(&products, 1, "Watermelon");
    insertElement(&products, 3, "Beans");
    insertElement(&products, 6, "Avocado");
    printf("List size: %d\n", size(products));
    displayList(products);
    deleteElement(&products, "Apple");
    displayList(products);
    return 0;
}
