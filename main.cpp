#include <iostream>

using namespace std;

//节点结构体
struct node{
    char name[100];
    struct node *next;
}

//函数的参数要存放到节点的数据
struct node *creatnode(char *value)
{
    struct node *pnode = malloc(sizeof(struct node));分配空间
    if(value == NULL)
    {
        pnode->name[0] = '\0';
    }
    else
    {
        strcpy(pnode->name, value);
    }
    pnode->next = NULL;
    return pnode;
}

//增加一个节点
void add(struct node **list, char *value)
{
    //遍历链表，遇到next为空则创建一个节点
    struct node *tmp = (*list);//用一个临时变量遍历链表
    while(tmp->next != NULL)
    {
        tmp = tmp->next;//tmp往后移动一个节点
    }
    struct node *newnode = creatnode(value);//创建新节点
    tmp->next = newnode;
}

//遍历链表
void traval(struct node *list)
{
    struct node *tmp = list;
    while(tmp->next != NULL)
    {
        cout<<tmp->next->name<<endl;
        tmp = tmp->next;
    }
}

//释放链表
void clear(struct node **list)
{
    struct node *tmp1 = (*list);
    struct node *tmp2;
    while(tmp2 = tmp1->next)
    {
        free(tmp1);
        tmp1 = tmp2;//将第一个指针移到下一个节点
    }
    tmp1->name[0] = '\0';
}

//插入节点
void insert(struct node **list, char *value, int idx)
{
    int i = 0;
    struct node *tmp = *list;
    while(tmp->next)
    {
        tmp = tmp->next;
        i++;
        if(i == idx)
            break;
    }
    //判断是否为尾部
    struct node *tmpnext = tmp->next;
    if(tmpnext == NULL)
    {
        tmp->next = creatnode(value);
    }
    else
    {
        tmp->next = creatnode(value);
        tmp->next->next = tmpnext;
    }
}

//删除某个节点
void delete(struct node **list, int idx)
{
    struct node *tmp = (*list);
    struct node *last;
    int i = 0;
    while(tmp->next)
    {
        last = tmp;
        tmp = tmp->next;
        i++;
        if(i == idx)
            break;
    }
    if(i != idx)
    return;
    last->next = tmp->next;
    free(tmp);
    tmp = NULL;
}

int main(void)
{
    //创建一个链表，用一个节点来代表链表
    struct node *list = NULL;
    //给这个指针分配空间
    list = creatnode(NULL);
    //加入节点
    add(&list, "yanqiansong");
    add(&list, "liuyunzhen");
    add(&list, "yanzixiang");
    add(&list, "zhangjinding");
    insert(&list, "liuyang", 2);
    traval(list);//遍历链表
    delete(&list, 3);
    cout<<'\r\n'<<endl;
    traval(list);
    clear(&list);
}