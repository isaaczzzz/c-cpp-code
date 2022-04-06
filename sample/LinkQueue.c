#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define TRUE 1
#define FALSE 0

typedef struct Node
{
    ElementType data;
    struct Node *next;
} LinkQueueNode;
typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

int initQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front != NULL)
    {
        Q->front = NULL;
        Q->rear = Q->front;
        return TRUE;
    }
    else
        return FALSE;
}

void clearQueue(LinkQueue *Q)
{
    LinkQueueNode *p = Q->front->next, *r;
    if (p != NULL)
    {
        r = p->next;
        while (r != NULL)
        {
            free(p);
            p = r;
            r = p->next;
        }
    }
    free(p);
    Q->rear = Q->front;
}

int isEmpty(LinkQueue *Q)
{
    return (Q->rear == Q->front);
}

int enter(LinkQueue *Q, ElementType e)
{
    LinkQueueNode *p;
    p = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (p != NULL)
    {
        p->data = e;
        p->next = NULL;
        Q->rear->next = p;
        Q->rear = p;
        return TRUE;
    }
    else
        return FALSE;
}

int delete(LinkQueue *Q, ElementType *x)
{ 
    LinkQueueNode *p;
    if (Q->front == Q->rear)
        return FALSE;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)         // 如果队中只有一个元素p，则p出队后成为空队 
        Q->rear = Q->front;
    *x = p->data;
    free(p);
    return FALSE;
}

void test1()
{
    LinkQueue Q;
    ElementType e;
    initQueue(&Q);
    
    enter(&Q, 10);
    enter(&Q, 20);
    printf("%d", isEmpty(&Q));

    delete(&Q, &e);
    printf("%d ", e);
    delete(&Q, &e);
    printf("%d ", e);

    printf("%d", isEmpty(&Q));
}

int main(void)
{
    test1();
    system("pause");
    return 0;
}