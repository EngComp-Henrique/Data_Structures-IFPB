//
// Created by luis on 16/08/2021.
//

#define MAX 10

typedef struct {
    int A[MAX];
    int numElements;
} SEQ_LIST;

void initialization(SEQ_LIST* l);
int size(SEQ_LIST* l);
void displayList(SEQ_LIST* l);
int searchElement(SEQ_LIST* l, int element);
int insertElement(SEQ_LIST* l, int element, int i);
int append(SEQ_LIST* l, int element);
int delete(SEQ_LIST* l, int element);
void restartList(SEQ_LIST* l);
