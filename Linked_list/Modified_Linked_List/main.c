#include <stdio.h>
#include "mod_linked_list.h"
#include <string.h>

int op;

int main() {
    List *li;
    li = createList();
    struct student st1, st2, st3;

    st1.registration_number = 100;
    strcpy(st1.name, "Luis");
    st1.first_exam = 9.3;
    st1.sec_exam = 8.1;
    st1.third_exam = 7.0;

    st2.registration_number = 200;
    strcpy(st2.name, "Henrique");
    st2.first_exam = 5.4;
    st2.sec_exam = 10;
    st2.third_exam = 10;

    st3.registration_number = 300;
    strcpy(st3.name, "Matheus");
    st3.first_exam = 7.5;
    st3.sec_exam = 7.9;
    st3.third_exam = 8.0;

    insertHead(li, st1);
    insertHead(li, st2);
    insertTail(li, st3);

    getStudentsInfo(li);

    removeHead(li);
    removeTail(li);

    getStudentsInfo(li);

    freeList(li);
    return 0;
}