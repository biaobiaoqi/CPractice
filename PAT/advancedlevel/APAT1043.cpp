#include<stdio.h>
#include<algorithm>
using namespace std;
int t[1001], a[1001], n;
int m = 1;
void inorderTrav(int index)
{
    if (index*2 <= n)
        inorderTrav(index*2);
    t[index] = a[m++];
    if (index*2 + 1 <= n)
        inorderTrav(index*2 + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <=n ; ++ i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    inorderTrav(1);
    
    for (int i = 1; i <= n; i ++) {
        printf("%d", t[i]);
        if (i != n)
            printf(" ");
    }
    return 0;
}

//a recursive way:
/*
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 1005
int n, a[MAX];

struct node {
    int value;
    node * left, *right;
} *root;

node *build(int s, int e) {
    node *no = (node *)malloc(sizeof(node));
    int num = e - s + 1;
    if (num <= 0) { //take care of the boundry
        no = 0;
    } else if (num == 1) {
        no->value = a[e];
    }else {
        int p = -1;
        int count = 1;
        while (count - 1 < num) {
            count <<= 1;
        }
        
        int completeCount = (count >> 1) - 1;
        if (num - completeCount >= (completeCount + 1)/2) {
            p = s + completeCount;
        }else {
            p = s + (completeCount - 1)/2 + num - completeCount;
        }
        
        no->value = a[p];
        no->left = build(s, p - 1);
        no->right = build(p + 1, e);
    }
    return no;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    root = build(1, n);
    
    queue<node *> q;
    q.push(root);
    bool flag = false;
    while (q.size() != 0) {
        node *curNode = q.front();
        q.pop();
        if (flag){
            printf(" ");
        } else {
            flag = true;
        }
        printf("%d", curNode->value);
        
        if (curNode->left)
            q.push(curNode->left);
        if (curNode->right)
            q.push(curNode->right);
    }
    
    return 0;
}
*/
