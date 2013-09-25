/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1001
 */
#include <stdio.h>
#include <math.h>
double a[1005];

int main()
{
    int count = 0;
    int c = 2;
    while (c--) {
        int k, p;
        double e;
        scanf("%d", &k);
        for (int i = 0; i != k; ++ i) {
            scanf("%d%lf", &p, &e);
            if (fabs(a[p]) < 1e-8)
                ++ count;
            a[p] += e;
            if (fabs(a[p]) < 1e-8)
                -- count;
        }
    }
    
    printf("%d", count);
    for (int i = 1000; i >= 0; -- i) {
        if (fabs(a[i]) > 1e-8)
            printf(" %d %.1lf", i, a[i]);
    }
}