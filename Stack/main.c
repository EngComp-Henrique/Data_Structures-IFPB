#include <stdio.h>
#include "Stack.h"

int main() {
    Stack myBooks;
    startStack(&myBooks);
    printf("Is my bookcase empty? %s\n", isEmpty(myBooks)? "Yes": "No");

    push(&myBooks, "Alice in Wonderland");
    push(&myBooks, "Introduction to Algorithms");
    push(&myBooks, "C prime");

    printf("Is my bookcase empty? %s\n", isEmpty(myBooks)? "Yes": "No");

    char *firstBook = peek(myBooks);
    printf("Book on the top: %s\n", firstBook);

    displayStack(myBooks);
    pop(&myBooks);
    displayStack(myBooks);
    return 0;
}
