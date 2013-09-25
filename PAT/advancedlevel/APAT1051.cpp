/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1051
 此题简单的做可以使用C++的 stack做模拟判定合理；但看到10ms的限时，我担心即使是线性算法也遇到timeout。由于判定条件是一个序列，我想到如何使用序列本身的特征来做线性的判定，于是有了这个简单的解法：
 
 不使用stack模拟的判定条件：
 1.x取出后，比x小的必须由大到小输出。
 2.栈容量怎么用起来：【x取出时，如果大于之前的最大值，必须满足，（x - 出栈数目）< m】
 */
#include<stdio.h>
int m, n, k;
int max, min, tmp;
bool flag;
int main()
{
    scanf("%d %d %d", &m, &n, &k);
    while(k --) {
        flag = true;
        max = 0;
        min = 1001;
        
        for (int i = 0; i != n; ++ i) {
            scanf("%d", &tmp);
            if (tmp > max) {
                if (tmp - i > m) flag = false;
                else max = min= tmp;
            } else {
                if ( tmp > min) flag = false;
                else min = tmp;
            }
        }
        
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
}