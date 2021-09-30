struct student {
    int registration_number;
    char name[30];
    float first_exam, sec_exam, third_exam;
};

typedef struct descriptor List;

List* createList();
void freeList(List *li);
int lenList(List *li);
int insertHead(List *li, struct student st);
int insertTail(List *li, struct student st);
int removeHead(List *li);
int removeTail(List *li);
void getStudentsInfo(List *li);