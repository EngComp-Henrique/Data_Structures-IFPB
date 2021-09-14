//
// Created by luis on 20/08/2021.
//

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void startStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack stack) {return stack.top == NULL;}

int push(Stack* stack, char* data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return 0;
    newNode->bookName = data;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

int pop(Stack* stack) {
    if (isEmpty(*stack)) return 0;
    Node *aux = stack->top;
    stack->top = stack->top->next;
    free(aux);
    return 1;
}

char* peek(Stack stack) {
    return stack.top->bookName;
}

void displayStack(Stack stack) {
    printf("Bookcase: ");
    while (stack.top != NULL) {
        if (stack.top->next != NULL)
            printf("%s, ", stack.top->bookName);
        else
            printf("%s\n", stack.top->bookName);
        stack.top = stack.top->next;
    }

}