/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1044
 简单DP思想：数组中记录从第一个钻石到当前位置的钻石价值之和。两层循环计算。注意，第二层循环的起始点（这个优化不可少）
 */
#include<stdio.h>

#define MAX 100001
#define MAXX 100000001
using namespace::std;
int n, m;
long long k[MAX];
struct range {
    int start;
    int end;
} results[MAX];
int rCount = 0;
void clearResult()
{
    rCount = 0;
}
void insertResult(int start, int end)
{
    results[rCount].start = start;
    results[rCount].end = end;
    ++ rCount;
}
int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; ++ i) {
        scanf("%lld", &k[i]);
        k[i] += k[i - 1];
    }
    
    long long tmp, min = MAXX;
    int i, j;
    for (i = 1, j = 1; i <=n; ++ i) {
        for (--j ; j <= n; ++ j) { //这个优化很关键。
            tmp = k[j] - k[i - 1];
            if (tmp == m ) {
                if (min != m)
                    clearResult();
                
                insertResult(i, j);
                min = m;
                break;
            }else if (tmp > m) {
                if (tmp < min) {
                    clearResult();
                    
                    insertResult(i, j);
                    min = tmp;
                }else if (tmp == min) {
                    insertResult(i, j);
                    min = tmp;
                }
                
                break;
            }
        }
    }
    
    for (int i = 0; i != rCount; ++ i)
        printf("%d-%d\n", results[i].start, results[i].end);
    
    return 0;
}