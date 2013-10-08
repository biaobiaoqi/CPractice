nclude <stdio.h>
#include <stdlib.h>

#define MAX 10001
#define MAXX 101
int n, p;
int c[MAX];
int dp[MAX][MAXX], has[MAX][MAXX];

int compare(const void *a, const void *b) {
    int aa = *((int *)a);
    int bb = *((int *)b);
    return bb - aa;
}

int main() {
    scanf("%d%d", &n, &p);
    int index = 1;
    while ( n-- ) {
        scanf("%d", &c[index]);
        if (c[index] <= 100) {
            ++ index;
        }
    }
    -- index;
    qsort(c + 1, index, sizeof(int), compare);
    
    for (int i = 1; i <= index; ++ i) {
        for (int j = 1; j <= p; ++ j) {
            if (j >= c[i]) {
                if (dp[i - 1][j] > dp[i - 1][j - c[i]] + c[i]) {
                    dp[i][j] = dp[i - 1][j];
                    has[i][j] = 0;
                } else {
                    dp[i][j] = dp[i -1 ][j - c[i]] + c[i];
                    has[i][j] = 1;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                has[i][j] = 0;
            }
        }
    }
    
    if (dp[index][p] != p) {
        printf("No Solution\n");
    } else {
        while (p > 0) {
            if (has[index][p]) {
                printf("%d", c[index]);
                if (p - c[index] > 0) {
                    printf(" ");
                }
                p -= c[index];
            }
            -- index;
        }
    }
    
    return 0;
}

