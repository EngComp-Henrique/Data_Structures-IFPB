#define MAX 100
typedef struct priority_queue PriorityQueue;

PriorityQueue* createQueue();
void freeQueue(PriorityQueue *pq);
char* query(PriorityQueue *pq);
int insert(PriorityQueue *pq, char *name, int priority);
int removeElem(PriorityQueue *pq);
int queueSize(PriorityQueue *pq);
int isFull(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
void showQueue(PriorityQueue *pq);