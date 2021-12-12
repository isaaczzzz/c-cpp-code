#include <stdio.h>
#include <stdlib.h>

#define GOODS_FILE_NAME "goodsinfo.txt"

#define MAX_ID_LEN 30

#define MAX_NAME_LEN 30

#define MAX_PRICE_LEN 30

#define MAX_DISCOUNT_LEN 30
typedef struct
{
    char goods_id[MAX_ID_LEN];
    char goods_name[MAX_NAME_LEN];
    int goods_price;
    char goods_discount[MAX_DISCOUNT_LEN];
    int goods_amount;
    int goods_remain;
} GoodsInfo;

typedef struct node
{
    GoodsInfo data;
    struct node *next;
} GoodsList;

GoodsInfo read_goods_info();
void init_list(GoodsList **pL);
void destory_list(GoodsList **pL);
void destory_list_and_file(GoodsList **pL);
int save_to_file(GoodsList *L);
void output_one_item(GoodsList *L);
void output_all_items(GoodsList *L);
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
bool delete_item(GoodsList *L, char *goods_id);
GoodsList *search_item(GoodsList *L, char *goods_id);
bool change_item(GoodsList *L, char *goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList *L);
int read_line(char str[], int n);

int main(void)
{
    GoodsList *goodsList;
    init_list(&goodsList);
    GoodsInfo item;
    char tmp_id[MAX_ID_LEN];

    while (1)
    {
        int choice;
        printf("超市商品管理系统\n");
        printf("1.显示所有商品的信息:\n");
        printf("2.修改某个商品的信息:\n");
        printf("3.插入某个商品的信息:\n");
        printf("4.删除某个商品的信息:\n");
        printf("5.查找某个商品的信息:\n");
        printf("6.商品存盘并退出系统:\n");
        printf("7.对商品价格进行排序:\n");
        printf("8.(慎用)删除所有内容:\n");
        printf("其他.不存盘并退出系统:\n");
        printf("输入您的选择: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            output_all_items(goodsList);
        case 2:
            item = read_goods_info();
            printf("输入要修改记录的 ID: ");
            read_line(tmp_id, MAX_ID_LEN);
            change_item(goodsList, tmp_id, item);
            break;
        case 3:
            item = read_goods_info();
            int pos;
            printf("输入数字表明你要插入的商品位置:0.商品列表尾部 1.商品列表头部 i.商品列表中间第i号位置\n");
            scanf("%d", &pos);
            insert_item(goodsList, item, pos);
            break;
        case 4:
            printf("输入要删除记录的 ID:");
            read_line(tmp_id, MAX_ID_LEN);
            delete_item(goodsList, tmp_id);
            break;
        case 5:
            printf("输入要删除记录的 ID:");
            read_line(tmp_id, MAX_ID_LEN);
            goodsList = search_item(goodsList, tmp_id);
            break;
        case 6:
            save_to_file(goodsList);
            printf("您已经存盘并退出超市商品管理系统!\n");
            return 0;
        case 7:
            bubble_sort(goodsList);
            break;
        case 8:
            destory_list_and_file(&goodsList);
            printf("您已经删除商品文件内容以及链表内容!\n");
            break;
        default:
            destory_list(&goodsList);
            printf("您已经退出超市商品管理系统!\n");
            return 0;
        }
    }
}

extern int CurrentCnt;

void init_list(GoodsList **L)
{
    GoodsList *first, *p;
    (*L) = (GoodsList *)malloc(sizeof(GoodsList));
    (*L)->next = NULL;
    first = (*L);

    FILE *fp = fopen("GOODS_FILE_NAME", "r");

    if (fp == NULL)
    {
        printf("error: file not found");
        exit(0);
    }
    else
    {
        while (1)
        {
            p = (GoodsList *)malloc(sizeof(GoodsList));
            p->next = NULL;
            if (fscanf(fp, "%s %s %d %s %d %d", p->data.goods_id, p->data.goods_name, &p->data.goods_price,
                       p->data.goods_discount, &p->data.goods_amount, &p->data.goods_remain) != 6)
                break;
            first->next = p;
            first = p;
            CurrentCnt++;
        }
    }
    free(p);
    fclose(fp);
    printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
}

bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice)
{
    GoodsList *cur, *new_node;
    new_node = (GoodsList *)malloc(sizeof(GoodsList));

    if (new_node == NULL)
        return false;
    new_node->data = goodsInfo;
    new_node->next = NULL;
    cur = L->next;
    int i = 2;
    switch (choice)
    {
    case 0: //尾插
        if (cur == NULL)
        {
            L->next = new_node;
            CurrentCnt++;
            break;
        }
        else
            while (cur->next)
                cur = cur->next;
        cur->next = new_node;
        CurrentCnt++;
        break;
    case 1: //头插
        if (cur == NULL)
        {
            L->next = new_node;
            CurrentCnt++;
        }
        else
        {
            new_node->next = L->next;
            L->next = new_node;
            CurrentCnt++;
        }
        break;
    default:
        while (cur)
        {
            if (i == choice)
            {
                new_node->next = cur->next;
                cur->next = new_node;
                CurrentCnt++;
                return true;
            }
            cur = cur->next;
            i++;
        }
        return false;
        break;
    }
    return true;
}

bool delete_item(GoodsList *L, char *goods_id)
{
    GoodsList *cur = L, *nxt = L->next;
    while (nxt != NULL && (strcmp(nxt->data.goods_id, goods_id)))
    {
        cur = nxt;
        nxt = nxt->next;
    }
    if (nxt == NULL)
    {
        return false;
    }
    else
    {
        cur->next = nxt->next;
        free(nxt);
        CurrentCnt--;
        return true;
    }
}

GoodsList *search_item(GoodsList *L, char *goods_id)
{
    GoodsList *p;
    p = L->next;
    if (strcmp(L->data.goods_id, goods_id) == 0)
        return L;
    while (p != NULL)
    {
        if (strcmp(p->data.goods_id, goods_id) == 0)
            return p;
        p = p->next;
    }
    printf("Cannot be found.\n");
    return NULL;
}

bool change_item(GoodsList *L, char *goods_id, GoodsInfo new_info)
{
    GoodsList *p;
    p = L;
    p = search_item(p, goods_id);
    if (p == NULL)
    {
        return false;
    }
    if (strcmp(p->data.goods_id, goods_id) == 0)
    {
        p->data = new_info;
        return true;
    }
}

void output_one_item(GoodsList *p)
{
    if (p == NULL)
        return;
    printf("商品ID:%s \n", p->data.goods_id);
    printf("商品名称:%s \n", p->data.goods_name);
    printf("商品价格:%d  \n", p->data.goods_price);
    printf("商品折扣:%s \n", p->data.goods_discount);
    printf("商品数量:%d \n", p->data.goods_amount);
    printf("商品剩余数量:%d\n ", p->data.goods_remain);
}

void output_all_items(GoodsList *L)
{
    GoodsList *p;
    p = L->next;
    if (p == NULL)
    {
        printf("NULL\n");
        return;
    }
    while (p != NULL)
    {
        output_one_item(p);
        p = p->next;
    }
    return;
}

void destory_list(GoodsList **L)
{
    GoodsList *p;
    while (*L)
    {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    *L = NULL;
    CurrentCnt = 0;
}

void destory_list_and_file(GoodsList **L)
{
    destory_list(L);
    remove("GOODS_FILE_NAME");
}

int save_to_file(GoodsList *L)
{
    GoodsList *p;
    p = L->next;
    int i = 0;

    if (L->next == NULL)
        exit(0);
    FILE *fp = fopen("GOODS_FILE_NAME", "w+");
    if (fp == NULL)
        exit(0);
    while (p)
    {
        GoodsInfo gi = p->data;
        fprintf(fp, "%s %s %d %s %d %d\n", gi.goods_id, gi.goods_name, gi.goods_price, gi.goods_discount, gi.goods_amount, gi.goods_remain);
        p = p->next;
        i++;
    }
    fclose(fp);
    return i;
}

void bubble_sort(GoodsList *L)
{
    GoodsList *p;
    p = L;
    int n, h, j;
    n = 0;

    if (!p)
        return;

    while (p)
    {
        n++;
        p = p->next;
    }
    if (n == 1)
        return;
    for (j = 0; j < n - 1; j++)
    {
        p = L;
        for (h = 0; h < n - 1 - j; h++)
        {
            if (p->data.goods_price > p->next->data.goods_price)
            {
                GoodsInfo tmp;
                tmp = p->next->data;
                p->next->data = p->data;
                p->data = tmp;
            }
            p = p->next;
        }
    }
}

GoodsInfo read_goods_info()
{
    GoodsInfo t;
    printf("商品ID:");
    read_line(t.goods_id, MAX_ID_LEN);
    printf("商品名:");
    read_line(t.goods_name, MAX_NAME_LEN);
    printf("商品价格:");
    scanf("%d", &t.goods_price);
    printf("商品折扣:");
    read_line(t.goods_discount, MAX_DISCOUNT_LEN);
    printf("商品数量:");
    scanf("%d", &t.goods_amount);
    printf("商品剩余数量:");
    scanf("%d", &t.goods_remain);
    return t;
}