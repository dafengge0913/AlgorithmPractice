#include <stdio.h>
#define N 5

typedef struct
{
    int data[N];
    int head;
    int tail;
    int size;
} RingQueue;

void init(RingQueue *q)
{
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

void enqueue(RingQueue *q, int i)
{
    if (q->size == N && q->tail == q->head)
    {
        // 队列已满
        q->head = (q->head + 1) % N;
    }
    q->data[q->tail] = i;
    q->tail = (q->tail + 1) % N;
    if (q->size < N)
    {
        q->size += 1;
    }
}

void dequeue(RingQueue *q)
{
    if (q->size == 0)
        return;

    q->head = (q->head + 1) % N;
    q->size -= 1;
}

void printAll(RingQueue q)
{
    int i;
    for (i = 0; i < q.size; i++)
    {
        printf("%d ", q.data[(q.head + i) % N]);
    }
    printf("\n");
}

void main()
{
    int i;
    RingQueue q;
    init(&q);
    enqueue(&q, 1);
    printAll(q);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printAll(q);
    enqueue(&q, 5);
    printAll(q);
    enqueue(&q, 6);
    printAll(q);
    for (i = 0; i < 10; i++)
    {
        dequeue(&q);
    }
    printAll(q);
    for (i = 10; i < 20; i++)
    {
        enqueue(&q, i);
    }
    printAll(q);
}