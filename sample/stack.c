#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define TRUE 1
#define FALSE 0

typedef struct node
{
    ElementType data;
    struct node *next;
} LinkStackNode;
typedef LinkStackNode *LinkStack;

void initStack(LinkStack *s) 
{
    *s = (LinkStack)malloc(sizeof(LinkStackNode));
    (*s)->next = NULL;
}

void destroyStack(LinkStackNode *s)
{
    LinkStackNode *p = s, *q = s->next;
    while(q != NULL) {
        free(p);
        p = q;
        q = p ->next;
    }
    free(p);
}

int isEmpty(LinkStackNode *s) 
{
    return (s->next == NULL);
}

int push(ElementType e, LinkStack s)
{
    LinkStackNode *p;
    p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if(p == NULL)
        return FALSE;
    p->data = e;
    p->next = s->next;
    s->next = p;
    return TRUE;
}

int pop(ElementType *e, LinkStack s)
{
    LinkStackNode *p;
    p = s->next;
    if(p == NULL)
        return FALSE;
    *e = p->data;
    s->next = p->next;
    free(p);
    return TRUE;
}

int getTop(ElementType *e, LinkStack s) 
{
    LinkStackNode *p;
    p = s->next;
    if(p == NULL)
        return FALSE;
    *e = p->data;
    return TRUE;
}

void test1()
{
    LinkStack *s;
    ElementType e;
    initStack(&s);
    push(1, s);
    push(2, s);
    getTop(&e, s);
    printf("%d ", e);
    pop(&e, s);
    printf("%d ", e);
    pop(&e, s);
    printf("%d ", e);
}

int main(void)
{
    test1();
    system("pause");
    return 0;
}