#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 500

typedef int VertexType;

typedef enum
{
    DG,
    UDG
} GraphType;

typedef struct ArcNode
{
    int adjvex;
    // InfoPtr *info;
    struct ArcNode *nextarc;

} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode;

typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} ListGraph;

ListGraph* init();
int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);
bool del_vertex(ListGraph* G, VertexType v);

int main(void) 
{
    ListGraph *G;
    bool flag = true;
    int op, v, w;
    
    system("chcp 65001");

    G = init();
    printf("图的类型(0=DG, 1 = UDG):\n");
    scanf("%d", &G->type);
    
    while(flag)
    {
        printf("输入操作:\n1. 插入结点\n2. 插入边\n3. 删除结点\n0. 退出\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("输入结点编号:");
            scanf("%d", &v);
            if(insert_vertex(G, v))
                printf("插入成功\n");
            else 
                printf("结点已存在\n");
            break;
        case 2:
            printf("输入边的两个结点:");
            scanf("%d %d", &v, &w);
            if(insert_arc(G, v, w))
                printf("插入成功\n");
            else
                printf("边已存在\n");
            break;
        case 3:
            printf("输入结点编号:");
            scanf("%d", &v);
            if(del_vertex(G, v))
                printf("删除成功\n");
            else 
                printf("结点不存在\n");
            break;
        case 0:
            flag = false;
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }
    return 0;
}

//初始化
ListGraph* init() 
{
    ListGraph *G;
    G = (ListGraph*)malloc(sizeof(ListGraph));
    G->vexnum = 0;
    G->arcnum = 0;
    return G;
}

int locate_vertex(ListGraph* G, VertexType v)
{
    int pos = -1;
    for(int i = 0; i < G->vexnum; i++)
        if(G->vertex[i].data == v)
            pos = i;
    return pos;
}

//插入结点
bool insert_vertex(ListGraph *G, VertexType v)
{
    if (locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM)
        return false;

    G->vexnum++;
    int num = G->vexnum - 1;
    G->vertex[num].data = v;
    G->vertex[num].firstarc = NULL;
    return true;
}

//插入边
bool insert_arc(ListGraph *G, VertexType v, VertexType w){
    int pv, pw;
    ArcNode *p;
    bool flag = false;
    
    pv = locate_vertex(G, v);
    pw = locate_vertex(G, w);
    if(pv == -1 || pw == -1)
        return false;
    
    //边已经存在
    for(p = G->vertex[pv].firstarc; p -> adjvex != w; p = p->nextarc)
        if(p -> adjvex == w)
            flag = true;
    for(p = G->vertex[pw].firstarc; p -> adjvex != v; p = p->nextarc)
        if(p -> adjvex == v)
            flag = true;
    if(flag)
        return false;
        
    p->nextarc = G->vertex[pv].firstarc;
    p->adjvex = w;
    G->vertex[pv].firstarc = p;
    if(G->type == 1) {//无向图, 多加一条边
        p->nextarc = G->vertex[pw].firstarc;
        p->adjvex = v;
        G->vertex[pw].firstarc = p;
    }
    G->arcnum++;
    return true;
}

//删除结点
bool del_vertex(ListGraph* G, VertexType v)
{
    int pv = locate_vertex(G, v);
    ArcNode *q, *p;
    if(pv == -1)
        return false;
    
    for (int i = 0; i < G->vexnum; i++) { //删除边链表中的结点
        q = G->vertex[i].firstarc;
        if (G->vertex[i].data == v) {
            while (q != NULL) {
                p = q;
                q = q->nextarc;
                free(p);
                G->arcnum--;
            }
            //表头结点中，后面的向前移动
            for (int i = pv; i < G->vexnum; i++)
                G->vertex[i] = G->vertex[i + 1];
            
            G->vexnum--;//结点数减1
            G->vertex[G->vexnum].data = 0;//清空原表头结点表的最后一个结点以及相应边链表
            G->vertex[G->vexnum].firstarc = NULL;
            i--;
        } else {
            p = NULL;
            while (q != NULL) {//删除边表中与v相连的边
                if (q->adjvex == pv) {
                    if (p == NULL) {
                        q = q->nextarc;
                        free(G->vertex[i].firstarc);
                        G->vertex[i].firstarc = q;
                    } else {
                        p = q;
                        q = q->nextarc;
                        p->nextarc = q;
                        free(p);
                    }
                    G->arcnum--;
                    break;
                } else {
                    p = q;
                    q = q->nextarc;
                }
            }
        }
    }
    return true;
}