#include <stdio.h>
#define MAX 100005
int a[MAX];
int visit[MAX];

//实际上是dfs的思想，但是直接套用dfs的递归方式，性能上并不见得好。（当然PATOJ上测试发现两者都能AC-,-）
int getLink(int x) {
    int count = 0;
    while (!visit[x]) {
        visit[x] = 1;
        ++ count;
        x = a[x];
    }
    return count;
}

int main() {
    int n, res = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; ++ i) {
        int count = getLink(i);
        if (count != 1 && count != 0) {
            res += count + 1;
        }
    }
    
    if (a[0] != 0) {
        res -= 2;
    }
    
    printf("%d\n", res);
    
    return 0;
}
