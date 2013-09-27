#include <stdio.h>
int a[1005][1005];

int find (int row, int collumn, int target) {
    bool find = false;
    
    if (row > 0 && collumn > 0 && a != NULL) {
        int r = 0;
        int c = collumn - 1;
        while (r < row && collumn >= 0) {
            if (a[r][c] == target) {
                find = true;
                break;
            }else if (a[r][c] < target) {
                ++ r;
            }else {
                -- c;
            }
        }
    }
    
    return find;
}

int main() {
    int m, n, t;
    while (scanf("%d%d", &m, &n) != EOF) {
        scanf("%d", &t);
        for (int i = 0; i != m; ++ i) {
            for (int j = 0; j != n; ++ j) {
                scanf("%d", &a[i][j]);
            }
        }
        if (find(m, n, t)) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}
