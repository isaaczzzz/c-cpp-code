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
    Goodlist *tmp;
    GoodList *prev = L;
    GoodList *p = L->next;

    if (CurrentCnt >= MAX_DISCOUNT_LEN)
    {
        printf("数据库已满\n");
        return false;
    }

    switch (choice)
    {
    case 0: //尾插
        while (p != NULL)
        {
            prev = p;
            p = p->next;
        }
        tmp = (GoodsList *)malloc(sizeof(GoodsList));
        tmp->data = goodsInfo;
        prev->next = tmp;
        tmp->next = NULL;
        CurrentCnt++;
        return true;
        break;
    case 1: //头插
        tmp = (GoodsList *)malloc(sizeof(GoodsList));
        tmp->data = goodsInfo;
        tmp->next = p->next;
        L->next = tmp;
        CurrentCnt++;
        return true;
        break;
    default:
        if (choice <= CurrentCnt + 1 && choice > 0)
        {
            for (int i = 1; i < choice; i++)
            {
                prev = p;
                p = p->next;
            }
            tmp = (GoodsList *)malloc(sizeof(GoodsList));
            tmp->data = goodsInfo;
            prev->next = tmp;
            tmp->next = p;
            CurrentCnt++;
            return true;
        }
        else
        {
            printf("输入的位置超出当前商品列表范围\n");
            return false;
        }

        break;
    }
}