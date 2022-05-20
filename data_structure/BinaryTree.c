#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define StackElemType BiTNode
#define TRUE 1
#define FALSE 0

typedef struct Node
{
    ElemType data;
    struct Node *left;
    struct Node *right;
}BiTNode, *BiTree;
ElemType a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

typedef struct node
{
    StackElemType data;
    struct node *next;
} StackNode;
typedef StackNode* Stack;

void creatTree(BiTree *T);
void insertTree(BiTree *T, ElemType e);
void preOrder(BiTree T);
//Stack
void initStack(Stack *s);
void destroyStack(Stack s);
int isEmpty(Stack s);
int push(StackElemType e, Stack s);
int pop(StackElemType *e, Stack s);
int getTop(StackElemType *e, Stack s);


int main(void) 
{
    BiTree T;
    creatTree(&T);
    preOrder(T);
    system("pause");
}

void creatTree(BiTree *T)
{
    *T = NULL;
    for(int i = 0; a[i] >= 0; i++) {
        insertTree(T, a[i]);
    }
}

//结点插入(二叉排序树形式)
void insertTree(BiTree *T, ElemType e)
{
    if((*T) == NULL) {
        BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
        p->data = e;
        p->left = p->right = NULL;
        *T = p;
    } else {
        if(e < (*T)->data)
            insertTree(&(*T)->left, e);
        else
            insertTree(&(*T)->right, e);
    }
}

//先序遍历
void preOrder(BiTree T){
    if(T == NULL)
        return;
    Stack S;
    initStack(&S);
    push(*T, S);
    
    while(!isEmpty(S)) {
        BiTNode *p;
        pop(&(*p), S);
        printf("%d\n", p->data);
        if(p->right != NULL) 
            push(*(p->right), S);
        if(p->left != NULL)//中左右，左先出，后入栈
            push(*(p->left), S);
    }
}

void initStack(Stack *s) 
{
    *s = (Stack)malloc(sizeof(StackNode));
    (*s)->next = NULL;
}

void destroyStack(Stack s)
{
    StackNode *p = s, *q = s->next;
    while(q != NULL) {
        free(p);
        p = q;
        q = p ->next;
    }
    free(p);
}

int isEmpty(Stack s) 
{
    return (s->next == NULL);
}

int push(StackElemType e, Stack s)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    if(p == NULL)
        return FALSE;
    p->data = e;
    p->next = s->next;
    s->next = p;
    return TRUE;
}

int pop(StackElemType *e, Stack s)
{
    StackNode *p;
    p = s->next;
    if(p == NULL)
        return FALSE;
    *e = p->data;
    s->next = p->next;
    free(p);
    return TRUE;
}

int getTop(StackElemType *e, Stack s) 
{
    StackNode *p;
    p = s->next;
    if(p == NULL)
        return FALSE;
    *e = p->data;
    return TRUE;
}


