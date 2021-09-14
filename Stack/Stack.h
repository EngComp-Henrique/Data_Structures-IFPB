//
// Created by luis on 20/08/2021.
//

#ifndef STACK_H
#define STACK_H

typedef struct reg {
    char* bookName;
    struct reg* next;
} Node;

typedef struct head {
    Node* top;
}Stack;

void startStack(Stack* stack);
int isEmpty(Stack stack);
int push(Stack* stack, char* data);
int pop(Stack* stack);
char* peek(Stack stack);
void displayStack(Stack stack);


#endif
