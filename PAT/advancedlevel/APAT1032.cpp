/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1032
 实现思路：对第一个链表做遍历，做好标记。第二链表遍历时，一旦遇到已经标记过的节点，则该节点为结果。
 注意：刚开始使用map实现，最后一个case超时。看到题目中数据量很小（100000），完全可以使用数组，用空间换时间。
 */
#include<stdio.h>
#define MAX 100001
int a, b, n;
struct node {
    bool visited;
    int next;
}m[MAX];

int find(int node)
{
    while (node != -1 && !m[node].visited) {
        m[node].visited = true;
        node = m[node].next;
    }
    return node;
}

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    char tmp;
    int point, next;
    while ( n-- ) {
        scanf("%d %c %d", &point, &tmp, &next);
        m[point].next = next;
        m[point].visited = false;
    }
    find(a);
    int result = find(b);
    
    if (result == -1)
        printf("-1");
    else
        printf("%05d", result);
    
    return 0;
}