/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1052
 自定义结构体，用qsort排序。
 注意：
 1.题目给出的input数据并没有保证所有数据都在链表中。需要自己先过滤一遍。
 2.注意head指针本身指向NULL 的显示。
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100001
struct node{
    int key;
    int value;
    int next;
} m[MAX], links[MAX];
int n;
int cmp (const void *aa, const void * bb)
{
    node *a = (node *)aa;
    node *b = (node *)bb;
    return a->value - b->value;
}

int main()
{
    int head, key;
    scanf("%d %d", &n, &head);
    while ( n --) {
        scanf("%d", &key);
        scanf("%d%d", &m[key].value, &m[key].next);
        m[key].key = key;
    }
    int count = 0;
    while (head != -1) {
        links[count ++] = m[head];
        head = m[head].next;
    }
    
    qsort(links, count, sizeof(node), cmp);
    if (count == 0)
        printf("0 -1");
    else {
        printf("%d %05d\n", count, links[0].key);
        for (int i = 0; i != count; ++ i) {
            if (i == count - 1)
                printf("%05d %d -1\n", links[i].key, links[i].value);
            else
                printf("%05d %d %05d\n", links[i].key, links[i].value, links[i + 1].key);
        }
    }
    
    return 0;
}